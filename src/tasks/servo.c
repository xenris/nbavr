#include "servo.h"

static void loop(void);
static void end(int code);

// Servo module has no setup because the list of servos may be initialised
//  before this setup is called, and the servos need to be remembered even if
//  this module is reset.

// Servos have a range of -128 to 127.

static bool servoEnable[MAX_SERVOS];
static Pin servoPins[MAX_SERVOS];
static int8_t servoPositions[MAX_SERVOS];
static const int16_t servoMinTime = US_TO_TICKS(600);
static const int16_t servoMaxTime = US_TO_TICKS(2400);
static const int16_t servoUpdateDelay = MS_TO_TICKS(20);

Task servoTask = {
    .loop = loop,
};

static void loop(void) {
    for(int8_t i = 0; i < MAX_SERVOS; i++) {
        if(!servoEnable[i]) {
            continue;
        }

        Pin pin = servoPins[i];

        pinSet(pin, High);

        int16_t position = servoPositions[i];

        int16_t middle = (servoMaxTime + servoMinTime) / 2;
        int16_t range = servoMaxTime - servoMinTime;
        int16_t adjust = position * (range / 256);

        int16_t ticks = middle + adjust;

        addInterrupt(end, pin, ticks);
    }

    delay(&servoTask, servoUpdateDelay);
}

static void end(int code) {
    pinSet(code, Low);
}

int8_t servoAdd(Pin pin) {
    int8_t servo = 0;

    while(servoEnable[servo]) {
        servo++;

        if(servo >= MAX_SERVOS) {
            return -1;
        }
    }

    servoEnable[servo] = true;

    pinDirection(pin, Output);
    pinSet(pin, Low);

    servoPins[servo] = pin;
    servoPositions[servo] = 0;

    return servo;
}

void servoRemove(int8_t servo) {
    if((servo >= 0) && (servo < MAX_SERVOS)) {
        servoEnable[servo] = false;
        pinSet(servoPins[servo], Low);
    }
}

void servoSet(int8_t servo, int8_t position) {
    if((servo >= 0) && (servo < MAX_SERVOS)) {
        servoPositions[servo] = position;
    }
}

int8_t servoGet(int8_t servo) {
    if((servo >= 0) && (servo < MAX_SERVOS)) {
        return servoPositions[servo];
    }

    return 0;
}
