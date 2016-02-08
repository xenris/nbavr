#ifndef NBAVR_TIMING_H
#define NBAVR_TIMING_H

#include "hardware.h"
#include "state.h"

void timingSetup();
bool addInterrupt(void (*function)(void), uint16_t us);
uint32_t getMillis();

#endif
