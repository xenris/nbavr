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
        InputPullup,
        Output,
    };

    enum class Value : int8_t {
        Low,
        High,
    };

    static force_inline void direction(Direction d) {
        switch(d) {
            case Direction::Input:
                *DIRECTION_REG &= ~bv(BIT);
                *OUTPUT_REG &= ~bv(BIT);
                break;
            case Direction::InputPullup:
                *DIRECTION_REG &= ~bv(BIT);
                *OUTPUT_REG |= bv(BIT);
                break;
            case Direction::Output:
                *DIRECTION_REG |= bv(BIT);
                break;
        }
    }

    static force_inline Direction direction() {
        if(*DIRECTION_REG & bv(BIT)) {
            return Direction::Output;
        } else if(*OUTPUT_REG & bv(BIT)) {
            return Direction::InputPullup;
        } else {
            return Direction::Input;
        }
    }

    static force_inline void value(Value v) {
        if(v == Value::High) {
            *OUTPUT_REG |= bv(BIT);
        } else {
            *OUTPUT_REG &= ~bv(BIT);
        }
    }

    static force_inline Value value() {
        return (*INPUT_REG & bv(BIT)) ? Value::High : Value::Low;
    }

    static force_inline void toggle() {
        *INPUT_REG |= bv(BIT);
    }
};

#undef PinXN

#undef OUTPUT_REG
#undef DIRECTION_REG
#undef INPUT_REG
