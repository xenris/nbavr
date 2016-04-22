#ifndef NBAVR_TASK_H
#define NBAVR_TASK_H

#include <stdint.h>
#include <stdbool.h>

typedef enum {
    TaskPriorityDriver = 1,
    TaskPriorityHigh = 5,
    TaskPriorityMedium = 10,
    TaskPriorityLow = 20,
} TaskPriority;

typedef enum {
    TaskStateSetup = 0,
    TaskStateLoop,
    TaskStateCrash,
} TaskState;

typedef void (*TaskFunction)(void);

typedef struct Task {
    const TaskFunction setup;
    const TaskFunction loop;
    const TaskFunction crash;
    TaskPriority priority;
    uint8_t tokens;
    TaskState state;
    uint32_t delay;
} Task;

#endif
