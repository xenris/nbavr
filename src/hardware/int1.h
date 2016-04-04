#ifndef NBAVR_INT1_H
#define NBAVR_INT1_H

#include "chip.h"

#ifdef CHIP_INT_1

#define INT_ID 1
#include "intn.h"
#undef INT_ID

#endif // CHIP_INT_1

#endif
