/// [[Index]]

/// # {{Pin Change Interrupts}}

/// ```c++
/// const auto f = [](void*) {
///     nbos::hw::PortB::Pin5::toggle();
/// };
///
/// atomic([]() {
///     nbos::hw::PcInt1::mask(0x0F);
///     nbos::hw::PcInt1::callback((callback_t)f);
///     nbos::hw::PcInt1::intEnable(true);
/// });
/// ```

#ifndef NBOS_PCINT_HPP

#include "isr.hpp"
#include "chip.hpp"
#include "hardwaretype.hpp"
#include "macros.hpp"
#include "system.hpp"

#include "loopi"

#ifdef _I
    #define N _I
    #define PcIntN CAT(PcInt, N)
    #define PCINT_N(A) CAT(CHIP_PCINT_, N, _, A)

    #if CAT(CHIP_PCINT_, N)

//--------------------------------------------------------

namespace nbos::hw {

/// ## Class {{PcIntN}}
struct PcIntN {
    PcIntN() = delete;

    /// #### static [[HardwareType]] getHardwareType()
    static constexpr HardwareType getHardwareType() {
        return HardwareType::pcInt;
    }

    #if DEFINED(PCINT_N(ENABLE_BIT_0_BIT))
        /// #### static void intEnable(bool e)
        static force_inline void intEnable(bool e) {
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

    #if DEFINED(PCINT_N(INT_FLAG_BIT_0_BIT))
        /// #### static bool intFlag()
        static force_inline bool intFlag() {
            return *REG(PCINT_N(INT_FLAG_BIT_0_REG)) & bv(PCINT_N(INT_FLAG_BIT_0_BIT));
        }
    #endif

    #if DEFINED(PCINT_N(INT_FLAG_BIT_0_BIT))
        /// #### static void intFlagClear()
        static force_inline void intFlagClear() {
            setBit_(REG(PCINT_N(INT_FLAG_BIT_0_REG)), PCINT_N(INT_FLAG_BIT_0_BIT), true);
        }
    #endif
};

ISR(PCINT_N(INT_VECTOR)) {
    PcIntN::callback();
}

} // nbos::hw

//--------------------------------------------------------

    #endif

    #undef N
    #undef PcIntN
    #undef PCINT_N

    #include "pcint.hpp"
#else
    #define NBOS_PCINT_HPP
#endif

#endif
