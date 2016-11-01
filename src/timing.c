#include "timing.h"

// NOTE This library works with some assumptions, such as the cpu mhz being
//  a power of 2 up to 64

// To prevent interrupts being missed.
// (0, 2^16 - buffer) is in the future.
// [2^16 - buffer, 0] is past and now.
#define INTERRUPT_TICK_BUFFER 200
#define MIN_INTERRUPT_TICK 2

typedef struct {
    // The callback to use.
    void (*callback)(int16_t);
    // Code to pass into the callback.
    int16_t code;
    // The tick at which to perform the callback.
    uint16_t tick;
} Interrupt;

typedef struct {
    uint8_t size;
    Interrupt interrupts[MAX_TICK_INTERRUPTS];
} Queue;

static void tickCallback();
static void tockCallback();
static void push(Queue* queue, uint16_t base, Interrupt interrupt) __attribute__((always_inline));
static void pop(Queue* queue) __attribute__((always_inline));
static Interrupt peek(Queue* queue) __attribute__((always_inline));
static bool compare(uint16_t a, uint16_t b, uint16_t c) __attribute__((always_inline));

// Tock counter. (Tick overflows, 2^16 ticks.)
static uint16_t mTocks;
// Queue of pending tick interrupts.
static Queue mInterrupts;

// Start the tick counter.
void setupTicks(void (*halt)(void)) {
    Timer1Config config = {
        .clock = Timer1Clock64,
        .outputAIntCallback = tickCallback,
        .outputBIntCallback = halt,
        .overflowIntEnable = true,
        .overflowIntCallback = tockCallback,
    };

    timer1(config);
}

// Get the 16 bit hardware counter.
uint16_t getTicks16(void) {
    return timer1GetTimerRegister();
}

// Get the 32 bit combined hardware and overflow counter.
uint32_t getTicks(void) {
    atomic {
        return getTicks_();
    }

    return 0;
}

// Non-atomic version
uint32_t getTicks_(void) {
    // Get the value of the counter.
    uint16_t low = getTicks16();
    // Get the value of the overflow counter.
    uint16_t high = mTocks;

    // Check if the counter has overflowed since atomic started.
    if(timer1OverflowFlag()) {
        // If it has then there is a possibility that the numbers are not synchronised.
        // Get the new counter value, and increment "high".
        low = getTicks16();
        high++;
    }

    return ((uint32_t)high << 16) | low;
}

uint16_t getTocks(void) {
    atomic {
        return mTocks;
    }

    return 0;
}

// Add a tick precision interrupt.
bool addInterrupt(void (*callback)(int16_t), int16_t code, uint16_t delay) {
    atomic {
        uint16_t now = getTicks16();

        if(mInterrupts.size >= MAX_TICK_INTERRUPTS) {
            // Interrupt queue is full.
            return false;
        }

        if(callback == NULL) {
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
        Interrupt interrupt = {callback, code, interruptTick};
        push(&mInterrupts, now - INTERRUPT_TICK_BUFFER, interrupt);

        // Set the timer to the first interrupt.
        timer1SetOutputCompareA(peek(&mInterrupts).tick);

        // If the queue was previously empty, clear the flag and enable interrupt.
        if(mInterrupts.size == 1) {
            timer1ClearOutputCompareAMatchFlag();
            timer1OutputCompareAMatchIntEnable(true);
        }
    }

    return true;
}

void enableHaltInterrupt(uint16_t tick) {
    atomic {
        timer1SetOutputCompareB(tick);
        timer1OutputCompareBMatchIntEnable(true);
        timer1ClearOutputCompareBMatchFlag();
    }
}

void disableHaltInterrupt(void) {
    atomic {
        timer1OutputCompareBMatchIntEnable(false);
        timer1ClearOutputCompareBMatchFlag();
    }
}

// Called when a tick interrupt occurs.
static void tickCallback() {
    loop: ;

    Interrupt interrupt = peek(&mInterrupts);

    interrupt.callback(interrupt.code);

    pop(&mInterrupts);

    if(mInterrupts.size > 0) {
        uint16_t next = peek(&mInterrupts).tick;

        timer1ClearOutputCompareAMatchFlag();
        timer1SetOutputCompareA(next);

        if(!compare(interrupt.tick, getTicks16() + 1, next)) {
            goto loop;
        }
    } else {
        timer1OutputCompareAMatchIntEnable(false);
    }
}

// System clock.
// Keeps track of tocks (tick overflows).
static void tockCallback() {
    mTocks++;
}

// Push an interrupt to the queue.
// Check queue size before calling.
static void push(Queue* queue, uint16_t base, Interrupt interrupt) {
    Interrupt* interrupts = queue->interrupts;

    interrupts[queue->size] = interrupt;

    uint8_t n = queue->size;

    queue->size++;

    while(n > 0) {
        uint8_t p = n / 2;

        if(compare(base, interrupts[n].tick, interrupts[p].tick)) {
            Interrupt t = interrupts[p];
            interrupts[p] = interrupts[n];
            interrupts[n] = t;
        } else {
            break;
        }

        n = p;
    }
}

// Pop an interrupt from the queue.
// Check queue size before calling.
static void pop(Queue* queue) {
    Interrupt* interrupts = queue->interrupts;

    queue->size--;

    // Priority to compare to when ordering.
    uint16_t base = interrupts[0].tick;

    interrupts[0] = interrupts[queue->size];

    uint8_t p = 0;
    uint8_t s = queue->size / 2;

    while(p < s) {
        uint8_t l = p * 2 + 1;
        uint8_t r = p * 2 + 2;
        uint8_t c = r;

        // If there is only one child, or left is sooner.
        if((c >= queue->size) || (compare(base, interrupts[l].tick, interrupts[r].tick))) {
            c = l;
        }

        // If child is sooner, swap with parent.
        if(compare(base, interrupts[c].tick, interrupts[p].tick)) {
            Interrupt t = interrupts[p];
            interrupts[p] = interrupts[c];
            interrupts[c] = t;
        } else {
            break;
        }

        p = c;
    }
}

// Look at the top interrupt in the queue.
// Will return rubbish if the queue is empty.
static Interrupt peek(Queue* queue) {
    return queue->interrupts[0];
}

// Indicates which of b or c is closer to a.
// true if b is sooner.
// otherwise false.
static bool compare(uint16_t a, uint16_t b, uint16_t c) {
    if((a > b) == (b >= c)) {
        return a < c;
    } else {
        return a > c;
    }
}
