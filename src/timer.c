#include "timer.h"

typedef struct {
    void (*function)(void);
    uint16_t tick;
} Interrupt;

#define inc(i) (i + 1 < TIME_INTERRUPTS ? i + 1 : 0)
#define dec(i) (i == 0 ? TIME_INTERRUPTS - 1 : i - 1)

#define DIVISOR 8 // May use 64 instead.
#define F_CPU_MHZ (F_CPU / 1000000)
/*#define RESOLUTION_US (DIVISOR / F_CPU_MHZ) // FIXME This can be a fraction, and rounded to 0.*/
/*#define MICROSECONDS_PER_TICK RESOLUTION_US*/
#define TICKS_PER_MICROSECOND (F_CPU_MHZ / DIVISOR) // FIXME This can be a fraction, and rounded to 0.
#define OVERFLOW_TIME ((65536 / F_CPU_MHZ) * DIVISOR)

static int compareInterruptTimes(uint16_t a, uint16_t b, uint16_t now);
static uint16_t usToTimerTicks(uint16_t n);

static volatile Interrupt interrupts[TIME_INTERRUPTS];
static volatile int interruptsHead = 0;
static volatile int interruptsTail = 0;
static volatile uint32_t mMillis;

void timerSetup() {
    Timer1Config config = {
        .clockSelect = TIMER1_SOURCE_8,
        .outputCompareRegisterA = usToTimerTicks(1000),
        .outputCompareMatchAIntEnable = true,
        // TODO Use output compare A for clock.
    };

    timer1(config);
}

uint32_t getMillis() {
    uint32_t millis;

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        millis = mMillis;
    }

    return millis;
}

bool addInterrupt(void (*function)(void), uint16_t us) {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        if(interruptsTail == dec(interruptsHead)) {
            // interrupt queue is full.
            return false;
        }

        uint16_t currentTicks = timer1GetTimerRegister();

        // If clock is higher than 8MHz a uint16_t is able to hold a number greater than the overflow time.
        // Alternatively, I could just limit this function to take an upper bound which works at any frequency.
        #if(F_CPU > 8000000)
            if(us >= OVERFLOW_TIME) {
                us = OVERFLOW_TIME - 1;
            }
        #endif

        uint16_t requestedTicks = usToTimerTicks(us);

        // If divisor is 1 then min bound requestedTicks to at least 8.
        // This ensures there is at least 8 clock cycles between interrupts for other things to happen.
        // XXX On the other hand, if interrupts are been created this quickly then all 8 clock cycles, and more, are
        //  being used up to process this function. So really this is pointless, unless the min bound is much larger.
        //  This problem applies to divisors of 8 too.
        #if(DIVISOR == 1)
            if(requestedTicks < 8) {
                requestedTicks = 8;
            }
        #endif

        uint16_t interruptTime = currentTicks + requestedTicks;

        // Add interrupt to sorted ring buffer.
        int n = interruptsTail;

        while(true) {
            int p = dec(n);

            if((n == interruptsHead)
            || (compareInterruptTimes(interrupts[p].tick, interruptTime, currentTicks) <= 0)) {
                break;
            }

            interrupts[n] = interrupts[p];

            n = p;
        }

        interrupts[n].function = function;
        interrupts[n].tick = interruptTime;

        interruptsTail = inc(interruptsTail);

        if(n == interruptsHead) {
            timer1SetOutputCompareB(interruptTime);
            timer1OutputCompareMatchBIntEnable(true);
        }
    }

    return true;
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
    uint16_t now = timer1GetTimerRegister();

    if(interruptsTail == interruptsHead) {
        // This shouldn't happen.
        timer1OutputCompareMatchBIntEnable(false);
    } else {
        Interrupt interrupt = interrupts[interruptsHead];

        interruptsHead = inc(interruptsHead);

        if(interruptsTail != interruptsHead) {
            Interrupt next = interrupts[interruptsHead];

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

    mMillis++;
}
