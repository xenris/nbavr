#include "timing.h"

#define inc(i) (i + 1 < MAX_MICRO_INTERRUPTS ? i + 1 : 0)
#define dec(i) (i == 0 ? MAX_MICRO_INTERRUPTS - 1 : i - 1)

#define DIVISOR 64
#define F_CPU_MHZ (F_CPU / 1000000)
#define OVERFLOW_TIME ((65536 / F_CPU_MHZ) * DIVISOR)

static int compareInterruptTimes(uint16_t a, uint16_t b, uint16_t now);
static uint16_t usToTimerTicks(uint16_t n);
static void outputBIntCallback();
static void outputAIntCallback();

void timingSetup() {
    Timer1Config config = {
        .clock = Timer1Clock64,
        .outputARegister = usToTimerTicks(1000),
        .outputAIntEnable = true,
        .outputBIntCallback = outputBIntCallback,
        .outputAIntCallback = outputAIntCallback,
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

bool addInterrupt(void (*function)(int), int code, uint16_t us) {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        volatile uint16_t currentTicks = timer1GetTimerRegister();

        if(kernel.microIntsTail >= MAX_MICRO_INTERRUPTS) {
            // interrupt stack is full.
            return false;
        }

        uint16_t requestedTicks = usToTimerTicks(us);

        if(requestedTicks < 2) { // TODO Check that an interrupt in only 2 ticks won't be missed.
            requestedTicks = 2;
        }

        uint16_t interruptTime = currentTicks + requestedTicks;

        uint8_t index;

        for(index = kernel.microIntsTail; index > 0; index--) {
            if(compareInterruptTimes(kernel.microInts[index - 1].tick, interruptTime, currentTicks) < 0) {
                kernel.microInts[index] = kernel.microInts[index - 1];
            } else {
                break;
            }
        }

        kernel.microInts[index] = (MicroInt){function, code, interruptTime};

        if(index == kernel.microIntsTail) {
            timer1SetOutputCompareB(interruptTime);
            timer1OutputCompareMatchBIntEnable(true);
        }

        kernel.microIntsTail++;
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

static void outputBIntCallback() {
    while(true) {
        if(kernel.microIntsTail == 0) {
            timer1OutputCompareMatchBIntEnable(false);
            break;
        }

        MicroInt interrupt = kernel.microInts[kernel.microIntsTail - 1];

        uint16_t now = timer1GetTimerRegister();

        uint16_t diff = interrupt.tick - now;

        if((int16_t)diff <= 1) {
            interrupt.function(interrupt.code);
            kernel.microIntsTail--;
        } else {
            timer1SetOutputCompareB(interrupt.tick);
            break;
        }
    }
}

static void outputAIntCallback() {
    uint16_t newTicks = timer1GetOutputCompareA() + usToTimerTicks(1000);

    timer1SetOutputCompareA(newTicks);

    kernel.millis++;

    if(kernel.currentTask != NULL) {
        if(kernel.millis > kernel.haltTimeout) {
            longjmp(kernel.haltJmp, 1);
        }
    }
}
