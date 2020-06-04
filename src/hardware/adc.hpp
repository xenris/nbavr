/// [[Index]]

/// # {{Analog to Digital Converters}}

/// ```c++
/// atomic {
///     nblib::hw::Adc0::reference(nblib::hw::Adc0::Reference::avcc);
///     nblib::hw::Adc0::channel(nblib::hw::Adc0::Channel::adc1);
///     nblib::hw::Adc0::prescaler(nblib::hw::Adc0::Prescaler::div128);
///     nblib::hw::Adc0::trigger(nblib::hw::Adc0::Trigger::singleConversion);
///     nblib::hw::Adc0::intFlagClear();
/// }
///
/// nblib::hw::Adc0::start();
///
/// while(!nblib::hw::Adc0::intFlag());
///
/// const uint16_t value = nblib::hw::Adc0::value();
/// ```

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

    #if CAT(CHIP_ADC_, N)

//------------------------------------------------------------------

namespace nblib::hw {

/// ## class {{AdcN}}
struct AdcN {
    AdcN() = delete;
    AdcN& operator=(const AdcN&) = delete;
    AdcN(const AdcN&) = delete;

    /// #### enum {{AdcN::Reference}}
    /// * aref
    /// * avcc
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
    };

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

        #if DEFINED(ADC_N(CHANNEL_GND_ID))
            gnd = ADC_N(CHANNEL_GND_ID),
        #endif
    };

    #if DEFINED(ADC_N(PRESCALER_BIT_0_BIT))
        /// #### enum {{AdcN::Prescaler}}
        /// * div2
        /// * div4
        /// * div8
        /// * div16
        /// * div32
        /// * div64
        /// * div128
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
        };
    #endif

    #if DEFINED(ADC_N(TRIGGER_BIT_0_BIT))
        /// #### enum {{AdcN::Trigger}}
        /// * singleConversion
        /// * freeRunning
        /// * analogComparator
        /// * externalInt0
        /// * timer0CompareMatchA
        /// * timer0Overflow
        /// * timer1CompareMatchB
        /// * timer1Overflow
        /// * timer1CaptureEvent
        /// * freeRunning
        enum class Trigger {
            #if DEFINED(ADC_N(TRIGGER_SINGLE_CONVERSION_ID))
                singleConversion = ADC_N(TRIGGER_SINGLE_CONVERSION_ID),
            #endif

            #if DEFINED(ADC_N(TRIGGER_FREE_RUNNING_ID))
                freeRunning = ADC_N(TRIGGER_FREE_RUNNING_ID),
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

    #if DEFINED(ADC_N(ENABLE_BIT_0_BIT))
        /// #### static void enable(bool e)
        static force_inline void enable(bool e) {
            setBit_(REG(ADC_N(ENABLE_BIT_0_REG)), ADC_N(ENABLE_BIT_0_BIT), e);
        }
    #endif

    #if DEFINED(ADC_N(START_BIT_0_BIT))
        /// #### static void start()
        static force_inline void start() {
            setBit_(REG(ADC_N(START_BIT_0_REG)), ADC_N(START_BIT_0_BIT), true);
        }
    #endif

    #if REG_DEFINED(ADC_N(DATA_REG))
        /// #### static uint16_t value()
        static force_inline uint16_t value() {
            return getReg_(REG(ADC_N(DATA_REG)));
        }
    #endif

    #if DEFINED(ADC_N(REFERENCE_BIT_0_BIT))
        /// #### static void reference([[AdcN::Reference]] r)
        static force_inline void reference(Reference r) {
            setBit_(REG(ADC_N(REFERENCE_BIT_0_REG)), ADC_N(REFERENCE_BIT_0_BIT), int(r) & 0x01);
            setBit_(REG(ADC_N(REFERENCE_BIT_1_REG)), ADC_N(REFERENCE_BIT_1_BIT), int(r) & 0x02);
        }
    #endif

    #if DEFINED(ADC_N(CHANNEL_BIT_0_BIT))
        /// #### static void channel([[AdcN::Channel]] c)
        static force_inline void channel(Channel c) {
            setBit_(REG(ADC_N(CHANNEL_BIT_0_REG)), ADC_N(CHANNEL_BIT_0_BIT), int(c) & 0x01);
            setBit_(REG(ADC_N(CHANNEL_BIT_1_REG)), ADC_N(CHANNEL_BIT_1_BIT), int(c) & 0x02);
            setBit_(REG(ADC_N(CHANNEL_BIT_2_REG)), ADC_N(CHANNEL_BIT_2_BIT), int(c) & 0x04);
            setBit_(REG(ADC_N(CHANNEL_BIT_3_REG)), ADC_N(CHANNEL_BIT_3_BIT), int(c) & 0x08);
        }
    #endif

    #if DEFINED(ADC_N(PRESCALER_BIT_0_BIT))
        /// #### static void prescaler([[AdcN::Prescaler]] p)
        static force_inline void prescaler(Prescaler p) {
            setBit_(REG(ADC_N(PRESCALER_BIT_0_REG)), ADC_N(PRESCALER_BIT_0_BIT), int(p) & 0x01);
            setBit_(REG(ADC_N(PRESCALER_BIT_1_REG)), ADC_N(PRESCALER_BIT_1_BIT), int(p) & 0x02);
            setBit_(REG(ADC_N(PRESCALER_BIT_2_REG)), ADC_N(PRESCALER_BIT_2_BIT), int(p) & 0x04);
        }
    #endif

    #if DEFINED(ADC_N(LEFT_ADJUST_BIT_0_BIT))
        /// #### static void leftAdjust(bool l)
        static force_inline void leftAdjust(bool l) {
            setBit_(REG(ADC_N(LEFT_ADJUST_BIT_0_REG)), ADC_N(LEFT_ADJUST_BIT_0_BIT), l);
        }
    #endif

    #if DEFINED(ADC_N(TRIGGER_BIT_0_BIT))
        /// #### static void trigger([[AdcN::Trigger]] t)
        static force_inline void trigger(Trigger t) {
            setBit_(REG(ADC_N(TRIGGER_BIT_0_REG)), ADC_N(TRIGGER_BIT_0_BIT), int(t) & 0x01);

            #if DEFINED(ADC_N(TRIGGER_BIT_1_BIT))
                setBit_(REG(ADC_N(TRIGGER_BIT_1_REG)), ADC_N(TRIGGER_BIT_1_BIT), int(t) & 0x02);
            #endif

            #if DEFINED(ADC_N(TRIGGER_BIT_2_BIT))
                setBit_(REG(ADC_N(TRIGGER_BIT_2_REG)), ADC_N(TRIGGER_BIT_2_BIT), int(t) & 0x04);
            #endif

            #if DEFINED(ADC_N(TRIGGER_BIT_3_BIT))
                setBit_(REG(ADC_N(TRIGGER_BIT_3_REG)), ADC_N(TRIGGER_BIT_3_BIT), int(t) & 0x08);
            #endif
        }
    #endif

    #if DEFINED(ADC_N(INT_ENABLE_BIT_0_BIT))
        /// #### static void intEnable(bool e)
        static force_inline void intEnable(bool e) {
            setBit_(REG(ADC_N(INT_ENABLE_BIT_0_REG)), ADC_N(INT_ENABLE_BIT_0_BIT), e);
        }
    #endif

    #if DEFINED(ADC_N(INT_FLAG_BIT_0_BIT))
        /// #### static bool intFlag()
        static force_inline bool intFlag() {
            return getBit_(REG(ADC_N(INT_FLAG_BIT_0_REG)), ADC_N(INT_FLAG_BIT_0_BIT));
        }
    #endif

    #if DEFINED(ADC_N(INT_FLAG_BIT_0_BIT))
        /// #### static void intFlagClear()
        static force_inline void intFlagClear() {
            // Can't use clearFlagBit() as this bit is not in a pure flag register.
            // TODO work out how to define this in the chip definition files.
            setBit_(REG(ADC_N(INT_FLAG_BIT_0_REG)), ADC_N(INT_FLAG_BIT_0_BIT), true);
        }
    #endif
};

