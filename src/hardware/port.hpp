#ifndef NBAVR_PORT_HPP
#define NBAVR_PORT_HPP

class Port {
    volatile uint8_t& _output;
    volatile uint8_t& _direction;
    volatile uint8_t& _input;

public:
    Port(volatile uint8_t& output, volatile uint8_t& direction, volatile uint8_t& input)
        : _output(output), _direction(direction), _input(input) {
    }

    force_inline uint8_t direction(uint8_t d) const {
        _direction = d;
        return d;
    }

    force_inline uint8_t direction() const {
        return _direction;
    }

    force_inline uint8_t pullup(uint8_t p) const {
        _output = p;
        return p;
    }

    force_inline uint8_t pullup() const {
        return _output;
    }

    force_inline uint8_t value(uint8_t v) const {
        _output = v;
        return v;
    }

    force_inline uint8_t value() const {
        return _input;
    }

    force_inline uint8_t toggle(uint8_t bits) const {
        _input = bits;
        return bits;
    }

    force_inline uint8_t operator=(uint8_t v) {
        return value(v);
    }

    force_inline operator uint8_t() const {
        return value();
    }
};

#define MAKE_PORT_CLASS(PORT) \
    struct Port##PORT : public Port { \
        Port##PORT() \
            : Port(CHIP_PORT_##PORT##_OUTPUT_REG, CHIP_PORT_##PORT##_DIRECTION_REG, CHIP_PORT_##PORT##_INPUT_REG) { \
        } \
        force_inline uint8_t operator=(uint8_t v) { \
            return Port::operator=(v); \
        } \
    };

#ifdef CHIP_PORT_A_OUTPUT_REG
    MAKE_PORT_CLASS(A)
#endif

#ifdef CHIP_PORT_B_OUTPUT_REG
    MAKE_PORT_CLASS(B)
#endif

#ifdef CHIP_PORT_C_OUTPUT_REG
    MAKE_PORT_CLASS(C)
#endif

#ifdef CHIP_PORT_D_OUTPUT_REG
    MAKE_PORT_CLASS(D)
#endif

#ifdef CHIP_PORT_E_OUTPUT_REG
    MAKE_PORT_CLASS(E)
#endif

#ifdef CHIP_PORT_F_OUTPUT_REG
    MAKE_PORT_CLASS(F)
#endif

#ifdef CHIP_PORT_G_OUTPUT_REG
    MAKE_PORT_CLASS(G)
#endif

#ifdef CHIP_PORT_H_OUTPUT_REG
    MAKE_PORT_CLASS(H)
#endif

#ifdef CHIP_PORT_I_OUTPUT_REG
    MAKE_PORT_CLASS(I)
#endif

#ifdef CHIP_PORT_J_OUTPUT_REG
    MAKE_PORT_CLASS(J)
#endif

#ifdef CHIP_PORT_K_OUTPUT_REG
    MAKE_PORT_CLASS(K)
#endif

#ifdef CHIP_PORT_L_OUTPUT_REG
    MAKE_PORT_CLASS(L)
#endif

#endif
