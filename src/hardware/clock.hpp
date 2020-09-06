/// [[Index]]

/// # {{Clock}}

/// ```c++
/// ```

#ifndef NBLIB_CLOCK_HPP
#define NBLIB_CLOCK_HPP

#include "chip.hpp"
#include "register.hpp"
#include "hardwaretype.hpp"
#include "macros.hpp"
#include "system.hpp"

#define CLOCK(A) CAT(CHIP_CLOCK_, A)

namespace nblib::hw {

/// ## class Clock
struct Clock {
    Clock() = delete;
    Clock& operator=(const Clock&) = delete;
    Clock(const Clock&) = delete;

    #if REG_DEFINED(CLOCK(SOURCE_REG))
        /// #### enum {{Clock::Source}}
        /// * internal16M20M
        /// * internal32K
        /// * external
        enum class Source {
            #if DEFINED(CLOCK(SOURCE_16M20M_ID))
                internal16M20M = CLOCK(SOURCE_16M20M_ID),
            #endif
            #if DEFINED(CLOCK(SOURCE_HIGH_SPEED_INTERNAL_ID))
                highSpeedInternal = CLOCK(SOURCE_HIGH_SPEED_INTERNAL_ID),
            #endif
            #if DEFINED(CLOCK(SOURCE_HIGH_SPEED_EXTERNAL_ID))
                highSpeedExternal = CLOCK(SOURCE_HIGH_SPEED_EXTERNAL_ID),
            #endif
            #if DEFINED(CLOCK(SOURCE_PLL1_ID))
                pll1 = CLOCK(SOURCE_PLL1_ID),
            #endif
            #if DEFINED(CLOCK(SOURCE_32K_ID))
                internal32K = CLOCK(SOURCE_32K_ID),
            #endif
            #if DEFINED(CLOCK(SOURCE_EXTERNAL_ID))
                external = CLOCK(SOURCE_EXTERNAL_ID),
            #endif
        };
    #endif

    #if REG_DEFINED(CLOCK(PRESCALER_REG))
        /// #### enum {{Clock::Prescaler}}
        /// * div2
        /// * div4
        /// * div6
        /// * div8
        /// * div10
        /// * div12
        /// * div16
        /// * div24
        /// * div32
        /// * div48
        /// * div64
        enum class Prescaler {
            #if DEFINED(CLOCK(PRESCALER_2_ID))
                div2 = CLOCK(PRESCALER_2_ID),
            #endif

            #if DEFINED(CLOCK(PRESCALER_4_ID))
                div4 = CLOCK(PRESCALER_4_ID),
            #endif

            #if DEFINED(CLOCK(PRESCALER_6_ID))
                div6 = CLOCK(PRESCALER_6_ID),
            #endif

            #if DEFINED(CLOCK(PRESCALER_8_ID))
                div8 = CLOCK(PRESCALER_8_ID),
            #endif

            #if DEFINED(CLOCK(PRESCALER_10_ID))
                div10 = CLOCK(PRESCALER_10_ID),
            #endif

            #if DEFINED(CLOCK(PRESCALER_12_ID))
                div12 = CLOCK(PRESCALER_12_ID),
            #endif

            #if DEFINED(CLOCK(PRESCALER_16_ID))
                div16 = CLOCK(PRESCALER_16_ID),
            #endif

            #if DEFINED(CLOCK(PRESCALER_24_ID))
                div24 = CLOCK(PRESCALER_24_ID),
            #endif

            #if DEFINED(CLOCK(PRESCALER_32_ID))
                div32 = CLOCK(PRESCALER_32_ID),
            #endif

            #if DEFINED(CLOCK(PRESCALER_48_ID))
                div48 = CLOCK(PRESCALER_48_ID),
            #endif

            #if DEFINED(CLOCK(PRESCALER_64_ID))
                div64 = CLOCK(PRESCALER_64_ID),
            #endif
        };
    #endif

