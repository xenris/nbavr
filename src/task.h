#ifndef TASK_H
#define TASK_H

#include <stdint.h>
#include <stdbool.h>

#include "stream.h"

typedef enum {
    PRIORITY_DRIVER = 1,
    PRIORITY_HIGH = 5,
    PRIORITY_MEDIUM = 10,
    PRIORITY_LOW = 20,
} TaskPriority;

typedef enum {
    STATE_SETUP = 0,
    STATE_LOOP,
    STATE_CRASH,
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
