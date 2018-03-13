/// # SPI

/// N is the USI id (0, 1, 2, etc).

#ifndef NBOS_USI_HPP

#include "callbacks.hpp"
#include "chip.hpp"
#include "hardwaretype.hpp"
#include "macros.hpp"
#include "type.hpp"
#include "util.hpp"
#include "port.hpp"

#define N _I
#define UsiN CAT(Usi,N)
#define USI_N(A) CAT(CHIP_USI_, N, _, A)
#define _USI_N(A) UNDERLINE(USI, N, A)

/// #### macro INCLUDE_USI_CALLBACK(N, X)
/// Include this to use Usi callbacks.<br>
/// N is the Usi id, X is one of START or OVERFLOW.
#define INCLUDE_USI_CALLBACK(N, X) MAKE_CALLBACK(USI, N, X)

#include "loopi"

#ifdef _I
    #if CAT(CHIP_USI_, N)

//------------------------------------------------------------------

MAKE_CALLBACK_HEADER(USI, N, START);
MAKE_CALLBACK_HEADER(USI, N, OVERFLOW);

/// ## class UsiN
struct UsiN {
    UsiN() = delete;
    UsiN& operator=(const UsiN&) = delete;
    UsiN(const UsiN&) = delete;

    /// #### type PinDo
    /// The DO IO pin.
    using PinDo = USI_N(PIN_DO);

    /// #### type PinDi
    /// The DI IO pin.
    using PinDi = USI_N(PIN_DI);

    /// #### type PinSda
    /// The SDA IO pin.
    using PinSda = USI_N(PIN_SDA);

    /// #### type PinScl
    /// The SCL IO pin.
    using PinScl = USI_N(PIN_SCL);

    /// #### type PinUsck
    /// The USCK IO pin.
    using PinUsck = USI_N(PIN_USCK);

    #if DEFINED(USI_N(WIRE_MODE_BIT_0_BIT))
        /// #### enum WireMode
        /// * disabled
        /// * threeWire
        /// * twoWire
        /// * twoWireOverflow
        enum class WireMode : uint8_t {
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
        enum class Clock : uint8_t {
            none = USI_N(CLOCK_SELECT_NONE_ID),
            timer0CompareMatch = USI_N(CLOCK_SELECT_TIMER_0_COMPARE_MATCH_ID),
            externalPositiveEdge = USI_N(CLOCK_SELECT_EXTERNAL_POSITIVE_EDGE_ID),
            externalNegativeEdge = USI_N(CLOCK_SELECT_EXTERNAL_NEGATIVE_EDGE_ID),
        };
    #endif

    // #if DEFINED(USI_N(POLARITY_BIT_0_BIT))
    //     /// #### enum Polarity
    //     /// * leadingRisingTrailingFalling
    //     /// * leadingFallingTrailingRising
    //     enum class Polarity : uint8_t {
    //         leadingRisingTrailingFalling = USI_N(POLARITY_LEADING_RISING_TRAILING_FALLING_ID),
    //         leadingFallingTrailingRising = USI_N(POLARITY_LEADING_FALLING_TRAILING_RISING_ID),
    //     };
    // #endif

    // #if DEFINED(USI_N(PHASE_BIT_0_BIT))
    //     /// #### enum Phase
    //     /// * leadingSampleTrailingSetup
    //     /// * leadingSetupTrailingSample
    //     enum class Phase : uint8_t {
    //         leadingSampleTrailingSetup = USI_N(PHASE_LEADING_SAMPLE_TRAILING_SETUP_ID),
    //         leadingSetupTrailingSample = USI_N(PHASE_LEADING_SETUP_TRAILING_SAMPLE_ID),
    //     };
    // #endif

    // #if DEFINED(USI_N(CLOCK_BIT_0_BIT))
    //     /// #### enum Clock
    //     /// * div2
    //     /// * div4
    //     /// * div8
    //     /// * div16
    //     /// * div32
    //     /// * div64
    //     /// * div128
    //     enum class Clock : uint8_t {
    //         #if DEFINED(USI_N(CLOCK_DIV_2_ID))
    //             div2 = USI_N(CLOCK_DIV_2_ID),
    //         #endif

