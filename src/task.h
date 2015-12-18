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

struct Task;

typedef void (*TaskFunction)(struct Task*, uint32_t);

typedef struct Task {
    void* const data;
    const uint16_t dataSize;
    const TaskFunction setup;
    const TaskFunction loop;
    const TaskFunction crash;
    TaskPriority priority;
    TaskState state;
    Stream** inputStreams;
    uint8_t inputStreamCount;
    Stream** outputStreams;
    uint8_t outputStreamCount;
} Task;

#endif