    #if REG_DEFINED(CLOCK(PLL_1_PRESCALER_REG))
        enum class Pll1Prescaler {
            #if DEFINED(CLOCK(PLL_1_PRESCALER_1_ID))
                div1 = CLOCK(PLL_1_PRESCALER_1_ID),
            #endif
            #if DEFINED(CLOCK(PLL_1_PRESCALER_2_ID))
                div2 = CLOCK(PLL_1_PRESCALER_2_ID),
            #endif
            #if DEFINED(CLOCK(PLL_1_PRESCALER_3_ID))
                div3 = CLOCK(PLL_1_PRESCALER_3_ID),
            #endif
            #if DEFINED(CLOCK(PLL_1_PRESCALER_4_ID))
                div4 = CLOCK(PLL_1_PRESCALER_4_ID),
            #endif
            #if DEFINED(CLOCK(PLL_1_PRESCALER_5_ID))
                div5 = CLOCK(PLL_1_PRESCALER_5_ID),
            #endif
            #if DEFINED(CLOCK(PLL_1_PRESCALER_6_ID))
                div6 = CLOCK(PLL_1_PRESCALER_6_ID),
            #endif
            #if DEFINED(CLOCK(PLL_1_PRESCALER_7_ID))
                div7 = CLOCK(PLL_1_PRESCALER_7_ID),
            #endif
            #if DEFINED(CLOCK(PLL_1_PRESCALER_8_ID))
                div8 = CLOCK(PLL_1_PRESCALER_8_ID),
            #endif
            #if DEFINED(CLOCK(PLL_1_PRESCALER_9_ID))
                div9 = CLOCK(PLL_1_PRESCALER_9_ID),
            #endif
            #if DEFINED(CLOCK(PLL_1_PRESCALER_10_ID))
                div10 = CLOCK(PLL_1_PRESCALER_10_ID),
            #endif
            #if DEFINED(CLOCK(PLL_1_PRESCALER_11_ID))
                div11 = CLOCK(PLL_1_PRESCALER_11_ID),
            #endif
            #if DEFINED(CLOCK(PLL_1_PRESCALER_12_ID))
                div12 = CLOCK(PLL_1_PRESCALER_12_ID),
            #endif
            #if DEFINED(CLOCK(PLL_1_PRESCALER_16_ID))
                div16 = CLOCK(PLL_1_PRESCALER_16_ID),
            #endif
        };
    #endif

    /// #### enum {{Clock::PllNMultiplier}}
    /// * x8
    /// * x9
    /// * x10
    /// * x11
    /// * x12
    /// * x13
    /// * x14
    /// * x16
    /// * x20

    #if REG_DEFINED(CLOCK(PLL_1_MULTIPLIER_REG))
        enum class Pll1Multiplier {
            #if DEFINED(CLOCK(PLL_1_MULTIPLIER_4_ID))
                x4 = CLOCK(PLL_1_MULTIPLIER_4_ID),
            #endif
            #if DEFINED(CLOCK(PLL_1_MULTIPLIER_5_ID))
                x5 = CLOCK(PLL_1_MULTIPLIER_5_ID),
            #endif
            #if DEFINED(CLOCK(PLL_1_MULTIPLIER_6_ID))
                x6 = CLOCK(PLL_1_MULTIPLIER_6_ID),
            #endif
            #if DEFINED(CLOCK(PLL_1_MULTIPLIER_6_5_ID))
                x6_5 = CLOCK(PLL_1_MULTIPLIER_6_5_ID),
            #endif
            #if DEFINED(CLOCK(PLL_1_MULTIPLIER_7_ID))
                x7 = CLOCK(PLL_1_MULTIPLIER_7_ID),
            #endif
            #if DEFINED(CLOCK(PLL_1_MULTIPLIER_8_ID))
                x8 = CLOCK(PLL_1_MULTIPLIER_8_ID),
            #endif
            #if DEFINED(CLOCK(PLL_1_MULTIPLIER_9_ID))
                x9 = CLOCK(PLL_1_MULTIPLIER_9_ID),
            #endif
            #if DEFINED(CLOCK(PLL_1_MULTIPLIER_10_ID))
                x10 = CLOCK(PLL_1_MULTIPLIER_10_ID),
            #endif
            #if DEFINED(CLOCK(PLL_1_MULTIPLIER_11_ID))
                x11 = CLOCK(PLL_1_MULTIPLIER_11_ID),
            #endif
            #if DEFINED(CLOCK(PLL_1_MULTIPLIER_12_ID))
                x12 = CLOCK(PLL_1_MULTIPLIER_12_ID),
            #endif
            #if DEFINED(CLOCK(PLL_1_MULTIPLIER_13_ID))
                x13 = CLOCK(PLL_1_MULTIPLIER_13_ID),
            #endif
            #if DEFINED(CLOCK(PLL_1_MULTIPLIER_14_ID))
                x14 = CLOCK(PLL_1_MULTIPLIER_14_ID),
            #endif
            #if DEFINED(CLOCK(PLL_1_MULTIPLIER_16_ID))
                x16 = CLOCK(PLL_1_MULTIPLIER_16_ID),
            #endif
            #if DEFINED(CLOCK(PLL_1_MULTIPLIER_20_ID))
                x20 = CLOCK(PLL_1_MULTIPLIER_20_ID),
            #endif
        };
    #endif

