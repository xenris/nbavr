/// [[Index]]

/// # {{Clock}}

/// ```c++
/// ```

#ifndef NBLIB_CLOCK_HPP
#define NBLIB_CLOCK_HPP

#include "chip.hpp"
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

    // #if REG_ADDR(CLOCK(SOURCE_BIT_0_REG))
    #if REG_ADDR(CLOCK(SOURCE_REG))
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

    // #if REG_ADDR(CLOCK(PRESCALER_BIT_0_REG))
    #if REG_ADDR(CLOCK(PRESCALER_REG))
        /// #### enum {{Clock::Prescaler}}
        /// * div2
        /// * div4
        /// * div8
        /// * div16
        /// * div32
        /// * div64
        /// * div6
        /// * div10
        /// * div12
        /// * div24
        /// * div48
        enum class Prescaler {
            #if DEFINED(CLOCK(PRESCALER_2_ID))
                div2 = CLOCK(PRESCALER_2_ID),
            #endif

            #if DEFINED(CLOCK(PRESCALER_4_ID))
                div4 = CLOCK(PRESCALER_4_ID),
            #endif

            #if DEFINED(CLOCK(PRESCALER_8_ID))
                div8 = CLOCK(PRESCALER_8_ID),
            #endif

            #if DEFINED(CLOCK(PRESCALER_16_ID))
                div16 = CLOCK(PRESCALER_16_ID),
            #endif

            #if DEFINED(CLOCK(PRESCALER_32_ID))
                div32 = CLOCK(PRESCALER_32_ID),
            #endif

            #if DEFINED(CLOCK(PRESCALER_64_ID))
                div64 = CLOCK(PRESCALER_64_ID),
            #endif

            #if DEFINED(CLOCK(PRESCALER_6_ID))
                div6 = CLOCK(PRESCALER_6_ID),
            #endif

            #if DEFINED(CLOCK(PRESCALER_10_ID))
                div10 = CLOCK(PRESCALER_10_ID),
            #endif

            #if DEFINED(CLOCK(PRESCALER_12_ID))
                div12 = CLOCK(PRESCALER_12_ID),
            #endif

            #if DEFINED(CLOCK(PRESCALER_24_ID))
                div24 = CLOCK(PRESCALER_24_ID),
            #endif

            #if DEFINED(CLOCK(PRESCALER_48_ID))
                div48 = CLOCK(PRESCALER_48_ID),
            #endif
        };
    #endif

    /// #### static [[HardwareType]] getHardwareType()
    static constexpr HardwareType getHardwareType() {
        return HardwareType::clock;
    }

    #if REG_ADDR(CLOCK(SOURCE_REG))
        /// #### static void source([[Clock::Source]])
        static force_inline void source(Source s) {
            using T = REG_TYPE(CLOCK(SOURCE_REG));

            T r = T((getReg(REG(CLOCK(SOURCE_REG))) & ~CLOCK(SOURCE_MASK)) | T(s));

            #if DEFINED(CLOCK(SOURCE_CONFIG_CHANGE_PROTECTION))
                System::allowConfigChange(System::ConfigChangeProtection::ioReg);
            #endif

            setReg(REG(CLOCK(SOURCE_REG)), r);
        }
    #endif

    #if REG_DEFINED(CLOCK(PRESCALER_REG))
        /// #### static void prescaler([[Clock::Prescaler]])
        static force_inline void prescaler(Prescaler p) {
            using T = REG_TYPE(CLOCK(PRESCALER_REG));

            #if DEFINED(CLOCK(PRESCALER_CONFIG_CHANGE_PROTECTION))
                System::setBits(REG(CLOCK(PRESCALER_REG)), T(CLOCK(PRESCALER_MASK)), T(p), System::ConfigChangeProtection::ioReg);
            #else
                System::setBits(REG(CLOCK(PRESCALER_REG)), T(CLOCK(PRESCALER_MASK)), T(p));
            #endif
        }
    #endif

    #if REG_ADDR(CLOCK(PRESCALER_ENABLE_REG))
        /// #### static void prescalerEnable(bool)
        static force_inline void prescalerEnable(bool e) {
            #if DEFINED(CLOCK(PRESCALER_CONFIG_CHANGE_PROTECTION))
                System::setBit(REG(CLOCK(PRESCALER_ENABLE_REG)), CLOCK(PRESCALER_ENABLE_BIT), e, System::ConfigChangeProtection::ioReg);
            #else
                System::setBit(REG(CLOCK(PRESCALER_ENABLE_REG)), CLOCK(PRESCALER_ENABLE_BIT), e);
            #endif
        }
    #endif

    #if REG_ADDR(CLOCK(LOCK_REG))
        /// #### static void lock()
        static force_inline void lock() {
            #if DEFINED(CLOCK(LOCK_CONFIG_CHANGE_PROTECTION))
                System::setBit(REG(CLOCK(LOCK_REG)), CLOCK(LOCK_BIT), true, System::ConfigChangeProtection::ioReg);
            #else
                System::setBit(REG(CLOCK(LOCK_REG)), CLOCK(LOCK_BIT), true);
            #endif
        }
    #endif
};

#ifdef TEST

// TEST(Clock, getHardwareType) {
//     ASSERT_EQ(Clock::getHardwareType(), HardwareType::clock);
// }

// #if DEFINED(USART_N(MODE_BIT_0_BIT))
//     TEST(Clock, mode) {
//         TEST_REG_WRITE(Clock::mode(Clock::Mode::asynchronous));
//         TEST_REG_WRITE(Clock::mode(Clock::Mode::synchronous));

//         #if USART_N(MODE_MASTER_SPI_ID)
//             TEST_REG_WRITE(Clock::mode(Clock::Mode::masterSpi));
//         #endif
//     }
// #endif

// #if REG_ADDR(USART_N(BAUD_RATE_REG))
//     TEST(Clock, baud) {
//         TEST_REG_WRITE(Clock::baud(0x1234));
//     }
// #endif

#endif // TEST

} // nblib::hw

#undef CLOCK

#endif
