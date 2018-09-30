#ifndef NBOS_CLOCK_HPP
#define NBOS_CLOCK_HPP

/// # Clock

/// Useful class for managing the passing of time.<br>
/// Required by TaskManager.

/// ## Example

/// ```c++
/// const uint64_t cpuFreq = 16000000;

/// using SystemTimer = nbos::hw::Timer1;

/// using Clock = nbos::Clock<SystemTimer, cpuFreq>;

/// uint64_t ticks = Clock::getTicks();
/// uint64_t millis = Clock::ticksToMillis(ticks);
/// ```

/// Every cpu clock cycle is 1 / freq seconds. (62.5ns at 16MHz)<br>
/// Every 64 clock cycles is a tick. (4us at 16MHz)<br>
/// Every 2^16 ticks is a tock. (262.144ms at 16MHz)<br>
/// Every 2^32 ticks the clock overflows. (4.77 hours at 16Mhz)

/// If Clock is given an 8 bit timer (rather than 16 bit) each tick will be
/// 4x longer.

#include "priorityqueue.hpp"
#include "hardware/system.hpp"
#include "hardware/hardwaretype.hpp"

namespace nbos {

struct DelayedCall {
    callback_t callback;
    void* data;
    uint64_t tick;

    DelayedCall() {
    }

    DelayedCall(callback_t callback, void* data, uint64_t tick)
    : callback(callback), data(data), tick(tick) {
    }

    bool operator<(const DelayedCall& other) const {
        return int64_t(other.tick - tick) > 0;
    }
};

/// ## class Clock\<class Timer, uint64_t cpuFreq, int maxCalls = 8\>
template<class TimerT, uint64_t cpuFreq, int maxCalls = 8>
class Clock {
    static_assert(TimerT::getHardwareType() == hw::HardwareType::timer, "Clock requires a Timer");

    static constexpr bool EightBitCounter = sizeof(typename TimerT::type) == 1;
    static constexpr int32_t Divisor = EightBitCounter ? 256 : 64;

    uint64_t _ticks = 0;
    PriorityQueue<DelayedCall, maxCalls> _calls;

    Clock() {
        atomic([]() {
            TimerT::OutputA::callback(handleDelayedCall, nullptr);
            TimerT::overflowCallback(handleTimerOverflow, nullptr);
            TimerT::overflowIntEnable(true);
            TimerT::clock(EightBitCounter ? TimerT::Clock::div256 : TimerT::Clock::div64);
        });
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
        return (float(ms) * (cpuFreq / 1000) / Divisor) + 0.5;
    }

    /// #### static constexpr uint64_t microsToTicks(uint64_t us)
    /// Convert microseconds to ticks.
    static constexpr uint64_t microsToTicks(uint64_t us) {
        return ((float(us) / 1000) * (cpuFreq / 1000) / Divisor) + 0.5;
    }

    /// #### static constexpr uint64_t ticksToMillis(uint64_t ticks)
    /// Convert ticks to milliseconds.
    static constexpr uint64_t ticksToMillis(uint64_t ticks) {
        return (float(ticks) * 1000 * Divisor / cpuFreq) + 0.5;
    }

    /// #### static constexpr uint64_t ticksToMicros(uint64_t ticks)
    /// Convert ticks to microseconds.
    static constexpr uint64_t ticksToMicros(uint64_t ticks) {
        return (float(ticks) * 1000 * Divisor / (cpuFreq / 1000)) + 0.5;
    }

    /// #### static uint64_t getTicks()
    /// Gets the current value of the 32 bit tick counter.<br>
    /// Wraps every 2^32 ticks. (4.77 hours at 16Mhz)
    static uint64_t getTicks() {
        return atomic([]() {
            return getTicks_();
        });
    }

    /// #### static uint64_t getTicks_()
    /// Non-atomic version of getTicks().<br>
    /// Only use this when the global interrupt flag is clear, such
    /// as during hardware interrupts.
    static uint64_t getTicks_() {
        const auto& self = getInstance();

        uint64_t ticks = self._ticks;
        auto counter = TimerT::counter();

        if(TimerT::overflowIntFlag()) {
            ticks += bv<uint64_t>(sizeof(typename TimerT::type) * 8);
            counter = TimerT::counter();
        }

        return ticks | counter;
    }

