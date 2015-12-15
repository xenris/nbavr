#ifndef TASK2_H
#define TASK2_H

#include <nbavr.h>

typedef struct {
    bool initialised;
    uint32_t delay;
    uint8_t count;
    OutputStream* outputStream;
} Task2Data;

bool task2(void* data, uint32_t millis);

#endif
