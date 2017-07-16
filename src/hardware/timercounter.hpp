/// # Timer/Counters

/// ## Example
/// ```c++
/// // TODO
/// ```

/// N is the timer/counter id (1, 2, etc).<br>
/// T is the type of the timer's counter, either uint8_t or uint16_t.<br>

#ifndef NBAVR_TIMERCOUNTER_HPP

#ifndef N
    // TimerCounter id.
    #define N 0
#endif

#if N < CHIP_TIMERCOUNTER_COUNT
    // If this hardware exists.
    #if CONCAT(CHIP_TIMERCOUNTER_, N)

//--------------------------------------------------------

#define TimerCounterN CONCAT(TimerCounter, N)
#define C(A) CONCAT(CHIP_TIMERCOUNTER_, N, _, A)
#define _C(A) UNDERLINE(TIMERCOUNTER, N, A)

#if C(OUTPUTCOMPARE_A)
    MAKE_CALLBACK_HEADER(TIMERCOUNTER, N, OUTPUTCOMPARE_A);
#endif

#if C(OUTPUTCOMPARE_B)
    MAKE_CALLBACK_HEADER(TIMERCOUNTER, N, OUTPUTCOMPARE_B);
#endif

#if C(OUTPUTCOMPARE_C)
    MAKE_CALLBACK_HEADER(TIMERCOUNTER, N, OUTPUTCOMPARE_C);
#endif

MAKE_CALLBACK_HEADER(TIMERCOUNTER, N, OVERFLOW);

/// #### macro INCLUDE_TIMERCOUNTER_OUTPUT_CALLBACK(N, X)
/// Include this to use TimerCounter output compare callbacks.
#define INCLUDE_TIMERCOUNTER_OUTPUT_CALLBACK(N, X) MAKE_CALLBACK(TIMERCOUNTER, N, OUTPUTCOMPARE, X)

/// #### macro INCLUDE_TIMERCOUNTER_OVERFLOW_CALLBACK(N)
/// Include this to use TimerCounter overflow callbacks.
#define INCLUDE_TIMERCOUNTER_OVERFLOW_CALLBACK(N) MAKE_CALLBACK(TIMERCOUNTER, N, OVERFLOW)

/// ## Class TimerCounterN
struct TimerCounterN {
    /// #### typedef T type
    /// The underlying type of this timer/counter. (uint8_t or uint16_t)
    typedef C(TYPE) type;

    TimerCounterN() = delete;

