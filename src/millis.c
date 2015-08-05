#include "millis.h"

static volatile uint32_t mMillis;

void millisInit() {
    TIMSK1 |= _BV(OCIE1A);
    OCR1A = 16000;
    TCCR1B = _BV(CS10) | _BV(WGM12);
}

uint32_t millis() {
    uint32_t m;

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        m = mMillis;
    }

    return m;
}

void millisSet(uint32_t m) {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        mMillis = m;
    }
}

#ifdef INCLUDE_MILLIS

ISR(TIMER1_COMPA_vect) {
    mMillis++;
}

#endif
