#include "scheduler.h"

Task* getNextTask(void) {
    Task* task;

    while(true) {
        kernel.taskIndex++;

        task = kernel.tasks[kernel.taskIndex];

        if(task == NULL) {
            kernel.taskIndex = -1;
            continue;
        }

        if(task->priority == 0) {
            task->priority = TaskPriorityMedium;
        }

        if(task->tokens >= task->priority) {
            task->tokens -= task->priority;
            break;
        }

        task->tokens++;
    }

    return task;
}

void setPriority(TaskPriority priority) {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        if(kernel.currentTask != NULL) {
            kernel.currentTask->priority = priority;
        }
    }
}
