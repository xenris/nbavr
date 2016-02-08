#include "timing.h"

#define inc(i) (i + 1 < MAX_MICRO_INTERRUPTS ? i + 1 : 0)
#define dec(i) (i == 0 ? MAX_MICRO_INTERRUPTS - 1 : i - 1)

#define DIVISOR 64
#define F_CPU_MHZ (F_CPU / 1000000)
#define OVERFLOW_TIME ((65536 / F_CPU_MHZ) * DIVISOR)

static int compareInterruptTimes(uint16_t a, uint16_t b, uint16_t now);
static uint16_t usToTimerTicks(uint16_t n);

void timingSetup() {
    Timer1Config config = {
        .clockSelect = TIMER1_SOURCE_64,
        .outputCompareRegisterA = usToTimerTicks(1000),
        .outputCompareMatchAIntEnable = true,
    };

    timer1(config);
}

uint32_t getMillis() {
    uint32_t millis;

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        millis = kernel.millis;
    }

    return millis;
}

uint32_t getMicros() {
    return 0; // TODO
}

bool addInterrupt(void (*function)(void), uint16_t us) {
    volatile uint16_t currentTicks = timer1GetTimerRegister();

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        if(kernel.microIntsTail == dec(kernel.microIntsHead)) {
            // interrupt queue is full.
            return false;
        }

        uint16_t requestedTicks = usToTimerTicks(us);

        uint16_t interruptTime = currentTicks + requestedTicks;

        // Add interrupt to sorted ring buffer.
        int n = kernel.microIntsTail;

        while(true) {
            int p = dec(n);

            if((n == kernel.microIntsHead)
            || (compareInterruptTimes(kernel.microInts[p].tick, interruptTime, currentTicks) <= 0)) {
                break;
            }

            kernel.microInts[n] = kernel.microInts[p];

            n = p;
        }

        kernel.microInts[n].function = function;
        kernel.microInts[n].tick = interruptTime;

        kernel.microIntsTail = inc(kernel.microIntsTail);

        if(n == kernel.microIntsHead) {
            timer1SetOutputCompareB(interruptTime);
            timer1OutputCompareMatchBIntEnable(true);
        }
    }

    return true;
}

void delayMillis(uint16_t ms) {
    // Take the currently active task and set its delay time to now + ms
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        if(kernel.currentTask != NULL) {
            kernel.currentTask->delay = getMillis() + ms + 1;
        }
    }
}

void delaySeconds(uint16_t s) {
    // Take the currently active task and set its delay time to now + s
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        if(kernel.currentTask != NULL) {
            kernel.currentTask->delay = getMillis() + ((uint32_t)s * 1000);
        }
    }
}

static int compareInterruptTimes(uint16_t a, uint16_t b, uint16_t now) {
    if(a > now) {
        if(b > now) {
            return a - b;
        } else {
            return -1;
        }
    } else {
        if(b > now) {
            return 1;
        } else {
            return a - b;
        }
    }
}

static uint16_t usToTimerTicks(uint16_t n) {
    // Rounded up. Prefered because n = 1 will never output 0.
    // With integer overflow handling, via 32 bit integers.
    // Would be better if 32bit ints were not needed. TODO
    return (uint16_t)(((uint32_t)n * F_CPU_MHZ + (DIVISOR - 1)) / DIVISOR);

    // Mathematically correct rounding version.
    // return (uint16_t)(((uint32_t)n * F_CPU_MHZ + (DIVISOR / 2)) / DIVISOR);
}

ISR(TIMER1_COMPB_vect) {
    volatile uint16_t now = timer1GetTimerRegister();

    if(kernel.microIntsTail == kernel.microIntsHead) {
        // This shouldn't happen.
        timer1OutputCompareMatchBIntEnable(false);
    } else {
        MicroInt interrupt = kernel.microInts[kernel.microIntsHead];

        kernel.microIntsHead = inc(kernel.microIntsHead);

        if(kernel.microIntsTail != kernel.microIntsHead) {
            MicroInt next = kernel.microInts[kernel.microIntsHead];

            if(next.tick == now) {
/*                timer1SetOutputCompareMatchBFlag(); // Force interrupt to happen imediately.*/
                // TODO How to handle this? Can't set flag manually, and interrupt will be missed
                //  if tick == now.
                //  Could handle it immediately in this interrupt...?
                timer1SetOutputCompareB(next.tick); // XXX This probably won't work...
            } else {
                timer1SetOutputCompareB(next.tick);
            }
        } else {
            timer1OutputCompareMatchBIntEnable(false);
        }

        interrupt.function();
    }
}

ISR(TIMER1_COMPA_vect) {
    uint16_t newTicks = timer1GetOutputCompareA() + usToTimerTicks(1000);

    timer1SetOutputCompareA(newTicks);

    kernel.millis++;
}
