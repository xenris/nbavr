/// [[Index]]

/// # {{Tc}}

#ifndef NBLIB_TC_HPP

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
    #define TcN CAT(Tc, N)
    #define TC_N(A) CAT(CHIP_TC_, N, _, A)

    #if DEFINED(CAT(CHIP_TC_, N))

//--------------------------------------------------------

namespace nblib::hw {

/// ## Class {{TcN}}
struct TcN {
    TcN() = delete;
    TcN& operator=(const TcN&) = delete;
    TcN(const TcN&) = delete;

    /// #### enum {{TcN::Clock}}
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
        #if DEFINED(TC_N(CLOCK_NONE_ID))
            none = TC_N(CLOCK_NONE_ID),
        #endif

        #if DEFINED(TC_N(CLOCK_1_ID))
            div1 = TC_N(CLOCK_1_ID),
        #endif

        #if DEFINED(TC_N(CLOCK_2_ID))
            div2 = TC_N(CLOCK_2_ID),
        #endif

        #if DEFINED(TC_N(CLOCK_4_ID))
            div4 = TC_N(CLOCK_4_ID),
        #endif

        #if DEFINED(TC_N(CLOCK_8_ID))
            div8 = TC_N(CLOCK_8_ID),
        #endif

        #if DEFINED(TC_N(CLOCK_16_ID))
            div16 = TC_N(CLOCK_16_ID),
        #endif

        #if DEFINED(TC_N(CLOCK_32_ID))
            div32 = TC_N(CLOCK_32_ID),
        #endif

        #if DEFINED(TC_N(CLOCK_64_ID))
            div64 = TC_N(CLOCK_64_ID),
        #endif

        #if TC_N(CLOCK_128_ID)
            div128 = TC_N(CLOCK_128_ID),
        #endif

        #if TC_N(CLOCK_256_ID)
            div256 = TC_N(CLOCK_256_ID),
        #endif

        #if DEFINED(TC_N(CLOCK_512_ID))
            div512 = TC_N(CLOCK_512_ID),
        #endif

        #if DEFINED(TC_N(CLOCK_1024_ID))
            div1024 = TC_N(CLOCK_1024_ID),
        #endif

        #if DEFINED(TC_N(CLOCK_2048_ID))
            div2048 = TC_N(CLOCK_2048_ID),
        #endif

        #if DEFINED(TC_N(CLOCK_4096_ID))
            div4096 = TC_N(CLOCK_4096_ID),
        #endif

        #if DEFINED(TC_N(CLOCK_8192_ID))
            div8192 = TC_N(CLOCK_8192_ID),
        #endif

        #if DEFINED(TC_N(CLOCK_16384_ID))
            div16384 = TC_N(CLOCK_16384_ID),
        #endif

        #if DEFINED(TC_N(CLOCK_EXT_FALLING_ID))
            extFalling = TC_N(CLOCK_EXT_FALLING_ID),
        #endif

        #if DEFINED(TC_N(CLOCK_EXT_RISING_ID))
            extRising = TC_N(CLOCK_EXT_RISING_ID),
        #endif
    };

    /// #### enum {{TcN::Waveform}}
    /// * normal
    /// * pwm
    /// * pwm8Bit
    /// * pwm9Bit
    /// * pwm10Bit
    /// * ctcOcra
    /// * ctcOcrc
    /// * ctcIcr
    /// * fastPwm8Bit
    /// * fastPwm9Bit
    /// * fastPwm10Bit
    /// * fastPwm
    /// * pwmOcra
    /// * fastPwmOcra
    /// * fastPwmOcrc
    /// * fastPwmAOcrc
    /// * fastPwmBOcrc
    /// * fastPwmABOcrc
    /// * frequency
    /// * singleSlopePwm
    /// * dualSlopePwmOverflowTop
    /// * dualSlopePwmOverflowBottom
    /// * dualSlopePwmOverflowBoth
    enum class Waveform {
        #if DEFINED(TC_N(WAVEFORM_NORMAL_ID))
            normal = TC_N(WAVEFORM_NORMAL_ID),
        #endif

        #if DEFINED(TC_N(WAVEFORM_PWM_PHASE_CORRECT_ID))
            pwm = TC_N(WAVEFORM_PWM_PHASE_CORRECT_ID),
        #endif

        #if DEFINED(TC_N(WAVEFORM_PWM_PHASE_CORRECT_8_ID))
            pwm8Bit = TC_N(WAVEFORM_PWM_PHASE_CORRECT_8_ID),
        #endif

        #if DEFINED(TC_N(WAVEFORM_PWM_PHASE_CORRECT_9_ID))
            pwm9Bit = TC_N(WAVEFORM_PWM_PHASE_CORRECT_9_ID),
        #endif

        #if DEFINED(TC_N(WAVEFORM_PWM_PHASE_CORRECT_10_ID))
            pwm10Bit = TC_N(WAVEFORM_PWM_PHASE_CORRECT_10_ID),
        #endif

        #if DEFINED(TC_N(WAVEFORM_CTC_OCRA_ID))
            ctcOcra = TC_N(WAVEFORM_CTC_OCRA_ID),
        #endif

        #if DEFINED(TC_N(WAVEFORM_CTC_OCRC_ID))
            ctcOcrc = TC_N(WAVEFORM_CTC_OCRC_ID),
        #endif

        #if DEFINED(TC_N(WAVEFORM_CTC_ICR_ID))
            ctcIcr = TC_N(WAVEFORM_CTC_ICR_ID),
        #endif

        #if DEFINED(TC_N(WAVEFORM_FAST_PWM_8_ID))
            fastPwm8Bit = TC_N(WAVEFORM_FAST_PWM_8_ID),
        #endif

        #if DEFINED(TC_N(WAVEFORM_FAST_PWM_9_ID))
            fastPwm9Bit = TC_N(WAVEFORM_FAST_PWM_9_ID),
        #endif

        #if DEFINED(TC_N(WAVEFORM_FAST_PWM_10_ID))
            fastPwm10Bit = TC_N(WAVEFORM_FAST_PWM_10_ID),
        #endif

        #if DEFINED(TC_N(WAVEFORM_FAST_PWM_ID))
            fastPwm = TC_N(WAVEFORM_FAST_PWM_ID),
        #endif

        #if DEFINED(TC_N(WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID))
            pwmOcra = TC_N(WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID),
        #endif

        #if DEFINED(TC_N(WAVEFORM_FAST_PWM_OCRA_ID))
            fastPwmOcra = TC_N(WAVEFORM_FAST_PWM_OCRA_ID),
        #endif

        #if DEFINED(TC_N(WAVEFORM_FAST_PWM_OCRC_ID))
            fastPwmOcrc = TC_N(WAVEFORM_FAST_PWM_OCRC_ID),
        #endif

        #if DEFINED(TC_N(WAVEFORM_FAST_PWM_A_OCRC_ID))
            fastPwmAOcrc = TC_N(WAVEFORM_FAST_PWM_A_OCRC_ID),
        #endif

        #if DEFINED(TC_N(WAVEFORM_FAST_PWM_B_OCRC_ID))
            fastPwmBOcrc = TC_N(WAVEFORM_FAST_PWM_B_OCRC_ID),
        #endif

        #if DEFINED(TC_N(WAVEFORM_FAST_PWM_A_B_OCRC_ID))
            fastPwmABOcrc = TC_N(WAVEFORM_FAST_PWM_A_B_OCRC_ID),
        #endif

        #if DEFINED(TC_N(WAVEFORM_FREQUENCY_ID))
            frequency = TC_N(WAVEFORM_FREQUENCY_ID),
        #endif

        #if DEFINED(TC_N(WAVEFORM_SINGLE_SLOPE_PWM_ID))
            singleSlopePwm = TC_N(WAVEFORM_SINGLE_SLOPE_PWM_ID),
        #endif

        #if DEFINED(TC_N(WAVEFORM_DUAL_SLOPE_PWM_OVF_TOP_ID))
            dualSlopePwmOverflowTop = TC_N(WAVEFORM_DUAL_SLOPE_PWM_OVF_TOP_ID),
        #endif

