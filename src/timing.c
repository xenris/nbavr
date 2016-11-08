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
    uint8_t head;
    uint8_t tail;
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
        return addInterrupt_(callback, code, delay);
    }

    return false;
}

// Non-atomic version.
bool addInterrupt_(void (*callback)(int16_t), int16_t code, uint16_t delay) {
    uint16_t now = getTicks16();

    if(callback == NULL) {
        return false;
    }

    // Check if queue is full.
    if(mInterrupts.size >= MAX_TICK_INTERRUPTS) {
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
static void pop(Queue* queue) {
    queue->size--;
    queue->head++;

    if(queue->head >= MAX_TICK_INTERRUPTS) {
        queue->head = 0;
    }
}

// Look at the top interrupt in the queue.
// Will return rubbish if the queue is empty.
static Interrupt peek(Queue* queue) {
    return queue->interrupts[queue->head];
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
