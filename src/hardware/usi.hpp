/// [[Index]]

/// # {{Universal Serial Interfaces}}

/// ```c++
/// // TODO
/// ```

#ifndef NBLIB_USI_HPP

#include "isr.hpp"
#include "chip.hpp"
#include "hardwaretype.hpp"
#include "macros.hpp"
#include "system.hpp"
#include "callback.hpp"
#include "port.hpp"

#include "loopi"

#ifdef _I
    #define N _I
    #define UsiN CAT(Usi,N)
    #define USI_N(A) CAT(CHIP_USI_, N, _, A)

    #if CAT(CHIP_USI_, N)

//------------------------------------------------------------------

namespace nblib::hw {

/// ## class UsiN
struct UsiN {
    UsiN() = delete;
    UsiN& operator=(const UsiN&) = delete;
    UsiN(const UsiN&) = delete;

    /// #### type PinDo
    using PinDo = USI_N(PIN_DO);

    /// #### type PinDi
    using PinDi = USI_N(PIN_DI);

    /// #### type PinSda
    using PinSda = USI_N(PIN_SDA);

    /// #### type PinScl
    using PinScl = USI_N(PIN_SCL);

    /// #### type PinUsck
    using PinUsck = USI_N(PIN_USCK);

    #if DEFINED(USI_N(WIRE_MODE_BIT_0_BIT))
        /// #### enum WireMode
        /// * disabled
        /// * threeWire
        /// * twoWire
        /// * twoWireOverflow
        enum class WireMode {
            disabled = USI_N(WIRE_MODE_DISABLED_ID),
            threeWire = USI_N(WIRE_MODE_THREE_WIRE_ID),
            twoWire = USI_N(WIRE_MODE_TWO_WIRE_ID),
            twoWireOverflow = USI_N(WIRE_MODE_TWO_WIRE_OVERFLOW_ID),
        };
    #endif

    #if DEFINED(USI_N(CLOCK_SELECT_BIT_0_BIT))
    /// #### enum Clock
        /// * none
        /// * timer0CompareMatch
        /// * externalPositiveEdge
        /// * externalNegativeEdge
        enum class Clock {
            none = USI_N(CLOCK_SELECT_NONE_ID),
            timer0CompareMatch = USI_N(CLOCK_SELECT_TIMER_0_COMPARE_MATCH_ID),
            externalPositiveEdge = USI_N(CLOCK_SELECT_EXTERNAL_POSITIVE_EDGE_ID),
            externalNegativeEdge = USI_N(CLOCK_SELECT_EXTERNAL_NEGATIVE_EDGE_ID),
        };
    #endif

    /// #### static HardwareType getHardwareType()
    static constexpr HardwareType getHardwareType() {
        return HardwareType::usi;
    }

    #if REG_DEFINED(USI_N(DATA_REG))
        /// #### static void data(uint8_t d)
        static force_inline void data(uint8_t d) {
            setReg_(REG(USI_N(DATA_REG)), d);
        }
    #endif

    #if REG_DEFINED(USI_N(BUFFER_REG))
        /// #### static uint8_t data()
        static force_inline uint8_t data() {
            return getReg_(REG(USI_N(BUFFER_REG)));
        }
    #endif

    #if DEFINED(USI_N(START_CONDITION_INT_ENABLE_BIT_0_BIT))
        /// #### static void startIntEnable(bool b)
        /// Enable the start condition interrupt.
        static force_inline void startIntEnable(bool b) {
            setBit_(REG(USI_N(START_CONDITION_INT_ENABLE_BIT_0_REG)), USI_N(START_CONDITION_INT_ENABLE_BIT_0_BIT), b);
        }
    #endif

    #if DEFINED(USI_N(COUNTER_OVERFLOW_INT_ENABLE_BIT_0_BIT))
        /// #### static void overflowIntEnable(bool b)
        /// Enable the counter overflow interrupt.
        static force_inline void overflowIntEnable(bool b) {
            setBit_(REG(USI_N(COUNTER_OVERFLOW_INT_ENABLE_BIT_0_REG)), USI_N(COUNTER_OVERFLOW_INT_ENABLE_BIT_0_BIT), b);
        }
    #endif

    #if DEFINED(USI_N(WIRE_MODE_BIT_0_BIT))
        /// #### static void wireMode(WireMode m)
        static force_inline void wireMode(WireMode m) {
            setBit_(REG(USI_N(WIRE_MODE_BIT_0_REG)), USI_N(WIRE_MODE_BIT_0_BIT), int(m) & 0x01);

            #if DEFINED(USI_N(CLOCK_SELECT_BIT_1_BIT))
                setBit_(REG(USI_N(CLOCK_SELECT_BIT_1_REG)), USI_N(CLOCK_SELECT_BIT_1_BIT), int(m) & 0x01);
            #endif
        }
    #endif

