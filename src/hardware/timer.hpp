/// # Timers

/// ## Example
/// ```c++
/// // TODO
/// ```

/// N is the timer's id (1, 2, etc).<br>
/// T is the type of the timer's counter, either uint8_t or uint16_t.<br>

#ifndef NBAVR_TIMER_HPP

#include "callbacks.hpp"
#include "chip.hpp"
#include "hardwaretype.hpp"
#include "macros.hpp"
#include "util.hpp"

#define N _I
#define TimerN CAT(Timer, N)
#define TIMER_N(A) CAT(CHIP_TIMER_, N, _, A)
#define _TIMER_N(A) UNDERLINE(TIMER, N, A)

/// #### macro INCLUDE_TIMER_OUTPUT_CALLBACK(N, X)
/// Include this to use Timer output callbacks.
#define INCLUDE_TIMER_OUTPUT_CALLBACK(N, X) MAKE_CALLBACK(TIMER, N, OUTPUT, X)

/// #### macro INCLUDE_TIMER_OVERFLOW_CALLBACK(N)
/// Include this to use Timer overflow callbacks.
#define INCLUDE_TIMER_OVERFLOW_CALLBACK(N) MAKE_CALLBACK(TIMER, N, OVERFLOW)

/// #### macro INCLUDE_TIMER_INPUT_CALLBACK(N)
/// Include this to use Timer input callbacks.
#define INCLUDE_TIMER_INPUT_CALLBACK(N) MAKE_CALLBACK(TIMER, N, INPUT)

#include "loopi"

#ifdef _I
    #if CAT(CHIP_TIMER_, N)

//--------------------------------------------------------

#if TIMER_N(OUTPUT_A)
    MAKE_CALLBACK_HEADER(TIMER, N, OUTPUT_A);
#endif

#if TIMER_N(OUTPUT_B)
    MAKE_CALLBACK_HEADER(TIMER, N, OUTPUT_B);
#endif

#if TIMER_N(OUTPUT_C)
    MAKE_CALLBACK_HEADER(TIMER, N, OUTPUT_C);
#endif

MAKE_CALLBACK_HEADER(TIMER, N, OVERFLOW);

#if TIMER_N(INPUT)
    MAKE_CALLBACK_HEADER(TIMER, N, INPUT);
#endif

/// ## Class TimerN
struct TimerN {
    /// #### using type = T
    /// The underlying type of this timer/counter. (uint8_t or uint16_t)
    using type = REGTYPE(TIMER_N(COUNTER_REG));

    TimerN() = delete;

    /// #### enum Clock
    /// * None (No clock)
    /// * Div1 (cpu frequency / 1)
    /// * Div8
    /// * Div32
    /// * Div64
    /// * Div128
    /// * Div256
    /// * Div1024
    /// * ExtFalling (clock on external pin falling edge)
    /// * ExtRising
    enum class Clock : uint8_t {
        #if DEFINED(TIMER_N(CLOCK_NONE_ID))
            None = TIMER_N(CLOCK_NONE_ID),
        #endif

        #if DEFINED(TIMER_N(CLOCK_1_ID))
            Div1 = TIMER_N(CLOCK_1_ID),
        #endif

        #if DEFINED(TIMER_N(CLOCK_2_ID))
            Div2 = TIMER_N(CLOCK_2_ID),
        #endif

        #if DEFINED(TIMER_N(CLOCK_4_ID))
            Div4 = TIMER_N(CLOCK_4_ID),
        #endif

        #if DEFINED(TIMER_N(CLOCK_8_ID))
            Div8 = TIMER_N(CLOCK_8_ID),
        #endif

        #if DEFINED(TIMER_N(CLOCK_16_ID))
            Div16 = TIMER_N(CLOCK_16_ID),
        #endif

        #if TIMER_N(CLOCK_32_ID)
            Div32 = TIMER_N(CLOCK_32_ID),
        #endif

        #if TIMER_N(CLOCK_64_ID)
            Div64 = TIMER_N(CLOCK_64_ID),
        #endif

        #if TIMER_N(CLOCK_128_ID)
            Div128 = TIMER_N(CLOCK_128_ID),
        #endif

