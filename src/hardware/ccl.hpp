/// [[Index]]

/// # {{Ccl}}

#ifndef NBLIB_CCL_HPP

#include "chip.hpp"
#include "register.hpp"
#include "hardwaretype.hpp"
#include "macros.hpp"
#include "system.hpp"

#include "loopi"

#ifdef _I
    #define N _I
    #define CclN CAT(Ccl,N)
    #define CCL_N(A) CAT(CHIP_CCL_, N, _, A)

    #if DEFINED(CAT(CHIP_CCL_, N))

//------------------------------------------------------------------

namespace nblib::hw {

/// ## class {{CclN}}
struct CclN {
    CclN() = delete;
    CclN& operator=(const CclN&) = delete;
    CclN(const CclN&) = delete;

    /// #### enum {{CclN::LutXInputN}}
    /// X = {A, B}<br>
    /// N = {0, 1, 2}<br>
    /// * mask
    /// * feedback
    /// * link
    /// * event0
    /// * event1
    /// * io
    /// * ac0
    /// * tcb0
    /// * tca0
    /// * usart0
    /// * spi0
    /// * tcd0
    /// * ac1
    /// * tcb1
    /// * ac2
    enum class LutAInput0 {
        #if DEFINED(CCL_N(LUT_A_INPUT_0_MASK_ID))
            mask = CCL_N(LUT_A_INPUT_0_MASK_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_0_FEEDBACK_ID))
            feedback = CCL_N(LUT_A_INPUT_0_FEEDBACK_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_0_LINK_ID))
            link = CCL_N(LUT_A_INPUT_0_LINK_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_0_EVENT0_ID))
            event0 = CCL_N(LUT_A_INPUT_0_EVENT0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_0_EVENT1_ID))
            event1 = CCL_N(LUT_A_INPUT_0_EVENT1_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_0_IO_ID))
            io = CCL_N(LUT_A_INPUT_0_IO_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_0_AC0_ID))
            ac0 = CCL_N(LUT_A_INPUT_0_AC0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_0_TCB0_ID))
            tcb0 = CCL_N(LUT_A_INPUT_0_TCB0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_0_TCA0_ID))
            tca0 = CCL_N(LUT_A_INPUT_0_TCA0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_0_USART0_ID))
            usart0 = CCL_N(LUT_A_INPUT_0_USART0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_0_SPI0_ID))
            spi0 = CCL_N(LUT_A_INPUT_0_SPI0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_0_TCD0_ID))
            tcd0 = CCL_N(LUT_A_INPUT_0_TCD0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_0_AC1_ID))
            ac1 = CCL_N(LUT_A_INPUT_0_AC1_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_0_TCB1_ID))
            tcb1 = CCL_N(LUT_A_INPUT_0_TCB1_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_0_AC2_ID))
            ac2 = CCL_N(LUT_A_INPUT_0_AC2_ID),
        #endif
    };

    enum class LutAInput1 {
        #if DEFINED(CCL_N(LUT_A_INPUT_1_MASK_ID))
            mask = CCL_N(LUT_A_INPUT_1_MASK_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_1_FEEDBACK_ID))
            feedback = CCL_N(LUT_A_INPUT_1_FEEDBACK_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_1_LINK_ID))
            link = CCL_N(LUT_A_INPUT_1_LINK_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_1_EVENT0_ID))
            event0 = CCL_N(LUT_A_INPUT_1_EVENT0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_1_EVENT1_ID))
            event1 = CCL_N(LUT_A_INPUT_1_EVENT1_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_1_IO_ID))
            io = CCL_N(LUT_A_INPUT_1_IO_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_1_AC0_ID))
            ac0 = CCL_N(LUT_A_INPUT_1_AC0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_1_TCB0_ID))
            tcb0 = CCL_N(LUT_A_INPUT_1_TCB0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_1_TCA0_ID))
            tca0 = CCL_N(LUT_A_INPUT_1_TCA0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_1_USART0_ID))
            usart0 = CCL_N(LUT_A_INPUT_1_USART0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_1_SPI0_ID))
            spi0 = CCL_N(LUT_A_INPUT_1_SPI0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_1_TCD0_ID))
            tcd0 = CCL_N(LUT_A_INPUT_1_TCD0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_1_AC1_ID))
            ac1 = CCL_N(LUT_A_INPUT_1_AC1_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_1_TCB1_ID))
            tcb1 = CCL_N(LUT_A_INPUT_1_TCB1_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_1_AC2_ID))
            ac2 = CCL_N(LUT_A_INPUT_1_AC2_ID),
        #endif
    };

    enum class LutAInput2 {
        #if DEFINED(CCL_N(LUT_A_INPUT_2_MASK_ID))
            mask = CCL_N(LUT_A_INPUT_2_MASK_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_2_FEEDBACK_ID))
            feedback = CCL_N(LUT_A_INPUT_2_FEEDBACK_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_2_LINK_ID))
            link = CCL_N(LUT_A_INPUT_2_LINK_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_2_EVENT0_ID))
            event0 = CCL_N(LUT_A_INPUT_2_EVENT0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_2_EVENT1_ID))
            event1 = CCL_N(LUT_A_INPUT_2_EVENT1_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_2_IO_ID))
            io = CCL_N(LUT_A_INPUT_2_IO_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_2_AC0_ID))
            ac0 = CCL_N(LUT_A_INPUT_2_AC0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_2_TCB0_ID))
            tcb0 = CCL_N(LUT_A_INPUT_2_TCB0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_2_TCA0_ID))
            tca0 = CCL_N(LUT_A_INPUT_2_TCA0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_2_USART0_ID))
            usart0 = CCL_N(LUT_A_INPUT_2_USART0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_2_SPI0_ID))
            spi0 = CCL_N(LUT_A_INPUT_2_SPI0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_2_TCD0_ID))
            tcd0 = CCL_N(LUT_A_INPUT_2_TCD0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_2_AC1_ID))
            ac1 = CCL_N(LUT_A_INPUT_2_AC1_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_2_TCB1_ID))
            tcb1 = CCL_N(LUT_A_INPUT_2_TCB1_ID),
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_2_AC2_ID))
            ac2 = CCL_N(LUT_A_INPUT_2_AC2_ID),
        #endif
    };

    enum class LutBInput0 {
        #if DEFINED(CCL_N(LUT_B_INPUT_0_MASK_ID))
            mask = CCL_N(LUT_B_INPUT_0_MASK_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_0_FEEDBACK_ID))
            feedback = CCL_N(LUT_B_INPUT_0_FEEDBACK_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_0_LINK_ID))
            link = CCL_N(LUT_B_INPUT_0_LINK_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_0_EVENT0_ID))
            event0 = CCL_N(LUT_B_INPUT_0_EVENT0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_0_EVENT1_ID))
            event1 = CCL_N(LUT_B_INPUT_0_EVENT1_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_0_IO_ID))
            io = CCL_N(LUT_B_INPUT_0_IO_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_0_AC0_ID))
            ac0 = CCL_N(LUT_B_INPUT_0_AC0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_0_TCB0_ID))
            tcb0 = CCL_N(LUT_B_INPUT_0_TCB0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_0_TCA0_ID))
            tca0 = CCL_N(LUT_B_INPUT_0_TCA0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_0_USART0_ID))
            usart0 = CCL_N(LUT_B_INPUT_0_USART0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_0_SPI0_ID))
            spi0 = CCL_N(LUT_B_INPUT_0_SPI0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_0_TCD0_ID))
            tcd0 = CCL_N(LUT_B_INPUT_0_TCD0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_0_AC1_ID))
            ac1 = CCL_N(LUT_B_INPUT_0_AC1_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_0_TCB1_ID))
            tcb1 = CCL_N(LUT_B_INPUT_0_TCB1_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_0_AC2_ID))
            ac2 = CCL_N(LUT_B_INPUT_0_AC2_ID),
        #endif
    };

    enum class LutBInput1 {
        #if DEFINED(CCL_N(LUT_B_INPUT_1_MASK_ID))
            mask = CCL_N(LUT_B_INPUT_1_MASK_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_1_FEEDBACK_ID))
            feedback = CCL_N(LUT_B_INPUT_1_FEEDBACK_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_1_LINK_ID))
            link = CCL_N(LUT_B_INPUT_1_LINK_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_1_EVENT0_ID))
            event0 = CCL_N(LUT_B_INPUT_1_EVENT0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_1_EVENT1_ID))
            event1 = CCL_N(LUT_B_INPUT_1_EVENT1_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_1_IO_ID))
            io = CCL_N(LUT_B_INPUT_1_IO_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_1_AC0_ID))
            ac0 = CCL_N(LUT_B_INPUT_1_AC0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_1_TCB0_ID))
            tcb0 = CCL_N(LUT_B_INPUT_1_TCB0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_1_TCA0_ID))
            tca0 = CCL_N(LUT_B_INPUT_1_TCA0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_1_USART0_ID))
            usart0 = CCL_N(LUT_B_INPUT_1_USART0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_1_SPI0_ID))
            spi0 = CCL_N(LUT_B_INPUT_1_SPI0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_1_TCD0_ID))
            tcd0 = CCL_N(LUT_B_INPUT_1_TCD0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_1_AC1_ID))
            ac1 = CCL_N(LUT_B_INPUT_1_AC1_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_1_TCB1_ID))
            tcb1 = CCL_N(LUT_B_INPUT_1_TCB1_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_1_AC2_ID))
            ac2 = CCL_N(LUT_B_INPUT_1_AC2_ID),
        #endif
    };

    enum class LutBInput2 {
        #if DEFINED(CCL_N(LUT_B_INPUT_2_MASK_ID))
            mask = CCL_N(LUT_B_INPUT_2_MASK_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_2_FEEDBACK_ID))
            feedback = CCL_N(LUT_B_INPUT_2_FEEDBACK_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_2_LINK_ID))
            link = CCL_N(LUT_B_INPUT_2_LINK_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_2_EVENT0_ID))
            event0 = CCL_N(LUT_B_INPUT_2_EVENT0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_2_EVENT1_ID))
            event1 = CCL_N(LUT_B_INPUT_2_EVENT1_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_2_IO_ID))
            io = CCL_N(LUT_B_INPUT_2_IO_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_2_AC0_ID))
            ac0 = CCL_N(LUT_B_INPUT_2_AC0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_2_TCB0_ID))
            tcb0 = CCL_N(LUT_B_INPUT_2_TCB0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_2_TCA0_ID))
            tca0 = CCL_N(LUT_B_INPUT_2_TCA0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_2_USART0_ID))
            usart0 = CCL_N(LUT_B_INPUT_2_USART0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_2_SPI0_ID))
            spi0 = CCL_N(LUT_B_INPUT_2_SPI0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_2_TCD0_ID))
            tcd0 = CCL_N(LUT_B_INPUT_2_TCD0_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_2_AC1_ID))
            ac1 = CCL_N(LUT_B_INPUT_2_AC1_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_2_TCB1_ID))
            tcb1 = CCL_N(LUT_B_INPUT_2_TCB1_ID),
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_2_AC2_ID))
            ac2 = CCL_N(LUT_B_INPUT_2_AC2_ID),
        #endif
    };

    /// #### static [[HardwareType]] getHardwareType()
    static constexpr HardwareType getHardwareType() {
        return HardwareType::ccl;
    }

    /// #### static void enable(bool)
    #if REG_DEFINED(CCL_N(ENABLE_REG))
        static force_inline void enable(bool e) {
            CCL_N(ENABLE_REG)::setBit(CCL_N(ENABLE_BIT), e);
        }
    #endif

    #if REG_DEFINED(CCL_N(LUT_A_ENABLE_REG))
        /// #### static void lutAEnable(bool)
        static force_inline void lutAEnable(bool e) {
            CCL_N(LUT_A_ENABLE_REG)::setBit(CCL_N(LUT_A_ENABLE_BIT), e);
        }
    #endif

    #if REG_DEFINED(CCL_N(LUT_B_ENABLE_REG))
        /// #### static void lutBEnable(bool)
        static force_inline void lutBEnable(bool e) {
            CCL_N(LUT_B_ENABLE_REG)::setBit(CCL_N(LUT_B_ENABLE_BIT), e);
        }
    #endif

    #if REG_DEFINED(CCL_N(LUT_A_OUTPUT_ENABLE_REG))
        /// #### static void lutAOutputEnable(bool)
        static force_inline void lutAOutputEnable(bool e) {
            CCL_N(LUT_A_OUTPUT_ENABLE_REG)::setBit(CCL_N(LUT_A_OUTPUT_ENABLE_BIT), e);
        }
    #endif

    #if REG_DEFINED(CCL_N(LUT_B_OUTPUT_ENABLE_REG))
        /// #### static void lutBOutputEnable(bool)
        static force_inline void lutBOutputEnable(bool e) {
            CCL_N(LUT_B_OUTPUT_ENABLE_REG)::setBit(CCL_N(LUT_B_OUTPUT_ENABLE_BIT), e);
        }
    #endif

    #if REG_DEFINED(CCL_N(LUT_A_TRUTH_REG))
        /// #### static void lutATruth(uint8_t)
        static force_inline void lutATruth(uint8_t t) {
            CCL_N(LUT_A_TRUTH_REG)::setReg(t);
        }
    #endif

    #if REG_DEFINED(CCL_N(LUT_B_TRUTH_REG))
        /// #### static void lutBTruth(uint8_t)
        static force_inline void lutBTruth(uint8_t t) {
            CCL_N(LUT_B_TRUTH_REG)::setReg(t);
        }
    #endif

    /// #### static void lutXInputN([[CclN::LutXInputN]])
    /// X = {A, B}<br>
    /// N = {0, 1, 2}

    #if REG_DEFINED(CCL_N(LUT_A_INPUT_0_REG))
        static force_inline void lutAInput0(LutAInput0 i) {
            CCL_N(LUT_A_INPUT_0_REG)::setBits(CCL_N(LUT_A_INPUT_0_MASK), i);
        }
    #endif

    #if REG_DEFINED(CCL_N(LUT_A_INPUT_1_REG))
        static force_inline void lutAInput1(LutAInput1 i) {
            CCL_N(LUT_A_INPUT_1_REG)::setBits(CCL_N(LUT_A_INPUT_1_MASK), i);
        }
    #endif

    #if REG_DEFINED(CCL_N(LUT_A_INPUT_2_REG))
        static force_inline void lutAInput2(LutAInput2 i) {
            CCL_N(LUT_A_INPUT_2_REG)::setBits(CCL_N(LUT_A_INPUT_2_MASK), i);
        }
    #endif

    #if REG_DEFINED(CCL_N(LUT_B_INPUT_0_REG))
        static force_inline void lutBInput0(LutBInput0 i) {
            CCL_N(LUT_B_INPUT_0_REG)::setBits(CCL_N(LUT_B_INPUT_0_MASK), i);
        }
    #endif

    #if REG_DEFINED(CCL_N(LUT_B_INPUT_1_REG))
        static force_inline void lutBInput1(LutBInput1 i) {
            CCL_N(LUT_B_INPUT_1_REG)::setBits(CCL_N(LUT_B_INPUT_1_MASK), i);
        }
    #endif

    #if REG_DEFINED(CCL_N(LUT_B_INPUT_2_REG))
        static force_inline void lutBInput2(LutBInput2 i) {
            CCL_N(LUT_B_INPUT_2_REG)::setBits(CCL_N(LUT_B_INPUT_2_MASK), i);
        }
    #endif
};

