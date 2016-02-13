#ifndef NBAVR_MICROINT_H
#define NBAVR_MICROINT_H

#include <stdint.h>

typedef struct {
    void (*function)(uint16_t);
    uint16_t code;
    uint16_t tick;
} MicroInt;

#endif
