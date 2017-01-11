#define timerCounterN(X) CONCAT(timerCounter,TIMERCOUNTER_ID,X)
#define _timerCounterN(X) CONCAT(_timerCounter,TIMERCOUNTER_ID,X)
#define TIMERCOUNTER_N(X) CONCAT(CHIP_TIMERCOUNTER_,TIMERCOUNTER_ID,X)
#define TimerCounterN CONCAT(TimerCounter,TIMERCOUNTER_ID,)

struct TimerCounterN {
    #if TIMERCOUNTER_N(_WAVEFORM)
    enum class Waveform : uint8_t {
        Normal = TIMERCOUNTER_N(_WAVEFORM_NORMAL_ID),
        PWM = TIMERCOUNTER_N(_WAVEFORM_PWM_PHASE_CORRECT_ID),
        CTCOCRA = TIMERCOUNTER_N(_WAVEFORM_CTC_OCRA_ID),
        FastPWM = TIMERCOUNTER_N(_WAVEFORM_FAST_PWM_ID),
        #if TIMERCOUNTER_N(_WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID)
        PWMOCRA = TIMERCOUNTER_N(_WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID),
        #endif
        #if TIMERCOUNTER_N(_WAVEFORM_FAST_PWM_OCRA_ID)
        FastPWMOCRA = TIMERCOUNTER_N(_WAVEFORM_FAST_PWM_OCRA_ID),
        #endif
    };
    #endif

    enum class ClockSelect : uint8_t {
        None = TIMERCOUNTER_N(_CLOCK_NONE_ID),
        Div1 = TIMERCOUNTER_N(_CLOCK_1_ID),
        Div8 = TIMERCOUNTER_N(_CLOCK_8_ID),
        #if TIMERCOUNTER_N(_CLOCK_32_ID)
        Div32 = TIMERCOUNTER_N(_CLOCK_32_ID),
        #endif
        Div64 = TIMERCOUNTER_N(_CLOCK_64_ID),
        #if TIMERCOUNTER_N(_CLOCK_128_ID)
        Div128 = TIMERCOUNTER_N(_CLOCK_128_ID),
        #endif
        Div256 = TIMERCOUNTER_N(_CLOCK_256_ID),
        Div1024 = TIMERCOUNTER_N(_CLOCK_1024_ID),
        #if TIMERCOUNTER_N(_CLOCK_EXT_FALLING_ID)
        ExtFalling = TIMERCOUNTER_N(_CLOCK_EXT_FALLING_ID),
        #endif
        #if TIMERCOUNTER_N(_CLOCK_EXT_RISING_ID)
        ExtRising = TIMERCOUNTER_N(_CLOCK_EXT_RISING_ID),
        #endif
    };

    #if TIMERCOUNTER_N(_OUTPUTCOMPARE_MODE)
    enum class OutputMode : uint8_t {
        Disconnected = TIMERCOUNTER_N(_OUTPUTCOMPARE_MODE_DISCONNECTED_ID),
        Toggle = TIMERCOUNTER_N(_OUTPUTCOMPARE_MODE_TOGGLE_ID),
        Clear = TIMERCOUNTER_N(_OUTPUTCOMPARE_MODE_CLEAR_ID),
        Set = TIMERCOUNTER_N(_OUTPUTCOMPARE_MODE_SET_ID),
    };
    #endif

    struct Config {
        #if TIMERCOUNTER_N(_WAVEFORM)
        Waveform waveform = Waveform::Normal;
        #endif
        ClockSelect clockSelect = ClockSelect::None;
        TIMERCOUNTER_N(_TYPE) timerRegister = 0;
        #if TIMERCOUNTER_N(_OUTPUTCOMPARE_A)
        TIMERCOUNTER_N(_TYPE) outputARegister = 0;
        bool outputAIntEnable = false;
        OutputMode outputAMode = OutputMode::Disconnected;
        void (*outputCompareAInterrupt)(void*) = nullptr;
        void* outputCompareAInterruptData = nullptr;
        #endif
        #if TIMERCOUNTER_N(_OUTPUTCOMPARE_B)
        TIMERCOUNTER_N(_TYPE) outputBRegister = 0;
        bool outputBIntEnable = false;
        OutputMode outputBMode = OutputMode::Disconnected;
        void (*outputCompareBInterrupt)(void*) = nullptr;
        void* outputCompareBInterruptData = nullptr;
        #endif
        #if TIMERCOUNTER_N(_OUTPUTCOMPARE_C)
        TIMERCOUNTER_N(_TYPE) outputCRegister = 0;
        bool outputCIntEnable = false;
        OutputMode outputCMode = OutputMode::Disconnected;
        void (*outputCompareCInterrupt)(void*) = nullptr;
        void* outputCompareCInterruptData = nullptr;
        #endif
        bool overflowIntEnable = false;
        void (*overflowInterrupt)(void*) = nullptr;
        void* overflowInterruptData = nullptr;
    };

