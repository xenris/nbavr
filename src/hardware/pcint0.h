#ifndef NBAVR_PCINT0_H
#define NBAVR_PCINT0_H

#include "chip.h"

#ifdef CHIP_PC_INT_0

#define PC_INT_ID 0
#include "pcintn.h"
#undef PC_INT_ID

#endif // CHIP_PC_INT_0

#endif
