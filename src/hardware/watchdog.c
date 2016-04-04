#include "watchdog.h"

// TODO Confirm that this is being put early in the programme.

uint8_t resetStatus __attribute__ ((section (".noinit")));

void get_mcusr(void) __attribute__((naked)) __attribute__((section(".init3")));

void get_mcusr(void) {
    #ifdef MCUSR
        resetStatus = MCUSR;
        MCUSR = 0;
    #else
        resetStatus = MCUCSR;
        MCUCSR = 0;
    #endif

    wdt_disable();
}
