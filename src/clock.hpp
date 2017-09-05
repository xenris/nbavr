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
///
/// If Clock is given an 8 bit timer (rather than 16 bit) each tick will be
/// 4x longer.


#include "priorityqueue.hpp"

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

    static constexpr bool EightBitCounter = sizeof(typename TimerCounter::type) == 1;
    static constexpr int32_t Divisor = EightBitCounter ? 256 : 64;

    uint16_t _tocks = 0;
    // Only used for eight bit TimerCounter.
    uint8_t _ticksHigh = 0;
    PriorityQueue<DelayedCall, MaxCalls> _calls;

    Clock() {
        atomic {
            TimerCounter::OutputCompareA::callback(handleDelayedCall, nullptr);
            TimerCounter::overflowCallback(handleTimerOverflow, nullptr);
            TimerCounter::overflowIntEnable(true);
            TimerCounter::clock(EightBitCounter ? TimerCounter::Clock::Div256 : TimerCounter::Clock::Div64);
        }
    }

    Clock(Clock const&);

    void operator=(Clock const&);

public:

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
        if constexpr (EightBitCounter) {
            uint16_t ticks;

            atomic {
                uint8_t low = TimerCounter::counter();
                uint8_t high = getInstance()._ticksHigh;

                if(TimerCounter::overflowIntFlag()) {
                    // If it has overflowed then there is a possibility that
                    // the numbers are not synchronised.
                    low = TimerCounter::counter();
                    high++;
                }

                ticks = (uint16_t(high) << 8) | low;
            }

            return ticks;
        } else {
            return TimerCounter::counter();
        }
    }

    /// #### static uint32_t getTicks()
    /// Gets the current value of the 32 bit tick counter.<br>
    /// Wraps every 2^32 ticks. (4.77 hours at 16Mhz)
    static uint32_t getTicks() {
        auto& self = getInstance();
        uint32_t ticks;

        atomic {
            if constexpr (EightBitCounter) {
                uint8_t low = TimerCounter::counter();
                uint8_t mid = self._ticksHigh;
                uint16_t high = self._tocks;

                if(TimerCounter::overflowIntFlag()) {
                    // If it has overflowed then there is a possibility that
                    // the numbers are not synchronised.
                    low = TimerCounter::counter();
                    mid++;

                    if(mid == 0) {
                        high++;
                    }
                }

                ticks = (uint32_t(high) << 16) | (uint32_t(mid) << 8) | low;
            } else {
                uint16_t low = TimerCounter::counter();
                uint16_t high = self._tocks;

                if(TimerCounter::overflowIntFlag()) {
                    // If it has overflowed then there is a possibility that
                    // the numbers are not synchronised.
                    low = TimerCounter::counter();
                    high++;
                }

                ticks = (uint32_t(high) << 16) | low;
            }
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
                    handleDelayedCall();
                    // XXX What happens if another call is due to happen right now?
                } else if(delta < (EightBitCounter ? 255 : 65536)) {
                    TimerCounter::OutputCompareA::value(dc.tick);
                    TimerCounter::OutputCompareA::intEnable(true);
                } else {
                    TimerCounter::OutputCompareA::intEnable(false);
                }
            }
        }

        return success;
    }

    static void haltCallback(callback_t callback, void* data) {
        TimerCounter::OutputCompareB::callback(callback, data);
    }

    static void haltStart(typename TimerCounter::type ticks) {
        block TimerCounter::OutputCompareB::value(TimerCounter::counter() + ticks);
        block TimerCounter::OutputCompareB::intEnable(true);
    }

    static void haltEnd() {
        block TimerCounter::OutputCompareB::intEnable(false);
    }

private:

    // Called when a tick interrupt occurs.
    static void handleDelayedCall(void* data = nullptr) {
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
                } else if(delta < (EightBitCounter ? 255 : 65536)) {
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

        if constexpr (EightBitCounter) {
            self._ticksHigh++;

            if(self._ticksHigh == 0) {
                self._tocks++;
            }
        } else {
            self._tocks++;
        }

        if(!TimerCounter::OutputCompareA::intEnabled()) {
            DelayedCall dc;

            if(calls.peek_(&dc)) {
                int32_t delta = dc.tick - getTicks();

                // FIXME This could cancel potential calls.
                TimerCounter::OutputCompareA::intFlagClear();

                if(delta <= 2) {
                    handleDelayedCall();
                } else if(delta < (EightBitCounter ? 255 : 65536)) {
                    TimerCounter::OutputCompareA::value(dc.tick);
                    TimerCounter::OutputCompareA::intEnable(true);
                }
            } else {
                TimerCounter::OutputCompareA::intEnable(false);
            }
        }
    }
};

#endif
