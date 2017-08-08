/// # Nbavr
///
/// ## Example

/// ```c++
/// const uint32_t CpuFreq = 16000000;
///
/// typedef PinB5 ledPin;
/// typedef TimerCounter1 systemTimer;
///
/// typedef Nbavr<systemTimer, CpuFreq> Nbavr;
///
/// Flash<Nbavr, ledPin> flash;
///
/// Task* tasks[] = {&flash};
///
/// Nbavr::run(tasks);
///
///
/// // Within Flash::loop()
/// uint32_t ticks = Nbavr::getTicks();
/// uint32_t millis = Nbavr::ticksToMillis(ticks);
/// ```

#ifndef NBAVR_HPP
#define NBAVR_HPP

#include <stddef.h>
#include <stdint.h>

#include "util/type_info.hpp"

#include "hardware.hpp"
#include "atomic.hpp"
#include "stream.hpp"
#include "array.hpp"
#include "taskmanager.hpp"
#include "print.hpp"

#include "tasks/lcd.hpp"
#include "tasks/serial.hpp"
#include "tasks/servo.hpp"
#include "tasks/twi.hpp"

/// Every clock cycle is 1 / freq seconds. (62.5ns at 16MHz)<br>
/// Every 64 clock cycles is a tick. (4us at 16MHz)<br>
/// Every 2^16 ticks is a tock. (262.144ms at 16MHz)<br>
/// Every 2^32 ticks the clock overflows. (4.77 hours at 16Mhz)

#define MAX_TICK_INTERRUPTS 10
#define DIVISOR 64UL
#define INTERRUPT_TICK_BUFFER 200
#define MIN_INTERRUPT_TICK 2

/// ## class Nbavr<class TimerCounter, uint32_t CpuFreq>
template<class TimerCounter, uint32_t CpuFreq>
class Nbavr {
    struct Interrupt {
        // The callback to use.
        void (*callback)(void*) = nullptr;
        // Data to pass into the callback.
        void* data = nullptr;
        // The tick at which to perform the callback.
        uint16_t tick = 0;
    };

    struct Queue {
        uint8_t size = 0;
        uint8_t head = 0;
        uint8_t tail = 0;
        Interrupt interrupts[MAX_TICK_INTERRUPTS];
    };

    uint16_t _tocks = 0;
    Queue _interrupts;
    void (*_haltCallback)(void*) = nullptr;
    void* _haltCallbackData = nullptr;

    Nbavr() {}
    Nbavr(Nbavr const&);
    void operator=(Nbavr const&);

public:
    typedef TimerCounter timer;
    static const uint32_t freq = CpuFreq;

    static force_inline Nbavr& getInstance() {
        static Nbavr nbavr;
        return nbavr;
    }

    /// #### static void run(Task\*[])
    /// Run an array of tasks.<br>
    /// This function does not return.
    template <uint8_t S>
    static force_inline void run(Task<Nbavr>* (&tasks)[S]) {
        static_assert(TimerCounter::getHardwareType() == HardwareType::TimerCounter, "Nbavr requires a TimerCounter");
        static_assert(sizeof(typename TimerCounter::type) == 2, "Nbavr requires a 16 bit TimerCounter");

        atomic {
            TimerCounter::OutputCompareA::callback(timerCounterOutputCompareA, nullptr);
            TimerCounter::overflowCallback(timerCounterOverflow, nullptr);
            TimerCounter::overflowIntEnable(true);
            TimerCounter::clock(TimerCounter::Clock::Div64);
        }

        TaskManager<Nbavr<TimerCounter, CpuFreq>> tm(tasks);
    }

    /// #### static constexpr uint32_t millisToTicks(uint32_t ms)
    /// Converts milliseconds to ticks.
    static constexpr uint32_t millisToTicks(uint32_t ms) {
        // const uint32_t CpuFreqMhz = CpuFreq / 1000000;

        // return ((ms * 1000) + (DIVISOR / CpuFreqMhz / 2)) / (DIVISOR / CpuFreqMhz);
        // return ((ms * 1000) + (DIVISOR / CpuFreqMhz / 2)) / (DIVISOR / CpuFreqMhz);

        // const uint32_t seconds = ms / 1000;

        // constexpr uint32_t ticksPerSecond = CpuFreq / DIVISOR;
        // constexpr uint32_t ticksPerMs = ticksPerSecond / 1000;
        // constexpr uint32_t ticksPerMsRem = ticksPerSecond % 1000;

        // return ms * ticksPerMs + ms * ticksPerMsRem / 1000;

        return (float(ms) * (CpuFreq / 1000) / DIVISOR) + 0.5;
    }