#ifdef TEST

TEST(CclN, getHardwareType) {
    ASSERT_EQ(CclN::getHardwareType(), HardwareType::ccl);
}

#if REG_DEFINED(CCL_N(ENABLE_REG))
    TEST(CclN, enable) {
        TEST_REG_WRITE(CclN::enable(true));
        TEST_REG_WRITE(CclN::enable(false));
    }
#endif

#if REG_DEFINED(CCL_N(LUT_A_ENABLE_REG))
    TEST(CclN, lutAEnable) {
        TEST_REG_WRITE(CclN::lutAEnable(true));
        TEST_REG_WRITE(CclN::lutAEnable(false));
    }
#endif

#if REG_DEFINED(CCL_N(LUT_B_ENABLE_REG))
    TEST(CclN, lutBEnable) {
        TEST_REG_WRITE(CclN::lutBEnable(true));
        TEST_REG_WRITE(CclN::lutBEnable(false));
    }
#endif

#if REG_DEFINED(CCL_N(LUT_A_OUTPUT_ENABLE_REG))
    TEST(CclN, lutAOutputEnable) {
        TEST_REG_WRITE(CclN::lutAOutputEnable(true));
        TEST_REG_WRITE(CclN::lutAOutputEnable(false));
    }
#endif

#if REG_DEFINED(CCL_N(LUT_B_OUTPUT_ENABLE_REG))
    TEST(CclN, lutBOutputEnable) {
        TEST_REG_WRITE(CclN::lutBOutputEnable(true));
        TEST_REG_WRITE(CclN::lutBOutputEnable(false));
    }
