#ifndef NBAVR_PCINT2_H
#define NBAVR_PCINT2_H

#include "chip.h"

#ifdef CHIP_PC_INT_2

#define PC_INT_ID 2
#include "pcintn.h"
#undef PC_INT_ID

#endif // CHIP_PC_INT_2

#endif
