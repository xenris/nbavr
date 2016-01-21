#include "taskmanager.h"

static void taskManagerProcessTask(Task* task);
static Task* getRandomTask(Task** tasks, uint8_t taskCount);
inline TaskFunction processState(Task* task);

static bool mTaskIsActive;
static jmp_buf mHaltJmp;

void taskManagerRun(Task** tasks, uint8_t taskCount) {
    resetClearStatus();

    watchdog(WATCHDOG_16MS, WATCHDOG_INTERRUPT_RESET);

    while(true) {
        watchdogReset();
        watchdogInterruptEnable(true);
        sei();

        Task* task = getRandomTask(tasks, taskCount);

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
            f(task);
        }

        mTaskIsActive = false;
    } else if(jmp == 1) { // Task halted.
        task->state = STATE_CRASH;
    } else { // Watchdog interrupt, but no task running.
        // Do nothing.
    }
}

static Task* getRandomTask(Task** tasks, uint8_t taskCount) {
    int sum = 0;
    for(uint8_t i = 0; i < taskCount; i++) {
        Task* task = tasks[i];

        // If no priority set then set it to medium.
        if(task->priority == 0) {
            task->priority = PRIORITY_MEDIUM;
        }

        sum += (PRIORITY_LOW + 1) - task->priority;
    }

    if(sum == 0) {
        return NULL;
    }

    int r = (rand() % sum) + 1;
    int t = 0;

    for(uint8_t i = 0; i < taskCount; i++) {
        Task* task = tasks[i];

        t += (PRIORITY_LOW + 1) - task->priority;

        if(t >= r) {
            return task;
        }
    }

    return NULL;

// XXX This system takes up HEAPS of cpu time
// If something like this could be done with only integers that would be better.
//    Task* result = NULL;
//    float k = 0;

//    for(uint8_t i = 0; i < taskManager->maxTasks; i++) {
//        Task* task = &taskManager->tasks[i];

//        if(task->active) {
//            const float r = (float)rand() / (float)RAND_MAX;
//            const float p = (PRIORITY_LOW + 1) - task->priority;
//            k += p;

//            if((p / k) >= r) {
//                result = task;
//            }
//        }
//    }

//    return result;
}

inline TaskFunction processState(Task* task) {
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
    longjmp(mHaltJmp, mTaskIsActive ? 1 : 2);
}