#ifdef TEST

TEST(AdcN, getHardwareType) {
    ASSERT_EQ(AdcN::getHardwareType(), HardwareType::adc);
}

#if DEFINED(ADC_N(ENABLE_BIT_0_BIT))
    TEST(AdcN, enable) {
        TEST_REG_WRITE(AdcN::enable(true));
        TEST_REG_WRITE(AdcN::enable(false));
    }
#endif

#if DEFINED(ADC_N(START_BIT_0_BIT))
    TEST(AdcN, start) {
        TEST_REG_WRITE(AdcN::start());
    }
#endif

#if REG_DEFINED(ADC_N(DATA_REG))
    TEST(AdcN, value) {
        TEST_REG_READ_WRITE(AdcN::value());
    }
#endif

#if DEFINED(ADC_N(REFERENCE_BIT_0_BIT))
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
    }
#endif

#if DEFINED(ADC_N(CHANNEL_BIT_0_BIT))
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

        #if DEFINED(ADC_N(CHANNEL_GND_ID))
            TEST_REG_WRITE(AdcN::channel(AdcN::Channel::gnd));
        #endif
    }
#endif

#if DEFINED(ADC_N(PRESCALER_BIT_0_BIT))
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

#if DEFINED(ADC_N(LEFT_ADJUST_BIT_0_BIT))
    TEST(AdcN, leftAdjust) {
        TEST_REG_WRITE(AdcN::leftAdjust(true));
        TEST_REG_WRITE(AdcN::leftAdjust(false));
    }
#endif

#if DEFINED(ADC_N(TRIGGER_BIT_0_BIT))
    TEST(AdcN, trigger) {
        #if DEFINED(ADC_N(TRIGGER_SINGLE_CONVERSION_ID))
            TEST_REG_WRITE(AdcN::trigger(AdcN::Trigger::singleConversion));
        #endif

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

#if DEFINED(ADC_N(INT_ENABLE_BIT_0_BIT))
    TEST(AdcN, intEnable) {
        TEST_REG_WRITE(AdcN::intEnable(false));
        TEST_REG_WRITE(AdcN::intEnable(true));
    }
#endif

#if DEFINED(ADC_N(INT_FLAG_BIT_0_BIT))
    TEST(AdcN, intFlag) {
        TEST_REG_READ_WRITE(AdcN::intFlag());
    }
#endif

#if DEFINED(ADC_N(INT_FLAG_BIT_0_BIT))
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
