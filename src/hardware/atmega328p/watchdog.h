#ifndef NBAVR_WATCHDOG_H
#define NBAVR_WATCHDOG_H

typedef enum {
    WATCHDOG_INTERRUPT = _BV(WDIE),
    WATCHDOG_RESET = _BV(WDE),
    WATCHDOG_INTERRUPT_RESET = _BV(WDE) | _BV(WDIE),
} WatchdogMode;

typedef enum {
    WATCHDOG_16MS = 0,
    WATCHDOG_32MS = _BV(WDP0),
    WATCHDOG_64MS = _BV(WDP1),
    WATCHDOG_125MS = _BV(WDP1) | _BV(WDP0),
    WATCHDOG_250MS = _BV(WDP2),
    WATCHDOG_500MS = _BV(WDP2) | _BV(WDP0),
    WATCHDOG_1S = _BV(WDP2) | _BV(WDP1),
    WATCHDOG_2S = _BV(WDP2) | _BV(WDP1) | _BV(WDP0),
    WATCHDOG_4S = _BV(WDP3),
    WATCHDOG_8S = _BV(WDP3) | _BV(WDP0),
} WatchdogPrescaler;

static inline void watchdogReset() {
    __asm__ __volatile__ ("wdr");
}

static inline void watchdog(WatchdogPrescaler prescaler, WatchdogMode mode) {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        watchdogReset();
        WDTCSR = _BV(WDCE) | _BV(WDE);
        WDTCSR = mode | prescaler;
    }
}

static inline void watchdogDisable() {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        watchdogReset();
        MCUSR &= ~_BV(WDRF);
        WDTCSR = _BV(WDCE) | _BV(WDE);
        WDTCSR = 0x00;
    }
}

static inline void watchdogSystemResetEnable(bool b) {
    if(b) {
        WDTCSR |= _BV(WDE);
    } else {
        WDTCSR &= ~_BV(WDE);
    }
}

static inline void watchdogInterruptEnable(bool b) {
    if(b) {
        WDTCSR |= _BV(WDIE);
    } else {
        WDTCSR &= ~_BV(WDIE);
    }
}

#endif
