#ifndef NBAVR_WATCHDOG_HPP
#define NBAVR_WATCHDOG_HPP

// TODO Add enum class to indicate what sort of reset occured.

uint8_t _resetStatus __attribute__((section(".noinit")));

struct WDT {
    WDT() = delete;

    static constexpr HardwareType getHardwareType() {
        return HardwareType::WDT;
    }

    static force_inline void reset() {
        __asm__ __volatile__ ("wdr");
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

void _getResetStatus() __attribute__((used, naked, section(".init3")));
void _getResetStatus() {
   _resetStatus = *CHIP_RESET_STATUS_REG;
   *CHIP_RESET_STATUS_REG = 0;

   WDT::disable();
}

#endif
