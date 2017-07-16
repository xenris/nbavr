/// # Analog to Digital Converter
///
/// ## Example

/// ```c++
/// // Start the analog to digital converter.
///
/// atomic {
///     Adc::reference(Adc::Reference::AVCC);
///     Adc::channel(Adc::Channel::ADC1);
///     Adc::prescaler(Adc::Prescaler::Div128);
///     Adc::trigger(Adc::Trigger::SingleConversion);
/// }
///
/// Adc::start();
///
/// // In the main loop.
///
/// if(Adc::intFlag()) {
///     adcValue = Adc::value();
///
///     Adc::intFlagClear();
/// } else {
///     // Conversion not done yet.
/// }
/// ```

#ifndef NBAVR_ADC_HPP
#define NBAVR_ADC_HPP

#ifdef CHIP_ADC

MAKE_CALLBACK_HEADER(ADC);

/// #### macro INCLUDE_ADC_CALLBACK(N)
/// Include this to use Adc callbacks.
#define INCLUDE_ADC_CALLBACK MAKE_CALLBACK(ADC)

/// ## class Adc
struct Adc {
    Adc() = delete;

    /// #### enum Reference
    /// * AREF
    /// * AVCC
    /// * Internal
    enum class Reference : uint8_t {
        AREF = CHIP_ADC_REFERENCE_AREF_ID,
        AVCC = CHIP_ADC_REFERENCE_AVCC_ID,
        Internal = CHIP_ADC_REFERENCE_INTERNAL_ID,
    };

    /// #### enum Channel
    /// * ADC0
    /// * ADC1
    /// * ADC2
    /// * ADC3
    /// * ADC4
    /// * ADC5
    /// * ADC6
    /// * ADC7
    /// * ADC8
    /// * VBG
    /// * GND
    enum class Channel : uint8_t {
        #ifdef CHIP_ADC_CHANNEL_0_ID
            ADC0 = CHIP_ADC_CHANNEL_0_ID,
        #endif
        #ifdef CHIP_ADC_CHANNEL_1_ID
            ADC1 = CHIP_ADC_CHANNEL_1_ID,
        #endif
        #ifdef CHIP_ADC_CHANNEL_2_ID
            ADC2 = CHIP_ADC_CHANNEL_2_ID,
        #endif
        #ifdef CHIP_ADC_CHANNEL_3_ID
            ADC3 = CHIP_ADC_CHANNEL_3_ID,
        #endif
        #ifdef CHIP_ADC_CHANNEL_4_ID
            ADC4 = CHIP_ADC_CHANNEL_4_ID,
        #endif
        #ifdef CHIP_ADC_CHANNEL_5_ID
            ADC5 = CHIP_ADC_CHANNEL_5_ID,
        #endif
        #ifdef CHIP_ADC_CHANNEL_6_ID
            ADC6 = CHIP_ADC_CHANNEL_6_ID,
        #endif
        #ifdef CHIP_ADC_CHANNEL_7_ID
            ADC7 = CHIP_ADC_CHANNEL_7_ID,
        #endif
        #ifdef CHIP_ADC_CHANNEL_8_ID
            ADC8 = CHIP_ADC_CHANNEL_8_ID,
        #endif
        #ifdef CHIP_ADC_CHANNEL_VBG_ID
            VBG = CHIP_ADC_CHANNEL_VBG_ID,
        #endif
        #ifdef CHIP_ADC_CHANNEL_GND_ID
            GND = CHIP_ADC_CHANNEL_GND_ID,
        #endif
    };

