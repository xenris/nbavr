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
#include "callback.hpp"

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
        enum class Trigger {
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
        /// #### static void intEnable(Bool e)
        static force_inline void intEnable(Bool e) {
            setBit_(REG(EXINT_N(ENABLE_BIT_0_REG)), EXINT_N(ENABLE_BIT_0_BIT), e);
        }
    #endif

    #if DEFINED(EXINT_N(TRIGGER_BIT_0_BIT))
        /// #### static void trigger([[ExIntN::Trigger]] t)
        static force_inline void trigger(Trigger t) {
            setBit_(REG(EXINT_N(TRIGGER_BIT_0_REG)), EXINT_N(TRIGGER_BIT_0_BIT), Int(t) & 0x01);
            setBit_(REG(EXINT_N(TRIGGER_BIT_1_REG)), EXINT_N(TRIGGER_BIT_1_BIT), Int(t) & 0x02);
        }
    #endif

    /// #### static void setCallback([[Callback]]<T\> function, T\* data)
    template <class T>
    static force_inline void setCallback(Callback<T> function, T* data = nullptr) {
        callback((Callback<void>)function, data);
    }

    /// #### static void callCallback()
    static force_inline void callCallback() {
        callback();
    }

    #if DEFINED(EXINT_N(INT_FLAG_BIT_0_BIT))
        /// #### static Bool intFlag()
        static force_inline Bool intFlag() {
            return Bool(*REG(EXINT_N(INT_FLAG_BIT_0_REG)) & bv(EXINT_N(INT_FLAG_BIT_0_BIT)));
        }
    #endif

    #if DEFINED(EXINT_N(INT_FLAG_BIT_0_BIT))
        /// #### static void intFlagClear()
        static force_inline void intFlagClear() {
            setBit_(REG(EXINT_N(INT_FLAG_BIT_0_REG)), EXINT_N(INT_FLAG_BIT_0_BIT), true);
        }
    #endif

private:

    static force_inline void callback(Callback<void> function = nullptr, void* data = nullptr) {
        static Callback<void> f = nullptr;
        static void* d = nullptr;

        if(function == nullptr) {
            if(f != nullptr) {
                f(d);
            }
        } else {
            f = function;
            d = data;
        }
    }
};

ISR(EXINT_N(INT_VECTOR)) {
    ExIntN::callCallback();
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
