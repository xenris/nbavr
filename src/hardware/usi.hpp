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

    #if DEFINED(CAT(CHIP_USI_, N))

//------------------------------------------------------------------

namespace nblib::hw {

/// ## class UsiN
struct UsiN {
    UsiN() = delete;
    UsiN& operator=(const UsiN&) = delete;
    UsiN(const UsiN&) = delete;

    #if REG_DEFINED(USI_N(WIRE_MODE_REG))
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

    #if REG_DEFINED(USI_N(CLOCK_SELECT_REG))
        /// #### enum Clock
        /// * none
        /// * tc0CompareMatch
        /// * externalPositiveEdge
        /// * externalNegativeEdge
        enum class Clock {
            none = USI_N(CLOCK_SELECT_NONE_ID),
            tc0CompareMatch = USI_N(CLOCK_SELECT_TC_0_COMPARE_MATCH_ID),
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
            USI_N(DATA_REG)::setReg(d);
        }

        /// #### static uint8_t data()
        static force_inline uint8_t data() {
            return USI_N(DATA_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(USI_N(BUFFER_REG))
        /// #### static uint8_t buffer()
        /// Buffered copy of the data register.
        static force_inline uint8_t buffer() {
            return USI_N(BUFFER_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(USI_N(START_CONDITION_INT_ENABLE_REG))
        /// #### static void startIntEnable(bool b)
        static force_inline void startIntEnable(bool b) {
            USI_N(START_CONDITION_INT_ENABLE_REG)::setBit(USI_N(START_CONDITION_INT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(USI_N(COUNTER_OVERFLOW_INT_ENABLE_REG))
        /// #### static void overflowIntEnable(bool b)
        static force_inline void overflowIntEnable(bool b) {
            USI_N(COUNTER_OVERFLOW_INT_ENABLE_REG)::setBit(USI_N(COUNTER_OVERFLOW_INT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(USI_N(WIRE_MODE_REG))
        /// #### static void wireMode(WireMode m)
        static force_inline void wireMode(WireMode m) {
            USI_N(WIRE_MODE_REG)::setBits(USI_N(WIRE_MODE_MASK), m);
        }
    #endif

    #if REG_DEFINED(USI_N(CLOCK_SELECT_REG))
        /// #### static void clock(Clock c)
        static force_inline void clock(Clock c) {
            USI_N(CLOCK_SELECT_REG)::setBits(USI_N(CLOCK_SELECT_MASK), c);
        }
    #endif

    #if REG_DEFINED(USI_N(CLOCK_STROBE_REG))
        /// #### static void clockStrobe()
        /// Increment counter and Shift the USI data register.
        static force_inline void clockStrobe() {
            USI_N(CLOCK_STROBE_REG)::setBit(USI_N(CLOCK_STROBE_BIT), true);
        }
    #endif

    #if REG_DEFINED(USI_N(TOGGLE_CLOCK_PIN_REG))
        /// #### static void toggleClockPin()
        /// Toggle the clock pin or increment the counter
        static force_inline void toggleClockPin() {
            USI_N(TOGGLE_CLOCK_PIN_REG)::setBit(USI_N(TOGGLE_CLOCK_PIN_BIT), true);
        }
    #endif

    #if REG_DEFINED(USI_N(START_CONDITION_INT_FLAG_REG))
        /// #### static void startIntFlag()
        static force_inline bool startIntFlag() {
            return USI_N(START_CONDITION_INT_FLAG_REG)::getBit(USI_N(START_CONDITION_INT_FLAG_BIT));
        }

        /// #### static void startIntFlagClear()
        static force_inline void startIntFlagClear() {
            USI_N(START_CONDITION_INT_FLAG_REG)::setBit(USI_N(START_CONDITION_INT_FLAG_BIT), true);
        }
    #endif

    #if REG_DEFINED(USI_N(STOP_CONDITION_INT_FLAG_REG))
        /// #### static void stopIntFlag()
        static force_inline bool stopIntFlag() {
            return USI_N(STOP_CONDITION_INT_FLAG_REG)::getBit(USI_N(STOP_CONDITION_INT_FLAG_BIT));
        }

        /// #### static void stopIntFlagClear()
        static force_inline void stopIntFlagClear() {
            USI_N(STOP_CONDITION_INT_FLAG_REG)::setBit(USI_N(STOP_CONDITION_INT_FLAG_BIT), true);
        }
    #endif

    #if REG_DEFINED(USI_N(COUNTER_OVERFLOW_INT_FLAG_REG))
        /// #### static bool overflowIntFlag()
        static force_inline bool overflowIntFlag() {
            return USI_N(COUNTER_OVERFLOW_INT_FLAG_REG)::getBit(USI_N(COUNTER_OVERFLOW_INT_FLAG_BIT));
        }

        /// #### static void overflowIntFlagClear()
        static force_inline void overflowIntFlagClear() {
            USI_N(COUNTER_OVERFLOW_INT_FLAG_REG)::setBit(USI_N(COUNTER_OVERFLOW_INT_FLAG_BIT), true);
        }
    #endif

    #if REG_DEFINED(USI_N(COLLISION_FLAG_REG))
        /// #### static bool collisionFlag()
        static force_inline bool collisionFlag() {
            return USI_N(COLLISION_FLAG_REG)::getBit(USI_N(COLLISION_FLAG_BIT));
        }
    #endif

    #if REG_DEFINED(USI_N(COUNTER_REG))
        /// #### static void counter(uint8_t c)
        static force_inline void counter(uint8_t c) {
            USI_N(COUNTER_REG)::setReg(c & USI_N(COUNTER_MASK));
        }

        /// #### static uint8_t counter()
        static force_inline uint8_t counter() {
            return USI_N(COUNTER_REG)::getReg<uint8_t>() & USI_N(COUNTER_MASK);
        }
    #endif
};

#ifdef TEST

TEST(UsiN, getHardwareType) {
    ASSERT_EQ(UsiN::getHardwareType(), HardwareType::usi);
}

#if REG_DEFINED(USI_N(DATA_REG))
    TEST(UsiN, data) {
        TEST_REG_WRITE(UsiN::data(0x12));

        TEST_REG_READ_WRITE(UsiN::data());

        #if REG_DEFINED(USI_N(BUFFER_REG))
            TEST_REG_READ_WRITE(UsiN::buffer());
        #endif
    }
#endif

#if REG_DEFINED(USI_N(START_CONDITION_INT_ENABLE_REG))
    TEST(UsiN, startIntEnable) {
        TEST_REG_WRITE(UsiN::startIntEnable(true));
        TEST_REG_WRITE(UsiN::startIntEnable(false));
    }
#endif

#if REG_DEFINED(USI_N(COUNTER_OVERFLOW_INT_ENABLE_REG))
    TEST(UsiN, overflowIntEnable) {
        TEST_REG_WRITE(UsiN::overflowIntEnable(true));
        TEST_REG_WRITE(UsiN::overflowIntEnable(false));
    }
#endif

#if REG_DEFINED(USI_N(WIRE_MODE_REG))
    TEST(UsiN, wireMode) {
        TEST_REG_WRITE(UsiN::wireMode(UsiN::WireMode::disabled));
        TEST_REG_WRITE(UsiN::wireMode(UsiN::WireMode::threeWire));
        TEST_REG_WRITE(UsiN::wireMode(UsiN::WireMode::twoWire));
        TEST_REG_WRITE(UsiN::wireMode(UsiN::WireMode::twoWireOverflow));
    }
#endif

#if REG_DEFINED(USI_N(CLOCK_SELECT_REG))
    TEST(UsiN, clock) {
        TEST_REG_WRITE(UsiN::clock(UsiN::Clock::none));
        TEST_REG_WRITE(UsiN::clock(UsiN::Clock::tc0CompareMatch));
        TEST_REG_WRITE(UsiN::clock(UsiN::Clock::externalPositiveEdge));
        TEST_REG_WRITE(UsiN::clock(UsiN::Clock::externalNegativeEdge));
    }
#endif

#if REG_DEFINED(USI_N(CLOCK_STROBE_REG))
    TEST(UsiN, clockStrobe) {
        TEST_REG_WRITE(UsiN::clockStrobe());
    }
#endif

#if REG_DEFINED(USI_N(TOGGLE_CLOCK_PIN_REG))
    TEST(UsiN, toggleClockPin) {
        TEST_REG_WRITE(UsiN::toggleClockPin());
    }
#endif

#if REG_DEFINED(USI_N(START_CONDITION_INT_FLAG_REG))
    TEST(UsiN, startIntFlag) {
        TEST_REG_READ_WRITE(UsiN::startIntFlag());
    }

    TEST(UsiN, startIntFlagClear) {
        TEST_REG_WRITE(UsiN::startIntFlagClear());
    }
#endif

#if REG_DEFINED(USI_N(STOP_CONDITION_INT_FLAG_REG))
    TEST(UsiN, stopIntFlag) {
        TEST_REG_READ_WRITE(UsiN::stopIntFlag());
    }

    TEST(UsiN, stopIntFlagClear) {
        TEST_REG_WRITE(UsiN::stopIntFlagClear());
    }
#endif

#if REG_DEFINED(USI_N(COUNTER_OVERFLOW_INT_FLAG_REG))
    TEST(UsiN, overflowIntFlag) {
        TEST_REG_READ_WRITE(UsiN::overflowIntFlag());
    }

    TEST(UsiN, overflowIntFlagClear) {
        TEST_REG_WRITE(UsiN::overflowIntFlagClear());
    }
#endif

#if REG_DEFINED(USI_N(COLLISION_FLAG_REG))
    TEST(UsiN, collisionFlag) {
        TEST_REG_READ_WRITE(UsiN::collisionFlag());
    }
#endif

#if REG_DEFINED(USI_N(COUNTER_REG))
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
