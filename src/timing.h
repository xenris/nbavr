#ifndef NBAVR_TIMING_H
#define NBAVR_TIMING_H

#include "hardware.h"

void timingSetup();
bool addInterrupt(void (*function)(void), uint16_t us);
uint32_t getMillis();

#endif
