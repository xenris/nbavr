#include "servo.h"

// Servo module has no setup because the list of servos may be initialised
//  before this setup is called, and the servos need to be remembered even if
//  this module is reset.

// Servos have a range of -128 to 127.
// Servo speed is a number between 0 and 255, slowest to fastest. Speed is the
//  maximum step size done each cycle.

#define SERVO_MIN_TIME US_TO_TICKS(600)
#define SERVO_MAX_TIME US_TO_TICKS(2400)
#define SERVO_UPDATE_DELAY MS_TO_TICKS(20)

#define abs(n) ((n) < 0 ? -(n) : (n))

typedef struct {
    bool enabled;
    Pin pin;
    // Where it is currently set to.
    int8_t position;
    // Where it is aiming for.
    int8_t goal;
    uint8_t speed;
} ServoData;

static struct {
    ServoData servos[MAX_SERVOS];
    uint8_t index;
    uint16_t start;
} state;

static void loop(void);
static void updatePosition(ServoData* servoData);
static void pulseServo(ServoData* servoData);
static void end(int16_t code);

Task servoTask = {
    .loop = loop,
};

static void loop(void) {
    if(state.index == 0) {
        state.start = getTicks16();
    }

    if(state.index < MAX_SERVOS) {
        ServoData* servoData = &state.servos[state.index];

        if(servoData->enabled) {
            updatePosition(servoData);
            pulseServo(servoData);

            sleep(&servoTask);
        }

        state.index += 1;
    } else {
        state.index = 0;

        uint16_t diff = getTicks16() - state.start;

        if(diff < SERVO_UPDATE_DELAY) {
            delay(&servoTask, SERVO_UPDATE_DELAY - diff);
        }
    }
}

static void updatePosition(ServoData* servoData) {
    if(servoData->position != servoData->goal) {
        int16_t step = servoData->speed;
        int16_t diff = servoData->position - servoData->goal;
        diff = abs(diff);

        if(diff < step) {
            servoData->position = servoData->goal;
        } else {
            if(servoData->goal < servoData->position) {
                step = -step;
            }

            servoData->position += step;
        }

    }
}

static void pulseServo(ServoData* servoData) {
    int16_t middle = (SERVO_MAX_TIME + SERVO_MIN_TIME) / 2;
    int16_t range = SERVO_MAX_TIME - SERVO_MIN_TIME;
    int16_t adjust = servoData->position * (range / 256);

    int16_t ticks = middle + adjust;

    atomic {
        if(addInterrupt_(end, servoData->pin, ticks)) {
            pinSet(servoData->pin, High);
        }
    }
}

static void end(int16_t code) {
    pinSet(code, Low);
    wake(&servoTask);
}

Servo servoAdd(Pin pin) {
    Servo servo = {0};

    while(state.servos[servo.id].enabled) {
        servo.id++;

        if(servo.id >= MAX_SERVOS) {
            return (Servo){-1};
        }
    }

    ServoData* servoData = &state.servos[servo.id];

    servoData->enabled = true;

    pinDirection(pin, Output);
    pinSet(pin, Low);

    servoData->pin = pin;
    servoData->goal = 0;
    servoData->position = 0;
    servoData->speed = 255;

    return servo;
}

void servoRemove(Servo servo) {
    if((servo.id >= 0) && (servo.id < MAX_SERVOS)) {
        ServoData* servoData = &state.servos[servo.id];

        servoData->enabled = false;
        pinSet(servoData->pin, Low);
    }
}

void servoSet(Servo servo, int8_t goal) {
    if((servo.id >= 0) && (servo.id < MAX_SERVOS)) {
        state.servos[servo.id].goal = goal;
    }
}

int8_t servoGet(Servo servo) {
    if((servo.id >= 0) && (servo.id < MAX_SERVOS)) {
        return state.servos[servo.id].goal;
    }

    return 0;
}

void servoSetSpeed(Servo servo, uint8_t speed) {
    if((servo.id >= 0) && (servo.id < MAX_SERVOS)) {

        state.servos[servo.id].speed = speed;
    }
}

uint8_t servoGetSpeed(Servo servo) {
    if((servo.id >= 0) && (servo.id < MAX_SERVOS)) {
        return state.servos[servo.id].speed;
    }

    return 0;
}
