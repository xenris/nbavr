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

    #if CLOCK(SOURCE_MASK)
        /// #### enum {{Clock::Source}}
        /// * internal16M20M
        /// * internal32K
        /// * external
        enum class Source {
            #if DEFINED(CLOCK(SOURCE_16M20M_ID))
                internal16M20M = CLOCK(SOURCE_16M20M_ID),
            #endif

            #if DEFINED(CLOCK(SOURCE_32K_ID))
                internal32K = CLOCK(SOURCE_32K_ID),
            #endif

            #if DEFINED(CLOCK(SOURCE_EXTERNAL_ID))
                external = CLOCK(SOURCE_EXTERNAL_ID),
            #endif
        };
    #endif

    #if CLOCK(PRESCALER_MASK)
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

    /// #### static [[HardwareType]] getHardwareType()
    static constexpr HardwareType getHardwareType() {
        return HardwareType::clock;
    }

    #if CLOCK(SOURCE_MASK)
        /// #### static void source([[Clock::Source]])
        static force_inline void source(Source s) {
            CLOCK(SOURCE_REG)::setBits(CLOCK(SOURCE_MASK), s);
        }
    #endif

    #if CLOCK(PRESCALER_MASK)
        /// #### static void prescaler([[Clock::Prescaler]])
        static force_inline void prescaler(Prescaler p) {
            CLOCK(PRESCALER_REG)::setBits(CLOCK(PRESCALER_MASK), p);
        }
    #endif

    #if DEFINED(CLOCK(PRESCALER_ENABLE_BIT))
        /// #### static void prescalerEnable(bool)
        static force_inline void prescalerEnable(bool e) {
            CLOCK(PRESCALER_ENABLE_REG)::setBit(CLOCK(PRESCALER_ENABLE_BIT), e);
        }
    #endif

    #if DEFINED(CLOCK(LOCK_BIT))
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