#endif

#if REG_DEFINED(CCL_N(LUT_A_TRUTH_REG))
    TEST(CclN, lutATruth) {
        TEST_REG_WRITE(CclN::lutATruth(0x12));
        TEST_REG_WRITE(CclN::lutATruth(0xED));
    }
#endif

#if REG_DEFINED(CCL_N(LUT_B_TRUTH_REG))
    TEST(CclN, lutBTruth) {
        TEST_REG_WRITE(CclN::lutBTruth(0x12));
        TEST_REG_WRITE(CclN::lutBTruth(0xED));
    }
#endif

#if REG_DEFINED(CCL_N(LUT_A_INPUT_0_REG))
    TEST(CclN, lutAInput0) {
        #if DEFINED(CCL_N(LUT_A_INPUT_0_MASK_ID))
            TEST_REG_WRITE(CclN::lutAInput0(CclN::LutAInput0::mask));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_0_FEEDBACK_ID))
            TEST_REG_WRITE(CclN::lutAInput0(CclN::LutAInput0::feedback));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_0_LINK_ID))
            TEST_REG_WRITE(CclN::lutAInput0(CclN::LutAInput0::link));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_0_EVENT0_ID))
            TEST_REG_WRITE(CclN::lutAInput0(CclN::LutAInput0::event0));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_0_EVENT1_ID))
            TEST_REG_WRITE(CclN::lutAInput0(CclN::LutAInput0::event1));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_0_IO_ID))
            TEST_REG_WRITE(CclN::lutAInput0(CclN::LutAInput0::io));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_0_AC0_ID))
            TEST_REG_WRITE(CclN::lutAInput0(CclN::LutAInput0::ac0));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_0_TCB0_ID))
            TEST_REG_WRITE(CclN::lutAInput0(CclN::LutAInput0::tcb0));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_0_TCA0_ID))
            TEST_REG_WRITE(CclN::lutAInput0(CclN::LutAInput0::tca0));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_0_USART0_ID))
            TEST_REG_WRITE(CclN::lutAInput0(CclN::LutAInput0::usart0));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_0_SPI0_ID))
            TEST_REG_WRITE(CclN::lutAInput0(CclN::LutAInput0::spi0));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_0_TCD0_ID))
            TEST_REG_WRITE(CclN::lutAInput0(CclN::LutAInput0::tcd0));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_0_AC1_ID))
            TEST_REG_WRITE(CclN::lutAInput0(CclN::LutAInput0::ac1));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_0_TCB1_ID))
            TEST_REG_WRITE(CclN::lutAInput0(CclN::LutAInput0::tcb1));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_0_AC2_ID))
            TEST_REG_WRITE(CclN::lutAInput0(CclN::LutAInput0::ac2));
        #endif
    }
