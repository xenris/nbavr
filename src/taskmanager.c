#include "taskmanager.h"

#define MAX_TASK_TIME 20

// FIXME Streams are a fixed magic number.

typedef struct Task {
    bool active;
    TaskFunction taskFunction;
    void* data;
    uint16_t dataSize;
    const char* id;
    TaskPriority priority;
    InputStream* inputStreams[6];
    OutputStream* outputStreams[6];
} Task;

typedef struct TaskManager {
    uint8_t maxTasks;
    Task* tasks;
} TaskManager;

Task* findTaskById(TaskManager* taskManager, const char* id);
static void taskManagerProcessTask(Task* task, uint32_t millis);
static Task* getRandomActiveTask(TaskManager* taskManager);

static volatile uint32_t mMillis;
static Task* mCurrentTask;
static jmp_buf mHaltJmp;
static uint8_t mTaskTimeCounter;

TaskManager* taskManagerInit(uint8_t maxTasks) {
    setupSystemClock();

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
            task->dataSize = dataSize;
            task->id = id;
            task->priority = priority;
            task->active = true;

            return true;
        }
    }

    return false;
}

bool taskManagerAddStream(TaskManager* taskManager, const char* fromId, const char* toId, const char* streamId, uint8_t bufferSize) {
    Task* fromTask = findTaskById(taskManager, fromId);
    Task* toTask = findTaskById(taskManager, toId);

    if((fromTask == NULL) || (toTask == NULL)) {
        return false;
    }

    RingBuffer* ringBuffer = ringBufferCreate(bufferSize);

    if(ringBuffer == NULL) {
        return false;
    }

    OutputStream* outputStream = outputStreamCreate(streamId, ringBuffer);

    if(outputStream == NULL) {
        free(ringBuffer);
        return false;
    }

    InputStream* inputStream = inputStreamCreate(streamId, ringBuffer);

    if(inputStream == NULL) {
        free(ringBuffer);
        free(outputStream);
        return false;
    }

    bool added = false;

    for(uint8_t i = 0; i < 6; i++) {
        if(fromTask->outputStreams[i] == NULL) {
            fromTask->outputStreams[i] = outputStream;
            added = true;
            break;
        }
    }

    if(!added) {
        free(ringBuffer);
        free(outputStream);
        free(inputStream);
        return false;
    }

    added = false;

    for(uint8_t i = 0; i < 6; i++) {
        if(toTask->inputStreams[i] == NULL) {
            toTask->inputStreams[i] = inputStream;
            added = true;
            break;
        }
    }

    if(!added) {
        free(ringBuffer);
        free(outputStream);
        free(inputStream);
        return false;
    }

    return true;
}

Task* findTaskById(TaskManager* taskManager, const char* id) {
    for(uint8_t i = 0; i < taskManager->maxTasks; i++) {
        Task* task = &taskManager->tasks[i];

        if(task->id == id) {
            return task;
        }
    }

    return NULL;
}

OutputStream* getOutputStream(const char* streamId) {
    if(mCurrentTask != NULL) {
        for(uint8_t i = 0; i < 6; i++) {
            OutputStream* outputStream = mCurrentTask->outputStreams[i];

            if(outputStreamId(outputStream) == streamId) {
                return outputStream;
            }
        }
    }

    return NULL;
}

InputStream* getInputStream(const char* streamId) {
    if(mCurrentTask != NULL) {
        for(uint8_t i = 0; i < 6; i++) {
            InputStream* inputStream = mCurrentTask->inputStreams[i];

            if(inputStreamId(inputStream) == streamId) {
                return inputStream;
            }
        }
    }

    return NULL;
}

OutputStream** getOutputStreams() {
    if(mCurrentTask != NULL) {
        return mCurrentTask->outputStreams;
    }

    return NULL;
}

InputStream** getInputStreams() {
    if(mCurrentTask != NULL) {
        return mCurrentTask->inputStreams;
    }

    return NULL;
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
//        printf("Task \"%s\" was reset because it was taking too long.\n", task->id);
        memset(task->data, 0, task->dataSize);
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

tickInterrupt {
    mMillis++;
    mTaskTimeCounter++;

    if((mCurrentTask != NULL) && (mTaskTimeCounter >= MAX_TASK_TIME)) {
        longjmp(mHaltJmp, 1);
    }
}
