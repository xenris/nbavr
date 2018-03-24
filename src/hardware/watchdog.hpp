#ifndef NBOS_WATCHDOG_HPP
#define NBOS_WATCHDOG_HPP

// TODO Add enum class to indicate what sort of reset occured.
// TODO Some things have been excluded from testing. Need to work out how to
//  include them.

namespace nbos::hw {

#ifdef CHIP_WATCHDOG_TIMER_CONTROL_REG

#ifndef TEST
uint8_t _resetStatus __attribute__((section(".noinit")));
#endif

struct Wdt {
    Wdt() = delete;

    static constexpr HardwareType getHardwareType() {
        return HardwareType::wdt;
    }

    static force_inline void reset() {
        #ifndef TEST
        __asm__ __volatile__ ("wdr");
        #endif
    }

    static force_inline void enable() {
        reset();

        *CHIP_WATCHDOG_TIMER_CONTROL_REG = bv(CHIP_WATCHDOG_TIMER_ENABLE_BIT);
    }

    static force_inline void disable() {
        reset();

        *CHIP_WATCHDOG_TIMER_CONTROL_REG = bv(CHIP_WATCHDOG_TIMER_CHANGE_ENABLE_BIT) | bv(CHIP_WATCHDOG_TIMER_ENABLE_BIT);

        *CHIP_WATCHDOG_TIMER_CONTROL_REG = 0;
    }
};

#ifndef TEST
void _getResetStatus() __attribute__((used, naked, section(".init3")));
void _getResetStatus() {
   _resetStatus = *CHIP_RESET_STATUS_REG;
   *CHIP_RESET_STATUS_REG = 0;

   Wdt::disable();
}
#endif

#endif

} // nbos::hw

#endif