    //         #if DEFINED(USI_N(CLOCK_DIV_4_ID))
    //             div4 = USI_N(CLOCK_DIV_4_ID),
    //         #endif

    //         #if DEFINED(USI_N(CLOCK_DIV_8_ID))
    //             div8 = USI_N(CLOCK_DIV_8_ID),
    //         #endif

    //         #if DEFINED(USI_N(CLOCK_DIV_16_ID))
    //             div16 = USI_N(CLOCK_DIV_16_ID),
    //         #endif

    //         #if DEFINED(USI_N(CLOCK_DIV_32_ID))
    //             div32 = USI_N(CLOCK_DIV_32_ID),
    //         #endif

    //         #if DEFINED(USI_N(CLOCK_DIV_64_ID))
    //             div64 = USI_N(CLOCK_DIV_64_ID),
    //         #endif

    //         #if DEFINED(USI_N(CLOCK_DIV_128_ID))
    //             div128 = USI_N(CLOCK_DIV_128_ID),
    //         #endif
    //     };
    // #endif

    /// #### static constexpr HardwareType getHardwareType()
    /// Get the type of hardware that this class represents.
    static constexpr HardwareType getHardwareType() {
        return HardwareType::usi;
    }

    #if REG_DEFINED(USI_N(DATA_REG))
        /// #### static void data(uint8_t d)
        /// Put value d into the data register.
        static force_inline void data(uint8_t d) {
            *REG(USI_N(DATA_REG)) = d;
        }
    #endif

    #if REG_DEFINED(USI_N(BUFFER_REG))
        /// #### static uint8_t data()
        /// Get value from the data register.
        static force_inline uint8_t data() {
            return *REG(USI_N(BUFFER_REG));
        }
    #endif

    #if DEFINED(USI_N(START_CONDITION_INT_ENABLE_BIT_0_BIT))
        /// #### static void startConditionIntEnable(bool b)
        /// Enable the start condition interrupt.
        static force_inline void startConditionIntEnable(bool b) {
            setBit_(REG(USI_N(START_CONDITION_INT_ENABLE_BIT_0_REG)), USI_N(START_CONDITION_INT_ENABLE_BIT_0_BIT), b);
        }
    #endif

    #if DEFINED(USI_N(COUNTER_OVERFLOW_INT_ENABLE_BIT_0_BIT))
        /// #### static void counterOverflowIntEnable(bool b)
        /// Enable the counter overflow interrupt.
        static force_inline void counterOverflowIntEnable(bool b) {
            setBit_(REG(USI_N(COUNTER_OVERFLOW_INT_ENABLE_BIT_0_REG)), USI_N(COUNTER_OVERFLOW_INT_ENABLE_BIT_0_BIT), b);
        }
    #endif

    #if DEFINED(USI_N(WIRE_MODE_BIT_0_BIT))
        /// #### static void wireMode(WireMode m)
        /// Set the USI interface mode.
        static force_inline void wireMode(WireMode m) {
            setBit_(REG(USI_N(WIRE_MODE_BIT_0_REG)), USI_N(WIRE_MODE_BIT_0_BIT), uint8_t(m) & 0x01);

            #if DEFINED(USI_N(CLOCK_SELECT_BIT_1_BIT))
                setBit_(REG(USI_N(CLOCK_SELECT_BIT_1_REG)), USI_N(CLOCK_SELECT_BIT_1_BIT), uint8_t(m) & 0x01);
            #endif
        }
    #endif

