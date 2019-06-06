/// [[Index]]

/// # {{Clock}}

/// Useful class for managing the passing of time.<br>
/// Required by TaskManager.

/// ```c++
/// const uint64_t cpuFreq = 16000000;

/// using SystemTimer = nbos::hw::Timer1;

/// using Clock = nbos::Clock<SystemTimer, cpuFreq>;

/// uint64_t ticks = Clock::getTicks();
/// uint64_t millis = Clock::ticksToMillis(ticks);
/// ```

/// Every cpu clock cycle is 1 / freq seconds. (62.5ns at 16MHz)<br>
/// Every 64 clock cycles is a tick. (4us at 16MHz)<br>
/// Every 2^64 ticks the clock overflows. (~2339769 years at 16Mhz)

/// If Clock is given an 8 bit timer (rather than 16 bit) each tick will be
/// 4x longer.

#ifndef NBOS_CLOCK_HPP
#define NBOS_CLOCK_HPP

#include "hardware/system.hpp"
#include "hardware/timer.hpp"
#include "hardware/hardwaretype.hpp"
#include "priorityqueue.hpp"
#include "callback.hpp"

namespace nbos {

struct DelayedCall {
    Callback<void> callback;
    void* data;
    uint64_t tick;

    DelayedCall() {
    }

    DelayedCall(Callback<void> callback, void* data, uint64_t tick)
    : callback(callback), data(data), tick(tick) {
    }

    bool operator<(const DelayedCall& other) const {
        return int64_t(other.tick - tick) > 0;
    }
};

/// ## class Clock<class Timer, uint64_t cpuFreq, uint64_t maxCalls = 8\>
template<class TimerT, uint64_t cpuFreq, uint64_t maxCalls = 8>
class Clock {
    static_assert(TimerT::getHardwareType() == hw::HardwareType::timer, "Clock requires a Timer");

    static constexpr bool isEightBitCounter = sizeof(typename TimerT::Type) == 1;
    static constexpr int32_t divisor = 64;

    uint64_t _ticks = 0;
    PriorityQueue<DelayedCall, int(maxCalls)> _calls;

    Clock() {
        atomic() {
            TimerT::OutputA::setCallback(handleDelayedCall);
            TimerT::setCallback(handleTimerOverflow);
            TimerT::intEnable(true);
            TimerT::clock(TimerT::Clock::div64);
        }
    }

    Clock(Clock const&);
    Clock& operator=(const Clock&);

    static force_inline Clock& getInstance() {
        static Clock clock;
        return clock;
    }

public:

    static constexpr uint64_t freq = cpuFreq;
    using Timer = TimerT;

    static void init() {
        getInstance();
    }

    /// #### static constexpr uint64_t millisToTicks(uint64_t ms)
    /// Convert milliseconds to ticks.
    static constexpr uint64_t millisToTicks(uint64_t ms) {
        return uint64_t((float(ms) * (cpuFreq / 1000) / float(divisor)) + 0.5);
    }

    /// #### static constexpr uint64_t microsToTicks(uint64_t us)
    /// Convert microseconds to ticks.
    static constexpr uint64_t microsToTicks(uint64_t us) {
        return uint64_t(((float(us) / 1000) * (cpuFreq / 1000) / float(divisor)) + 0.5);
    }

    /// #### static constexpr uint64_t ticksToMillis(uint64_t ticks)
    /// Convert ticks to milliseconds.
    static constexpr uint64_t ticksToMillis(uint64_t ticks) {
        return uint64_t((float(ticks) * 1000 * float(divisor) / cpuFreq) + 0.5);
    }

    /// #### static constexpr uint64_t ticksToMicros(uint64_t ticks)
    /// Convert ticks to microseconds.
    static constexpr uint64_t ticksToMicros(uint64_t ticks) {
        return uint64_t((float(ticks) * 1000 * float(divisor) / (cpuFreq / 1000)) + 0.5);
    }

    /// #### static uint64_t getTicks()
    /// Get the current value of the 64 bit tick counter.
    static uint64_t getTicks() {
        return atomic(getTicks_());
    }

    /// #### static uint64_t getTicks_()
    /// Non-atomic version of getTicks().
    static uint64_t getTicks_() {
        const auto& self = getInstance();

        uint64_t ticks = self._ticks;
        auto counter = TimerT::counter();

        if(TimerT::intFlag()) {
            ticks += bv<uint64_t>(sizeof(typename TimerT::Type) * 8);
            counter = TimerT::counter();
        }

        return ticks | uint64_t(counter);
    }

