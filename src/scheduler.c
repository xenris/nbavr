#include "scheduler.h"

Task* getNextTask(void) {
    Task* task;

    while(true) {
        state.taskIndex++;

        task = state.tasks[state.taskIndex];

        if(task == NULL) {
            state.taskIndex = -1;
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
