/// # Serial Peripheral Interface

/// ```c++
/// atomic([]() {
///     nbos::hw::Spi0::PinMosi::mode(nbos::hw::Spi0::PinMosi::Mode::output);
///     nbos::hw::Spi0::PinSck::mode(nbos::hw::Spi0::PinSck::Mode::output);
/// });
///
/// atomic([]() {
///     nbos::hw::Spi0::clock(nbos::hw::Spi0::Clock::div16);
///     nbos::hw::Spi0::masterSlave(nbos::hw::Spi0::MasterSlave::master);
///     nbos::hw::Spi0::enable(true);
/// });
///
/// nbos::hw::Spi0::data(0x31);
///
/// while(!nbos::hw::Spi0::intFlag());
///
/// nbos::hw::Spi0::data(0x44);
///
/// while(!nbos::hw::Spi0::intFlag());
/// ```

#ifndef NBOS_SPI_HPP

#include "isr.hpp"
#include "chip.hpp"
#include "hardwaretype.hpp"
#include "macros.hpp"
#include "type.hpp"
#include "system.hpp"
#include "port.hpp"

#include "loopi"

#ifdef _I
    #define N _I
    #define SpiN CAT(Spi,N)
    #define SPI_N(A) CAT(CHIP_SPI_, N, _, A)

    #if CAT(CHIP_SPI_, N)

//------------------------------------------------------------------

namespace nbos::hw {

/// ## class SpiN
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
        /// #### enum DataOrder
        /// * msbFirst
        /// * lsbFirst
        enum class DataOrder : uint8_t {
            msbFirst = SPI_N(DATA_ORDER_MSB_FIRST_ID),
            lsbFirst = SPI_N(DATA_ORDER_LSB_FIRST_ID),
        };
    #endif

    #if DEFINED(SPI_N(MASTER_SLAVE_SELECT_BIT_0_BIT))
        /// #### enum MasterSlave
        /// * master
        /// * slave
        enum class MasterSlave : uint8_t {
            master = SPI_N(MASTER_SLAVE_SELECT_MASTER_ID),
            slave = SPI_N(MASTER_SLAVE_SELECT_SLAVE_ID),
        };
    #endif

    #if DEFINED(SPI_N(POLARITY_BIT_0_BIT))
        /// #### enum Polarity
        /// * leadingRisingTrailingFalling
        /// * leadingFallingTrailingRising
        enum class Polarity : uint8_t {
            leadingRisingTrailingFalling = SPI_N(POLARITY_LEADING_RISING_TRAILING_FALLING_ID),
            leadingFallingTrailingRising = SPI_N(POLARITY_LEADING_FALLING_TRAILING_RISING_ID),
        };
    #endif

    #if DEFINED(SPI_N(PHASE_BIT_0_BIT))
        /// #### enum Phase
        /// * leadingSampleTrailingSetup
        /// * leadingSetupTrailingSample
        enum class Phase : uint8_t {
            leadingSampleTrailingSetup = SPI_N(PHASE_LEADING_SAMPLE_TRAILING_SETUP_ID),
            leadingSetupTrailingSample = SPI_N(PHASE_LEADING_SETUP_TRAILING_SAMPLE_ID),
        };
    #endif

    #if DEFINED(SPI_N(CLOCK_BIT_0_BIT))
        /// #### enum Clock
        /// * div2
        /// * div4
        /// * div8
        /// * div16
        /// * div32
        /// * div64
        /// * div128
        enum class Clock : uint8_t {
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

    /// #### static HardwareType getHardwareType()
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

    /// #### static void callback(callback_t callback, void\* data)
    /// Set the callback for when the serial transfer is complete.
    static force_inline void callback(callback_t callback = nullptr, void* data = nullptr) {
        static callback_t f = nullptr;
        static void* d = nullptr;

        if(callback == nullptr) {
            if(f != nullptr) {
                f(d);
            }
        } else {
            f = callback;
            d = data;
        }
    }

