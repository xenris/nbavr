#ifndef NBAVR_SERVO_H
#define NBAVR_SERVO_H

#include <nbavr.h>

typedef struct {
    int8_t id;
} Servo;

extern Task servoTask;

Servo servoAdd(Pin pin);
void servoRemove(Servo servo);
void servoSet(Servo servo, int8_t position);
int8_t servoGet(Servo servo);
void servoSetSpeed(Servo servo, uint8_t speed);
uint8_t servoGetSpeed(Servo servo);

#endif