#endif

#if REG_DEFINED(CCL_N(LUT_A_INPUT_1_REG))
    TEST(CclN, lutAInput1) {
        #if DEFINED(CCL_N(LUT_A_INPUT_1_MASK_ID))
            TEST_REG_WRITE(CclN::lutAInput1(CclN::LutAInput1::mask));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_1_FEEDBACK_ID))
            TEST_REG_WRITE(CclN::lutAInput1(CclN::LutAInput1::feedback));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_1_LINK_ID))
            TEST_REG_WRITE(CclN::lutAInput1(CclN::LutAInput1::link));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_1_EVENT0_ID))
            TEST_REG_WRITE(CclN::lutAInput1(CclN::LutAInput1::event0));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_1_EVENT1_ID))
            TEST_REG_WRITE(CclN::lutAInput1(CclN::LutAInput1::event1));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_1_IO_ID))
            TEST_REG_WRITE(CclN::lutAInput1(CclN::LutAInput1::io));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_1_AC0_ID))
            TEST_REG_WRITE(CclN::lutAInput1(CclN::LutAInput1::ac0));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_1_TCB0_ID))
            TEST_REG_WRITE(CclN::lutAInput1(CclN::LutAInput1::tcb0));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_1_TCA0_ID))
            TEST_REG_WRITE(CclN::lutAInput1(CclN::LutAInput1::tca0));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_1_USART0_ID))
            TEST_REG_WRITE(CclN::lutAInput1(CclN::LutAInput1::usart0));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_1_SPI0_ID))
            TEST_REG_WRITE(CclN::lutAInput1(CclN::LutAInput1::spi0));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_1_TCD0_ID))
            TEST_REG_WRITE(CclN::lutAInput1(CclN::LutAInput1::tcd0));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_1_AC1_ID))
            TEST_REG_WRITE(CclN::lutAInput1(CclN::LutAInput1::ac1));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_1_TCB1_ID))
            TEST_REG_WRITE(CclN::lutAInput1(CclN::LutAInput1::tcb1));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_1_AC2_ID))
            TEST_REG_WRITE(CclN::lutAInput1(CclN::LutAInput1::ac2));
        #endif
    }
