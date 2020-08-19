/// [[Index]]

/// # {{Analog to Digital Converters}}

#ifndef NBLIB_ADC_HPP

#include "chip.hpp"
#include "hardwaretype.hpp"
#include "isr.hpp"
#include "macros.hpp"
#include "system.hpp"
#include "callback.hpp"

#include "loopi"

#ifdef _I
    #define N _I
    #define AdcN CAT(Adc, N)
    #define ADC_N(A) CAT(CHIP_ADC_, N, _, A)

    #if DEFINED(CAT(CHIP_ADC_, N))

//------------------------------------------------------------------

namespace nblib::hw {

/// ## class {{AdcN}}
struct AdcN {
    AdcN() = delete;
    AdcN& operator=(const AdcN&) = delete;
    AdcN(const AdcN&) = delete;

    #if REG_DEFINED(ADC_N(REFERENCE_REG))
        /// #### enum {{AdcN::Reference}}
        /// * aref
        /// * avcc
        /// * vdd
        /// * internal
        /// * internal_1_1
        /// * internal_2_56
        /// * internal_2_56_cap
        enum class Reference {
            #if DEFINED(ADC_N(REFERENCE_AREF_ID))
                aref = ADC_N(REFERENCE_AREF_ID),
            #endif

            #if DEFINED(ADC_N(REFERENCE_AVCC_ID))
                avcc = ADC_N(REFERENCE_AVCC_ID),
            #endif

            #if DEFINED(ADC_N(REFERENCE_INTERNAL_ID))
                internal = ADC_N(REFERENCE_INTERNAL_ID),
            #endif

            #if DEFINED(ADC_N(REFERENCE_INTERNAL_1_1_ID))
                internal_1_1 = ADC_N(REFERENCE_INTERNAL_1_1_ID),
            #endif

            #if DEFINED(ADC_N(REFERENCE_INTERNAL_2_56_ID))
                internal_2_56 = ADC_N(REFERENCE_INTERNAL_2_56_ID),
            #endif

            #if DEFINED(ADC_N(REFERENCE_INTERNAL_2_56_CAP_ID))
                internal_2_56_cap = ADC_N(REFERENCE_INTERNAL_2_56_CAP_ID),
            #endif

            #if DEFINED(ADC_N(REFERENCE_VCC_ID))
                vcc = ADC_N(REFERENCE_VCC_ID),
            #endif

            #if DEFINED(ADC_N(REFERENCE_VDD_ID))
                vdd = ADC_N(REFERENCE_VDD_ID),
            #endif
        };
    #endif

    #if REG_DEFINED(ADC_N(CHANNEL_REG))
        /// #### enum {{AdcN::Channel}}
        /// * adc0
        /// * adc1
        /// * adc2
        /// * adc3
        /// * adc4
        /// * adc5
        /// * adc6
        /// * adc7
        /// * adc8
        /// * vbg
        /// * internal
        /// * temperature
        /// * gnd
        enum class Channel {
            #if DEFINED(ADC_N(CHANNEL_0_ID))
                adc0 = ADC_N(CHANNEL_0_ID),
            #endif

            #if DEFINED(ADC_N(CHANNEL_1_ID))
                adc1 = ADC_N(CHANNEL_1_ID),
            #endif

            #if DEFINED(ADC_N(CHANNEL_2_ID))
                adc2 = ADC_N(CHANNEL_2_ID),
            #endif

            #if DEFINED(ADC_N(CHANNEL_3_ID))
                adc3 = ADC_N(CHANNEL_3_ID),
            #endif

            #if DEFINED(ADC_N(CHANNEL_4_ID))
                adc4 = ADC_N(CHANNEL_4_ID),
            #endif

            #if DEFINED(ADC_N(CHANNEL_5_ID))
                adc5 = ADC_N(CHANNEL_5_ID),
            #endif

            #if DEFINED(ADC_N(CHANNEL_6_ID))
                adc6 = ADC_N(CHANNEL_6_ID),
            #endif

            #if DEFINED(ADC_N(CHANNEL_7_ID))
                adc7 = ADC_N(CHANNEL_7_ID),
            #endif

            #if DEFINED(ADC_N(CHANNEL_8_ID))
                adc8 = ADC_N(CHANNEL_8_ID),
            #endif

            #if DEFINED(ADC_N(CHANNEL_VBG_ID))
                vbg = ADC_N(CHANNEL_VBG_ID),
            #endif

            #if DEFINED(ADC_N(CHANNEL_INTERNAL_ID))
                internal = ADC_N(CHANNEL_INTERNAL_ID),
            #endif