        #if DEFINED(TC_N(WAVEFORM_DUAL_SLOPE_PWM_OVF_BOTTOM_ID))
            dualSlopePwmOverflowBottom = TC_N(WAVEFORM_DUAL_SLOPE_PWM_OVF_BOTTOM_ID),
        #endif

        #if DEFINED(TC_N(WAVEFORM_DUAL_SLOPE_PWM_OVF_BOTH_ID))
            dualSlopePwmOverflowBoth = TC_N(WAVEFORM_DUAL_SLOPE_PWM_OVF_BOTH_ID),
        #endif
    };

    /// #### enum {{TcN::CompareXOutputMode}}
    /// * disconnected
    /// * toggle
    /// * clear
    /// * set
    #if REG_DEFINED(TC_N(COMPARE_A_OUTPUT_MODE_REG))
        enum class CompareAOutputMode {
            #if DEFINED(TC_N(COMPARE_A_OUTPUT_MODE_DISCONNECTED_ID))
                disconnected = TC_N(COMPARE_A_OUTPUT_MODE_DISCONNECTED_ID),
            #endif

            #if DEFINED(TC_N(COMPARE_A_OUTPUT_MODE_TOGGLE_ID))
                toggle = TC_N(COMPARE_A_OUTPUT_MODE_TOGGLE_ID),
            #endif

            #if DEFINED(TC_N(COMPARE_A_OUTPUT_MODE_CLEAR_ID))
                clear = TC_N(COMPARE_A_OUTPUT_MODE_CLEAR_ID),
            #endif

            #if DEFINED(TC_N(COMPARE_A_OUTPUT_MODE_SET_ID))
                set = TC_N(COMPARE_A_OUTPUT_MODE_SET_ID),
            #endif
        };
    #endif

    #if REG_DEFINED(TC_N(COMPARE_B_OUTPUT_MODE_REG))
        enum class CompareBOutputMode {
            #if DEFINED(TC_N(COMPARE_B_OUTPUT_MODE_DISCONNECTED_ID))
                disconnected = TC_N(COMPARE_B_OUTPUT_MODE_DISCONNECTED_ID),
            #endif

            #if DEFINED(TC_N(COMPARE_B_OUTPUT_MODE_TOGGLE_ID))
                toggle = TC_N(COMPARE_B_OUTPUT_MODE_TOGGLE_ID),
            #endif

            #if DEFINED(TC_N(COMPARE_B_OUTPUT_MODE_CLEAR_ID))
                clear = TC_N(COMPARE_B_OUTPUT_MODE_CLEAR_ID),
            #endif

            #if DEFINED(TC_N(COMPARE_B_OUTPUT_MODE_SET_ID))
                set = TC_N(COMPARE_B_OUTPUT_MODE_SET_ID),
            #endif
        };
    #endif

    #if REG_DEFINED(TC_N(COMPARE_C_OUTPUT_MODE_REG))
        enum class CompareCOutputMode {
            #if DEFINED(TC_N(COMPARE_C_OUTPUT_MODE_DISCONNECTED_ID))
                disconnected = TC_N(COMPARE_C_OUTPUT_MODE_DISCONNECTED_ID),
            #endif

            #if DEFINED(TC_N(COMPARE_C_OUTPUT_MODE_TOGGLE_ID))
                toggle = TC_N(COMPARE_C_OUTPUT_MODE_TOGGLE_ID),
            #endif

            #if DEFINED(TC_N(COMPARE_C_OUTPUT_MODE_CLEAR_ID))
                clear = TC_N(COMPARE_C_OUTPUT_MODE_CLEAR_ID),
            #endif

            #if DEFINED(TC_N(COMPARE_C_OUTPUT_MODE_SET_ID))
                set = TC_N(COMPARE_C_OUTPUT_MODE_SET_ID),
            #endif
        };
    #endif

    #if REG_DEFINED(TC_N(CAPTURE_EDGE_REG))
        /// #### enum {{TcN::CaptureEdge}}
        /// * rising
        /// * falling
        enum class CaptureEdge {
            rising = TC_N(CAPTURE_EDGE_RISING_ID),
            falling = TC_N(CAPTURE_EDGE_FALLING_ID),
        };
    #endif

    /// #### static [[HardwareType]] getHardwareType()
    static constexpr HardwareType getHardwareType() {
        return HardwareType::tc;
    }

