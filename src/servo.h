#ifndef NBAVR_SERVO_H
#define NBAVR_SERVO_H

#include <nbavr.h>

extern Task servoTask;

int8_t servoAdd(Pin pin);
void servoSet(int8_t servo, int8_t position);
int8_t servoGet(int8_t servo);

#endif