    /// #### static bool delayedCall(callback_t callback, void* data, uint64_t delay)
    /// Add a callback to call after delay ticks.<br>
    /// Returns true if successful added.
    static bool delayedCall(callback_t callback, void* data, uint64_t delay) {
        return atomic([&]() {
            return delayedCall_(callback, data, delay);
        });
    }

    /// #### static bool delayedCall_(callback_t callback, void* data, uint64_t delay)
    /// Non-atomic version of delayedCall().
    /// Returns true if successful added.
    // TODO This function is quite time consuming, ~5 ticks. Need to make it faster.
    static bool delayedCall_(callback_t callback, void* data, uint64_t delay) {
        if(callback == nullptr) {
            return false;
        }

        auto& self = getInstance();
        auto& calls = self._calls;

        bool success;

        delay = max(delay, uint64_t(0));

        uint64_t now = getTicks_();

        DelayedCall dc(callback, data, now + uint64_t(delay));

        success = calls.push_(dc);

        if(success) {
            calls.peek_(&dc);

            int64_t delta = dc.tick - now;

            // FIXME This could cancel potential calls.
            TimerT::OutputA::intFlagClear();

            // TODO Need to come up with a more reliable system. Something
            //  that guarantees the interrupt won't be missed.
            if(delta <= 2) {
                handleDelayedCall();
                // XXX What happens if another call is due to happen right now?
            } else if(delta < (EightBitCounter ? 255 : 65536)) {
                TimerT::OutputA::value(dc.tick);
                TimerT::OutputA::intEnable(true);
            } else {
                TimerT::OutputA::intEnable(false);
            }
        }

        return success;
    }

    /// #### static void delay<uint64_t ns>()
    /// Delays the cpu for the given number of nanoseconds.<br>
    /// Should only be used for very short delays.<br>
    /// Limited to 2 milliseconds.<br>
    /// Rounds to the nearest possible delay. E.g. at 16MHz, delay<50>() will
    /// delay for 62.5 nanoseconds (1 cpu clock cycle).
    template <uint64_t ns>
    static force_inline void delay() {
        nbos::delay<cpuFreq, ns>();
    }

    static void haltCallback(callback_t callback, void* data) {
        TimerT::OutputB::callback(callback, data);
    }

    static void haltStart(typename TimerT::type ticks) {
        block([ticks]() {
            TimerT::OutputB::value(TimerT::counter() + ticks);
            block();
            TimerT::OutputB::intFlagClear();
            block();
            TimerT::OutputB::intEnable(true);
        });
    }

    static void haltEnd() {
        block([]() {
            TimerT::OutputB::intEnable(false);
        });
    }

private:

    // Called when a tick interrupt occurs.
    static void handleDelayedCall(void* data = nullptr) {
        auto& self = getInstance();
        auto& calls = self._calls;

        DelayedCall delayedCall;

        if(calls.peek_(&delayedCall)) {
            loop: ;

            delayedCall.callback(delayedCall.data);

            calls.pop_();

            if(calls.peek_(&delayedCall)) {
                int64_t delta = delayedCall.tick - getTicks();

                // FIXME This could cancel potential calls.
                TimerT::OutputA::intFlagClear();

                if(delta <= 2) {
                    goto loop;
                } else if(delta < (EightBitCounter ? 255 : 65536)) {
                    TimerT::OutputA::value(delayedCall.tick);
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

        self._ticks += bv<uint64_t>(sizeof(typename TimerT::type) * 8);

        if(!TimerT::OutputA::intEnabled()) {
            DelayedCall delayedCall;

            if(calls.peek_(&delayedCall)) {
                int64_t delta = delayedCall.tick - getTicks();

                // FIXME This could cancel potential calls.
                TimerT::OutputA::intFlagClear();

                if(delta <= 2) {
                    handleDelayedCall();
                } else if(delta < (EightBitCounter ? 255 : 65536)) {
                    TimerT::OutputA::value(delayedCall.tick);
                    TimerT::OutputA::intEnable(true);
                }
            } else {
                TimerT::OutputA::intEnable(false);
            }
        }
    }
};

} // nbos

#endif
