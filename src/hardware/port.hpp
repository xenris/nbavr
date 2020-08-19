/// [[Index]]

/// # {{Digital IO Ports}}

#ifndef NBLIB_PORT_HPP

#include "isr.hpp"
#include "chip.hpp"
#include "hardwaretype.hpp"
#include "macros.hpp"
#include "pin.xpp"
#include "system.hpp"
#include "register.hpp"

#include "loopi"

#ifdef _I
    #define X TO_LETTER(_I)
    #define PortX CAT(Port, X)
    #define PORT_X(A) CAT(CHIP_PORT_, X, _, A)

    #if DEFINED(CAT(CHIP_PORT_, X))

//------------------------------------------------------------------

namespace nblib::hw {

/// ## Class {{PortX}}
struct PortX {
    PortX() = delete;

    PortX& operator=(const PortX&) = delete;

    PortX(const PortX&) = delete;

    /// #### static [[HardwareType]] getHardwareType()
    static constexpr HardwareType getHardwareType() {
        return HardwareType::port;
    }

    #if REG_DEFINED(PORT_X(CLOCK_ENABLE_REG))
        /// #### static void enableClock(bool)
        static force_inline void enableClock(bool e) {
            PORT_X(CLOCK_ENABLE_REG)::setBit(PORT_X(CLOCK_ENABLE_BIT), e);
        }
    #endif

    #if REG_DEFINED(PORT_X(DIRECTION_REG))
        /// #### static void direction(T bits)
        static force_inline void direction(PORT_X(OUTPUT_REG)::Type bits) {
            PORT_X(DIRECTION_REG)::setReg(bits);
        }
    #endif

    #if REG_DEFINED(PORT_X(OUTPUT_REG))
        /// #### static void output(T value)
        static force_inline void output(PORT_X(OUTPUT_REG)::Type value) {
            PORT_X(OUTPUT_REG)::setReg(value);
        }
    #endif

    #if REG_DEFINED(PORT_X(SET_OUTPUTS_REG))
        /// #### static void setOutputs(T bits)
        static force_inline void setOutputs(PORT_X(SET_OUTPUTS_REG)::Type bits) {
            PORT_X(SET_OUTPUTS_REG)::setReg(bits);
        }
    #endif

    #if REG_DEFINED(PORT_X(CLEAR_OUTPUTS_REG))
        /// #### static void clearOutputs(T bits)
        static force_inline void clearOutputs(PORT_X(CLEAR_OUTPUTS_REG)::Type bits) {
            PORT_X(CLEAR_OUTPUTS_REG)::setReg(bits);
        }
    #endif

    #if REG_DEFINED(PORT_X(INPUT_REG))
        /// #### static T input()
        static force_inline PORT_X(INPUT_REG)::Type input() {
            return PORT_X(INPUT_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(PORT_X(PULLUP_REG))
        /// #### static void pullup(T bits)
        static force_inline void pullup(PORT_X(PULLUP_REG)::Type bits) {
            PORT_X(PULLUP_REG)::setReg(bits);
        }
    #endif

    #if REG_DEFINED(PORT_X(OUTPUT_TOGGLE_REG))
        /// #### static void outputToggle(T bits)
        static force_inline void outputToggle(PORT_X(OUTPUT_TOGGLE_REG)::Type bits) {
            PORT_X(OUTPUT_TOGGLE_REG)::setReg(bits);
        }
    #endif

    #include "pin.xpp"
};

#ifdef TEST

TEST(PortX, getHardwareType) {
    ASSERT_EQ(PortX::getHardwareType(), HardwareType::port);
}

#if REG_DEFINED(PORT_X(CLOCK_ENABLE_REG))
    TEST(PortX, enableClock) {
        TEST_REG_WRITE(PortX::enableClock(true));
        TEST_REG_WRITE(PortX::enableClock(false));
    }
#endif

#if REG_DEFINED(PORT_X(DIRECTION_REG))
    TEST(PortX, direction) {
        TEST_REG_WRITE(PortX::direction(0x12));
    }
#endif

#if REG_DEFINED(PORT_X(OUTPUT_REG))
    TEST(PortX, output) {
        TEST_REG_WRITE(PortX::output(0x12));
    }
#endif

#if REG_DEFINED(PORT_X(SET_OUTPUTS_REG))
    TEST(PortX, setOutputs) {
        TEST_REG_WRITE(PortX::setOutputs(0x12));
        TEST_REG_WRITE(PortX::setOutputs(0x34));
    }
#endif

#if REG_DEFINED(PORT_X(CLEAR_OUTPUTS_REG))
    TEST(PortX, clearOutputs) {
        TEST_REG_WRITE(PortX::clearOutputs(0x12));
        TEST_REG_WRITE(PortX::clearOutputs(0x34));
    }
#endif

#if REG_DEFINED(PORT_X(INPUT_REG))
    TEST(PortX, input) {
        TEST_REG_READ_WRITE(PortX::input());
    }
#endif

#if REG_DEFINED(PORT_X(PULLUP_REG))
    TEST(PortX, pullup) {
        TEST_REG_WRITE(PortX::pullup(0x23));
    }
#endif

#if REG_DEFINED(PORT_X(OUTPUT_TOGGLE_REG))
    TEST(PortX, outputToggle) {
        TEST_REG_WRITE(PortX::outputToggle(0x12));
    }
#endif

#define PIN_TESTS
#include "pin.xpp"
#undef PIN_TESTS

#endif // TEST

} // nblib::hw

//--------------------------------------------------------

    #endif

    #undef X
    #undef PortX
    #undef PORT_X

    #include "port.hpp"
#else
    #define NBLIB_PORT_HPP
#endif

#endif