    #if REG_DEFINED(TC_N(ENABLE_REG))
        /// #### static void enable(bool)
        static force_inline void enable(bool b) {
            TC_N(ENABLE_REG)::setBit(TC_N(ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TC_N(COUNTER_REG))
        /// #### static void counter(T)
        static force_inline void counter(TC_N(COUNTER_REG)::Type value) {
            TC_N(COUNTER_REG)::setReg(value);
        }

        /// #### static T counter()
        static force_inline TC_N(COUNTER_REG)::Type counter() {
            return TC_N(COUNTER_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(TC_N(TOP_REG))
        /// #### static void top(T)
        static force_inline void top(TC_N(TOP_REG)::Type value) {
            TC_N(TOP_REG)::setReg(value);
        }

        /// #### static T top()
        static force_inline TC_N(TOP_REG)::Type top() {
            return TC_N(TOP_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(TC_N(TOP_BUFFER_REG))
        /// #### static void topBuffer(T)
        static force_inline void topBuffer(TC_N(TOP_BUFFER_REG)::Type value) {
            TC_N(TOP_BUFFER_REG)::setReg(value);
        }

        /// #### static T topBuffer()
        static force_inline TC_N(TOP_BUFFER_REG)::Type topBuffer() {
            return TC_N(TOP_BUFFER_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(TC_N(CLOCK_REG))
        /// #### static void clock([[TcN::Clock]] c)
        static force_inline void clock(Clock c) {
            TC_N(CLOCK_REG)::setBits(TC_N(CLOCK_MASK), c);
        }
    #endif

    #if REG_DEFINED(TC_N(WAVEFORM_REG))
        /// #### static void waveform([[TcN::Waveform]] w)
        static force_inline void waveform(Waveform w) {
            TC_N(WAVEFORM_REG)::setBits(TC_N(WAVEFORM_MASK), w);

            #if REG_DEFINED(TC_N(WAVEFORM_REG_EXTRA))
                TC_N(WAVEFORM_REG_EXTRA)::setBits(TC_N(WAVEFORM_MASK_EXTRA), uint(w) >> 8);
            #endif
        }
    #endif

    #if REG_DEFINED(TC_N(OVERFLOW_INT_ENABLE_REG))
        /// #### static void overflowIntEnable(bool)
        static force_inline void overflowIntEnable(bool b) {
            TC_N(OVERFLOW_INT_ENABLE_REG)::setBit(TC_N(OVERFLOW_INT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TC_N(OVERFLOW_INT_FLAG_REG))
        /// #### static bool overflowIntFlag()
        static force_inline bool overflowIntFlag() {
            return TC_N(OVERFLOW_INT_FLAG_REG)::getBit(TC_N(OVERFLOW_INT_FLAG_BIT));
        }

        /// #### static void overflowIntFlagClear()
        static force_inline void overflowIntFlagClear() {
            TC_N(OVERFLOW_INT_FLAG_REG)::setBit(TC_N(OVERFLOW_INT_FLAG_BIT), true);
        }
    #endif

    #if REG_DEFINED(TC_N(PRESCALER_RESET_REG))
        /// #### static void prescalerReset()
        /// Resets the *shared* timer prescaler to zero.
        static force_inline void prescalerReset() {
            TC_N(PRESCALER_RESET_REG)::setBit(TC_N(PRESCALER_RESET_BIT), true);
        }
    #endif

    #if REG_DEFINED(TC_N(SYNCHRONIZE_REG))
        /// #### static void synchronizeMode(bool b)
        /// Set to true then call prescalerReset() to hold the timers' prescalers at zero, effectively pausing the timers.
        /// Set back to false to start all timers at exactly the same time.
        static force_inline void synchronizeMode(bool b) {
            TC_N(SYNCHRONIZE_REG)::setBit(TC_N(SYNCHRONIZE_BIT), b);
        }
    #endif

    /// #### static void compareX(T value)

    /// #### static T compareX()

    #if REG_DEFINED(TC_N(COMPARE_A_REG))
        static force_inline void compareA(TC_N(COMPARE_A_REG)::Type value) {
            TC_N(COMPARE_A_REG)::setReg(value);
        }

        static force_inline TC_N(COMPARE_A_REG)::Type compareA() {
            return TC_N(COMPARE_A_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(TC_N(COMPARE_B_REG))
        static force_inline void compareB(TC_N(COMPARE_B_REG)::Type value) {
            TC_N(COMPARE_B_REG)::setReg(value);
        }

        static force_inline TC_N(COMPARE_B_REG)::Type compareB() {
            return TC_N(COMPARE_B_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(TC_N(COMPARE_C_REG))
        static force_inline void compareC(TC_N(COMPARE_C_REG)::Type value) {
            TC_N(COMPARE_C_REG)::setReg(value);
        }

        static force_inline TC_N(COMPARE_C_REG)::Type compareC() {
            return TC_N(COMPARE_C_REG)::getReg();
        }
    #endif

    /// #### static void compareXBuffer(T value)

    /// #### static T compareXBuffer()

    #if REG_DEFINED(TC_N(COMPARE_A_BUFFER_REG))
        static force_inline void compareABuffer(TC_N(COMPARE_A_BUFFER_REG)::Type value) {
            TC_N(COMPARE_A_BUFFER_REG)::setReg(value);
        }

        static force_inline TC_N(COMPARE_A_BUFFER_REG)::Type compareABuffer() {
            return TC_N(COMPARE_A_BUFFER_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(TC_N(COMPARE_B_BUFFER_REG))
        static force_inline void compareBBuffer(TC_N(COMPARE_B_BUFFER_REG)::Type value) {
            TC_N(COMPARE_B_BUFFER_REG)::setReg(value);
        }

        static force_inline TC_N(COMPARE_B_BUFFER_REG)::Type compareBBuffer() {
            return TC_N(COMPARE_B_BUFFER_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(TC_N(COMPARE_C_BUFFER_REG))
        static force_inline void compareCBuffer(TC_N(COMPARE_C_BUFFER_REG)::Type value) {
            TC_N(COMPARE_C_BUFFER_REG)::setReg(value);
        }

        static force_inline TC_N(COMPARE_C_BUFFER_REG)::Type compareCBuffer() {
            return TC_N(COMPARE_C_BUFFER_REG)::getReg();
        }
    #endif

    /// #### static void compareXOutputEnable(bool)

    #if REG_DEFINED(TC_N(COMPARE_A_OUTPUT_ENABLE_REG))
        static force_inline void compareAOutputEnable(bool b) {
            TC_N(COMPARE_A_OUTPUT_ENABLE_REG)::setBit(TC_N(COMPARE_A_OUTPUT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TC_N(COMPARE_B_OUTPUT_ENABLE_REG))
        static force_inline void compareBOutputEnable(bool b) {
            TC_N(COMPARE_B_OUTPUT_ENABLE_REG)::setBit(TC_N(COMPARE_B_OUTPUT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TC_N(COMPARE_C_OUTPUT_ENABLE_REG))
        static force_inline void compareCOutputEnable(bool b) {
            TC_N(COMPARE_C_OUTPUT_ENABLE_REG)::setBit(TC_N(COMPARE_C_OUTPUT_ENABLE_BIT), b);
        }
    #endif

    /// #### static void compareXOutputMode(CompareXOutputMode)

    #if REG_DEFINED(TC_N(COMPARE_A_OUTPUT_MODE_REG))
        static force_inline void compareAOutputMode(CompareAOutputMode m) {
            TC_N(COMPARE_A_OUTPUT_MODE_REG)::setBits(TC_N(COMPARE_A_OUTPUT_MODE_MASK), m);
        }
    #endif

    #if REG_DEFINED(TC_N(COMPARE_B_OUTPUT_MODE_REG))
        static force_inline void compareBOutputMode(CompareBOutputMode m) {
            TC_N(COMPARE_B_OUTPUT_MODE_REG)::setBits(TC_N(COMPARE_B_OUTPUT_MODE_MASK), m);
        }
    #endif

    #if REG_DEFINED(TC_N(COMPARE_C_OUTPUT_MODE_REG))
        static force_inline void compareCOutputMode(CompareCOutputMode m) {
            TC_N(COMPARE_C_OUTPUT_MODE_REG)::setBits(TC_N(COMPARE_C_OUTPUT_MODE_MASK), m);
        }
    #endif

    /// #### static void compareXIntEnable(bool)

    #if REG_DEFINED(TC_N(COMPARE_A_INT_ENABLE_REG))
        static force_inline void compareAIntEnable(bool b) {
            TC_N(COMPARE_A_INT_ENABLE_REG)::setBit(TC_N(COMPARE_A_INT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TC_N(COMPARE_B_INT_ENABLE_REG))
        static force_inline void compareBIntEnable(bool b) {
            TC_N(COMPARE_B_INT_ENABLE_REG)::setBit(TC_N(COMPARE_B_INT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TC_N(COMPARE_C_INT_ENABLE_REG))
        static force_inline void compareCIntEnable(bool b) {
            TC_N(COMPARE_C_INT_ENABLE_REG)::setBit(TC_N(COMPARE_C_INT_ENABLE_BIT), b);
        }
    #endif

    /// #### static bool compareXIntFlag()

    /// #### static void compareXIntFlagClear()

    #if REG_DEFINED(TC_N(COMPARE_A_INT_FLAG_REG))
        static force_inline bool compareAIntFlag() {
            return TC_N(COMPARE_A_INT_FLAG_REG)::getBit(TC_N(COMPARE_A_INT_FLAG_BIT));
        }

        static force_inline void compareAIntFlagClear() {
            TC_N(COMPARE_A_INT_FLAG_REG)::setBit(TC_N(COMPARE_A_INT_FLAG_BIT), true);
        }
    #endif

    #if REG_DEFINED(TC_N(COMPARE_B_INT_FLAG_REG))
        static force_inline bool compareBIntFlag() {
            return TC_N(COMPARE_B_INT_FLAG_REG)::getBit(TC_N(COMPARE_B_INT_FLAG_BIT));
        }

        static force_inline void compareBIntFlagClear() {
            TC_N(COMPARE_B_INT_FLAG_REG)::setBit(TC_N(COMPARE_B_INT_FLAG_BIT), true);
        }
    #endif

    #if REG_DEFINED(TC_N(COMPARE_C_INT_FLAG_REG))
        static force_inline bool compareCIntFlag() {
            return TC_N(COMPARE_C_INT_FLAG_REG)::getBit(TC_N(COMPARE_C_INT_FLAG_BIT));
        }

        static force_inline void compareCIntFlagClear() {
            TC_N(COMPARE_C_INT_FLAG_REG)::setBit(TC_N(COMPARE_C_INT_FLAG_BIT), true);
        }
    #endif

    #if REG_DEFINED(TC_N(CAPTURE_REG))
        /// #### static void capture(T)
        static force_inline void capture(TC_N(CAPTURE_REG)::Type t) {
            TC_N(CAPTURE_REG)::setReg(t);
        }

        /// #### static T capture()
        static force_inline TC_N(CAPTURE_REG)::Type capture() {
            return TC_N(CAPTURE_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(TC_N(CAPTURE_REG))
        /// #### static void captureEdge([[TcN::CaptureEdge]])
        static force_inline void captureEdge(CaptureEdge e) {
            TC_N(CAPTURE_EDGE_REG)::setBits(TC_N(CAPTURE_EDGE_MASK), e);
        }
    #endif

    #if REG_DEFINED(TC_N(CAPTURE_NOISE_CANCEL_ENABLE_REG))
        /// #### static void captureNoiseCancelEnable(bool)
        static force_inline void captureNoiseCancelEnable(bool b) {
            TC_N(CAPTURE_NOISE_CANCEL_ENABLE_REG)::setBit(TC_N(CAPTURE_NOISE_CANCEL_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TC_N(CAPTURE_INT_ENABLE_REG))
        /// #### static void captureIntEnable(bool)
        static force_inline void captureIntEnable(bool b) {
            TC_N(CAPTURE_INT_ENABLE_REG)::setBit(TC_N(CAPTURE_INT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TC_N(CAPTURE_INT_FLAG_REG))
        /// #### static bool captureIntFlag()
        static force_inline bool captureIntFlag() {
            return TC_N(CAPTURE_INT_FLAG_REG)::getBit(TC_N(CAPTURE_INT_FLAG_BIT));
        }

        /// #### static void captureIntFlagClear()
        static force_inline void captureIntFlagClear() {
            TC_N(CAPTURE_INT_FLAG_REG)::setBit(TC_N(CAPTURE_INT_FLAG_BIT), true);
        }
    #endif

    #if REG_DEFINED(TC_N(SPLIT_MODE_ENABLE_REG))
        /// #### static bool splitModeEnable(bool)
        static force_inline void splitModeEnable(bool b) {
            TC_N(SPLIT_MODE_ENABLE_REG)::setBit(TC_N(SPLIT_MODE_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TC_N(LOW_COUNTER_REG))
        /// #### static void lowCounter(T value)
        static force_inline void lowCounter(TC_N(LOW_COUNTER_REG)::Type value) {
            TC_N(LOW_COUNTER_REG)::setReg(value);
        }

        /// #### static T lowCounter()
        static force_inline TC_N(LOW_COUNTER_REG)::Type lowCounter() {
            return TC_N(LOW_COUNTER_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(TC_N(HIGH_COUNTER_REG))
        /// #### static void highCounter(T value)
        static force_inline void highCounter(TC_N(HIGH_COUNTER_REG)::Type value) {
            TC_N(HIGH_COUNTER_REG)::setReg(value);
        }

        /// #### static T highCounter()
        static force_inline TC_N(HIGH_COUNTER_REG)::Type highCounter() {
            return TC_N(HIGH_COUNTER_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(TC_N(LOW_TOP_REG))
        /// #### static void lowTop(T value)
        static force_inline void lowTop(TC_N(LOW_TOP_REG)::Type value) {
            TC_N(LOW_TOP_REG)::setReg(value);
        }

        /// #### static T lowTop()
        static force_inline TC_N(LOW_TOP_REG)::Type lowTop() {
            return TC_N(LOW_TOP_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(TC_N(HIGH_TOP_REG))
        /// #### static void highTop(T value)
        static force_inline void highTop(TC_N(HIGH_TOP_REG)::Type value) {
            TC_N(HIGH_TOP_REG)::setReg(value);
        }

        /// #### static T highTop()
        static force_inline TC_N(HIGH_TOP_REG)::Type highTop() {
            return TC_N(HIGH_TOP_REG)::getReg();
        }
    #endif

    /// #### static void lowCompareX(T value)

    /// #### static T lowCompareX()

    #if REG_DEFINED(TC_N(LOW_COMPARE_A_REG))
        static force_inline void lowCompareA(TC_N(LOW_COMPARE_A_REG)::Type value) {
            TC_N(LOW_COMPARE_A_REG)::setReg(value);
        }

        static force_inline TC_N(LOW_COMPARE_A_REG)::Type lowCompareA() {
            return TC_N(LOW_COMPARE_A_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(TC_N(LOW_COMPARE_B_REG))
        static force_inline void lowCompareB(TC_N(LOW_COMPARE_B_REG)::Type value) {
            TC_N(LOW_COMPARE_B_REG)::setReg(value);
        }

        static force_inline TC_N(LOW_COMPARE_B_REG)::Type lowCompareB() {
            return TC_N(LOW_COMPARE_B_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(TC_N(LOW_COMPARE_C_REG))
        static force_inline void lowCompareC(TC_N(LOW_COMPARE_C_REG)::Type value) {
            TC_N(LOW_COMPARE_C_REG)::setReg(value);
        }

        static force_inline TC_N(LOW_COMPARE_C_REG)::Type lowCompareC() {
            return TC_N(LOW_COMPARE_C_REG)::getReg();
        }
    #endif

    /// #### static void highCompareX(T value)

    /// #### static T highCompareX()

    #if REG_DEFINED(TC_N(HIGH_COMPARE_A_REG))
        static force_inline void highCompareA(TC_N(HIGH_COMPARE_A_REG)::Type value) {
            TC_N(HIGH_COMPARE_A_REG)::setReg(value);
        }

        static force_inline TC_N(HIGH_COMPARE_A_REG)::Type highCompareA() {
            return TC_N(HIGH_COMPARE_A_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(TC_N(HIGH_COMPARE_B_REG))
        static force_inline void highCompareB(TC_N(HIGH_COMPARE_B_REG)::Type value) {
            TC_N(HIGH_COMPARE_B_REG)::setReg(value);
        }

        static force_inline TC_N(HIGH_COMPARE_B_REG)::Type highCompareB() {
            return TC_N(HIGH_COMPARE_B_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(TC_N(HIGH_COMPARE_C_REG))
        static force_inline void highCompareC(TC_N(HIGH_COMPARE_C_REG)::Type value) {
            TC_N(HIGH_COMPARE_C_REG)::setReg(value);
        }

        static force_inline TC_N(HIGH_COMPARE_C_REG)::Type highCompareC() {
            return TC_N(HIGH_COMPARE_C_REG)::getReg();
        }
    #endif

    /// #### static void lowCompareXOutputEnable(bool)

    #if REG_DEFINED(TC_N(LOW_COMPARE_A_OUTPUT_ENABLE_REG))
        static force_inline void lowCompareAOutputEnable(bool b) {
            TC_N(LOW_COMPARE_A_OUTPUT_ENABLE_REG)::setBit(TC_N(LOW_COMPARE_A_OUTPUT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TC_N(LOW_COMPARE_B_OUTPUT_ENABLE_REG))
        static force_inline void lowCompareBOutputEnable(bool b) {
            TC_N(LOW_COMPARE_B_OUTPUT_ENABLE_REG)::setBit(TC_N(LOW_COMPARE_B_OUTPUT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TC_N(LOW_COMPARE_C_OUTPUT_ENABLE_REG))
        static force_inline void lowCompareCOutputEnable(bool b) {
            TC_N(LOW_COMPARE_C_OUTPUT_ENABLE_REG)::setBit(TC_N(LOW_COMPARE_C_OUTPUT_ENABLE_BIT), b);
        }
    #endif

    /// #### static void highCompareXOutputEnable(bool)

    #if REG_DEFINED(TC_N(HIGH_COMPARE_A_OUTPUT_ENABLE_REG))
        static force_inline void highCompareAOutputEnable(bool b) {
            TC_N(HIGH_COMPARE_A_OUTPUT_ENABLE_REG)::setBit(TC_N(HIGH_COMPARE_A_OUTPUT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TC_N(HIGH_COMPARE_B_OUTPUT_ENABLE_REG))
        static force_inline void highCompareBOutputEnable(bool b) {
            TC_N(HIGH_COMPARE_B_OUTPUT_ENABLE_REG)::setBit(TC_N(HIGH_COMPARE_B_OUTPUT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TC_N(HIGH_COMPARE_C_OUTPUT_ENABLE_REG))
        static force_inline void highCompareCOutputEnable(bool b) {
            TC_N(HIGH_COMPARE_C_OUTPUT_ENABLE_REG)::setBit(TC_N(HIGH_COMPARE_C_OUTPUT_ENABLE_BIT), b);
        }
    #endif

    /// #### static void lowCompareXIntEnable(bool)

    #if REG_DEFINED(TC_N(LOW_COMPARE_A_INT_ENABLE_REG))
        static force_inline void lowCompareAIntEnable(bool b) {
            TC_N(LOW_COMPARE_A_INT_ENABLE_REG)::setBit(TC_N(LOW_COMPARE_A_INT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TC_N(LOW_COMPARE_B_INT_ENABLE_REG))
        static force_inline void lowCompareBIntEnable(bool b) {
            TC_N(LOW_COMPARE_B_INT_ENABLE_REG)::setBit(TC_N(LOW_COMPARE_B_INT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TC_N(LOW_COMPARE_C_INT_ENABLE_REG))
        static force_inline void lowCompareCIntEnable(bool b) {
            TC_N(LOW_COMPARE_C_INT_ENABLE_REG)::setBit(TC_N(LOW_COMPARE_C_INT_ENABLE_BIT), b);
        }
    #endif

    /// #### static bool lowCompareXIntFlag()

    /// #### static void lowCompareXIntFlagClear()

    #if REG_DEFINED(TC_N(LOW_COMPARE_A_INT_FLAG_REG))
        static force_inline bool lowCompareAIntFlag() {
            return TC_N(LOW_COMPARE_A_INT_FLAG_REG)::getBit(TC_N(LOW_COMPARE_A_INT_FLAG_BIT));
        }

        static force_inline void lowCompareAIntFlagClear() {
            TC_N(LOW_COMPARE_A_INT_FLAG_REG)::setBit(TC_N(LOW_COMPARE_A_INT_FLAG_BIT), true);
        }
    #endif

    #if REG_DEFINED(TC_N(LOW_COMPARE_B_INT_FLAG_REG))
        static force_inline bool lowCompareBIntFlag() {
            return TC_N(LOW_COMPARE_B_INT_FLAG_REG)::getBit(TC_N(LOW_COMPARE_B_INT_FLAG_BIT));
        }

        static force_inline void lowCompareBIntFlagClear() {
            TC_N(LOW_COMPARE_B_INT_FLAG_REG)::setBit(TC_N(LOW_COMPARE_B_INT_FLAG_BIT), true);
        }
    #endif

    #if REG_DEFINED(TC_N(LOW_COMPARE_C_INT_FLAG_REG))
        static force_inline bool lowCompareCIntFlag() {
            return TC_N(LOW_COMPARE_C_INT_FLAG_REG)::getBit(TC_N(LOW_COMPARE_C_INT_FLAG_BIT));
        }

        static force_inline void lowCompareCIntFlagClear() {
            TC_N(LOW_COMPARE_C_INT_FLAG_REG)::setBit(TC_N(LOW_COMPARE_C_INT_FLAG_BIT), true);
        }
    #endif

    #if REG_DEFINED(TC_N(LOW_UNDERFLOW_INT_ENABLE_REG))
        /// #### static void lowUnderflowIntEnable(bool)
        static force_inline void lowUnderflowIntEnable(bool b) {
            TC_N(LOW_UNDERFLOW_INT_ENABLE_REG)::setBit(TC_N(LOW_UNDERFLOW_INT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TC_N(LOW_UNDERFLOW_INT_FLAG_REG))
        /// #### static bool lowUnderflowIntFlag()
        static force_inline bool lowUnderflowIntFlag() {
            return TC_N(LOW_UNDERFLOW_INT_FLAG_REG)::getBit(TC_N(LOW_UNDERFLOW_INT_FLAG_BIT));
        }

        /// #### static void lowUnderflowIntFlagClear()
        static force_inline void lowUnderflowIntFlagClear() {
            TC_N(LOW_UNDERFLOW_INT_FLAG_REG)::setBit(TC_N(LOW_UNDERFLOW_INT_FLAG_BIT), true);
        }
    #endif

    #if REG_DEFINED(TC_N(HIGH_UNDERFLOW_INT_ENABLE_REG))
        /// #### static void highUnderflowIntEnable(bool)
        static force_inline void highUnderflowIntEnable(bool b) {
            TC_N(HIGH_UNDERFLOW_INT_ENABLE_REG)::setBit(TC_N(HIGH_UNDERFLOW_INT_ENABLE_BIT), b);
        }
    #endif

    #if REG_DEFINED(TC_N(HIGH_UNDERFLOW_INT_FLAG_REG))
        /// #### static bool highUnderflowIntFlag()
        static force_inline bool highUnderflowIntFlag() {
            return TC_N(HIGH_UNDERFLOW_INT_FLAG_REG)::getBit(TC_N(HIGH_UNDERFLOW_INT_FLAG_BIT));
        }

        /// #### static void highUnderflowIntFlagClear()
        static force_inline void highUnderflowIntFlagClear() {
            TC_N(HIGH_UNDERFLOW_INT_FLAG_REG)::setBit(TC_N(HIGH_UNDERFLOW_INT_FLAG_BIT), true);
        }
    #endif
};

#ifdef TEST

TEST(TcN, getHardwareType) {
    ASSERT_EQ(TcN::getHardwareType(), HardwareType::tc);
}

#if REG_DEFINED(TC_N(ENABLE_REG))
    TEST(TcN, enable) {
        TEST_REG_WRITE(TcN::enable(true));
        TEST_REG_WRITE(TcN::enable(false));
    }
#endif

#if REG_DEFINED(TC_N(COUNTER_REG))
    TEST(TcN, counter) {
        TEST_REG_WRITE(TcN::counter(0x12));
        TEST_REG_READ_WRITE(TcN::counter());
    }
#endif

#if REG_DEFINED(TC_N(TOP_REG))
    TEST(TcN, top) {
        TEST_REG_WRITE(TcN::top(0x12));
        TEST_REG_READ_WRITE(TcN::top());
    }
#endif

#if REG_DEFINED(TC_N(TOP_BUFFER_REG))
    TEST(TcN, topBuffer) {
        TEST_REG_WRITE(TcN::topBuffer(0x12));
        TEST_REG_READ_WRITE(TcN::topBuffer());
    }
#endif

#if REG_DEFINED(TC_N(CLOCK_REG))
    TEST(TcN, clock) {
        #if DEFINED(TC_N(CLOCK_NONE_ID))
            TEST_REG_WRITE(TcN::clock(TcN::Clock::none));
        #endif

        #if DEFINED(TC_N(CLOCK_1_ID))
            TEST_REG_WRITE(TcN::clock(TcN::Clock::div1));
        #endif

        #if DEFINED(TC_N(CLOCK_2_ID))
            TEST_REG_WRITE(TcN::clock(TcN::Clock::div2));
        #endif

        #if DEFINED(TC_N(CLOCK_4_ID))
            TEST_REG_WRITE(TcN::clock(TcN::Clock::div4));
        #endif

        #if DEFINED(TC_N(CLOCK_8_ID))
            TEST_REG_WRITE(TcN::clock(TcN::Clock::div8));
        #endif

        #if DEFINED(TC_N(CLOCK_16_ID))
            TEST_REG_WRITE(TcN::clock(TcN::Clock::div16));
        #endif

        #if DEFINED(TC_N(CLOCK_32_ID))
            TEST_REG_WRITE(TcN::clock(TcN::Clock::div32));
        #endif

        #if DEFINED(TC_N(CLOCK_64_ID))
            TEST_REG_WRITE(TcN::clock(TcN::Clock::div64));
        #endif

        #if DEFINED(TC_N(CLOCK_128_ID))
            TEST_REG_WRITE(TcN::clock(TcN::Clock::div128));
        #endif

        #if DEFINED(TC_N(CLOCK_256_ID))
            TEST_REG_WRITE(TcN::clock(TcN::Clock::div256));
        #endif

        #if DEFINED(TC_N(CLOCK_512_ID))
            TEST_REG_WRITE(TcN::clock(TcN::Clock::div512));
        #endif

        #if DEFINED(TC_N(CLOCK_1024_ID))
            TEST_REG_WRITE(TcN::clock(TcN::Clock::div1024));
        #endif

        #if DEFINED(TC_N(CLOCK_2048_ID))
            TEST_REG_WRITE(TcN::clock(TcN::Clock::div2048));
        #endif

        #if DEFINED(TC_N(CLOCK_4096_ID))
            TEST_REG_WRITE(TcN::clock(TcN::Clock::div4096));
        #endif

        #if DEFINED(TC_N(CLOCK_8192_ID))
            TEST_REG_WRITE(TcN::clock(TcN::Clock::div8192));
        #endif

        #if DEFINED(TC_N(CLOCK_16384_ID))
            TEST_REG_WRITE(TcN::clock(TcN::Clock::div16384));
        #endif

        #if DEFINED(TC_N(CLOCK_EXT_FALLING_ID))
            TEST_REG_WRITE(TcN::clock(TcN::Clock::extFalling));
        #endif

        #if DEFINED(TC_N(CLOCK_EXT_RISING_ID))
            TEST_REG_WRITE(TcN::clock(TcN::Clock::extRising));
        #endif
    }
#endif

#if REG_DEFINED(TC_N(WAVEFORM_REG))
    TEST(TcN, waveform) {
        #if DEFINED(TC_N(WAVEFORM_NORMAL_ID))
            TEST_REG_WRITE(TcN::waveform(TcN::Waveform::normal));
        #endif

        #if DEFINED(TC_N(WAVEFORM_PWM_PHASE_CORRECT_ID))
            TEST_REG_WRITE(TcN::waveform(TcN::Waveform::pwm));
        #endif

        #if DEFINED(TC_N(WAVEFORM_PWM_PHASE_CORRECT_8_ID))
            TEST_REG_WRITE(TcN::waveform(TcN::Waveform::pwm8Bit));
        #endif

        #if DEFINED(TC_N(WAVEFORM_PWM_PHASE_CORRECT_9_ID))
            TEST_REG_WRITE(TcN::waveform(TcN::Waveform::pwm9Bit));
        #endif

        #if DEFINED(TC_N(WAVEFORM_PWM_PHASE_CORRECT_10_ID))
            TEST_REG_WRITE(TcN::waveform(TcN::Waveform::pwm10Bit));
        #endif

        #if DEFINED(TC_N(WAVEFORM_CTC_OCRA_ID))
            TEST_REG_WRITE(TcN::waveform(TcN::Waveform::ctcOcra));
        #endif

        #if DEFINED(TC_N(WAVEFORM_CTC_OCRC_ID))
            TEST_REG_WRITE(TcN::waveform(TcN::Waveform::ctcOcrc));
        #endif

        #if DEFINED(TC_N(WAVEFORM_CTC_ICR_ID))
            TEST_REG_WRITE(TcN::waveform(TcN::Waveform::ctcIcr));
        #endif

        #if DEFINED(TC_N(WAVEFORM_FAST_PWM_8_ID))
            TEST_REG_WRITE(TcN::waveform(TcN::Waveform::fastPwm8Bit));
        #endif

        #if DEFINED(TC_N(WAVEFORM_FAST_PWM_9_ID))
            TEST_REG_WRITE(TcN::waveform(TcN::Waveform::fastPwm9Bit));
        #endif

        #if DEFINED(TC_N(WAVEFORM_FAST_PWM_10_ID))
            TEST_REG_WRITE(TcN::waveform(TcN::Waveform::fastPwm10Bit));
        #endif

        #if DEFINED(TC_N(WAVEFORM_FAST_PWM_ID))
            TEST_REG_WRITE(TcN::waveform(TcN::Waveform::fastPwm));
        #endif

        #if DEFINED(TC_N(WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID))
            TEST_REG_WRITE(TcN::waveform(TcN::Waveform::pwmOcra));
        #endif

        #if DEFINED(TC_N(WAVEFORM_FAST_PWM_OCRA_ID))
            TEST_REG_WRITE(TcN::waveform(TcN::Waveform::fastPwmOcra));
        #endif

        #if DEFINED(TC_N(WAVEFORM_FAST_PWM_OCRC_ID))
            TEST_REG_WRITE(TcN::waveform(TcN::Waveform::fastPwmOcrc));
        #endif

        #if DEFINED(TC_N(WAVEFORM_FAST_PWM_A_OCRC_ID))
            TEST_REG_WRITE(TcN::waveform(TcN::Waveform::fastPwmAOcrc));
        #endif

        #if DEFINED(TC_N(WAVEFORM_FAST_PWM_B_OCRC_ID))
            TEST_REG_WRITE(TcN::waveform(TcN::Waveform::fastPwmBOcrc));
        #endif

        #if DEFINED(TC_N(WAVEFORM_FAST_PWM_A_B_OCRC_ID))
            TEST_REG_WRITE(TcN::waveform(TcN::Waveform::fastPwmABOcrc));
        #endif

        #if DEFINED(TC_N(WAVEFORM_FREQUENCY_ID))
            TEST_REG_WRITE(TcN::waveform(TcN::Waveform::frequency));
        #endif

        #if DEFINED(TC_N(WAVEFORM_SINGLE_SLOPE_PWM_ID))
            TEST_REG_WRITE(TcN::waveform(TcN::Waveform::singleSlopePwm));
        #endif

        #if DEFINED(TC_N(WAVEFORM_DUAL_SLOPE_PWM_OVF_TOP_ID))
            TEST_REG_WRITE(TcN::waveform(TcN::Waveform::dualSlopePwmOverflowTop));
        #endif

        #if DEFINED(TC_N(WAVEFORM_DUAL_SLOPE_PWM_OVF_BOTTOM_ID))
            TEST_REG_WRITE(TcN::waveform(TcN::Waveform::dualSlopePwmOverflowBottom));
        #endif

        #if DEFINED(TC_N(WAVEFORM_DUAL_SLOPE_PWM_OVF_BOTH_ID))
            TEST_REG_WRITE(TcN::waveform(TcN::Waveform::dualSlopePwmOverflowBoth));
        #endif
    }
#endif

#if REG_DEFINED(TC_N(OVERFLOW_INT_ENABLE_REG))
    TEST(TcN, overflowIntEnable) {
        TEST_REG_WRITE(TcN::overflowIntEnable(true));
        TEST_REG_WRITE(TcN::overflowIntEnable(false));
    }
#endif

#if REG_DEFINED(TC_N(OVERFLOW_INT_FLAG_REG))
    TEST(TcN, overflowIntFlag) {
        TEST_REG_READ_WRITE(TcN::overflowIntFlag());
    }

    TEST(TcN, overflowIntFlagClear) {
        TEST_REG_WRITE(TcN::overflowIntFlagClear());
    }
#endif

#if REG_DEFINED(TC_N(PRESCALER_RESET_REG))
    TEST(TcN, prescalerReset) {
        TEST_REG_WRITE(TcN::prescalerReset());
    }
#endif

#if REG_DEFINED(TC_N(SYNCHRONIZE_REG))
    TEST(TcN, synchronizeMode) {
        TEST_REG_WRITE(TcN::synchronizeMode(true));
        TEST_REG_WRITE(TcN::synchronizeMode(false));
    }
#endif

#if REG_DEFINED(TC_N(COMPARE_A_REG))
    TEST(TcN, compareA) {
        TEST_REG_WRITE(TcN::compareA(0x12));
        TEST_REG_READ_WRITE(TcN::compareA());
    }
#endif

#if REG_DEFINED(TC_N(COMPARE_B_REG))
    TEST(TcN, compareB) {
        TEST_REG_WRITE(TcN::compareB(0x12));
        TEST_REG_READ_WRITE(TcN::compareB());
    }
#endif

#if REG_DEFINED(TC_N(COMPARE_C_REG))
    TEST(TcN, compareC) {
        TEST_REG_WRITE(TcN::compareC(0x12));
        TEST_REG_READ_WRITE(TcN::compareC());
    }
#endif

#if REG_DEFINED(TC_N(COMPARE_A_BUFFER_REG))
    TEST(TcN, compareABuffer) {
        TEST_REG_WRITE(TcN::compareABuffer(0x12));
        TEST_REG_READ_WRITE(TcN::compareABuffer());
    }
#endif

#if REG_DEFINED(TC_N(COMPARE_B_BUFFER_REG))
    TEST(TcN, compareBBuffer) {
        TEST_REG_WRITE(TcN::compareBBuffer(0x12));
        TEST_REG_READ_WRITE(TcN::compareBBuffer());
    }
#endif

#if REG_DEFINED(TC_N(COMPARE_C_BUFFER_REG))
    TEST(TcN, compareCBuffer) {
        TEST_REG_WRITE(TcN::compareCBuffer(0x12));
        TEST_REG_READ_WRITE(TcN::compareCBuffer());
    }
#endif

#if REG_DEFINED(TC_N(COMPARE_A_OUTPUT_ENABLE_REG))
    TEST(TcN, compareAOutputEnable) {
        TEST_REG_WRITE(TcN::compareAOutputEnable(true));
        TEST_REG_WRITE(TcN::compareAOutputEnable(false));
    }
#endif

#if REG_DEFINED(TC_N(COMPARE_B_OUTPUT_ENABLE_REG))
    TEST(TcN, compareBOutputEnable) {
        TEST_REG_WRITE(TcN::compareBOutputEnable(true));
        TEST_REG_WRITE(TcN::compareBOutputEnable(false));
    }
#endif

#if REG_DEFINED(TC_N(COMPARE_C_OUTPUT_ENABLE_REG))
    TEST(TcN, compareCOutputEnable) {
        TEST_REG_WRITE(TcN::compareCOutputEnable(true));
        TEST_REG_WRITE(TcN::compareCOutputEnable(false));
    }
#endif

#if REG_DEFINED(TC_N(COMPARE_A_OUTPUT_MODE_REG))
    TEST(TcN, compareAOutputMode) {
        #if DEFINED(TC_N(COMPARE_A_OUTPUT_MODE_DISCONNECTED_ID))
            TEST_REG_WRITE(TcN::compareAOutputMode(TcN::CompareAOutputMode::disconnected));
        #endif

        #if DEFINED(TC_N(COMPARE_A_OUTPUT_MODE_TOGGLE_ID))
            TEST_REG_WRITE(TcN::compareAOutputMode(TcN::CompareAOutputMode::toggle));
        #endif

        #if DEFINED(TC_N(COMPARE_A_OUTPUT_MODE_CLEAR_ID))
            TEST_REG_WRITE(TcN::compareAOutputMode(TcN::CompareAOutputMode::clear));
        #endif

        #if DEFINED(TC_N(COMPARE_A_OUTPUT_MODE_SET_ID))
            TEST_REG_WRITE(TcN::compareAOutputMode(TcN::CompareAOutputMode::set));
        #endif
    }
#endif

#if REG_DEFINED(TC_N(COMPARE_B_OUTPUT_MODE_REG))
    TEST(TcN, compareBOutputMode) {
        #if DEFINED(TC_N(COMPARE_B_OUTPUT_MODE_DISCONNECTED_ID))
            TEST_REG_WRITE(TcN::compareBOutputMode(TcN::CompareBOutputMode::disconnected));
        #endif

        #if DEFINED(TC_N(COMPARE_B_OUTPUT_MODE_TOGGLE_ID))
            TEST_REG_WRITE(TcN::compareBOutputMode(TcN::CompareBOutputMode::toggle));
        #endif

        #if DEFINED(TC_N(COMPARE_B_OUTPUT_MODE_CLEAR_ID))
            TEST_REG_WRITE(TcN::compareBOutputMode(TcN::CompareBOutputMode::clear));
        #endif

        #if DEFINED(TC_N(COMPARE_B_OUTPUT_MODE_SET_ID))
            TEST_REG_WRITE(TcN::compareBOutputMode(TcN::CompareBOutputMode::set));
        #endif
    }
#endif

#if REG_DEFINED(TC_N(COMPARE_C_OUTPUT_MODE_REG))
    TEST(TcN, compareCOutputMode) {
        #if DEFINED(TC_N(COMPARE_C_OUTPUT_MODE_DISCONNECTED_ID))
            TEST_REG_WRITE(TcN::compareCOutputMode(TcN::CompareCOutputMode::disconnected));
        #endif

        #if DEFINED(TC_N(COMPARE_C_OUTPUT_MODE_TOGGLE_ID))
            TEST_REG_WRITE(TcN::compareCOutputMode(TcN::CompareCOutputMode::toggle));
        #endif

        #if DEFINED(TC_N(COMPARE_C_OUTPUT_MODE_CLEAR_ID))
            TEST_REG_WRITE(TcN::compareCOutputMode(TcN::CompareCOutputMode::clear));
        #endif

        #if DEFINED(TC_N(COMPARE_C_OUTPUT_MODE_SET_ID))
            TEST_REG_WRITE(TcN::compareCOutputMode(TcN::CompareCOutputMode::set));
        #endif
    }
#endif

#if REG_DEFINED(TC_N(COMPARE_A_INT_ENABLE_REG))
    TEST(TcN, compareAIntEnable) {
        TEST_REG_WRITE(TcN::compareAIntEnable(true));
        TEST_REG_WRITE(TcN::compareAIntEnable(false));
    }
#endif

#if REG_DEFINED(TC_N(COMPARE_B_INT_ENABLE_REG))
    TEST(TcN, compareBIntEnable) {
        TEST_REG_WRITE(TcN::compareBIntEnable(true));
        TEST_REG_WRITE(TcN::compareBIntEnable(false));
    }
#endif

#if REG_DEFINED(TC_N(COMPARE_C_INT_ENABLE_REG))
    TEST(TcN, compareCIntEnable) {
        TEST_REG_WRITE(TcN::compareCIntEnable(true));
        TEST_REG_WRITE(TcN::compareCIntEnable(false));
    }
#endif

#if REG_DEFINED(TC_N(COMPARE_A_INT_FLAG_REG))
    TEST(TcN, compareAIntFlag) {
        TEST_REG_READ_WRITE(TcN::compareAIntFlag());
    }

    TEST(TcN, compareAIntFlagClear) {
        TEST_REG_WRITE(TcN::compareAIntFlagClear());
    }
#endif

#if REG_DEFINED(TC_N(COMPARE_B_INT_FLAG_REG))
    TEST(TcN, compareBIntFlag) {
        TEST_REG_READ_WRITE(TcN::compareBIntFlag());
    }

    TEST(TcN, compareBIntFlagClear) {
        TEST_REG_WRITE(TcN::compareBIntFlagClear());
    }
#endif

#if REG_DEFINED(TC_N(COMPARE_C_INT_FLAG_REG))
    TEST(TcN, compareCIntFlag) {
        TEST_REG_READ_WRITE(TcN::compareCIntFlag());
    }

    TEST(TcN, compareCIntFlagClear) {
        TEST_REG_WRITE(TcN::compareCIntFlagClear());
    }
#endif

#if REG_DEFINED(TC_N(CAPTURE_REG))
    TEST(TcN, capture) {
        TEST_REG_WRITE(TcN::capture(0x1234));
        TEST_REG_READ_WRITE(TcN::capture());
    }
#endif

#if REG_DEFINED(TC_N(CAPTURE_REG))
    TEST(TcN, captureEdge) {
        TEST_REG_WRITE(TcN::captureEdge(TcN::CaptureEdge::rising));
        TEST_REG_WRITE(TcN::captureEdge(TcN::CaptureEdge::falling));
    }
#endif

#if REG_DEFINED(TC_N(CAPTURE_NOISE_CANCEL_ENABLE_REG))
    TEST(TcN, captureNoiseCancelEnable) {
        TEST_REG_WRITE(TcN::captureNoiseCancelEnable(true));
        TEST_REG_WRITE(TcN::captureNoiseCancelEnable(false));
    }
#endif

#if REG_DEFINED(TC_N(CAPTURE_INT_ENABLE_REG))
    TEST(TcN, captureIntEnable) {
        TEST_REG_WRITE(TcN::captureIntEnable(true));
        TEST_REG_WRITE(TcN::captureIntEnable(false));
    }
#endif

#if REG_DEFINED(TC_N(CAPTURE_INT_FLAG_REG))
    TEST(TcN, captureIntFlag) {
        TEST_REG_READ_WRITE(TcN::captureIntFlag());
    }

    TEST(TcN, captureIntFlagClear) {
            TEST_REG_WRITE(TcN::captureIntFlagClear());
    }
#endif

#if REG_DEFINED(TC_N(SPLIT_MODE_ENABLE_REG))
    TEST(TcN, splitModeEnable) {
        TEST_REG_WRITE(TcN::splitModeEnable(true));
        TEST_REG_WRITE(TcN::splitModeEnable(false));
    }
#endif

#if REG_DEFINED(TC_N(LOW_COUNTER_REG))
    TEST(TcN, lowCounter) {
        TEST_REG_WRITE(TcN::lowCounter(0x12));
        TEST_REG_READ_WRITE(TcN::lowCounter());
    }
#endif

#if REG_DEFINED(TC_N(HIGH_COUNTER_REG))
    TEST(TcN, highCounter) {
        TEST_REG_WRITE(TcN::highCounter(0x12));
        TEST_REG_READ_WRITE(TcN::highCounter());
    }
#endif

#if REG_DEFINED(TC_N(LOW_TOP_REG))
    TEST(TcN, lowTop) {
        TEST_REG_WRITE(TcN::lowTop(0x12));
        TEST_REG_READ_WRITE(TcN::lowTop());
    }
#endif

#if REG_DEFINED(TC_N(HIGH_TOP_REG))
    TEST(TcN, highTop) {
        TEST_REG_WRITE(TcN::highTop(0x12));
        TEST_REG_READ_WRITE(TcN::highTop());
    }
#endif

#if REG_DEFINED(TC_N(LOW_COMPARE_A_REG))
    TEST(TcN, lowCompareA) {
        TEST_REG_WRITE(TcN::lowCompareA(0x12));
        TEST_REG_READ_WRITE(TcN::lowCompareA());
    }
#endif

#if REG_DEFINED(TC_N(LOW_COMPARE_B_REG))
    TEST(TcN, lowCompareB) {
        TEST_REG_WRITE(TcN::lowCompareB(0x12));
        TEST_REG_READ_WRITE(TcN::lowCompareB());
    }
#endif

#if REG_DEFINED(TC_N(LOW_COMPARE_C_REG))
    TEST(TcN, lowCompareC) {
        TEST_REG_WRITE(TcN::lowCompareC(0x12));
        TEST_REG_READ_WRITE(TcN::lowCompareC());
    }
#endif

#if REG_DEFINED(TC_N(HIGH_COMPARE_A_REG))
    TEST(TcN, highCompareA) {
        TEST_REG_WRITE(TcN::highCompareA(0x12));
        TEST_REG_READ_WRITE(TcN::highCompareA());
    }
#endif

#if REG_DEFINED(TC_N(HIGH_COMPARE_B_REG))
    TEST(TcN, highCompareB) {
        TEST_REG_WRITE(TcN::highCompareB(0x12));
        TEST_REG_READ_WRITE(TcN::highCompareB());
    }
#endif

#if REG_DEFINED(TC_N(HIGH_COMPARE_C_REG))
    TEST(TcN, highCompareC) {
        TEST_REG_WRITE(TcN::highCompareC(0x12));
        TEST_REG_READ_WRITE(TcN::highCompareC());
    }
#endif

#if REG_DEFINED(TC_N(LOW_COMPARE_A_OUTPUT_ENABLE_REG))
    TEST(TcN, lowCompareAOutputEnable) {
        TEST_REG_WRITE(TcN::lowCompareAOutputEnable(true));
        TEST_REG_WRITE(TcN::lowCompareAOutputEnable(false));
    }
#endif

#if REG_DEFINED(TC_N(LOW_COMPARE_B_OUTPUT_ENABLE_REG))
    TEST(TcN, lowCompareBOutputEnable) {
        TEST_REG_WRITE(TcN::lowCompareBOutputEnable(true));
        TEST_REG_WRITE(TcN::lowCompareBOutputEnable(false));
    }
#endif

#if REG_DEFINED(TC_N(LOW_COMPARE_C_OUTPUT_ENABLE_REG))
    TEST(TcN, lowCompareCOutputEnable) {
        TEST_REG_WRITE(TcN::lowCompareCOutputEnable(true));
        TEST_REG_WRITE(TcN::lowCompareCOutputEnable(false));
    }
#endif

#if REG_DEFINED(TC_N(HIGH_COMPARE_A_OUTPUT_ENABLE_REG))
    TEST(TcN, highCompareAOutputEnable) {
        TEST_REG_WRITE(TcN::highCompareAOutputEnable(true));
        TEST_REG_WRITE(TcN::highCompareAOutputEnable(false));
    }
#endif

#if REG_DEFINED(TC_N(HIGH_COMPARE_B_OUTPUT_ENABLE_REG))
    TEST(TcN, highCompareBOutputEnable) {
        TEST_REG_WRITE(TcN::highCompareBOutputEnable(true));
        TEST_REG_WRITE(TcN::highCompareBOutputEnable(false));
    }
#endif

#if REG_DEFINED(TC_N(HIGH_COMPARE_C_OUTPUT_ENABLE_REG))
    TEST(TcN, highCompareCOutputEnable) {
        TEST_REG_WRITE(TcN::highCompareCOutputEnable(true));
        TEST_REG_WRITE(TcN::highCompareCOutputEnable(false));
    }
#endif

#if REG_DEFINED(TC_N(LOW_COMPARE_A_INT_ENABLE_REG))
    TEST(TcN, lowCompareAIntEnable) {
        TEST_REG_WRITE(TcN::lowCompareAIntEnable(true));
        TEST_REG_WRITE(TcN::lowCompareAIntEnable(false));
    }
#endif

#if REG_DEFINED(TC_N(LOW_COMPARE_B_INT_ENABLE_REG))
    TEST(TcN, lowCompareBIntEnable) {
        TEST_REG_WRITE(TcN::lowCompareBIntEnable(true));
        TEST_REG_WRITE(TcN::lowCompareBIntEnable(false));
    }
#endif

#if REG_DEFINED(TC_N(LOW_COMPARE_C_INT_ENABLE_REG))
    TEST(TcN, lowCompareCIntEnable) {
        TEST_REG_WRITE(TcN::lowCompareCIntEnable(true));
        TEST_REG_WRITE(TcN::lowCompareCIntEnable(false));
    }
#endif

#if REG_DEFINED(TC_N(LOW_COMPARE_A_INT_FLAG_REG))
    TEST(TcN, lowCompareAIntFlag) {
        TEST_REG_READ_WRITE(TcN::lowCompareAIntFlag());
        TEST_REG_WRITE(TcN::lowCompareAIntFlagClear());
    }
#endif

#if REG_DEFINED(TC_N(LOW_COMPARE_B_INT_FLAG_REG))
    TEST(TcN, lowCompareBIntFlag) {
        TEST_REG_READ_WRITE(TcN::lowCompareBIntFlag());
        TEST_REG_WRITE(TcN::lowCompareBIntFlagClear());
    }
#endif

#if REG_DEFINED(TC_N(LOW_COMPARE_C_INT_FLAG_REG))
    TEST(TcN, lowCompareCIntFlag) {
        TEST_REG_READ_WRITE(TcN::lowCompareCIntFlag());
        TEST_REG_WRITE(TcN::lowCompareCIntFlagClear());
    }
#endif

#if REG_DEFINED(TC_N(LOW_UNDERFLOW_INT_ENABLE_REG))
    TEST(TcN, lowUnderflowIntEnable) {
        TEST_REG_WRITE(TcN::lowUnderflowIntEnable(true));
        TEST_REG_WRITE(TcN::lowUnderflowIntEnable(false));
    }
#endif

#if REG_DEFINED(TC_N(LOW_UNDERFLOW_INT_FLAG_REG))
    TEST(TcN, lowUnderflowIntFlag) {
        TEST_REG_READ_WRITE(TcN::lowUnderflowIntFlag());
        TEST_REG_WRITE(TcN::lowUnderflowIntFlagClear());
    }
#endif

#if REG_DEFINED(TC_N(HIGH_UNDERFLOW_INT_ENABLE_REG))
    TEST(TcN, highUnderflowIntEnable) {
        TEST_REG_WRITE(TcN::highUnderflowIntEnable(true));
        TEST_REG_WRITE(TcN::highUnderflowIntEnable(false));
    }
#endif

#if REG_DEFINED(TC_N(HIGH_UNDERFLOW_INT_FLAG_REG))
    TEST(TcN, highUnderflowIntFlag) {
        TEST_REG_READ_WRITE(TcN::highUnderflowIntFlag());
        TEST_REG_WRITE(TcN::highUnderflowIntFlagClear());
    }
#endif

#endif // TEST

} // nblib::hw

//--------------------------------------------------------

    #endif

    #undef N
    #undef TcN
    #undef TC_N

    #include "tc.hpp"
#else
    #define NBLIB_TC_HPP
#endif

#endif