    /// #### enum Prescaler
    /// * Div2
    /// * Div4
    /// * Div8
    /// * Div16
    /// * Div32
    /// * Div64
    /// * Div128
    #ifdef CHIP_ADC_PRESCALER
    enum class Prescaler : uint8_t {
        #ifdef CHIP_ADC_PRESCALER_2_ID
            Div2 = CHIP_ADC_PRESCALER_2_ID,
        #endif
        #ifdef CHIP_ADC_PRESCALER_4_ID
            Div4 = CHIP_ADC_PRESCALER_4_ID,
        #endif
        #ifdef CHIP_ADC_PRESCALER_8_ID
            Div8 = CHIP_ADC_PRESCALER_8_ID,
        #endif
        #ifdef CHIP_ADC_PRESCALER_16_ID
            Div16 = CHIP_ADC_PRESCALER_16_ID,
        #endif
        #ifdef CHIP_ADC_PRESCALER_32_ID
            Div32 = CHIP_ADC_PRESCALER_32_ID,
        #endif
        #ifdef CHIP_ADC_PRESCALER_64_ID
            Div64 = CHIP_ADC_PRESCALER_64_ID,
        #endif
        #ifdef CHIP_ADC_PRESCALER_128_ID
            Div128 = CHIP_ADC_PRESCALER_128_ID,
        #endif
    };
    #endif

    /// #### enum Trigger
    /// * SingleConversion
    /// * FreeRunning
    /// * AnalogComparator
    /// * ExternalInt0
    /// * Timer0CompareMatchA
    /// * Timer0Overflow
    /// * Timer1CompareMatchB
    /// * Timer1Overflow
    /// * Timer1CaptureEvent
    /// * FreeRunning
    enum class Trigger : uint8_t {
        #if CHIP_ADC_TRIGGER
            FreeRunning = CHIP_ADC_TRIGGER_FREE_RUNNING_ID,
            AnalogComparator = CHIP_ADC_TRIGGER_ANALOG_COMPARATOR_ID,
            ExternalInt0 = CHIP_ADC_TRIGGER_EXTERNAL_INT_0_ID,
            Timer0CompareMatchA = CHIP_ADC_TRIGGER_TIMER0_COMPARE_MATCH_A_ID,
            Timer0Overflow = CHIP_ADC_TRIGGER_TIMER0_OVERFLOW_ID,
            #if CHIP_ADC_TRIGGER_TIMER1_COMPARE_MATCH_B_ID
            Timer1CompareMatchB = CHIP_ADC_TRIGGER_TIMER1_COMPARE_MATCH_B_ID,
            #endif
            #if CHIP_ADC_TRIGGER_TIMER1_OVERFLOW_ID
            Timer1Overflow = CHIP_ADC_TRIGGER_TIMER1_OVERFLOW_ID,
            #endif
            #if CHIP_ADC_TRIGGER_TIMER1_CAPTURE_EVENT_ID
            Timer1CaptureEvent = CHIP_ADC_TRIGGER_TIMER1_CAPTURE_EVENT_ID,
            #endif
        #else
            FreeRunning,
        #endif

        SingleConversion,
    };

    /// #### constexpr HardwareType getHardwareType()
    /// Get the type of hardware that this class represents.
    static constexpr HardwareType getHardwareType() {
        return HardwareType::ADC;
    }

    /// #### void enable(bool)
    /// Enable/disable the analog to digital converter.
    static force_inline void enable(bool e) {
        setBit_(CHIP_ADC_ENABLE_REG, CHIP_ADC_ENABLE_BIT, e);
    }

    /// #### void start()
    /// Start a convertion if set to single conversion or free running modes.
    static force_inline void start() {
        setBit_(CHIP_ADC_START_REG, CHIP_ADC_START_BIT, true);
    }

    /// #### uint16_t value()
    /// Get the the most recent conversion.
    static force_inline uint16_t value() {
        return *CHIP_ADC_DATA_REG;
    }

    /// #### void reference(Reference)
    /// Set the reference voltage source.
    static force_inline void reference(Reference ref) {
        setBit_(CHIP_ADC_REFERENCE_BIT_0_REG, CHIP_ADC_REFERENCE_BIT_0_BIT, uint8_t(ref) & 0x01);
        setBit_(CHIP_ADC_REFERENCE_BIT_1_REG, CHIP_ADC_REFERENCE_BIT_1_BIT, uint8_t(ref) & 0x02);
    }

