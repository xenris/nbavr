#ifndef NBAVR_MICROINT_H
#define NBAVR_MICROINT_H

#include <stdint.h>

typedef struct {
    void (*function)(void);
    uint16_t tick;
} MicroInt;

#endif