            #if DEFINED(ADC_N(CHANNEL_TEMPERATURE_ID))
                temperature = ADC_N(CHANNEL_TEMPERATURE_ID),
            #endif

            #if DEFINED(ADC_N(CHANNEL_GND_ID))
                gnd = ADC_N(CHANNEL_GND_ID),
            #endif
        };
    #endif

    #if REG_DEFINED(ADC_N(PRESCALER_REG))
        /// #### enum {{AdcN::Prescaler}}
        /// * div2
        /// * div4
        /// * div8
        /// * div16
        /// * div32
        /// * div64
        /// * div128
        /// * div256
        enum class Prescaler {
            #if DEFINED(ADC_N(PRESCALER_2_ID))
                div2 = ADC_N(PRESCALER_2_ID),
            #endif

            #if DEFINED(ADC_N(PRESCALER_4_ID))
                div4 = ADC_N(PRESCALER_4_ID),
            #endif

            #if DEFINED(ADC_N(PRESCALER_8_ID))
                div8 = ADC_N(PRESCALER_8_ID),
            #endif

            #if DEFINED(ADC_N(PRESCALER_16_ID))
                div16 = ADC_N(PRESCALER_16_ID),
            #endif

            #if DEFINED(ADC_N(PRESCALER_32_ID))
                div32 = ADC_N(PRESCALER_32_ID),
            #endif

            #if DEFINED(ADC_N(PRESCALER_64_ID))
                div64 = ADC_N(PRESCALER_64_ID),
            #endif

            #if DEFINED(ADC_N(PRESCALER_128_ID))
                div128 = ADC_N(PRESCALER_128_ID),
            #endif

            #if DEFINED(ADC_N(PRESCALER_256_ID))
                div256 = ADC_N(PRESCALER_256_ID),
            #endif
        };
    #endif

    #if REG_DEFINED(ADC_N(TRIGGER_REG))
        /// #### enum {{AdcN::Trigger}}
        /// * freeRunning
        /// * event
        /// * analogComparator
        /// * externalInt0
        /// * timer0CompareMatchA
        /// * timer0Overflow
        /// * timer1CompareMatchB
        /// * timer1Overflow
        /// * timer1CaptureEvent
        enum class Trigger {
            #if DEFINED(ADC_N(TRIGGER_FREE_RUNNING_ID))
                freeRunning = ADC_N(TRIGGER_FREE_RUNNING_ID),
            #endif

            #if DEFINED(ADC_N(TRIGGER_EVENT_ID))
                event = ADC_N(TRIGGER_EVENT_ID),
            #endif

            #if DEFINED(ADC_N(TRIGGER_ANALOG_COMPARATOR_ID))
                analogComparator = ADC_N(TRIGGER_ANALOG_COMPARATOR_ID),
            #endif

            #if DEFINED(ADC_N(TRIGGER_EXTERNAL_INT_0_ID))
                externalInt0 = ADC_N(TRIGGER_EXTERNAL_INT_0_ID),
            #endif

            #if DEFINED(ADC_N(TRIGGER_TIMER0_COMPARE_MATCH_A_ID))
                timer0CompareMatchA = ADC_N(TRIGGER_TIMER0_COMPARE_MATCH_A_ID),
            #endif

            #if DEFINED(ADC_N(TRIGGER_TIMER0_OVERFLOW_ID))
                timer0Overflow = ADC_N(TRIGGER_TIMER0_OVERFLOW_ID),
            #endif

            #if DEFINED(ADC_N(TRIGGER_TIMER1_COMPARE_MATCH_B_ID))
                timer1CompareMatchB = ADC_N(TRIGGER_TIMER1_COMPARE_MATCH_B_ID),
            #endif

            #if DEFINED(ADC_N(TRIGGER_TIMER1_OVERFLOW_ID))
                timer1Overflow = ADC_N(TRIGGER_TIMER1_OVERFLOW_ID),
            #endif

            #if DEFINED(ADC_N(TRIGGER_TIMER1_CAPTURE_EVENT_ID))
                timer1CaptureEvent = ADC_N(TRIGGER_TIMER1_CAPTURE_EVENT_ID),
            #endif
        };
    #endif

    /// #### static [[HardwareType]] getHardwareType()
    static constexpr HardwareType getHardwareType() {
        return HardwareType::adc;
    }

    #if REG_DEFINED(ADC_N(ENABLE_REG))
        /// #### static void enable(bool e)
        static force_inline void enable(bool e) {
            ADC_N(ENABLE_REG)::setBit(ADC_N(ENABLE_BIT), e);
        }
    #endif

