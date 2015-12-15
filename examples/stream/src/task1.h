#ifndef TASK1_H
#define TASK1_H

#include <nbavr.h>

typedef struct {
    bool initialised;
    uint32_t delay;
    uint16_t count;
    InputStream* inputStream;
    OutputStream* printStream;
} Task1Data;

bool task1(void* data, uint32_t millis);

#endif
