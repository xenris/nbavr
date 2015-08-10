#include "taskmanager.h"


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

void taskManagerCheckForCrashes();

static Task* mCurrentTask;

TaskManager* taskManagerInit(uint8_t maxTasks) {
    MCUSR &= (uint8_t)~_BV(WDRF);
    wdt_enable(WDTO_2S);

    taskManagerCheckForCrashes();

    TaskManager* taskManager = calloc(1, sizeof(TaskManager));
    taskManager->maxTasks = maxTasks;
    taskManager->tasks = calloc(maxTasks, sizeof(Task));

    WDTCSR |= _BV(WDIE);

    return taskManager;
}

bool taskManagerAddTask(TaskManager* taskManager, TaskFunction taskFunction, TaskInit taskInit, const char* id, TaskPriority priority) {
    for(uint8_t i = 0; i < taskManager->maxTasks; i++) {
        Task* task = &taskManager->tasks[i];

        if(task->taskFunction == NULL) {
            task->taskFunction = taskFunction;
            task->data = (taskInit != NULL) ? taskInit() : NULL;
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
        wdt_reset();

        for(uint8_t i = 0; i < taskManager->maxTasks; i++) {
            Task* task = &taskManager->tasks[i];

            if(task->active) {
                if((priorityIndex % task->priority) == 0) {
                    mCurrentTask = task;

                    task->active = task->taskFunction(task->data);
                }
            }

            mCurrentTask = NULL;
        }

        // priorityIndex counts from 1 to PRIORITY_LOW.
        priorityIndex = (priorityIndex % PRIORITY_LOW) + 1;
    }
}

void taskManagerCheckForCrashes() {
    uint16_t addr = eeprom_read_word((uint16_t*)0);

    if(addr != 0xFFFF) {
        uint8_t str[20];
        eeprom_read_block(str, (uint8_t*)2, 20);
        str[19] = 0;

        printf("Halt occurred during task \"%s\" at address: %x\n", str, addr);

        while(true);
    }
}

ISR(WDT_vect, ISR_NAKED) {
    register uint8_t* stackptr = (uint8_t*)SP;

    stackptr++;

    uint16_t addr = (*stackptr << 8) | *(stackptr + 1);
    addr *= 2;

    eeprom_write_word((uint16_t*)0, addr);
    if((mCurrentTask != NULL) && (mCurrentTask->id != NULL)) {
        eeprom_write_block(mCurrentTask->id, (uint8_t*)2, strlen(mCurrentTask->id) + 1);
    } else {
        eeprom_write_block("NULL", (uint8_t*)2, strlen("NULL") + 1);
    }

    // Second watchdog timeout triggers a full reset.
    while(true);
}
