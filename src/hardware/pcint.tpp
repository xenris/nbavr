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

    static force_inline void enable(bool e) {
        setBit_(ENABLE_REG, ENABLE_BIT, e);
    }

    static force_inline void mask(uint8_t m) {
        *MASK_REG = m;
    }

    static force_inline void callback(void (*func)(void*), void* data) {
        INTERRUPT = func;
        INTERRUPT_DATA = data;
    }

    static force_inline bool intFlag() {
        return *FLAG_REG & bv(FLAG_BIT);
    }

    static force_inline void intFlagClear() {
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
