#ifndef NBAVR_PIN_HPP
#define NBAVR_PIN_HPP

class Pin {
    volatile uint8_t& _output;
    volatile uint8_t& _direction;
    volatile uint8_t& _input;
    const uint8_t bit;

    public:

    enum class Direction : int8_t {
        Input,
        InputPullup,
        Output,
    };

    enum class Value : int8_t {
        Low,
        High,
    };

    Pin(volatile uint8_t& output, volatile uint8_t& direction, volatile uint8_t& input, uint8_t bit)
        : _output(output), _direction(direction), _input(input), bit(bit) {
    }

    force_inline Direction direction(Direction d) const {
        switch(d) {
            case Direction::Input:
                _direction &= ~bv(bit);
                _output &= ~bv(bit);
                break;
            case Direction::InputPullup:
                _direction &= ~bv(bit);
                _output |= bv(bit);
                break;
            case Direction::Output:
                _direction |= bv(bit);
                _output &= ~bv(bit);
                break;
        }

        return d;
    }

    force_inline Direction direction() const {
        if(_direction & bv(bit)) {
            return Direction::Output;
        } else if(_output & bv(bit)) {
            return Direction::InputPullup;
        } else {
            return Direction::Input;
        }
    }

    force_inline Value value(Value v) const {
        if(v == Value::High) {
            _output |= bv(bit);
        } else {
            _output &= ~bv(bit);
        }

        return v;
    }

    force_inline Value value() const {
        return (_input & bv(bit)) ? Value::High : Value::Low;
    }

    force_inline void toggle() const {
        _input |= bv(bit);
    }

    force_inline Value operator=(Value v) {
        return value(v);
    }

    force_inline Direction operator=(Direction d) {
        return direction(d);
    }

    force_inline operator Value() const {
        return value();
    }

    force_inline operator Direction() const {
        return direction();
    }
};

#define MAKE_PIN_CLASS(PORT,PIN) \
    struct Pin##PORT##PIN : Pin { \
        Pin##PORT##PIN() \
            : Pin(CHIP_PORT_##PORT##_OUTPUT_REG, CHIP_PORT_##PORT##_DIRECTION_REG, CHIP_PORT_##PORT##_INPUT_REG, PIN) { \
        } \
        force_inline Value operator=(Value v) { \
            return Pin::operator=(v); \
        } \
        force_inline Direction operator=(Direction v) { \
            return Pin::operator=(v); \
        } \
    };

#ifdef CHIP_PIN_A0
    MAKE_PIN_CLASS(A, 0)
#endif

#ifdef CHIP_PIN_A1
    MAKE_PIN_CLASS(A, 1)
#endif

#ifdef CHIP_PIN_A2
    MAKE_PIN_CLASS(A, 2)
#endif

#ifdef CHIP_PIN_A3
    MAKE_PIN_CLASS(A, 3)
#endif

#ifdef CHIP_PIN_A4
    MAKE_PIN_CLASS(A, 4)
#endif

#ifdef CHIP_PIN_A5
    MAKE_PIN_CLASS(A, 5)
#endif

#ifdef CHIP_PIN_A6
    MAKE_PIN_CLASS(A, 6)
#endif

#ifdef CHIP_PIN_A7
    MAKE_PIN_CLASS(A, 7)
#endif

#ifdef CHIP_PIN_B0
    MAKE_PIN_CLASS(B, 0)
#endif

#ifdef CHIP_PIN_B1
    MAKE_PIN_CLASS(B, 1)
#endif

#ifdef CHIP_PIN_B2
    MAKE_PIN_CLASS(B, 2)
#endif

#ifdef CHIP_PIN_B3
    MAKE_PIN_CLASS(B, 3)
#endif

#ifdef CHIP_PIN_B4
    MAKE_PIN_CLASS(B, 4)
#endif

#ifdef CHIP_PIN_B5
    MAKE_PIN_CLASS(B,5)
#endif

#ifdef CHIP_PIN_B6
    MAKE_PIN_CLASS(B, 6)
#endif

#ifdef CHIP_PIN_B7
    MAKE_PIN_CLASS(B, 7)
#endif

#ifdef CHIP_PIN_C0
    MAKE_PIN_CLASS(C, 0)
