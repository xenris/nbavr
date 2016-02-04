#ifndef NBAVR_TIMER_H
#define NBAVR_TIMER_H

#include "hardware.h"

void timerSetup();
bool addInterrupt(void (*function)(void), uint16_t us);

#endif
