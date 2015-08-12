#include "taskmanager.h"

#define MAX_TASK_TIME 20

typedef struct Task {
    bool active;
    TaskFunction taskFunction;
    void* data;
    const char* id;
    TaskPriority priority;
} Task;

typedef struct TaskManager {
    uint8_t maxTasks;
    Task* tasks;
} TaskManager;

static void taskManagerProcessTask(Task* task, uint32_t millis);
static Task* getRandomActiveTask(TaskManager* taskManager);

static volatile uint32_t mMillis;
static Task* mCurrentTask;
static jmp_buf mHaltJmp;
static uint8_t mTaskTimeCounter;

TaskManager* taskManagerInit(uint8_t maxTasks) {
    TIMSK1 |= _BV(OCIE1A);
    OCR1A = 16000;
    TCCR1B = _BV(CS10) | _BV(WGM12);

    TaskManager* taskManager = calloc(1, sizeof(TaskManager));
    taskManager->maxTasks = maxTasks;
    taskManager->tasks = calloc(maxTasks, sizeof(Task));

    return taskManager;
}

bool taskManagerAddTask(TaskManager* taskManager, TaskFunction taskFunction, uint16_t dataSize, const char* id, TaskPriority priority) {
    for(uint8_t i = 0; i < taskManager->maxTasks; i++) {
        Task* task = &taskManager->tasks[i];

        if(!task->active) {
            task->taskFunction = taskFunction;
            if(dataSize > 0) {
                task->data = calloc(1, dataSize);
                if(task->data == NULL) {
                    return false;
                }
            } else {
                task->data = NULL;
            }
            task->id = id;
            task->priority = priority;
            task->active = true;

            return true;
        }
    }

    return false;
}

void taskManagerRun(TaskManager* taskManager) {
    while(true) {
        Task* task = getRandomActiveTask(taskManager);

        if(task != NULL) {
            uint32_t millis;

            ATOMIC_BLOCK(ATOMIC_FORCEON) {
                millis = mMillis;
            }

            taskManagerProcessTask(task, millis);
        }
    }
}

static void taskManagerProcessTask(Task* task, uint32_t millis) {
    // Save state in case the task halts.
    if(setjmp(mHaltJmp)) {
        // The folloing task halted if this is running.
        mCurrentTask = NULL;
        printf("Task \"%s\" was stopped because it was taking too long.\n", task->id);
        task->active = false;
    } else {
        mTaskTimeCounter = 0;
        mCurrentTask = task;
        task->active = task->taskFunction(task->data, millis);
        mCurrentTask = NULL;
    }

    if(!task->active) {
        free(task->data);
    }
}

static Task* getRandomActiveTask(TaskManager* taskManager) {
    int sum = 0;
    for(uint8_t i = 0; i < taskManager->maxTasks; i++) {
        Task* task = &taskManager->tasks[i];

        if(task->active) {
            sum += (PRIORITY_LOW + 1) - task->priority;
        }
    }

    if(sum == 0) {
        return NULL;
    }

    int r = (rand() % sum) + 1;
    int t = 0;

    for(uint8_t i = 0; i < taskManager->maxTasks; i++) {
        Task* task = &taskManager->tasks[i];

        if(task->active) {
            t += (PRIORITY_LOW + 1) - task->priority;

            if(t >= r) {
                return task;
            }
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

ISR(TIMER1_COMPA_vect) {
    mMillis++;
    mTaskTimeCounter++;

    if((mCurrentTask != NULL) && (mTaskTimeCounter >= MAX_TASK_TIME)) {
        longjmp(mHaltJmp, 1);
    }
}
