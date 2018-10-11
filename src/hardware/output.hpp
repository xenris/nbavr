/// # Timer Output

/// ```c++
/// // PWM.
///
/// using Timer = nbos::hw::Timer0;
///
/// Timer::OutputA::Pin::mode(nbos::hw::Pin::Mode::output);
/// Timer::OutputB::Pin::mode(nbos::hw::Pin::Mode::output);
///
/// atomic([]() {
///     Timer::waveform(Timer::Waveform::fastPWM);
///     Timer::OutputA::mode(Timer::OutputA::Mode::set);
///     Timer::OutputB::mode(Timer::OutputB::Mode::set);
///     Timer::OutputA::value(128);
///     Timer::OutputB::value(128);
///     Timer::clock(Timer::Clock::div8);
/// });
/// ```

#define OutputX CAT(Output, ID)
#define OUTPUT_X(X) CAT(TIMER_N(OUTPUT), _, ID, _, X)

/// ## class {{TimerN::OutputX}}
struct OutputX {
    /// #### type Pin
    /// The IO pin which relates to this output.
    #if DEFINED(OUTPUT_X(MODE_TOGGLE_ID))
        using Pin = OUTPUT_X(PIN);
    #endif

    /// #### enum {{TimerN::Mode}}
    /// * disconnected
    /// * toggle
    /// * clear
    /// * set
    #if DEFINED(OUTPUT_X(MODE_TOGGLE_ID))
    enum class Mode : uint8_t {
        disconnected = OUTPUT_X(MODE_DISCONNECTED_ID),
        toggle = OUTPUT_X(MODE_TOGGLE_ID),
        clear = OUTPUT_X(MODE_CLEAR_ID),
        set = OUTPUT_X(MODE_SET_ID),
    };
    #endif

    /// #### static void value(T v)
    static force_inline void value(REGTYPE(OUTPUT_X(REG)) v) {
        *REG(OUTPUT_X(REG)) = v;
    }

    /// #### static T value()
    static force_inline REGTYPE(OUTPUT_X(REG)) value() {
        return *REG(OUTPUT_X(REG));
    }

    /// #### static void mode([[TimerN::Mode]] m)
    #if DEFINED(OUTPUT_X(MODE_TOGGLE_ID))
    static force_inline void mode(Mode m) {
        setBit_(REG(OUTPUT_X(MODE_BIT_0_REG)), OUTPUT_X(MODE_BIT_0_BIT), uint8_t(m) & 0x01);
        setBit_(REG(OUTPUT_X(MODE_BIT_1_REG)), OUTPUT_X(MODE_BIT_1_BIT), uint8_t(m) & 0x02);
    }
    #endif

    /// #### static void callback([[callback_t]] callback, void\* data)
    #if OUTPUT_X(MODE_BIT_1_BIT)
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
    #endif

    /// #### static void intEnable(bool b)
    #if OUTPUT_X(MODE_BIT_1_BIT)
    static force_inline void intEnable(bool b) {
        if(b) {
            *REG(OUTPUT_X(INT_ENABLE_REG)) |= bv(OUTPUT_X(INT_ENABLE_BIT));
        } else {
            *REG(OUTPUT_X(INT_ENABLE_REG)) &= ~bv(OUTPUT_X(INT_ENABLE_BIT));
        }
    }

    /// #### static bool intEnabled()
    static force_inline bool intEnabled() {
        return *REG(OUTPUT_X(INT_ENABLE_REG)) & bv(OUTPUT_X(INT_ENABLE_BIT));
    }
    #endif

    /// #### static bool intFlag()
    #if OUTPUT_X(MODE_BIT_1_BIT)
    static force_inline bool intFlag() {
        return *REG(OUTPUT_X(INT_FLAG_REG)) & bv(OUTPUT_X(INT_FLAG_BIT));
    }
    #endif

    /// #### static void intFlagClear()
    #if OUTPUT_X(MODE_BIT_1_BIT)
    static force_inline void intFlagClear() {
        *REG(OUTPUT_X(INT_FLAG_REG)) |= bv(OUTPUT_X(INT_FLAG_BIT));
    }
    #endif
};

#undef OutputX
#undef OUTPUT_X
