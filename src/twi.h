#ifndef TWI_H
#define TWI_H

#include "../config.h"

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <util/twi.h>
#include <avr/interrupt.h>

typedef struct TWIAction {
    uint8_t rw;
    uint8_t addr;
    uint8_t count;
    uint8_t* data;
    struct TWIAction* next;
} TWIAction;

#define TWI_BUSY 1
#define TWI_SUCCESS 2
#define TWI_FAIL 3

#define TWI_READ TW_READ
#define TWI_WRITE TW_WRITE

void twiInit(uint16_t kHz);
bool twiDoAction(TWIAction* action, uint8_t* status);

#endif
