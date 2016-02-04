#ifndef NBAVR_RESET_H
#define NBAVR_RESET_H

static inline bool resetWasWatchdog() {
    return MCUSR & _BV(WDRF);
}

static inline bool resetWasBrownout() {
    return MCUSR & _BV(BORF);
}

static inline bool resetWasExternal() {
    return MCUSR & _BV(EXTRF);
}

static inline bool resetWasPoweron() {
    return MCUSR & _BV(PORF);
}

static inline uint8_t resetStatus() {
    return MCUSR;
}

static inline void resetClearStatus() {
    MCUSR = 0;
}

#endif
