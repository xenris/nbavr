#ifndef LEDTASK_H
#define LEDTASK_H

#include <nbavr.h>

struct LEDData {
    bool initialised;
    InputStream* serial;
    uint32_t ledPulseTime;
};

typedef struct LEDData LEDData;

bool ledTask(void* data, uint32_t millis);

#endif
