#define PcIntN CONCAT(PcInt, ID, )

#define ENABLE_REG CONCAT(CHIP_PCINT_, ID, _ENABLE_REG)
#define MASK_REG CONCAT(CHIP_PCINT_, ID, _MASK_REG)
#define FLAG_REG CONCAT(CHIP_PCINT_, ID, _FLAG_REG)

#define ENABLE_BIT CONCAT(CHIP_PCINT_, ID, _ENABLE_BIT)
#define FLAG_BIT CONCAT(CHIP_PCINT_, ID, _FLAG_BIT)

#define INTERRUPT CONCAT(_pcInt, ID, Interrupt)
#define INTERRUPT_DATA CONCAT(_pcInt, ID, InterruptData)

struct PcIntN {
    PcIntN() = delete;

    static constexpr HardwareType getHardwareType() {
        return HardwareType::PcInt;
    }

    force_inline void enable(uint8_t mask, void (*interrupt)(void*), void* data) {
        // Register interrupt function.
        INTERRUPT = interrupt;
        INTERRUPT_DATA = data;

        // Select pins.
        *MASK_REG = mask;

        // Enable interrupt.
        setBit_(ENABLE_REG, ENABLE_BIT, true);

        // Clear interrupt flag.
        setBit_(FLAG_REG, FLAG_BIT, true);
    }

    force_inline void disable() {
        // Unregister interrupt function.
        INTERRUPT = nullptr;
        INTERRUPT_DATA = nullptr;

        // Unselect pins.
        *MASK_REG = 0;

        // Disable interrupt.
        setBit_(ENABLE_REG, ENABLE_BIT, false);

        // Clear interrupt flag.
        setBit_(FLAG_REG, FLAG_BIT, true);
    }
};

#undef PcIntN

#undef ENABLE_REG
#undef MASK_REG
#undef FLAG_REG

#undef ENABLE_BIT
#undef FLAG_BIT

#undef INTERRUPT
#undef INTERRUPT_DATA
