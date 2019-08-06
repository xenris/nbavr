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
    #if CAT(CHIP_EXINT_, N)

//--------------------------------------------------------

namespace nblib::hw {

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
        /// #### static void intEnable(bool e)
        static force_inline void intEnable(bool e) {
            setBit_(REG(EXINT_N(ENABLE_BIT_0_REG)), EXINT_N(ENABLE_BIT_0_BIT), e);
        }
    #endif

    #if DEFINED(EXINT_N(TRIGGER_BIT_0_BIT))
        /// #### static void trigger([[ExIntN::Trigger]] t)
        static force_inline void trigger(Trigger t) {
            setBit_(REG(EXINT_N(TRIGGER_BIT_0_REG)), EXINT_N(TRIGGER_BIT_0_BIT), int(t) & 0x01);
            setBit_(REG(EXINT_N(TRIGGER_BIT_1_REG)), EXINT_N(TRIGGER_BIT_1_BIT), int(t) & 0x02);
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
        /// #### static bool intFlag()
        static force_inline bool intFlag() {
            return getBit_(REG(EXINT_N(INT_FLAG_BIT_0_REG)), EXINT_N(INT_FLAG_BIT_0_BIT));
        }
    #endif

    #if DEFINED(EXINT_N(INT_FLAG_BIT_0_BIT))
        /// #### static void intFlagClear()
        static force_inline void intFlagClear() {
            clearFlagBit(REG(EXINT_N(INT_FLAG_BIT_0_REG)), EXINT_N(INT_FLAG_BIT_0_BIT));
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

#ifdef TEST

TEST(ExIntN, getHardwareType) {
    ASSERT_EQ(ExIntN::getHardwareType(), HardwareType::exInt);
}

TEST(ExIntN, intEnable) {
    TEST_REG_WRITE(ExIntN::intEnable(true));
    TEST_REG_WRITE(ExIntN::intEnable(false));
}

TEST(ExIntN, trigger) {
    TEST_REG_WRITE(ExIntN::trigger(ExIntN::Trigger::low));
    TEST_REG_WRITE(ExIntN::trigger(ExIntN::Trigger::change));
    TEST_REG_WRITE(ExIntN::trigger(ExIntN::Trigger::falling));
    TEST_REG_WRITE(ExIntN::trigger(ExIntN::Trigger::rising));
}

TEST(ExIntN, intFlag) {
    TEST_REG_READ_WRITE(ExIntN::intFlag());
}

TEST(ExIntN, intFlagClear) {
    TEST_REG_WRITE(ExIntN::intFlagClear());
}

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