    /// #### void channel(Channel)
    /// Set the input channel.
    static force_inline void channel(Channel ch) {
        setBit_(CHIP_ADC_CHANNEL_BIT_0_REG, CHIP_ADC_CHANNEL_BIT_0_BIT, uint8_t(ch) & 0x01);
        setBit_(CHIP_ADC_CHANNEL_BIT_1_REG, CHIP_ADC_CHANNEL_BIT_1_BIT, uint8_t(ch) & 0x02);
        setBit_(CHIP_ADC_CHANNEL_BIT_2_REG, CHIP_ADC_CHANNEL_BIT_2_BIT, uint8_t(ch) & 0x04);
        setBit_(CHIP_ADC_CHANNEL_BIT_3_REG, CHIP_ADC_CHANNEL_BIT_3_BIT, uint8_t(ch) & 0x08);
    }

    /// #### void prescaler(Prescaler)
    /// Set the clock prescaler.
    #ifdef CHIP_ADC_PRESCALER
    static force_inline void prescaler(Prescaler pre) {
        setBit_(CHIP_ADC_PRESCALER_BIT_0_REG, CHIP_ADC_PRESCALER_BIT_0_BIT, uint8_t(pre) & 0x01);
        setBit_(CHIP_ADC_PRESCALER_BIT_1_REG, CHIP_ADC_PRESCALER_BIT_1_BIT, uint8_t(pre) & 0x02);
        setBit_(CHIP_ADC_PRESCALER_BIT_2_REG, CHIP_ADC_PRESCALER_BIT_2_BIT, uint8_t(pre) & 0x04);
    }
    #endif

    /// #### void leftAdjust(bool)
    /// Enable/disable left adjustment of 10 bit data in 16 bit register.
    static force_inline void leftAdjust(bool l) {
        setBit_(CHIP_ADC_LEFT_ADJUST_REG, CHIP_ADC_LEFT_ADJUST_BIT, l);
    }

    /// #### void trigger(Trigger)
    /// Set the conversion trigger source.
    static force_inline void trigger(Trigger trig) {
        if(trig == Trigger::SingleConversion) {
            #ifdef CHIP_ADC_TRIGGER
            setBit_(CHIP_ADC_TRIGGER_ENABLE_REG, CHIP_ADC_TRIGGER_ENABLE_BIT, false);
            #else
            setBit_(CHIP_ADC_FREE_RUNNING_ENABLE_REG, CHIP_ADC_FREE_RUNNING_ENABLE_BIT, false);
            #endif
        } else {
            #ifdef CHIP_ADC_TRIGGER
            setBit_(CHIP_ADC_TRIGGER_BIT_0_REG, CHIP_ADC_TRIGGER_BIT_0_BIT, uint8_t(trig) & 0x01);
            setBit_(CHIP_ADC_TRIGGER_BIT_1_REG, CHIP_ADC_TRIGGER_BIT_1_BIT, uint8_t(trig) & 0x02);
            setBit_(CHIP_ADC_TRIGGER_BIT_2_REG, CHIP_ADC_TRIGGER_BIT_2_BIT, uint8_t(trig) & 0x04);
            setBit_(CHIP_ADC_TRIGGER_ENABLE_REG, CHIP_ADC_TRIGGER_ENABLE_BIT, true);
            #else
            setBit_(CHIP_ADC_FREE_RUNNING_ENABLE_REG, CHIP_ADC_FREE_RUNNING_ENABLE_BIT, true);
            #endif
        }
    }

    /// #### void callback(void (\*)(void\*), void\*)
    /// Set the callback and data for when a conversion is complete.
    static force_inline void callback(void (*func)(void*), void* data) {
        _ADC_Callback_ = func;
        _ADC_CallbackData_ = data;
    }

    /// #### void intEnable(bool)
    /// Enable/diable the ADC interrupt.
    static force_inline void intEnable(bool e) {
        setBit_(CHIP_ADC_INT_ENABLE_REG, CHIP_ADC_INT_ENABLE_BIT, e);
    }

    /// #### bool intFlag()
    /// Returns true if the interrupt flag is set.
    static force_inline bool intFlag() {
        return *CHIP_ADC_INT_FLAG_REG & bv(CHIP_ADC_INT_FLAG_BIT);
    }

    /// #### void intFlagClear()
    /// Clear the interrupt flag.
    static force_inline void intFlagClear() {
        setBit_(CHIP_ADC_INT_FLAG_REG, CHIP_ADC_INT_FLAG_BIT, true);
    }
};

#endif // #ifdef CHIP_ADC

#endif