    force_inline void apply(Config config) {
        atomic {
            #if TIMERCOUNTER_N(_WAVEFORM)
            waveform(config.waveform);
            #endif

            clockSelect(config.clockSelect);

            // Load timer register.
            TIMERCOUNTER_N(_COUNTER_REG) = config.timerRegister;

            // Setup output compares.
            #if TIMERCOUNTER_N(_OUTPUTCOMPARE_A)
            setBit_(TIMERCOUNTER_N(_OUTPUTCOMPARE_A_MODE_BIT_0_REG), TIMERCOUNTER_N(_OUTPUTCOMPARE_A_MODE_BIT_0_BIT), (uint8_t)config.outputAMode & 0x01);
            setBit_(TIMERCOUNTER_N(_OUTPUTCOMPARE_A_MODE_BIT_1_REG), TIMERCOUNTER_N(_OUTPUTCOMPARE_A_MODE_BIT_1_BIT), (uint8_t)config.outputAMode & 0x02);
            setBit_(TIMERCOUNTER_N(_OUTPUTCOMPARE_A_INT_ENABLE_REG), TIMERCOUNTER_N(_OUTPUTCOMPARE_A_INT_ENABLE_BIT), config.outputAIntEnable);
            setBit_(TIMERCOUNTER_N(_OUTPUTCOMPARE_A_INT_FLAG_REG), TIMERCOUNTER_N(_OUTPUTCOMPARE_A_INT_FLAG_BIT), true);
            TIMERCOUNTER_N(_OUTPUTCOMPARE_A_REG) = config.outputARegister;
            _timerCounterN(OutputCompareAInterrupt) = config.outputCompareAInterrupt;
            _timerCounterN(OutputCompareAInterruptData) = config.outputCompareAInterruptData;
            #endif

            #if TIMERCOUNTER_N(_OUTPUTCOMPARE_B)
            setBit_(TIMERCOUNTER_N(_OUTPUTCOMPARE_B_MODE_BIT_0_REG), TIMERCOUNTER_N(_OUTPUTCOMPARE_B_MODE_BIT_0_BIT), (uint8_t)config.outputBMode & 0x01);
            setBit_(TIMERCOUNTER_N(_OUTPUTCOMPARE_B_MODE_BIT_1_REG), TIMERCOUNTER_N(_OUTPUTCOMPARE_B_MODE_BIT_1_BIT), (uint8_t)config.outputBMode & 0x02);
            setBit_(TIMERCOUNTER_N(_OUTPUTCOMPARE_B_INT_ENABLE_REG), TIMERCOUNTER_N(_OUTPUTCOMPARE_B_INT_ENABLE_BIT), config.outputBIntEnable);
            setBit_(TIMERCOUNTER_N(_OUTPUTCOMPARE_B_INT_FLAG_REG), TIMERCOUNTER_N(_OUTPUTCOMPARE_B_INT_FLAG_BIT), true);
            TIMERCOUNTER_N(_OUTPUTCOMPARE_B_REG) = config.outputBRegister;
            _timerCounterN(OutputCompareBInterrupt) = config.outputCompareBInterrupt;
            _timerCounterN(OutputCompareBInterruptData) = config.outputCompareBInterruptData;
            #endif

            #if TIMERCOUNTER_N(_OUTPUTCOMPARE_C)
            setBit_(TIMERCOUNTER_N(_OUTPUTCOMPARE_C_MODE_BIT_0_REG), TIMERCOUNTER_N(_OUTPUTCOMPARE_C_MODE_BIT_0_BIT), (uint8_t)config.outputCMode & 0x01);
            setBit_(TIMERCOUNTER_N(_OUTPUTCOMPARE_C_MODE_BIT_1_REG), TIMERCOUNTER_N(_OUTPUTCOMPARE_C_MODE_BIT_1_BIT), (uint8_t)config.outputCMode & 0x02);
            setBit_(TIMERCOUNTER_N(_OUTPUTCOMPARE_C_INT_ENABLE_REG), TIMERCOUNTER_N(_OUTPUTCOMPARE_C_INT_ENABLE_BIT), config.outputCIntEnable);
            setBit_(TIMERCOUNTER_N(_OUTPUTCOMPARE_C_INT_FLAG_REG), TIMERCOUNTER_N(_OUTPUTCOMPARE_C_INT_FLAG_BIT), true);
            TIMERCOUNTER_N(_OUTPUTCOMPARE_C_REG) = config.outputCRegister;
            _timerCounterN(OutputCompareCInterrupt) = config.outputCompareCInterrupt;
            _timerCounterN(OutputCompareCInterruptData) = config.outputCompareCInterruptData;
            #endif

            // Setup overflow int.
            setBit_(TIMERCOUNTER_N(_OVERFLOW_INT_ENABLE_REG), TIMERCOUNTER_N(_OVERFLOW_INT_ENABLE_BIT), config.overflowIntEnable);
            setBit_(TIMERCOUNTER_N(_OVERFLOW_INT_FLAG_REG), TIMERCOUNTER_N(_OVERFLOW_INT_FLAG_BIT), true);
            _timerCounterN(OverflowInterrupt) = config.overflowInterrupt;
            _timerCounterN(OverflowInterruptData) = config.overflowInterruptData;
        }
    }

