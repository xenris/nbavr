/// # Clock
///
/// ## Example

/// ```c++
/// const uint32_t CpuFreq = 16000000;
///
/// typedef PinB5 ledPin;
/// typedef TimerCounter1 systemTimer;
///
/// typedef Clock<systemTimer, CpuFreq> Clock;
///
/// Clock::init();
///
/// Flash<Clock, ledPin> flash;
///
/// Task* tasks[] = {&flash};
///
/// TaskManager tm(tasks);
///
///
/// // Within Flash::loop()
/// uint32_t ticks = Clock::getTicks();
/// uint32_t millis = Clock::ticksToMillis(ticks);
/// ```

#ifndef NBAVR_CLOCK_HPP
#define NBAVR_CLOCK_HPP

/// Every cpu clock cycle is 1 / freq seconds. (62.5ns at 16MHz)<br>
/// Every 64 clock cycles is a tick. (4us at 16MHz)<br>
/// Every 2^16 ticks is a tock. (262.144ms at 16MHz)<br>
/// Every 2^32 ticks the clock overflows. (4.77 hours at 16Mhz)

struct DelayedCall {
    callback_t callback;
    void* data;
    uint32_t tick;

    DelayedCall() {
    }

    DelayedCall(callback_t callback, void* data, uint32_t tick)
    : callback(callback), data(data), tick(tick) {
    }

    bool operator<(const DelayedCall& other) const {
        return int32_t(other.tick - tick) > 0;
    }
};

/// ## class Clock\<class TimerCounter, uint32_t CpuFreq, int MaxCalls = 8\>
template<class TimerCounter, uint32_t CpuFreq, int MaxCalls = 8>
class Clock {
    static_assert(TimerCounter::getHardwareType() == HardwareType::TimerCounter, "Clock requires a TimerCounter");
    static_assert(sizeof(typename TimerCounter::type) == 2, "Clock requires a 16 bit TimerCounter");

    static constexpr int32_t Divisor = 64;

    uint16_t _tocks = 0;
    PriorityQueue<DelayedCall, MaxCalls> _calls;

    Clock() {
        atomic {
            TimerCounter::OutputCompareA::callback(handleDelayedCallback, nullptr);
            TimerCounter::overflowCallback(handleTimerOverflow, nullptr);
            TimerCounter::overflowIntEnable(true);
            TimerCounter::clock(TimerCounter::Clock::Div64);
        }
    }

    Clock(Clock const&);

    void operator=(Clock const&);

public:

    typedef TimerCounter timer;
    static const uint32_t freq = CpuFreq;

    static force_inline Clock& getInstance() {
        static Clock clock;
        return clock;
    }

    /// #### static constexpr uint32_t millisToTicks(uint32_t ms)
    /// Convert milliseconds to ticks.
    static constexpr uint32_t millisToTicks(uint32_t ms) {
        return (float(ms) * (CpuFreq / 1000) / Divisor) + 0.5;
    }

    /// #### static constexpr uint32_t microsToTicks(uint32_t us)
    /// Convert microseconds to ticks.
    static constexpr uint32_t microsToTicks(uint32_t us) {
        return ((float(us) / 1000) * (CpuFreq / 1000) / Divisor) + 0.5;
    }

    /// #### static constexpr uint32_t ticksToMillis(uint32_t ticks)
    /// Convert ticks to milliseconds.
    static constexpr uint32_t ticksToMillis(uint32_t ticks) {
        return (float(ticks) * 1000 * Divisor / CpuFreq) + 0.5;
    }

    /// #### static constexpr uint32_t ticksToMicros(uint32_t ticks)
    /// Convert ticks to microseconds.
    static constexpr uint32_t ticksToMicros(uint32_t ticks) {
        return (float(ticks) * 1000 * Divisor / (CpuFreq / 1000)) + 0.5;
    }

    /// #### static uint16_t getTicks16()
    /// Gets the current value of the 16 bit tick counter.<br>
    /// Wraps every 2^16 ticks. (262.144ms at 16MHz)
    static force_inline uint16_t getTicks16() {
        // FIXME This should probably have a "block".
        return TimerCounter::counter();
    }

