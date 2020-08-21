/// [[Index]]

/// # {{AC}}

#ifndef NBLIB_AC_HPP

#include "chip.hpp"
#include "hardwaretype.hpp"
#include "isr.hpp"
#include "macros.hpp"
#include "system.hpp"
#include "callback.hpp"

#include "loopi"

#ifdef _I
    #define N _I
    #define AcN CAT(Ac, N)
    #define AC_N(A) CAT(CHIP_AC_, N, _, A)

    #if DEFINED(CAT(CHIP_AC_, N))

//------------------------------------------------------------------

namespace nblib::hw {

/// ## class {{AcN}}
struct AcN {
    AcN() = delete;
    AcN& operator=(const AcN&) = delete;
    AcN(const AcN&) = delete;

    #if REG_DEFINED(AC_N(INT_EDGE_REG))
        /// #### enum {{AN::IntEdge}}
        /// * both
        /// * negative
        /// * positive
        enum class IntEdge {
            #if DEFINED(AC_N(INT_EDGE_BOTH_ID))
                both = AC_N(INT_EDGE_BOTH_ID),
            #endif

            #if DEFINED(AC_N(INT_EDGE_NEGATIVE_ID))
                negative = AC_N(INT_EDGE_NEGATIVE_ID),
            #endif

            #if DEFINED(AC_N(INT_EDGE_POSITIVE_ID))
                positive = AC_N(INT_EDGE_POSITIVE_ID),
            #endif
        };
    #endif

    #if REG_DEFINED(AC_N(HYSTERESIS_REG))
        /// #### enum {{AcN::Hysteresis}}
        /// * off
        /// * _10mv
        /// * _25mv
        /// * _50mv
        enum class Hysteresis {
            #if DEFINED(AC_N(HYSTERESIS_OFF_ID))
                off = AC_N(HYSTERESIS_OFF_ID),
            #endif

            #if DEFINED(AC_N(HYSTERESIS_10_ID))
                _10mv = AC_N(HYSTERESIS_10_ID),
            #endif

            #if DEFINED(AC_N(HYSTERESIS_25_ID))
                _25mv = AC_N(HYSTERESIS_25_ID),
            #endif

            #if DEFINED(AC_N(HYSTERESIS_50_ID))
                _50mv = AC_N(HYSTERESIS_50_ID),
            #endif
        };
    #endif

    #if REG_DEFINED(AC_N(MUX_POS_REG))
        /// #### enum {{AcN::InputPositive}}
        /// * p0
        /// * p1
        /// * p2
        /// * p3
        /// * p4
        /// * p5
        enum class InputPositive {
            #if DEFINED(AC_N(MUX_POS_0_ID))
                p0 = AC_N(MUX_POS_0_ID),
            #endif

            #if DEFINED(AC_N(MUX_POS_1_ID))
                p1 = AC_N(MUX_POS_1_ID),
            #endif

            #if DEFINED(AC_N(MUX_POS_2_ID))
                p2 = AC_N(MUX_POS_2_ID),
            #endif

            #if DEFINED(AC_N(MUX_POS_3_ID))
                p3 = AC_N(MUX_POS_3_ID),
            #endif

            #if DEFINED(AC_N(MUX_POS_4_ID))
                p4 = AC_N(MUX_POS_4_ID),
            #endif

            #if DEFINED(AC_N(MUX_POS_5_ID))
                p5 = AC_N(MUX_POS_5_ID),
            #endif
        };
    #endif

    #if REG_DEFINED(AC_N(MUX_NEG_REG))
        /// #### enum {{AcN::InputNegative}}
        /// * n0
        /// * n1
        /// * n2
        /// * n3
        /// * vref
        /// * dac
        enum class InputNegative {
            #if DEFINED(AC_N(MUX_NEG_0_ID))
                n0 = AC_N(MUX_NEG_0_ID),
            #endif

            #if DEFINED(AC_N(MUX_NEG_1_ID))
                n1 = AC_N(MUX_NEG_1_ID),
            #endif

            #if DEFINED(AC_N(MUX_NEG_2_ID))
                n2 = AC_N(MUX_NEG_2_ID),
            #endif

            #if DEFINED(AC_N(MUX_NEG_3_ID))
                n3 = AC_N(MUX_NEG_3_ID),
            #endif

            #if DEFINED(AC_N(MUX_NEG_VREF_ID))
                vref = AC_N(MUX_NEG_VREF_ID),
            #endif

            #if DEFINED(AC_N(MUX_NEG_DAC_ID))
                dac = AC_N(MUX_NEG_DAC_ID),
            #endif
        };
    #endif