    #if DEFINED(USI_N(CLOCK_SELECT_BIT_0_BIT))
        /// #### static void clock(Clock c)
        static force_inline void clock(Clock c) {
            setBit_(REG(USI_N(CLOCK_SELECT_BIT_0_REG)), USI_N(CLOCK_SELECT_BIT_0_BIT), int(c) & 0x01);

            #if DEFINED(USI_N(CLOCK_SELECT_BIT_1_BIT))
                setBit_(REG(USI_N(CLOCK_SELECT_BIT_1_REG)), USI_N(CLOCK_SELECT_BIT_1_BIT), int(c) & 0x02);
            #endif
        }
    #endif

    #if DEFINED(USI_N(CLOCK_STROBE_BIT_0_BIT))
        /// #### static void clockStrobe()
        /// Increment counter and Shift the USI data register.
        static force_inline void clockStrobe() {
            setBit_(REG(USI_N(CLOCK_STROBE_BIT_0_REG)), USI_N(CLOCK_STROBE_BIT_0_BIT), true);
        }
    #endif

    #if DEFINED(USI_N(TOGGLE_CLOCK_PIN_BIT_0_BIT))
        /// #### static void toggleClockPin()
        /// Toggle the clock pin or increment the counter
        static force_inline void toggleClockPin() {
            setBit_(REG(USI_N(TOGGLE_CLOCK_PIN_BIT_0_REG)), USI_N(TOGGLE_CLOCK_PIN_BIT_0_BIT), true);
        }
    #endif

    #if DEFINED(USI_N(START_CONDITION_INT_FLAG_BIT_0_BIT))
        /// #### static void startIntFlag()
        /// Get the start condition interrupt flag's state.
        static force_inline bool startIntFlag() {
            return getBit(REG(USI_N(START_CONDITION_INT_FLAG_BIT_0_REG)), USI_N(START_CONDITION_INT_FLAG_BIT_0_BIT));
        }

        /// #### static void startIntFlagClear()
        /// Clear the start condition interrupt flag.
        static force_inline void startIntFlagClear() {
            setBit_(REG(USI_N(START_CONDITION_INT_FLAG_BIT_0_REG)), USI_N(START_CONDITION_INT_FLAG_BIT_0_BIT), true);
        }
    #endif

    #if DEFINED(USI_N(STOP_CONDITION_INT_FLAG_BIT_0_BIT))
        /// #### static void stopIntFlag()
        /// Get the stop condition interrupt flag's state.
        static force_inline bool stopIntFlag() {
            return getBit(REG(USI_N(STOP_CONDITION_INT_FLAG_BIT_0_REG)), USI_N(STOP_CONDITION_INT_FLAG_BIT_0_BIT));
        }

        /// #### static void stopIntFlagClear()
        /// Clear the stop condition interrupt flag.
        static force_inline void stopIntFlagClear() {
            setBit_(REG(USI_N(STOP_CONDITION_INT_FLAG_BIT_0_REG)), USI_N(STOP_CONDITION_INT_FLAG_BIT_0_BIT), true);
        }
    #endif

    #if DEFINED(USI_N(COUNTER_OVERFLOW_INT_FLAG_BIT_0_BIT))
        /// #### static bool overflowIntFlag()
        /// Get the counter overflow interrupt flag's state.
        static force_inline bool overflowIntFlag() {
            return getBit(REG(USI_N(COUNTER_OVERFLOW_INT_FLAG_BIT_0_REG)), USI_N(COUNTER_OVERFLOW_INT_FLAG_BIT_0_BIT));
        }

        /// #### static void overflowIntFlagClear()
        /// Clear the counter overflow interrupt flag.
        static force_inline void overflowIntFlagClear() {
            setBit_(REG(USI_N(COUNTER_OVERFLOW_INT_FLAG_BIT_0_REG)), USI_N(COUNTER_OVERFLOW_INT_FLAG_BIT_0_BIT), true);
        }
    #endif

    #if DEFINED(USI_N(COLLISION_FLAG_BIT_0_BIT))
        /// #### static bool collisionFlag()
        /// Get the data output collision flag's state.
        static force_inline bool collisionFlag() {
            return getBit(REG(USI_N(COLLISION_FLAG_BIT_0_REG)), USI_N(COLLISION_FLAG_BIT_0_BIT));
        }
    #endif

    #if DEFINED(USI_N(COUNTER_BIT_0_BIT))
        /// #### static void counter(uint8_t c)
        static force_inline void counter(uint8_t c) {
            setBit_(REG(USI_N(COUNTER_BIT_0_REG)), USI_N(COUNTER_BIT_0_BIT), bool(c & 0x01));
            setBit_(REG(USI_N(COUNTER_BIT_1_REG)), USI_N(COUNTER_BIT_1_BIT), bool(c & 0x02));
            setBit_(REG(USI_N(COUNTER_BIT_2_REG)), USI_N(COUNTER_BIT_2_BIT), bool(c & 0x04));
            setBit_(REG(USI_N(COUNTER_BIT_3_REG)), USI_N(COUNTER_BIT_3_BIT), bool(c & 0x08));
        }

