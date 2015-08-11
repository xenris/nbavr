#ifndef TWI_H
#define TWI_H

#include "../config.h"

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>
#include <util/twi.h>

#include "taskmanager.h"

typedef enum {
    TWI_READ = TW_READ,
    TWI_WRITE = TW_WRITE,
} TWIDirection;

typedef struct TWIAction {
    TWIDirection rw;
    uint8_t addr;
    uint8_t count;
    uint8_t* data;
    struct TWIAction* next;
} TWIAction;

#define TWI_QUEUED 0
#define TWI_BUSY 1
#define TWI_SUCCESS 2
#define TWI_FAIL 3

void twiInit(TaskManager* taskManager, uint16_t kHz);
bool twiDoAction(TWIAction* action, volatile uint8_t* status);

#endif
