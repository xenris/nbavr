/// # Pin Change Interrupts

/// All functions are static.

#ifndef NBAVR_PCINT_HPP

#ifndef N
    // PcInt id.
    #define N 0
#endif

#if N < CHIP_PCINT_COUNT
    // If this hardware exists.
    #if CONCAT(CHIP_PCINT_, N)

//--------------------------------------------------------

#define PcIntN CONCAT(PcInt, N)
#define C(X) CONCAT(CHIP_PCINT_, N, _, X)
#define _C(X) UNDERLINE(PCINT, N, X)

MAKE_CALLBACK_HEADER(PCINT, N);

/// #### macro INCLUDE_PCINT_CALLBACK(N)
/// Include this to use PcInt callbacks.
#define INCLUDE_PCINT_CALLBACK(N) MAKE_CALLBACK(PCINT, N)

/// ## Class PCIntN
struct PcIntN {
    PcIntN() = delete;

    /// #### static constexpr HardwareType getHardwareType()
    /// Get the type of hardware that this class represents.
    static constexpr HardwareType getHardwareType() {
        return HardwareType::PcInt;
    }

    /// #### static void enable(bool)
    /// Enable/disable this interrupt.
    static force_inline void enable(bool e) {
        setBit_(C(ENABLE_REG), C(ENABLE_BIT), e);
    }

    /// #### static void mask(uint8_t)
    /// Set which pins trigger this interrupt.
    static force_inline void mask(uint8_t m) {
        *C(MASK_REG) = m;
    }

    /// #### static void callback(void (\*)(void\*), void\*)
    /// Set the callback and data for this interrupt.
    static force_inline void callback(void (*func)(void*), void* data) {
        _C(Callback) = func;
        _C(CallbackData) = data;
    }

    /// #### static bool intFlag()
    /// Returns true if the interrupt flag is set.
    static force_inline bool intFlag() {
        return *C(FLAG_REG) & bv(C(FLAG_BIT));
    }

    /// #### static void intFlagClear()
    /// Clear the interrupt flag.
    static force_inline void intFlagClear() {
        setBit_(C(FLAG_REG), C(FLAG_BIT), true);
    }
};

#undef PcIntN
#undef C
#undef _C

//--------------------------------------------------------

    #endif // CONCAT(CHIP_PCINT_, N)

    #include "incn.hpp"

    #include "pcint.hpp"

#else // N < CHIP_PCINT_COUNT

    #undef N

    #define NBAVR_PCINT_HPP

#endif // N < CHIP_PCINT_COUNT

#endif
