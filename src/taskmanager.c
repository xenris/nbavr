#include "taskmanager.h"

#define MAX_TASK_TIME 20

static void taskManagerProcessTask(Task* task, uint32_t millis);
static Task* getRandomTask(Task** tasks, uint8_t taskCount);
inline TaskFunction processState(Task* task);

static volatile uint32_t mMillis;
static volatile uint16_t mMicros;
static Task* mCurrentTask;
static jmp_buf mHaltJmp;
static uint8_t mTaskTimeCounter;

void taskManagerRun(Task** tasks, uint8_t taskCount) {
    setupSystemClock();

    while(true) {
        wdt_reset();

        Task* task = getRandomTask(tasks, taskCount);

        uint32_t millis;

        ATOMIC_BLOCK(ATOMIC_FORCEON) {
            millis = mMillis;
        }

        taskManagerProcessTask(task, millis);
    }
}

static void taskManagerProcessTask(Task* task, uint32_t millis) {
    // Save state in case the task halts.
    if(setjmp(mHaltJmp)) {
        // If we are here then the task must have halted.
        task->state = STATE_CRASH;
    } else {
        mTaskTimeCounter = 0;
        mCurrentTask = task;
        TaskFunction f = processState(task);
        if(f != NULL) {
            f(task, millis);
        }
        mCurrentTask = NULL;
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

tickInterrupt {
    mMicros += US_PER_TICK;

    while(mMicros > 1000) {
        mMillis++;
        mTaskTimeCounter++;
        mMicros -= 1000;
    }

    if((mCurrentTask != NULL) && (mTaskTimeCounter >= MAX_TASK_TIME)) {
        longjmp(mHaltJmp, 1);
    }
}
