#include "ledtask.h"

#define PULSE_LENGTH 50

static void setup(void);
static void loop(void);

Task ledTask = {
    .setup = setup,
    .loop = loop,
};

static void setup(void) {
    pinDirection(PinB5, Output);
}

static void loop(void) {
    pinSet(PinB5, Low);

    uint8_t c;

    if(streamPop(stdin, &c)) {
        streamClear(stdin);
        pinSet(PinB5, High);
        delayMillis(PULSE_LENGTH);
    }
}
