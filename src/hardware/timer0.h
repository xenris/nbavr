#ifndef NBAVR_TIMER0_H
#define NBAVR_TIMER0_H

#include "chip.h"

#ifdef CHIP_TIMER_0

#define TIMER_ID 0
#include "timern.h"
#undef TIMER_ID

#endif // CHIP_TIMER_0

#endif
