#ifndef NBAVR_WATCHDOG_HPP
#define NBAVR_WATCHDOG_HPP

// TODO Add enum class to indicate what sort of reset occured.

uint8_t _resetStatus __attribute__((section(".noinit")));

force_inline void _wdt_reset() {
    __asm__ __volatile__ ("wdr");
}

force_inline void _wdt_enable() {
    _wdt_reset();

    *CHIP_WATCHDOG_TIMER_CONTROL_REG = bv(CHIP_WATCHDOG_TIMER_ENABLE_BIT);
}

force_inline void _wdt_disable() {
    _wdt_reset();

    *CHIP_WATCHDOG_TIMER_CONTROL_REG = bv(CHIP_WATCHDOG_TIMER_CHANGE_ENABLE_BIT) | bv(CHIP_WATCHDOG_TIMER_ENABLE_BIT);

    *CHIP_WATCHDOG_TIMER_CONTROL_REG = 0;
}

void _getResetStatus() __attribute__((used, naked, section(".init3")));
void _getResetStatus() {
   _resetStatus = *CHIP_RESET_STATUS_REG;
   *CHIP_RESET_STATUS_REG = 0;

   _wdt_disable();
}

#endif
