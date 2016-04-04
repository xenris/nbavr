#include "servo.h"

static void loop(void);
static void end(int code);

// Servo module has no setup because the list of servos may be initialised
//  before this setup is called, and the servos need to be remembered even if
//  this module is reset.

// Servos have a range of -128 to 127.

static int8_t servoCount;
static Pin servoPins[MAX_SERVOS];
static int8_t servoPositions[MAX_SERVOS];
static const int16_t servoMinTime = 600;
static const int16_t servoMaxTime = 2400;
static const int16_t servoUpdateDelay = 20;

Task servoTask = {
    .loop = loop,
    .priority = PRIORITY_LOW,
};

static void loop(void) {
    for(int8_t i = 0; i < servoCount; i++) {
        Pin pin = servoPins[i];

        pinSet(pin, High);

        int16_t position = servoPositions[i];

        int16_t middle = (servoMaxTime + servoMinTime) / 2;
        int16_t range = servoMaxTime - servoMinTime;
        int16_t adjust = position * (range / 256);

        int16_t us = middle + adjust;

        addInterrupt(end, pin, us);
    }

    delayMillis(servoUpdateDelay);
}

static void end(int code) {
    pinSet(code, Low);
}

int8_t servoAdd(Pin pin) {
    if(servoCount >= MAX_SERVOS) {
        return -1;
    }

    pinDirection(pin, Output);
    pinSet(pin, Low);

    servoPins[servoCount] = pin;
    servoPositions[servoCount] = 0;

    return servoCount++;
}

void servoSet(int8_t servo, int8_t position) {
    if((servo >= 0) && (servo < servoCount)) {
        servoPositions[servo] = position;
    }
}

int8_t servoGet(int8_t servo) {
    if((servo >= 0) && (servo < servoCount)) {
        return servoPositions[servo];
    }

    return 0;
}
