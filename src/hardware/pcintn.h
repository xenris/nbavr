#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "util.h"

#define pcintN(A) CONCAT(pcint,PC_INT_ID,A)
#define PC_INT_N(A) CONCAT(CHIP_PC_INT_,PC_INT_ID,A)

typedef void (*PCIntCallback)(void);

void pcintN()(uint8_t active, PCIntCallback callback) __attribute__((always_inline));