#endif

#if REG_DEFINED(CCL_N(LUT_A_INPUT_2_REG))
    TEST(CclN, lutAInput2) {
        #if DEFINED(CCL_N(LUT_A_INPUT_2_MASK_ID))
            TEST_REG_WRITE(CclN::lutAInput2(CclN::LutAInput2::mask));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_2_FEEDBACK_ID))
            TEST_REG_WRITE(CclN::lutAInput2(CclN::LutAInput2::feedback));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_2_LINK_ID))
            TEST_REG_WRITE(CclN::lutAInput2(CclN::LutAInput2::link));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_2_EVENT0_ID))
            TEST_REG_WRITE(CclN::lutAInput2(CclN::LutAInput2::event0));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_2_EVENT1_ID))
            TEST_REG_WRITE(CclN::lutAInput2(CclN::LutAInput2::event1));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_2_IO_ID))
            TEST_REG_WRITE(CclN::lutAInput2(CclN::LutAInput2::io));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_2_AC0_ID))
            TEST_REG_WRITE(CclN::lutAInput2(CclN::LutAInput2::ac0));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_2_TCB0_ID))
            TEST_REG_WRITE(CclN::lutAInput2(CclN::LutAInput2::tcb0));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_2_TCA0_ID))
            TEST_REG_WRITE(CclN::lutAInput2(CclN::LutAInput2::tca0));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_2_USART0_ID))
            TEST_REG_WRITE(CclN::lutAInput2(CclN::LutAInput2::usart0));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_2_SPI0_ID))
            TEST_REG_WRITE(CclN::lutAInput2(CclN::LutAInput2::spi0));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_2_TCD0_ID))
            TEST_REG_WRITE(CclN::lutAInput2(CclN::LutAInput2::tcd0));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_2_AC1_ID))
            TEST_REG_WRITE(CclN::lutAInput2(CclN::LutAInput2::ac1));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_2_TCB1_ID))
            TEST_REG_WRITE(CclN::lutAInput2(CclN::LutAInput2::tcb1));
        #endif
        #if DEFINED(CCL_N(LUT_A_INPUT_2_AC2_ID))
            TEST_REG_WRITE(CclN::lutAInput2(CclN::LutAInput2::ac2));
        #endif
    }