        #if TIMER_N(CLOCK_256_ID)
            Div256 = TIMER_N(CLOCK_256_ID),
        #endif

        #if DEFINED(TIMER_N(CLOCK_512_ID))
            Div512 = TIMER_N(CLOCK_512_ID),
        #endif

        #if DEFINED(TIMER_N(CLOCK_1024_ID))
            Div1024 = TIMER_N(CLOCK_1024_ID),
        #endif

        #if DEFINED(TIMER_N(CLOCK_2048_ID))
            Div2048 = TIMER_N(CLOCK_2048_ID),
        #endif

        #if DEFINED(TIMER_N(CLOCK_4096_ID))
            Div4096 = TIMER_N(CLOCK_4096_ID),
        #endif

        #if DEFINED(TIMER_N(CLOCK_8192_ID))
            Div8192 = TIMER_N(CLOCK_8192_ID),
        #endif

        #if DEFINED(TIMER_N(CLOCK_16384_ID))
            Div16384 = TIMER_N(CLOCK_16384_ID),
        #endif

        #if TIMER_N(CLOCK_EXT_FALLING_ID)
            ExtFalling = TIMER_N(CLOCK_EXT_FALLING_ID),
        #endif

        #if TIMER_N(CLOCK_EXT_RISING_ID)
            ExtRising = TIMER_N(CLOCK_EXT_RISING_ID),
        #endif
    };

