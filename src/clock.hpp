/// [[Index]]

/// # {{Clock}}

/// Useful class for managing the passing of time.<br>
/// Required by TaskManager.

/// ```c++
/// const Word64 cpuFreq = 16000000;

/// using SystemTimer = nbos::hw::Timer1;

/// using Clock = nbos::Clock<SystemTimer, cpuFreq>;

/// Word64 ticks = Clock::getTicks();
/// Word64 millis = Clock::ticksToMillis(ticks);
/// ```

/// Every cpu clock cycle is 1 / freq seconds. (62.5ns at 16MHz)<br>
/// Every 64 clock cycles is a tick. (4us at 16MHz)<br>
/// Every 2^64 ticks the clock overflows. (~2339769 years at 16Mhz)

/// If Clock is given an 8 bit timer (rather than 16 bit) each tick will be
/// 4x longer.

#ifndef NBOS_CLOCK_HPP
#define NBOS_CLOCK_HPP

#include "hardware/system.hpp"
#include "hardware/hardwaretype.hpp"
#include "priorityqueue.hpp"
#include "callback.hpp"

namespace nbos {

struct DelayedCall {
    Callback<void> callback;
    void* data;
    Word64 tick;

    DelayedCall() {
    }

    DelayedCall(Callback<void> callback, void* data, Word64 tick)
    : callback(callback), data(data), tick(tick) {
    }

    Bool operator<(const DelayedCall& other) const {
        return Int64(other.tick - tick) > 0;
    }
};

/// ## class Clock<class Timer, Integer cpuFreq, Integer maxCalls = 8\>
template<class TimerT, Integer cpuFreq, Integer maxCalls = 8>
class Clock {
    static_assert(TimerT::getHardwareType() == hw::HardwareType::timer, "Clock requires a Timer");

    static constexpr Bool isEightBitCounter = sizeof(typename TimerT::Type) == 1;
    static constexpr Int32 divisor = isEightBitCounter ? 256 : 64;

    Word64 _ticks = 0;
    PriorityQueue<DelayedCall, maxCalls> _calls;

    Clock() {
        atomic {
            TimerT::OutputA::setCallback(handleDelayedCall);
            TimerT::setCallback(handleTimerOverflow);
            TimerT::intEnable(true);
            TimerT::clock(isEightBitCounter ? TimerT::Clock::div256 : TimerT::Clock::div64);
        }
    }

    Clock(Clock const&);
    Clock& operator=(const Clock&);

    static force_inline Clock& getInstance() {
        static Clock clock;
        return clock;
    }

public:

    static constexpr Word64 freq = cpuFreq;
    using Timer = TimerT;

    static void init() {
        getInstance();
    }

    /// #### static constexpr Word64 millisToTicks(Word64 ms)
    /// Convert milliseconds to ticks.
    static constexpr Word64 millisToTicks(Word64 ms) {
        return Word64((Float(ms) * (cpuFreq / 1000) / Float(divisor)) + 0.5);
    }

    /// #### static constexpr Word64 microsToTicks(Word64 us)
    /// Convert microseconds to ticks.
    static constexpr Word64 microsToTicks(Word64 us) {
        return Word64(((Float(us) / 1000) * (cpuFreq / 1000) / Float(divisor)) + 0.5);
    }

    /// #### static constexpr Word64 ticksToMillis(Word64 ticks)
    /// Convert ticks to milliseconds.
    static constexpr Word64 ticksToMillis(Word64 ticks) {
        return Word64((Float(ticks) * 1000 * Float(divisor) / cpuFreq) + 0.5);
    }

    /// #### static constexpr Word64 ticksToMicros(Word64 ticks)
    /// Convert ticks to microseconds.
    static constexpr Word64 ticksToMicros(Word64 ticks) {
        return Word64((Float(ticks) * 1000 * Float(divisor) / (cpuFreq / 1000)) + 0.5);
    }

    /// #### static Word64 getTicks()
    /// Get the current value of the 64 bit tick counter.
    static Word64 getTicks() {
        atomic {
            return getTicks_();
        }
    }

    /// #### static Word64 getTicks_()
    /// Non-atomic version of getTicks().
    static Word64 getTicks_() {
        const auto& self = getInstance();

        Word64 ticks = self._ticks;
        auto counter = TimerT::counter();

        if(TimerT::intFlag()) {
            ticks += bv<Word64>(sizeof(typename TimerT::Type) * 8);
            counter = TimerT::counter();
        }

        return ticks | Word64(counter);
    }

    /// #### static Bool delayedCall(Callback callback, void\* data, Word64 delay)
    /// Add a callback to call after delay ticks.<br>
    /// Returns true if successfully added.
    template<class T>
    static Bool delayedCall(Callback<T> callback, T* data, Word64 delay) {
        atomic {
            return delayedCall_(callback, data, delay);
        }
    }

    /// #### static Bool delayedCall_(Callback callback, void\* data, Word64 delay)
    /// Non-atomic version of delayedCall().
    // TODO This function is quite time consuming, ~5 ticks. Need to make it faster.
    template<class T>
    static Bool delayedCall_(Callback<T> callback, T* data, Word64 delay) {
        if(callback == nullptr) {
            return false;
        }

        auto& self = getInstance();
        auto& calls = self._calls;

        Word64 now = getTicks_();

        DelayedCall dc(callback, data, now + Word64(delay));

        const Bool success = calls.push(dc);

        if(success) {
            dc = *calls.peek();

            Int64 delta = Int64(dc.tick - now);

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

    /// #### static void delay<Word64 ns\>()
    /// Delays the cpu for the given number of nanoseconds.<br>
    /// Should only be used for very short delays.<br>
    /// Limited to 2 milliseconds.<br>
    /// Rounds to the nearest possible delay. E.g. at 16MHz, delay<50\>() will
    /// delay for 62.5 nanoseconds (1 cpu clock cycle).
    template <Integer ns>
    static force_inline void delay() {
        nbos::delay<cpuFreq, ns>();
    }

    template<class T>
    static void haltCallback(Callback<T> callback, T* data) {
        TimerT::OutputB::setCallback(callback, data);
    }

    static void haltStart(typename TimerT::Type ticks) {
        block {
            TimerT::OutputB::value(TimerT::counter() + ticks);
            block {};
            TimerT::OutputB::intFlagClear();
            block {};
            TimerT::OutputB::intEnable(true);
        }
    }

    static void haltEnd() {
        block {
            TimerT::OutputB::intEnable(false);
        }
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
                Int64 delta = Int64(delayedCall->tick - getTicks());

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

        self._ticks += bv<Word64>(sizeof(typename TimerT::Type) * 8);

        if(!TimerT::OutputA::intEnabled()) {
            Optional<DelayedCall> delayedCall;

            if((delayedCall = calls.peek())) {
                Int64 delta = Int64(delayedCall->tick - getTicks());

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

} // nbos

#endif
