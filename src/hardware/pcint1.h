#ifndef NBAVR_PCINT1_H
#define NBAVR_PCINT1_H

#include "chip.h"

#ifdef CHIP_PC_INT_1

#define PC_INT_ID 1
#include "pcintn.h"
#undef PC_INT_ID

#endif // CHIP_PC_INT_1

#endif
