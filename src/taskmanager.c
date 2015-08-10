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

bool taskManagerAddTask(TaskManager* taskManager, TaskFunction taskFunction, void* data, const char* id, TaskPriority priority) {
    for(uint8_t i = 0; i < taskManager->maxTasks; i++) {
        Task* task = &taskManager->tasks[i];

        if(!task->active) {
            task->taskFunction = taskFunction;
            task->data = data;
            task->id = id;
            task->priority = priority;
            task->active = true;

            return true;
        }
    }

    return false;
}

void taskManagerRun(TaskManager* taskManager) {
    uint8_t priorityIndex = 1;

    while(true) {
        uint32_t millis;

        ATOMIC_BLOCK(ATOMIC_FORCEON) {
            millis = mMillis;
        }

        for(uint8_t i = 0; i < taskManager->maxTasks; i++) {
            Task* task = &taskManager->tasks[i];

            if(task->active) {
                if((priorityIndex % task->priority) == 0) {
                    taskManagerProcessTask(task, millis);
                }
            }
        }

        // priorityIndex counts from 1 to PRIORITY_LOW.
        priorityIndex = (priorityIndex % PRIORITY_LOW) + 1;
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
}

ISR(TIMER1_COMPA_vect) {
    mMillis++;
    mTaskTimeCounter++;

    if((mCurrentTask != NULL) && (mTaskTimeCounter >= MAX_TASK_TIME)) {
        longjmp(mHaltJmp, 1);
    }
}