    /// #### static bool delayedCall(Callback callback, void\* data, uint64_t delay)
    /// Add a callback to call after delay ticks.<br>
    /// Returns true if successfully added.
    template<class T>
    static bool delayedCall(Callback<T> callback, T* data, uint64_t delay) {
        return atomic(delayedCall_(callback, data, delay));
    }

    /// #### static bool delayedCall_(Callback callback, void\* data, uint64_t delay)
    /// Non-atomic version of delayedCall().
    // TODO This function is quite time consuming, ~5 ticks. Need to make it faster.
    template<class T>
    static bool delayedCall_(Callback<T> callback, T* data, uint64_t delay) {
        if(callback == nullptr) {
            return false;
        }

        auto& self = getInstance();
        auto& calls = self._calls;

        uint64_t now = getTicks_();

        DelayedCall dc(callback, data, now + uint64_t(delay));

        const bool success = calls.push(dc);

        if(success) {
            dc = *calls.peek();

            int64_t delta = int64_t(dc.tick - now);

            // FIXME This could cancel potential calls.
            TimerT::OutputA::intFlagClear();

            // TODO Need to come up with a more reliable system. Something
            //  that guarantees the interrupt won't be missed.
            if(delta <= 2) {
                handleDelayedCall();
                // XXX What happens if another call is due to happen right now?
            } else if(delta < (isEightBitCounter ? 255 : 65536)) {
                TimerT::OutputA::value(typename TimerT::Type(dc.tick));
                TimerT::OutputA::intEnable(true);
            } else {
                TimerT::OutputA::intEnable(false);
            }
        }

        return success;
    }

    /// #### static void delay<uint64_t ns\>()
    /// Delays the cpu for the given number of nanoseconds.<br>
    /// Should only be used for very short delays.<br>
    /// Limited to 2 milliseconds.<br>
    /// Rounds to the nearest possible delay. E.g. at 16MHz, delay<50\>() will
    /// delay for 62.5 nanoseconds (1 cpu clock cycle).
    template <uint64_t ns>
    static force_inline void delay() {
        nbos::delay<cpuFreq, ns>();
    }

    template<class T>
    static void haltCallback(Callback<T> callback, T* data) {
        TimerT::OutputB::setCallback(callback, data);
    }

    static void haltStart(typename TimerT::Type ticks) {
        block(TimerT::OutputB::value(TimerT::counter() + ticks));
        block(TimerT::OutputB::intFlagClear());
        block(TimerT::OutputB::intEnable(true));
    }

    static void haltEnd() {
        block(TimerT::OutputB::intEnable(false));
    }

private:

    // Called when a tick interrupt occurs.
    static void handleDelayedCall(void* data = nullptr) {
        auto& self = getInstance();
        auto& calls = self._calls;

        Optional<DelayedCall> delayedCall;

        if((delayedCall = calls.peek())) {
            loop: ;

            delayedCall->callback(delayedCall->data);

            calls.pop();

            if((delayedCall = calls.peek())) {
                int64_t delta = int64_t(delayedCall->tick - getTicks());

                // FIXME This could cancel potential calls.
                TimerT::OutputA::intFlagClear();

                if(delta <= 2) {
                    goto loop;
                } else if(delta < (isEightBitCounter ? 255 : 65536)) {
                    TimerT::OutputA::value(typename TimerT::Type(delayedCall->tick));
                    TimerT::OutputA::intEnable(true);
                } else {
                    TimerT::OutputA::intEnable(false);
                }
            } else {
                TimerT::OutputA::intEnable(false);
            }
        } else {
            TimerT::OutputA::intEnable(false);
        }
    }

