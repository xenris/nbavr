/// # Clock

/// ## Example

/// ```c++
/// const uint32_t CpuFreq = 16000000;

/// using LedPin = nbavr::PinB5;
/// using SystemTimer = nbavr::TimerCounter1;

/// using Clock = nbavr::Clock<SystemTimer, CpuFreq>;

/// Flash<Clock, LedPin> flash;

/// nbavr::Task<Clock>* tasks[] = {&flash};

/// nbavr::TaskManager<Clock> tm(tasks);

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

/// If Clock is given an 8 bit timer (rather than 16 bit) each tick will be
/// 4x longer.


#include "priorityqueue.hpp"
#include "hardware.hpp"

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

/// ## class Clock\<class Timer, uint32_t CpuFreq, int MaxCalls = 8\>
template<class TimerT, uint32_t CpuFreq, int MaxCalls = 8>
class Clock {
    static_assert(TimerT::getHardwareType() == hw::HardwareType::timer, "Clock requires a Timer");

    static constexpr bool EightBitCounter = sizeof(typename TimerT::type) == 1;
    static constexpr int32_t Divisor = EightBitCounter ? 256 : 64;

    uint16_t _tocks = 0;
    typename conditional<EightBitCounter, uint8_t, nulltype>::type _ticksHigh = 0;
    PriorityQueue<DelayedCall, MaxCalls> _calls;

    Clock() {
        atomic {
            TimerT::OutputA::callback(handleDelayedCall, nullptr);
            TimerT::overflowCallback(handleTimerOverflow, nullptr);
            TimerT::overflowIntEnable(true);
            TimerT::clock(EightBitCounter ? TimerT::Clock::Div256 : TimerT::Clock::Div64);
        }
    }

    Clock(Clock const&);
    Clock& operator=(const Clock&);

    static force_inline Clock& getInstance() {
        static Clock clock;
        return clock;
    }

public:

    static const uint32_t freq = CpuFreq;
    using Timer = TimerT;

    static void init() {
        getInstance();
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
                uint8_t low = TimerT::counter();
                uint8_t high = getInstance()._ticksHigh;

                if(TimerT::overflowIntFlag()) {
                    // If it has overflowed then there is a possibility that
                    // the numbers are not synchronised.
                    low = TimerT::counter();
                    high++;
                }

                ticks = (uint16_t(high) << 8) | low;
            }

            return ticks;
        } else {
            return TimerT::counter();
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
                uint8_t low = TimerT::counter();
                uint8_t mid = self._ticksHigh;
                uint16_t high = self._tocks;

                if(TimerT::overflowIntFlag()) {
                    // If it has overflowed then there is a possibility that
                    // the numbers are not synchronised.
                    low = TimerT::counter();
                    mid++;

                    if(mid == 0) {
                        high++;
                    }
                }

                ticks = (uint32_t(high) << 16) | (uint32_t(mid) << 8) | low;
            } else {
                uint16_t low = TimerT::counter();
                uint16_t high = self._tocks;

                if(TimerT::overflowIntFlag()) {
                    // If it has overflowed then there is a possibility that
                    // the numbers are not synchronised.
                    low = TimerT::counter();
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
        }

        return success;
    }

    /// #### static void delay<uint32_t ns>()
    /// Delays the cpu for the given number of nanoseconds.<br>
    /// Should only be used for very short delays.<br>
    /// Limited to 2 milliseconds.<br>
    /// Rounds to the nearest possible delay. E.g. at 16MHz, delay<50>() will
    /// delay for 62.5 nanoseconds (1 cpu clock cycle).
    template <uint32_t ns>
    static force_inline void delay() {
        static_assert(ns <= 2000000, "Cannot delay for more than 2 milliseconds");

        // Ensure that this delay separates hardware actions, even when 0ns.
        block;

        const uint64_t clocks = (uint64_t(ns) * CpuFreq + 500000000) / 1000000000;
        const uint64_t clocksPerLoop = 4;

        // TODO Handle higher cpu frequencies.
        static_assert(clocks / 4 <= integer_max<uint16_t>::value, "Cannot handle this length of delay at this cpu frequency");

        const uint16_t loops = (clocks <= 0) ? (0) : ((clocks - 1) / clocksPerLoop);
        const uint16_t nops = (clocks <= 4) ? (clocks) : ((clocks - 1) % clocksPerLoop);

        if constexpr (loops != 0) {
            const uint16_t c = loops;

            asm volatile (
                "ldi r30, %0\n"
                "ldi r31, %1\n"
                "1: sbiw r30, 1\n"
                "brne 1b\n"
                :
                : "" (uint8_t(c)), "" (uint8_t(c >> 8))
                : "r30", "r31"
            );
        }

        if constexpr (nops == 1) {
            nop();
        } else if constexpr (nops == 2) {
            nop(); nop();
        } else if constexpr (nops == 3) {
            nop(); nop(); nop();
        } else if constexpr (nops == 4) {
            nop(); nop(); nop(); nop();
        }
    }

    static void haltCallback(callback_t callback, void* data) {
        TimerT::OutputB::callback(callback, data);
    }

    static void haltStart(typename TimerT::type ticks) {
        block TimerT::OutputB::value(TimerT::counter() + ticks);
        block TimerT::OutputB::intFlagClear();
        block TimerT::OutputB::intEnable(true);
    }

    static void haltEnd() {
        block TimerT::OutputB::intEnable(false);
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
                TimerT::OutputA::intFlagClear();

                if(delta <= 2) {
                    goto loop;
                } else if(delta < (EightBitCounter ? 255 : 65536)) {
                    TimerT::OutputA::value(dc.tick);
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

        if constexpr (EightBitCounter) {
            self._ticksHigh++;

            if(self._ticksHigh == 0) {
                self._tocks++;
            }
        } else {
            self._tocks++;
        }

        if(!TimerT::OutputA::intEnabled()) {
            DelayedCall dc;

            if(calls.peek_(&dc)) {
                int32_t delta = dc.tick - getTicks();

                // FIXME This could cancel potential calls.
                TimerT::OutputA::intFlagClear();

                if(delta <= 2) {
                    handleDelayedCall();
                } else if(delta < (EightBitCounter ? 255 : 65536)) {
                    TimerT::OutputA::value(dc.tick);
                    TimerT::OutputA::intEnable(true);
                }
            } else {
                TimerT::OutputA::intEnable(false);
            }
        }
    }
};

#endif
