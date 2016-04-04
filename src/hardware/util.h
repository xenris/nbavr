#ifndef NBAVR_UTIL_H
#define NBAVR_UTIL_H

#include <stdint.h>
#include <util/atomic.h>

#define CONCAT_(A,B,C) A ## B ## C
#define CONCAT(A,B,C) CONCAT_(A,B,C)

#define atomic ATOMIC_BLOCK(ATOMIC_RESTORESTATE)

void setBit(uint8_t* reg, uint8_t bit, uint8_t value) __attribute__((always_inline));

#endif