#endif

#if REG_DEFINED(CCL_N(LUT_B_INPUT_0_REG))
    TEST(CclN, lutBInput0) {
        #if DEFINED(CCL_N(LUT_B_INPUT_0_MASK_ID))
            TEST_REG_WRITE(CclN::lutBInput0(CclN::LutBInput0::mask));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_0_FEEDBACK_ID))
            TEST_REG_WRITE(CclN::lutBInput0(CclN::LutBInput0::feedback));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_0_LINK_ID))
            TEST_REG_WRITE(CclN::lutBInput0(CclN::LutBInput0::link));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_0_EVENT0_ID))
            TEST_REG_WRITE(CclN::lutBInput0(CclN::LutBInput0::event0));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_0_EVENT1_ID))
            TEST_REG_WRITE(CclN::lutBInput0(CclN::LutBInput0::event1));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_0_IO_ID))
            TEST_REG_WRITE(CclN::lutBInput0(CclN::LutBInput0::io));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_0_AC0_ID))
            TEST_REG_WRITE(CclN::lutBInput0(CclN::LutBInput0::ac0));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_0_TCB0_ID))
            TEST_REG_WRITE(CclN::lutBInput0(CclN::LutBInput0::tcb0));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_0_TCA0_ID))
            TEST_REG_WRITE(CclN::lutBInput0(CclN::LutBInput0::tca0));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_0_USART0_ID))
            TEST_REG_WRITE(CclN::lutBInput0(CclN::LutBInput0::usart0));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_0_SPI0_ID))
            TEST_REG_WRITE(CclN::lutBInput0(CclN::LutBInput0::spi0));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_0_TCD0_ID))
            TEST_REG_WRITE(CclN::lutBInput0(CclN::LutBInput0::tcd0));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_0_AC1_ID))
            TEST_REG_WRITE(CclN::lutBInput0(CclN::LutBInput0::ac1));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_0_TCB1_ID))
            TEST_REG_WRITE(CclN::lutBInput0(CclN::LutBInput0::tcb1));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_0_AC2_ID))
            TEST_REG_WRITE(CclN::lutBInput0(CclN::LutBInput0::ac2));
        #endif
    }