#endif

#ifdef CHIP_PIN_C1
    MAKE_PIN_CLASS(C, 1)
#endif

#ifdef CHIP_PIN_C2
    MAKE_PIN_CLASS(C, 2)
#endif

#ifdef CHIP_PIN_C3
    MAKE_PIN_CLASS(C, 3)
#endif

#ifdef CHIP_PIN_C4
    MAKE_PIN_CLASS(C, 4)
#endif

#ifdef CHIP_PIN_C5
    MAKE_PIN_CLASS(C, 5)
#endif

#ifdef CHIP_PIN_C6
    MAKE_PIN_CLASS(C, 6)
#endif

#ifdef CHIP_PIN_C7
    MAKE_PIN_CLASS(C, 7)
#endif

#ifdef CHIP_PIN_D0
    MAKE_PIN_CLASS(D, 0)
#endif

#ifdef CHIP_PIN_D1
    MAKE_PIN_CLASS(D, 1)
#endif

#ifdef CHIP_PIN_D2
    MAKE_PIN_CLASS(D, 2)
#endif

#ifdef CHIP_PIN_D3
    MAKE_PIN_CLASS(D, 3)
#endif

#ifdef CHIP_PIN_D4
    MAKE_PIN_CLASS(D, 4)
#endif

#ifdef CHIP_PIN_D5
    MAKE_PIN_CLASS(D, 5)
#endif

#ifdef CHIP_PIN_D6
    MAKE_PIN_CLASS(D, 6)
#endif

#ifdef CHIP_PIN_D7
    MAKE_PIN_CLASS(D, 7)
#endif

#ifdef CHIP_PIN_E0
    MAKE_PIN_CLASS(E, 0)
#endif

#ifdef CHIP_PIN_E1
    MAKE_PIN_CLASS(E, 1)
#endif

#ifdef CHIP_PIN_E2
    MAKE_PIN_CLASS(E, 2)
#endif

#ifdef CHIP_PIN_E3
    MAKE_PIN_CLASS(E, 3)
#endif

#ifdef CHIP_PIN_E4
    MAKE_PIN_CLASS(E, 4)
#endif

#ifdef CHIP_PIN_E5
    MAKE_PIN_CLASS(E, 5)
#endif

#ifdef CHIP_PIN_E6
    MAKE_PIN_CLASS(E, 6)
#endif

#ifdef CHIP_PIN_E7
    MAKE_PIN_CLASS(E, 7)
#endif

#ifdef CHIP_PIN_F0
    MAKE_PIN_CLASS(F, 0)
#endif

#ifdef CHIP_PIN_F1
    MAKE_PIN_CLASS(F, 1)
#endif

#ifdef CHIP_PIN_F2
    MAKE_PIN_CLASS(F, 2)
#endif

#ifdef CHIP_PIN_F3
    MAKE_PIN_CLASS(F, 3)
#endif

#ifdef CHIP_PIN_F4
    MAKE_PIN_CLASS(F, 4)
#endif

#ifdef CHIP_PIN_F5
    MAKE_PIN_CLASS(F, 5)
#endif

#ifdef CHIP_PIN_F6
    MAKE_PIN_CLASS(F, 6)
#endif

#ifdef CHIP_PIN_F7
    MAKE_PIN_CLASS(F, 7)
#endif

#ifdef CHIP_PIN_G0
    MAKE_PIN_CLASS(G, 0)
#endif

#ifdef CHIP_PIN_G1
    MAKE_PIN_CLASS(G, 1)
#endif

#ifdef CHIP_PIN_G2
    MAKE_PIN_CLASS(G, 2)
#endif

#ifdef CHIP_PIN_G3
    MAKE_PIN_CLASS(G, 3)
#endif

#ifdef CHIP_PIN_G4
    MAKE_PIN_CLASS(G, 4)
#endif

#ifdef CHIP_PIN_G5
    MAKE_PIN_CLASS(G, 5)
#endif

#ifdef CHIP_PIN_G6
    MAKE_PIN_CLASS(G, 6)
#endif

#ifdef CHIP_PIN_G7
    MAKE_PIN_CLASS(G, 7)
#endif

