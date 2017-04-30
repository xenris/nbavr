#define PinXN CONCAT(Pin, PORT, BIT)

#define OUTPUT_REG CONCAT(CHIP_PORT_, PORT, _OUTPUT_REG)
#define DIRECTION_REG CONCAT(CHIP_PORT_, PORT, _DIRECTION_REG)
#define INPUT_REG CONCAT(CHIP_PORT_, PORT, _INPUT_REG)

struct PinXN {
    PinXN() = delete;

    static constexpr HardwareType getHardwareType() {
        return HardwareType::Pin;
    }

    enum class Direction : int8_t {
        Input,
        Output,
    };

    enum class Value : int8_t {
        Low,
        High,
    };

    static force_inline void direction(Direction d) {
        setBit_(DIRECTION_REG, BIT, d == Direction::Output);
    }

    static force_inline Direction direction() {
        return (*DIRECTION_REG & bv(BIT)) ? Direction::Output : Direction::Input;
    }

    static force_inline void pullup(bool p) {
        output(p ? Value::High : Value::Low);
    }

    static force_inline bool pullup() {
        return output();
    }

    static force_inline void output(Value v) {
        setBit_(OUTPUT_REG, BIT, v == Value::High);
    }

    static force_inline bool output() {
        return *OUTPUT_REG & bv(BIT);
    }

    static force_inline Value input() {
        return (*INPUT_REG & bv(BIT)) ? Value::High : Value::Low;
    }

    static force_inline void toggle() {
        setBit_(INPUT_REG, BIT, true);
    }
};

#undef PinXN

#undef OUTPUT_REG
#undef DIRECTION_REG
#undef INPUT_REG
