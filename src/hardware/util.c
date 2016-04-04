#include "util.h"

void setBit(uint8_t* reg, uint8_t bit, uint8_t value) {
    if(value) {
        *reg |= _BV(bit);
    } else {
        *reg &= ~_BV(bit);
    }
}
