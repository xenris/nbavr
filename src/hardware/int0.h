#ifndef NBAVR_INT0_H
#define NBAVR_INT0_H

#include "chip.h"

#ifdef CHIP_INT_0

#define INT_ID 0
#include "intn.h"
#undef INT_ID

#endif // CHIP_INT_0

#endif