    #if TIMERCOUNTER_N(_WAVEFORM)
    force_inline void waveform(Waveform waveform) const {
        #if TIMERCOUNTER_N(_WAVEFORM_BIT_COUNT) > 0
        setBit_(TIMERCOUNTER_N(_WAVEFORM_BIT_0_REG), TIMERCOUNTER_N(_WAVEFORM_BIT_0_BIT), (uint8_t)waveform & 0x01);
        #endif
        #if TIMERCOUNTER_N(_WAVEFORM_BIT_COUNT) > 1
        setBit_(TIMERCOUNTER_N(_WAVEFORM_BIT_1_REG), TIMERCOUNTER_N(_WAVEFORM_BIT_1_BIT), (uint8_t)waveform & 0x02);
        #endif
        #if TIMERCOUNTER_N(_WAVEFORM_BIT_COUNT) > 2
        setBit_(TIMERCOUNTER_N(_WAVEFORM_BIT_2_REG), TIMERCOUNTER_N(_WAVEFORM_BIT_2_BIT), (uint8_t)waveform & 0x04);
        #endif
        #if TIMERCOUNTER_N(_WAVEFORM_BIT_COUNT) > 3
        setBit_(TIMERCOUNTER_N(_WAVEFORM_BIT_3_REG), TIMERCOUNTER_N(_WAVEFORM_BIT_3_BIT), (uint8_t)waveform & 0x08);
        #endif
    }
    #endif

    force_inline void clockSelect(ClockSelect clockSelect) const {
        setBit_(TIMERCOUNTER_N(_CLOCK_BIT_0_REG), TIMERCOUNTER_N(_CLOCK_BIT_0_BIT), (uint8_t)clockSelect & 0x01);
        setBit_(TIMERCOUNTER_N(_CLOCK_BIT_1_REG), TIMERCOUNTER_N(_CLOCK_BIT_1_BIT), (uint8_t)clockSelect & 0x02);
        setBit_(TIMERCOUNTER_N(_CLOCK_BIT_2_REG), TIMERCOUNTER_N(_CLOCK_BIT_2_BIT), (uint8_t)clockSelect & 0x04);
    }

    force_inline void timerRegister(TIMERCOUNTER_N(_TYPE) value) const {
        TIMERCOUNTER_N(_COUNTER_REG) = value;
    }

    force_inline TIMERCOUNTER_N(_TYPE) timerRegister() const {
        return TIMERCOUNTER_N(_COUNTER_REG);
    }

    #if TIMERCOUNTER_N(_OUTPUTCOMPARE_A)
        #define OUTPUTCOMPARE_ID A
        #include "outputcompare.tpp"
        #undef OUTPUTCOMPARE_ID
    #endif

    #if TIMERCOUNTER_N(_OUTPUTCOMPARE_B)
        #define OUTPUTCOMPARE_ID B
        #include "outputcompare.tpp"
        #undef OUTPUTCOMPARE_ID
    #endif

    #if TIMERCOUNTER_N(_OUTPUTCOMPARE_C)
        #define OUTPUTCOMPARE_ID C
        #include "outputcompare.tpp"
        #undef OUTPUTCOMPARE_ID
    #endif

    force_inline void overflowIntEnable(bool b) const {
        if(b) {
            TIMERCOUNTER_N(_OVERFLOW_INT_ENABLE_REG) |= bv(TIMERCOUNTER_N(_OVERFLOW_INT_ENABLE_BIT));
        } else {
            TIMERCOUNTER_N(_OVERFLOW_INT_ENABLE_REG) &= ~bv(TIMERCOUNTER_N(_OVERFLOW_INT_ENABLE_BIT));
        }
    }

    force_inline bool overflowIntFlag() const {
        return TIMERCOUNTER_N(_OVERFLOW_INT_FLAG_REG) & bv(TIMERCOUNTER_N(_OVERFLOW_INT_FLAG_BIT));
    }

    force_inline void overflowIntFlagClear() const {
        TIMERCOUNTER_N(_OVERFLOW_INT_FLAG_REG) |= bv(TIMERCOUNTER_N(_OVERFLOW_INT_FLAG_BIT));
    }

    static constexpr int size() {
        return sizeof(TIMERCOUNTER_N(_TYPE));
    }
};