    /// #### static uint32_t getTicks()
    /// Gets the current value of the 32 bit tick counter.<br>
    /// Wraps every 2^32 ticks. (4.77 hours at 16Mhz)
    static uint32_t getTicks() {
        uint32_t ticks;

        atomic {
            // Get the value of the counter.
            uint16_t low = getTicks16();
            // Get the value of the overflow counter.
            uint16_t high = getInstance()._tocks;

            // Check if the counter has overflowed since atomic started.
            if(TimerCounter::overflowIntFlag()) {
                // If it has then there is a possibility that the numbers are not synchronised.
                // Get the new counter value, and increment "high".
                low = getTicks16();
                high++;
            }

            ticks = (uint32_t(high) << 16) | low;
        }

        return ticks;
    }

    /// #### static uint16_t getTocks()
    /// Gets the current value of the 16 bit tock counter.<br>
    /// Wraps every 2^16 tocks. (4.77 hours at 16Mhz)
    static force_inline uint16_t getTocks() {
        uint16_t tocks;

        atomic {
            tocks = getInstance()._tocks;
        }

        return tocks;
    }

    /// #### static bool delayedCall(callback_t callback, void* data, int32_t delay)
    /// Add a callback to call after delay ticks.<br>
    /// Returns true if successful added.
    // TODO This function is quite time consuming, ~5 ticks. Need to make it faster.
    static bool delayedCall(callback_t callback, void* data, int32_t delay) {
        auto& self = getInstance();
        auto& calls = self._calls;

        if(callback == nullptr) {
            return false;
        }

        bool success;

        delay = max(delay, int32_t(0));

        atomic {
            uint32_t now = getTicks();

            DelayedCall dc(callback, data, now + uint32_t(delay));

            success = calls.push_(dc);

            if(success) {
                calls.peek_(&dc);

                int32_t delta = dc.tick - now;

                // FIXME This could cancel potential calls.
                TimerCounter::OutputCompareA::intFlagClear();

                // TODO Need to come up with a more reliable system. Something
                //  that guarantees the interrupt won't be missed.
                if(delta <= 2) {
                    handleDelayedCallback();
                    // XXX What happens if another call is due to happen right now?
                } else if(delta < 65536) {
                    TimerCounter::OutputCompareA::value(uint16_t(dc.tick & 0xffff));
                    TimerCounter::OutputCompareA::intEnable(true);
                } else {
                    TimerCounter::OutputCompareA::intEnable(false);
                }
            }
        }

        return success;
    }

private:

    // Called when a tick interrupt occurs.
    static void handleDelayedCallback(void* data = nullptr) {
        auto& self = getInstance();
        auto& calls = self._calls;

        DelayedCall dc;

        if(calls.peek_(&dc)) {
            loop: ;

            dc.callback(dc.data);

            calls.pop_();

            if(calls.peek_(&dc)) {
                int32_t delta = dc.tick - getTicks();

                // FIXME This could cancel potential calls.
                TimerCounter::OutputCompareA::intFlagClear();

                if(delta <= 2) {
                    goto loop;
                } else if(delta < 65536) {
                    TimerCounter::OutputCompareA::value(dc.tick);
                    TimerCounter::OutputCompareA::intEnable(true);
                } else {
                    TimerCounter::OutputCompareA::intEnable(false);
                }
            } else {
                TimerCounter::OutputCompareA::intEnable(false);
            }
        } else {
            TimerCounter::OutputCompareA::intEnable(false);
        }
    }

    static void handleTimerOverflow(void* data) {
        auto& self = getInstance();
        auto& calls = self._calls;

        self._tocks++;

        if(!TimerCounter::OutputCompareA::intEnabled() && !calls.empty()) {
            DelayedCall dc;

            calls.peek_(&dc);

            int32_t delta = dc.tick - getTicks();

            // FIXME This could cancel potential calls.
            TimerCounter::OutputCompareA::intFlagClear();

            if(delta <= 2) {
                handleDelayedCallback();
            } else if(delta < 65536) {
                TimerCounter::OutputCompareA::value(dc.tick);
                TimerCounter::OutputCompareA::intEnable(true);
            }
        }
    }
};

#endif