    static void handleTimerOverflow(void* data) {
        auto& self = getInstance();
        auto& calls = self._calls;

        self._ticks += bv<uint64_t>(sizeof(typename TimerT::Type) * 8);

        if(!TimerT::OutputA::intEnabled()) {
            Optional<DelayedCall> delayedCall;

            if((delayedCall = calls.peek())) {
                int64_t delta = int64_t(delayedCall->tick - getTicks());

                // FIXME This could cancel potential calls.
                TimerT::OutputA::intFlagClear();

                if(delta <= 2) {
                    handleDelayedCall();
                } else if(delta < (isEightBitCounter ? 255 : 65536)) {
                    TimerT::OutputA::value(typename TimerT::Type(delayedCall->tick));
                    TimerT::OutputA::intEnable(true);
                }
            } else {
                TimerT::OutputA::intEnable(false);
            }
        }
    }
};

#ifdef TEST

#ifdef CHIP_TIMER_1
    TEST(Clock, millisToTicks) {
        EXPECT_EQ((Clock<hw::Timer1, 1000000>::millisToTicks(0)), 0);
        EXPECT_EQ((Clock<hw::Timer1, 1000000>::millisToTicks(1)), 16);
        EXPECT_EQ((Clock<hw::Timer1, 1000000>::millisToTicks(1000)), 15625);
        EXPECT_EQ((Clock<hw::Timer1, 1000000>::millisToTicks(1001)), 15641);
        EXPECT_EQ((Clock<hw::Timer1, 1000000>::millisToTicks(16000000)), 250000000);
        EXPECT_EQ((Clock<hw::Timer1, 16000000>::millisToTicks(0)), 0);
        EXPECT_EQ((Clock<hw::Timer1, 16000000>::millisToTicks(1)), 250);
        EXPECT_EQ((Clock<hw::Timer1, 16000000>::millisToTicks(1000)), 250000);
        EXPECT_EQ((Clock<hw::Timer1, 16000000>::millisToTicks(16000000)), 4000000000);
        EXPECT_EQ((Clock<hw::Timer1, 20000000>::millisToTicks(0)), 0);
        EXPECT_EQ((Clock<hw::Timer1, 20000000>::millisToTicks(1)), 313);
        EXPECT_EQ((Clock<hw::Timer1, 20000000>::millisToTicks(1000)), 312500);
    }
#endif // CHIP_TIMER_1

#ifdef CHIP_TIMER_1
    TEST(Clock, ticksToMillis) {
        EXPECT_EQ((Clock<hw::Timer1, 1000000>::ticksToMillis(0)), 0);
        EXPECT_EQ((Clock<hw::Timer1, 1000000>::ticksToMillis(15)), 1);
        EXPECT_EQ((Clock<hw::Timer1, 1000000>::ticksToMillis(250)), 16);
        EXPECT_EQ((Clock<hw::Timer1, 16000000>::ticksToMillis(0)), 0);
        EXPECT_EQ((Clock<hw::Timer1, 16000000>::ticksToMillis(200)), 1);
        EXPECT_EQ((Clock<hw::Timer1, 16000000>::ticksToMillis(4000000000)), 16000000);
        EXPECT_EQ((Clock<hw::Timer1, 20000000>::ticksToMillis(0)), 0);
        EXPECT_EQ((Clock<hw::Timer1, 20000000>::ticksToMillis(316)), 1);
        EXPECT_EQ((Clock<hw::Timer1, 20000000>::ticksToMillis(312500)), 1000);
        EXPECT_EQ((Clock<hw::Timer1, 20000000>::ticksToMillis(312500)), 1000);
    }
#endif // CHIP_TIMER_1

TEST(Clock, delayedCall) {
    #ifdef CHIP_TIMER_1
        typedef Clock<hw::Timer1, 16000000> Clock;

        Clock::delayedCall((Callback<void>)nullptr, (void*)nullptr, Clock::millisToTicks(3000));
    #endif // CHIP_TIMER_1

    DelayedCall a(nullptr, nullptr, 1000);
    DelayedCall b(nullptr, nullptr, 1500);
    DelayedCall c(nullptr, nullptr, 1001);
    DelayedCall d(nullptr, nullptr, 999);
    DelayedCall e(nullptr, nullptr, 1000);
    DelayedCall f(nullptr, nullptr, 4294967296 / 2 - 1);
    DelayedCall g(nullptr, nullptr, 4294967296 / 2 - 2);

    EXPECT_TRUE(a < b);
    EXPECT_TRUE(a < c);
    EXPECT_TRUE(d < a);
    EXPECT_TRUE(a < c);
    EXPECT_TRUE(a < f);
    EXPECT_TRUE(g < f);
    EXPECT_FALSE(b < a);
    EXPECT_FALSE(c < a);
    EXPECT_FALSE(a < e);
    EXPECT_FALSE(e < a);
    EXPECT_FALSE(f < a);
}

#endif

} // nbos

#endif
