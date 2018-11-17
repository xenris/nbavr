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
#include "pin.xpp"
#include "system.hpp"

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

    /// #### static void enableClock(Bool e)
    #if DEFINED(PORT_X(CLOCK_ENABLE_BIT))
        static force_inline void enableClock(Bool e) {
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
        setReg_(REG(PORT_X(OUTPUT_REG)), value);
    }

    /// #### static void setOutputs(T bits)
    #if CAT(PORT_X(SET_OUTPUTS_REG),_ADDR)
        static force_inline void setOutputs(CAT(PORT_X(SET_OUTPUTS_REG), _TYPE) bits) {
            setReg_(REG(PORT_X(SET_OUTPUTS_REG)), bits);
        }
    #endif

    /// #### static void clearOutputs(T bits)
    #if CAT(PORT_X(CLEAR_OUTPUTS_REG),_ADDR)
        static force_inline void clearOutputs(CAT(PORT_X(CLEAR_OUTPUTS_REG),_TYPE) bits) {
            setReg_(REG(PORT_X(CLEAR_OUTPUTS_REG)), bits);
        }
    #endif

    /// #### static T output()
    static force_inline CAT(PORT_X(OUTPUT_REG),_TYPE) output() {
        return getReg_(REG(PORT_X(OUTPUT_REG)));
    }

    /// #### static T input()
    static force_inline CAT(PORT_X(INPUT_REG),_TYPE) input() {
        return getReg_(REG(PORT_X(INPUT_REG)));
    }

    /// #### static void toggle(T bits)
    #if CAT(PORT_X(TOGGLE_OUTPUTS_REG),_ADDR)
        static force_inline void toggle(CAT(PORT_X(TOGGLE_OUTPUTS_REG),_TYPE) bits) {
            setReg_(REG(PORT_X(TOGGLE_OUTPUTS_REG)), bits);
        }
    #endif

    #include "pin.xpp"
};

#ifdef TEST

TEST(PortX, getHardwareType) {
    ASSERT_EQ(PortX::getHardwareType(), HardwareType::port);
}

#if DEFINED(PORT_X(CLOCK_ENABLE_BIT))
    TEST(PortX, enableClock) {
        TEST_REG_WRITE(PortX::enableClock(true));
        TEST_REG_WRITE(PortX::enableClock(false));
    }
#endif

TEST(PortX, mode) {
    #define MODE(A) CAT(CHIP_PIN_MODE_, A, _ID)

    #if DEFINED(MODE(INPUT))
        TEST_REG_WRITE(PortX::mode(Pin::Mode::input));
    #endif

    #if DEFINED(MODE(INPUT_PULLUP))
        TEST_REG_WRITE(PortX::mode(Pin::Mode::inputPullup));
    #endif

    #if DEFINED(MODE(OUTPUT))
        TEST_REG_WRITE(PortX::mode(Pin::Mode::output));
    #endif

    #if DEFINED(MODE(INPUT_ANALOG))
        TEST_REG_WRITE(PortX::mode(Pin::Mode::inputAnalog));
    #endif

    #if DEFINED(MODE(INPUT_FLOATING))
        TEST_REG_WRITE(PortX::mode(Pin::Mode::inputFloating));
    #endif

    #if DEFINED(MODE(INPUT_PULLUPDOWN))
        TEST_REG_WRITE(PortX::mode(Pin::Mode::inputPullUpDown));
    #endif

    #if DEFINED(MODE(OUTPUT_GENERAL_PUSH_PULL_10MHZ))
        TEST_REG_WRITE(PortX::mode(Pin::Mode::outputGeneralPushPull10MHz));
    #endif

    #if DEFINED(MODE(OUTPUT_GENERAL_OPEN_DRAIN_10MHZ))
        TEST_REG_WRITE(PortX::mode(Pin::Mode::outputGeneralOpenDrain10MHz));
    #endif

    #if DEFINED(MODE(OUTPUT_ALTERNATE_PUSH_PULL_10MHZ))
        TEST_REG_WRITE(PortX::mode(Pin::Mode::outputAlternatePushPull10MHz));
    #endif

    #if DEFINED(MODE(OUTPUT_ALTERNATE_OPEN_DRAIN_10MHZ))
        TEST_REG_WRITE(PortX::mode(Pin::Mode::outputAlternateOpenDrain10MHz));
    #endif

    #if DEFINED(MODE(OUTPUT_GENERAL_PUSH_PULL_2MHZ))
        TEST_REG_WRITE(PortX::mode(Pin::Mode::outputGeneralPushPull2MHz));
    #endif

    #if DEFINED(MODE(OUTPUT_GENERAL_OPEN_DRAIN_2MHZ))
        TEST_REG_WRITE(PortX::mode(Pin::Mode::outputGeneralOpenDrain2MHz));
    #endif

    #if DEFINED(MODE(OUTPUT_ALTERNATE_PUSH_PULL_2MHZ))
        TEST_REG_WRITE(PortX::mode(Pin::Mode::outputAlternatePushPull2MHz));
    #endif

    #if DEFINED(MODE(OUTPUT_ALTERNATE_OPEN_DRAIN_2MHZ))
        TEST_REG_WRITE(PortX::mode(Pin::Mode::outputAlternateOpenDrain2MHz));
    #endif

    #if DEFINED(MODE(OUTPUT_GENERAL_PUSH_PULL_50MHZ))
        TEST_REG_WRITE(PortX::mode(Pin::Mode::outputGeneralPushPull50MHz));
    #endif

    #if DEFINED(MODE(OUTPUT_GENERAL_OPEN_DRAIN_50MHZ))
        TEST_REG_WRITE(PortX::mode(Pin::Mode::outputGeneralOpenDrain50MHz));
    #endif

    #if DEFINED(MODE(OUTPUT_ALTERNATE_PUSH_PULL_50MHZ))
        TEST_REG_WRITE(PortX::mode(Pin::Mode::outputAlternatePushPull50MHz));
    #endif

    #if DEFINED(MODE(OUTPUT_ALTERNATE_OPEN_DRAIN_50MHZ))
        TEST_REG_WRITE(PortX::mode(Pin::Mode::outputAlternateOpenDrain50MHz));
    #endif

    #undef MODE
}

TEST(PortX, output) {
    TEST_REG_WRITE(PortX::output(0x12));
    TEST_REG_READ_WRITE(PortX::output());
}

#if CAT(PORT_X(SET_OUTPUTS_REG),_ADDR)
    TEST(PortX, setOutputs) {
        TEST_REG_WRITE(PortX::setOutputs(0x12));
        TEST_REG_WRITE(PortX::setOutputs(0x34));
    }
#endif

#if CAT(PORT_X(CLEAR_OUTPUTS_REG),_ADDR)
    TEST(PortX, clearOutputs) {
        TEST_REG_WRITE(PortX::clearOutputs(0x12));
        TEST_REG_WRITE(PortX::clearOutputs(0x34));
    }
#endif

TEST(PortX, input) {
    TEST_REG_READ_WRITE(PortX::input());
}

#if CAT(PORT_X(TOGGLE_OUTPUTS_REG),_ADDR)
    TEST(PortX, toggle) {
        TEST_REG_WRITE(PortX::toggle(0x12));
    }
#endif

#define PIN_TESTS
#include "pin.xpp"
#undef PIN_TESTS

#endif // TEST

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