        /// #### static uint8_t counter()
        static force_inline uint8_t counter() {
            const uint8_t a = uint8_t(getBit(REG(USI_N(COUNTER_BIT_0_REG)), USI_N(COUNTER_BIT_0_BIT)) << 0);
            const uint8_t b = uint8_t(getBit(REG(USI_N(COUNTER_BIT_1_REG)), USI_N(COUNTER_BIT_1_BIT)) << 1);
            const uint8_t c = uint8_t(getBit(REG(USI_N(COUNTER_BIT_2_REG)), USI_N(COUNTER_BIT_2_BIT)) << 2);
            const uint8_t d = uint8_t(getBit(REG(USI_N(COUNTER_BIT_3_REG)), USI_N(COUNTER_BIT_3_BIT)) << 3);

            return a | b | c | d;
        }
    #endif
};

#ifdef TEST

TEST(UsiN, getHardwareType) {
    ASSERT_EQ(UsiN::getHardwareType(), HardwareType::usi);
}

TEST(UsiN, data) {
    #if REG_DEFINED(USI_N(DATA_REG))
        TEST_REG_WRITE(UsiN::data(0x12));
    #endif

    #if REG_DEFINED(USI_N(BUFFER_REG))
        TEST_REG_READ_WRITE(UsiN::data());
    #endif
}

#if DEFINED(USI_N(START_CONDITION_INT_ENABLE_BIT_0_BIT))
    TEST(UsiN, startIntEnable) {
        TEST_REG_WRITE(UsiN::startIntEnable(true));
        TEST_REG_WRITE(UsiN::startIntEnable(false));
    }
#endif

#if DEFINED(USI_N(COUNTER_OVERFLOW_INT_ENABLE_BIT_0_BIT))
    TEST(UsiN, overflowIntEnable) {
        TEST_REG_WRITE(UsiN::overflowIntEnable(true));
        TEST_REG_WRITE(UsiN::overflowIntEnable(false));
    }
#endif

#if DEFINED(USI_N(WIRE_MODE_BIT_0_BIT))
    TEST(UsiN, wireMode) {
        TEST_REG_WRITE(UsiN::wireMode(UsiN::WireMode::disabled));
        TEST_REG_WRITE(UsiN::wireMode(UsiN::WireMode::threeWire));
        TEST_REG_WRITE(UsiN::wireMode(UsiN::WireMode::twoWire));
        TEST_REG_WRITE(UsiN::wireMode(UsiN::WireMode::twoWireOverflow));
    }
#endif

#if DEFINED(USI_N(CLOCK_SELECT_BIT_0_BIT))
    TEST(UsiN, clock) {
        TEST_REG_WRITE(UsiN::clock(UsiN::Clock::none));
        TEST_REG_WRITE(UsiN::clock(UsiN::Clock::timer0CompareMatch));
        TEST_REG_WRITE(UsiN::clock(UsiN::Clock::externalPositiveEdge));
        TEST_REG_WRITE(UsiN::clock(UsiN::Clock::externalNegativeEdge));
    }
#endif

#if DEFINED(USI_N(CLOCK_STROBE_BIT_0_BIT))
    TEST(UsiN, clockStrobe) {
        TEST_REG_WRITE(UsiN::clockStrobe());
    }
#endif

#if DEFINED(USI_N(TOGGLE_CLOCK_PIN_BIT_0_BIT))
    TEST(UsiN, toggleClockPin) {
        TEST_REG_WRITE(UsiN::toggleClockPin());
    }
#endif

#if DEFINED(USI_N(START_CONDITION_INT_FLAG_BIT_0_BIT))
    TEST(UsiN, startIntFlag) {
        TEST_REG_READ_WRITE(UsiN::startIntFlag());
    }

    TEST(UsiN, startIntFlagClear) {
        TEST_REG_WRITE(UsiN::startIntFlagClear());
    }
#endif

#if DEFINED(USI_N(STOP_CONDITION_INT_FLAG_BIT_0_BIT))
    TEST(UsiN, stopIntFlag) {
        TEST_REG_READ_WRITE(UsiN::stopIntFlag());
    }

    TEST(UsiN, stopIntFlagClear) {
        TEST_REG_WRITE(UsiN::stopIntFlagClear());
    }
#endif

#if DEFINED(USI_N(COUNTER_OVERFLOW_INT_FLAG_BIT_0_BIT))
    TEST(UsiN, overflowIntFlag) {
        TEST_REG_READ_WRITE(UsiN::overflowIntFlag());
    }

    TEST(UsiN, overflowIntFlagClear) {
        TEST_REG_WRITE(UsiN::overflowIntFlagClear());
    }
#endif

#if DEFINED(USI_N(COLLISION_FLAG_BIT_0_BIT))
    TEST(UsiN, collisionFlag) {
        TEST_REG_READ_WRITE(UsiN::collisionFlag());
    }
#endif

#if DEFINED(USI_N(COUNTER_BIT_0_BIT))
    TEST(UsiN, counter) {
        TEST_REG_WRITE(UsiN::counter(0x12));
        TEST_REG_READ_WRITE(UsiN::counter());
    }
#endif

#endif

} // nblib::hw

//------------------------------------------------------------------

    #endif

    #undef N
    #undef UsiN
    #undef USI_N

    #include "usi.hpp"
#else
    #define NBLIB_USI_HPP
#endif

#endif