#ifdef CHIP_PIN_H0
    MAKE_PIN_CLASS(H, 0)
#endif

#ifdef CHIP_PIN_H1
    MAKE_PIN_CLASS(H, 1)
#endif

#ifdef CHIP_PIN_H2
    MAKE_PIN_CLASS(H, 2)
#endif

#ifdef CHIP_PIN_H3
    MAKE_PIN_CLASS(H, 3)
#endif

#ifdef CHIP_PIN_H4
    MAKE_PIN_CLASS(H, 4)
#endif

#ifdef CHIP_PIN_H5
    MAKE_PIN_CLASS(H, 5)
#endif

#ifdef CHIP_PIN_H6
    MAKE_PIN_CLASS(H, 6)
#endif

#ifdef CHIP_PIN_H7
    MAKE_PIN_CLASS(H, 7)
#endif

#ifdef CHIP_PIN_I0
    MAKE_PIN_CLASS(I, 0)
#endif

#ifdef CHIP_PIN_I1
    MAKE_PIN_CLASS(I, 1)
#endif

#ifdef CHIP_PIN_I2
    MAKE_PIN_CLASS(I, 2)
#endif

#ifdef CHIP_PIN_I3
    MAKE_PIN_CLASS(I, 3)
#endif

#ifdef CHIP_PIN_I4
    MAKE_PIN_CLASS(I, 4)
#endif

#ifdef CHIP_PIN_I5
    MAKE_PIN_CLASS(I, 5)
#endif

#ifdef CHIP_PIN_I6
    MAKE_PIN_CLASS(I, 6)
#endif

#ifdef CHIP_PIN_I7
    MAKE_PIN_CLASS(I, 7)
#endif

#ifdef CHIP_PIN_J0
    MAKE_PIN_CLASS(J, 0)
#endif

#ifdef CHIP_PIN_J1
    MAKE_PIN_CLASS(J, 1)
#endif

#ifdef CHIP_PIN_J2
    MAKE_PIN_CLASS(J, 2)
#endif

#ifdef CHIP_PIN_J3
    MAKE_PIN_CLASS(J, 3)
#endif

#ifdef CHIP_PIN_J4
    MAKE_PIN_CLASS(J, 4)
#endif

#ifdef CHIP_PIN_J5
    MAKE_PIN_CLASS(J, 5)
#endif

#ifdef CHIP_PIN_J6
    MAKE_PIN_CLASS(J, 6)
#endif

#ifdef CHIP_PIN_J7
    MAKE_PIN_CLASS(J, 7)
#endif

#ifdef CHIP_PIN_K0
    MAKE_PIN_CLASS(K, 0)
#endif

#ifdef CHIP_PIN_K1
    MAKE_PIN_CLASS(K, 1)
#endif

#ifdef CHIP_PIN_K2
    MAKE_PIN_CLASS(K, 2)
#endif

#ifdef CHIP_PIN_K3
    MAKE_PIN_CLASS(K, 3)
#endif

#ifdef CHIP_PIN_K4
    MAKE_PIN_CLASS(K, 4)
#endif

#ifdef CHIP_PIN_K5
    MAKE_PIN_CLASS(K, 5)
#endif

#ifdef CHIP_PIN_K6
    MAKE_PIN_CLASS(K, 6)
#endif

#ifdef CHIP_PIN_K7
    MAKE_PIN_CLASS(K, 7)
#endif

#ifdef CHIP_PIN_L0
    MAKE_PIN_CLASS(L, 0)
#endif

#ifdef CHIP_PIN_L1
    MAKE_PIN_CLASS(L, 1)
#endif

#ifdef CHIP_PIN_L2
    MAKE_PIN_CLASS(L, 2)
#endif

#ifdef CHIP_PIN_L3
    MAKE_PIN_CLASS(L, 3)
#endif

#ifdef CHIP_PIN_L4
    MAKE_PIN_CLASS(L, 4)
#endif

#ifdef CHIP_PIN_L5
    MAKE_PIN_CLASS(L, 5)
#endif

#ifdef CHIP_PIN_L6
    MAKE_PIN_CLASS(L, 6)
#endif

#ifdef CHIP_PIN_L7
    MAKE_PIN_CLASS(L, 7)
#endif

#endif
