#include "led.h"

static const Pin ledPin = PinB5;

static void setup(Task* task);
static void loop(Task* task);

Task ledTask = {
    .setup = setup,
    .loop = loop,
    .priority = PRIORITY_LOW,
};

static void setup(Task* task) {
    pinDirection(ledPin, Output);
}

static void loop(Task* task) {
    pinToggle(ledPin);
    delayMillis(1000);
}