    #if DEFINED(SPI_N(DATA_ORDER_BIT_0_BIT))
        /// #### static void dataOrder(DataOrder d)
        static force_inline void dataOrder(DataOrder d) {
            setBit_(REG(SPI_N(DATA_ORDER_BIT_0_REG)), SPI_N(DATA_ORDER_BIT_0_BIT), uint8_t(d) & 0x01);
        }
    #endif

    #if DEFINED(SPI_N(MASTER_SLAVE_SELECT_BIT_0_BIT))
        /// #### static void masterSlave(MasterSlave m)
        static force_inline void masterSlave(MasterSlave m) {
            setBit_(REG(SPI_N(MASTER_SLAVE_SELECT_BIT_0_REG)), SPI_N(MASTER_SLAVE_SELECT_BIT_0_BIT), uint8_t(m) & 0x01);
        }
    #endif

    #if DEFINED(SPI_N(POLARITY_BIT_0_BIT))
        /// #### static void polarity(Polarity p)
        static force_inline void polarity(Polarity p) {
            setBit_(REG(SPI_N(POLARITY_BIT_0_REG)), SPI_N(POLARITY_BIT_0_BIT), uint8_t(p) & 0x01);
        }
    #endif

    #if DEFINED(SPI_N(PHASE_BIT_0_BIT))
        /// #### static void phase(Phase p)
        static force_inline void phase(Phase p) {
            setBit_(REG(SPI_N(PHASE_BIT_0_REG)), SPI_N(PHASE_BIT_0_BIT), uint8_t(p) & 0x01);
        }
    #endif

    #if DEFINED(SPI_N(CLOCK_BIT_0_BIT))
        /// #### static void clock(Clock c)
        static force_inline void clock(Clock c) {
            setBit_(REG(SPI_N(CLOCK_BIT_0_REG)), SPI_N(CLOCK_BIT_0_BIT), uint8_t(c) & 0x01);

            #if DEFINED(SPI_N(CLOCK_BIT_1_BIT))
                setBit_(REG(SPI_N(CLOCK_BIT_1_REG)), SPI_N(CLOCK_BIT_1_BIT), uint8_t(c) & 0x02);
            #endif

            #if DEFINED(SPI_N(CLOCK_BIT_2_BIT))
                setBit_(REG(SPI_N(CLOCK_BIT_2_REG)), SPI_N(CLOCK_BIT_2_BIT), uint8_t(c) & 0x04);
            #endif
        }
    #endif

    #if DEFINED(SPI_N(INT_FLAG_BIT_0_BIT))
        /// #### static bool intFlag()
        static force_inline bool intFlag() {
            return getBit(REG(SPI_N(INT_FLAG_BIT_0_REG)), SPI_N(INT_FLAG_BIT_0_BIT));
        }

        /// #### static void intFlagClear()
        static force_inline void intFlagClear() {
            setBit_(REG(SPI_N(INT_FLAG_BIT_0_REG)), SPI_N(INT_FLAG_BIT_0_BIT), true);
        }
    #endif

    #if DEFINED(SPI_N(COLLISION_FLAG_BIT_0_BIT))
        /// #### static bool collisionFlag()
        static force_inline bool collisionFlag() {
            return getBit(REG(SPI_N(COLLISION_FLAG_BIT_0_REG)), SPI_N(COLLISION_FLAG_BIT_0_BIT));
        }

        /// #### static void collisionFlagClear()
        static force_inline void collisionFlagClear() {
            setBit_(REG(SPI_N(COLLISION_FLAG_BIT_0_REG)), SPI_N(COLLISION_FLAG_BIT_0_BIT), true);
        }
    #endif

    #if REG_DEFINED(SPI_N(DATA_REG))
        /// #### static void data(uint8_t d)
        static force_inline void data(uint8_t d) {
            *REG(SPI_N(DATA_REG)) = d;
        }

        /// #### static uint8_t data()
        static force_inline uint8_t data() {
            return *REG(SPI_N(DATA_REG));
        }
    #endif
};

ISR(SPI_N(INT_VECTOR)) {
    SpiN::callback();
}

} // nbos::hw

//------------------------------------------------------------------

    #endif

    #undef N
    #undef SpiN
    #undef SPI_N

    #include "spi.hpp"
#else
    #define NBOS_SPI_HPP
#endif


#endif