#endif

#if REG_DEFINED(CCL_N(LUT_B_INPUT_1_REG))
    TEST(CclN, lutBInput1) {
        #if DEFINED(CCL_N(LUT_B_INPUT_1_MASK_ID))
            TEST_REG_WRITE(CclN::lutBInput1(CclN::LutBInput1::mask));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_1_FEEDBACK_ID))
            TEST_REG_WRITE(CclN::lutBInput1(CclN::LutBInput1::feedback));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_1_LINK_ID))
            TEST_REG_WRITE(CclN::lutBInput1(CclN::LutBInput1::link));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_1_EVENT0_ID))
            TEST_REG_WRITE(CclN::lutBInput1(CclN::LutBInput1::event0));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_1_EVENT1_ID))
            TEST_REG_WRITE(CclN::lutBInput1(CclN::LutBInput1::event1));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_1_IO_ID))
            TEST_REG_WRITE(CclN::lutBInput1(CclN::LutBInput1::io));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_1_AC0_ID))
            TEST_REG_WRITE(CclN::lutBInput1(CclN::LutBInput1::ac0));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_1_TCB0_ID))
            TEST_REG_WRITE(CclN::lutBInput1(CclN::LutBInput1::tcb0));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_1_TCA0_ID))
            TEST_REG_WRITE(CclN::lutBInput1(CclN::LutBInput1::tca0));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_1_USART0_ID))
            TEST_REG_WRITE(CclN::lutBInput1(CclN::LutBInput1::usart0));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_1_SPI0_ID))
            TEST_REG_WRITE(CclN::lutBInput1(CclN::LutBInput1::spi0));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_1_TCD0_ID))
            TEST_REG_WRITE(CclN::lutBInput1(CclN::LutBInput1::tcd0));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_1_AC1_ID))
            TEST_REG_WRITE(CclN::lutBInput1(CclN::LutBInput1::ac1));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_1_TCB1_ID))
            TEST_REG_WRITE(CclN::lutBInput1(CclN::LutBInput1::tcb1));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_1_AC2_ID))
            TEST_REG_WRITE(CclN::lutBInput1(CclN::LutBInput1::ac2));
        #endif
    }
