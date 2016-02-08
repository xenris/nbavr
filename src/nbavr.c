#include "nbavr.h"

static void processTask(Task* task);
static TaskFunction processState(Task* task);

void nbavr(Task** tasks) {
    kernel.tasks = tasks;

    resetClearStatus();

    watchdog(WATCHDOG_16MS, WATCHDOG_INTERRUPT_RESET);

    timingSetup();

    while(true) {
        watchdogReset();
        watchdogInterruptEnable(true);
        sei();

        Task* task = getNextTask();

        if(task->delay <= getMillis()) {
            processTask(task);
        }
    }
}

static void processTask(Task* task) {
    // Save state in case the task halts.
    uint8_t jmp = setjmp(kernel.haltJmp);

    if(jmp == 0) {
        kernel.currentTask = task;

        TaskFunction f = processState(task);

        if(f != NULL) {
            watchdogReset();
            f(task);
        }

        kernel.currentTask = NULL;
    } else if(jmp == 1) { // Task halted.
        task->state = STATE_CRASH;
    } else { // Task yielded
        kernel.currentTask = NULL;
    }
}

static TaskFunction processState(Task* task) {
    switch(task->state) {
    case STATE_LOOP:
        return task->loop;
    case STATE_CRASH:
        task->state = STATE_SETUP;
        return task->crash;
    default:
        task->state = STATE_LOOP;
        return task->setup;
    }
}