    /// #### enum Waveform
    /// * Normal
    /// * PWM
    /// * CTCOCRA
    /// * FastPWM
    /// * PWMOCRA
    /// * FastPWMOCRA
    enum class Waveform : uint8_t {
        #if DEFINED(TIMER_N(WAVEFORM_NORMAL_ID))
            Normal = TIMER_N(WAVEFORM_NORMAL_ID),
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_PWM_PHASE_CORRECT_ID))
            PWM = TIMER_N(WAVEFORM_PWM_PHASE_CORRECT_ID),
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_CTC_OCRA_ID))
            CTCOCRA = TIMER_N(WAVEFORM_CTC_OCRA_ID),
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_CTC_OCRC_ID))
            CTCOCRC = TIMER_N(WAVEFORM_CTC_OCRC_ID),
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_FAST_PWM_ID))
            FastPWM = TIMER_N(WAVEFORM_FAST_PWM_ID),
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID))
            PWMOCRA = TIMER_N(WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID),
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_FAST_PWM_OCRA_ID))
            FastPWMOCRA = TIMER_N(WAVEFORM_FAST_PWM_OCRA_ID),
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_FAST_PWM_OCRC_ID))
            FastPWMOCRC = TIMER_N(WAVEFORM_FAST_PWM_OCRC_ID),
        #endif
    };

    /// #### static constexpr HardwareType getHardwareType()
    /// Get the type of hardware that this class represents.
    static constexpr HardwareType getHardwareType() {
        return HardwareType::timer;
    }

    /// #### static void counter(T value)
    /// Set the counter value.
    static force_inline void counter(REGTYPE(TIMER_N(COUNTER_REG)) value) {
        *REG(TIMER_N(COUNTER_REG)) = value;
    }

    /// #### static T counter()
    /// Get the counter value.
    static force_inline REGTYPE(TIMER_N(COUNTER_REG)) counter() {
        return *REG(TIMER_N(COUNTER_REG));
    }

    #if DEFINED(TIMER_N(CLOCK_BIT_0_BIT))
        /// #### static void clock(Clock c)
        /// Set the clock source.
        static force_inline void clock(Clock c) {
            setBit_(REG(TIMER_N(CLOCK_BIT_0_REG)), TIMER_N(CLOCK_BIT_0_BIT), uint8_t(c) & 0x01);
            setBit_(REG(TIMER_N(CLOCK_BIT_1_REG)), TIMER_N(CLOCK_BIT_1_BIT), uint8_t(c) & 0x02);
            setBit_(REG(TIMER_N(CLOCK_BIT_2_REG)), TIMER_N(CLOCK_BIT_2_BIT), uint8_t(c) & 0x04);

            #if DEFINED(TIMER_N(CLOCK_BIT_3_BIT))
                setBit_(REG(TIMER_N(CLOCK_BIT_3_REG)), TIMER_N(CLOCK_BIT_3_BIT), uint8_t(c) & 0x08);
            #endif
        }
    #endif

    #if DEFINED(TIMER_N(WAVEFORM_BIT_0_BIT))
        /// #### static void waveform(Waveform w)
        /// Set the counting method.
        static force_inline void waveform(Waveform w) {
            setBit_(REG(TIMER_N(WAVEFORM_BIT_0_REG)), TIMER_N(WAVEFORM_BIT_0_BIT), uint8_t(w) & 0x01);

            #if DEFINED(TIMER_N(WAVEFORM_BIT_1_BIT))
                setBit_(REG(TIMER_N(WAVEFORM_BIT_1_REG)), TIMER_N(WAVEFORM_BIT_1_BIT), uint8_t(w) & 0x02);
            #endif

            #if DEFINED(TIMER_N(WAVEFORM_BIT_2_BIT))
                setBit_(REG(TIMER_N(WAVEFORM_BIT_2_REG)), TIMER_N(WAVEFORM_BIT_2_BIT), uint8_t(w) & 0x04);
            #endif

            #if DEFINED(TIMER_N(WAVEFORM_BIT_3_BIT))
                setBit_(REG(TIMER_N(WAVEFORM_BIT_3_REG)), TIMER_N(WAVEFORM_BIT_3_BIT), uint8_t(w) & 0x08);
            #endif
        }
    #endif

    /// #### static void overflowCallback(callback_t callback, void\* data)
    /// Set the callback and data for the counter overflow interrupt.
    static force_inline void overflowCallback(callback_t callback, void* data) {
        _TIMER_N(OVERFLOW_Callback) = callback;
        _TIMER_N(OVERFLOW_CallbackData) = data;
    }

    #if DEFINED(TIMER_N(OVERFLOW_INT_ENABLE_BIT))
        /// #### static void overflowIntEnable(bool b)
        /// Enable/disable the counter overflow interrupt.
        static force_inline void overflowIntEnable(bool b) {
            if(b) {
                *REG(TIMER_N(OVERFLOW_INT_ENABLE_REG)) |= bv(TIMER_N(OVERFLOW_INT_ENABLE_BIT));
            } else {
                *REG(TIMER_N(OVERFLOW_INT_ENABLE_REG)) &= ~bv(TIMER_N(OVERFLOW_INT_ENABLE_BIT));
            }
        }
    #endif

    #if DEFINED(TIMER_N(OVERFLOW_INT_ENABLE_BIT))
        /// #### static bool overflowIntFlag()
        /// Returns true if the counter overflow flag is set.
        static force_inline bool overflowIntFlag() {
            return *REG(TIMER_N(OVERFLOW_INT_FLAG_REG)) & bv(TIMER_N(OVERFLOW_INT_FLAG_BIT));
        }
    #endif

    #if DEFINED(TIMER_N(OVERFLOW_INT_FLAG_BIT))
        /// #### static void overflowIntFlagClear()
        /// Clear the counter overflow interrupt flag.
        static force_inline void overflowIntFlagClear() {
            *REG(TIMER_N(OVERFLOW_INT_FLAG_REG)) |= bv(TIMER_N(OVERFLOW_INT_FLAG_BIT));
        }
    #endif

    /// ## class OutputX
    /// See [OutputX](output.md)

    #if TIMER_N(OUTPUT_A)
        #define ID A
        #include "output.hpp"
        #undef ID
    #endif

    #if TIMER_N(OUTPUT_B)
        #define ID B
        #include "output.hpp"
        #undef ID
    #endif

    #if TIMER_N(OUTPUT_C)
        #define ID C
        #include "output.hpp"
        #undef ID
    #endif

    /// ## class Input
    /// See [Input](input.md)

    #if TIMER_N(INPUT)
        #include "input.hpp"
    #endif
};

//--------------------------------------------------------

    #endif

    #include "timer.hpp"
#else
    #define NBAVR_TIMER_HPP
#endif

#undef N
#undef TimerN
#undef TIMER_N
#undef _TIMER_N

#endif
