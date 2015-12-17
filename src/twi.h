#ifndef TWI_H
#define TWI_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <util/twi.h>

#include "taskmanager.h"

typedef enum {
    TWI_READ = TW_READ,
    TWI_WRITE = TW_WRITE,
} TWIDirection;

typedef enum {
    TWI_QUEUED,
    TWI_BUSY,
    TWI_SUCCESS,
    TWI_FAIL,
} TWIResult;

typedef struct TWIAction {
    TWIDirection rw;
    uint8_t addr;
    uint8_t count;
    uint8_t* data;
    struct TWIAction* next;
} TWIAction;

bool twiDoAction(TWIAction* action, volatile TWIResult* result);

extern Task twiTask;

#endif
