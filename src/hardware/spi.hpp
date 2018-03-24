/// # SPI

/// N is the SPI id (0, 1, 2, etc).

/// ## Example

/// ```c++
/// // TODO
/// ```

#ifndef NBOS_SPI_HPP

#include "callbacks.hpp"
#include "chip.hpp"
#include "hardwaretype.hpp"
#include "macros.hpp"
#include "type.hpp"
#include "system.hpp"
#include "port.hpp"

/// #### macro INCLUDE_SPI_CALLBACK(N)
/// Include this to use Spi callback.<br>
/// N is the Spi id.
#define INCLUDE_SPI_CALLBACK(N) MAKE_CALLBACK(SPI, N)

#include "loopi"

#ifdef _I
    #define N _I
    #define SpiN CAT(Spi,N)
    #define SPI_N(A) CAT(CHIP_SPI_, N, _, A)
    #define _SPI_N(A) UNDERLINE(SPI, N, A)

    #if CAT(CHIP_SPI_, N)

//------------------------------------------------------------------

namespace nbos::hw {

MAKE_CALLBACK_HEADER(SPI, N);

/// ## class SpiN
struct SpiN {
    SpiN() = delete;
    SpiN& operator=(const SpiN&) = delete;
    SpiN(const SpiN&) = delete;

    /// #### type PinMiso
    /// The MISO IO pin.
    using PinMiso = SPI_N(PIN_MISO);

    /// #### type PinMosi
    /// The MOSI IO pin.
    using PinMosi = SPI_N(PIN_MOSI);

    /// #### type PinSck
    /// The SCK IO pin.
    using PinSck = SPI_N(PIN_SCK);

    /// #### type PinSs
    /// The SS IO pin.
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

    /// #### static constexpr HardwareType getHardwareType()
    /// Get the type of hardware that this class represents.
    static constexpr HardwareType getHardwareType() {
        return HardwareType::spi;
    }

    #if DEFINED(SPI_N(ENABLE_BIT_0_BIT))
        /// #### static void enable(bool b)
        /// Enable the SPI hardware.
        static force_inline void enable(bool b) {
            setBit_(REG(SPI_N(ENABLE_BIT_0_REG)), SPI_N(ENABLE_BIT_0_BIT), b);
        }
    #endif

    #if DEFINED(SPI_N(INT_ENABLE_BIT_0_BIT))
        /// #### static void intEnable(bool b)
        /// Enable the SPI interrupt.
        static force_inline void intEnable(bool b) {
            setBit_(REG(SPI_N(INT_ENABLE_BIT_0_REG)), SPI_N(INT_ENABLE_BIT_0_BIT), b);
        }
    #endif

    #if DEFINED(SPI_N(DATA_ORDER_BIT_0_BIT))
        /// #### static void dataOrder(DataOrder d)
        /// Set the data order msb/lsb first
        static force_inline void dataOrder(DataOrder d) {
            setBit_(REG(SPI_N(DATA_ORDER_BIT_0_REG)), SPI_N(DATA_ORDER_BIT_0_BIT), uint8_t(d) & 0x01);
        }
    #endif

    #if DEFINED(SPI_N(MASTER_SLAVE_SELECT_BIT_0_BIT))
        /// #### static void masterSlave(MasterSlave m)
        /// Set master or slave mode
        static force_inline void masterSlave(MasterSlave m) {
            setBit_(REG(SPI_N(MASTER_SLAVE_SELECT_BIT_0_REG)), SPI_N(MASTER_SLAVE_SELECT_BIT_0_BIT), uint8_t(m) & 0x01);
        }
    #endif

    #if DEFINED(SPI_N(POLARITY_BIT_0_BIT))
        /// #### static void polarity(Polarity p)
        /// Set the clock polarity.
        static force_inline void polarity(Polarity p) {
            setBit_(REG(SPI_N(POLARITY_BIT_0_REG)), SPI_N(POLARITY_BIT_0_BIT), uint8_t(p) & 0x01);
        }
    #endif

    #if DEFINED(SPI_N(PHASE_BIT_0_BIT))
        /// #### static void phase(Phase p)
        /// Set the clock phase.
        static force_inline void phase(Phase p) {
            setBit_(REG(SPI_N(PHASE_BIT_0_REG)), SPI_N(PHASE_BIT_0_BIT), uint8_t(p) & 0x01);
        }
    #endif

    #if DEFINED(SPI_N(CLOCK_BIT_0_BIT))
        /// #### static void clock(Clock c)
        /// Set the clock speed.
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
        /// Get the interrupt flag's state.
        static force_inline bool intFlag() {
            return getBit(REG(SPI_N(INT_FLAG_BIT_0_REG)), SPI_N(INT_FLAG_BIT_0_BIT));
        }

        /// #### static void intFlagClear()
        /// Clear the interrupt flag.
        static force_inline void intFlagClear() {
            setBit_(REG(SPI_N(INT_FLAG_BIT_0_REG)), SPI_N(INT_FLAG_BIT_0_BIT), true);
        }
    #endif

    #if DEFINED(SPI_N(COLLISION_FLAG_BIT_0_BIT))
        /// #### static bool collisionFlag()
        /// Get the write collision flag's state.
        static force_inline bool collisionFlag() {
            return getBit(REG(SPI_N(COLLISION_FLAG_BIT_0_REG)), SPI_N(COLLISION_FLAG_BIT_0_BIT));
        }

        /// #### static void collisionFlagClear()
        /// Clear the write collision flag.
        static force_inline void collisionFlagClear() {
            setBit_(REG(SPI_N(COLLISION_FLAG_BIT_0_REG)), SPI_N(COLLISION_FLAG_BIT_0_BIT), true);
        }
    #endif

    #if REG_DEFINED(SPI_N(DATA_REG))
        /// #### static void data(uint8_t d)
        /// Put value d into the data register.
        static force_inline void data(uint8_t d) {
            *REG(SPI_N(DATA_REG)) = d;
        }

        /// #### static uint8_t data()
        /// Get value from the data register.
        static force_inline uint8_t data() {
            return *REG(SPI_N(DATA_REG));
        }
    #endif
};

} // nbos::hw

//------------------------------------------------------------------

    #endif

    #undef N
    #undef SpiN
    #undef SPI_N
    #undef _SPI_N

    #include "spi.hpp"
#else
    #define NBOS_SPI_HPP
#endif


#endif
