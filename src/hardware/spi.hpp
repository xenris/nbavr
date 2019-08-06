/// [[Index]]

/// # {{Serial Peripheral Interfaces}}

/// ```c++
/// atomic {
///     nblib::hw::Spi0::PinMosi::mode(nblib::hw::Spi0::PinMosi::Mode::output);
///     nblib::hw::Spi0::PinSck::mode(nblib::hw::Spi0::PinSck::Mode::output);
/// });
///
/// atomic {
///     nblib::hw::Spi0::clock(nblib::hw::Spi0::Clock::div16);
///     nblib::hw::Spi0::masterSlave(nblib::hw::Spi0::MasterSlave::master);
///     nblib::hw::Spi0::enable(true);
/// });
///
/// nblib::hw::Spi0::data(0x31);
///
/// while(!nblib::hw::Spi0::intFlag());
///
/// nblib::hw::Spi0::data(0x44);
///
/// while(!nblib::hw::Spi0::intFlag());
/// ```

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

    #if CAT(CHIP_SPI_, N)

//------------------------------------------------------------------

namespace nblib::hw {

/// ## class {{SpiN}}
struct SpiN {
    SpiN() = delete;
    SpiN& operator=(const SpiN&) = delete;
    SpiN(const SpiN&) = delete;

    /// #### type PinMiso
    using PinMiso = SPI_N(PIN_MISO);

    /// #### type PinMosi
    using PinMosi = SPI_N(PIN_MOSI);

    /// #### type PinSck
    using PinSck = SPI_N(PIN_SCK);

    /// #### type PinSs
    using PinSs = SPI_N(PIN_SS);

    #if DEFINED(SPI_N(DATA_ORDER_BIT_0_BIT))
        /// #### enum {{SpiN::DataOrder}}
        /// * msbFirst
        /// * lsbFirst
        enum class DataOrder {
            msbFirst = SPI_N(DATA_ORDER_MSB_FIRST_ID),
            lsbFirst = SPI_N(DATA_ORDER_LSB_FIRST_ID),
        };
    #endif

    #if DEFINED(SPI_N(MASTER_SLAVE_SELECT_BIT_0_BIT))
        /// #### enum {{SpiN::MasterSlave}}
        /// * master
        /// * slave
        enum class MasterSlave {
            master = SPI_N(MASTER_SLAVE_SELECT_MASTER_ID),
            slave = SPI_N(MASTER_SLAVE_SELECT_SLAVE_ID),
        };
    #endif

    #if DEFINED(SPI_N(POLARITY_BIT_0_BIT))
        /// #### enum {{SpiN::Polarity}}
        /// * leadingRisingTrailingFalling
        /// * leadingFallingTrailingRising
        enum class Polarity {
            leadingRisingTrailingFalling = SPI_N(POLARITY_LEADING_RISING_TRAILING_FALLING_ID),
            leadingFallingTrailingRising = SPI_N(POLARITY_LEADING_FALLING_TRAILING_RISING_ID),
        };
    #endif

    #if DEFINED(SPI_N(PHASE_BIT_0_BIT))
        /// #### enum {{SpiN::Phase}}
        /// * leadingSampleTrailingSetup
        /// * leadingSetupTrailingSample
        enum class Phase {
            leadingSampleTrailingSetup = SPI_N(PHASE_LEADING_SAMPLE_TRAILING_SETUP_ID),
            leadingSetupTrailingSample = SPI_N(PHASE_LEADING_SETUP_TRAILING_SAMPLE_ID),
        };
    #endif

    #if DEFINED(SPI_N(CLOCK_BIT_0_BIT))
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

    #if DEFINED(SPI_N(ENABLE_BIT_0_BIT))
        /// #### static void enable(bool b)
        static force_inline void enable(bool b) {
            setBit_(REG(SPI_N(ENABLE_BIT_0_REG)), SPI_N(ENABLE_BIT_0_BIT), b);
        }
    #endif

    #if DEFINED(SPI_N(INT_ENABLE_BIT_0_BIT))
        /// #### static void intEnable(bool b)
        static force_inline void intEnable(bool b) {
            setBit_(REG(SPI_N(INT_ENABLE_BIT_0_REG)), SPI_N(INT_ENABLE_BIT_0_BIT), b);
        }
    #endif

    /// #### static void setCallback([[Callback]]<T\> function, T\* data)
    /// Set the callback for when the serial transfer is complete.
    template <class T>
    static force_inline void setCallback(Callback<T> function, T* data = nullptr) {
        callback((Callback<void>)function, data);
    }

    /// #### static void callCallback()
    static force_inline void callCallback() {
        callback();
    }

    #if DEFINED(SPI_N(DATA_ORDER_BIT_0_BIT))
        /// #### static void dataOrder([[SpiN::DataOrder]] d)
        static force_inline void dataOrder(DataOrder d) {
            setBit_(REG(SPI_N(DATA_ORDER_BIT_0_REG)), SPI_N(DATA_ORDER_BIT_0_BIT), int(d) & 0x01);
        }
    #endif

    #if DEFINED(SPI_N(MASTER_SLAVE_SELECT_BIT_0_BIT))
        /// #### static void masterSlave([[SpiN::MasterSlave]] m)
        static force_inline void masterSlave(MasterSlave m) {
            setBit_(REG(SPI_N(MASTER_SLAVE_SELECT_BIT_0_REG)), SPI_N(MASTER_SLAVE_SELECT_BIT_0_BIT), int(m) & 0x01);
        }
    #endif

