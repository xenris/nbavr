#include "led.h"

static struct {
    uint32_t delay;
} mData;

static void setup(Task* task, uint32_t millis);
static void loop(Task* task, uint32_t millis);

Task ledTask = {&mData, sizeof(mData), setup, NULL, PRIORITY_MEDIUM, NULL, 0, NULL, 0};

static void setup(Task* task, uint32_t millis) {
    pinDirection(PinB5, Output);
    mData.delay = 0;
    task->function = loop;
}

static void loop(Task* task, uint32_t millis) {
    if(millis >= mData.delay) {
        pinToggle(PinB5);
        mData.delay = millis + 1000;
    }
}