    ///
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
        None = C(CLOCK_NONE_ID),
        Div1 = C(CLOCK_1_ID),
        Div8 = C(CLOCK_8_ID),
        #if C(CLOCK_32_ID)
        Div32 = C(CLOCK_32_ID),
        #endif
        Div64 = C(CLOCK_64_ID),
        #if C(CLOCK_128_ID)
        Div128 = C(CLOCK_128_ID),
        #endif
        Div256 = C(CLOCK_256_ID),
        Div1024 = C(CLOCK_1024_ID),
        #if C(CLOCK_EXT_FALLING_ID)
        ExtFalling = C(CLOCK_EXT_FALLING_ID),
        #endif
        #if C(CLOCK_EXT_RISING_ID)
        ExtRising = C(CLOCK_EXT_RISING_ID),
        #endif
    };

    // TODO Make it such that there is always a waveform enumeration with at least "Normal"
    //  so that waveform(Waveform::Normal) compiles on all chips.

    ///
    /// #### enum Waveform
    /// * Normal
    /// * PWM
    /// * CTCOCRA
    /// * FastPWM
    /// * PWMOCRA
    /// * FastPWMOCRA
    #if C(WAVEFORM)
    enum class Waveform : uint8_t {
        Normal = C(WAVEFORM_NORMAL_ID),
        #if C(WAVEFORM_PWM_PHASE_CORRECT_ID)
        PWM = C(WAVEFORM_PWM_PHASE_CORRECT_ID),
        #endif
        CTCOCRA = C(WAVEFORM_CTC_OCRA_ID),
        #if C(WAVEFORM_FAST_PWM_ID)
        FastPWM = C(WAVEFORM_FAST_PWM_ID),
        #endif
        #if C(WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID)
        PWMOCRA = C(WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID),
        #endif
        #if C(WAVEFORM_FAST_PWM_OCRA_ID)
        FastPWMOCRA = C(WAVEFORM_FAST_PWM_OCRA_ID),
        #endif
    };
    #endif

    ///
    /// #### enum OutputMode
    /// * Disconnected
    /// * Toggle
    /// * Clear
    /// * Set
    #if C(OUTPUTCOMPARE_MODE)
    enum class OutputMode : uint8_t {
        Disconnected = C(OUTPUTCOMPARE_MODE_DISCONNECTED_ID),
        Toggle = C(OUTPUTCOMPARE_MODE_TOGGLE_ID),
        Clear = C(OUTPUTCOMPARE_MODE_CLEAR_ID),
        Set = C(OUTPUTCOMPARE_MODE_SET_ID),
    };
    #endif

    ///
    /// #### static constexpr HardwareType getHardwareType()
    /// Get the type of hardware that this class represents.
    static constexpr HardwareType getHardwareType() {
        return HardwareType::TimerCounter;
    }

    ///
    /// #### static void counter(T)
    /// Set the counter value.
    static force_inline void counter(C(TYPE) value) {
        *C(COUNTER_REG) = value;
    }

    ///
    /// #### static T counter()
    /// Get the counter value.
    static force_inline C(TYPE) counter() {
        return *C(COUNTER_REG);
    }

    ///
    /// #### static void clock(Clock)
    /// Set the clock source.
    static force_inline void clock(Clock clock) {
        setBit_(C(CLOCK_BIT_0_REG), C(CLOCK_BIT_0_BIT), uint8_t(clock) & 0x01);
        setBit_(C(CLOCK_BIT_1_REG), C(CLOCK_BIT_1_BIT), uint8_t(clock) & 0x02);
        setBit_(C(CLOCK_BIT_2_REG), C(CLOCK_BIT_2_BIT), uint8_t(clock) & 0x04);
    }

    ///
    /// #### static void waveform(Waveform)
    /// Set the counting method.
    #if C(WAVEFORM)
    static force_inline void waveform(Waveform waveform) {
        #if C(WAVEFORM_BIT_COUNT) > 0
        setBit_(C(WAVEFORM_BIT_0_REG), C(WAVEFORM_BIT_0_BIT), uint8_t(waveform) & 0x01);
        #endif
        #if C(WAVEFORM_BIT_COUNT) > 1
        setBit_(C(WAVEFORM_BIT_1_REG), C(WAVEFORM_BIT_1_BIT), uint8_t(waveform) & 0x02);
        #endif
        #if C(WAVEFORM_BIT_COUNT) > 2
        setBit_(C(WAVEFORM_BIT_2_REG), C(WAVEFORM_BIT_2_BIT), uint8_t(waveform) & 0x04);
        #endif
        #if C(WAVEFORM_BIT_COUNT) > 3
        setBit_(C(WAVEFORM_BIT_3_REG), C(WAVEFORM_BIT_3_BIT), uint8_t(waveform) & 0x08);
        #endif
    }
    #endif

    ///
    /// #### static void overflowCallback(void (\*)(void\*), void\*)
    /// Set the callback and data for the counter overflow interrupt.
    static force_inline void overflowCallback(void (*func)(void*), void* data) {
        _C(OVERFLOW_Callback) = func;
        _C(OVERFLOW_CallbackData) = data;
    }

    ///
    /// #### static void overflowIntEnable(bool)
    /// Enable/disable the counter overflow interrupt.
    static force_inline void overflowIntEnable(bool b) {
        if(b) {
            *C(OVERFLOW_INT_ENABLE_REG) |= bv(C(OVERFLOW_INT_ENABLE_BIT));
        } else {
            *C(OVERFLOW_INT_ENABLE_REG) &= ~bv(C(OVERFLOW_INT_ENABLE_BIT));
        }
    }

    ///
    /// #### static bool overflowIntFlag()
    /// Returns true if the counter overflow flag is set.
    static force_inline bool overflowIntFlag() {
        return *C(OVERFLOW_INT_FLAG_REG) & bv(C(OVERFLOW_INT_FLAG_BIT));
    }

    ///
    /// #### static void overflowIntFlagClear()
    /// Clear the counter overflow interrupt flag.
    static force_inline void overflowIntFlagClear() {
        *C(OVERFLOW_INT_FLAG_REG) |= bv(C(OVERFLOW_INT_FLAG_BIT));
    }

    ///
    /// ## class OutputCompareX
    /// See [OutputCompareX](outputcompare.md)

    #if C(OUTPUTCOMPARE_A)
        #define ID A
        #include "outputcompare.hpp"
        #undef ID
    #endif

    #if C(OUTPUTCOMPARE_B)
        #define ID B
        #include "outputcompare.hpp"
        #undef ID
    #endif

    #if C(OUTPUTCOMPARE_C)
        #define ID C
        #include "outputcompare.hpp"
        #undef ID
    #endif

    #undef MAKE_OUTPUTCOMPARE
};

#undef TimerCounterN
#undef C
#undef _C

//--------------------------------------------------------

    #endif // CONCAT(CHIP_TIMERCOUNTER_, N)

    #include "incn.hpp"

    #include "timercounter.hpp"

#else // N < CHIP_TIMERCOUNTER_COUNT

    #undef N

    #define NBAVR_TIMERCOUNTER_HPP

#endif // N < CHIP_TIMERCOUNTER_COUNT

#endif