    #if REG_DEFINED(CLOCK(PLL_2_MULTIPLIER_REG))
        enum class Pll2Multiplier {
            #if DEFINED(CLOCK(PLL_2_MULTIPLIER_8_ID))
                x8 = CLOCK(PLL_2_MULTIPLIER_8_ID),
            #endif
            #if DEFINED(CLOCK(PLL_2_MULTIPLIER_9_ID))
                x9 = CLOCK(PLL_2_MULTIPLIER_9_ID),
            #endif
            #if DEFINED(CLOCK(PLL_2_MULTIPLIER_10_ID))
                x10 = CLOCK(PLL_2_MULTIPLIER_10_ID),
            #endif
            #if DEFINED(CLOCK(PLL_2_MULTIPLIER_11_ID))
                x11 = CLOCK(PLL_2_MULTIPLIER_11_ID),
            #endif
            #if DEFINED(CLOCK(PLL_2_MULTIPLIER_12_ID))
                x12 = CLOCK(PLL_2_MULTIPLIER_12_ID),
            #endif
            #if DEFINED(CLOCK(PLL_2_MULTIPLIER_13_ID))
                x13 = CLOCK(PLL_2_MULTIPLIER_13_ID),
            #endif
            #if DEFINED(CLOCK(PLL_2_MULTIPLIER_14_ID))
                x14 = CLOCK(PLL_2_MULTIPLIER_14_ID),
            #endif
            #if DEFINED(CLOCK(PLL_2_MULTIPLIER_16_ID))
                x16 = CLOCK(PLL_2_MULTIPLIER_16_ID),
            #endif
            #if DEFINED(CLOCK(PLL_2_MULTIPLIER_20_ID))
                x20 = CLOCK(PLL_2_MULTIPLIER_20_ID),
            #endif
        };
    #endif

    #if REG_DEFINED(CLOCK(PLL_3_MULTIPLIER_REG))
        enum class Pll3Multiplier {
            #if DEFINED(CLOCK(PLL_3_MULTIPLIER_8_ID))
                x8 = CLOCK(PLL_3_MULTIPLIER_8_ID),
            #endif
            #if DEFINED(CLOCK(PLL_3_MULTIPLIER_9_ID))
                x9 = CLOCK(PLL_3_MULTIPLIER_9_ID),
            #endif
            #if DEFINED(CLOCK(PLL_3_MULTIPLIER_10_ID))
                x10 = CLOCK(PLL_3_MULTIPLIER_10_ID),
            #endif
            #if DEFINED(CLOCK(PLL_3_MULTIPLIER_11_ID))
                x11 = CLOCK(PLL_3_MULTIPLIER_11_ID),
            #endif
            #if DEFINED(CLOCK(PLL_3_MULTIPLIER_12_ID))
                x12 = CLOCK(PLL_3_MULTIPLIER_12_ID),
            #endif
            #if DEFINED(CLOCK(PLL_3_MULTIPLIER_13_ID))
                x13 = CLOCK(PLL_3_MULTIPLIER_13_ID),
            #endif
            #if DEFINED(CLOCK(PLL_3_MULTIPLIER_14_ID))
                x14 = CLOCK(PLL_3_MULTIPLIER_14_ID),
            #endif
            #if DEFINED(CLOCK(PLL_3_MULTIPLIER_16_ID))
                x16 = CLOCK(PLL_3_MULTIPLIER_16_ID),
            #endif
            #if DEFINED(CLOCK(PLL_3_MULTIPLIER_20_ID))
                x20 = CLOCK(PLL_3_MULTIPLIER_20_ID),
            #endif
        };
    #endif

