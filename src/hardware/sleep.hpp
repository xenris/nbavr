/// [[Index]]

/// # {{System Sleep}}

/// ```c++
/// using Sleep = nblib::hw::Sleep;
///
/// Sleep::mode(Sleep::Mode::idle);
/// Sleep::enable(true);
///
/// Sleep::sleep();
/// ```

#ifndef NBLIB_SLEEP_HPP
#define NBLIB_SLEEP_HPP

#include "chip.hpp"
#include "hardwaretype.hpp"
#include "macros.hpp"
#include "system.hpp"

namespace nblib::hw {

/// ## class {{Sleep}}
struct Sleep {
    Sleep() = delete;
    Sleep& operator=(const Sleep&) = delete;
    Sleep(const Sleep&) = delete;

    /// #### enum {{Sleep::Mode}}
    /// * idle
    /// * adcNoiseReduction
    /// * powerDown
    /// * powerSave
    /// * standby
    /// * extendedStandby
    #if CHIP_SLEEP_MODE_MASK
        enum class Mode {
            #if DEFINED(CHIP_SLEEP_MODE_IDLE_ID)
                idle = CHIP_SLEEP_MODE_IDLE_ID,
            #endif

            #if DEFINED(CHIP_SLEEP_MODE_ADC_NOISE_REDUCTION_ID)
                adcNoiseReduction = CHIP_SLEEP_MODE_ADC_NOISE_REDUCTION_ID,
            #endif

            #if DEFINED(CHIP_SLEEP_MODE_POWER_DOWN_ID)
                powerDown = CHIP_SLEEP_MODE_POWER_DOWN_ID,
            #endif

            #if DEFINED(CHIP_SLEEP_MODE_POWER_SAVE_ID)
                powerSave = CHIP_SLEEP_MODE_POWER_SAVE_ID,
            #endif

            #if DEFINED(CHIP_SLEEP_MODE_STANDBY_ID)
                standby = CHIP_SLEEP_MODE_STANDBY_ID,
            #endif

            #if DEFINED(CHIP_SLEEP_MODE_EXTENDED_STANDBY_ID)
                extendedStandby = CHIP_SLEEP_MODE_EXTENDED_STANDBY_ID,
            #endif
        };
    #endif

    /// #### static [[HardwareType]] getHardwareType()
    static constexpr HardwareType getHardwareType() {
        return HardwareType::sleep;
    }

    /// #### static void mode([[Sleep::Mode]] m)
    /// Set the level of sleep that happens when sleep() is called.
    #if CHIP_SLEEP_MODE_MASK
        static force_inline void mode(Mode m) {
            CHIP_SLEEP_MODE_REG::setBits(CHIP_SLEEP_MODE_MASK, m);
        }
    #endif

    /// #### static void enable(bool b)
    /// Set this to true to let the CPU sleep when sleep() is called.
    #if DEFINED(CHIP_SLEEP_ENABLE_BIT)
        static force_inline void enable(bool b) {
            CHIP_SLEEP_ENABLE_REG::setBit(CHIP_SLEEP_ENABLE_BIT, b);
        }
    #endif

    /// #### static bool isEnabled()
    #if DEFINED(CHIP_SLEEP_ENABLE_BIT)
        static force_inline bool isEnabled() {
            return CHIP_SLEEP_ENABLE_REG::getBit(CHIP_SLEEP_ENABLE_BIT);
        }
    #endif

    /// #### static void sleep()
    /// Put the CPU to sleep.
    static force_inline void sleep() {
        #if defined(__AVR__)
            asm volatile("sleep" ::: "memory");
        #elif defined(__ARM__)
            // TODO
        #elif defined(TEST)
            // Ignore this function.
        #else
            #warning sleep() not defined for this architecture.
        #endif
    }
};

#ifdef TEST

TEST(Sleep, getHardwareType) {
    ASSERT_EQ(Sleep::getHardwareType(), HardwareType::sleep);
}

#if DEFINED(CHIP_SLEEP_ENABLE_BIT)
    TEST(Sleep, enable) {
        TEST_REG_WRITE(Sleep::enable(true));
        TEST_REG_WRITE(Sleep::enable(false));

        TEST_REG_READ_WRITE(Sleep::isEnabled());
    }
#endif

#if CHIP_SLEEP_MODE_MASK
    TEST(Sleep, mode) {
        #if DEFINED(CHIP_SLEEP_MODE_IDLE_ID)
            TEST_REG_WRITE(Sleep::mode(Sleep::Mode::idle));
        #endif

        #if DEFINED(CHIP_SLEEP_MODE_ADC_NOISE_REDUCTION_ID)
            TEST_REG_WRITE(Sleep::mode(Sleep::Mode::adcNoiseReduction));
        #endif

        #if DEFINED(CHIP_SLEEP_MODE_POWER_DOWN_ID)
            TEST_REG_WRITE(Sleep::mode(Sleep::Mode::powerDown));
        #endif

        #if DEFINED(CHIP_SLEEP_MODE_POWER_SAVE_ID)
            TEST_REG_WRITE(Sleep::mode(Sleep::Mode::powerSave));
        #endif

        #if DEFINED(CHIP_SLEEP_MODE_STANDBY_ID)
            TEST_REG_WRITE(Sleep::mode(Sleep::Mode::standby));
        #endif

        #if DEFINED(CHIP_SLEEP_MODE_EXTENDED_STANDBY_ID)
            TEST_REG_WRITE(Sleep::mode(Sleep::Mode::extendedStandby));
        #endif
    }
#endif

#endif // TEST

} // nblib::hw

#endif
