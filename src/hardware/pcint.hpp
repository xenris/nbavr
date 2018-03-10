/// # Pin Change Interrupts

#ifndef NBAVR_PCINT_HPP

#include "callbacks.hpp"
#include "chip.hpp"
#include "hardwaretype.hpp"
#include "macros.hpp"
#include "util.hpp"

#define N _I
#define PcIntN CAT(PcInt, N)
#define PCINT_N(A) CAT(CHIP_PCINT_, N, _, A)
#define _PCINT_N(A) UNDERLINE(PCINT, N, A)

/// #### macro INCLUDE_PCINT_CALLBACK(N)
/// Include this to use PcInt callbacks.
#define INCLUDE_PCINT_CALLBACK(N) MAKE_CALLBACK(PCINT, N)

#include "loopi"

#ifdef _I
    #if CAT(CHIP_PCINT_, N)

//--------------------------------------------------------

MAKE_CALLBACK_HEADER(PCINT, N);

/// ## Class PCIntN
struct PcIntN {
    PcIntN() = delete;

    /// #### static constexpr HardwareType getHardwareType()
    /// Get the type of hardware that this class represents.
    static constexpr HardwareType getHardwareType() {
        return HardwareType::pcInt;
    }

    #if DEFINED(PCINT_N(ENABLE_BIT_0_BIT))
        /// #### static void enable(bool e)
        /// Enable/disable this interrupt.
        static force_inline void enable(bool e) {
            setBit_(REG(PCINT_N(ENABLE_BIT_0_REG)), PCINT_N(ENABLE_BIT_0_BIT), e);
        }
    #endif

    #if REG_DEFINED(PCINT_N(MASK_REG))
        /// #### static void mask(uint8_t m)
        /// Set which pins trigger this interrupt.
        static force_inline void mask(uint8_t m) {
            *REG(PCINT_N(MASK_REG)) = m;
        }
    #endif

    /// #### static void callback(callback_t callback, void\* data)
    /// Set the callback and data for this interrupt.
    static force_inline void callback(callback_t callback, void* data) {
        _PCINT_N(Callback) = callback;
        _PCINT_N(CallbackData) = data;
    }

    #if DEFINED(PCINT_N(INT_FLAG_BIT_0_BIT))
        /// #### static bool intFlag()
        /// Returns true if the interrupt flag is set.
        static force_inline bool intFlag() {
            return *REG(PCINT_N(INT_FLAG_BIT_0_REG)) & bv(PCINT_N(INT_FLAG_BIT_0_BIT));
        }
    #endif

    #if DEFINED(PCINT_N(INT_FLAG_BIT_0_BIT))
        /// #### static void intFlagClear()
        /// Clear the interrupt flag.
        static force_inline void intFlagClear() {
            setBit_(REG(PCINT_N(INT_FLAG_BIT_0_REG)), PCINT_N(INT_FLAG_BIT_0_BIT), true);
        }
    #endif
};

//--------------------------------------------------------

    #endif

    #include "pcint.hpp"
#else
    #define NBAVR_PCINT_HPP
#endif

#undef N
#undef PcIntN
#undef PCINT_N
#undef _PCINT_N

#endif
