/// # {{Timers}}

/// ```c++
/// // Constant interval.
///
/// using Timer = nbos::hw::Timer1;
///
/// nbos::hw::Pin::Value value = nbos::hw::Pin::Value::low;
///
/// const auto f = [](nbos::hw::Pin::Value* value) {
///     *value = nbos::hw::PortB::Pin5::input();
/// };
///
/// atomic([]() {
///     Timer::waveform(Timer::Waveform::ctcOcra);
///     Timer::OutputA::value(2036);
///     Timer::clock(Timer::Clock::Div16);
///     Timer::intEnable(true);
///     Timer::callback((callback_t)f, &value);
/// });
/// ```

#ifndef NBOS_TIMER_HPP

#include "isr.hpp"
#include "chip.hpp"
#include "hardwaretype.hpp"
#include "macros.hpp"
#include "system.hpp"

#include "loopi"

#ifdef _I
    #define N _I
    #define TimerN CAT(Timer, N)
    #define TIMER_N(A) CAT(CHIP_TIMER_, N, _, A)

    #if CAT(CHIP_TIMER_, N)

//--------------------------------------------------------

namespace nbos::hw {

/// ## Class {{TimerN}}
struct TimerN {
    /// #### using type = T
    /// The underlying type of this timer/counter. (uint8_t or uint16_t)
    using type = REGTYPE(TIMER_N(COUNTER_REG));

    TimerN() = delete;

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
    enum class Clock : uint8_t {
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
    enum class Waveform : uint8_t {
        #if DEFINED(TIMER_N(WAVEFORM_NORMAL_ID))
            normal = TIMER_N(WAVEFORM_NORMAL_ID),
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_PWM_PHASE_CORRECT_ID))
            pwm = TIMER_N(WAVEFORM_PWM_PHASE_CORRECT_ID),
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_CTC_OCRA_ID))
            ctcOcra = TIMER_N(WAVEFORM_CTC_OCRA_ID),
        #endif

        #if DEFINED(TIMER_N(WAVEFORM_CTC_OCRC_ID))
            ctcOcrc = TIMER_N(WAVEFORM_CTC_OCRC_ID),
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
    };

    /// #### static [[HardwareType]] getHardwareType()
    static constexpr HardwareType getHardwareType() {
        return HardwareType::timer;
    }

    /// #### static void counter(T value)
    static force_inline void counter(REGTYPE(TIMER_N(COUNTER_REG)) value) {
        *REG(TIMER_N(COUNTER_REG)) = value;
    }

    /// #### static T counter()
    static force_inline REGTYPE(TIMER_N(COUNTER_REG)) counter() {
        return *REG(TIMER_N(COUNTER_REG));
    }

    #if DEFINED(TIMER_N(CLOCK_BIT_0_BIT))
        /// #### static void clock([[TimerN::Clock]] c)
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
        /// #### static void waveform([[TimerN::Waveform]] w)
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

    /// #### static void callback([[callback_t]] callback, void\* data)
    /// Set the timer overflow callback.
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

    #if DEFINED(TIMER_N(OVERFLOW_INT_ENABLE_BIT))
        /// #### static void intEnable(bool b)
        static force_inline void intEnable(bool b) {
            if(b) {
                *REG(TIMER_N(OVERFLOW_INT_ENABLE_REG)) |= bv(TIMER_N(OVERFLOW_INT_ENABLE_BIT));
            } else {
                *REG(TIMER_N(OVERFLOW_INT_ENABLE_REG)) &= ~bv(TIMER_N(OVERFLOW_INT_ENABLE_BIT));
            }
        }
    #endif

    #if DEFINED(TIMER_N(OVERFLOW_INT_ENABLE_BIT))
        /// #### static bool intFlag()
        static force_inline bool intFlag() {
            return *REG(TIMER_N(OVERFLOW_INT_FLAG_REG)) & bv(TIMER_N(OVERFLOW_INT_FLAG_BIT));
        }
    #endif

    #if DEFINED(TIMER_N(OVERFLOW_INT_FLAG_BIT))
        /// #### static void intFlagClear()
        static force_inline void intFlagClear() {
            *REG(TIMER_N(OVERFLOW_INT_FLAG_REG)) |= bv(TIMER_N(OVERFLOW_INT_FLAG_BIT));
        }
    #endif

    /// ## class OutputX
    /// See [[TimerN::OutputX]]

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
    /// See [[TimerN::Input]]

    #if TIMER_N(INPUT)
        #include "input.hpp"
    #endif
};

#if TIMER_N(OUTPUT_A_MODE_BIT_1_BIT)
    ISR(TIMER_N(OUTPUT_A_INT_VECTOR)) {
        TimerN::OutputA::callback();
    }
#endif

#if TIMER_N(OUTPUT_B_MODE_BIT_1_BIT)
    ISR(TIMER_N(OUTPUT_B_INT_VECTOR)) {
        TimerN::OutputB::callback();
    }
#endif

#if TIMER_N(OUTPUT_C_MODE_BIT_1_BIT)
    ISR(TIMER_N(OUTPUT_C_INT_VECTOR)) {
        TimerN::OutputC::callback();
    }
#endif

#if TIMER_N(INPUT)
    ISR(TIMER_N(INPUT_INT_VECTOR)) {
        TimerN::Input::callback();
    }
#endif

ISR(TIMER_N(OVERFLOW_INT_VECTOR)) {
    TimerN::callback();
}

} // nbos::hw

//--------------------------------------------------------

    #endif

    #undef N
    #undef TimerN
    #undef TIMER_N

    #include "timer.hpp"
#else
    #define NBOS_TIMER_HPP
#endif


#endif
