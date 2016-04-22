#include "nbavr.h"

static void processTask(Task* task);
static TaskFunction processState(Task* task);

void nbavr(Task** tasks) {
    kernel.tasks = tasks;

    wdt_enable(WDTO_15MS);

    timingSetup();

    while(true) {
        wdt_reset();

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
            wdt_reset();
            f();
        }

        kernel.currentTask = NULL;
    } else if(jmp == 1) { // Task halted.
        task->state = TaskStateCrash;
    } else { // Task yielded
        kernel.currentTask = NULL;
    }
}

static TaskFunction processState(Task* task) {
    switch(task->state) {
    case TaskStateLoop:
        return task->loop;
    case TaskStateCrash:
        task->state = TaskStateSetup;
        return task->crash;
    default:
        task->state = TaskStateLoop;
        return task->setup;
    }
}
