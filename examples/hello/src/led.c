#include "led.h"

static void setup(void);
static void loop(void);

static const Pin ledPin = PinB5;

Task ledTask = {
    .setup = setup,
    .loop = loop,
};

static void setup(void) {
    pinDirection(ledPin, Output);
}

static void loop(void) {
    pinToggle(ledPin);
    delay(&ledTask, MS_TO_TICKS(500));
}
