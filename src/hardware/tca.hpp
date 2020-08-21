/// [[Index]]

/// # {{TCA}}

#ifndef NBLIB_TCA_HPP

#include "chip.hpp"
#include "hardwaretype.hpp"
#include "port.hpp"
#include "macros.hpp"
#include "system.hpp"
#include "callback.hpp"
#include "register.hpp"

#include "loopi"

#ifdef _I
    #define N _I
    #define TcAN CAT(TcA, N)
    #define TCA_N(A) CAT(CHIP_TCA_, N, _, A)

    #if DEFINED(CAT(CHIP_TCA_, N))

//--------------------------------------------------------

namespace nblib::hw {

/// ## Class {{TcAN}}
struct TcAN {
    TcAN() = delete;
    TcAN& operator=(const TcAN&) = delete;
    TcAN(const TcAN&) = delete;

    /// #### enum {{TcAN::Clock}}
    /// * div1
    /// * div2
    /// * div4
    /// * div8
    /// * div16
    /// * div64
    /// * div256
    /// * div1024
    enum class Clock {
        #if DEFINED(TCA_N(CLOCK_1_ID))
            div1 = TCA_N(CLOCK_1_ID),
        #endif

        #if DEFINED(TCA_N(CLOCK_2_ID))
            div2 = TCA_N(CLOCK_2_ID),
        #endif

        #if DEFINED(TCA_N(CLOCK_4_ID))
            div4 = TCA_N(CLOCK_4_ID),
        #endif

        #if DEFINED(TCA_N(CLOCK_8_ID))
            div8 = TCA_N(CLOCK_8_ID),
        #endif

        #if DEFINED(TCA_N(CLOCK_16_ID))
            div16 = TCA_N(CLOCK_16_ID),
        #endif

        #if TCA_N(CLOCK_64_ID)
            div64 = TCA_N(CLOCK_64_ID),
        #endif

        #if TCA_N(CLOCK_256_ID)
            div256 = TCA_N(CLOCK_256_ID),
        #endif

        #if DEFINED(TCA_N(CLOCK_1024_ID))
            div1024 = TCA_N(CLOCK_1024_ID),
        #endif
    };

    /// #### enum {{TcAN::Waveform}}
    /// * normal
    /// * frequency
    /// * singleSlopePwm
    /// * dualSlopePwmOverflowTop
    /// * dualSlopePwmOverflowBottom
    /// * dualSlopePwmOverflowBoth
    enum class Waveform {
        #if DEFINED(TCA_N(WAVEFORM_NORMAL_ID))
            normal = TCA_N(WAVEFORM_NORMAL_ID),
        #endif

        #if DEFINED(TCA_N(WAVEFORM_FREQUENCY_ID))
            frequency = TCA_N(WAVEFORM_FREQUENCY_ID),
        #endif

        #if DEFINED(TCA_N(WAVEFORM_SINGLE_SLOPE_PWM_ID))
            singleSlopePwm = TCA_N(WAVEFORM_SINGLE_SLOPE_PWM_ID),
        #endif

        #if DEFINED(TCA_N(WAVEFORM_DUAL_SLOPE_PWM_OVF_TOP_ID))
            dualSlopePwmOverflowTop = TCA_N(WAVEFORM_DUAL_SLOPE_PWM_OVF_TOP_ID),
        #endif

        #if DEFINED(TCA_N(WAVEFORM_DUAL_SLOPE_PWM_OVF_BOTTOM_ID))
            dualSlopePwmOverflowBottom = TCA_N(WAVEFORM_DUAL_SLOPE_PWM_OVF_BOTTOM_ID),
        #endif

        #if DEFINED(TCA_N(WAVEFORM_DUAL_SLOPE_PWM_OVF_BOTH_ID))
            dualSlopePwmOverflowBoth = TCA_N(WAVEFORM_DUAL_SLOPE_PWM_OVF_BOTH_ID),
        #endif
    };

    /// #### static [[HardwareType]] getHardwareType()
    static constexpr HardwareType getHardwareType() {
        return HardwareType::tcA;
    }