    /// #### static [[HardwareType]] getHardwareType()
    static constexpr HardwareType getHardwareType() {
        return HardwareType::ac;
    }

    #if REG_DEFINED(AC_N(ENABLE_REG))
        /// #### static void enable(bool)
        static force_inline void enable(bool e) {
            AC_N(ENABLE_REG)::setBit(AC_N(ENABLE_BIT), e);
        }
    #endif

    #if REG_DEFINED(AC_N(OUTPUT_ENABLE_REG))
        /// #### static void outputEnable(bool)
        static force_inline void outputEnable(bool e) {
            AC_N(OUTPUT_ENABLE_REG)::setBit(AC_N(OUTPUT_ENABLE_BIT), e);
        }
    #endif

    #if REG_DEFINED(AC_N(OUTPUT_INVERT_REG))
        /// #### static void outputInvert(bool)
        static force_inline void outputInvert(bool e) {
            AC_N(OUTPUT_INVERT_REG)::setBit(AC_N(OUTPUT_INVERT_BIT), e);
        }
    #endif

    #if REG_DEFINED(AC_N(HYSTERESIS_REG))
        /// #### static void hysteresis([[AcN::Hysteresis]])
        static force_inline void hysteresis(Hysteresis h) {
            AC_N(HYSTERESIS_REG)::setBits(AC_N(HYSTERESIS_MASK), h);
        }
    #endif

    #if REG_DEFINED(AC_N(MUX_POS_REG))
        /// #### static void inputPositive([[AcN::InputPositive]])
        static force_inline void inputPositive(InputPositive i) {
            AC_N(MUX_POS_REG)::setBits(AC_N(MUX_POS_MASK), i);
        }
    #endif

    #if REG_DEFINED(AC_N(MUX_NEG_REG))
        /// #### static void inputNegative([[AcN::InputNegative]])
        static force_inline void inputNegative(InputNegative i) {
            AC_N(MUX_NEG_REG)::setBits(AC_N(MUX_NEG_MASK), i);
        }
    #endif

    #if REG_DEFINED(AC_N(INT_EDGE_REG))
        /// #### static void intEdge([[AcN::IntEdge]])
        static force_inline void intEdge(IntEdge e) {
            AC_N(INT_EDGE_REG)::setBits(AC_N(INT_EDGE_MASK), e);
        }
    #endif

    #if REG_DEFINED(AC_N(INT_ENABLE_REG))
        /// #### static void intEnable(bool e)
        static force_inline void intEnable(bool e) {
            AC_N(INT_ENABLE_REG)::setBit(AC_N(INT_ENABLE_BIT), e);
        }
    #endif

    #if REG_DEFINED(AC_N(INT_FLAG_REG))
        /// #### static bool intFlag()
        static force_inline bool intFlag() {
            return AC_N(INT_FLAG_REG)::getBit(AC_N(INT_FLAG_BIT));
        }

        /// #### static void intFlagClear()
        static force_inline void intFlagClear() {
            AC_N(INT_FLAG_REG)::setBit(AC_N(INT_FLAG_BIT), true);
        }
    #endif

