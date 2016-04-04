#ifndef NBAVR_TIMER2_H
#define NBAVR_TIMER2_H

#include "chip.h"

#ifdef CHIP_TIMER_2

#define TIMER_ID 2
#include "timern.h"
#undef TIMER_ID

#endif // CHIP_TIMER_2

#endif
