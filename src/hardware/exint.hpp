/// [[Index]]

/// # {{External Interrupts}}

/// ```c++
/// const auto f = [](void*) {
///     nbos::hw::PortB::Pin5::toggle();
/// };
///
/// atomic([]() {
///     nbos::hw::ExInt0::trigger(nbos::hw::ExInt0::Trigger::rising);
///     nbos::hw::ExInt0::callback((callback_t)f);
///     nbos::hw::ExInt0::intEnable(true);
/// });
/// ```

#ifndef NBOS_EXINT_HPP

#include "isr.hpp"
#include "chip.hpp"
#include "hardwaretype.hpp"
#include "macros.hpp"
#include "system.hpp"

#define N _I
#define ExIntN CAT(ExInt, N)
#define EXINT_N(A) CAT(CHIP_EXINT_, N, _, A)

#include "loopi"

#ifdef _I
    #if CAT(CHIP_EXINT_, N)

//--------------------------------------------------------

namespace nbos::hw {

/// ## class {{ExIntN}}
struct ExIntN {
    ExIntN() = delete;
    ExIntN& operator=(const ExIntN&) = delete;
    ExIntN(const ExIntN&) = delete;

    #if DEFINED(EXINT_N(TRIGGER_BIT_0_BIT))
        /// #### enum {{ExIntN::Trigger}}
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

    /// #### static [[HardwareType]] getHardwareType()
    static constexpr HardwareType getHardwareType() {
        return HardwareType::exInt;
    }

    #if DEFINED(EXINT_N(ENABLE_BIT_0_BIT))
        /// #### static void intEnable(bool e)
        static force_inline void intEnable(bool e) {
            setBit_(REG(EXINT_N(ENABLE_BIT_0_REG)), EXINT_N(ENABLE_BIT_0_BIT), e);
        }
    #endif

    #if DEFINED(EXINT_N(TRIGGER_BIT_0_BIT))
        /// #### static void trigger([[ExIntN::Trigger]] t)
        static force_inline void trigger(Trigger t) {
            setBit_(REG(EXINT_N(TRIGGER_BIT_0_REG)), EXINT_N(TRIGGER_BIT_0_BIT), uint8_t(t) & 0x01);
            setBit_(REG(EXINT_N(TRIGGER_BIT_1_REG)), EXINT_N(TRIGGER_BIT_1_BIT), uint8_t(t) & 0x02);
        }
    #endif

    /// #### static void callback([[callback_t]] callback, void\* data)
    static force_inline void callback(callback_t callback = nullptr, void* data = nullptr) {
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

    #if DEFINED(EXINT_N(INT_FLAG_BIT_0_BIT))
        /// #### static bool intFlag()
        static force_inline bool intFlag() {
            return *REG(EXINT_N(INT_FLAG_BIT_0_REG)) & bv(EXINT_N(INT_FLAG_BIT_0_BIT));
        }
    #endif

    #if DEFINED(EXINT_N(INT_FLAG_BIT_0_BIT))
        /// #### static void intFlagClear()
        static force_inline void intFlagClear() {
            setBit_(REG(EXINT_N(INT_FLAG_BIT_0_REG)), EXINT_N(INT_FLAG_BIT_0_BIT), true);
        }
    #endif
};

ISR(EXINT_N(INT_VECTOR)) {
    ExIntN::callback();
}

} // nbos::hw

//--------------------------------------------------------

    #endif

    #include "exint.hpp"
#else
    #define NBOS_EXINT_HPP
#endif

#undef N
#undef ExIntN
#undef EXINT_N

#endif
