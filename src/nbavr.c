#include "nbavr.h"

static void processTask(Task* task);
static TaskFunction processState(Task* task);

void nbavr(Task** tasks) {
    state.tasks = tasks;

    resetClearStatus();

    watchdog(WATCHDOG_16MS, WATCHDOG_INTERRUPT_RESET);

    timingSetup();

    while(true) {
        watchdogReset();
        watchdogInterruptEnable(true);
        sei();

        Task* task = getNextTask();

        processTask(task);
    }
}

static void processTask(Task* task) {
    // Save state in case the task halts.
    uint8_t jmp = setjmp(state.haltJmp);

    if(jmp == 0) {
        state.currentTask = task;

        TaskFunction f = processState(task);

        if(f != NULL) {
            watchdogReset();
            f(task);
        }

        state.currentTask = NULL;
    } else if(jmp == 1) { // Task halted.
        task->state = STATE_CRASH;
    } else { // Task yielded
        state.currentTask = NULL;
    }
}

static TaskFunction processState(Task* task) {
    if(task->state == STATE_LOOP) {
        return task->loop;
    } else if(task->state == STATE_CRASH) {
        task->state = STATE_SETUP;
        return task->crash;
    } else { // STATE_SETUP or any other value.
        if(task->data != NULL) {
            memset(task->data, 0, task->dataSize);
        }
        task->state = STATE_LOOP;
        return task->setup;
    }
}
