/// [[Index]]

/// # {{Timers}}

#ifndef NBLIB_TIMER_HPP

#include "isr.hpp"
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
    #define TimerN CAT(Timer, N)
    #define TIMER_N(A) CAT(CHIP_TIMER_, N, _, A)

    #if DEFINED(CAT(CHIP_TIMER_, N))

//--------------------------------------------------------

namespace nblib::hw {

/// ## Class {{TimerN}}
struct TimerN {
    TimerN() = delete;
    TimerN& operator=(const TimerN&) = delete;
    TimerN(const TimerN&) = delete;

    /// #### enum {{TimerN::Clock}}
    /// * none
    /// * div1
    /// * div2
    /// * div4
    /// * div8
    /// * div16
    /// * div32
    /// * div64
    /// * div128
    /// * div256
    /// * div512
    /// * div1024
    /// * div2048
    /// * div4096
    /// * div8192
    /// * div16384
    /// * extFalling
    /// * extRising
    enum class Clock {
        #if DEFINED(TIMER_N(CLOCK_NONE_ID))
            none = TIMER_N(CLOCK_NONE_ID),
        #endif

        #if DEFINED(TIMER_N(CLOCK_1_ID))
            div1 = TIMER_N(CLOCK_1_ID),
        #endif

        #if DEFINED(TIMER_N(CLOCK_2_ID))
            div2 = TIMER_N(CLOCK_2_ID),
        #endif

        #if DEFINED(TIMER_N(CLOCK_4_ID))
            div4 = TIMER_N(CLOCK_4_ID),
        #endif

        #if DEFINED(TIMER_N(CLOCK_8_ID))
            div8 = TIMER_N(CLOCK_8_ID),
        #endif

        #if DEFINED(TIMER_N(CLOCK_16_ID))
            div16 = TIMER_N(CLOCK_16_ID),
        #endif

        #if TIMER_N(CLOCK_32_ID)
            div32 = TIMER_N(CLOCK_32_ID),
        #endif

        #if TIMER_N(CLOCK_64_ID)
            div64 = TIMER_N(CLOCK_64_ID),
        #endif

        #if TIMER_N(CLOCK_128_ID)
            div128 = TIMER_N(CLOCK_128_ID),
        #endif

        #if TIMER_N(CLOCK_256_ID)
            div256 = TIMER_N(CLOCK_256_ID),
        #endif

        #if DEFINED(TIMER_N(CLOCK_512_ID))
            div512 = TIMER_N(CLOCK_512_ID),
        #endif

        #if DEFINED(TIMER_N(CLOCK_1024_ID))
            div1024 = TIMER_N(CLOCK_1024_ID),
        #endif

        #if DEFINED(TIMER_N(CLOCK_2048_ID))
            div2048 = TIMER_N(CLOCK_2048_ID),
        #endif

        #if DEFINED(TIMER_N(CLOCK_4096_ID))
            div4096 = TIMER_N(CLOCK_4096_ID),
        #endif

        #if DEFINED(TIMER_N(CLOCK_8192_ID))
            div8192 = TIMER_N(CLOCK_8192_ID),
        #endif

        #if DEFINED(TIMER_N(CLOCK_16384_ID))
            div16384 = TIMER_N(CLOCK_16384_ID),
        #endif

        #if TIMER_N(CLOCK_EXT_FALLING_ID)
            extFalling = TIMER_N(CLOCK_EXT_FALLING_ID),
        #endif

        #if TIMER_N(CLOCK_EXT_RISING_ID)
            extRising = TIMER_N(CLOCK_EXT_RISING_ID),
        #endif
    };

