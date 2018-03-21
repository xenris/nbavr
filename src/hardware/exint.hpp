/// # External Interrupts

/// N is the external interrupt id (1, 2, etc).

#ifndef NBOS_EXINT_HPP

#include "callbacks.hpp"
#include "chip.hpp"
#include "hardwaretype.hpp"
#include "macros.hpp"
#include "system.hpp"

#define N _I
#define ExIntN CAT(ExInt, N)
#define EXINT_N(A) CAT(CHIP_EXINT_, N, _, A)
#define _EXINT_N(A) UNDERLINE(EXINT, N, A)

/// #### macro INCLUDE_EXINT_CALLBACK(N)
/// Include this to use ExInt callbacks.
#define INCLUDE_EXINT_CALLBACK(N) MAKE_CALLBACK(EXINT, N)

#include "loopi"

#ifdef _I
    #if CAT(CHIP_EXINT_, N)

//--------------------------------------------------------

MAKE_CALLBACK_HEADER(EXINT, N);

/// ## class ExIntN
struct ExIntN {
    ExIntN() = delete;
    ExIntN& operator=(const ExIntN&) = delete;
    ExIntN(const ExIntN&) = delete;

    #if DEFINED(EXINT_N(TRIGGER_BIT_0_BIT))
        /// #### enum Trigger
        /// * low
        /// * change
        /// * falling
        /// * rising
        enum class Trigger : uint8_t {
            low = EXINT_N(TRIGGER_LOW_ID),
            change = EXINT_N(TRIGGER_CHANGE_ID),
            falling = EXINT_N(TRIGGER_FALLING_ID),
            rising = EXINT_N(TRIGGER_RISING_ID),
        };
    #endif

    /// #### static constexpr HardwareType getHardwareType()
    /// Get the type of hardware that this class represents.
    static constexpr HardwareType getHardwareType() {
        return HardwareType::exInt;
    }

    #if DEFINED(EXINT_N(ENABLE_BIT_0_BIT))
        /// #### static void enable(bool e)
        /// Enable/disable this interrupt.
        static force_inline void enable(bool e) {
            setBit_(REG(EXINT_N(ENABLE_BIT_0_REG)), EXINT_N(ENABLE_BIT_0_BIT), e);
        }
    #endif

    #if DEFINED(EXINT_N(TRIGGER_BIT_0_BIT))
        /// #### static void trigger(Trigger t)
        /// Set the trigger action.
        static force_inline void trigger(Trigger t) {
            setBit_(REG(EXINT_N(TRIGGER_BIT_0_REG)), EXINT_N(TRIGGER_BIT_0_BIT), uint8_t(t) & 0x01);
            setBit_(REG(EXINT_N(TRIGGER_BIT_1_REG)), EXINT_N(TRIGGER_BIT_1_BIT), uint8_t(t) & 0x02);
        }
    #endif

    /// #### static void callback(callback_t callback, void\* data)
    /// Set the callback and data for this interrupt.
    static force_inline void callback(callback_t callback, void* data) {
        _EXINT_N(Callback) = callback;
        _EXINT_N(CallbackData) = data;
    }

    #if DEFINED(EXINT_N(INT_FLAG_BIT_0_BIT))
        /// #### static bool intFlag()
        /// Returns true if the interrupt flag is set.
        static force_inline bool intFlag() {
            return *REG(EXINT_N(INT_FLAG_BIT_0_REG)) & bv(EXINT_N(INT_FLAG_BIT_0_BIT));
        }
    #endif

    #if DEFINED(EXINT_N(INT_FLAG_BIT_0_BIT))
        /// #### static void intFlagClear()
        /// Clear the interrupt flag.
        static force_inline void intFlagClear() {
            setBit_(REG(EXINT_N(INT_FLAG_BIT_0_REG)), EXINT_N(INT_FLAG_BIT_0_BIT), true);
        }
    #endif
};

//--------------------------------------------------------

    #endif

    #include "exint.hpp"
#else
    #define NBOS_EXINT_HPP
#endif

#undef N
#undef ExIntN
#undef EXINT_N
#undef _EXINT_N

#endif
