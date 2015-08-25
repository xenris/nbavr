#ifndef TASK_H
#define TASK_H

#include <stdint.h>
#include <stdbool.h>

typedef enum {
    PRIORITY_DRIVER = 1,
    PRIORITY_HIGH = 5,
    PRIORITY_MEDIUM = 10,
    PRIORITY_LOW = 20,
} TaskPriority;

typedef bool (*TaskFunction)(void*, uint32_t);

#endif
