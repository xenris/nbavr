/// [[Index]]

/// # {{Serial Peripheral Interfaces}}

#ifndef NBLIB_SPI_HPP

#include "isr.hpp"
#include "chip.hpp"
#include "hardwaretype.hpp"
#include "macros.hpp"
#include "system.hpp"
#include "callback.hpp"
#include "port.hpp"

#include "loopi"

#ifdef _I
    #define N _I
    #define SpiN CAT(Spi,N)
    #define SPI_N(A) CAT(CHIP_SPI_, N, _, A)

    #if DEFINED(CAT(CHIP_SPI_, N))

//------------------------------------------------------------------

namespace nblib::hw {

/// ## class {{SpiN}}
struct SpiN {
    SpiN() = delete;
    SpiN& operator=(const SpiN&) = delete;
    SpiN(const SpiN&) = delete;

    #if REG_DEFINED(SPI_N(DATA_ORDER_REG))
        /// #### enum {{SpiN::DataOrder}}
        /// * msbFirst
        /// * lsbFirst
        enum class DataOrder {
            msbFirst = SPI_N(DATA_ORDER_MSB_FIRST_ID),
            lsbFirst = SPI_N(DATA_ORDER_LSB_FIRST_ID),
        };
    #endif

    #if REG_DEFINED(SPI_N(MASTER_SLAVE_SELECT_REG))
        /// #### enum {{SpiN::MasterSlave}}
        /// * master
        /// * slave
        enum class MasterSlave {
            master = SPI_N(MASTER_SLAVE_SELECT_MASTER_ID),
            slave = SPI_N(MASTER_SLAVE_SELECT_SLAVE_ID),
        };
    #endif

    #if REG_DEFINED(SPI_N(POLARITY_REG))
        /// #### enum {{SpiN::Polarity}}
        /// * leadingRisingTrailingFalling
        /// * leadingFallingTrailingRising
        enum class Polarity {
            leadingRisingTrailingFalling = SPI_N(POLARITY_LEADING_RISING_TRAILING_FALLING_ID),
            leadingFallingTrailingRising = SPI_N(POLARITY_LEADING_FALLING_TRAILING_RISING_ID),
        };
    #endif

    #if REG_DEFINED(SPI_N(PHASE_REG))
        /// #### enum {{SpiN::Phase}}
        /// * leadingSampleTrailingSetup
        /// * leadingSetupTrailingSample
        enum class Phase {
            leadingSampleTrailingSetup = SPI_N(PHASE_LEADING_SAMPLE_TRAILING_SETUP_ID),
            leadingSetupTrailingSample = SPI_N(PHASE_LEADING_SETUP_TRAILING_SAMPLE_ID),
        };
    #endif

    #if REG_DEFINED(SPI_N(CLOCK_REG))
        /// #### enum {{SpiN::Clock}}
        /// * div2
        /// * div4
        /// * div8
        /// * div16
        /// * div32
        /// * div64
        /// * div128
        enum class Clock {
            #if DEFINED(SPI_N(CLOCK_DIV_2_ID))
                div2 = SPI_N(CLOCK_DIV_2_ID),
            #endif

            #if DEFINED(SPI_N(CLOCK_DIV_4_ID))
                div4 = SPI_N(CLOCK_DIV_4_ID),
            #endif

            #if DEFINED(SPI_N(CLOCK_DIV_8_ID))
                div8 = SPI_N(CLOCK_DIV_8_ID),
            #endif

            #if DEFINED(SPI_N(CLOCK_DIV_16_ID))
                div16 = SPI_N(CLOCK_DIV_16_ID),
            #endif

            #if DEFINED(SPI_N(CLOCK_DIV_32_ID))
                div32 = SPI_N(CLOCK_DIV_32_ID),
            #endif

            #if DEFINED(SPI_N(CLOCK_DIV_64_ID))
                div64 = SPI_N(CLOCK_DIV_64_ID),
            #endif

