#ifndef NBAVR_TIMING_H
#define NBAVR_TIMING_H

// Every clock cycle is 1 / freq seconds. (62.5ns at 16MHz)
// Every 64 clock cycles is a tick. (4us at 16MHz)
// Every 2^16 ticks is a tock. (262.144ms at 16MHz)
// Every 2^32 ticks the clock overflows. (4.77 hours at 16Mhz)

#include <config.h>
#include <stddef.h>
#include "hardware.h"

#define DIVISOR 64UL
#define F_CPU_MHZ (F_CPU / 1000000UL)
#define OVERFLOW_TIME ((65536UL / F_CPU_MHZ) * DIVISOR)

#define US_TO_TICKS(us) (((us) + (DIVISOR / F_CPU_MHZ / 2)) / (DIVISOR / F_CPU_MHZ))
#define MS_TO_TICKS(ms) (US_TO_TICKS((ms) * 1000UL))

#define TICKS_TO_US(ts) ((ts) * (DIVISOR / F_CPU_MHZ))
#define TICKS_TO_MS(ts) (TICKS_TO_US(ts) / 1000UL)

#define TICKS_TO_TOCKS(t) (((t) + 32768UL) / 65536UL)
#define TOCKS_TO_TICKS(t) ((t) * 65536UL)

void setupTicks();
uint16_t getTicks16(void) __attribute__((always_inline));
uint32_t getTicks(void) __attribute__((always_inline));
uint32_t getTicks_(void);
uint16_t getTocks(void);
bool addInterrupt(void (*callback)(int16_t), int16_t code, uint16_t ticks);
void enableHaltInterrupt(uint16_t tick);
void disableHaltInterrupt(void);

#endif
