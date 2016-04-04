#ifndef NBAVR_TIMER1_H
#define NBAVR_TIMER1_H

#include "chip.h"

#ifdef CHIP_TIMER_1

#define TIMER_ID 1
#include "timern.h"
#undef TIMER_ID

#endif // CHIP_TIMER_1

#endif
