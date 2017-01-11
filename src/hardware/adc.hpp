#ifndef NBAVR_ADC_HPP
#define NBAVR_ADC_HPP

#ifdef CHIP_ADC

struct ADC {
    enum class Reference : uint8_t {
        AREF = CHIP_ADC_REFERENCE_AREF_ID,
        AVCC = CHIP_ADC_REFERENCE_AVCC_ID,
        Internal = CHIP_ADC_REFERENCE_INTERNAL_ID,
    };

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

    enum class Trigger : uint8_t {
        #if CHIP_ADC_TRIGGER
            FreeRunning = CHIP_ADC_TRIGGER_FREE_RUNNING_ID,
            AnalogComparator = CHIP_ADC_TRIGGER_ANALOG_COMPARATOR_ID,
            ExternalInt0 = CHIP_ADC_TRIGGER_EXTERNAL_INT_0_ID,
            Timer0CompareMatchA = CHIP_ADC_TRIGGER_TIMER0_COMPARE_MATCH_A_ID,
            Timer0Overflow = CHIP_ADC_TRIGGER_TIMER0_OVERFLOW_ID,
            Timer1CompareMatchB = CHIP_ADC_TRIGGER_TIMER1_COMPARE_MATCH_B_ID,
            Timer1Overflow = CHIP_ADC_TRIGGER_TIMER1_OVERFLOW_ID,
            Timer1CaptureEvent = CHIP_ADC_TRIGGER_TIMER1_CAPTURE_EVENT_ID,
        #else
            FreeRunning,
        #endif

        SingleConversion,
    };

    struct Config {
        Reference reference = Reference::AVCC;
        Channel channel = Channel::ADC0;
        #ifdef CHIP_ADC_PRESCALER
            Prescaler prescaler = Prescaler::Div128;
        #endif
        bool leftAdjust = false;
        Trigger trigger = Trigger::SingleConversion;
        void (*adcCompleteInterrupt)(void*) = nullptr;
        void* adcCompleteInterruptData = nullptr;
    };

    force_inline void start(Config config) {
        atomic {
            // TODO Disable ADC power reduction. (Needed?)

            // Enable ADC.
            setBit_(CHIP_ADC_ENABLE_REG, CHIP_ADC_ENABLE_BIT, true);

            // Clear interrupt flag.
            setBit_(CHIP_ADC_INT_FLAG_REG, CHIP_ADC_INT_FLAG_BIT, true);

            #if CHIP_ADC_TRIGGER
            // Enable auto trigger.
            setBit_(CHIP_ADC_TRIGGER_ENABLE_REG, CHIP_ADC_TRIGGER_ENABLE_BIT, config.trigger != Trigger::SingleConversion);
            #else
            // Enable free running.
            setBit_(CHIP_ADC_FREE_RUNNING_ENABLE_REG, CHIP_ADC_FREE_RUNNING_ENABLE_BIT, config.trigger != Trigger::SingleConversion);
            #endif

            // Set auto trigger value.
            #ifdef CHIP_ADC_TRIGGER
            setBit_(CHIP_ADC_TRIGGER_BIT_0_REG, CHIP_ADC_TRIGGER_BIT_0_BIT, (uint8_t)config.trigger & 0x01);
            setBit_(CHIP_ADC_TRIGGER_BIT_1_REG, CHIP_ADC_TRIGGER_BIT_1_BIT, (uint8_t)config.trigger & 0x02);
            setBit_(CHIP_ADC_TRIGGER_BIT_2_REG, CHIP_ADC_TRIGGER_BIT_2_BIT, (uint8_t)config.trigger & 0x04);
            #endif

            // Set left adjust.
            setBit_(CHIP_ADC_LEFT_ADJUST_REG, CHIP_ADC_LEFT_ADJUST_BIT, config.leftAdjust);

            // Set input channel.
            setBit_(CHIP_ADC_CHANNEL_BIT_0_REG, CHIP_ADC_CHANNEL_BIT_0_BIT, (uint8_t)config.channel & 0x01);
            setBit_(CHIP_ADC_CHANNEL_BIT_1_REG, CHIP_ADC_CHANNEL_BIT_1_BIT, (uint8_t)config.channel & 0x02);
            setBit_(CHIP_ADC_CHANNEL_BIT_2_REG, CHIP_ADC_CHANNEL_BIT_2_BIT, (uint8_t)config.channel & 0x04);
            setBit_(CHIP_ADC_CHANNEL_BIT_3_REG, CHIP_ADC_CHANNEL_BIT_3_BIT, (uint8_t)config.channel & 0x08);

            // Set reference.
            setBit_(CHIP_ADC_REFERENCE_BIT_0_REG, CHIP_ADC_REFERENCE_BIT_0_BIT, (uint8_t)config.reference & 0x01);
            setBit_(CHIP_ADC_REFERENCE_BIT_1_REG, CHIP_ADC_REFERENCE_BIT_1_BIT, (uint8_t)config.reference & 0x02);

            // Set prescaler
            #ifdef CHIP_ADC_PRESCALER
            setBit_(CHIP_ADC_PRESCALER_BIT_0_REG, CHIP_ADC_PRESCALER_BIT_0_BIT, (uint8_t)config.prescaler & 0x01);
            setBit_(CHIP_ADC_PRESCALER_BIT_1_REG, CHIP_ADC_PRESCALER_BIT_1_BIT, (uint8_t)config.prescaler & 0x02);
            setBit_(CHIP_ADC_PRESCALER_BIT_2_REG, CHIP_ADC_PRESCALER_BIT_2_BIT, (uint8_t)config.prescaler & 0x04);
            #endif

            // Enable interrupt.
            setBit_(CHIP_ADC_INT_ENABLE_REG, CHIP_ADC_INT_ENABLE_BIT, true);

            // Register callback.
            _adcInterrupt = config.adcCompleteInterrupt;
            _adcInterruptData = config.adcCompleteInterruptData;
            // callback = config.callback;

            // Start ADC.
            if((config.trigger == Trigger::SingleConversion)
            || (config.trigger == Trigger::FreeRunning)) {
                setBit_(CHIP_ADC_START_REG, CHIP_ADC_START_BIT, true);
            }
        }
    }

    force_inline void stop() {
        atomic {
            // Disable ADC
            setBit_(CHIP_ADC_ENABLE_REG, CHIP_ADC_ENABLE_BIT, false);

            // Clear interrupt flag
            setBit_(CHIP_ADC_INT_FLAG_REG, CHIP_ADC_INT_FLAG_BIT, true);
        }
    }

    force_inline uint16_t value() {
        return CHIP_ADC_DATA_REG;
    }
};

#endif // #ifdef CHIP_ADC

#endif
