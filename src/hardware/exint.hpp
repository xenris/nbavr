/// [[Index]]

/// # {{External Interrupts}}

/// ```c++
/// Callback<void> f = [](void*) {
///     nblib::hw::PortB::Pin5::toggle();
/// };
///
/// atomic {
///     nblib::hw::ExInt0::trigger(nblib::hw::ExInt0::Trigger::rising);
///     nblib::hw::ExInt0::setCallback(f);
///     nblib::hw::ExInt0::intEnable(true);
/// }
/// ```

#ifndef NBLIB_EXINT_HPP

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
    #if DEFINED(CAT(CHIP_EXINT_, N))

//--------------------------------------------------------

namespace nblib::hw {

/// ## class {{ExIntN}}
struct ExIntN {
    ExIntN() = delete;
    ExIntN& operator=(const ExIntN&) = delete;
    ExIntN(const ExIntN&) = delete;

    #if EXINT_N(TRIGGER_MASK)
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

    #if REG_DEFINED(EXINT_N(ENABLE_REG))
        /// #### static void intEnable(bool e)
        static force_inline void intEnable(bool e) {
            EXINT_N(ENABLE_REG)::setBit(EXINT_N(ENABLE_BIT), e);
        }
    #endif

    #if REG_DEFINED(EXINT_N(TRIGGER_REG))
        /// #### static void trigger([[ExIntN::Trigger]] t)
        static force_inline void trigger(Trigger t) {
            EXINT_N(TRIGGER_REG)::setBits(EXINT_N(TRIGGER_MASK), t);
        }
    #endif

    #if REG_DEFINED(EXINT_N(INT_FLAG_REG))
        /// #### static bool intFlag()
        static force_inline bool intFlag() {
            return EXINT_N(INT_FLAG_REG)::getBit(EXINT_N(INT_FLAG_BIT));
        }

        /// #### static void intFlagClear()
        static force_inline void intFlagClear() {
            EXINT_N(INT_FLAG_REG)::setBit(EXINT_N(INT_FLAG_BIT), true);
        }
    #endif
};

#ifdef TEST

TEST(ExIntN, getHardwareType) {
    ASSERT_EQ(ExIntN::getHardwareType(), HardwareType::exInt);
}

#if REG_DEFINED(EXINT_N(ENABLE_REG))
    TEST(ExIntN, intEnable) {
        TEST_REG_WRITE(ExIntN::intEnable(true));
        TEST_REG_WRITE(ExIntN::intEnable(false));
    }
#endif

#if REG_DEFINED(EXINT_N(TRIGGER_REG))
    TEST(ExIntN, trigger) {
        TEST_REG_WRITE(ExIntN::trigger(ExIntN::Trigger::low));
        TEST_REG_WRITE(ExIntN::trigger(ExIntN::Trigger::change));
        TEST_REG_WRITE(ExIntN::trigger(ExIntN::Trigger::falling));
        TEST_REG_WRITE(ExIntN::trigger(ExIntN::Trigger::rising));
    }
#endif

#if REG_DEFINED(EXINT_N(INT_FLAG_REG))
    TEST(ExIntN, intFlag) {
        TEST_REG_READ_WRITE(ExIntN::intFlag());
    }

    TEST(ExIntN, intFlagClear) {
        TEST_REG_WRITE(ExIntN::intFlagClear());
    }
#endif

#endif

} // nblib::hw

//--------------------------------------------------------

    #endif

    #include "exint.hpp"
#else
    #define NBLIB_EXINT_HPP
#endif

#undef N
#undef ExIntN
#undef EXINT_N

#endif