    /// #### enum {{TimerN::Waveform}}
    /// * normal
    /// * pwm
    /// * ctcOcra
    /// * fastPwm
    /// * pwmOcra
    /// * fastPwmOcra
    /// * frequency
    /// * singleSlopePwm
    /// * dualSlopePwmOverflowTop
    /// * dualSlopePwmOverflowBottom
    /// * dualSlopePwmOverflowBoth
    enum class Waveform {
        #if DEFINED(TIMER_N(WAVEFORM_NORMAL_ID))
            normal = TIMER_N(WAVEFORM_NORMAL_ID),
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_PWM_PHASE_CORRECT_ID))
            pwm = TIMER_N(WAVEFORM_PWM_PHASE_CORRECT_ID),
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_PWM_PHASE_CORRECT_8_ID))
            pwm8Bit = TIMER_N(WAVEFORM_PWM_PHASE_CORRECT_8_ID),
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_PWM_PHASE_CORRECT_9_ID))
            pwm9Bit = TIMER_N(WAVEFORM_PWM_PHASE_CORRECT_9_ID),
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_PWM_PHASE_CORRECT_10_ID))
            pwm10Bit = TIMER_N(WAVEFORM_PWM_PHASE_CORRECT_10_ID),
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_CTC_OCRA_ID))
            ctcOcra = TIMER_N(WAVEFORM_CTC_OCRA_ID),
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_CTC_OCRC_ID))
            ctcOcrc = TIMER_N(WAVEFORM_CTC_OCRC_ID),
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_CTC_ICR_ID))
            ctcIcr = TIMER_N(WAVEFORM_CTC_ICR_ID),
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_FAST_PWM_8_ID))
            fastPwm8Bit = TIMER_N(WAVEFORM_FAST_PWM_8_ID),
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_FAST_PWM_9_ID))
            fastPwm9Bit = TIMER_N(WAVEFORM_FAST_PWM_9_ID),
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_FAST_PWM_10_ID))
            fastPwm10Bit = TIMER_N(WAVEFORM_FAST_PWM_10_ID),
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_FAST_PWM_ID))
            fastPwm = TIMER_N(WAVEFORM_FAST_PWM_ID),
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID))
            pwmOcra = TIMER_N(WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID),
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_FAST_PWM_OCRA_ID))
            fastPwmOcra = TIMER_N(WAVEFORM_FAST_PWM_OCRA_ID),
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_FAST_PWM_OCRC_ID))
            fastPwmOcrc = TIMER_N(WAVEFORM_FAST_PWM_OCRC_ID),
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_FAST_PWM_A_OCRC_ID))
            fastPwmAOcrc = TIMER_N(WAVEFORM_FAST_PWM_A_OCRC_ID),
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_FAST_PWM_B_OCRC_ID))
            fastPwmBOcrc = TIMER_N(WAVEFORM_FAST_PWM_B_OCRC_ID),
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_FAST_PWM_A_B_OCRC_ID))
            fastPwmABOcrc = TIMER_N(WAVEFORM_FAST_PWM_A_B_OCRC_ID),
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_FREQUENCY_ID))
            frequency = TIMER_N(WAVEFORM_FREQUENCY_ID),
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_SINGLE_SLOPE_PWM_ID))
            singleSlopePwm = TIMER_N(WAVEFORM_SINGLE_SLOPE_PWM_ID),
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_DUAL_SLOPE_PWM_OVF_TOP_ID))
            dualSlopePwmOverflowTop = TIMER_N(WAVEFORM_DUAL_SLOPE_PWM_OVF_TOP_ID),
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_DUAL_SLOPE_PWM_OVF_BOTTOM_ID))
            dualSlopePwmOverflowBottom = TIMER_N(WAVEFORM_DUAL_SLOPE_PWM_OVF_BOTTOM_ID),
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_DUAL_SLOPE_PWM_OVF_BOTH_ID))
            dualSlopePwmOverflowBoth = TIMER_N(WAVEFORM_DUAL_SLOPE_PWM_OVF_BOTH_ID),
        #endif
    };

    /// #### enum {{TimerN::CompareXOutput}}
    /// * disconnected
    /// * toggle
    /// * clear
    /// * set
    #if REG_DEFINED(TIMER_N(COMPARE_A_OUTPUT_REG))
        enum class CompareAOutput {
            #if DEFINED(TIMER_N(COMPARE_A_OUTPUT_DISCONNECTED_ID))
                disconnected = TIMER_N(COMPARE_A_OUTPUT_DISCONNECTED_ID),
            #endif

            #if DEFINED(TIMER_N(COMPARE_A_OUTPUT_TOGGLE_ID))
                toggle = TIMER_N(COMPARE_A_OUTPUT_TOGGLE_ID),
            #endif

            #if DEFINED(TIMER_N(COMPARE_A_OUTPUT_CLEAR_ID))
                clear = TIMER_N(COMPARE_A_OUTPUT_CLEAR_ID),
            #endif

            #if DEFINED(TIMER_N(COMPARE_A_OUTPUT_SET_ID))
                set = TIMER_N(COMPARE_A_OUTPUT_SET_ID),
            #endif
        };
    #endif

    #if REG_DEFINED(TIMER_N(COMPARE_B_OUTPUT_REG))
        enum class CompareBOutput {
            #if DEFINED(TIMER_N(COMPARE_B_OUTPUT_DISCONNECTED_ID))
                disconnected = TIMER_N(COMPARE_B_OUTPUT_DISCONNECTED_ID),
            #endif

            #if DEFINED(TIMER_N(COMPARE_B_OUTPUT_TOGGLE_ID))
                toggle = TIMER_N(COMPARE_B_OUTPUT_TOGGLE_ID),
            #endif

            #if DEFINED(TIMER_N(COMPARE_B_OUTPUT_CLEAR_ID))
                clear = TIMER_N(COMPARE_B_OUTPUT_CLEAR_ID),
            #endif

            #if DEFINED(TIMER_N(COMPARE_B_OUTPUT_SET_ID))
                set = TIMER_N(COMPARE_B_OUTPUT_SET_ID),
            #endif
        };
    #endif

    #if REG_DEFINED(TIMER_N(COMPARE_C_OUTPUT_REG))
        enum class CompareCOutput {
            #if DEFINED(TIMER_N(COMPARE_C_OUTPUT_DISCONNECTED_ID))
                disconnected = TIMER_N(COMPARE_C_OUTPUT_DISCONNECTED_ID),
            #endif

            #if DEFINED(TIMER_N(COMPARE_C_OUTPUT_TOGGLE_ID))
                toggle = TIMER_N(COMPARE_C_OUTPUT_TOGGLE_ID),
            #endif

            #if DEFINED(TIMER_N(COMPARE_C_OUTPUT_CLEAR_ID))
                clear = TIMER_N(COMPARE_C_OUTPUT_CLEAR_ID),
            #endif

            #if DEFINED(TIMER_N(COMPARE_C_OUTPUT_SET_ID))
                set = TIMER_N(COMPARE_C_OUTPUT_SET_ID),
            #endif
        };
    #endif

    #if REG_DEFINED(TIMER_N(CAPTURE_REG))
        /// #### enum {{TimerN::CaptureEdge}}
        /// * rising
        /// * falling
        enum class CaptureEdge {
            rising = TIMER_N(CAPTURE_EDGE_RISING_ID),
            falling = TIMER_N(CAPTURE_EDGE_FALLING_ID),
        };
    #endif

    /// #### static [[HardwareType]] getHardwareType()
    static constexpr HardwareType getHardwareType() {
        return HardwareType::timer;
    }

    #if REG_DEFINED(TIMER_N(COUNTER_REG))
        /// #### static void counter(T value)
        static force_inline void counter(TIMER_N(COUNTER_REG)::Type value) {
            TIMER_N(COUNTER_REG)::setReg(value);
        }

        /// #### static T counter()
        static force_inline TIMER_N(COUNTER_REG)::Type counter() {
            return TIMER_N(COUNTER_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(TIMER_N(ENABLE_REG))
        /// #### static void enable(bool)
        static force_inline void enable(bool b) {
            TIMER_N(ENABLE_REG)::setBit(TIMER_N(ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TIMER_N(TOP_REG))
        /// #### static void top(T value)
        static force_inline void top(TIMER_N(TOP_REG)::Type value) {
            TIMER_N(TOP_REG)::setReg(value);
        }

        /// #### static T top()
        static force_inline TIMER_N(TOP_REG)::Type top() {
            return TIMER_N(TOP_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(TIMER_N(CLOCK_REG))
        /// #### static void clock([[TimerN::Clock]] c)
        static force_inline void clock(Clock c) {
            TIMER_N(CLOCK_REG)::setBits(TIMER_N(CLOCK_MASK), c);
        }
    #endif

    #if REG_DEFINED(TIMER_N(WAVEFORM_REG))
        /// #### static void waveform([[TimerN::Waveform]] w)
        static force_inline void waveform(Waveform w) {
            TIMER_N(WAVEFORM_REG)::setBits(TIMER_N(WAVEFORM_MASK), w);

            #if REG_DEFINED(TIMER_N(WAVEFORM_REG_EXTRA))
                TIMER_N(WAVEFORM_REG_EXTRA)::setBits(TIMER_N(WAVEFORM_MASK_EXTRA), uint(w) >> 8);
            #endif
        }
    #endif

    #if REG_DEFINED(TIMER_N(OVERFLOW_INT_ENABLE_REG))
        /// #### static void overflowIntEnable(bool)
        static force_inline void overflowIntEnable(bool b) {
            TIMER_N(OVERFLOW_INT_ENABLE_REG)::setBit(TIMER_N(OVERFLOW_INT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TIMER_N(OVERFLOW_INT_FLAG_REG))
        /// #### static bool overflowIntFlag()
        static force_inline bool overflowIntFlag() {
            return TIMER_N(OVERFLOW_INT_FLAG_REG)::getBit(TIMER_N(OVERFLOW_INT_FLAG_BIT));
        }

        /// #### static void overflowIntFlagClear()
        static force_inline void overflowIntFlagClear() {
            TIMER_N(OVERFLOW_INT_FLAG_REG)::setBit(TIMER_N(OVERFLOW_INT_FLAG_BIT), true);
        }
    #endif

    #if REG_DEFINED(TIMER_N(PRESCALER_RESET_REG))
        /// #### static void prescalerReset()
        /// Resets the *shared* timer prescaler to zero.
        static force_inline void prescalerReset() {
            TIMER_N(PRESCALER_RESET_REG)::setBit(TIMER_N(PRESCALER_RESET_BIT), true);
        }
    #endif

    #if REG_DEFINED(TIMER_N(SYNCHRONIZE_REG))
        /// #### static void synchronizeMode(bool b)
        /// Set to true then call prescalerReset() to hold the timers' prescalers at zero, effectively pausing the timers.
        /// Set back to false to start all timers at exactly the same time.
        static force_inline void synchronizeMode(bool b) {
            TIMER_N(SYNCHRONIZE_REG)::setBit(TIMER_N(SYNCHRONIZE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TIMER_N(COMPARE_A_REG))
        /// #### static void compareA(T value)
        static force_inline void compareA(TIMER_N(COMPARE_A_REG)::Type value) {
            TIMER_N(COMPARE_A_REG)::setReg(value);
        }

        /// #### static T compareA()
        static force_inline TIMER_N(COMPARE_A_REG)::Type compareA() {
            return TIMER_N(COMPARE_A_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(TIMER_N(COMPARE_B_REG))
        /// #### static void compareB(T value)
        static force_inline void compareB(TIMER_N(COMPARE_B_REG)::Type value) {
            TIMER_N(COMPARE_B_REG)::setReg(value);
        }

        /// #### static T compareB()
        static force_inline TIMER_N(COMPARE_B_REG)::Type compareB() {
            return TIMER_N(COMPARE_B_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(TIMER_N(COMPARE_C_REG))
        /// #### static void compareC(T value)
        static force_inline void compareC(TIMER_N(COMPARE_C_REG)::Type value) {
            TIMER_N(COMPARE_C_REG)::setReg(value);
        }

        /// #### static T compareC()
        static force_inline TIMER_N(COMPARE_C_REG)::Type compareC() {
            return TIMER_N(COMPARE_C_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(TIMER_N(COMPARE_A_OUTPUT_ENABLE_REG))
        /// #### static void compareAOutputEnable(bool)
        static force_inline void compareAOutputEnable(bool b) {
            TIMER_N(COMPARE_A_OUTPUT_ENABLE_REG)::setBit(TIMER_N(COMPARE_A_OUTPUT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TIMER_N(COMPARE_B_OUTPUT_ENABLE_REG))
        /// #### static void compareBOutputEnable(bool)
        static force_inline void compareBOutputEnable(bool b) {
            TIMER_N(COMPARE_B_OUTPUT_ENABLE_REG)::setBit(TIMER_N(COMPARE_B_OUTPUT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TIMER_N(COMPARE_C_OUTPUT_ENABLE_REG))
        /// #### static void compareCOutputEnable(bool)
        static force_inline void compareCOutputEnable(bool b) {
            TIMER_N(COMPARE_C_OUTPUT_ENABLE_REG)::setBit(TIMER_N(COMPARE_C_OUTPUT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TIMER_N(COMPARE_A_PWM_OUTPUT_ENABLE_REG))
        /// #### static void compareAPwmOutputEnable(bool)
        static force_inline void compareAPwmOutputEnable(bool b) {
            TIMER_N(COMPARE_A_PWM_OUTPUT_ENABLE_REG)::setBit(TIMER_N(COMPARE_A_PWM_OUTPUT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TIMER_N(COMPARE_B_PWM_OUTPUT_ENABLE_REG))
        /// #### static void compareBPwmOutputEnable(bool)
        static force_inline void compareBPwmOutputEnable(bool b) {
            TIMER_N(COMPARE_B_PWM_OUTPUT_ENABLE_REG)::setBit(TIMER_N(COMPARE_B_PWM_OUTPUT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TIMER_N(COMPARE_C_PWM_OUTPUT_ENABLE_REG))
        /// #### static void compareCPwmOutputEnable(bool)
        static force_inline void compareCPwmOutputEnable(bool b) {
            TIMER_N(COMPARE_C_PWM_OUTPUT_ENABLE_REG)::setBit(TIMER_N(COMPARE_C_PWM_OUTPUT_ENABLE_BIT), b);
        }
    #endif

    /// #### static void compareXOutput(CompareXOutput)

    #if REG_DEFINED(TIMER_N(COMPARE_A_OUTPUT_REG))
        static force_inline void compareAOutput(CompareAOutput o) {
            TIMER_N(COMPARE_A_OUTPUT_REG)::setBits(TIMER_N(COMPARE_A_OUTPUT_MASK), o);
        }
    #endif

    #if REG_DEFINED(TIMER_N(COMPARE_B_OUTPUT_REG))
        static force_inline void compareBOutput(CompareBOutput o) {
            TIMER_N(COMPARE_B_OUTPUT_REG)::setBits(TIMER_N(COMPARE_B_OUTPUT_MASK), o);
        }
    #endif

    #if REG_DEFINED(TIMER_N(COMPARE_C_OUTPUT_REG))
        static force_inline void compareCOutput(CompareCOutput o) {
            TIMER_N(COMPARE_C_OUTPUT_REG)::setBits(TIMER_N(COMPARE_C_OUTPUT_MASK), o);
        }
    #endif

    /// #### static void compareXIntEnable(bool)

    #if REG_DEFINED(TIMER_N(COMPARE_A_INT_ENABLE_REG))
        static force_inline void compareAIntEnable(bool b) {
            TIMER_N(COMPARE_A_INT_ENABLE_REG)::setBit(TIMER_N(COMPARE_A_INT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TIMER_N(COMPARE_B_INT_ENABLE_REG))
        static force_inline void compareBIntEnable(bool b) {
            TIMER_N(COMPARE_B_INT_ENABLE_REG)::setBit(TIMER_N(COMPARE_B_INT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TIMER_N(COMPARE_C_INT_ENABLE_REG))
        static force_inline void compareCIntEnable(bool b) {
            TIMER_N(COMPARE_C_INT_ENABLE_REG)::setBit(TIMER_N(COMPARE_C_INT_ENABLE_BIT), b);
        }
    #endif

    /// #### static bool compareXIntFlag()

    /// #### static void compareXIntFlagClear\(\)

    #if REG_DEFINED(TIMER_N(COMPARE_A_INT_FLAG_REG))
        static force_inline bool compareAIntFlag() {
            return TIMER_N(COMPARE_A_INT_FLAG_REG)::getBit(TIMER_N(COMPARE_A_INT_FLAG_BIT));
        }

        static force_inline void compareAIntFlagClear() {
            TIMER_N(COMPARE_A_INT_FLAG_REG)::setBit(TIMER_N(COMPARE_A_INT_FLAG_BIT), true);
        }
    #endif

    #if REG_DEFINED(TIMER_N(COMPARE_B_INT_FLAG_REG))
        static force_inline bool compareBIntFlag() {
            return TIMER_N(COMPARE_B_INT_FLAG_REG)::getBit(TIMER_N(COMPARE_B_INT_FLAG_BIT));
        }

        static force_inline void compareBIntFlagClear() {
            TIMER_N(COMPARE_B_INT_FLAG_REG)::setBit(TIMER_N(COMPARE_B_INT_FLAG_BIT), true);
        }
    #endif

    #if REG_DEFINED(TIMER_N(COMPARE_C_INT_FLAG_REG))
        static force_inline bool compareCIntFlag() {
            return TIMER_N(COMPARE_C_INT_FLAG_REG)::getBit(TIMER_N(COMPARE_C_INT_FLAG_BIT));
        }

        static force_inline void compareCIntFlagClear() {
            TIMER_N(COMPARE_C_INT_FLAG_REG)::setBit(TIMER_N(COMPARE_C_INT_FLAG_BIT), true);
        }
    #endif

    #if REG_DEFINED(TIMER_N(CAPTURE_REG))
        /// #### static void capture(T)
        static force_inline void capture(TIMER_N(CAPTURE_REG)::Type t) {
            TIMER_N(CAPTURE_REG)::setReg(t);
        }

        /// #### static T capture()
        static force_inline TIMER_N(CAPTURE_REG)::Type capture() {
            return TIMER_N(CAPTURE_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(TIMER_N(CAPTURE_REG))
        /// #### static void captureEdge([[TimerN::CaptureEdge]])
        static force_inline void captureEdge(CaptureEdge e) {
            TIMER_N(CAPTURE_EDGE_REG)::setBits(TIMER_N(CAPTURE_EDGE_MASK), e);
        }
    #endif

    #if REG_DEFINED(TIMER_N(CAPTURE_NOISE_CANCEL_ENABLE_REG))
        /// #### static void captureNoiseCancelEnable(bool)
        static force_inline void captureNoiseCancelEnable(bool b) {
            TIMER_N(CAPTURE_NOISE_CANCEL_ENABLE_REG)::setBit(TIMER_N(CAPTURE_NOISE_CANCEL_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TIMER_N(CAPTURE_INT_ENABLE_REG))
        /// #### static void captureIntEnable(bool)
        static force_inline void captureIntEnable(bool b) {
            TIMER_N(CAPTURE_INT_ENABLE_REG)::setBit(TIMER_N(CAPTURE_INT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TIMER_N(CAPTURE_INT_FLAG_REG))
        /// #### static bool captureIntFlag()
        static force_inline bool captureIntFlag() {
            return TIMER_N(CAPTURE_INT_FLAG_REG)::getBit(TIMER_N(CAPTURE_INT_FLAG_BIT));
        }

        /// #### static void captureIntFlagClear()
        static force_inline void captureIntFlagClear() {
            TIMER_N(CAPTURE_INT_FLAG_REG)::setBit(TIMER_N(CAPTURE_INT_FLAG_BIT), true);
        }
    #endif
};

#ifdef TEST

TEST(TimerN, getHardwareType) {
    ASSERT_EQ(TimerN::getHardwareType(), HardwareType::timer);
}

#if REG_DEFINED(TIMER_N(COUNTER_REG))
    TEST(TimerN, counter) {
        TEST_REG_WRITE(TimerN::counter(0x12));
        TEST_REG_READ_WRITE(TimerN::counter());
    }
#endif

#if REG_DEFINED(TIMER_N(CLOCK_REG))
    TEST(TimerN, clock) {
        #if DEFINED(TIMER_N(CLOCK_NONE_ID))
            TEST_REG_WRITE(TimerN::clock(TimerN::Clock::none));
        #endif

        #if DEFINED(TIMER_N(CLOCK_1_ID))
            TEST_REG_WRITE(TimerN::clock(TimerN::Clock::div1));
        #endif

        #if DEFINED(TIMER_N(CLOCK_2_ID))
            TEST_REG_WRITE(TimerN::clock(TimerN::Clock::div2));
        #endif

        #if DEFINED(TIMER_N(CLOCK_4_ID))
            TEST_REG_WRITE(TimerN::clock(TimerN::Clock::div4));
        #endif

        #if DEFINED(TIMER_N(CLOCK_8_ID))
            TEST_REG_WRITE(TimerN::clock(TimerN::Clock::div8));
        #endif

        #if DEFINED(TIMER_N(CLOCK_16_ID))
            TEST_REG_WRITE(TimerN::clock(TimerN::Clock::div16));
        #endif

        #if TIMER_N(CLOCK_32_ID)
            TEST_REG_WRITE(TimerN::clock(TimerN::Clock::div32));
        #endif

        #if TIMER_N(CLOCK_64_ID)
            TEST_REG_WRITE(TimerN::clock(TimerN::Clock::div64));
        #endif

        #if TIMER_N(CLOCK_128_ID)
            TEST_REG_WRITE(TimerN::clock(TimerN::Clock::div128));
        #endif

        #if TIMER_N(CLOCK_256_ID)
            TEST_REG_WRITE(TimerN::clock(TimerN::Clock::div256));
        #endif

        #if DEFINED(TIMER_N(CLOCK_512_ID))
            TEST_REG_WRITE(TimerN::clock(TimerN::Clock::div512));
        #endif

        #if DEFINED(TIMER_N(CLOCK_1024_ID))
            TEST_REG_WRITE(TimerN::clock(TimerN::Clock::div1024));
        #endif

        #if DEFINED(TIMER_N(CLOCK_2048_ID))
            TEST_REG_WRITE(TimerN::clock(TimerN::Clock::div2048));
        #endif

        #if DEFINED(TIMER_N(CLOCK_4096_ID))
            TEST_REG_WRITE(TimerN::clock(TimerN::Clock::div4096));
        #endif

        #if DEFINED(TIMER_N(CLOCK_8192_ID))
            TEST_REG_WRITE(TimerN::clock(TimerN::Clock::div8192));
        #endif

        #if DEFINED(TIMER_N(CLOCK_16384_ID))
            TEST_REG_WRITE(TimerN::clock(TimerN::Clock::div16384));
        #endif

        #if TIMER_N(CLOCK_EXT_FALLING_ID)
            TEST_REG_WRITE(TimerN::clock(TimerN::Clock::extFalling));
        #endif

        #if TIMER_N(CLOCK_EXT_RISING_ID)
            TEST_REG_WRITE(TimerN::clock(TimerN::Clock::extRising));
        #endif
    }
#endif

#if REG_DEFINED(TIMER_N(WAVEFORM_REG))
    TEST(TimerN, waveform) {
        #if DEFINED(TIMER_N(WAVEFORM_NORMAL_ID))
            TEST_REG_WRITE(TimerN::waveform(TimerN::Waveform::normal));
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_PWM_PHASE_CORRECT_ID))
            TEST_REG_WRITE(TimerN::waveform(TimerN::Waveform::pwm));
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_PWM_PHASE_CORRECT_8_ID))
            TEST_REG_WRITE(TimerN::waveform(TimerN::Waveform::pwm8Bit));
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_PWM_PHASE_CORRECT_9_ID))
            TEST_REG_WRITE(TimerN::waveform(TimerN::Waveform::pwm9Bit));
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_PWM_PHASE_CORRECT_10_ID))
            TEST_REG_WRITE(TimerN::waveform(TimerN::Waveform::pwm10Bit));
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_CTC_OCRA_ID))
            TEST_REG_WRITE(TimerN::waveform(TimerN::Waveform::ctcOcra));
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_CTC_OCRC_ID))
            TEST_REG_WRITE(TimerN::waveform(TimerN::Waveform::ctcOcrc));
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_CTC_ICR_ID))
            TEST_REG_WRITE(TimerN::waveform(TimerN::Waveform::ctcIcr));
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_FAST_PWM_8_ID))
            TEST_REG_WRITE(TimerN::waveform(TimerN::Waveform::fastPwm8Bit));
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_FAST_PWM_9_ID))
            TEST_REG_WRITE(TimerN::waveform(TimerN::Waveform::fastPwm9Bit));
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_FAST_PWM_10_ID))
            TEST_REG_WRITE(TimerN::waveform(TimerN::Waveform::fastPwm10Bit));
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_FAST_PWM_ID))
            TEST_REG_WRITE(TimerN::waveform(TimerN::Waveform::fastPwm));
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID))
            TEST_REG_WRITE(TimerN::waveform(TimerN::Waveform::pwmOcra));
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_FAST_PWM_OCRA_ID))
            TEST_REG_WRITE(TimerN::waveform(TimerN::Waveform::fastPwmOcra));
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_FAST_PWM_OCRC_ID))
            TEST_REG_WRITE(TimerN::waveform(TimerN::Waveform::fastPwmOcrc));
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_FAST_PWM_A_OCRC_ID))
            TEST_REG_WRITE(TimerN::waveform(TimerN::Waveform::fastPwmAOcrc));
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_FAST_PWM_B_OCRC_ID))
            TEST_REG_WRITE(TimerN::waveform(TimerN::Waveform::fastPwmBOcrc));
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_FAST_PWM_A_B_OCRC_ID))
            TEST_REG_WRITE(TimerN::waveform(TimerN::Waveform::fastPwmABOcrc));
        #endif
    }
#endif

#if REG_DEFINED(TIMER_N(OVERFLOW_INT_ENABLE_REG))
    TEST(TimerN, overflowIntEnable) {
        TEST_REG_WRITE(TimerN::overflowIntEnable(true));
        TEST_REG_WRITE(TimerN::overflowIntEnable(false));
    }
#endif

#if REG_DEFINED(TIMER_N(OVERFLOW_INT_FLAG_REG))
    TEST(TimerN, overflowIntFlag) {
        TEST_REG_READ_WRITE(TimerN::overflowIntFlag());
    }

    TEST(TimerN, overflowIntFlagClear) {
        TEST_REG_WRITE(TimerN::overflowIntFlagClear());
    }
#endif

#if REG_DEFINED(TIMER_N(PRESCALER_RESET_REG))
    TEST(TimerN, prescalerReset) {
        TEST_REG_WRITE(TimerN::prescalerReset());
    }
#endif

#if REG_DEFINED(TIMER_N(SYNCHRONIZE_REG))
    TEST(TimerN, synchronizeMode) {
        TEST_REG_WRITE(TimerN::synchronizeMode(true));
        TEST_REG_WRITE(TimerN::synchronizeMode(false));
    }
#endif

#if REG_DEFINED(TIMER_N(COMPARE_A_REG))
    TEST(TimerN, compareA) {
        TEST_REG_WRITE(TimerN::compareA(0x12));
        TEST_REG_READ_WRITE(TimerN::compareA());
    }
#endif

#if REG_DEFINED(TIMER_N(COMPARE_B_REG))
    TEST(TimerN, compareB) {
        TEST_REG_WRITE(TimerN::compareB(0x12));
        TEST_REG_READ_WRITE(TimerN::compareB());
    }
#endif

#if REG_DEFINED(TIMER_N(COMPARE_C_REG))
    TEST(TimerN, compareC) {
        TEST_REG_WRITE(TimerN::compareC(0x12));
        TEST_REG_READ_WRITE(TimerN::compareC());
    }
#endif

#if REG_DEFINED(TIMER_N(COMPARE_A_OUTPUT_ENABLE_REG))
    TEST(TimerN, compareAOutputEnable) {
        TEST_REG_WRITE(TimerN::compareAOutputEnable(true));
        TEST_REG_WRITE(TimerN::compareAOutputEnable(false));
    }
#endif

#if REG_DEFINED(TIMER_N(COMPARE_B_OUTPUT_ENABLE_REG))
    TEST(TimerN, compareBOutputEnable) {
        TEST_REG_WRITE(TimerN::compareBOutputEnable(true));
        TEST_REG_WRITE(TimerN::compareBOutputEnable(false));
    }
#endif

#if REG_DEFINED(TIMER_N(COMPARE_C_OUTPUT_ENABLE_REG))
    TEST(TimerN, compareCOutputEnable) {
        TEST_REG_WRITE(TimerN::compareCOutputEnable(true));
        TEST_REG_WRITE(TimerN::compareCOutputEnable(false));
    }
#endif

#if REG_DEFINED(TIMER_N(COMPARE_A_PWM_OUTPUT_ENABLE_REG))
    TEST(TimerN, compareAPwmOutputEnable) {
        TEST_REG_WRITE(TimerN::compareAPwmOutputEnable(true));
        TEST_REG_WRITE(TimerN::compareAPwmOutputEnable(false));
    }
#endif

#if REG_DEFINED(TIMER_N(COMPARE_B_PWM_OUTPUT_ENABLE_REG))
    TEST(TimerN, compareBPwmOutputEnable) {
        TEST_REG_WRITE(TimerN::compareBPwmOutputEnable(true));
        TEST_REG_WRITE(TimerN::compareBPwmOutputEnable(false));
    }
#endif

#if REG_DEFINED(TIMER_N(COMPARE_C_PWM_OUTPUT_ENABLE_REG))
    TEST(TimerN, compareCPwmOutputEnable) {
        TEST_REG_WRITE(TimerN::compareCPwmOutputEnable(true));
        TEST_REG_WRITE(TimerN::compareCPwmOutputEnable(false));
    }
#endif

#if REG_DEFINED(TIMER_N(COMPARE_A_OUTPUT_REG))
    TEST(TimerN, compareAOutput) {
        #if DEFINED(TIMER_N(COMPARE_A_OUTPUT_DISCONNECTED_ID))
            TEST_REG_WRITE(TimerN::compareAOutput(TimerN::CompareAOutput::disconnected));
        #endif

        #if DEFINED(TIMER_N(COMPARE_A_OUTPUT_TOGGLE_ID))
            TEST_REG_WRITE(TimerN::compareAOutput(TimerN::CompareAOutput::toggle));
        #endif

        #if DEFINED(TIMER_N(COMPARE_A_OUTPUT_CLEAR_ID))
            TEST_REG_WRITE(TimerN::compareAOutput(TimerN::CompareAOutput::clear));
        #endif

        #if DEFINED(TIMER_N(COMPARE_A_OUTPUT_SET_ID))
            TEST_REG_WRITE(TimerN::compareAOutput(TimerN::CompareAOutput::set));
        #endif
    }
#endif

#if REG_DEFINED(TIMER_N(COMPARE_B_OUTPUT_REG))
    TEST(TimerN, compareBOutput) {
        #if DEFINED(TIMER_N(COMPARE_B_OUTPUT_DISCONNECTED_ID))
            TEST_REG_WRITE(TimerN::compareBOutput(TimerN::CompareBOutput::disconnected));
        #endif

        #if DEFINED(TIMER_N(COMPARE_B_OUTPUT_TOGGLE_ID))
            TEST_REG_WRITE(TimerN::compareBOutput(TimerN::CompareBOutput::toggle));
        #endif

        #if DEFINED(TIMER_N(COMPARE_B_OUTPUT_CLEAR_ID))
            TEST_REG_WRITE(TimerN::compareBOutput(TimerN::CompareBOutput::clear));
        #endif

        #if DEFINED(TIMER_N(COMPARE_B_OUTPUT_SET_ID))
            TEST_REG_WRITE(TimerN::compareBOutput(TimerN::CompareBOutput::set));
        #endif
    }
#endif

#if REG_DEFINED(TIMER_N(COMPARE_C_OUTPUT_REG))
    TEST(TimerN, compareCOutput) {
        #if DEFINED(TIMER_N(COMPARE_C_OUTPUT_DISCONNECTED_ID))
            TEST_REG_WRITE(TimerN::compareCOutput(TimerN::CompareCOutput::disconnected));
        #endif

        #if DEFINED(TIMER_N(COMPARE_C_OUTPUT_TOGGLE_ID))
            TEST_REG_WRITE(TimerN::compareCOutput(TimerN::CompareCOutput::toggle));
        #endif

        #if DEFINED(TIMER_N(COMPARE_C_OUTPUT_CLEAR_ID))
            TEST_REG_WRITE(TimerN::compareCOutput(TimerN::CompareCOutput::clear));
        #endif

        #if DEFINED(TIMER_N(COMPARE_C_OUTPUT_SET_ID))
            TEST_REG_WRITE(TimerN::compareCOutput(TimerN::CompareCOutput::set));
        #endif
    }
#endif

#if REG_DEFINED(TIMER_N(COMPARE_A_INT_ENABLE_REG))
    TEST(TimerN, compareAIntEnable) {
        TEST_REG_WRITE(TimerN::compareAIntEnable(true));
        TEST_REG_WRITE(TimerN::compareAIntEnable(false));
    }
#endif

#if REG_DEFINED(TIMER_N(COMPARE_B_INT_ENABLE_REG))
    TEST(TimerN, compareBIntEnable) {
        TEST_REG_WRITE(TimerN::compareBIntEnable(true));
        TEST_REG_WRITE(TimerN::compareBIntEnable(false));
    }
#endif

#if REG_DEFINED(TIMER_N(COMPARE_C_INT_ENABLE_REG))
    TEST(TimerN, compareCIntEnable) {
        TEST_REG_WRITE(TimerN::compareCIntEnable(true));
        TEST_REG_WRITE(TimerN::compareCIntEnable(false));
    }
#endif

#if REG_DEFINED(TIMER_N(COMPARE_A_INT_FLAG_REG))
    TEST(TimerN, compareAIntFlag) {
        TEST_REG_READ_WRITE(TimerN::compareAIntFlag());
    }

    TEST(TimerN, compareAIntFlagClear) {
        TEST_REG_WRITE(TimerN::compareAIntFlagClear());
    }
#endif

#if REG_DEFINED(TIMER_N(COMPARE_B_INT_FLAG_REG))
    TEST(TimerN, compareBIntFlag) {
        TEST_REG_READ_WRITE(TimerN::compareBIntFlag());
    }

    TEST(TimerN, compareBIntFlagClear) {
        TEST_REG_WRITE(TimerN::compareBIntFlagClear());
    }
#endif

#if REG_DEFINED(TIMER_N(COMPARE_C_INT_FLAG_REG))
    TEST(TimerN, compareCIntFlag) {
        TEST_REG_READ_WRITE(TimerN::compareCIntFlag());
    }

    TEST(TimerN, compareCIntFlagClear) {
        TEST_REG_WRITE(TimerN::compareCIntFlagClear());
    }
#endif

#if REG_DEFINED(TIMER_N(CAPTURE_REG))
    TEST(TimerN, capture) {
        TEST_REG_WRITE(TimerN::capture(0x1234));
        TEST_REG_READ_WRITE(TimerN::capture());
    }
#endif

#if REG_DEFINED(TIMER_N(CAPTURE_REG))
    TEST(TimerN, captureEdge) {
        TEST_REG_WRITE(TimerN::captureEdge(TimerN::CaptureEdge::rising));
        TEST_REG_WRITE(TimerN::captureEdge(TimerN::CaptureEdge::falling));
    }
#endif

#if REG_DEFINED(TIMER_N(CAPTURE_NOISE_CANCEL_ENABLE_REG))
    TEST(TimerN, captureNoiseCancelEnable) {
        TEST_REG_WRITE(TimerN::captureNoiseCancelEnable(true));
        TEST_REG_WRITE(TimerN::captureNoiseCancelEnable(false));
    }
#endif

#if REG_DEFINED(TIMER_N(CAPTURE_INT_ENABLE_REG))
    TEST(TimerN, captureIntEnable) {
        TEST_REG_WRITE(TimerN::captureIntEnable(true));
        TEST_REG_WRITE(TimerN::captureIntEnable(false));
    }
#endif

#if REG_DEFINED(TIMER_N(CAPTURE_INT_FLAG_REG))
    TEST(TimerN, captureIntFlag) {
        TEST_REG_READ_WRITE(TimerN::captureIntFlag());
    }

    TEST(TimerN, captureIntFlagClear) {
            TEST_REG_WRITE(TimerN::captureIntFlagClear());
    }
#endif

#endif // TEST

} // nblib::hw

//--------------------------------------------------------

    #endif

    #undef N
    #undef TimerN
    #undef TIMER_N

    #include "timer.hpp"
#else
    #define NBLIB_TIMER_HPP
#endif


#endif
