/// [[Index]]

/// # {{Universal Serial Interfaces}}

/// ```c++
/// // TODO
/// ```

#ifndef NBOS_USI_HPP

#include "isr.hpp"
#include "chip.hpp"
#include "hardwaretype.hpp"
#include "macros.hpp"
#include "type.hpp"
#include "system.hpp"
#include "port.hpp"

#include "loopi"

#ifdef _I
    #define N _I
    #define UsiN CAT(Usi,N)
    #define USI_N(A) CAT(CHIP_USI_, N, _, A)

    #if CAT(CHIP_USI_, N)

//------------------------------------------------------------------

namespace nbos::hw {

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

    /// #### static HardwareType getHardwareType()
    static constexpr HardwareType getHardwareType() {
        return HardwareType::usi;
    }

    #if REG_DEFINED(USI_N(DATA_REG))
        /// #### static void data(uint8_t d)
        static force_inline void data(uint8_t d) {
            *REG(USI_N(DATA_REG)) = d;
        }
    #endif

    #if REG_DEFINED(USI_N(BUFFER_REG))
        /// #### static uint8_t data()
        static force_inline uint8_t data() {
            return *REG(USI_N(BUFFER_REG));
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
            setBit_(REG(USI_N(WIRE_MODE_BIT_0_REG)), USI_N(WIRE_MODE_BIT_0_BIT), uint8_t(m) & 0x01);

            #if DEFINED(USI_N(CLOCK_SELECT_BIT_1_BIT))
                setBit_(REG(USI_N(CLOCK_SELECT_BIT_1_REG)), USI_N(CLOCK_SELECT_BIT_1_BIT), uint8_t(m) & 0x01);
            #endif
        }
    #endif

    #if DEFINED(USI_N(CLOCK_SELECT_BIT_0_BIT))
        /// #### static void clock(Clock c)
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
            setBit_(REG(USI_N(COUNTER_BIT_0_REG)), USI_N(COUNTER_BIT_0_BIT), c & 0x01);
            setBit_(REG(USI_N(COUNTER_BIT_1_REG)), USI_N(COUNTER_BIT_1_BIT), c & 0x02);
            setBit_(REG(USI_N(COUNTER_BIT_2_REG)), USI_N(COUNTER_BIT_2_BIT), c & 0x04);
            setBit_(REG(USI_N(COUNTER_BIT_3_REG)), USI_N(COUNTER_BIT_3_BIT), c & 0x08);
        }

        /// #### static uint8_t counter()
        static force_inline uint8_t counter() {
            uint8_t c = 0;

            c |= uint8_t(getBit(REG(USI_N(COUNTER_BIT_0_REG)), USI_N(COUNTER_BIT_0_BIT))) << 0;
            c |= uint8_t(getBit(REG(USI_N(COUNTER_BIT_1_REG)), USI_N(COUNTER_BIT_1_BIT))) << 1;
            c |= uint8_t(getBit(REG(USI_N(COUNTER_BIT_2_REG)), USI_N(COUNTER_BIT_2_BIT))) << 2;
            c |= uint8_t(getBit(REG(USI_N(COUNTER_BIT_3_REG)), USI_N(COUNTER_BIT_3_BIT))) << 3;

            return c;
        }
    #endif

    /// #### static void startCallback(callback_t callback, void\* data)
    /// Set callback for start condition interrupt.
    static force_inline void startCallback(callback_t callback = nullptr, void* data = nullptr) {
        static callback_t f = nullptr;
        static void* d = nullptr;

        if(callback == nullptr) {
            if(f != nullptr) {
                f(d);
            }
        } else {
            f = callback;
            d = data;
        }
    }

    /// #### static void overflowCallback(callback_t callback, void\* data)
    /// Set callback for timer overflow interrupt.
    static force_inline void overflowCallback(callback_t callback = nullptr, void* data = nullptr) {
        static callback_t f = nullptr;
        static void* d = nullptr;

        if(callback == nullptr) {
            if(f != nullptr) {
                f(d);
            }
        } else {
            f = callback;
            d = data;
        }
    }
};

ISR(USI_N(START_INT_VECTOR)) {
    UsiN::startCallback();
}

ISR(USI_N(OVERFLOW_INT_VECTOR)) {
    UsiN::overflowCallback();
}

} // nbos::hw

//------------------------------------------------------------------

    #endif

    #undef N
    #undef UsiN
    #undef USI_N

    #include "usi.hpp"
#else
    #define NBOS_USI_HPP
#endif

#endif
