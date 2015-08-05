#ifndef MILLIS_H
#define MILLIS_H

// Uses the 16bit Timer/Counter1 to get the number of milliseconds since
//  millisInit was called, or based on the time set in millisSet.

#include <avr/interrupt.h>
#include <util/atomic.h>

#include "../config.h"

void millisInit();
uint32_t millis();
void millisSet(uint32_t m);

#endif
