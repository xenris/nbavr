#define PortX CONCAT(Port, PORT, )

#define OUTPUT_REG CONCAT(CHIP_PORT_, PORT, _OUTPUT_REG)
#define DIRECTION_REG CONCAT(CHIP_PORT_, PORT, _DIRECTION_REG)
#define INPUT_REG CONCAT(CHIP_PORT_, PORT, _INPUT_REG)

struct PortX {
    PortX() = delete;

    static constexpr HardwareType getHardwareType() {
        return HardwareType::Port;
    }

    static force_inline void direction(uint8_t d) {
        *DIRECTION_REG = d;
    }

    static force_inline uint8_t direction() {
        return *DIRECTION_REG;
    }

    static force_inline void pullup(uint8_t p) {
        *OUTPUT_REG = p;
    }

    static force_inline uint8_t pullup() {
        return *OUTPUT_REG;
    }

    static force_inline void value(uint8_t v) {
        *OUTPUT_REG = v;
    }

    static force_inline uint8_t value() {
        return *INPUT_REG;
    }

    static force_inline void toggle(uint8_t bits) {
        *INPUT_REG = bits;
    }
};

#undef PortX

#undef OUTPUT_REG
#undef DIRECTION_REG
#undef INPUT_REG
