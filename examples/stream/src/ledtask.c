#include "ledtask.h"

#define PULSE_LENGTH 50

static void setup(Task* task);
static void loop(Task* task);

Task ledTask = {
    .setup = setup,
    .loop = loop,
};

static void setup(Task* task) {
    pinDirection(PinB5, Output);
}

static void loop(Task* task) {
    pinSet(PinB5, Low);

    uint8_t c;

    if(streamPop(&stdin, &c)) {
        streamClear(&stdin);
        pinSet(PinB5, High);
        delayMillis(PULSE_LENGTH);
    }
}
