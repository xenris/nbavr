#ifndef NBAVR_CLOCK_H
#define NBAVR_CLOCK_H

#include <stdint.h>
#include <util/atomic.h>

void clockInit(uint16_t microsPerTick);
void clockTick();
uint32_t clockMillis();

#endif
