/// [[Index]]

/// # {{Pin Change Interrupts}}

/// ```c++
/// Callback<void> f = [](void*) {
///     nbos::hw::PortB::Pin5::toggle();
/// };
///
/// atomic {
///     nbos::hw::PcInt0::mask(0x0F);
///     nbos::hw::PcInt0::setCallback(f);
///     nbos::hw::PcInt0::intEnable(true);
/// }
/// ```

#ifndef NBOS_PCINT_HPP

#include "isr.hpp"
#include "chip.hpp"
#include "hardwaretype.hpp"
#include "macros.hpp"
#include "system.hpp"
#include "callback.hpp"

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
            setReg_(REG(PCINT_N(MASK_REG)), m);
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

    #if DEFINED(PCINT_N(INT_FLAG_BIT_0_BIT))
        /// #### static bool intFlag()
        static force_inline bool intFlag() {
            return getBit_(REG(PCINT_N(INT_FLAG_BIT_0_REG)), PCINT_N(INT_FLAG_BIT_0_BIT));
        }
    #endif

    #if DEFINED(PCINT_N(INT_FLAG_BIT_0_BIT))
        /// #### static void intFlagClear()
        static force_inline void intFlagClear() {
            clearFlagBit(REG(PCINT_N(INT_FLAG_BIT_0_REG)), PCINT_N(INT_FLAG_BIT_0_BIT));
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

ISR(PCINT_N(INT_VECTOR)) {
    PcIntN::callCallback();
}

#ifdef TEST

TEST(PcIntN, getHardwareType) {
    ASSERT_EQ(PcIntN::getHardwareType(), HardwareType::pcInt);
}

TEST(PcIntN, intEnable) {
    TEST_REG_WRITE(PcIntN::intEnable(true));
    TEST_REG_WRITE(PcIntN::intEnable(false));
}

TEST(PcIntN, mask) {
    TEST_REG_WRITE(PcIntN::mask(0x12));
}

TEST(PcIntN, intFlag) {
    TEST_REG_READ_WRITE(PcIntN::intFlag());
}

TEST(PcIntN, intFlagClear) {
    TEST_REG_WRITE(PcIntN::intFlagClear());
}

#endif

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