    /// #### static constexpr uint32_t ticksToMillis(uint32_t ms)
    /// Converts ticks to milliseconds.
    static constexpr uint32_t ticksToMillis(uint32_t ticks) {
        // const uint32_t CpuFreqMhz = CpuFreq / 1000000;

        // return (ticks * (DIVISOR / CpuFreqMhz)) / 1000;

        // return DIVISOR * ticks / (CpuFreq / 1000);

        return (float(ticks) * 1000 * DIVISOR / CpuFreq) + 0.5;
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

    /// #### static bool addInterrupt(void (*callback)(void*), void* data, uint16_t delay)
    /// Add a tick precision interrupt.<br>
    /// Returns true if successful.
    static bool addInterrupt(void (*callback)(void*), void* data, uint16_t delay) {
        atomic {
            Nbavr& self = getInstance();

            uint16_t now = getTicks16();

            if(callback == nullptr) {
                return false;
            }

            // Check if queue is full.
            if(self._interrupts.size >= MAX_TICK_INTERRUPTS) {
                return false;
            }

            // Enforce a minimum delay to prevent missed interrupts.
            if(delay < MIN_INTERRUPT_TICK) {
                delay = MIN_INTERRUPT_TICK;
            }

            // Ensure the delay isn't in the faked negative range.
            uint16_t limit = 0U - INTERRUPT_TICK_BUFFER - 1U;

            if(delay > limit) {
                delay = limit;
            }

            uint16_t interruptTick = now + delay;

            // Add the interrupt to the queue
            Interrupt interrupt = {callback, data, interruptTick};
            push(&self._interrupts, now - INTERRUPT_TICK_BUFFER, interrupt);

            // Set the timer to the first interrupt.
            block TimerCounter::outputA(peek(&self._interrupts).tick);

            // If the queue was previously empty, clear the flag and enable interrupt.
            if(self._interrupts.size == 1) {
                atomic {
                    TimerCounter::outputAIntFlagClear();
                    TimerCounter::outputAIntEnable(true);
                }
            }
        }

        return true;
    }

private:
    // Push an interrupt to the queue.
    // Check queue size before calling.
    static void push(Queue* queue, uint16_t base, Interrupt interrupt) {
        Interrupt* interrupts = queue->interrupts;

        interrupts[queue->tail] = interrupt;

        uint8_t t = queue->tail;
        uint8_t h = queue->head;

        queue->size++;
        queue->tail++;

        if(queue->tail >= MAX_TICK_INTERRUPTS) {
            queue->tail = 0;
        }

        while(t != h) {
            uint8_t p;

            if(t == 0) {
                p = MAX_TICK_INTERRUPTS - 1;
            } else {
                p = t - 1;
            }

            if(compare(base, interrupts[t].tick, interrupts[p].tick)) {
                Interrupt temp = interrupts[p];
                interrupts[p] = interrupts[t];
                interrupts[t] = temp;
            } else {
                break;
            }

            t = p;
        }
    }

    // Pop an interrupt from the queue.
    // Check queue size before calling.
    force_inline static void pop(Queue* queue) {
        queue->size--;
        queue->head++;

        if(queue->head >= MAX_TICK_INTERRUPTS) {
            queue->head = 0;
        }
    }

    // Look at the top interrupt in the queue.
    // Will return rubbish if the queue is empty.
    force_inline static Interrupt peek(Queue* queue) {
        return queue->interrupts[queue->head];
    }

    // Indicates which of b or c is closer to a.
    // true if b is sooner.
    // otherwise false.
    force_inline static bool compare(uint16_t a, uint16_t b, uint16_t c) {
        if((a > b) == (b >= c)) {
            return a < c;
        } else {
            return a > c;
        }
    }

    // Called when a tick interrupt occurs.
    static void timerCounterOutputCompareA(void* data) {
        Nbavr& self = getInstance();

        loop: ;

        Interrupt interrupt = peek(&self._interrupts);

        interrupt.callback(interrupt.data);

        pop(&self._interrupts);

        if(self._interrupts.size > 0) {
            uint16_t next = peek(&self._interrupts).tick;

            block TimerCounter::OutputCompareA::value(next);
            block TimerCounter::OutputCompareA::intFlagClear();

            if(!compare(interrupt.tick, self.getTicks16() + 1, next)) {
                goto loop;
            }
        } else {
            block TimerCounter::OutputCompareA::intEnable(false);
        }
    }

    static void timerCounterOverflow(void* data) {
        Nbavr& self = getInstance();

        self._tocks++;
    }
};

__extension__ typedef int __guard __attribute__((mode (__DI__)));

extern "C" force_inline int __cxa_guard_acquire(__guard *) __attribute__((used));
extern "C" force_inline void __cxa_guard_release (__guard *) __attribute__((used));
extern "C" force_inline void __cxa_guard_abort (__guard *) __attribute__((used));
extern "C" force_inline void __cxa_pure_virtual(void) __attribute__((used));

int __cxa_guard_acquire(__guard *g) {
    return !*reinterpret_cast<char*>(g);
}

void __cxa_guard_release(__guard *g) {
    *reinterpret_cast<char*>(g) = 1;
}

void __cxa_pure_virtual(void) {
}

void __cxa_guard_abort (__guard *) {
}

#endif