    #if REG_DEFINED(ADC_N(START_REG))
        /// #### static void start()
        static force_inline void start() {
            ADC_N(START_REG)::setBit(ADC_N(START_BIT), true);
        }
    #endif

    #if REG_DEFINED(ADC_N(FREE_RUNNING_REG))
        /// #### static void freeRunning(bool e)
        static force_inline void freeRunning(bool e) {
            ADC_N(FREE_RUNNING_REG)::setBit(ADC_N(FREE_RUNNING_BIT), e);
        }
    #endif

    #if REG_DEFINED(ADC_N(TRIGGER_ENABLE_REG))
        /// #### static void triggerEnable(bool e)
        static force_inline void triggerEnable(bool e) {
            ADC_N(TRIGGER_ENABLE_REG)::setBit(ADC_N(TRIGGER_ENABLE_BIT), e);
        }
    #endif

    #if REG_DEFINED(ADC_N(BIPOLAR_MODE_REG))
        /// #### static void bipolarModeEnable(bool e)
        static force_inline void bipolarModeEnable(bool e) {
            ADC_N(BIPOLAR_MODE_REG)::setBit(ADC_N(BIPOLAR_MODE_BIT), e);
        }
    #endif

    /// #### static uint8/16_t result()
    static force_inline ADC_N(RESULT_REG)::Type result() {
        return ADC_N(RESULT_REG)::getReg();
    }

    #if REG_DEFINED(ADC_N(REFERENCE_REG))
        /// #### static void reference([[AdcN::Reference]] r)
        static force_inline void reference(Reference r) {
            ADC_N(REFERENCE_REG)::setBits(ADC_N(REFERENCE_MASK), r);
        }
    #endif

    #if REG_DEFINED(ADC_N(CHANNEL_REG))
        /// #### static void channel([[AdcN::Channel]] c)
        static force_inline void channel(Channel c) {
            ADC_N(CHANNEL_REG)::setBits(ADC_N(CHANNEL_MASK), c);

            #if REG_DEFINED(ADC_N(CHANNEL_REG_EXTRA))
                ADC_N(CHANNEL_REG_EXTRA)::setBits(ADC_N(CHANNEL_MASK_EXTRA), c >> 8);
            #endif
        }
    #endif

    #if REG_DEFINED(ADC_N(PRESCALER_REG))
        /// #### static void prescaler([[AdcN::Prescaler]] p)
        static force_inline void prescaler(Prescaler p) {
            ADC_N(PRESCALER_REG)::setBits(ADC_N(PRESCALER_MASK), p);
        }
    #endif

    #if REG_DEFINED(ADC_N(TRIGGER_REG))
        /// #### static void trigger([[AdcN::Trigger]] t)
        static force_inline void trigger(Trigger t) {
            ADC_N(TRIGGER_REG)::setBits(ADC_N(TRIGGER_MASK), t);
        }
    #endif

    #if REG_DEFINED(ADC_N(INT_ENABLE_REG))
        /// #### static void intEnable(bool e)
        static force_inline void intEnable(bool e) {
            ADC_N(INT_ENABLE_REG)::setBit(ADC_N(INT_ENABLE_BIT), e);
        }
    #endif

    #if REG_DEFINED(ADC_N(INT_FLAG_REG))
        /// #### static bool intFlag()
        static force_inline bool intFlag() {
            return ADC_N(INT_FLAG_REG)::getBit(ADC_N(INT_FLAG_BIT));
        }

