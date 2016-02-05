#include "taskmanager.h"

static void taskManagerProcessTask(Task* task);
static Task* getNextTask(Task** tasks);
static inline TaskFunction processState(Task* task);

static bool mTaskIsActive;
static jmp_buf mHaltJmp;
static uint8_t mNextTaskIndex = -1;

void taskManagerRun(Task** tasks) {
    resetClearStatus();

    watchdog(WATCHDOG_16MS, WATCHDOG_INTERRUPT_RESET);

    timerSetup();

    while(true) {
        watchdogReset();
        watchdogInterruptEnable(true);
        sei();

        Task* task = getNextTask(tasks);

        taskManagerProcessTask(task);
    }
}

static void taskManagerProcessTask(Task* task) {
    // Save state in case the task halts.
    uint8_t jmp = setjmp(mHaltJmp);

    if(jmp == 0) {
        mTaskIsActive = true;

        TaskFunction f = processState(task);

        if(f != NULL) {
            watchdogReset();
            f(task);
        }

        mTaskIsActive = false;
    } else { // Task halted.
        task->state = STATE_CRASH;
    }
}

static Task* getNextTask(Task** tasks) {
    Task* task;

    while(true) {
        mNextTaskIndex++;

        task = tasks[mNextTaskIndex];

        if(task == NULL) {
            mNextTaskIndex = -1;
            continue;
        }

        if(task->priority == 0) {
            task->priority = PRIORITY_MEDIUM;
        }

        if(task->tokens >= task->priority) {
            task->tokens -= task->priority;
            break;
        }

        task->tokens++;
    }

    return task;
}

static inline TaskFunction processState(Task* task) {
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

ISR(WDT_vect) {
    if(mTaskIsActive) {
        longjmp(mHaltJmp, 1);
    }
}
