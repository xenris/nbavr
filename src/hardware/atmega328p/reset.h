#ifndef NBAVR_RESET_H
#define NBAVR_RESET_H

inline bool resetWasWatchdog() {
    return MCUSR & _BV(WDRF);
}

inline bool resetWasBrownout() {
    return MCUSR & _BV(BORF);
}

inline bool resetWasExternal() {
    return MCUSR & _BV(EXTRF);
}

inline bool resetWasPoweron() {
    return MCUSR & _BV(PORF);
}

inline uint8_t resetStatus() {
    return MCUSR;
}

inline void resetClearStatus() {
    MCUSR = 0;
}

#endif
