#include "nbavr.h"

// TODO Reorder task list on the fly by how long they are sleeping for,
//  keeping awake tasks at the top of the list.
//  This will result in less 32 bit checks being done to see if tasks need to be woken.
//  Need something to detect when a task is woken before the due time so it
//  isn't ignored.

#define LONG_JUMP_HALT 1
#define LONG_JUMP_YIELD 2

static void step(Task* task);

// Used to jump out of a task if it halts or yields.
static jmp_buf mLongJmp;

// Entry point to nbavr.
void nbavr(Task** tasks) {
    // Disable interrupts.
    cli();

    // Check there is at least one task.
    if((tasks == NULL) || (tasks[0] == NULL)) {
        while(true);
    }

    // Enable watchdog timer with 15MS timouts.
    wdt_enable(WDTO_15MS);

    // Setup tick timer.
    setupTicks(halt);

    // If a task halts or yields, the cpu will jump back here.
    int jmp = setjmp(mLongJmp);

    // Pointer to current task.
    // Static to prevent being reinitialised when a task yields or halts.
    static Task** taskp = NULL;

    // If a task halted set its state to crashed and go to the next task.
    if(jmp == LONG_JUMP_HALT) {
        (*taskp)->state = TaskStateCrash;
        taskp++;
    } else if(jmp == LONG_JUMP_YIELD) {
        taskp++;
    }

    while(true) {
        Task* task = (*taskp);
        // Reset watchdog timer.
        wdt_reset();

        // Enable interrupts.
        sei();

        if(task != NULL) {
            if(task->sleepState == SleepStateDelay) {
                // Check if it is time for this task to wake up.
                if((int32_t)(getTicks() - task->wakeTick) >= 0) {
                    task->sleepState = SleepStateAwake;
                }
            }

            if(task->sleepState == SleepStateAwake) {
                step(task);
            }

            // Go to next task.
            taskp++;
        } else {
            // Reached end of task list.
            // TODO Sleep the cpu.
            taskp = tasks;
        }
    }
}

// Handle task states, enable halt timeout, and run task.
static void step(Task* task) {
    TaskFunction f = NULL;

    switch(task->state) {
    case TaskStateLoop:
        f = task->loop;
        break;
    case TaskStateCrash:
        f = task->crash;
        task->state = TaskStateSetup;
        break;
    default: // Any other value means do setup.
        f = task->setup;
        task->state = TaskStateLoop;
        break;
    }

    if(f != NULL) {
        enableHaltInterrupt(getTicks16() + TASK_TIMEOUT);

        f();

        disableHaltInterrupt();
    }
}

void yield(void) {
    longjmp(mLongJmp, LONG_JUMP_YIELD);
}

void halt(void) {
    longjmp(mLongJmp, LONG_JUMP_HALT);
}

void delay(Task* task, uint32_t ticks) {
    task->wakeTick = getTicks() + ticks;
    task->sleepState = SleepStateDelay;
}

void sleep(Task* task) {
    task->sleepState = SleepStateSleep;
}

void wake(Task* task) {
    task->sleepState = SleepStateAwake;
}