    #if REG_DEFINED(AC_N(STATE_REG))
        /// #### static bool state()
        static force_inline bool state() {
            return AC_N(STATE_REG)::getBit(AC_N(STATE_BIT));
        }
    #endif
};

#ifdef TEST

TEST(AcN, getHardwareType) {
    ASSERT_EQ(AcN::getHardwareType(), HardwareType::ac);
}

#if REG_DEFINED(AC_N(ENABLE_REG))
    TEST(AcN, enable) {
        TEST_REG_WRITE(AcN::enable(true));
        TEST_REG_WRITE(AcN::enable(false));
    }
#endif

#if REG_DEFINED(AC_N(OUTPUT_ENABLE_REG))
    TEST(AcN, outputEnable) {
        TEST_REG_WRITE(AcN::outputEnable(true));
        TEST_REG_WRITE(AcN::outputEnable(false));
    }
#endif

#if REG_DEFINED(AC_N(OUTPUT_INVERT_REG))
    TEST(AcN, outputInvert) {
        TEST_REG_WRITE(AcN::outputInvert(true));
        TEST_REG_WRITE(AcN::outputInvert(false));
    }
#endif

#if REG_DEFINED(AC_N(HYSTERESIS_REG))
    TEST(AcN, hysteresis) {
        #if DEFINED(AC_N(HYSTERESIS_OFF_ID))
            TEST_REG_WRITE(AcN::hysteresis(AcN::Hysteresis::off));
        #endif

        #if DEFINED(AC_N(HYSTERESIS_10_ID))
            TEST_REG_WRITE(AcN::hysteresis(AcN::Hysteresis::_10mv));
        #endif

        #if DEFINED(AC_N(HYSTERESIS_25_ID))
            TEST_REG_WRITE(AcN::hysteresis(AcN::Hysteresis::_25mv));
        #endif

        #if DEFINED(AC_N(HYSTERESIS_50_ID))
            TEST_REG_WRITE(AcN::hysteresis(AcN::Hysteresis::_50mv));
        #endif
    }
#endif

#if REG_DEFINED(AC_N(MUX_POS_REG))
    TEST(AcN, inputPositive) {
        #if DEFINED(AC_N(MUX_POS_0_ID))
            TEST_REG_WRITE(AcN::inputPositive(AcN::InputPositive::p0));
        #endif

        #if DEFINED(AC_N(MUX_POS_1_ID))
            TEST_REG_WRITE(AcN::inputPositive(AcN::InputPositive::p1));
        #endif

        #if DEFINED(AC_N(MUX_POS_2_ID))
            TEST_REG_WRITE(AcN::inputPositive(AcN::InputPositive::p2));
        #endif

        #if DEFINED(AC_N(MUX_POS_3_ID))
            TEST_REG_WRITE(AcN::inputPositive(AcN::InputPositive::p3));
        #endif

        #if DEFINED(AC_N(MUX_POS_4_ID))
            TEST_REG_WRITE(AcN::inputPositive(AcN::InputPositive::p4));
        #endif

        #if DEFINED(AC_N(MUX_POS_5_ID))
            TEST_REG_WRITE(AcN::inputPositive(AcN::InputPositive::p5));
        #endif
    }
#endif

#if REG_DEFINED(AC_N(MUX_NEG_REG))
    TEST(AcN, inputNegative) {
        #if DEFINED(AC_N(MUX_NEG_0_ID))
            TEST_REG_WRITE(AcN::inputNegative(AcN::InputNegative::n0));
        #endif

        #if DEFINED(AC_N(MUX_NEG_1_ID))
            TEST_REG_WRITE(AcN::inputNegative(AcN::InputNegative::n1));
        #endif

        #if DEFINED(AC_N(MUX_NEG_2_ID))
            TEST_REG_WRITE(AcN::inputNegative(AcN::InputNegative::n2));
        #endif

        #if DEFINED(AC_N(MUX_NEG_3_ID))
            TEST_REG_WRITE(AcN::inputNegative(AcN::InputNegative::n3));
        #endif

        #if DEFINED(AC_N(MUX_NEG_VREF_ID))
            TEST_REG_WRITE(AcN::inputNegative(AcN::InputNegative::vref));
        #endif

        #if DEFINED(AC_N(MUX_NEG_DAC_ID))
            TEST_REG_WRITE(AcN::inputNegative(AcN::InputNegative::dac));
        #endif
    }
#endif

#if REG_DEFINED(AC_N(INT_EDGE_REG))
    TEST(AcN, intEdge) {
        #if DEFINED(AC_N(INT_EDGE_BOTH))
            TEST_REG_WRITE(AcN::intEdge(AcN::IntEdge::both));
        #endif

        #if DEFINED(AC_N(INT_EDGE_NEGATIVE))
            TEST_REG_WRITE(AcN::intEdge(AcN::IntEdge::negative));
        #endif

        #if DEFINED(AC_N(INT_EDGE_POSITIVE))
            TEST_REG_WRITE(AcN::intEdge(AcN::IntEdge::positive));
        #endif
    }
#endif

#if REG_DEFINED(AC_N(INT_ENABLE_REG))
    TEST(AcN, intEnable) {
        TEST_REG_WRITE(AcN::intEnable(true));
        TEST_REG_WRITE(AcN::intEnable(false));
    }
#endif

#if REG_DEFINED(AC_N(INT_FLAG_REG))
    TEST(AcN, intFlag) {
        TEST_REG_READ_WRITE(AcN::intFlag());
    }

    TEST(AcN, intFlagClear) {
        TEST_REG_WRITE(AcN::intFlagClear());
    }
#endif

#if REG_DEFINED(AC_N(STATE_REG))
    TEST(AcN, state) {
        TEST_REG_READ_WRITE(AcN::state());
    }
#endif

#endif // TEST

} // nblib::hw

//------------------------------------------------------------------

    #endif

    #undef N
    #undef AcN
    #undef AC_N

    #include "ac.hpp"
#else
    #define NBLIB_AC_HPP
#endif

#endif
