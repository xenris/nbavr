/// [[Index]]

/// # {{DAC}}

#ifndef NBLIB_DAC_HPP

#include "chip.hpp"
#include "hardwaretype.hpp"
#include "isr.hpp"
#include "macros.hpp"
#include "system.hpp"
#include "callback.hpp"

#include "loopi"

#ifdef _I
    #define N _I
    #define DacN CAT(Dac, N)
    #define DAC_N(A) CAT(CHIP_DAC_, N, _, A)

    #if DEFINED(CAT(CHIP_DAC_, N))

//------------------------------------------------------------------

namespace nblib::hw {

/// ## class {{DacN}}
struct DacN {
    DacN() = delete;
    DacN& operator=(const DacN&) = delete;
    DacN(const DacN&) = delete;

    /// #### static [[HardwareType]] getHardwareType()
    static constexpr HardwareType getHardwareType() {
        return HardwareType::dac;
    }

    #if REG_DEFINED(DAC_N(ENABLE_REG))
        /// #### static void enable(bool)
        static force_inline void enable(bool e) {
            DAC_N(ENABLE_REG)::setBit(DAC_N(ENABLE_BIT), e);
        }
    #endif

    #if REG_DEFINED(DAC_N(OUTPUT_ENABLE_REG))
        /// #### static void outputEnable(bool)
        static force_inline void outputEnable(bool e) {
            DAC_N(OUTPUT_ENABLE_REG)::setBit(DAC_N(OUTPUT_ENABLE_BIT), e);
        }
    #endif

    #if REG_DEFINED(DAC_N(DATA_REG))
        /// #### static void data(uint8_t)
        static force_inline void data(uint8_t d) {
            DAC_N(DATA_REG)::setReg(d);
        }
    #endif
};

#ifdef TEST

TEST(DacN, getHardwareType) {
    ASSERT_EQ(DacN::getHardwareType(), HardwareType::dac);
}

#if REG_DEFINED(DAC_N(ENABLE_REG))
    TEST(DacN, enable) {
        TEST_REG_WRITE(DacN::enable(true));
        TEST_REG_WRITE(DacN::enable(false));
    }
#endif

#if REG_DEFINED(DAC_N(OUTPUT_ENABLE_REG))
    TEST(DacN, outputEnable) {
        TEST_REG_WRITE(DacN::outputEnable(true));
        TEST_REG_WRITE(DacN::outputEnable(false));
    }
#endif

#if REG_DEFINED(DAC_N(DATA_REG))
    TEST(DacN, data) {
        TEST_REG_WRITE(DacN::data(0x12));
    }
#endif

#endif // TEST

} // nblib::hw

//------------------------------------------------------------------

    #endif

    #undef N
    #undef DacN
    #undef DAC_N

    #include "dac.hpp"
#else
    #define NBLIB_DAC_HPP
#endif

#endif
