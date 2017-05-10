/// # External Interrupts

/// N is the external interrupt id (1, 2, etc).<br>
/// All functions are static.

#ifndef NBAVR_EXINT_HPP

#ifndef N
    // ExInt id.
    #define N 0
#endif

#if N < CHIP_EXINT_COUNT
    // If this hardware exists.
    #if CONCAT(CHIP_EXINT_, N)

//--------------------------------------------------------

#define ExIntN CONCAT(ExInt, N)
#define C(X) CONCAT(CHIP_EXINT_, N, _, X)
#define _C(X) UNDERLINE(EXINT, N, X)

MAKE_CALLBACK_HEADER(EXINT, N);

/// #### macro INCLUDE_EXINT_CALLBACK(N)
/// Include this to use ExInt callbacks.
#define INCLUDE_EXINT_CALLBACK(N) MAKE_CALLBACK(EXINT, N)

/// ## class ExIntN
struct ExIntN {
    ExIntN() = delete;

    /// #### enum Trigger
    /// * Low
    /// * Change
    /// * Falling
    /// * Rising
    enum class Trigger : uint8_t {
        Low = C(TRIGGER_LOW_ID),
        Change = C(TRIGGER_CHANGE_ID),
        Falling = C(TRIGGER_FALLING_ID),
        Rising = C(TRIGGER_RISING_ID),
    };

    /// #### constexpr HardwareType getHardwareType()
    /// Get the type of hardware that this class represents.
    static constexpr HardwareType getHardwareType() {
        return HardwareType::ExInt;
    }

    /// #### void enable(bool)
    /// Enable/disable this interrupt.
    static force_inline void enable(bool e) {
        setBit_(C(ENABLE_REG), C(ENABLE_BIT), e);
    }

    /// #### void trigger(Trigger)
    /// Set the trigger action.
    static force_inline void trigger(Trigger trigger) {
        setBit_(C(TRIGGER_BIT_0_REG), C(TRIGGER_BIT_0_BIT), uint8_t(trigger) & 0x01);
        setBit_(C(TRIGGER_BIT_1_REG), C(TRIGGER_BIT_1_BIT), uint8_t(trigger) & 0x02);
    }

    /// #### void callback(void (\*)(void\*), void\*)
    /// Set the callback and data for this interrupt.
    static force_inline void callback(void (*func)(void*), void* data) {
        _C(Callback) = func;
        _C(CallbackData) = data;
    }

    /// #### bool intFlag()
    /// Returns true if the interrupt flag is set.
    static force_inline bool intFlag() {
        return *C(FLAG_REG) & bv(C(FLAG_BIT));
    }

    /// #### void intFlagClear()
    /// Clear the interrupt flag.
    static force_inline void intFlagClear() {
        setBit_(C(FLAG_REG), C(FLAG_BIT), true);
    }
};

#undef ExIntN
#undef C
#undef _C

//--------------------------------------------------------

    #endif // CONCAT(CHIP_EXINT_, N)

    #include "incn.hpp"

    #include "exint.hpp"

#else // N < CHIP_EXINT_COUNT

    #undef N

    #define NBAVR_EXINT_HPP

#endif // N < CHIP_EXINT_COUNT

#endif
