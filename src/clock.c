#include "clock.h"

// TODO Make clock more accurate by accessing the timer's counter.

static volatile uint32_t mMillis;
static volatile uint16_t mMicros;
static uint16_t mMicrosPerTick;

void clockInit(uint16_t microsPerTick) {
    mMicrosPerTick = microsPerTick;
    mMillis = 0;
    mMicros = 0;
}

void clockTick() {
    mMicros += mMicrosPerTick;

    while(mMicros >= 1000) {
        mMicros -= 1000;
        mMillis++;
    }
}

uint32_t clockMillis() {
    uint32_t millis;

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        millis = mMillis;
    }

    return millis;
}
