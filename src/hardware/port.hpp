/// [[Index]]

/// # {{Digital IO Ports}}

/// ```c++
/// using PortC = nbos::hw::PortC;
///
/// nbos::hw::PortC::mode(nbos::hw::Pin::Mode::output);
///
/// nbos::hw::PortC::output(0x03);
///
/// nbos::hw::PortC::Pin15::output(nbos::hw::Pin::Value::low);
///
/// while(true) {
///     nbos::hw::PortC::toggle(0x0C);
///     nbos::block();
/// }
/// ```

#ifndef NBOS_PORT_HPP

#include "isr.hpp"
#include "chip.hpp"
#include "hardwaretype.hpp"
#include "macros.hpp"
#include "pin.hpp"
#include "system.hpp"
#include "type.hpp"

#include "loopi"

#ifdef _I
    #define X TO_LETTER(_I)
    #define PortX CAT(Port, X)
    #define PORT_X(A) CAT(CHIP_PORT_, X, _, A)

    #if CAT(CHIP_PORT_, X)

//------------------------------------------------------------------

namespace nbos::hw {

/// ## Class {{PortX}}
struct PortX {
    PortX() = delete;
    PortX& operator=(const PortX&) = delete;
    PortX(const PortX&) = delete;

    /// #### static [[HardwareType]] getHardwareType()
    static constexpr HardwareType getHardwareType() {
        return HardwareType::port;
    }

    /// #### static void enableClock(bool e)
    #if DEFINED(PORT_X(CLOCK_ENABLE_BIT))
        static force_inline void enableClock(bool e) {
            setBit_(REG(PORT_X(CLOCK_ENABLE_REG)), PORT_X(CLOCK_ENABLE_BIT), e);
        }
    #endif

    /// #### static void mode([[Pin::Mode]] m)
    static force_inline void mode(Pin::Mode m) {
        #if DEFINED(CAT(CHIP_PIN_, X, 0, _INPUT_BIT_0_BIT))
            Pin0::mode(m);
        #endif
        #if DEFINED(CAT(CHIP_PIN_, X, 1, _INPUT_BIT_0_BIT))
            Pin1::mode(m);
        #endif
        #if DEFINED(CAT(CHIP_PIN_, X, 2, _INPUT_BIT_0_BIT))
            Pin2::mode(m);
        #endif
        #if DEFINED(CAT(CHIP_PIN_, X, 3, _INPUT_BIT_0_BIT))
            Pin3::mode(m);
        #endif
        #if DEFINED(CAT(CHIP_PIN_, X, 4, _INPUT_BIT_0_BIT))
            Pin4::mode(m);
        #endif
        #if DEFINED(CAT(CHIP_PIN_, X, 5, _INPUT_BIT_0_BIT))
            Pin5::mode(m);
        #endif
        #if DEFINED(CAT(CHIP_PIN_, X, 6, _INPUT_BIT_0_BIT))
            Pin6::mode(m);
        #endif
        #if DEFINED(CAT(CHIP_PIN_, X, 7, _INPUT_BIT_0_BIT))
            Pin7::mode(m);
        #endif
        #if DEFINED(CAT(CHIP_PIN_, X, 8, _INPUT_BIT_0_BIT))
            Pin8::mode(m);
        #endif
        #if DEFINED(CAT(CHIP_PIN_, X, 9, _INPUT_BIT_0_BIT))
            Pin9::mode(m);
        #endif
        #if DEFINED(CAT(CHIP_PIN_, X, 10, _INPUT_BIT_0_BIT))
            Pin10::mode(m);
        #endif
        #if DEFINED(CAT(CHIP_PIN_, X, 11, _INPUT_BIT_0_BIT))
            Pin11::mode(m);
        #endif
        #if DEFINED(CAT(CHIP_PIN_, X, 12, _INPUT_BIT_0_BIT))
            Pin12::mode(m);
        #endif
        #if DEFINED(CAT(CHIP_PIN_, X, 13, _INPUT_BIT_0_BIT))
            Pin13::mode(m);
        #endif
        #if DEFINED(CAT(CHIP_PIN_, X, 14, _INPUT_BIT_0_BIT))
            Pin14::mode(m);
        #endif
        #if DEFINED(CAT(CHIP_PIN_, X, 15, _INPUT_BIT_0_BIT))
            Pin15::mode(m);
        #endif
    }

    /// #### static void output(T value)
    static force_inline void output(CAT(PORT_X(OUTPUT_REG), _TYPE) value) {
        *REG(PORT_X(OUTPUT_REG)) = value;
    }

    /// #### static void setOutputs(T bits)
    #if CAT(PORT_X(SET_OUTPUTS_REG),_ADDR)
        static force_inline void setOutputs(CAT(PORT_X(SET_OUTPUTS_REG), _TYPE) bits) {
            *REG(PORT_X(SET_OUTPUTS_REG)) = bits;
        }
    #endif

    /// #### static void clearOutputs(T bits)
    #if CAT(PORT_X(CLEAR_OUTPUTS_REG),_ADDR)
        static force_inline void clearOutputs(CAT(PORT_X(CLEAR_OUTPUTS_REG),_TYPE) bits) {
            *REG(PORT_X(CLEAR_OUTPUTS_REG)) = bits;
        }
    #endif

    /// #### static T output()
    static force_inline CAT(PORT_X(OUTPUT_REG),_TYPE) output() {
        return *REG(PORT_X(OUTPUT_REG));
    }

    /// #### static T input()
    static force_inline CAT(PORT_X(INPUT_REG),_TYPE) input() {
        return *REG(PORT_X(INPUT_REG));
    }

    /// #### static void toggle(T bits)
    #if CAT(PORT_X(TOGGLE_OUTPUTS_REG),_ADDR)
        static force_inline void toggle(CAT(PORT_X(TOGGLE_OUTPUTS_REG),_TYPE) bits) {
            *REG(PORT_X(TOGGLE_OUTPUTS_REG)) = bits;
        }
    #endif

    #include "pin.hpp"
};

} // nbos::hw

//--------------------------------------------------------

    #endif

    #undef X
    #undef PortX
    #undef PORT_X

    #include "port.hpp"
#else
    #define NBOS_PORT_HPP
#endif


#endif