    #if DEFINED(SPI_N(POLARITY_BIT_0_BIT))
        /// #### static void polarity([[SpiN::Polarity]] p)
        static force_inline void polarity(Polarity p) {
            setBit_(REG(SPI_N(POLARITY_BIT_0_REG)), SPI_N(POLARITY_BIT_0_BIT), int(p) & 0x01);
        }
    #endif

    #if DEFINED(SPI_N(PHASE_BIT_0_BIT))
        /// #### static void phase([[SpiN::Phase]] p)
        static force_inline void phase(Phase p) {
            setBit_(REG(SPI_N(PHASE_BIT_0_REG)), SPI_N(PHASE_BIT_0_BIT), int(p) & 0x01);
        }
    #endif

    #if DEFINED(SPI_N(CLOCK_BIT_0_BIT))
        /// #### static void clock([[SpiN::Clock]] c)
        static force_inline void clock(Clock c) {
            setBit_(REG(SPI_N(CLOCK_BIT_0_REG)), SPI_N(CLOCK_BIT_0_BIT), int(c) & 0x01);

            #if DEFINED(SPI_N(CLOCK_BIT_1_BIT))
                setBit_(REG(SPI_N(CLOCK_BIT_1_REG)), SPI_N(CLOCK_BIT_1_BIT), int(c) & 0x02);
            #endif

            #if DEFINED(SPI_N(CLOCK_BIT_2_BIT))
                setBit_(REG(SPI_N(CLOCK_BIT_2_REG)), SPI_N(CLOCK_BIT_2_BIT), int(c) & 0x04);
            #endif
        }
    #endif

    #if DEFINED(SPI_N(INT_FLAG_BIT_0_BIT))
        /// #### static bool intFlag()
        static force_inline bool intFlag() {
            return getBit(REG(SPI_N(INT_FLAG_BIT_0_REG)), SPI_N(INT_FLAG_BIT_0_BIT));
        }
    #endif

    #if DEFINED(SPI_N(COLLISION_FLAG_BIT_0_BIT))
        /// #### static bool collisionFlag()
        static force_inline bool collisionFlag() {
            return getBit(REG(SPI_N(COLLISION_FLAG_BIT_0_REG)), SPI_N(COLLISION_FLAG_BIT_0_BIT));
        }
    #endif

    #if REG_DEFINED(SPI_N(DATA_REG))
        /// #### static void data(uint8_t d)
        static force_inline void data(uint8_t d) {
            setReg_(REG(SPI_N(DATA_REG)), d);
        }

        /// #### static uint8_t data()
        static force_inline uint8_t data() {
            return getReg_(REG(SPI_N(DATA_REG)));
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

ISR(SPI_N(INT_VECTOR)) {
    SpiN::callCallback();
}

#ifdef TEST

TEST(SpiN, getHardwareType) {
    ASSERT_EQ(SpiN::getHardwareType(), HardwareType::spi);
}

#if DEFINED(SPI_N(ENABLE_BIT_0_BIT))
    TEST(SpiN, enable) {
        TEST_REG_WRITE(SpiN::enable(true));
        TEST_REG_WRITE(SpiN::enable(false));
    }
#endif

#if DEFINED(SPI_N(INT_ENABLE_BIT_0_BIT))
    TEST(SpiN, intEnable) {
        TEST_REG_WRITE(SpiN::intEnable(true));
        TEST_REG_WRITE(SpiN::intEnable(false));
    }
#endif

#if DEFINED(SPI_N(DATA_ORDER_BIT_0_BIT))
    TEST(SpiN, dataOrder) {
        TEST_REG_WRITE(SpiN::dataOrder(SpiN::DataOrder::msbFirst));
        TEST_REG_WRITE(SpiN::dataOrder(SpiN::DataOrder::lsbFirst));
    }
#endif

#if DEFINED(SPI_N(MASTER_SLAVE_SELECT_BIT_0_BIT))
    TEST(SpiN, masterSlave) {
        TEST_REG_WRITE(SpiN::masterSlave(SpiN::MasterSlave::master));
        TEST_REG_WRITE(SpiN::masterSlave(SpiN::MasterSlave::slave));
    }
#endif

#if DEFINED(SPI_N(POLARITY_BIT_0_BIT))
    TEST(SpiN, polarity) {
        TEST_REG_WRITE(SpiN::polarity(SpiN::Polarity::leadingRisingTrailingFalling));
        TEST_REG_WRITE(SpiN::polarity(SpiN::Polarity::leadingFallingTrailingRising));
    }
#endif

#if DEFINED(SPI_N(PHASE_BIT_0_BIT))
    TEST(SpiN, phase) {
        TEST_REG_WRITE(SpiN::phase(SpiN::Phase::leadingSampleTrailingSetup));
        TEST_REG_WRITE(SpiN::phase(SpiN::Phase::leadingSetupTrailingSample));
    }
#endif

#if DEFINED(SPI_N(CLOCK_BIT_0_BIT))
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

#if DEFINED(SPI_N(INT_FLAG_BIT_0_BIT))
    TEST(SpiN, intFlag) {
        TEST_REG_READ_WRITE(SpiN::intFlag());
    }
#endif

#if DEFINED(SPI_N(COLLISION_FLAG_BIT_0_BIT))
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
