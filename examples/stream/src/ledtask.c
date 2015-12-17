#include "ledtask.h"

#define PULSE_LENGTH 50

static struct {
    uint32_t ledPulseTime;
} mData;

static void setup(Task* task, uint32_t millis);
static void loop(Task* task, uint32_t millis);

Task ledTask = {&mData, sizeof(mData), setup, NULL, PRIORITY_MEDIUM, NULL, 0, NULL, 0};

static void setup(Task* task, uint32_t millis) {
    pinDirection(PinB5, Output);

    task->function = loop;
}

static void loop(Task* task, uint32_t millis) {
    uint8_t c;

    if(streamPop(task->inputStreams[0], &c)) {
        mData.ledPulseTime = millis + PULSE_LENGTH;
    }

    bool on = !(millis > mData.ledPulseTime);
    pinSet(PinB5, on ? High : Low);

    return true;
}
