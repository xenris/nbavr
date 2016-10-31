#ifndef NBAVR_TASK_H
#define NBAVR_TASK_H

#include <stdint.h>
#include <stdbool.h>

typedef enum __attribute__((packed)) {
    TaskStateSetup,
    TaskStateLoop,
    TaskStateCrash,
} TaskState;

typedef enum __attribute__((packed)) {
    SleepStateAwake,
    SleepStateDelay,
    SleepStateSleep,
} SleepState;

typedef void (*TaskFunction)(void);

typedef struct __attribute__((packed)) {
    const TaskFunction setup;
    const TaskFunction loop;
    const TaskFunction crash;
    TaskState state;
    SleepState sleepState;
    uint32_t wakeTick;
} Task;

#endif