            #if DEFINED(SPI_N(CLOCK_DIV_128_ID))
                div128 = SPI_N(CLOCK_DIV_128_ID),
            #endif
        };
    #endif

    /// #### static [[HardwareType]] getHardwareType()
    static constexpr HardwareType getHardwareType() {
        return HardwareType::spi;
    }

    #if REG_DEFINED(SPI_N(ENABLE_REG))
        /// #### static void enable(bool b)
        static force_inline void enable(bool b) {
            SPI_N(ENABLE_REG)::setBit(SPI_N(ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(SPI_N(INT_ENABLE_REG))
        /// #### static void intEnable(bool b)
        static force_inline void intEnable(bool b) {
            SPI_N(INT_ENABLE_REG)::setBit(SPI_N(INT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(SPI_N(DATA_ORDER_REG))
        /// #### static void dataOrder([[SpiN::DataOrder]] d)
        static force_inline void dataOrder(DataOrder d) {
            SPI_N(DATA_ORDER_REG)::setBits(SPI_N(DATA_ORDER_MASK), d);
        }
    #endif

    #if REG_DEFINED(SPI_N(MASTER_SLAVE_SELECT_REG))
        /// #### static void masterSlave([[SpiN::MasterSlave]] m)
        static force_inline void masterSlave(MasterSlave m) {
            SPI_N(MASTER_SLAVE_SELECT_REG)::setBits(SPI_N(MASTER_SLAVE_SELECT_MASK), m);
        }
    #endif

    #if REG_DEFINED(SPI_N(POLARITY_REG))
        /// #### static void polarity([[SpiN::Polarity]] p)
        static force_inline void polarity(Polarity p) {
            SPI_N(POLARITY_REG)::setBits(SPI_N(POLARITY_MASK), p);
        }
    #endif

    #if REG_DEFINED(SPI_N(PHASE_REG))
        /// #### static void phase([[SpiN::Phase]] p)
        static force_inline void phase(Phase p) {
            SPI_N(PHASE_REG)::setBits(SPI_N(PHASE_MASK), p);
        }
    #endif

    #if REG_DEFINED(SPI_N(CLOCK_REG))
        /// #### static void clock([[SpiN::Clock]] c)
        static force_inline void clock(Clock c) {
            SPI_N(CLOCK_REG)::setBits(SPI_N(CLOCK_MASK), c);

            #if REG_DEFINED(SPI_N(CLOCK_REG_EXTRA))
                SPI_N(CLOCK_REG_EXTRA)::setBits(SPI_N(CLOCK_MASK_EXTRA), uint(c) >> 8);
            #endif
        }
    #endif

    #if REG_DEFINED(SPI_N(INT_FLAG_REG))
        /// #### static bool intFlag()
        static force_inline bool intFlag() {
            return SPI_N(INT_FLAG_REG)::getBit(SPI_N(INT_FLAG_BIT));
        }
    #endif

    #if REG_DEFINED(SPI_N(COLLISION_FLAG_REG))
        /// #### static bool collisionFlag()
        static force_inline bool collisionFlag() {
            return SPI_N(COLLISION_FLAG_REG)::getBit(SPI_N(COLLISION_FLAG_BIT));
        }
    #endif

    #if REG_DEFINED(SPI_N(DATA_REG))
        /// #### static void data(uint8_t d)
        static force_inline void data(uint8_t d) {
            SPI_N(DATA_REG)::setReg(d);
        }

        /// #### static uint8_t data()
        static force_inline uint8_t data() {
            return SPI_N(DATA_REG)::getReg();
        }
    #endif
};

#ifdef TEST

TEST(SpiN, getHardwareType) {
    ASSERT_EQ(SpiN::getHardwareType(), HardwareType::spi);
}

#if REG_DEFINED(SPI_N(ENABLE_REG))
    TEST(SpiN, enable) {
        TEST_REG_WRITE(SpiN::enable(true));
        TEST_REG_WRITE(SpiN::enable(false));
    }
#endif

#if REG_DEFINED(SPI_N(INT_ENABLE_REG))
    TEST(SpiN, intEnable) {
        TEST_REG_WRITE(SpiN::intEnable(true));
        TEST_REG_WRITE(SpiN::intEnable(false));
    }
#endif

#if REG_DEFINED(SPI_N(DATA_ORDER_REG))
    TEST(SpiN, dataOrder) {
        TEST_REG_WRITE(SpiN::dataOrder(SpiN::DataOrder::msbFirst));
        TEST_REG_WRITE(SpiN::dataOrder(SpiN::DataOrder::lsbFirst));
    }
#endif

#if REG_DEFINED(SPI_N(MASTER_SLAVE_SELECT_REG))
    TEST(SpiN, masterSlave) {
        TEST_REG_WRITE(SpiN::masterSlave(SpiN::MasterSlave::master));
        TEST_REG_WRITE(SpiN::masterSlave(SpiN::MasterSlave::slave));
    }
#endif

#if REG_DEFINED(SPI_N(POLARITY_REG))
    TEST(SpiN, polarity) {
        TEST_REG_WRITE(SpiN::polarity(SpiN::Polarity::leadingRisingTrailingFalling));
        TEST_REG_WRITE(SpiN::polarity(SpiN::Polarity::leadingFallingTrailingRising));
    }
#endif

#if REG_DEFINED(SPI_N(PHASE_REG))
    TEST(SpiN, phase) {
        TEST_REG_WRITE(SpiN::phase(SpiN::Phase::leadingSampleTrailingSetup));
        TEST_REG_WRITE(SpiN::phase(SpiN::Phase::leadingSetupTrailingSample));
    }
#endif

#if REG_DEFINED(SPI_N(CLOCK_REG))
    TEST(SpiN, clock) { //(Clock c) {
        #if DEFINED(SPI_N(CLOCK_DIV_2_ID))
            TEST_REG_WRITE(SpiN::clock(SpiN::Clock::div2));
        #endif

        #if DEFINED(SPI_N(CLOCK_DIV_4_ID))
            TEST_REG_WRITE(SpiN::clock(SpiN::Clock::div4));
        #endif

        #if DEFINED(SPI_N(CLOCK_DIV_8_ID))
            TEST_REG_WRITE(SpiN::clock(SpiN::Clock::div8));
        #endif

        #if DEFINED(SPI_N(CLOCK_DIV_16_ID))
            TEST_REG_WRITE(SpiN::clock(SpiN::Clock::div16));
        #endif

        #if DEFINED(SPI_N(CLOCK_DIV_32_ID))
            TEST_REG_WRITE(SpiN::clock(SpiN::Clock::div32));
        #endif

        #if DEFINED(SPI_N(CLOCK_DIV_64_ID))
            TEST_REG_WRITE(SpiN::clock(SpiN::Clock::div64));
        #endif

        #if DEFINED(SPI_N(CLOCK_DIV_128_ID))
            TEST_REG_WRITE(SpiN::clock(SpiN::Clock::div128));
        #endif
    }
#endif

#if REG_DEFINED(SPI_N(INT_FLAG_REG))
    TEST(SpiN, intFlag) {
        TEST_REG_READ_WRITE(SpiN::intFlag());
    }
#endif

#if REG_DEFINED(SPI_N(COLLISION_FLAG_REG))
    TEST(SpiN, collisionFlag) {
        TEST_REG_READ_WRITE(SpiN::collisionFlag());
    }
#endif

#if REG_DEFINED(SPI_N(DATA_REG))
    TEST(SpiN, data) {
        TEST_REG_WRITE(SpiN::data(0x12));
        TEST_REG_READ_WRITE(SpiN::data());
    }
#endif

#endif // TEST

} // nblib::hw

//------------------------------------------------------------------

    #endif

    #undef N
    #undef SpiN
    #undef SPI_N

    #include "spi.hpp"
#else
    #define NBLIB_SPI_HPP
#endif


#endif
