#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "util.h"

#define intN(A) CONCAT(int,INT_ID,A)
#define INT_N(A) CONCAT(CHIP_INT_,INT_ID,A)

#ifndef INT_TRIGGER_ENUM
#define INT_TRIGGER_ENUM
typedef enum {
    IntTriggerLow = INT_N(_TRIGGER_LOW_ID),
    IntTriggerChange = INT_N(_TRIGGER_CHANGE_ID),
    IntTriggerFalling = INT_N(_TRIGGER_FALLING_ID),
    IntTriggerRising = INT_N(_TRIGGER_RISING_ID),
    IntDisable,
} IntTrigger;
#endif

typedef void (*IntCallback)(void);

void intN()(IntTrigger trigger, IntCallback callback) __attribute__((always_inline));
