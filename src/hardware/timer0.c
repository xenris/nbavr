#include "timer0.h"

#include "chip.h"

#ifdef CHIP_TIMER_0

#define TIMER_ID 0
#include "timern.t"
#undef TIMER_ID

#endif // CHIP_TIMER_0
