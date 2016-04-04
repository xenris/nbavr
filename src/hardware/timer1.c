#include "timer1.h"

#include "chip.h"

#ifdef CHIP_TIMER_1

#define TIMER_ID 1
#include "timern.t"
#undef TIMER_ID

#endif // CHIP_TIMER_1
