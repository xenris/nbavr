/// # Digital IO Ports

/// X is the port id (A, B, etc).

/// ## Example

/// ```c++
/// // Set pins 0 and 1 as outputs and all others as inputs.
/// PortC::direction(0x03);
/// // Set pin 0 high and all others low.
/// PortC::output(0x01);
/// ```

#ifndef NBAVR_PORT_HPP

#ifndef X
    // Port id.
    #define X 0
#endif

#if X < CHIP_PORT_COUNT
    #define PORT TO_LETTER(X)

    // If this hardware exists.
    #if CONCAT(CHIP_PORT_, PORT)

//--------------------------------------------------------

#define PortX CONCAT(Port, PORT)
#define C(X) CONCAT(CHIP_PORT_, PORT, _, X)

/// ## Class PortX
struct PortX {
    PortX() = delete;

    /// #### static constexpr HardwareType getHardwareType()
    /// Get the type of hardware that this class represents.
    static constexpr HardwareType getHardwareType() {
        return HardwareType::Port;
    }

    /// #### static void direction(uint8_t)
    /// Set the direction of each pin. 0 = input, 1 = output.
    static force_inline void direction(uint8_t d) {
        *C(DIRECTION_REG) = d;
    }

    /// #### static uint8_t direction()
    /// Get the direction of each pin. 0 = input, 1 = output.
    static force_inline uint8_t direction() {
        return *C(DIRECTION_REG);
    }

    /// #### static void pullup(uint8_t)
    /// Enable/disable the pullup resistor of each pin.
    static force_inline void pullup(uint8_t p) {
        output(p);
    }

    /// #### static uint8_t pullup()
    /// Get the pullup resistor state of each pin.
    static force_inline uint8_t pullup() {
        return output();
    }

    /// #### static void output(uint8_t)
    /// Set the output state of each pin.
    static force_inline void output(uint8_t v) {
        *C(OUTPUT_REG) = v;
    }

    /// #### static uint8_t output()
    /// Get the output state of each pin.
    static force_inline uint8_t output() {
        return *C(OUTPUT_REG);
    }

    /// #### static uint8_t input()
    /// Get the input state of each pin.
    static force_inline uint8_t input() {
        return *C(INPUT_REG);
    }

    /// #### static void toggle(uint8_t)
    /// Toggle the output state of each pin.
    static force_inline void toggle(uint8_t bits) {
        *C(INPUT_REG) = bits;
    }
};

#undef PortX
#undef C

//--------------------------------------------------------

    #endif // CONCAT(CHIP_PORT_, PORT)

    #undef PORT

    #include "incx.hpp"

    #include "port.hpp"
#else // X < CHIP_PORT_COUNT
    #undef X

    #define NBAVR_PORT_HPP
#endif // X < CHIP_PORT_COUNT

#endif