    #if DEFINED(USI_N(CLOCK_SELECT_BIT_0_BIT))
        /// #### static void clock(Clock c)
        /// Set the clock source.
        static force_inline void clock(Clock c) {
            setBit_(REG(USI_N(CLOCK_SELECT_BIT_0_REG)), USI_N(CLOCK_SELECT_BIT_0_BIT), uint8_t(c) & 0x01);

            #if DEFINED(USI_N(CLOCK_SELECT_BIT_1_BIT))
                setBit_(REG(USI_N(CLOCK_SELECT_BIT_1_REG)), USI_N(CLOCK_SELECT_BIT_1_BIT), uint8_t(c) & 0x02);
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
        /// #### static void startConditionIntFlag()
        /// Get the start condition interrupt flag's state.
        static force_inline bool startConditionIntFlag() {
            return getBit(REG(USI_N(START_CONDITION_INT_FLAG_BIT_0_REG)), USI_N(START_CONDITION_INT_FLAG_BIT_0_BIT));
        }

        /// #### static void startConditionIntFlagClear()
        /// Clear the start condition interrupt flag.
        static force_inline void startConditionIntFlagClear() {
            setBit_(REG(USI_N(START_CONDITION_INT_FLAG_BIT_0_REG)), USI_N(START_CONDITION_INT_FLAG_BIT_0_BIT), true);
        }
    #endif

    #if DEFINED(USI_N(STOP_CONDITION_INT_FLAG_BIT_0_BIT))
        /// #### static void stopConditionIntFlag()
        /// Get the stop condition interrupt flag's state.
        static force_inline bool stopConditionIntFlag() {
            return getBit(REG(USI_N(STOP_CONDITION_INT_FLAG_BIT_0_REG)), USI_N(STOP_CONDITION_INT_FLAG_BIT_0_BIT));
        }

        /// #### static void stopConditionIntFlagClear()
        /// Clear the stop condition interrupt flag.
        static force_inline void stopConditionIntFlagClear() {
            setBit_(REG(USI_N(STOP_CONDITION_INT_FLAG_BIT_0_REG)), USI_N(STOP_CONDITION_INT_FLAG_BIT_0_BIT), true);
        }
    #endif

    #if DEFINED(USI_N(COUNTER_OVERFLOW_INT_FLAG_BIT_0_BIT))
        /// #### static bool counterOverflowIntFlag()
        /// Get the counter overflow interrupt flag's state.
        static force_inline bool counterOverflowIntFlag() {
            return getBit(REG(USI_N(COUNTER_OVERFLOW_INT_FLAG_BIT_0_REG)), USI_N(COUNTER_OVERFLOW_INT_FLAG_BIT_0_BIT));
        }

        /// #### static void counterOverflowIntFlagClear()
        /// Clear the counter overflow interrupt flag.
        static force_inline void counterOverflowIntFlagClear() {
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
        /// Set the counter register.
        static force_inline void counter(uint8_t c) {
            setBit_(REG(USI_N(COUNTER_BIT_0_REG)), USI_N(COUNTER_BIT_0_BIT), c & 0x01);
            setBit_(REG(USI_N(COUNTER_BIT_1_REG)), USI_N(COUNTER_BIT_1_BIT), c & 0x02);
            setBit_(REG(USI_N(COUNTER_BIT_2_REG)), USI_N(COUNTER_BIT_2_BIT), c & 0x04);
            setBit_(REG(USI_N(COUNTER_BIT_3_REG)), USI_N(COUNTER_BIT_3_BIT), c & 0x08);
        }

        /// #### static uint8_t counter()
        /// Get the counter register.
        static force_inline uint8_t counter() {
            uint8_t c = 0;

            c |= uint8_t(getBit(REG(USI_N(COUNTER_BIT_0_REG)), USI_N(COUNTER_BIT_0_BIT))) << 0;
            c |= uint8_t(getBit(REG(USI_N(COUNTER_BIT_1_REG)), USI_N(COUNTER_BIT_1_BIT))) << 1;
            c |= uint8_t(getBit(REG(USI_N(COUNTER_BIT_2_REG)), USI_N(COUNTER_BIT_2_BIT))) << 2;
            c |= uint8_t(getBit(REG(USI_N(COUNTER_BIT_3_REG)), USI_N(COUNTER_BIT_3_BIT))) << 3;

            return c;
        }
    #endif
};

//------------------------------------------------------------------

    #endif

    #include "usi.hpp"
#else
    #define NBOS_USI_HPP
#endif

#undef N
#undef UsiN
#undef USI_N
#undef _USI_N

#endif
