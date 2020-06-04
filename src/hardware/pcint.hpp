/// [[Index]]

/// # {{Pin Change Interrupts}}

/// ```c++
/// Callback<void> f = [](void*) {
///     nblib::hw::PortB::Pin5::toggle();
/// };
///
/// atomic {
///     nblib::hw::PcInt0::mask(0x0F);
///     nblib::hw::PcInt0::setCallback(f);
///     nblib::hw::PcInt0::intEnable(true);
/// }
/// ```

#ifndef NBLIB_PCINT_HPP

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

namespace nblib::hw {

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
};

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

} // nblib::hw

//--------------------------------------------------------

    #endif

    #undef N
    #undef PcIntN
    #undef PCINT_N

    #include "pcint.hpp"
#else
    #define NBLIB_PCINT_HPP
#endif

#endif