    #if REG_DEFINED(TCA_N(ENABLE_REG))
        /// #### static void enable(bool)
        static force_inline void enable(bool b) {
            TCA_N(ENABLE_REG)::setBit(TCA_N(ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TCA_N(COUNTER_REG))
        /// #### static void counter(T value)
        static force_inline void counter(TCA_N(COUNTER_REG)::Type value) {
            TCA_N(COUNTER_REG)::setReg(value);
        }

        /// #### static T counter()
        static force_inline TCA_N(COUNTER_REG)::Type counter() {
            return TCA_N(COUNTER_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(TCA_N(TOP_REG))
        /// #### static void top(T value)
        static force_inline void top(TCA_N(TOP_REG)::Type value) {
            TCA_N(TOP_REG)::setReg(value);
        }

        /// #### static T top()
        static force_inline TCA_N(TOP_REG)::Type top() {
            return TCA_N(TOP_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(TCA_N(TOP_BUFFER_REG))
        /// #### static void topBuffer(T value)
        static force_inline void topBuffer(TCA_N(TOP_BUFFER_REG)::Type value) {
            TCA_N(TOP_BUFFER_REG)::setReg(value);
        }

        /// #### static T topBuffer()
        static force_inline TCA_N(TOP_BUFFER_REG)::Type topBuffer() {
            return TCA_N(TOP_BUFFER_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(TCA_N(CLOCK_REG))
        /// #### static void clock([[TcAN::Clock]] c)
        static force_inline void clock(Clock c) {
            TCA_N(CLOCK_REG)::setBits(TCA_N(CLOCK_MASK), c);
        }
    #endif

    #if REG_DEFINED(TCA_N(WAVEFORM_REG))
        /// #### static void waveform([[TcAN::Waveform]] w)
        static force_inline void waveform(Waveform w) {
            TCA_N(WAVEFORM_REG)::setBits(TCA_N(WAVEFORM_MASK), w);

            #if REG_DEFINED(TCA_N(WAVEFORM_REG_EXTRA))
                TCA_N(WAVEFORM_REG_EXTRA)::setBits(TCA_N(WAVEFORM_MASK_EXTRA), uint(w) >> 8);
            #endif
        }
    #endif

    #if REG_DEFINED(TCA_N(OVERFLOW_INT_ENABLE_REG))
        /// #### static void overflowIntEnable(bool)
        static force_inline void overflowIntEnable(bool b) {
            TCA_N(OVERFLOW_INT_ENABLE_REG)::setBit(TCA_N(OVERFLOW_INT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TCA_N(OVERFLOW_INT_FLAG_REG))
        /// #### static bool overflowIntFlag()
        static force_inline bool overflowIntFlag() {
            return TCA_N(OVERFLOW_INT_FLAG_REG)::getBit(TCA_N(OVERFLOW_INT_FLAG_BIT));
        }

        /// #### static void overflowIntFlagClear()
        static force_inline void overflowIntFlagClear() {
            TCA_N(OVERFLOW_INT_FLAG_REG)::setBit(TCA_N(OVERFLOW_INT_FLAG_BIT), true);
        }
    #endif

    /// #### static void compareN(T value)

    /// #### static T compareN()

    #if REG_DEFINED(TCA_N(COMPARE_0_REG))
        static force_inline void compare0(TCA_N(COMPARE_0_REG)::Type value) {
            TCA_N(COMPARE_0_REG)::setReg(value);
        }

        static force_inline TCA_N(COMPARE_0_REG)::Type compare0() {
            return TCA_N(COMPARE_0_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(TCA_N(COMPARE_1_REG))
        static force_inline void compare1(TCA_N(COMPARE_1_REG)::Type value) {
            TCA_N(COMPARE_1_REG)::setReg(value);
        }

        static force_inline TCA_N(COMPARE_1_REG)::Type compare1() {
            return TCA_N(COMPARE_1_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(TCA_N(COMPARE_2_REG))
        static force_inline void compare2(TCA_N(COMPARE_2_REG)::Type value) {
            TCA_N(COMPARE_2_REG)::setReg(value);
        }

        static force_inline TCA_N(COMPARE_2_REG)::Type compare2() {
            return TCA_N(COMPARE_2_REG)::getReg();
        }
    #endif

    /// #### static void compareNBuffer(T value)

    /// #### static T compareNBuffer()

    #if REG_DEFINED(TCA_N(COMPARE_0_BUFFER_REG))
        static force_inline void compare0Buffer(TCA_N(COMPARE_0_BUFFER_REG)::Type value) {
            TCA_N(COMPARE_0_BUFFER_REG)::setReg(value);
        }

        static force_inline TCA_N(COMPARE_0_BUFFER_REG)::Type compare0Buffer() {
            return TCA_N(COMPARE_0_BUFFER_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(TCA_N(COMPARE_1_BUFFER_REG))
        static force_inline void compare1Buffer(TCA_N(COMPARE_1_BUFFER_REG)::Type value) {
            TCA_N(COMPARE_1_BUFFER_REG)::setReg(value);
        }

        static force_inline TCA_N(COMPARE_1_BUFFER_REG)::Type compare1Buffer() {
            return TCA_N(COMPARE_1_BUFFER_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(TCA_N(COMPARE_2_BUFFER_REG))
        static force_inline void compare2Buffer(TCA_N(COMPARE_2_BUFFER_REG)::Type value) {
            TCA_N(COMPARE_2_BUFFER_REG)::setReg(value);
        }

        static force_inline TCA_N(COMPARE_2_BUFFER_REG)::Type compare2Buffer() {
            return TCA_N(COMPARE_2_BUFFER_REG)::getReg();
        }
    #endif

    /// #### static void compareNOutputEnable(bool)

    #if REG_DEFINED(TCA_N(COMPARE_0_OUTPUT_ENABLE_REG))
        static force_inline void compare0OutputEnable(bool b) {
            TCA_N(COMPARE_0_OUTPUT_ENABLE_REG)::setBit(TCA_N(COMPARE_0_OUTPUT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TCA_N(COMPARE_1_OUTPUT_ENABLE_REG))
        static force_inline void compare1OutputEnable(bool b) {
            TCA_N(COMPARE_1_OUTPUT_ENABLE_REG)::setBit(TCA_N(COMPARE_1_OUTPUT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TCA_N(COMPARE_2_OUTPUT_ENABLE_REG))
        static force_inline void compare2OutputEnable(bool b) {
            TCA_N(COMPARE_2_OUTPUT_ENABLE_REG)::setBit(TCA_N(COMPARE_2_OUTPUT_ENABLE_BIT), b);
        }
    #endif

    /// #### static void compareNIntEnable(bool)

    #if REG_DEFINED(TCA_N(COMPARE_0_INT_ENABLE_REG))
        static force_inline void compare0IntEnable(bool b) {
            TCA_N(COMPARE_0_INT_ENABLE_REG)::setBit(TCA_N(COMPARE_0_INT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TCA_N(COMPARE_1_INT_ENABLE_REG))
        static force_inline void compare1IntEnable(bool b) {
            TCA_N(COMPARE_1_INT_ENABLE_REG)::setBit(TCA_N(COMPARE_1_INT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TCA_N(COMPARE_2_INT_ENABLE_REG))
        static force_inline void compare2IntEnable(bool b) {
            TCA_N(COMPARE_2_INT_ENABLE_REG)::setBit(TCA_N(COMPARE_2_INT_ENABLE_BIT), b);
        }
    #endif

    /// #### static bool compareNIntFlag()

    /// #### static void compareNIntFlagClear()

    #if REG_DEFINED(TCA_N(COMPARE_0_INT_FLAG_REG))
        static force_inline bool compare0IntFlag() {
            return TCA_N(COMPARE_0_INT_FLAG_REG)::getBit(TCA_N(COMPARE_0_INT_FLAG_BIT));
        }

        static force_inline void compare0IntFlagClear() {
            TCA_N(COMPARE_0_INT_FLAG_REG)::setBit(TCA_N(COMPARE_0_INT_FLAG_BIT), true);
        }
    #endif

    #if REG_DEFINED(TCA_N(COMPARE_1_INT_FLAG_REG))
        static force_inline bool compare1IntFlag() {
            return TCA_N(COMPARE_1_INT_FLAG_REG)::getBit(TCA_N(COMPARE_1_INT_FLAG_BIT));
        }

        static force_inline void compare1IntFlagClear() {
            TCA_N(COMPARE_1_INT_FLAG_REG)::setBit(TCA_N(COMPARE_1_INT_FLAG_BIT), true);
        }
    #endif

    #if REG_DEFINED(TCA_N(COMPARE_2_INT_FLAG_REG))
        static force_inline bool compare2IntFlag() {
            return TCA_N(COMPARE_2_INT_FLAG_REG)::getBit(TCA_N(COMPARE_2_INT_FLAG_BIT));
        }

        static force_inline void compare2IntFlagClear() {
            TCA_N(COMPARE_2_INT_FLAG_REG)::setBit(TCA_N(COMPARE_2_INT_FLAG_BIT), true);
        }
    #endif

    #if REG_DEFINED(TCA_N(SPLIT_MODE_ENABLE_REG))
        /// #### static bool splitModeEnable(bool)
        static force_inline void splitModeEnable(bool b) {
            TCA_N(SPLIT_MODE_ENABLE_REG)::setBit(TCA_N(SPLIT_MODE_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TCA_N(LOW_COUNTER_REG))
        /// #### static void lowCounter(T value)
        static force_inline void lowCounter(TCA_N(LOW_COUNTER_REG)::Type value) {
            TCA_N(LOW_COUNTER_REG)::setReg(value);
        }

        /// #### static T lowCounter()
        static force_inline TCA_N(LOW_COUNTER_REG)::Type lowCounter() {
            return TCA_N(LOW_COUNTER_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(TCA_N(HIGH_COUNTER_REG))
        /// #### static void highCounter(T value)
        static force_inline void highCounter(TCA_N(HIGH_COUNTER_REG)::Type value) {
            TCA_N(HIGH_COUNTER_REG)::setReg(value);
        }

        /// #### static T highCounter()
        static force_inline TCA_N(HIGH_COUNTER_REG)::Type highCounter() {
            return TCA_N(HIGH_COUNTER_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(TCA_N(LOW_TOP_REG))
        /// #### static void lowTop(T value)
        static force_inline void lowTop(TCA_N(LOW_TOP_REG)::Type value) {
            TCA_N(LOW_TOP_REG)::setReg(value);
        }

        /// #### static T lowTop()
        static force_inline TCA_N(LOW_TOP_REG)::Type lowTop() {
            return TCA_N(LOW_TOP_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(TCA_N(HIGH_TOP_REG))
        /// #### static void highTop(T value)
        static force_inline void highTop(TCA_N(HIGH_TOP_REG)::Type value) {
            TCA_N(HIGH_TOP_REG)::setReg(value);
        }

        /// #### static T highTop()
        static force_inline TCA_N(HIGH_TOP_REG)::Type highTop() {
            return TCA_N(HIGH_TOP_REG)::getReg();
        }
    #endif

    /// #### static void lowCompareN(T value)

    /// #### static T lowCompareN()

    #if REG_DEFINED(TCA_N(COMPARE_0_REG))
        static force_inline void lowCompare0(TCA_N(LOW_COMPARE_0_REG)::Type value) {
            TCA_N(LOW_COMPARE_0_REG)::setReg(value);
        }

        static force_inline TCA_N(LOW_COMPARE_0_REG)::Type lowCompare0() {
            return TCA_N(LOW_COMPARE_0_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(TCA_N(LOW_COMPARE_1_REG))
        static force_inline void lowCompare1(TCA_N(LOW_COMPARE_1_REG)::Type value) {
            TCA_N(LOW_COMPARE_1_REG)::setReg(value);
        }

        static force_inline TCA_N(LOW_COMPARE_1_REG)::Type lowCompare1() {
            return TCA_N(LOW_COMPARE_1_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(TCA_N(LOW_COMPARE_2_REG))
        static force_inline void lowCompare2(TCA_N(LOW_COMPARE_2_REG)::Type value) {
            TCA_N(LOW_COMPARE_2_REG)::setReg(value);
        }

        static force_inline TCA_N(LOW_COMPARE_2_REG)::Type lowCompare2() {
            return TCA_N(LOW_COMPARE_2_REG)::getReg();
        }
    #endif

    /// #### static void highCompareN(T value)

    /// #### static T highCompareN()

    #if REG_DEFINED(TCA_N(HIGH_COMPARE_0_REG))
        static force_inline void highCompare0(TCA_N(HIGH_COMPARE_0_REG)::Type value) {
            TCA_N(HIGH_COMPARE_0_REG)::setReg(value);
        }

        static force_inline TCA_N(HIGH_COMPARE_0_REG)::Type highCompare0() {
            return TCA_N(HIGH_COMPARE_0_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(TCA_N(HIGH_COMPARE_1_REG))
        static force_inline void highCompare1(TCA_N(HIGH_COMPARE_1_REG)::Type value) {
            TCA_N(HIGH_COMPARE_1_REG)::setReg(value);
        }

        static force_inline TCA_N(HIGH_COMPARE_1_REG)::Type highCompare1() {
            return TCA_N(HIGH_COMPARE_1_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(TCA_N(HIGH_COMPARE_2_REG))
        static force_inline void highCompare2(TCA_N(HIGH_COMPARE_2_REG)::Type value) {
            TCA_N(HIGH_COMPARE_2_REG)::setReg(value);
        }

        static force_inline TCA_N(HIGH_COMPARE_2_REG)::Type highCompare2() {
            return TCA_N(HIGH_COMPARE_2_REG)::getReg();
        }
    #endif

    /// #### static void lowCompareNOutputEnable(bool)

    #if REG_DEFINED(TCA_N(LOW_COMPARE_0_OUTPUT_ENABLE_REG))
        static force_inline void lowCompare0OutputEnable(bool b) {
            TCA_N(LOW_COMPARE_0_OUTPUT_ENABLE_REG)::setBit(TCA_N(LOW_COMPARE_0_OUTPUT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TCA_N(LOW_COMPARE_1_OUTPUT_ENABLE_REG))
        static force_inline void lowCompare1OutputEnable(bool b) {
            TCA_N(LOW_COMPARE_1_OUTPUT_ENABLE_REG)::setBit(TCA_N(LOW_COMPARE_1_OUTPUT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TCA_N(LOW_COMPARE_2_OUTPUT_ENABLE_REG))
        static force_inline void lowCompare2OutputEnable(bool b) {
            TCA_N(LOW_COMPARE_2_OUTPUT_ENABLE_REG)::setBit(TCA_N(LOW_COMPARE_2_OUTPUT_ENABLE_BIT), b);
        }
    #endif

    /// #### static void highCompareNOutputEnable(bool)

    #if REG_DEFINED(TCA_N(HIGH_COMPARE_0_OUTPUT_ENABLE_REG))
        static force_inline void highCompare0OutputEnable(bool b) {
            TCA_N(HIGH_COMPARE_0_OUTPUT_ENABLE_REG)::setBit(TCA_N(HIGH_COMPARE_0_OUTPUT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TCA_N(HIGH_COMPARE_1_OUTPUT_ENABLE_REG))
        static force_inline void highCompare1OutputEnable(bool b) {
            TCA_N(HIGH_COMPARE_1_OUTPUT_ENABLE_REG)::setBit(TCA_N(HIGH_COMPARE_1_OUTPUT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TCA_N(HIGH_COMPARE_2_OUTPUT_ENABLE_REG))
        static force_inline void highCompare2OutputEnable(bool b) {
            TCA_N(HIGH_COMPARE_2_OUTPUT_ENABLE_REG)::setBit(TCA_N(HIGH_COMPARE_2_OUTPUT_ENABLE_BIT), b);
        }
    #endif

    /// #### static void lowCompareNIntEnable(bool)

    #if REG_DEFINED(TCA_N(LOW_COMPARE_0_INT_ENABLE_REG))
        static force_inline void lowCompare0IntEnable(bool b) {
            TCA_N(LOW_COMPARE_0_INT_ENABLE_REG)::setBit(TCA_N(LOW_COMPARE_0_INT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TCA_N(LOW_COMPARE_1_INT_ENABLE_REG))
        static force_inline void lowCompare1IntEnable(bool b) {
            TCA_N(LOW_COMPARE_1_INT_ENABLE_REG)::setBit(TCA_N(LOW_COMPARE_1_INT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TCA_N(LOW_COMPARE_2_INT_ENABLE_REG))
        static force_inline void lowCompare2IntEnable(bool b) {
            TCA_N(LOW_COMPARE_2_INT_ENABLE_REG)::setBit(TCA_N(LOW_COMPARE_2_INT_ENABLE_BIT), b);
        }
    #endif

    /// #### static bool lowCompareNIntFlag()

    /// #### static void lowCompareNIntFlagClear()

    #if REG_DEFINED(TCA_N(LOW_COMPARE_0_INT_FLAG_REG))
        static force_inline bool lowCompare0IntFlag() {
            return TCA_N(LOW_COMPARE_0_INT_FLAG_REG)::getBit(TCA_N(LOW_COMPARE_0_INT_FLAG_BIT));
        }

        static force_inline void lowCompare0IntFlagClear() {
            TCA_N(LOW_COMPARE_0_INT_FLAG_REG)::setBit(TCA_N(LOW_COMPARE_0_INT_FLAG_BIT), true);
        }
    #endif

    #if REG_DEFINED(TCA_N(LOW_COMPARE_1_INT_FLAG_REG))
        static force_inline bool lowCompare1IntFlag() {
            return TCA_N(LOW_COMPARE_1_INT_FLAG_REG)::getBit(TCA_N(LOW_COMPARE_1_INT_FLAG_BIT));
        }

        static force_inline void lowCompare1IntFlagClear() {
            TCA_N(LOW_COMPARE_1_INT_FLAG_REG)::setBit(TCA_N(LOW_COMPARE_1_INT_FLAG_BIT), true);
        }
    #endif

    #if REG_DEFINED(TCA_N(LOW_COMPARE_2_INT_FLAG_REG))
        static force_inline bool lowCompare2IntFlag() {
            return TCA_N(LOW_COMPARE_2_INT_FLAG_REG)::getBit(TCA_N(LOW_COMPARE_2_INT_FLAG_BIT));
        }

        static force_inline void lowCompare2IntFlagClear() {
            TCA_N(LOW_COMPARE_2_INT_FLAG_REG)::setBit(TCA_N(LOW_COMPARE_2_INT_FLAG_BIT), true);
        }
    #endif

    #if REG_DEFINED(TCA_N(LOW_UNDERFLOW_INT_ENABLE_REG))
        /// #### static void lowUnderflowIntEnable(bool)
        static force_inline void lowUnderflowIntEnable(bool b) {
            TCA_N(LOW_UNDERFLOW_INT_ENABLE_REG)::setBit(TCA_N(LOW_UNDERFLOW_INT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TCA_N(LOW_UNDERFLOW_INT_FLAG_REG))
        /// #### static bool lowUnderflowIntFlag()
        static force_inline bool lowUnderflowIntFlag() {
            return TCA_N(LOW_UNDERFLOW_INT_FLAG_REG)::getBit(TCA_N(LOW_UNDERFLOW_INT_FLAG_BIT));
        }

        /// #### static void lowUnderflowIntFlagClear()
        static force_inline void lowUnderflowIntFlagClear() {
            TCA_N(LOW_UNDERFLOW_INT_FLAG_REG)::setBit(TCA_N(LOW_UNDERFLOW_INT_FLAG_BIT), true);
        }
    #endif

    #if REG_DEFINED(TCA_N(HIGH_UNDERFLOW_INT_ENABLE_REG))
        /// #### static void highUnderflowIntEnable(bool)
        static force_inline void highUnderflowIntEnable(bool b) {
            TCA_N(HIGH_UNDERFLOW_INT_ENABLE_REG)::setBit(TCA_N(HIGH_UNDERFLOW_INT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TCA_N(HIGH_UNDERFLOW_INT_FLAG_REG))
        /// #### static bool highUnderflowIntFlag()
        static force_inline bool highUnderflowIntFlag() {
            return TCA_N(HIGH_UNDERFLOW_INT_FLAG_REG)::getBit(TCA_N(HIGH_UNDERFLOW_INT_FLAG_BIT));
        }

        /// #### static void highUnderflowIntFlagClear()
        static force_inline void highUnderflowIntFlagClear() {
            TCA_N(HIGH_UNDERFLOW_INT_FLAG_REG)::setBit(TCA_N(HIGH_UNDERFLOW_INT_FLAG_BIT), true);
        }
    #endif
};

#ifdef TEST

TEST(TcAN, getHardwareType) {
    ASSERT_EQ(TcAN::getHardwareType(), HardwareType::tcA);
}

#if REG_DEFINED(TCA_N(ENABLE_REG))
    TEST(TcAN, enable) {
        TEST_REG_WRITE(TcAN::enable(true));
        TEST_REG_WRITE(TcAN::enable(false));
    }
#endif

#if REG_DEFINED(TCA_N(COUNTER_REG))
    TEST(TcAN, counter) {
        TEST_REG_WRITE(TcAN::counter(0x12));
        TEST_REG_READ_WRITE(TcAN::counter());
    }
#endif

#if REG_DEFINED(TCA_N(TOP_REG))
    TEST(TcAN, top) {
        TEST_REG_WRITE(TcAN::top(0x12));
        TEST_REG_READ_WRITE(TcAN::top());
    }
#endif

#if REG_DEFINED(TCA_N(TOP_BUFFER_REG))
    TEST(TcAN, topBuffer) {
        TEST_REG_WRITE(TcAN::topBuffer(0x12));
        TEST_REG_READ_WRITE(TcAN::topBuffer());
    }
#endif

#if REG_DEFINED(TCA_N(CLOCK_REG))
    TEST(TcAN, clock) {
        #if DEFINED(TCA_N(CLOCK_1_ID))
            TEST_REG_WRITE(TcAN::clock(TcAN::Clock::div1));
        #endif

        #if DEFINED(TCA_N(CLOCK_2_ID))
            TEST_REG_WRITE(TcAN::clock(TcAN::Clock::div2));
        #endif

        #if DEFINED(TCA_N(CLOCK_4_ID))
            TEST_REG_WRITE(TcAN::clock(TcAN::Clock::div4));
        #endif

        #if DEFINED(TCA_N(CLOCK_8_ID))
            TEST_REG_WRITE(TcAN::clock(TcAN::Clock::div8));
        #endif

        #if DEFINED(TCA_N(CLOCK_16_ID))
            TEST_REG_WRITE(TcAN::clock(TcAN::Clock::div16));
        #endif

        #if DEFINED(TCA_N(CLOCK_64_ID))
            TEST_REG_WRITE(TcAN::clock(TcAN::Clock::div64));
        #endif

        #if DEFINED(TCA_N(CLOCK_256_ID))
            TEST_REG_WRITE(TcAN::clock(TcAN::Clock::div256));
        #endif

        #if DEFINED(TCA_N(CLOCK_1024_ID))
            TEST_REG_WRITE(TcAN::clock(TcAN::Clock::div1024));
        #endif
    }
#endif

#if REG_DEFINED(TCA_N(WAVEFORM_REG))
    TEST(TcAN, waveform) {
        #if DEFINED(TCA_N(WAVEFORM_NORMAL_ID))
            TEST_REG_WRITE(TcAN::waveform(TcAN::Waveform::normal));
        #endif

        #if DEFINED(TCA_N(WAVEFORM_FREQUENCY_ID))
            TEST_REG_WRITE(TcAN::waveform(TcAN::Waveform::frequency));
        #endif

        #if DEFINED(TCA_N(WAVEFORM_SINGLE_SLOPE_PWM_ID))
            TEST_REG_WRITE(TcAN::waveform(TcAN::Waveform::singleSlopePwm));
        #endif

        #if DEFINED(TCA_N(WAVEFORM_DUAL_SLOPE_PWM_OVF_TOP_ID))
            TEST_REG_WRITE(TcAN::waveform(TcAN::Waveform::dualSlopePwmOverflowTop));
        #endif

        #if DEFINED(TCA_N(WAVEFORM_DUAL_SLOPE_PWM_OVF_BOTTOM_ID))
            TEST_REG_WRITE(TcAN::waveform(TcAN::Waveform::dualSlopePwmOverflowBottom));
        #endif

        #if DEFINED(TCA_N(WAVEFORM_DUAL_SLOPE_PWM_OVF_BOTH_ID))
            TEST_REG_WRITE(TcAN::waveform(TcAN::Waveform::dualSlopePwmOverflowBoth));
        #endif
    }
#endif

#if REG_DEFINED(TCA_N(OVERFLOW_INT_ENABLE_REG))
    TEST(TcAN, overflowIntEnable) {
        TEST_REG_WRITE(TcAN::overflowIntEnable(true));
        TEST_REG_WRITE(TcAN::overflowIntEnable(false));
    }
#endif

#if REG_DEFINED(TCA_N(OVERFLOW_INT_FLAG_REG))
    TEST(TcAN, overflowIntFlag) {
        TEST_REG_READ_WRITE(TcAN::overflowIntFlag());
    }

    TEST(TcAN, overflowIntFlagClear) {
        TEST_REG_WRITE(TcAN::overflowIntFlagClear());
    }
#endif

#if REG_DEFINED(TCA_N(COMPARE_0_REG))
    TEST(TcAN, compare0) {
        TEST_REG_WRITE(TcAN::compare0(0x12));
        TEST_REG_READ_WRITE(TcAN::compare0());
    }
#endif

#if REG_DEFINED(TCA_N(COMPARE_1_REG))
    TEST(TcAN, compare1) {
        TEST_REG_WRITE(TcAN::compare1(0x12));
        TEST_REG_READ_WRITE(TcAN::compare1());
    }
#endif

#if REG_DEFINED(TCA_N(COMPARE_2_REG))
    TEST(TcAN, compare2) {
        TEST_REG_WRITE(TcAN::compare2(0x12));
        TEST_REG_READ_WRITE(TcAN::compare2());
    }
#endif

#if REG_DEFINED(TCA_N(COMPARE_0_BUFFER_REG))
    TEST(TcAN, compare0Buffer) {
        TEST_REG_WRITE(TcAN::compare0Buffer(0x12));
        TEST_REG_READ_WRITE(TcAN::compare0Buffer());
    }
#endif

#if REG_DEFINED(TCA_N(COMPARE_1_BUFFER_REG))
    TEST(TcAN, compare1Buffer) {
        TEST_REG_WRITE(TcAN::compare1Buffer(0x12));
        TEST_REG_READ_WRITE(TcAN::compare1Buffer());
    }
#endif

#if REG_DEFINED(TCA_N(COMPARE_2_BUFFER_REG))
    TEST(TcAN, compare2Buffer) {
        TEST_REG_WRITE(TcAN::compare2Buffer(0x12));
        TEST_REG_READ_WRITE(TcAN::compare2Buffer());
    }
#endif

#if REG_DEFINED(TCA_N(COMPARE_0_OUTPUT_ENABLE_REG))
    TEST(TcAN, compare0OutputEnable) {
        TEST_REG_WRITE(TcAN::compare0OutputEnable(true));
        TEST_REG_WRITE(TcAN::compare0OutputEnable(false));
    }
#endif

#if REG_DEFINED(TCA_N(COMPARE_1_OUTPUT_ENABLE_REG))
    TEST(TcAN, compare1OutputEnable) {
        TEST_REG_WRITE(TcAN::compare1OutputEnable(true));
        TEST_REG_WRITE(TcAN::compare1OutputEnable(false));
    }
#endif

#if REG_DEFINED(TCA_N(COMPARE_2_OUTPUT_ENABLE_REG))
    TEST(TcAN, compare2OutputEnable) {
        TEST_REG_WRITE(TcAN::compare2OutputEnable(true));
        TEST_REG_WRITE(TcAN::compare2OutputEnable(false));
    }
#endif

#if REG_DEFINED(TCA_N(COMPARE_0_INT_ENABLE_REG))
    TEST(TcAN, compare0IntEnable) {
        TEST_REG_WRITE(TcAN::compare0IntEnable(true));
        TEST_REG_WRITE(TcAN::compare0IntEnable(false));
    }
#endif

#if REG_DEFINED(TCA_N(COMPARE_1_INT_ENABLE_REG))
    TEST(TcAN, compare1IntEnable) {
        TEST_REG_WRITE(TcAN::compare1IntEnable(true));
        TEST_REG_WRITE(TcAN::compare1IntEnable(false));
    }
#endif

#if REG_DEFINED(TCA_N(COMPARE_2_INT_ENABLE_REG))
    TEST(TcAN, compare2IntEnable) {
        TEST_REG_WRITE(TcAN::compare2IntEnable(true));
        TEST_REG_WRITE(TcAN::compare2IntEnable(false));
    }
#endif

#if REG_DEFINED(TCA_N(COMPARE_0_INT_FLAG_REG))
    TEST(TcAN, compare0IntFlag) {
        TEST_REG_READ_WRITE(TcAN::compare0IntFlag());
    }

    TEST(TcAN, compare0IntFlagClear) {
        TEST_REG_WRITE(TcAN::compare0IntFlagClear());
    }
#endif

#if REG_DEFINED(TCA_N(COMPARE_1_INT_FLAG_REG))
    TEST(TcAN, compare1IntFlag) {
        TEST_REG_READ_WRITE(TcAN::compare1IntFlag());
    }

    TEST(TcAN, compare1IntFlagClear) {
        TEST_REG_WRITE(TcAN::compare1IntFlagClear());
    }
#endif

#if REG_DEFINED(TCA_N(COMPARE_2_INT_FLAG_REG))
    TEST(TcAN, compare2IntFlag) {
        TEST_REG_READ_WRITE(TcAN::compare2IntFlag());
    }

    TEST(TcAN, compare2IntFlagClear) {
        TEST_REG_WRITE(TcAN::compare2IntFlagClear());
    }
#endif

#if REG_DEFINED(TCA_N(SPLIT_MODE_ENABLE_REG))
    TEST(TcAN, splitModeEnable) {
        TEST_REG_WRITE(TcAN::splitModeEnable(true));
        TEST_REG_WRITE(TcAN::splitModeEnable(false));
    }
#endif

#if REG_DEFINED(TCA_N(LOW_COUNTER_REG))
    TEST(TcAN, lowCounter) {
        TEST_REG_WRITE(TcAN::lowCounter(0x12));
        TEST_REG_READ_WRITE(TcAN::lowCounter());
    }
#endif

#if REG_DEFINED(TCA_N(HIGH_COUNTER_REG))
    TEST(TcAN, highCounter) {
        TEST_REG_WRITE(TcAN::highCounter(0x12));
        TEST_REG_READ_WRITE(TcAN::highCounter());
    }
#endif

#if REG_DEFINED(TCA_N(LOW_TOP_REG))
    TEST(TcAN, lowTop) {
        TEST_REG_WRITE(TcAN::lowTop(0x12));
        TEST_REG_READ_WRITE(TcAN::lowTop());
    }
#endif

#if REG_DEFINED(TCA_N(HIGH_TOP_REG))
    TEST(TcAN, highTop) {
        TEST_REG_WRITE(TcAN::highTop(0x12));
        TEST_REG_READ_WRITE(TcAN::highTop());
    }
#endif

#if REG_DEFINED(TCA_N(COMPARE_0_REG))
    TEST(TcAN, lowCompare0) {
        TEST_REG_WRITE(TcAN::lowCompare0(0x12));
        TEST_REG_READ_WRITE(TcAN::lowCompare0());
    }
#endif

#if REG_DEFINED(TCA_N(LOW_COMPARE_1_REG))
    TEST(TcAN, lowCompare1) {
        TEST_REG_WRITE(TcAN::lowCompare1(0x12));
        TEST_REG_READ_WRITE(TcAN::lowCompare1());
    }
#endif

#if REG_DEFINED(TCA_N(LOW_COMPARE_2_REG))
    TEST(TcAN, lowCompare2) {
        TEST_REG_WRITE(TcAN::lowCompare2(0x12));
        TEST_REG_READ_WRITE(TcAN::lowCompare2());
    }
#endif

#if REG_DEFINED(TCA_N(HIGH_COMPARE_0_REG))
    TEST(TcAN, highCompare0) {
        TEST_REG_WRITE(TcAN::highCompare0(0x12));
        TEST_REG_READ_WRITE(TcAN::highCompare0());
    }
#endif

#if REG_DEFINED(TCA_N(HIGH_COMPARE_1_REG))
    TEST(TcAN, highCompare1) {
        TEST_REG_WRITE(TcAN::highCompare1(0x12));
        TEST_REG_READ_WRITE(TcAN::highCompare1());
    }
#endif

#if REG_DEFINED(TCA_N(HIGH_COMPARE_2_REG))
    TEST(TcAN, highCompare2) {
        TEST_REG_WRITE(TcAN::highCompare2(0x12));
        TEST_REG_READ_WRITE(TcAN::highCompare2());
    }
#endif

#if REG_DEFINED(TCA_N(LOW_COMPARE_0_OUTPUT_ENABLE_REG))
    TEST(TcAN, lowCompare0OutputEnable) {
        TEST_REG_WRITE(TcAN::lowCompare0OutputEnable(true));
        TEST_REG_WRITE(TcAN::lowCompare0OutputEnable(false));
    }
#endif

#if REG_DEFINED(TCA_N(LOW_COMPARE_1_OUTPUT_ENABLE_REG))
    TEST(TcAN, lowCompare1OutputEnable) {
        TEST_REG_WRITE(TcAN::lowCompare1OutputEnable(true));
        TEST_REG_WRITE(TcAN::lowCompare1OutputEnable(false));
    }
#endif

#if REG_DEFINED(TCA_N(LOW_COMPARE_2_OUTPUT_ENABLE_REG))
    TEST(TcAN, lowCompare2OutputEnable) {
        TEST_REG_WRITE(TcAN::lowCompare2OutputEnable(true));
        TEST_REG_WRITE(TcAN::lowCompare2OutputEnable(false));
    }
#endif

#if REG_DEFINED(TCA_N(HIGH_COMPARE_0_OUTPUT_ENABLE_REG))
    TEST(TcAN, highCompare0OutputEnable) {
        TEST_REG_WRITE(TcAN::highCompare0OutputEnable(true));
        TEST_REG_WRITE(TcAN::highCompare0OutputEnable(false));
    }
#endif

#if REG_DEFINED(TCA_N(HIGH_COMPARE_1_OUTPUT_ENABLE_REG))
    TEST(TcAN, highCompare1OutputEnable) {
        TEST_REG_WRITE(TcAN::highCompare1OutputEnable(true));
        TEST_REG_WRITE(TcAN::highCompare1OutputEnable(false));
    }
#endif

#if REG_DEFINED(TCA_N(HIGH_COMPARE_2_OUTPUT_ENABLE_REG))
    TEST(TcAN, highCompare2OutputEnable) {
        TEST_REG_WRITE(TcAN::highCompare2OutputEnable(true));
        TEST_REG_WRITE(TcAN::highCompare2OutputEnable(false));
    }
#endif

#if REG_DEFINED(TCA_N(LOW_COMPARE_0_INT_ENABLE_REG))
    TEST(TcAN, lowCompare0IntEnable) {
        TEST_REG_WRITE(TcAN::lowCompare0IntEnable(true));
        TEST_REG_WRITE(TcAN::lowCompare0IntEnable(false));
    }
#endif

#if REG_DEFINED(TCA_N(LOW_COMPARE_1_INT_ENABLE_REG))
    TEST(TcAN, lowCompare1IntEnable) {
        TEST_REG_WRITE(TcAN::lowCompare1IntEnable(true));
        TEST_REG_WRITE(TcAN::lowCompare1IntEnable(false));
    }
#endif

#if REG_DEFINED(TCA_N(LOW_COMPARE_2_INT_ENABLE_REG))
    TEST(TcAN, lowCompare2IntEnable) {
        TEST_REG_WRITE(TcAN::lowCompare2IntEnable(true));
        TEST_REG_WRITE(TcAN::lowCompare2IntEnable(false));
    }
#endif

#if REG_DEFINED(TCA_N(LOW_COMPARE_0_INT_FLAG_REG))
    TEST(TcAN, lowCompare0IntFlag) {
        TEST_REG_READ_WRITE(TcAN::lowCompare0IntFlag());
        TEST_REG_WRITE(TcAN::lowCompare0IntFlagClear());
    }
#endif

#if REG_DEFINED(TCA_N(LOW_COMPARE_1_INT_FLAG_REG))
    TEST(TcAN, lowCompare1IntFlag) {
        TEST_REG_READ_WRITE(TcAN::lowCompare1IntFlag());
        TEST_REG_WRITE(TcAN::lowCompare1IntFlagClear());
    }
#endif

#if REG_DEFINED(TCA_N(LOW_COMPARE_2_INT_FLAG_REG))
    TEST(TcAN, lowCompare2IntFlag) {
        TEST_REG_READ_WRITE(TcAN::lowCompare2IntFlag());
        TEST_REG_WRITE(TcAN::lowCompare2IntFlagClear());
    }
#endif

#if REG_DEFINED(TCA_N(LOW_UNDERFLOW_INT_ENABLE_REG))
    TEST(TcAN, lowUnderflowIntEnable) {
        TEST_REG_WRITE(TcAN::lowUnderflowIntEnable(true));
        TEST_REG_WRITE(TcAN::lowUnderflowIntEnable(false));
    }
#endif

#if REG_DEFINED(TCA_N(LOW_UNDERFLOW_INT_FLAG_REG))
    TEST(TcAN, lowUnderflowIntFlag) {
        TEST_REG_READ_WRITE(TcAN::lowUnderflowIntFlag());
        TEST_REG_WRITE(TcAN::lowUnderflowIntFlagClear());
    }
#endif

#if REG_DEFINED(TCA_N(HIGH_UNDERFLOW_INT_ENABLE_REG))
    TEST(TcAN, highUnderflowIntEnable) {
        TEST_REG_WRITE(TcAN::highUnderflowIntEnable(true));
        TEST_REG_WRITE(TcAN::highUnderflowIntEnable(false));
    }
#endif

#if REG_DEFINED(TCA_N(HIGH_UNDERFLOW_INT_FLAG_REG))
    TEST(TcAN, highUnderflowIntFlag) {
        TEST_REG_READ_WRITE(TcAN::highUnderflowIntFlag());
        TEST_REG_WRITE(TcAN::highUnderflowIntFlagClear());
    }
#endif

#endif // TEST

} // nblib::hw

//--------------------------------------------------------

    #endif

    #undef N
    #undef TcAN
    #undef TCA_N

    #include "tca.hpp"
#else
    #define NBLIB_TCA_HPP
#endif

#endif
