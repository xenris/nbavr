#include "led.h"

static struct {
    uint32_t delay;
} mData;

static const Pin ledPin = PinB5;

static void setup(Task* task);
static void loop(Task* task);

Task ledTask = {
    .data = &mData,
    .dataSize = sizeof(mData),
    .setup = setup,
    .loop = loop,
    .priority = PRIORITY_LOW,
};

static void setup(Task* task) {
    pinDirection(ledPin, Output);
    mData.delay = 1000;
}

static void loop(Task* task) {
    uint32_t millis = getMillis();

    if(mData.delay <= millis) {
        pinToggle(ledPin);
        mData.delay = millis + 1000;
    }
}