    /// #### static [[HardwareType]] getHardwareType()
    static constexpr HardwareType getHardwareType() {
        return HardwareType::clock;
    }

    #if REG_DEFINED(CLOCK(SOURCE_REG))
        /// #### static void source([[Clock::Source]])
        static force_inline void source(Source s) {
            CLOCK(SOURCE_REG)::setBits(CLOCK(SOURCE_MASK), s);
        }
    #endif

    #if REG_DEFINED(CLOCK(PRESCALER_REG))
        /// #### static void prescaler([[Clock::Prescaler]])
        static force_inline void prescaler(Prescaler p) {
            CLOCK(PRESCALER_REG)::setBits(CLOCK(PRESCALER_MASK), p);
        }
    #endif

    #if REG_DEFINED(CLOCK(PLL_1_PRESCALER_REG))
        /// #### static void pll1Prescaler([[Clock::Pll1Prescaler]])
        static force_inline void pll1Prescaler(Pll1Prescaler p) {
            CLOCK(PLL_1_PRESCALER_REG)::setBits(CLOCK(PLL_1_PRESCALER_MASK), p);
        }
    #endif

    #if REG_DEFINED(CLOCK(PRESCALER_ENABLE_REG))
        /// #### static void prescalerEnable(bool)
        static force_inline void prescalerEnable(bool e) {
            CLOCK(PRESCALER_ENABLE_REG)::setBit(CLOCK(PRESCALER_ENABLE_BIT), e);
        }
    #endif

    #if REG_DEFINED(CLOCK(PLL_1_ENABLE_REG))
        /// #### static void pll1Enable(bool)
        static force_inline void pll1Enable(bool e) {
            CLOCK(PLL_1_ENABLE_REG)::setBit(CLOCK(PLL_1_ENABLE_BIT), e);
        }
    #endif

    #if REG_DEFINED(CLOCK(PLL_1_READY_REG))
        /// #### static bool pll1Ready()
        static force_inline bool pll1Ready() {
            return CLOCK(PLL_1_READY_REG)::getBit(CLOCK(PLL_1_READY_BIT));
        }
    #endif

    #if REG_DEFINED(CLOCK(EXTERNAL_HIGH_SPEED_CLOCK_ENABLE_REG))
        /// #### static void externalHighSpeedClockEnable(bool)
        static force_inline void externalHighSpeedClockEnable(bool e) {
            CLOCK(EXTERNAL_HIGH_SPEED_CLOCK_ENABLE_REG)::setBit(CLOCK(EXTERNAL_HIGH_SPEED_CLOCK_ENABLE_BIT), e);
        }
    #endif

    #if REG_DEFINED(CLOCK(EXTERNAL_HIGH_SPEED_CLOCK_READY_REG))
        /// #### static bool externalHighSpeedClockReady()
        static force_inline bool externalHighSpeedClockReady() {
            return CLOCK(EXTERNAL_HIGH_SPEED_CLOCK_READY_REG)::getBit(CLOCK(EXTERNAL_HIGH_SPEED_CLOCK_READY_BIT));
        }
    #endif

    #if REG_DEFINED(CLOCK(PLL_1_MULTIPLIER_REG))
        /// #### static void pll1Multiplier([[Clock::Pll1Multiplier]])
        static force_inline void pll1Multiplier(Pll1Multiplier m) {
            CLOCK(PLL_1_MULTIPLIER_REG)::setBits(CLOCK(PLL_1_MULTIPLIER_MASK), m);
        }
    #endif

    #if REG_DEFINED(CLOCK(PLL_2_MULTIPLIER_REG))
        /// #### static void pll2Multiplier([[Clock::Pll2Multiplier]])
        static force_inline void pll2Multiplier(Pll2Multiplier m) {
            CLOCK(PLL_2_MULTIPLIER_REG)::setBits(CLOCK(PLL_2_MULTIPLIER_MASK), m);
        }
    #endif

