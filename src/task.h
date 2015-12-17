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

struct Task;

typedef void (*TaskFunction)(struct Task*, uint32_t);
// TODO Pass in info indicating the cause of the crash. (Halt, memory, etc...)
// TODO Implement crash handling feature.
//  Somehow needs to reset the task after the crash function is called.
typedef void (*CrashFunction)(struct Task*);

typedef struct Task {
    void* data;
    uint16_t dataSize;
    TaskFunction function;
    CrashFunction crash;
    TaskPriority priority;
    Stream** inputStreams;
    uint8_t inputStreamCount;
    Stream** outputStreams;
    uint8_t outputStreamCount;
} Task;

#endif