        /// #### static void intFlagClear()
        static force_inline void intFlagClear() {
            ADC_N(INT_FLAG_REG)::setBit(ADC_N(INT_FLAG_BIT), true);
        }
    #endif
};

#ifdef TEST

TEST(AdcN, getHardwareType) {
    ASSERT_EQ(AdcN::getHardwareType(), HardwareType::adc);
}

#if REG_DEFINED(ADC_N(ENABLE_REG))
    TEST(AdcN, enable) {
        TEST_REG_WRITE(AdcN::enable(true));
        TEST_REG_WRITE(AdcN::enable(false));
    }
#endif

#if REG_DEFINED(ADC_N(START_REG))
    TEST(AdcN, start) {
        TEST_REG_WRITE(AdcN::start());
    }
#endif

#if REG_DEFINED(ADC_N(FREE_RUNNING_REG))
    TEST(AdcN, freeRunning) {
        TEST_REG_WRITE(AdcN::freeRunning(true));
        TEST_REG_WRITE(AdcN::freeRunning(false));
    }
#endif

#if REG_DEFINED(ADC_N(TRIGGER_ENABLE_REG))
    TEST(AdcN, triggerEnable) {
        TEST_REG_WRITE(AdcN::triggerEnable(true));
        TEST_REG_WRITE(AdcN::triggerEnable(false));
    }
#endif

#if REG_DEFINED(ADC_N(BIPOLAR_MODE_ENABLE_REG))
    TEST(AdcN, bipolarModeEnable) {
        TEST_REG_WRITE(AdcN::bipolarModeEnable(true));
        TEST_REG_WRITE(AdcN::bipolarModeEnable(false));
    }
#endif

#if REG_DEFINED(ADC_N(RESULT_REG))
    TEST(AdcN, result) {
        TEST_REG_READ_WRITE(AdcN::result());
    }
#endif

#if REG_DEFINED(ADC_N(REFERENCE_REG))
    TEST(AdcN, reference) {
        #if DEFINED(ADC_N(REFERENCE_AREF_ID))
            TEST_REG_WRITE(AdcN::reference(AdcN::Reference::aref));
        #endif

        #if DEFINED(ADC_N(REFERENCE_AVCC_ID))
            TEST_REG_WRITE(AdcN::reference(AdcN::Reference::avcc));
        #endif

        #if DEFINED(ADC_N(REFERENCE_INTERNAL_ID))
            TEST_REG_WRITE(AdcN::reference(AdcN::Reference::internal));
        #endif

        #if DEFINED(ADC_N(REFERENCE_INTERNAL_1_1_ID))
            TEST_REG_WRITE(AdcN::reference(AdcN::Reference::internal_1_1));
        #endif

        #if DEFINED(ADC_N(REFERENCE_INTERNAL_2_56_ID))
            TEST_REG_WRITE(AdcN::reference(AdcN::Reference::internal_2_56));
        #endif

        #if DEFINED(ADC_N(REFERENCE_INTERNAL_2_56_CAP_ID))
            TEST_REG_WRITE(AdcN::reference(AdcN::Reference::internal_2_56_cap));
        #endif

        #if DEFINED(ADC_N(REFERENCE_VCC_ID))
            TEST_REG_WRITE(AdcN::reference(AdcN::Reference::vcc));
        #endif

        #if DEFINED(ADC_N(REFERENCE_VDD_ID))
            TEST_REG_WRITE(AdcN::reference(AdcN::Reference::vdd));
        #endif
    }
#endif

#if REG_DEFINED(ADC_N(CHANNEL_REG))
    TEST(AdcN, channel) {
        #if DEFINED(ADC_N(CHANNEL_0_ID))
            TEST_REG_WRITE(AdcN::channel(AdcN::Channel::adc0));
        #endif

        #if DEFINED(ADC_N(CHANNEL_1_ID))
            TEST_REG_WRITE(AdcN::channel(AdcN::Channel::adc1));
        #endif

        #if DEFINED(ADC_N(CHANNEL_2_ID))
            TEST_REG_WRITE(AdcN::channel(AdcN::Channel::adc2));
        #endif

        #if DEFINED(ADC_N(CHANNEL_3_ID))
            TEST_REG_WRITE(AdcN::channel(AdcN::Channel::adc3));
        #endif

        #if DEFINED(ADC_N(CHANNEL_4_ID))
            TEST_REG_WRITE(AdcN::channel(AdcN::Channel::adc4));
        #endif

        #if DEFINED(ADC_N(CHANNEL_5_ID))
            TEST_REG_WRITE(AdcN::channel(AdcN::Channel::adc5));
        #endif

        #if DEFINED(ADC_N(CHANNEL_6_ID))
            TEST_REG_WRITE(AdcN::channel(AdcN::Channel::adc6));
        #endif

        #if DEFINED(ADC_N(CHANNEL_7_ID))
            TEST_REG_WRITE(AdcN::channel(AdcN::Channel::adc7));
        #endif

        #if DEFINED(ADC_N(CHANNEL_8_ID))
            TEST_REG_WRITE(AdcN::channel(AdcN::Channel::adc8));
        #endif

        #if DEFINED(ADC_N(CHANNEL_VBG_ID))
            TEST_REG_WRITE(AdcN::channel(AdcN::Channel::vbg));
        #endif

        #if DEFINED(ADC_N(CHANNEL_INTERNAL_ID))
            TEST_REG_WRITE(AdcN::channel(AdcN::Channel::internal));
        #endif

        #if DEFINED(ADC_N(CHANNEL_TEMPERATURE_ID))
            TEST_REG_WRITE(AdcN::channel(AdcN::Channel::temperature));
        #endif

        #if DEFINED(ADC_N(CHANNEL_GND_ID))
            TEST_REG_WRITE(AdcN::channel(AdcN::Channel::gnd));
        #endif
    }
#endif

#if REG_DEFINED(ADC_N(PRESCALER_REG))
    TEST(AdcN, prescaler) {
        #if DEFINED(ADC_N(PRESCALER_2_ID))
            TEST_REG_WRITE(AdcN::prescaler(AdcN::Prescaler::div2));
        #endif

        #if DEFINED(ADC_N(PRESCALER_4_ID))
            TEST_REG_WRITE(AdcN::prescaler(AdcN::Prescaler::div4));
        #endif

        #if DEFINED(ADC_N(PRESCALER_8_ID))
            TEST_REG_WRITE(AdcN::prescaler(AdcN::Prescaler::div8));
        #endif

        #if DEFINED(ADC_N(PRESCALER_16_ID))
            TEST_REG_WRITE(AdcN::prescaler(AdcN::Prescaler::div16));
        #endif

        #if DEFINED(ADC_N(PRESCALER_32_ID))
            TEST_REG_WRITE(AdcN::prescaler(AdcN::Prescaler::div32));
        #endif

        #if DEFINED(ADC_N(PRESCALER_64_ID))
            TEST_REG_WRITE(AdcN::prescaler(AdcN::Prescaler::div64));
        #endif

        #if DEFINED(ADC_N(PRESCALER_128_ID))
            TEST_REG_WRITE(AdcN::prescaler(AdcN::Prescaler::div128));
        #endif
    }
#endif

#if REG_DEFINED(ADC_N(TRIGGER_REG))
    TEST(AdcN, trigger) {
        #if DEFINED(ADC_N(TRIGGER_FREE_RUNNING_ID))
            TEST_REG_WRITE(AdcN::trigger(AdcN::Trigger::freeRunning));
        #endif

        #if DEFINED(ADC_N(TRIGGER_ANALOG_COMPARATOR_ID))
            TEST_REG_WRITE(AdcN::trigger(AdcN::Trigger::analogComparator));
        #endif

        #if DEFINED(ADC_N(TRIGGER_EXTERNAL_INT_0_ID))
            TEST_REG_WRITE(AdcN::trigger(AdcN::Trigger::externalInt0));
        #endif

        #if DEFINED(ADC_N(TRIGGER_TIMER0_COMPARE_MATCH_A_ID))
            TEST_REG_WRITE(AdcN::trigger(AdcN::Trigger::timer0CompareMatchA));
        #endif

        #if DEFINED(ADC_N(TRIGGER_TIMER0_OVERFLOW_ID))
            TEST_REG_WRITE(AdcN::trigger(AdcN::Trigger::timer0Overflow));
        #endif

        #if DEFINED(ADC_N(TRIGGER_TIMER1_COMPARE_MATCH_B_ID))
            TEST_REG_WRITE(AdcN::trigger(AdcN::Trigger::timer1CompareMatchB));
        #endif

        #if DEFINED(ADC_N(TRIGGER_TIMER1_OVERFLOW_ID))
            TEST_REG_WRITE(AdcN::trigger(AdcN::Trigger::timer1Overflow));
        #endif

        #if DEFINED(ADC_N(TRIGGER_TIMER1_CAPTURE_EVENT_ID))
            TEST_REG_WRITE(AdcN::trigger(AdcN::Trigger::timer1CaptureEvent));
        #endif
    }
#endif

#if REG_DEFINED(ADC_N(INT_ENABLE_REG))
    TEST(AdcN, intEnable) {
        TEST_REG_WRITE(AdcN::intEnable(false));
        TEST_REG_WRITE(AdcN::intEnable(true));
    }
#endif

#if REG_DEFINED(ADC_N(INT_FLAG_REG))
    TEST(AdcN, intFlag) {
        TEST_REG_READ_WRITE(AdcN::intFlag());
    }

    TEST(AdcN, intFlagClear) {
        TEST_REG_WRITE(AdcN::intFlagClear());
    }
#endif

#endif // TEST

} // nblib::hw

//------------------------------------------------------------------

    #endif

    #undef N
    #undef AdcN
    #undef ADC_N

    #include "adc.hpp"
#else
    #define NBLIB_ADC_HPP
#endif

#endif