    #if REG_DEFINED(CLOCK(PLL_3_MULTIPLIER_REG))
        /// #### static void pll3Multiplier([[Clock::Pll3Multiplier]])
        static force_inline void pll3Multiplier(Pll3Multiplier m) {
            CLOCK(PLL_3_MULTIPLIER_REG)::setBits(CLOCK(PLL_3_MULTIPLIER_MASK), m);
        }
    #endif

    #if REG_DEFINED(CLOCK(LOCK_REG))
        /// #### static void lock()
        static force_inline void lock() {
            CLOCK(LOCK_REG)::setBit(CLOCK(LOCK_BIT), true);
        }
    #endif
};

#ifdef TEST

TEST(Clock, getHardwareType) {
    ASSERT_EQ(Clock::getHardwareType(), HardwareType::clock);
}

#if CLOCK(SOURCE_MASK)
    TEST(Clock, source) {
        #if DEFINED(CLOCK(SOURCE_16M20M_ID))
            TEST_REG_WRITE(Clock::source(Clock::Source::internal16M20M));
        #endif

        #if DEFINED(CLOCK(SOURCE_32K_ID))
            TEST_REG_WRITE(Clock::source(Clock::Source::internal32K));
        #endif

        #if DEFINED(CLOCK(SOURCE_EXTERNAL_ID))
            TEST_REG_WRITE(Clock::source(Clock::Source::external));
        #endif
    }
#endif

#if CLOCK(PRESCALER_MASK)
    TEST(Clock, prescaler) {
        #if DEFINED(CLOCK(PRESCALER_2_ID))
            TEST_REG_WRITE(Clock::prescaler(Clock::Prescaler::div2));
        #endif

        #if DEFINED(CLOCK(PRESCALER_4_ID))
            TEST_REG_WRITE(Clock::prescaler(Clock::Prescaler::div4));
        #endif

        #if DEFINED(CLOCK(PRESCALER_6_ID))
            TEST_REG_WRITE(Clock::prescaler(Clock::Prescaler::div6));
        #endif

        #if DEFINED(CLOCK(PRESCALER_8_ID))
            TEST_REG_WRITE(Clock::prescaler(Clock::Prescaler::div8));
        #endif

        #if DEFINED(CLOCK(PRESCALER_10_ID))
            TEST_REG_WRITE(Clock::prescaler(Clock::Prescaler::div10));
        #endif

        #if DEFINED(CLOCK(PRESCALER_12_ID))
            TEST_REG_WRITE(Clock::prescaler(Clock::Prescaler::div12));
        #endif

        #if DEFINED(CLOCK(PRESCALER_16_ID))
            TEST_REG_WRITE(Clock::prescaler(Clock::Prescaler::div16));
        #endif

        #if DEFINED(CLOCK(PRESCALER_24_ID))
            TEST_REG_WRITE(Clock::prescaler(Clock::Prescaler::div24));
        #endif

        #if DEFINED(CLOCK(PRESCALER_32_ID))
            TEST_REG_WRITE(Clock::prescaler(Clock::Prescaler::div32));
        #endif

        #if DEFINED(CLOCK(PRESCALER_48_ID))
            TEST_REG_WRITE(Clock::prescaler(Clock::Prescaler::div48));
        #endif

        #if DEFINED(CLOCK(PRESCALER_64_ID))
            TEST_REG_WRITE(Clock::prescaler(Clock::Prescaler::div64));
        #endif
    }
#endif

#if DEFINED(CLOCK(PRESCALER_ENABLE_BIT))
    TEST(Clock, prescalerEnable) {
        TEST_REG_WRITE(Clock::prescalerEnable(true));
        TEST_REG_WRITE(Clock::prescalerEnable(false));
    }
#endif

#if DEFINED(CLOCK(LOCK_BIT))
    TEST(Clock, lock) {
        TEST_REG_WRITE(Clock::lock());
    }
#endif

#endif // TEST

} // nblib::hw

#undef CLOCK

#endif
