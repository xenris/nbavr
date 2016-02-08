#ifndef NBAVR_STATE_H
#define NBAVR_STATE_H

// This module will provide all the state variables of the kernel in one tidy
//  struct.

#include <setjmp.h>

#include "../config.h"

#include "task.h"
#include "microint.h"

typedef struct State {
    Task** tasks; // The list of tasks provided by the user.
    Task* currentTask; // The currently active task, or null if none.
    uint8_t taskIndex; // The index of the next task to be checked by the scheduler.
    jmp_buf haltJmp; // For escaping a task if it halts.
    volatile MicroInt microInts[MAX_MICRO_INTERRUPTS]; // Queue of microsecond interrupts.
    volatile int microIntsHead; // Head of microsecond interrupt queue.
    volatile int microIntsTail; // Tail of microsecond interrupt queue.
    volatile uint32_t millis; // Milliseconds passed since startup.
    volatile uint32_t seconds; // Seconds passed since startup.
} State;

extern State state;

#endif