#endif

#if REG_DEFINED(CCL_N(LUT_B_INPUT_2_REG))
    TEST(CclN, lutBInput2) {
        #if DEFINED(CCL_N(LUT_B_INPUT_2_MASK_ID))
            TEST_REG_WRITE(CclN::lutBInput2(CclN::LutBInput2::mask));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_2_FEEDBACK_ID))
            TEST_REG_WRITE(CclN::lutBInput2(CclN::LutBInput2::feedback));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_2_LINK_ID))
            TEST_REG_WRITE(CclN::lutBInput2(CclN::LutBInput2::link));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_2_EVENT0_ID))
            TEST_REG_WRITE(CclN::lutBInput2(CclN::LutBInput2::event0));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_2_EVENT1_ID))
            TEST_REG_WRITE(CclN::lutBInput2(CclN::LutBInput2::event1));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_2_IO_ID))
            TEST_REG_WRITE(CclN::lutBInput2(CclN::LutBInput2::io));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_2_AC0_ID))
            TEST_REG_WRITE(CclN::lutBInput2(CclN::LutBInput2::ac0));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_2_TCB0_ID))
            TEST_REG_WRITE(CclN::lutBInput2(CclN::LutBInput2::tcb0));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_2_TCA0_ID))
            TEST_REG_WRITE(CclN::lutBInput2(CclN::LutBInput2::tca0));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_2_USART0_ID))
            TEST_REG_WRITE(CclN::lutBInput2(CclN::LutBInput2::usart0));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_2_SPI0_ID))
            TEST_REG_WRITE(CclN::lutBInput2(CclN::LutBInput2::spi0));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_2_TCD0_ID))
            TEST_REG_WRITE(CclN::lutBInput2(CclN::LutBInput2::tcd0));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_2_AC1_ID))
            TEST_REG_WRITE(CclN::lutBInput2(CclN::LutBInput2::ac1));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_2_TCB1_ID))
            TEST_REG_WRITE(CclN::lutBInput2(CclN::LutBInput2::tcb1));
        #endif
        #if DEFINED(CCL_N(LUT_B_INPUT_2_AC2_ID))
            TEST_REG_WRITE(CclN::lutBInput2(CclN::LutBInput2::ac2));
        #endif
    }
#endif

#endif // TEST

} // nblib::hw

//------------------------------------------------------------------

    #endif

    #undef N
    #undef CclN
    #undef CCL_N

    #include "ccl.hpp"
#else
    #define NBLIB_CCL_HPP
#endif

#endif
