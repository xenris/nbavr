/// # Digital IO Pins

/// X is the port id (A, B, etc).<br>
/// N is the pin id (1, 2, etc).<br>
/// All functions are static.

/// ## Example

/// ```c++
/// PinB5::direction(PinB5::Direction::Output);
/// PinB5::output(PinB5::Value::High);
/// ```

#ifndef NBAVR_PIN_HPP

#ifdef N
    #if N < CHIP_PIN_COUNT
        #define PORT TO_LETTER(X)
        #define BIT N

        // If this hardware exists.
        #if CONCAT(CHIP_PIN_, PORT, BIT)

//--------------------------------------------------------

#define PinXN CONCAT(Pin, PORT, BIT)
#define C(X) CONCAT(CHIP_PORT_, PORT, _, X)

/// ## Class PinXN
struct PinXN {
    PinXN() = delete;

    /// #### enum Direction
    /// * Input
    /// * Output
    enum class Direction : int8_t {
        Input,
        Output,
    };

    /// #### enum Value
    /// * Low
    /// * High
    enum class Value : int8_t {
        Low,
        High,
    };

    /// #### constexpr [HardwareType](../hardware.hpp.md) getHardwareType()
    /// Get the type of hardware that this class represents.
    static constexpr HardwareType getHardwareType() {
        return HardwareType::Pin;
    }

    /// #### void direction(Direction)
    /// Set the direction. (Input/Output)
    static force_inline void direction(Direction d) {
        setBit_(C(DIRECTION_REG), BIT, d == Direction::Output);
    }

    /// #### Direction direction()
    /// Get the direction. (Input/Output)
    /// paragraph
    static force_inline Direction direction() {
        return (*C(DIRECTION_REG) & bv(BIT)) ? Direction::Output : Direction::Input;
    }

    /// #### void pullup(bool)
    /// Enable/disable the pullup resistor.
    static force_inline void pullup(bool p) {
        output(p ? Value::High : Value::Low);
    }

    /// #### bool pullup()
    /// Returns true if the pullup resistor is enabled.
    static force_inline bool pullup() {
        return output();
    }

    /// #### void output(Value)
    /// Set the output state. (High/Low)
    static force_inline void output(Value v) {
        setBit_(C(OUTPUT_REG), BIT, v == Value::High);
    }

    /// #### Value output()
    /// Get the output state. (High/Low)
    static force_inline bool output() {
        return *C(OUTPUT_REG) & bv(BIT);
    }

    /// #### Value input()
    /// Get the input state. (High/Low)
    static force_inline Value input() {
        return (*C(INPUT_REG) & bv(BIT)) ? Value::High : Value::Low;
    }

    /// #### void toggle()
    /// Toggle the output state. (High/Low)
    static force_inline void toggle() {
        setBit_(C(INPUT_REG), BIT, true);
    }
};

#undef PinXN
#undef C

//--------------------------------------------------------

        #endif // CONCAT(CHIP_PIN_, PORT, PIN)

        #undef PORT
        #undef BIT

        #include "incn.hpp"

        #include "pin.hpp"
    #endif // N < CHIP_PIN_COUNT
#else // N
    #ifndef X
        // Port id.
        #define X 0
    #endif

    #if X < CHIP_PORT_COUNT
        // Pin id.
        #define N 0

        #include "pin.hpp"

        #undef N

        #include "incx.hpp"

        #include "pin.hpp"
    #endif // X < CHIP_PORT_COUNT

    #undef X

    #define NBAVR_PIN_HPP
#endif // N

#endif
