#ifndef NBAVR_INTS_H
#define NBAVR_INTS_H

typedef enum {
    IntLow = 0,
    IntChange = 1,
    IntFalling = 2,
    IntRising = 3,
    IntDisable = 4,
} IntEvent;

static inline void int0(IntEvent event) {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        if(event == IntDisable) {
            EIMSK &= ~_BV(INT0);
        } else {
            uint8_t a = EICRA & (0x03 << ISC00);
            a |= event << ISC00;
            EICRA = a;

            EIMSK |= _BV(INT0);
        }
    }
}

static inline void int1(IntEvent event) {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        if(event == IntDisable) {
            EIMSK &= ~_BV(INT1);
        } else {
            uint8_t a = EICRA & (0x03 << ISC10);
            a |= event << ISC10;
            EICRA = a;

            EIMSK |= _BV(INT1);
        }
    }
}

static inline void pcint0(uint8_t active) {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        PCMSK0 = active;

        if(active == 0) {
            PCICR &= ~_BV(PCIE0);
        } else {
            PCICR |= _BV(PCIE0);
        }
    }
}

static inline void pcint1(uint8_t active) {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        PCMSK1 = active & 0x7F;

        if(active == 0) {
            PCICR &= ~_BV(PCIE1);
        } else {
            PCICR |= _BV(PCIE1);
        }
    }
}

static inline void pcint2(uint8_t active) {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        PCMSK2 = active;

        if(active == 0) {
            PCICR &= ~_BV(PCIE2);
        } else {
            PCICR |= _BV(PCIE2);
        }
    }
}

#endif
