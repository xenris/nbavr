#define __AVR_ATmega2560__

#define RECORD_ID "atmega2560"

#include "test.hpp"

typedef void (*ft)(void*);

static ft func = (ft)0x1234;
static void* data = (void*)0x5678;

//------------------------------------------------
// Analog to Digital

INCLUDE_ADC_CALLBACK;

TEST(Adc, getHardwareType) {
    ASSERT_EQ(Adc::getHardwareType(), HardwareType::ADC);
}

TEST(Adc, enable) {
    TEST_REG_WRITE(Adc::enable(true));
    TEST_REG_WRITE(Adc::enable(false));
}

TEST(Adc, start) {
    TEST_REG_WRITE(Adc::start());
}

TEST(Adc, value) {
    TEST_REG_READ_WRITE(Adc::value());
}

TEST(Adc, reference) {
    TEST_REG_WRITE(Adc::reference(Adc::Reference::AREF));
    TEST_REG_WRITE(Adc::reference(Adc::Reference::AVCC));
    TEST_REG_WRITE(Adc::reference(Adc::Reference::Internal));
}

TEST(Adc, channel) {
    TEST_REG_WRITE(Adc::channel(Adc::Channel::ADC0));
    TEST_REG_WRITE(Adc::channel(Adc::Channel::ADC1));
    TEST_REG_WRITE(Adc::channel(Adc::Channel::ADC2));
    TEST_REG_WRITE(Adc::channel(Adc::Channel::ADC3));
    TEST_REG_WRITE(Adc::channel(Adc::Channel::ADC4));
    TEST_REG_WRITE(Adc::channel(Adc::Channel::ADC5));
    TEST_REG_WRITE(Adc::channel(Adc::Channel::ADC6));
    TEST_REG_WRITE(Adc::channel(Adc::Channel::ADC7));
    // TEST_REG_WRITE(Adc::channel(Adc::Channel::ADC8));
    // TEST_REG_WRITE(Adc::channel(Adc::Channel::VBG));
    // TEST_REG_WRITE(Adc::channel(Adc::Channel::GND));
}

TEST(Adc, prescaler) {
    TEST_REG_WRITE(Adc::prescaler(Adc::Prescaler::Div2));
    TEST_REG_WRITE(Adc::prescaler(Adc::Prescaler::Div4));
    TEST_REG_WRITE(Adc::prescaler(Adc::Prescaler::Div8));
    TEST_REG_WRITE(Adc::prescaler(Adc::Prescaler::Div16));
    TEST_REG_WRITE(Adc::prescaler(Adc::Prescaler::Div32));
    TEST_REG_WRITE(Adc::prescaler(Adc::Prescaler::Div64));
    TEST_REG_WRITE(Adc::prescaler(Adc::Prescaler::Div128));
}

TEST(Adc, leftAdjust) {
    TEST_REG_WRITE(Adc::leftAdjust(true));
    TEST_REG_WRITE(Adc::leftAdjust(false));
}

TEST(Adc, trigger) {
    TEST_REG_WRITE(Adc::trigger(Adc::Trigger::SingleConversion));
    TEST_REG_WRITE(Adc::trigger(Adc::Trigger::FreeRunning));
    TEST_REG_WRITE(Adc::trigger(Adc::Trigger::AnalogComparator));
    TEST_REG_WRITE(Adc::trigger(Adc::Trigger::ExternalInt0));
    TEST_REG_WRITE(Adc::trigger(Adc::Trigger::Timer0CompareMatchA));
    TEST_REG_WRITE(Adc::trigger(Adc::Trigger::Timer0Overflow));
    TEST_REG_WRITE(Adc::trigger(Adc::Trigger::Timer1CompareMatchB));
    TEST_REG_WRITE(Adc::trigger(Adc::Trigger::Timer1Overflow));
    TEST_REG_WRITE(Adc::trigger(Adc::Trigger::Timer1CaptureEvent));
}

TEST(Adc, callback) {
    TEST_REG_WRITE(Adc::callback(func,data));
}

TEST(Adc, intEnable) {
    TEST_REG_WRITE(Adc::intEnable(false));
    TEST_REG_WRITE(Adc::intEnable(true));
}

TEST(Adc, intFlag) {
    TEST_REG_READ_WRITE(Adc::intFlag());
}

TEST(Adc, intFlagClear) {
    TEST_REG_WRITE(Adc::intFlagClear());
}

//------------------------------------------------
// External Interrupts

INCLUDE_EXINT_CALLBACK(0);
INCLUDE_EXINT_CALLBACK(1);
INCLUDE_EXINT_CALLBACK(2);
INCLUDE_EXINT_CALLBACK(3);
INCLUDE_EXINT_CALLBACK(4);
INCLUDE_EXINT_CALLBACK(5);
INCLUDE_EXINT_CALLBACK(6);
INCLUDE_EXINT_CALLBACK(7);

TEST(ExIntN, getHardwareType) {
    ASSERT_EQ(ExInt0::getHardwareType(), HardwareType::ExInt);
    ASSERT_EQ(ExInt1::getHardwareType(), HardwareType::ExInt);
    ASSERT_EQ(ExInt2::getHardwareType(), HardwareType::ExInt);
    ASSERT_EQ(ExInt3::getHardwareType(), HardwareType::ExInt);
    ASSERT_EQ(ExInt4::getHardwareType(), HardwareType::ExInt);
    ASSERT_EQ(ExInt5::getHardwareType(), HardwareType::ExInt);
    ASSERT_EQ(ExInt6::getHardwareType(), HardwareType::ExInt);
    ASSERT_EQ(ExInt7::getHardwareType(), HardwareType::ExInt);
}

TEST(ExIntN, enable) {
    TEST_REG_WRITE(ExInt0::enable(true));
    TEST_REG_WRITE(ExInt0::enable(false));
    TEST_REG_WRITE(ExInt1::enable(true));
    TEST_REG_WRITE(ExInt1::enable(false));
    TEST_REG_WRITE(ExInt2::enable(true));
    TEST_REG_WRITE(ExInt2::enable(false));
    TEST_REG_WRITE(ExInt3::enable(true));
    TEST_REG_WRITE(ExInt3::enable(false));
    TEST_REG_WRITE(ExInt4::enable(true));
    TEST_REG_WRITE(ExInt4::enable(false));
    TEST_REG_WRITE(ExInt5::enable(true));
    TEST_REG_WRITE(ExInt5::enable(false));
    TEST_REG_WRITE(ExInt6::enable(true));
    TEST_REG_WRITE(ExInt6::enable(false));
    TEST_REG_WRITE(ExInt7::enable(true));
    TEST_REG_WRITE(ExInt7::enable(false));
}

TEST(ExIntN, trigger) {
    TEST_REG_WRITE(ExInt0::trigger(ExInt0::Trigger::Low));
    TEST_REG_WRITE(ExInt0::trigger(ExInt0::Trigger::Change));
    TEST_REG_WRITE(ExInt0::trigger(ExInt0::Trigger::Falling));
    TEST_REG_WRITE(ExInt0::trigger(ExInt0::Trigger::Rising));

    TEST_REG_WRITE(ExInt1::trigger(ExInt1::Trigger::Low));
    TEST_REG_WRITE(ExInt1::trigger(ExInt1::Trigger::Change));
    TEST_REG_WRITE(ExInt1::trigger(ExInt1::Trigger::Falling));
    TEST_REG_WRITE(ExInt1::trigger(ExInt1::Trigger::Rising));

    TEST_REG_WRITE(ExInt2::trigger(ExInt2::Trigger::Low));
    TEST_REG_WRITE(ExInt2::trigger(ExInt2::Trigger::Change));
    TEST_REG_WRITE(ExInt2::trigger(ExInt2::Trigger::Falling));
    TEST_REG_WRITE(ExInt2::trigger(ExInt2::Trigger::Rising));

    TEST_REG_WRITE(ExInt3::trigger(ExInt3::Trigger::Low));
    TEST_REG_WRITE(ExInt3::trigger(ExInt3::Trigger::Change));
    TEST_REG_WRITE(ExInt3::trigger(ExInt3::Trigger::Falling));
    TEST_REG_WRITE(ExInt3::trigger(ExInt3::Trigger::Rising));

    TEST_REG_WRITE(ExInt4::trigger(ExInt4::Trigger::Low));
    TEST_REG_WRITE(ExInt4::trigger(ExInt4::Trigger::Change));
    TEST_REG_WRITE(ExInt4::trigger(ExInt4::Trigger::Falling));
    TEST_REG_WRITE(ExInt4::trigger(ExInt4::Trigger::Rising));

    TEST_REG_WRITE(ExInt5::trigger(ExInt5::Trigger::Low));
    TEST_REG_WRITE(ExInt5::trigger(ExInt5::Trigger::Change));
    TEST_REG_WRITE(ExInt5::trigger(ExInt5::Trigger::Falling));
    TEST_REG_WRITE(ExInt5::trigger(ExInt5::Trigger::Rising));

    TEST_REG_WRITE(ExInt6::trigger(ExInt6::Trigger::Low));
    TEST_REG_WRITE(ExInt6::trigger(ExInt6::Trigger::Change));
    TEST_REG_WRITE(ExInt6::trigger(ExInt6::Trigger::Falling));
    TEST_REG_WRITE(ExInt6::trigger(ExInt6::Trigger::Rising));

    TEST_REG_WRITE(ExInt7::trigger(ExInt7::Trigger::Low));
    TEST_REG_WRITE(ExInt7::trigger(ExInt7::Trigger::Change));
    TEST_REG_WRITE(ExInt7::trigger(ExInt7::Trigger::Falling));
    TEST_REG_WRITE(ExInt7::trigger(ExInt7::Trigger::Rising));
}

TEST(ExIntN, callback) {
    TEST_REG_WRITE(ExInt0::callback(func,data));
    TEST_REG_WRITE(ExInt1::callback(func,data));
    TEST_REG_WRITE(ExInt2::callback(func,data));
    TEST_REG_WRITE(ExInt3::callback(func,data));
    TEST_REG_WRITE(ExInt4::callback(func,data));
    TEST_REG_WRITE(ExInt5::callback(func,data));
    TEST_REG_WRITE(ExInt6::callback(func,data));
    TEST_REG_WRITE(ExInt7::callback(func,data));
}

TEST(ExIntN, intFlag) {
    TEST_REG_READ_WRITE(ExInt0::intFlag());
    TEST_REG_READ_WRITE(ExInt1::intFlag());
    TEST_REG_READ_WRITE(ExInt2::intFlag());
    TEST_REG_READ_WRITE(ExInt3::intFlag());
    TEST_REG_READ_WRITE(ExInt4::intFlag());
    TEST_REG_READ_WRITE(ExInt5::intFlag());
    TEST_REG_READ_WRITE(ExInt6::intFlag());
    TEST_REG_READ_WRITE(ExInt7::intFlag());
}

TEST(ExIntN, intFlagClear) {
    TEST_REG_WRITE(ExInt0::intFlagClear());
    TEST_REG_WRITE(ExInt1::intFlagClear());
    TEST_REG_WRITE(ExInt2::intFlagClear());
    TEST_REG_WRITE(ExInt3::intFlagClear());
    TEST_REG_WRITE(ExInt4::intFlagClear());
    TEST_REG_WRITE(ExInt5::intFlagClear());
    TEST_REG_WRITE(ExInt6::intFlagClear());
    TEST_REG_WRITE(ExInt7::intFlagClear());
}

//------------------------------------------------
// Pin Change Interrupts

INCLUDE_PCINT_CALLBACK(0);
INCLUDE_PCINT_CALLBACK(1);
INCLUDE_PCINT_CALLBACK(2);

TEST(PcIntN, getHardwareType) {
    ASSERT_EQ(PcInt0::getHardwareType(), HardwareType::PcInt);
    ASSERT_EQ(PcInt1::getHardwareType(), HardwareType::PcInt);
    ASSERT_EQ(PcInt2::getHardwareType(), HardwareType::PcInt);
}

TEST(PcIntN, enable) {
    TEST_REG_WRITE(PcInt0::enable(true));
    TEST_REG_WRITE(PcInt0::enable(false));
    TEST_REG_WRITE(PcInt1::enable(true));
    TEST_REG_WRITE(PcInt1::enable(false));
    TEST_REG_WRITE(PcInt2::enable(true));
    TEST_REG_WRITE(PcInt2::enable(false));
}

TEST(PcIntN, mask) {
    TEST_REG_WRITE(PcInt0::mask(0x64));
    TEST_REG_WRITE(PcInt1::mask(0x54));
    TEST_REG_WRITE(PcInt2::mask(0x16));
}

TEST(PcIntN, callback) {
    TEST_REG_WRITE(PcInt0::callback(func,data));
    TEST_REG_WRITE(PcInt1::callback(func,data));
    TEST_REG_WRITE(PcInt2::callback(func,data));
}

TEST(PcIntN, intFlag) {
    TEST_REG_READ_WRITE(PcInt0::intFlag());
    TEST_REG_READ_WRITE(PcInt1::intFlag());
    TEST_REG_READ_WRITE(PcInt2::intFlag());
}

TEST(PcIntN, intFlagClear) {
    TEST_REG_WRITE(PcInt0::intFlagClear());
    TEST_REG_WRITE(PcInt1::intFlagClear());
    TEST_REG_WRITE(PcInt2::intFlagClear());
}

//------------------------------------------------
// Digital Pins

TEST(PinXN, getHardwareType) {
    ASSERT_EQ(PinA0::getHardwareType(), HardwareType::Pin);
    ASSERT_EQ(PinA7::getHardwareType(), HardwareType::Pin);
    ASSERT_EQ(PinB0::getHardwareType(), HardwareType::Pin);
    ASSERT_EQ(PinB7::getHardwareType(), HardwareType::Pin);
    ASSERT_EQ(PinC0::getHardwareType(), HardwareType::Pin);
    ASSERT_EQ(PinC6::getHardwareType(), HardwareType::Pin);
    ASSERT_EQ(PinD0::getHardwareType(), HardwareType::Pin);
    ASSERT_EQ(PinD7::getHardwareType(), HardwareType::Pin);
    ASSERT_EQ(PinE0::getHardwareType(), HardwareType::Pin);
    ASSERT_EQ(PinE7::getHardwareType(), HardwareType::Pin);
    ASSERT_EQ(PinF0::getHardwareType(), HardwareType::Pin);
    ASSERT_EQ(PinF7::getHardwareType(), HardwareType::Pin);
    ASSERT_EQ(PinG0::getHardwareType(), HardwareType::Pin);
    ASSERT_EQ(PinG5::getHardwareType(), HardwareType::Pin);
    ASSERT_EQ(PinH0::getHardwareType(), HardwareType::Pin);
    ASSERT_EQ(PinH7::getHardwareType(), HardwareType::Pin);
    ASSERT_EQ(PinJ0::getHardwareType(), HardwareType::Pin);
    ASSERT_EQ(PinJ7::getHardwareType(), HardwareType::Pin);
    ASSERT_EQ(PinK0::getHardwareType(), HardwareType::Pin);
    ASSERT_EQ(PinK7::getHardwareType(), HardwareType::Pin);
    ASSERT_EQ(PinL0::getHardwareType(), HardwareType::Pin);
    ASSERT_EQ(PinL7::getHardwareType(), HardwareType::Pin);
}

TEST(PinXN, direction) {
    TEST_REG_WRITE(PinB0::direction(Direction::Input));
    TEST_REG_WRITE(PinB0::direction(Direction::Output));
    TEST_REG_READ_WRITE(PinB0::direction());

    TEST_REG_WRITE(PinC6::direction(Direction::Input));
    TEST_REG_WRITE(PinC6::direction(Direction::Output));
    TEST_REG_READ_WRITE(PinC6::direction());

    TEST_REG_WRITE(PinD3::direction(Direction::Input));
    TEST_REG_WRITE(PinD3::direction(Direction::Output));
    TEST_REG_READ_WRITE(PinD3::direction());
}

TEST(PinXN, pullup) {
    TEST_REG_WRITE(PinB1::pullup(true));
    TEST_REG_WRITE(PinB1::pullup(false));
    TEST_REG_READ_WRITE(PinB1::pullup());

    TEST_REG_WRITE(PinC5::pullup(true));
    TEST_REG_WRITE(PinC5::pullup(false));
    TEST_REG_READ_WRITE(PinC5::pullup());

    TEST_REG_WRITE(PinD4::pullup(true));
    TEST_REG_WRITE(PinD4::pullup(false));
    TEST_REG_READ_WRITE(PinD4::pullup());
}

TEST(PinXN, output) {
    TEST_REG_READ_WRITE(PinB2::output());

    TEST_REG_READ_WRITE(PinC4::output());

    TEST_REG_READ_WRITE(PinD4::output());
}

TEST(PinXN, input) {
    TEST_REG_READ_WRITE(PinB3::input());

    TEST_REG_READ_WRITE(PinC3::input());

    TEST_REG_READ_WRITE(PinD4::input());
}

TEST(PinXN, toggle) {
    TEST_REG_WRITE(PinB4::toggle());
    TEST_REG_WRITE(PinC2::toggle());
    TEST_REG_WRITE(PinD5::toggle());
}

//------------------------------------------------
// Digital Ports

TEST(PortX, getHardwareType) {
    ASSERT_EQ(PortA::getHardwareType(), HardwareType::Port);
    ASSERT_EQ(PortB::getHardwareType(), HardwareType::Port);
    ASSERT_EQ(PortC::getHardwareType(), HardwareType::Port);
    ASSERT_EQ(PortD::getHardwareType(), HardwareType::Port);
    ASSERT_EQ(PortE::getHardwareType(), HardwareType::Port);
    ASSERT_EQ(PortF::getHardwareType(), HardwareType::Port);
    ASSERT_EQ(PortG::getHardwareType(), HardwareType::Port);
    ASSERT_EQ(PortH::getHardwareType(), HardwareType::Port);
    ASSERT_EQ(PortJ::getHardwareType(), HardwareType::Port);
    ASSERT_EQ(PortK::getHardwareType(), HardwareType::Port);
    ASSERT_EQ(PortL::getHardwareType(), HardwareType::Port);
}

TEST(PortX, direction) {
    TEST_REG_WRITE(PortA::direction(0x1f));
    TEST_REG_READ_WRITE(PortA::direction());

    TEST_REG_WRITE(PortB::direction(0x3c));
    TEST_REG_READ_WRITE(PortB::direction());

    TEST_REG_WRITE(PortC::direction(0x74));
    TEST_REG_READ_WRITE(PortC::direction());

    TEST_REG_WRITE(PortD::direction(0x98));
    TEST_REG_READ_WRITE(PortD::direction());

    TEST_REG_WRITE(PortE::direction(0x51));
    TEST_REG_READ_WRITE(PortE::direction());

    TEST_REG_WRITE(PortF::direction(0xa6));
    TEST_REG_READ_WRITE(PortF::direction());

    TEST_REG_WRITE(PortG::direction(0x5d));
    TEST_REG_READ_WRITE(PortG::direction());

    TEST_REG_WRITE(PortH::direction(0x2d));
    TEST_REG_READ_WRITE(PortH::direction());

    TEST_REG_WRITE(PortJ::direction(0xc4));
    TEST_REG_READ_WRITE(PortJ::direction());

    TEST_REG_WRITE(PortK::direction(0xc2));
    TEST_REG_READ_WRITE(PortK::direction());

    TEST_REG_WRITE(PortL::direction(0x76));
    TEST_REG_READ_WRITE(PortL::direction());
}

TEST(PortX, pullup) {
    TEST_REG_WRITE(PortA::pullup(0xb8));
    TEST_REG_READ_WRITE(PortA::pullup());

    TEST_REG_WRITE(PortB::pullup(0x12));
    TEST_REG_READ_WRITE(PortB::pullup());

    TEST_REG_WRITE(PortC::pullup(0x41));
    TEST_REG_READ_WRITE(PortC::pullup());

    TEST_REG_WRITE(PortD::pullup(0x26));
    TEST_REG_READ_WRITE(PortD::pullup());

    TEST_REG_WRITE(PortE::pullup(0x1d));
    TEST_REG_READ_WRITE(PortE::pullup());

    TEST_REG_WRITE(PortF::pullup(0x7f));
    TEST_REG_READ_WRITE(PortF::pullup());

    TEST_REG_WRITE(PortG::pullup(0x3d));
    TEST_REG_READ_WRITE(PortG::pullup());

    TEST_REG_WRITE(PortH::pullup(0xcc));
    TEST_REG_READ_WRITE(PortH::pullup());

    TEST_REG_WRITE(PortJ::pullup(0x3c));
    TEST_REG_READ_WRITE(PortJ::pullup());

    TEST_REG_WRITE(PortK::pullup(0x7a));
    TEST_REG_READ_WRITE(PortK::pullup());

    TEST_REG_WRITE(PortL::pullup(0x5c));
    TEST_REG_READ_WRITE(PortL::pullup());
}

TEST(PortX, output) {
    TEST_REG_WRITE(PortA::output(0x86));
    TEST_REG_READ_WRITE(PortA::output());

    TEST_REG_WRITE(PortB::output(0x27));
    TEST_REG_READ_WRITE(PortB::output());

    TEST_REG_WRITE(PortC::output(0xf4));
    TEST_REG_READ_WRITE(PortC::output());

    TEST_REG_WRITE(PortD::output(0xa4));
    TEST_REG_READ_WRITE(PortD::output());

    TEST_REG_WRITE(PortE::output(0x21));
    TEST_REG_READ_WRITE(PortE::output());

    TEST_REG_WRITE(PortF::output(0x43));
    TEST_REG_READ_WRITE(PortF::output());

    TEST_REG_WRITE(PortG::output(0xc8));
    TEST_REG_READ_WRITE(PortG::output());

    TEST_REG_WRITE(PortH::output(0x6c));
    TEST_REG_READ_WRITE(PortH::output());

    TEST_REG_WRITE(PortJ::output(0xe9));
    TEST_REG_READ_WRITE(PortJ::output());

    TEST_REG_WRITE(PortK::output(0xe3));
    TEST_REG_READ_WRITE(PortK::output());

    TEST_REG_WRITE(PortL::output(0x8e));
    TEST_REG_READ_WRITE(PortL::output());
}

TEST(PortX, input) {
    TEST_REG_READ_WRITE(PortA::input());

    TEST_REG_READ_WRITE(PortB::input());

    TEST_REG_READ_WRITE(PortC::input());

    TEST_REG_READ_WRITE(PortD::input());

    TEST_REG_READ_WRITE(PortE::input());

    TEST_REG_READ_WRITE(PortF::input());

    TEST_REG_READ_WRITE(PortG::input());

    TEST_REG_READ_WRITE(PortH::input());

    TEST_REG_READ_WRITE(PortJ::input());

    TEST_REG_READ_WRITE(PortK::input());

    TEST_REG_READ_WRITE(PortL::input());
}

TEST(PortX, toggle) {
    TEST_REG_WRITE(PortA::toggle(0xd7));

    TEST_REG_WRITE(PortB::toggle(0x26));

    TEST_REG_WRITE(PortC::toggle(0xb4));

    TEST_REG_WRITE(PortD::toggle(0x82));

    TEST_REG_WRITE(PortE::toggle(0xdd));

    TEST_REG_WRITE(PortF::toggle(0x9c));

    TEST_REG_WRITE(PortG::toggle(0x41));

    TEST_REG_WRITE(PortH::toggle(0x66));

    TEST_REG_WRITE(PortJ::toggle(0xa3));

    TEST_REG_WRITE(PortK::toggle(0x71));

    TEST_REG_WRITE(PortL::toggle(0x92));
}

//------------------------------------------------
// Timer/Counters

INCLUDE_TIMERCOUNTER_OVERFLOW_CALLBACK(0);
INCLUDE_TIMERCOUNTER_OVERFLOW_CALLBACK(1);
INCLUDE_TIMERCOUNTER_OVERFLOW_CALLBACK(2);
INCLUDE_TIMERCOUNTER_OVERFLOW_CALLBACK(3);
INCLUDE_TIMERCOUNTER_OVERFLOW_CALLBACK(4);
INCLUDE_TIMERCOUNTER_OVERFLOW_CALLBACK(5);
INCLUDE_TIMERCOUNTER_OUTPUT_CALLBACK(0, A);
INCLUDE_TIMERCOUNTER_OUTPUT_CALLBACK(0, B);
INCLUDE_TIMERCOUNTER_OUTPUT_CALLBACK(1, A);
INCLUDE_TIMERCOUNTER_OUTPUT_CALLBACK(1, B);
INCLUDE_TIMERCOUNTER_OUTPUT_CALLBACK(1, C);
INCLUDE_TIMERCOUNTER_OUTPUT_CALLBACK(2, A);
INCLUDE_TIMERCOUNTER_OUTPUT_CALLBACK(2, B);
INCLUDE_TIMERCOUNTER_OUTPUT_CALLBACK(3, A);
INCLUDE_TIMERCOUNTER_OUTPUT_CALLBACK(3, B);
INCLUDE_TIMERCOUNTER_OUTPUT_CALLBACK(3, C);
INCLUDE_TIMERCOUNTER_OUTPUT_CALLBACK(4, A);
INCLUDE_TIMERCOUNTER_OUTPUT_CALLBACK(4, B);
INCLUDE_TIMERCOUNTER_OUTPUT_CALLBACK(4, C);
INCLUDE_TIMERCOUNTER_OUTPUT_CALLBACK(5, A);
INCLUDE_TIMERCOUNTER_OUTPUT_CALLBACK(5, B);
INCLUDE_TIMERCOUNTER_OUTPUT_CALLBACK(5, C);

TEST(TimerCounter0, getHardwareType) {
    ASSERT_EQ(TimerCounter0::getHardwareType(), HardwareType::TimerCounter);
}

TEST(TimerCounter0, type) {
    ::testing::StaticAssertTypeEq<TimerCounter0::type, uint8_t>();
}

TEST(TimerCounter0, counter) {
    TEST_REG_WRITE(TimerCounter0::counter(0xc4));
    TEST_REG_READ_WRITE(TimerCounter0::counter());
}

TEST(TimerCounter0, clock) {
    TEST_REG_WRITE(TimerCounter0::clock(TimerCounter0::Clock::None));
    TEST_REG_WRITE(TimerCounter0::clock(TimerCounter0::Clock::Div1));
    TEST_REG_WRITE(TimerCounter0::clock(TimerCounter0::Clock::Div8));
    TEST_REG_WRITE(TimerCounter0::clock(TimerCounter0::Clock::Div64));
    TEST_REG_WRITE(TimerCounter0::clock(TimerCounter0::Clock::Div256));
    TEST_REG_WRITE(TimerCounter0::clock(TimerCounter0::Clock::Div1024));
    TEST_REG_WRITE(TimerCounter0::clock(TimerCounter0::Clock::ExtFalling));
    TEST_REG_WRITE(TimerCounter0::clock(TimerCounter0::Clock::ExtRising));
}

TEST(TimerCounter0, waveform) {
    TEST_REG_WRITE(TimerCounter0::waveform(TimerCounter0::Waveform::Normal));
    TEST_REG_WRITE(TimerCounter0::waveform(TimerCounter0::Waveform::PWM));
    TEST_REG_WRITE(TimerCounter0::waveform(TimerCounter0::Waveform::CTCOCRA));
    TEST_REG_WRITE(TimerCounter0::waveform(TimerCounter0::Waveform::FastPWM));
    TEST_REG_WRITE(TimerCounter0::waveform(TimerCounter0::Waveform::PWMOCRA));
    TEST_REG_WRITE(TimerCounter0::waveform(TimerCounter0::Waveform::FastPWMOCRA));
}

TEST(TimerCounter0, overflowCallback) {
    TEST_REG_WRITE(TimerCounter0::overflowCallback(func,data));
}

TEST(TimerCounter0, overflowIntEnable) {
    TEST_REG_WRITE(TimerCounter0::overflowIntEnable(true));
    TEST_REG_WRITE(TimerCounter0::overflowIntEnable(false));
}

TEST(TimerCounter0, overflowIntFlag) {
    TEST_REG_READ_WRITE(TimerCounter0::overflowIntFlag());
}

TEST(TimerCounter0, overflowIntFlagClear) {
    TEST_REG_WRITE(TimerCounter0::overflowIntFlagClear());
}

TEST(TimerCounter0, outputA) {
    TEST_REG_WRITE(TimerCounter0::OutputCompareA::value(0xc8));
    TEST_REG_READ_WRITE(TimerCounter0::OutputCompareA::value());
}

TEST(TimerCounter0, outputB) {
    TEST_REG_WRITE(TimerCounter0::OutputCompareB::value(0x7a));
    TEST_REG_READ_WRITE(TimerCounter0::OutputCompareB::value());
}

TEST(TimerCounter0, outputAMode) {
    TEST_REG_WRITE(TimerCounter0::OutputCompareA::mode(TimerCounter0::OutputMode::Disconnected));
    TEST_REG_WRITE(TimerCounter0::OutputCompareA::mode(TimerCounter0::OutputMode::Toggle));
    TEST_REG_WRITE(TimerCounter0::OutputCompareA::mode(TimerCounter0::OutputMode::Clear));
    TEST_REG_WRITE(TimerCounter0::OutputCompareA::mode(TimerCounter0::OutputMode::Set));
}

TEST(TimerCounter0, outputBMode) {
    TEST_REG_WRITE(TimerCounter0::OutputCompareB::mode(TimerCounter0::OutputMode::Disconnected));
    TEST_REG_WRITE(TimerCounter0::OutputCompareB::mode(TimerCounter0::OutputMode::Toggle));
    TEST_REG_WRITE(TimerCounter0::OutputCompareB::mode(TimerCounter0::OutputMode::Clear));
    TEST_REG_WRITE(TimerCounter0::OutputCompareB::mode(TimerCounter0::OutputMode::Set));
}

TEST(TimerCounter0, outputACallback) {
    TEST_REG_WRITE(TimerCounter0::OutputCompareA::callback(func,data));
}

TEST(TimerCounter0, outputBCallback) {
    TEST_REG_WRITE(TimerCounter0::OutputCompareB::callback(func,data));
}

TEST(TimerCounter0, outputAIntEnable) {
    TEST_REG_WRITE(TimerCounter0::OutputCompareA::intEnable(true));
    TEST_REG_WRITE(TimerCounter0::OutputCompareA::intEnable(false));
}

TEST(TimerCounter0, outputBIntEnable) {
    TEST_REG_WRITE(TimerCounter0::OutputCompareB::intEnable(true));
    TEST_REG_WRITE(TimerCounter0::OutputCompareB::intEnable(false));
}

TEST(TimerCounter0, outputAIntFlag) {
    TEST_REG_READ_WRITE(TimerCounter0::OutputCompareA::intFlag());
}

TEST(TimerCounter0, outputBIntFlag) {
    TEST_REG_READ_WRITE(TimerCounter0::OutputCompareB::intFlag());
}

TEST(TimerCounter0, outputAIntFlagClear) {
    TEST_REG_WRITE(TimerCounter0::OutputCompareA::intFlagClear());
}

TEST(TimerCounter0, outputBIntFlagClear) {
    TEST_REG_WRITE(TimerCounter0::OutputCompareB::intFlagClear());
}

TEST(TimerCounter1, getHardwareType) {
    ASSERT_EQ(TimerCounter1::getHardwareType(), HardwareType::TimerCounter);
}

TEST(TimerCounter1, type) {
    ::testing::StaticAssertTypeEq<TimerCounter1::type, uint16_t>();
}

TEST(TimerCounter1, counter) {
    TEST_REG_WRITE(TimerCounter1::counter(0x7c8a));
    TEST_REG_READ_WRITE(TimerCounter1::counter());
}

TEST(TimerCounter1, clock) {
    TEST_REG_WRITE(TimerCounter1::clock(TimerCounter1::Clock::None));
    TEST_REG_WRITE(TimerCounter1::clock(TimerCounter1::Clock::Div1));
    TEST_REG_WRITE(TimerCounter1::clock(TimerCounter1::Clock::Div8));
    TEST_REG_WRITE(TimerCounter1::clock(TimerCounter1::Clock::Div64));
    TEST_REG_WRITE(TimerCounter1::clock(TimerCounter1::Clock::Div256));
    TEST_REG_WRITE(TimerCounter1::clock(TimerCounter1::Clock::Div1024));
    TEST_REG_WRITE(TimerCounter1::clock(TimerCounter1::Clock::ExtFalling));
    TEST_REG_WRITE(TimerCounter1::clock(TimerCounter1::Clock::ExtRising));
}

TEST(TimerCounter1, waveform) {
    TEST_REG_WRITE(TimerCounter1::waveform(TimerCounter1::Waveform::Normal));
    TEST_REG_WRITE(TimerCounter1::waveform(TimerCounter1::Waveform::PWM));
    TEST_REG_WRITE(TimerCounter1::waveform(TimerCounter1::Waveform::CTCOCRA));
    TEST_REG_WRITE(TimerCounter1::waveform(TimerCounter1::Waveform::FastPWM));
    TEST_REG_WRITE(TimerCounter1::waveform(TimerCounter1::Waveform::PWMOCRA));
    TEST_REG_WRITE(TimerCounter1::waveform(TimerCounter1::Waveform::FastPWMOCRA));
}

TEST(TimerCounter1, overflowCallback) {
    TEST_REG_WRITE(TimerCounter1::overflowCallback(func,data));
}

TEST(TimerCounter1, overflowIntEnable) {
    TEST_REG_WRITE(TimerCounter1::overflowIntEnable(true));
    TEST_REG_WRITE(TimerCounter1::overflowIntEnable(false));
}

TEST(TimerCounter1, overflowIntFlag) {
    TEST_REG_READ_WRITE(TimerCounter1::overflowIntFlag());
}

TEST(TimerCounter1, overflowIntFlagClear) {
    TEST_REG_WRITE(TimerCounter1::overflowIntFlagClear());
}

TEST(TimerCounter1, outputA) {
    TEST_REG_WRITE(TimerCounter1::OutputCompareA::value(0xe8d9));
    TEST_REG_READ_WRITE(TimerCounter1::OutputCompareA::value());
}

TEST(TimerCounter1, outputB) {
    TEST_REG_WRITE(TimerCounter1::OutputCompareB::value(0x7a8d));
    TEST_REG_READ_WRITE(TimerCounter1::OutputCompareB::value());
}

TEST(TimerCounter1, outputC) {
    TEST_REG_WRITE(TimerCounter1::OutputCompareC::value(0x6c8a));
    TEST_REG_READ_WRITE(TimerCounter1::OutputCompareC::value());
}

TEST(TimerCounter1, outputAMode) {
    TEST_REG_WRITE(TimerCounter1::OutputCompareA::mode(TimerCounter1::OutputMode::Disconnected));
    TEST_REG_WRITE(TimerCounter1::OutputCompareA::mode(TimerCounter1::OutputMode::Toggle));
    TEST_REG_WRITE(TimerCounter1::OutputCompareA::mode(TimerCounter1::OutputMode::Clear));
    TEST_REG_WRITE(TimerCounter1::OutputCompareA::mode(TimerCounter1::OutputMode::Set));
}

TEST(TimerCounter1, outputBMode) {
    TEST_REG_WRITE(TimerCounter1::OutputCompareB::mode(TimerCounter1::OutputMode::Disconnected));
    TEST_REG_WRITE(TimerCounter1::OutputCompareB::mode(TimerCounter1::OutputMode::Toggle));
    TEST_REG_WRITE(TimerCounter1::OutputCompareB::mode(TimerCounter1::OutputMode::Clear));
    TEST_REG_WRITE(TimerCounter1::OutputCompareB::mode(TimerCounter1::OutputMode::Set));
}

TEST(TimerCounter1, outputCMode) {
    TEST_REG_WRITE(TimerCounter1::OutputCompareC::mode(TimerCounter1::OutputMode::Disconnected));
    TEST_REG_WRITE(TimerCounter1::OutputCompareC::mode(TimerCounter1::OutputMode::Toggle));
    TEST_REG_WRITE(TimerCounter1::OutputCompareC::mode(TimerCounter1::OutputMode::Clear));
    TEST_REG_WRITE(TimerCounter1::OutputCompareC::mode(TimerCounter1::OutputMode::Set));
}

TEST(TimerCounter1, outputACallback) {
    TEST_REG_WRITE(TimerCounter1::OutputCompareA::callback(func,data));
}

TEST(TimerCounter1, outputBCallback) {
    TEST_REG_WRITE(TimerCounter1::OutputCompareB::callback(func,data));
}

TEST(TimerCounter1, outputCCallback) {
    TEST_REG_WRITE(TimerCounter1::OutputCompareC::callback(func,data));
}

TEST(TimerCounter1, outputAIntEnable) {
    TEST_REG_WRITE(TimerCounter1::OutputCompareA::intEnable(true));
    TEST_REG_WRITE(TimerCounter1::OutputCompareA::intEnable(false));
}

TEST(TimerCounter1, outputBIntEnable) {
    TEST_REG_WRITE(TimerCounter1::OutputCompareB::intEnable(true));
    TEST_REG_WRITE(TimerCounter1::OutputCompareB::intEnable(false));
}

TEST(TimerCounter1, outputCIntEnable) {
    TEST_REG_WRITE(TimerCounter1::OutputCompareC::intEnable(true));
    TEST_REG_WRITE(TimerCounter1::OutputCompareC::intEnable(false));
}

TEST(TimerCounter1, outputAIntFlag) {
    TEST_REG_READ_WRITE(TimerCounter1::OutputCompareA::intFlag());
}

TEST(TimerCounter1, outputBIntFlag) {
    TEST_REG_READ_WRITE(TimerCounter1::OutputCompareB::intFlag());
}

TEST(TimerCounter1, outputCIntFlag) {
    TEST_REG_READ_WRITE(TimerCounter1::OutputCompareC::intFlag());
}

TEST(TimerCounter1, outputAIntFlagClear) {
    TEST_REG_WRITE(TimerCounter1::OutputCompareA::intFlagClear());
}

TEST(TimerCounter1, outputBIntFlagClear) {
    TEST_REG_WRITE(TimerCounter1::OutputCompareB::intFlagClear());
}

TEST(TimerCounter1, outputCIntFlagClear) {
    TEST_REG_WRITE(TimerCounter1::OutputCompareC::intFlagClear());
}

TEST(TimerCounter2, getHardwareType) {
    ASSERT_EQ(TimerCounter2::getHardwareType(), HardwareType::TimerCounter);
}

TEST(TimerCounter2, type) {
    ::testing::StaticAssertTypeEq<TimerCounter2::type, uint8_t>();
}

TEST(TimerCounter2, counter) {
    TEST_REG_WRITE(TimerCounter2::counter(0x23));
    TEST_REG_READ_WRITE(TimerCounter2::counter());
}

TEST(TimerCounter2, clock) {
    TEST_REG_WRITE(TimerCounter2::clock(TimerCounter2::Clock::None));
    TEST_REG_WRITE(TimerCounter2::clock(TimerCounter2::Clock::Div1));
    TEST_REG_WRITE(TimerCounter2::clock(TimerCounter2::Clock::Div8));
    TEST_REG_WRITE(TimerCounter2::clock(TimerCounter2::Clock::Div32));
    TEST_REG_WRITE(TimerCounter2::clock(TimerCounter2::Clock::Div64));
    TEST_REG_WRITE(TimerCounter2::clock(TimerCounter2::Clock::Div128));
    TEST_REG_WRITE(TimerCounter2::clock(TimerCounter2::Clock::Div256));
    TEST_REG_WRITE(TimerCounter2::clock(TimerCounter2::Clock::Div1024));
}

TEST(TimerCounter2, waveform) {
    TEST_REG_WRITE(TimerCounter2::waveform(TimerCounter2::Waveform::Normal));
    TEST_REG_WRITE(TimerCounter2::waveform(TimerCounter2::Waveform::PWM));
    TEST_REG_WRITE(TimerCounter2::waveform(TimerCounter2::Waveform::CTCOCRA));
    TEST_REG_WRITE(TimerCounter2::waveform(TimerCounter2::Waveform::FastPWM));
    TEST_REG_WRITE(TimerCounter2::waveform(TimerCounter2::Waveform::PWMOCRA));
    TEST_REG_WRITE(TimerCounter2::waveform(TimerCounter2::Waveform::FastPWMOCRA));
}

TEST(TimerCounter2, overflowCallback) {
    TEST_REG_WRITE(TimerCounter2::overflowCallback(func,data));
}

TEST(TimerCounter2, overflowIntEnable) {
    TEST_REG_WRITE(TimerCounter2::overflowIntEnable(true));
    TEST_REG_WRITE(TimerCounter2::overflowIntEnable(false));
}

TEST(TimerCounter2, overflowIntFlag) {
    TEST_REG_READ_WRITE(TimerCounter2::overflowIntFlag());
}

TEST(TimerCounter2, overflowIntFlagClear) {
    TEST_REG_WRITE(TimerCounter2::overflowIntFlagClear());
}

TEST(TimerCounter2, outputA) {
    TEST_REG_WRITE(TimerCounter2::OutputCompareA::value(0xed));
    TEST_REG_READ_WRITE(TimerCounter2::OutputCompareA::value());
}

TEST(TimerCounter2, outputB) {
    TEST_REG_WRITE(TimerCounter2::OutputCompareB::value(0xd8));
    TEST_REG_READ_WRITE(TimerCounter2::OutputCompareB::value());
}

TEST(TimerCounter2, outputAMode) {
    TEST_REG_WRITE(TimerCounter2::OutputCompareA::mode(TimerCounter2::OutputMode::Disconnected));
    TEST_REG_WRITE(TimerCounter2::OutputCompareA::mode(TimerCounter2::OutputMode::Toggle));
    TEST_REG_WRITE(TimerCounter2::OutputCompareA::mode(TimerCounter2::OutputMode::Clear));
    TEST_REG_WRITE(TimerCounter2::OutputCompareA::mode(TimerCounter2::OutputMode::Set));
}

TEST(TimerCounter2, outputBMode) {
    TEST_REG_WRITE(TimerCounter2::OutputCompareB::mode(TimerCounter2::OutputMode::Disconnected));
    TEST_REG_WRITE(TimerCounter2::OutputCompareB::mode(TimerCounter2::OutputMode::Toggle));
    TEST_REG_WRITE(TimerCounter2::OutputCompareB::mode(TimerCounter2::OutputMode::Clear));
    TEST_REG_WRITE(TimerCounter2::OutputCompareB::mode(TimerCounter2::OutputMode::Set));
}

TEST(TimerCounter2, outputACallback) {
    TEST_REG_WRITE(TimerCounter2::OutputCompareA::callback(func,data));
}

TEST(TimerCounter2, outputBCallback) {
    TEST_REG_WRITE(TimerCounter2::OutputCompareB::callback(func,data));
}

TEST(TimerCounter2, outputAIntEnable) {
    TEST_REG_WRITE(TimerCounter2::OutputCompareA::intEnable(true));
    TEST_REG_WRITE(TimerCounter2::OutputCompareA::intEnable(false));
}

TEST(TimerCounter2, outputBIntEnable) {
    TEST_REG_WRITE(TimerCounter2::OutputCompareB::intEnable(true));
    TEST_REG_WRITE(TimerCounter2::OutputCompareB::intEnable(false));
}

TEST(TimerCounter2, outputAIntFlag) {
    TEST_REG_READ_WRITE(TimerCounter2::OutputCompareA::intFlag());
}

TEST(TimerCounter2, outputBIntFlag) {
    TEST_REG_READ_WRITE(TimerCounter2::OutputCompareB::intFlag());
}

TEST(TimerCounter2, outputAIntFlagClear) {
    TEST_REG_WRITE(TimerCounter2::OutputCompareA::intFlagClear());
}

TEST(TimerCounter2, outputBIntFlagClear) {
    TEST_REG_WRITE(TimerCounter2::OutputCompareB::intFlagClear());
}


TEST(TimerCounter3, getHardwareType) {
    ASSERT_EQ(TimerCounter3::getHardwareType(), HardwareType::TimerCounter);
}

TEST(TimerCounter3, type) {
    ::testing::StaticAssertTypeEq<TimerCounter3::type, uint16_t>();
}

TEST(TimerCounter3, counter) {
    TEST_REG_WRITE(TimerCounter3::counter(0x378f));
    TEST_REG_READ_WRITE(TimerCounter3::counter());
}

TEST(TimerCounter3, clock) {
    TEST_REG_WRITE(TimerCounter3::clock(TimerCounter3::Clock::None));
    TEST_REG_WRITE(TimerCounter3::clock(TimerCounter3::Clock::Div1));
    TEST_REG_WRITE(TimerCounter3::clock(TimerCounter3::Clock::Div8));
    TEST_REG_WRITE(TimerCounter3::clock(TimerCounter3::Clock::Div64));
    TEST_REG_WRITE(TimerCounter3::clock(TimerCounter3::Clock::Div256));
    TEST_REG_WRITE(TimerCounter3::clock(TimerCounter3::Clock::Div1024));
    TEST_REG_WRITE(TimerCounter3::clock(TimerCounter3::Clock::ExtFalling));
    TEST_REG_WRITE(TimerCounter3::clock(TimerCounter3::Clock::ExtRising));
}

TEST(TimerCounter3, waveform) {
    TEST_REG_WRITE(TimerCounter3::waveform(TimerCounter3::Waveform::Normal));
    TEST_REG_WRITE(TimerCounter3::waveform(TimerCounter3::Waveform::PWM));
    TEST_REG_WRITE(TimerCounter3::waveform(TimerCounter3::Waveform::CTCOCRA));
    TEST_REG_WRITE(TimerCounter3::waveform(TimerCounter3::Waveform::FastPWM));
    TEST_REG_WRITE(TimerCounter3::waveform(TimerCounter3::Waveform::PWMOCRA));
    TEST_REG_WRITE(TimerCounter3::waveform(TimerCounter3::Waveform::FastPWMOCRA));
}

TEST(TimerCounter3, overflowCallback) {
    TEST_REG_WRITE(TimerCounter3::overflowCallback(func,data));
}

TEST(TimerCounter3, overflowIntEnable) {
    TEST_REG_WRITE(TimerCounter3::overflowIntEnable(true));
    TEST_REG_WRITE(TimerCounter3::overflowIntEnable(false));
}

TEST(TimerCounter3, overflowIntFlag) {
    TEST_REG_READ_WRITE(TimerCounter3::overflowIntFlag());
}

TEST(TimerCounter3, overflowIntFlagClear) {
    TEST_REG_WRITE(TimerCounter3::overflowIntFlagClear());
}

TEST(TimerCounter3, outputA) {
    TEST_REG_WRITE(TimerCounter3::OutputCompareA::value(0x65d2));
    TEST_REG_READ_WRITE(TimerCounter3::OutputCompareA::value());
}

TEST(TimerCounter3, outputB) {
    TEST_REG_WRITE(TimerCounter3::OutputCompareB::value(0x78ee));
    TEST_REG_READ_WRITE(TimerCounter3::OutputCompareB::value());
}

TEST(TimerCounter3, outputC) {
    TEST_REG_WRITE(TimerCounter3::OutputCompareC::value(0x178f));
    TEST_REG_READ_WRITE(TimerCounter3::OutputCompareC::value());
}

TEST(TimerCounter3, outputAMode) {
    TEST_REG_WRITE(TimerCounter3::OutputCompareA::mode(TimerCounter3::OutputMode::Disconnected));
    TEST_REG_WRITE(TimerCounter3::OutputCompareA::mode(TimerCounter3::OutputMode::Toggle));
    TEST_REG_WRITE(TimerCounter3::OutputCompareA::mode(TimerCounter3::OutputMode::Clear));
    TEST_REG_WRITE(TimerCounter3::OutputCompareA::mode(TimerCounter3::OutputMode::Set));
}

TEST(TimerCounter3, outputBMode) {
    TEST_REG_WRITE(TimerCounter3::OutputCompareB::mode(TimerCounter3::OutputMode::Disconnected));
    TEST_REG_WRITE(TimerCounter3::OutputCompareB::mode(TimerCounter3::OutputMode::Toggle));
    TEST_REG_WRITE(TimerCounter3::OutputCompareB::mode(TimerCounter3::OutputMode::Clear));
    TEST_REG_WRITE(TimerCounter3::OutputCompareB::mode(TimerCounter3::OutputMode::Set));
}

TEST(TimerCounter3, outputCMode) {
    TEST_REG_WRITE(TimerCounter3::OutputCompareC::mode(TimerCounter3::OutputMode::Disconnected));
    TEST_REG_WRITE(TimerCounter3::OutputCompareC::mode(TimerCounter3::OutputMode::Toggle));
    TEST_REG_WRITE(TimerCounter3::OutputCompareC::mode(TimerCounter3::OutputMode::Clear));
    TEST_REG_WRITE(TimerCounter3::OutputCompareC::mode(TimerCounter3::OutputMode::Set));
}

TEST(TimerCounter3, outputACallback) {
    TEST_REG_WRITE(TimerCounter3::OutputCompareA::callback(func,data));
}

TEST(TimerCounter3, outputBCallback) {
    TEST_REG_WRITE(TimerCounter3::OutputCompareB::callback(func,data));
}

TEST(TimerCounter3, outputCCallback) {
    TEST_REG_WRITE(TimerCounter3::OutputCompareC::callback(func,data));
}

TEST(TimerCounter3, outputAIntEnable) {
    TEST_REG_WRITE(TimerCounter3::OutputCompareA::intEnable(true));
    TEST_REG_WRITE(TimerCounter3::OutputCompareA::intEnable(false));
}

TEST(TimerCounter3, outputBIntEnable) {
    TEST_REG_WRITE(TimerCounter3::OutputCompareB::intEnable(true));
    TEST_REG_WRITE(TimerCounter3::OutputCompareB::intEnable(false));
}

TEST(TimerCounter3, outputCIntEnable) {
    TEST_REG_WRITE(TimerCounter3::OutputCompareC::intEnable(true));
    TEST_REG_WRITE(TimerCounter3::OutputCompareC::intEnable(false));
}

TEST(TimerCounter3, outputAIntFlag) {
    TEST_REG_READ_WRITE(TimerCounter3::OutputCompareA::intFlag());
}

TEST(TimerCounter3, outputBIntFlag) {
    TEST_REG_READ_WRITE(TimerCounter3::OutputCompareB::intFlag());
}

TEST(TimerCounter3, outputCIntFlag) {
    TEST_REG_READ_WRITE(TimerCounter3::OutputCompareC::intFlag());
}

TEST(TimerCounter3, outputAIntFlagClear) {
    TEST_REG_WRITE(TimerCounter3::OutputCompareA::intFlagClear());
}

TEST(TimerCounter3, outputBIntFlagClear) {
    TEST_REG_WRITE(TimerCounter3::OutputCompareB::intFlagClear());
}

TEST(TimerCounter3, outputCIntFlagClear) {
    TEST_REG_WRITE(TimerCounter3::OutputCompareC::intFlagClear());
}


TEST(TimerCounter4, getHardwareType) {
    ASSERT_EQ(TimerCounter4::getHardwareType(), HardwareType::TimerCounter);
}

TEST(TimerCounter4, type) {
    ::testing::StaticAssertTypeEq<TimerCounter4::type, uint16_t>();
}

TEST(TimerCounter4, counter) {
    TEST_REG_WRITE(TimerCounter4::counter(0x78ac));
    TEST_REG_READ_WRITE(TimerCounter4::counter());
}

TEST(TimerCounter4, clock) {
    TEST_REG_WRITE(TimerCounter4::clock(TimerCounter4::Clock::None));
    TEST_REG_WRITE(TimerCounter4::clock(TimerCounter4::Clock::Div1));
    TEST_REG_WRITE(TimerCounter4::clock(TimerCounter4::Clock::Div8));
    TEST_REG_WRITE(TimerCounter4::clock(TimerCounter4::Clock::Div64));
    TEST_REG_WRITE(TimerCounter4::clock(TimerCounter4::Clock::Div256));
    TEST_REG_WRITE(TimerCounter4::clock(TimerCounter4::Clock::Div1024));
    TEST_REG_WRITE(TimerCounter4::clock(TimerCounter4::Clock::ExtFalling));
    TEST_REG_WRITE(TimerCounter4::clock(TimerCounter4::Clock::ExtRising));
}

TEST(TimerCounter4, waveform) {
    TEST_REG_WRITE(TimerCounter4::waveform(TimerCounter4::Waveform::Normal));
    TEST_REG_WRITE(TimerCounter4::waveform(TimerCounter4::Waveform::PWM));
    TEST_REG_WRITE(TimerCounter4::waveform(TimerCounter4::Waveform::CTCOCRA));
    TEST_REG_WRITE(TimerCounter4::waveform(TimerCounter4::Waveform::FastPWM));
    TEST_REG_WRITE(TimerCounter4::waveform(TimerCounter4::Waveform::PWMOCRA));
    TEST_REG_WRITE(TimerCounter4::waveform(TimerCounter4::Waveform::FastPWMOCRA));
}

TEST(TimerCounter4, overflowCallback) {
    TEST_REG_WRITE(TimerCounter4::overflowCallback(func,data));
}

TEST(TimerCounter4, overflowIntEnable) {
    TEST_REG_WRITE(TimerCounter4::overflowIntEnable(true));
    TEST_REG_WRITE(TimerCounter4::overflowIntEnable(false));
}

TEST(TimerCounter4, overflowIntFlag) {
    TEST_REG_READ_WRITE(TimerCounter4::overflowIntFlag());
}

TEST(TimerCounter4, overflowIntFlagClear) {
    TEST_REG_WRITE(TimerCounter4::overflowIntFlagClear());
}

TEST(TimerCounter4, outputA) {
    TEST_REG_WRITE(TimerCounter4::OutputCompareA::value(0x91ff));
    TEST_REG_READ_WRITE(TimerCounter4::OutputCompareA::value());
}

TEST(TimerCounter4, outputB) {
    TEST_REG_WRITE(TimerCounter4::OutputCompareB::value(0xaa72));
    TEST_REG_READ_WRITE(TimerCounter4::OutputCompareB::value());
}

TEST(TimerCounter4, outputC) {
    TEST_REG_WRITE(TimerCounter4::OutputCompareC::value(0xf7f8));
    TEST_REG_READ_WRITE(TimerCounter4::OutputCompareC::value());
}

TEST(TimerCounter4, outputAMode) {
    TEST_REG_WRITE(TimerCounter4::OutputCompareA::mode(TimerCounter4::OutputMode::Disconnected));
    TEST_REG_WRITE(TimerCounter4::OutputCompareA::mode(TimerCounter4::OutputMode::Toggle));
    TEST_REG_WRITE(TimerCounter4::OutputCompareA::mode(TimerCounter4::OutputMode::Clear));
    TEST_REG_WRITE(TimerCounter4::OutputCompareA::mode(TimerCounter4::OutputMode::Set));
}

TEST(TimerCounter4, outputBMode) {
    TEST_REG_WRITE(TimerCounter4::OutputCompareB::mode(TimerCounter4::OutputMode::Disconnected));
    TEST_REG_WRITE(TimerCounter4::OutputCompareB::mode(TimerCounter4::OutputMode::Toggle));
    TEST_REG_WRITE(TimerCounter4::OutputCompareB::mode(TimerCounter4::OutputMode::Clear));
    TEST_REG_WRITE(TimerCounter4::OutputCompareB::mode(TimerCounter4::OutputMode::Set));
}

TEST(TimerCounter4, outputCMode) {
    TEST_REG_WRITE(TimerCounter4::OutputCompareC::mode(TimerCounter4::OutputMode::Disconnected));
    TEST_REG_WRITE(TimerCounter4::OutputCompareC::mode(TimerCounter4::OutputMode::Toggle));
    TEST_REG_WRITE(TimerCounter4::OutputCompareC::mode(TimerCounter4::OutputMode::Clear));
    TEST_REG_WRITE(TimerCounter4::OutputCompareC::mode(TimerCounter4::OutputMode::Set));
}

TEST(TimerCounter4, outputACallback) {
    TEST_REG_WRITE(TimerCounter4::OutputCompareA::callback(func,data));
}

TEST(TimerCounter4, outputBCallback) {
    TEST_REG_WRITE(TimerCounter4::OutputCompareB::callback(func,data));
}

TEST(TimerCounter4, outputCCallback) {
    TEST_REG_WRITE(TimerCounter4::OutputCompareC::callback(func,data));
}

TEST(TimerCounter4, outputAIntEnable) {
    TEST_REG_WRITE(TimerCounter4::OutputCompareA::intEnable(true));
    TEST_REG_WRITE(TimerCounter4::OutputCompareA::intEnable(false));
}

TEST(TimerCounter4, outputBIntEnable) {
    TEST_REG_WRITE(TimerCounter4::OutputCompareB::intEnable(true));
    TEST_REG_WRITE(TimerCounter4::OutputCompareB::intEnable(false));
}

TEST(TimerCounter4, outputCIntEnable) {
    TEST_REG_WRITE(TimerCounter4::OutputCompareC::intEnable(true));
    TEST_REG_WRITE(TimerCounter4::OutputCompareC::intEnable(false));
}

TEST(TimerCounter4, outputAIntFlag) {
    TEST_REG_READ_WRITE(TimerCounter4::OutputCompareA::intFlag());
}

TEST(TimerCounter4, outputBIntFlag) {
    TEST_REG_READ_WRITE(TimerCounter4::OutputCompareB::intFlag());
}

TEST(TimerCounter4, outputCIntFlag) {
    TEST_REG_READ_WRITE(TimerCounter4::OutputCompareC::intFlag());
}

TEST(TimerCounter4, outputAIntFlagClear) {
    TEST_REG_WRITE(TimerCounter4::OutputCompareA::intFlagClear());
}

TEST(TimerCounter4, outputBIntFlagClear) {
    TEST_REG_WRITE(TimerCounter4::OutputCompareB::intFlagClear());
}

TEST(TimerCounter4, outputCIntFlagClear) {
    TEST_REG_WRITE(TimerCounter4::OutputCompareC::intFlagClear());
}


TEST(TimerCounter5, getHardwareType) {
    ASSERT_EQ(TimerCounter5::getHardwareType(), HardwareType::TimerCounter);
}

TEST(TimerCounter5, type) {
    ::testing::StaticAssertTypeEq<TimerCounter5::type, uint16_t>();
}

TEST(TimerCounter5, counter) {
    TEST_REG_WRITE(TimerCounter5::counter(0x028d));
    TEST_REG_READ_WRITE(TimerCounter5::counter());
}

TEST(TimerCounter5, clock) {
    TEST_REG_WRITE(TimerCounter5::clock(TimerCounter5::Clock::None));
    TEST_REG_WRITE(TimerCounter5::clock(TimerCounter5::Clock::Div1));
    TEST_REG_WRITE(TimerCounter5::clock(TimerCounter5::Clock::Div8));
    TEST_REG_WRITE(TimerCounter5::clock(TimerCounter5::Clock::Div64));
    TEST_REG_WRITE(TimerCounter5::clock(TimerCounter5::Clock::Div256));
    TEST_REG_WRITE(TimerCounter5::clock(TimerCounter5::Clock::Div1024));
    TEST_REG_WRITE(TimerCounter5::clock(TimerCounter5::Clock::ExtFalling));
    TEST_REG_WRITE(TimerCounter5::clock(TimerCounter5::Clock::ExtRising));
}

TEST(TimerCounter5, waveform) {
    TEST_REG_WRITE(TimerCounter5::waveform(TimerCounter5::Waveform::Normal));
    TEST_REG_WRITE(TimerCounter5::waveform(TimerCounter5::Waveform::PWM));
    TEST_REG_WRITE(TimerCounter5::waveform(TimerCounter5::Waveform::CTCOCRA));
    TEST_REG_WRITE(TimerCounter5::waveform(TimerCounter5::Waveform::FastPWM));
    TEST_REG_WRITE(TimerCounter5::waveform(TimerCounter5::Waveform::PWMOCRA));
    TEST_REG_WRITE(TimerCounter5::waveform(TimerCounter5::Waveform::FastPWMOCRA));
}

TEST(TimerCounter5, overflowCallback) {
    TEST_REG_WRITE(TimerCounter5::overflowCallback(func,data));
}

TEST(TimerCounter5, overflowIntEnable) {
    TEST_REG_WRITE(TimerCounter5::overflowIntEnable(true));
    TEST_REG_WRITE(TimerCounter5::overflowIntEnable(false));
}

TEST(TimerCounter5, overflowIntFlag) {
    TEST_REG_READ_WRITE(TimerCounter5::overflowIntFlag());
}

TEST(TimerCounter5, overflowIntFlagClear) {
    TEST_REG_WRITE(TimerCounter5::overflowIntFlagClear());
}

TEST(TimerCounter5, outputA) {
    TEST_REG_WRITE(TimerCounter5::OutputCompareA::value(0x102f));
    TEST_REG_READ_WRITE(TimerCounter5::OutputCompareA::value());
}

TEST(TimerCounter5, outputB) {
    TEST_REG_WRITE(TimerCounter5::OutputCompareB::value(0xff12));
    TEST_REG_READ_WRITE(TimerCounter5::OutputCompareB::value());
}

TEST(TimerCounter5, outputC) {
    TEST_REG_WRITE(TimerCounter5::OutputCompareC::value(0x2267));
    TEST_REG_READ_WRITE(TimerCounter5::OutputCompareC::value());
}

TEST(TimerCounter5, outputAMode) {
    TEST_REG_WRITE(TimerCounter5::OutputCompareA::mode(TimerCounter5::OutputMode::Disconnected));
    TEST_REG_WRITE(TimerCounter5::OutputCompareA::mode(TimerCounter5::OutputMode::Toggle));
    TEST_REG_WRITE(TimerCounter5::OutputCompareA::mode(TimerCounter5::OutputMode::Clear));
    TEST_REG_WRITE(TimerCounter5::OutputCompareA::mode(TimerCounter5::OutputMode::Set));
}

TEST(TimerCounter5, outputBMode) {
    TEST_REG_WRITE(TimerCounter5::OutputCompareB::mode(TimerCounter5::OutputMode::Disconnected));
    TEST_REG_WRITE(TimerCounter5::OutputCompareB::mode(TimerCounter5::OutputMode::Toggle));
    TEST_REG_WRITE(TimerCounter5::OutputCompareB::mode(TimerCounter5::OutputMode::Clear));
    TEST_REG_WRITE(TimerCounter5::OutputCompareB::mode(TimerCounter5::OutputMode::Set));
}

TEST(TimerCounter5, outputCMode) {
    TEST_REG_WRITE(TimerCounter5::OutputCompareC::mode(TimerCounter5::OutputMode::Disconnected));
    TEST_REG_WRITE(TimerCounter5::OutputCompareC::mode(TimerCounter5::OutputMode::Toggle));
    TEST_REG_WRITE(TimerCounter5::OutputCompareC::mode(TimerCounter5::OutputMode::Clear));
    TEST_REG_WRITE(TimerCounter5::OutputCompareC::mode(TimerCounter5::OutputMode::Set));
}

TEST(TimerCounter5, outputACallback) {
    TEST_REG_WRITE(TimerCounter5::OutputCompareA::callback(func,data));
}

TEST(TimerCounter5, outputBCallback) {
    TEST_REG_WRITE(TimerCounter5::OutputCompareB::callback(func,data));
}

TEST(TimerCounter5, outputCCallback) {
    TEST_REG_WRITE(TimerCounter5::OutputCompareC::callback(func,data));
}

TEST(TimerCounter5, outputAIntEnable) {
    TEST_REG_WRITE(TimerCounter5::OutputCompareA::intEnable(true));
    TEST_REG_WRITE(TimerCounter5::OutputCompareA::intEnable(false));
}

TEST(TimerCounter5, outputBIntEnable) {
    TEST_REG_WRITE(TimerCounter5::OutputCompareB::intEnable(true));
    TEST_REG_WRITE(TimerCounter5::OutputCompareB::intEnable(false));
}

TEST(TimerCounter5, outputCIntEnable) {
    TEST_REG_WRITE(TimerCounter5::OutputCompareC::intEnable(true));
    TEST_REG_WRITE(TimerCounter5::OutputCompareC::intEnable(false));
}

TEST(TimerCounter5, outputAIntFlag) {
    TEST_REG_READ_WRITE(TimerCounter5::OutputCompareA::intFlag());
}

TEST(TimerCounter5, outputBIntFlag) {
    TEST_REG_READ_WRITE(TimerCounter5::OutputCompareB::intFlag());
}

TEST(TimerCounter5, outputCIntFlag) {
    TEST_REG_READ_WRITE(TimerCounter5::OutputCompareC::intFlag());
}

TEST(TimerCounter5, outputAIntFlagClear) {
    TEST_REG_WRITE(TimerCounter5::OutputCompareA::intFlagClear());
}

TEST(TimerCounter5, outputBIntFlagClear) {
    TEST_REG_WRITE(TimerCounter5::OutputCompareB::intFlagClear());
}

TEST(TimerCounter5, outputCIntFlagClear) {
    TEST_REG_WRITE(TimerCounter5::OutputCompareC::intFlagClear());
}

//------------------------------------------------
// Usart

INCLUDE_USART_CALLBACK(0, RX);
INCLUDE_USART_CALLBACK(0, TX);
INCLUDE_USART_CALLBACK(0, DE);
INCLUDE_USART_CALLBACK(1, RX);
INCLUDE_USART_CALLBACK(1, TX);
INCLUDE_USART_CALLBACK(1, DE);
INCLUDE_USART_CALLBACK(2, RX);
INCLUDE_USART_CALLBACK(2, TX);
INCLUDE_USART_CALLBACK(2, DE);
INCLUDE_USART_CALLBACK(3, RX);
INCLUDE_USART_CALLBACK(3, TX);
INCLUDE_USART_CALLBACK(3, DE);

TEST(Usart0, getHardwareType) {
    ASSERT_EQ(Usart0::getHardwareType(), HardwareType::Usart);
}

TEST(Usart0, mode) {
    TEST_REG_WRITE(Usart0::mode(Usart0::Mode::Asynchronous));
    TEST_REG_WRITE(Usart0::mode(Usart0::Mode::Synchronous));
    TEST_REG_WRITE(Usart0::mode(Usart0::Mode::MasterSpi));
}

TEST(Usart0, parity) {
    TEST_REG_WRITE(Usart0::parity(Usart0::Parity::Disabled));
    TEST_REG_WRITE(Usart0::parity(Usart0::Parity::Even));
    TEST_REG_WRITE(Usart0::parity(Usart0::Parity::Odd));
}

TEST(Usart0, stopBits) {
    TEST_REG_WRITE(Usart0::stopBits(Usart0::StopBits::Bits1));
    TEST_REG_WRITE(Usart0::stopBits(Usart0::StopBits::Bits2));
}

TEST(Usart0, characterSize) {
    TEST_REG_WRITE(Usart0::characterSize(Usart0::CharacterSize::Size5));
    TEST_REG_WRITE(Usart0::characterSize(Usart0::CharacterSize::Size6));
    TEST_REG_WRITE(Usart0::characterSize(Usart0::CharacterSize::Size7));
    TEST_REG_WRITE(Usart0::characterSize(Usart0::CharacterSize::Size8));
    TEST_REG_WRITE(Usart0::characterSize(Usart0::CharacterSize::Size9));
}

TEST(Usart0, polarity) {
    TEST_REG_WRITE(Usart0::polarity(Usart0::Polarity::TxRisingRxFalling));
    TEST_REG_WRITE(Usart0::polarity(Usart0::Polarity::TxFallingRxRising));
}

TEST(Usart0, baud) {
    TEST_REG_WRITE(Usart0::baud(0xe819));
}

TEST(Usart0, use2X) {
    TEST_REG_WRITE(Usart0::use2X(true));
    TEST_REG_WRITE(Usart0::use2X(false));
}

TEST(Usart0, receiverEnable) {
    TEST_REG_WRITE(Usart0::receiverEnable(true));
    TEST_REG_WRITE(Usart0::receiverEnable(false));
}

TEST(Usart0, transmitterEnable) {
    TEST_REG_WRITE(Usart0::transmitterEnable(true));
    TEST_REG_WRITE(Usart0::transmitterEnable(false));
}

TEST(Usart0, multiprocessorCummunicationMode) {
    TEST_REG_WRITE(Usart0::multiprocessorCummunicationMode(true));
    TEST_REG_WRITE(Usart0::multiprocessorCummunicationMode(false));
}

TEST(Usart0, rxCompleteIntEnable) {
    TEST_REG_WRITE(Usart0::rxCompleteIntEnable(true));
    TEST_REG_WRITE(Usart0::rxCompleteIntEnable(false));
}

TEST(Usart0, txCompleteIntEnable) {
    TEST_REG_WRITE(Usart0::txCompleteIntEnable(true));
    TEST_REG_WRITE(Usart0::txCompleteIntEnable(false));
}

TEST(Usart0, dataRegisterEmptyIntEnable) {
    TEST_REG_WRITE(Usart0::dataRegisterEmptyIntEnable(true));
    TEST_REG_WRITE(Usart0::dataRegisterEmptyIntEnable(false));
}

TEST(Usart0, rxCompleteCallback) {
    TEST_REG_WRITE(Usart0::rxCompleteCallback(func,data));
}

TEST(Usart0, txCompleteCallback) {
    TEST_REG_WRITE(Usart0::txCompleteCallback(func,data));
}

TEST(Usart0, dataRegisterEmptyCallback) {
    TEST_REG_WRITE(Usart0::dataRegisterEmptyCallback(func,data));
}

TEST(Usart0, push) {
    TEST_REG_WRITE(Usart0::push(0x18));
}

TEST(Usart0, push9) {
    TEST_REG_WRITE(Usart0::push9(0x3261));
}

TEST(Usart0, pop) {
    TEST_REG_READ_WRITE(Usart0::pop());
}

TEST(Usart0, pop9) {
    TEST_REG_READ_WRITE(Usart0::pop9());
}

TEST(Usart0, frameError) {
    TEST_REG_READ_WRITE(Usart0::frameError());
}

TEST(Usart0, frameErrorClear) {
    TEST_REG_WRITE(Usart0::frameErrorClear());
}

TEST(Usart0, dataOverRun) {
    TEST_REG_READ_WRITE(Usart0::dataOverRun());
}

TEST(Usart0, dataOverRunClear) {
    TEST_REG_WRITE(Usart0::dataOverRunClear());
}

TEST(Usart0, parityError) {
    TEST_REG_READ_WRITE(Usart0::parityError());
}

TEST(Usart0, parityErrorClear) {
    TEST_REG_WRITE(Usart0::parityErrorClear());
}

TEST(Usart1, getHardwareType) {
    ASSERT_EQ(Usart1::getHardwareType(), HardwareType::Usart);
}

TEST(Usart1, mode) {
    TEST_REG_WRITE(Usart1::mode(Usart1::Mode::Asynchronous));
    TEST_REG_WRITE(Usart1::mode(Usart1::Mode::Synchronous));
    TEST_REG_WRITE(Usart1::mode(Usart1::Mode::MasterSpi));
}

TEST(Usart1, parity) {
    TEST_REG_WRITE(Usart1::parity(Usart1::Parity::Disabled));
    TEST_REG_WRITE(Usart1::parity(Usart1::Parity::Even));
    TEST_REG_WRITE(Usart1::parity(Usart1::Parity::Odd));
}

TEST(Usart1, stopBits) {
    TEST_REG_WRITE(Usart1::stopBits(Usart1::StopBits::Bits1));
    TEST_REG_WRITE(Usart1::stopBits(Usart1::StopBits::Bits2));
}

TEST(Usart1, characterSize) {
    TEST_REG_WRITE(Usart1::characterSize(Usart1::CharacterSize::Size5));
    TEST_REG_WRITE(Usart1::characterSize(Usart1::CharacterSize::Size6));
    TEST_REG_WRITE(Usart1::characterSize(Usart1::CharacterSize::Size7));
    TEST_REG_WRITE(Usart1::characterSize(Usart1::CharacterSize::Size8));
    TEST_REG_WRITE(Usart1::characterSize(Usart1::CharacterSize::Size9));
}

TEST(Usart1, polarity) {
    TEST_REG_WRITE(Usart1::polarity(Usart1::Polarity::TxRisingRxFalling));
    TEST_REG_WRITE(Usart1::polarity(Usart1::Polarity::TxFallingRxRising));
}

TEST(Usart1, baud) {
    TEST_REG_WRITE(Usart1::baud(0x9920));
}

TEST(Usart1, use2X) {
    TEST_REG_WRITE(Usart1::use2X(true));
    TEST_REG_WRITE(Usart1::use2X(false));
}

TEST(Usart1, receiverEnable) {
    TEST_REG_WRITE(Usart1::receiverEnable(true));
    TEST_REG_WRITE(Usart1::receiverEnable(false));
}

TEST(Usart1, transmitterEnable) {
    TEST_REG_WRITE(Usart1::transmitterEnable(true));
    TEST_REG_WRITE(Usart1::transmitterEnable(false));
}

TEST(Usart1, multiprocessorCummunicationMode) {
    TEST_REG_WRITE(Usart1::multiprocessorCummunicationMode(true));
    TEST_REG_WRITE(Usart1::multiprocessorCummunicationMode(false));
}

TEST(Usart1, rxCompleteIntEnable) {
    TEST_REG_WRITE(Usart1::rxCompleteIntEnable(true));
    TEST_REG_WRITE(Usart1::rxCompleteIntEnable(false));
}

TEST(Usart1, txCompleteIntEnable) {
    TEST_REG_WRITE(Usart1::txCompleteIntEnable(true));
    TEST_REG_WRITE(Usart1::txCompleteIntEnable(false));
}

TEST(Usart1, dataRegisterEmptyIntEnable) {
    TEST_REG_WRITE(Usart1::dataRegisterEmptyIntEnable(true));
    TEST_REG_WRITE(Usart1::dataRegisterEmptyIntEnable(false));
}

TEST(Usart1, rxCompleteCallback) {
    TEST_REG_WRITE(Usart1::rxCompleteCallback(func,data));
}

TEST(Usart1, txCompleteCallback) {
    TEST_REG_WRITE(Usart1::txCompleteCallback(func,data));
}

TEST(Usart1, dataRegisterEmptyCallback) {
    TEST_REG_WRITE(Usart1::dataRegisterEmptyCallback(func,data));
}

TEST(Usart1, push) {
    TEST_REG_WRITE(Usart1::push(0x97));
}

TEST(Usart1, push9) {
    TEST_REG_WRITE(Usart1::push9(0xf871));
}

TEST(Usart1, pop) {
    TEST_REG_READ_WRITE(Usart1::pop());
}

TEST(Usart1, pop9) {
    TEST_REG_READ_WRITE(Usart1::pop9());
}

TEST(Usart1, frameError) {
    TEST_REG_READ_WRITE(Usart1::frameError());
}

TEST(Usart1, frameErrorClear) {
    TEST_REG_WRITE(Usart1::frameErrorClear());
}

TEST(Usart1, dataOverRun) {
    TEST_REG_READ_WRITE(Usart1::dataOverRun());
}

TEST(Usart1, dataOverRunClear) {
    TEST_REG_WRITE(Usart1::dataOverRunClear());
}

TEST(Usart1, parityError) {
    TEST_REG_READ_WRITE(Usart1::parityError());
}

TEST(Usart1, parityErrorClear) {
    TEST_REG_WRITE(Usart1::parityErrorClear());
}

TEST(Usart2, getHardwareType) {
    ASSERT_EQ(Usart2::getHardwareType(), HardwareType::Usart);
}

TEST(Usart2, mode) {
    TEST_REG_WRITE(Usart2::mode(Usart2::Mode::Asynchronous));
    TEST_REG_WRITE(Usart2::mode(Usart2::Mode::Synchronous));
    TEST_REG_WRITE(Usart2::mode(Usart2::Mode::MasterSpi));
}

TEST(Usart2, parity) {
    TEST_REG_WRITE(Usart2::parity(Usart2::Parity::Disabled));
    TEST_REG_WRITE(Usart2::parity(Usart2::Parity::Even));
    TEST_REG_WRITE(Usart2::parity(Usart2::Parity::Odd));
}

TEST(Usart2, stopBits) {
    TEST_REG_WRITE(Usart2::stopBits(Usart2::StopBits::Bits1));
    TEST_REG_WRITE(Usart2::stopBits(Usart2::StopBits::Bits2));
}

TEST(Usart2, characterSize) {
    TEST_REG_WRITE(Usart2::characterSize(Usart2::CharacterSize::Size5));
    TEST_REG_WRITE(Usart2::characterSize(Usart2::CharacterSize::Size6));
    TEST_REG_WRITE(Usart2::characterSize(Usart2::CharacterSize::Size7));
    TEST_REG_WRITE(Usart2::characterSize(Usart2::CharacterSize::Size8));
    TEST_REG_WRITE(Usart2::characterSize(Usart2::CharacterSize::Size9));
}

TEST(Usart2, polarity) {
    TEST_REG_WRITE(Usart2::polarity(Usart2::Polarity::TxRisingRxFalling));
    TEST_REG_WRITE(Usart2::polarity(Usart2::Polarity::TxFallingRxRising));
}

TEST(Usart2, baud) {
    TEST_REG_WRITE(Usart2::baud(0xee87));
}

TEST(Usart2, use2X) {
    TEST_REG_WRITE(Usart2::use2X(true));
    TEST_REG_WRITE(Usart2::use2X(false));
}

TEST(Usart2, receiverEnable) {
    TEST_REG_WRITE(Usart2::receiverEnable(true));
    TEST_REG_WRITE(Usart2::receiverEnable(false));
}

TEST(Usart2, transmitterEnable) {
    TEST_REG_WRITE(Usart2::transmitterEnable(true));
    TEST_REG_WRITE(Usart2::transmitterEnable(false));
}

TEST(Usart2, multiprocessorCummunicationMode) {
    TEST_REG_WRITE(Usart2::multiprocessorCummunicationMode(true));
    TEST_REG_WRITE(Usart2::multiprocessorCummunicationMode(false));
}

TEST(Usart2, rxCompleteIntEnable) {
    TEST_REG_WRITE(Usart2::rxCompleteIntEnable(true));
    TEST_REG_WRITE(Usart2::rxCompleteIntEnable(false));
}

TEST(Usart2, txCompleteIntEnable) {
    TEST_REG_WRITE(Usart2::txCompleteIntEnable(true));
    TEST_REG_WRITE(Usart2::txCompleteIntEnable(false));
}

TEST(Usart2, dataRegisterEmptyIntEnable) {
    TEST_REG_WRITE(Usart2::dataRegisterEmptyIntEnable(true));
    TEST_REG_WRITE(Usart2::dataRegisterEmptyIntEnable(false));
}

TEST(Usart2, rxCompleteCallback) {
    TEST_REG_WRITE(Usart2::rxCompleteCallback(func,data));
}

TEST(Usart2, txCompleteCallback) {
    TEST_REG_WRITE(Usart2::txCompleteCallback(func,data));
}

TEST(Usart2, dataRegisterEmptyCallback) {
    TEST_REG_WRITE(Usart2::dataRegisterEmptyCallback(func,data));
}

TEST(Usart2, push) {
    TEST_REG_WRITE(Usart2::push(0x38));
}

TEST(Usart2, push9) {
    TEST_REG_WRITE(Usart2::push9(0x3939));
}

TEST(Usart2, pop) {
    TEST_REG_READ_WRITE(Usart2::pop());
}

TEST(Usart2, pop9) {
    TEST_REG_READ_WRITE(Usart2::pop9());
}

TEST(Usart2, frameError) {
    TEST_REG_READ_WRITE(Usart2::frameError());
}

TEST(Usart2, frameErrorClear) {
    TEST_REG_WRITE(Usart2::frameErrorClear());
}

TEST(Usart2, dataOverRun) {
    TEST_REG_READ_WRITE(Usart2::dataOverRun());
}

TEST(Usart2, dataOverRunClear) {
    TEST_REG_WRITE(Usart2::dataOverRunClear());
}

TEST(Usart2, parityError) {
    TEST_REG_READ_WRITE(Usart2::parityError());
}

TEST(Usart2, parityErrorClear) {
    TEST_REG_WRITE(Usart2::parityErrorClear());
}

TEST(Usart3, getHardwareType) {
    ASSERT_EQ(Usart3::getHardwareType(), HardwareType::Usart);
}

TEST(Usart3, mode) {
    TEST_REG_WRITE(Usart3::mode(Usart3::Mode::Asynchronous));
    TEST_REG_WRITE(Usart3::mode(Usart3::Mode::Synchronous));
    TEST_REG_WRITE(Usart3::mode(Usart3::Mode::MasterSpi));
}

TEST(Usart3, parity) {
    TEST_REG_WRITE(Usart3::parity(Usart3::Parity::Disabled));
    TEST_REG_WRITE(Usart3::parity(Usart3::Parity::Even));
    TEST_REG_WRITE(Usart3::parity(Usart3::Parity::Odd));
}

TEST(Usart3, stopBits) {
    TEST_REG_WRITE(Usart3::stopBits(Usart3::StopBits::Bits1));
    TEST_REG_WRITE(Usart3::stopBits(Usart3::StopBits::Bits2));
}

TEST(Usart3, characterSize) {
    TEST_REG_WRITE(Usart3::characterSize(Usart3::CharacterSize::Size5));
    TEST_REG_WRITE(Usart3::characterSize(Usart3::CharacterSize::Size6));
    TEST_REG_WRITE(Usart3::characterSize(Usart3::CharacterSize::Size7));
    TEST_REG_WRITE(Usart3::characterSize(Usart3::CharacterSize::Size8));
    TEST_REG_WRITE(Usart3::characterSize(Usart3::CharacterSize::Size9));
}

TEST(Usart3, polarity) {
    TEST_REG_WRITE(Usart3::polarity(Usart3::Polarity::TxRisingRxFalling));
    TEST_REG_WRITE(Usart3::polarity(Usart3::Polarity::TxFallingRxRising));
}

TEST(Usart3, baud) {
    TEST_REG_WRITE(Usart3::baud(0x99ff));
}

TEST(Usart3, use2X) {
    TEST_REG_WRITE(Usart3::use2X(true));
    TEST_REG_WRITE(Usart3::use2X(false));
}

TEST(Usart3, receiverEnable) {
    TEST_REG_WRITE(Usart3::receiverEnable(true));
    TEST_REG_WRITE(Usart3::receiverEnable(false));
}

TEST(Usart3, transmitterEnable) {
    TEST_REG_WRITE(Usart3::transmitterEnable(true));
    TEST_REG_WRITE(Usart3::transmitterEnable(false));
}

TEST(Usart3, multiprocessorCummunicationMode) {
    TEST_REG_WRITE(Usart3::multiprocessorCummunicationMode(true));
    TEST_REG_WRITE(Usart3::multiprocessorCummunicationMode(false));
}

TEST(Usart3, rxCompleteIntEnable) {
    TEST_REG_WRITE(Usart3::rxCompleteIntEnable(true));
    TEST_REG_WRITE(Usart3::rxCompleteIntEnable(false));
}

TEST(Usart3, txCompleteIntEnable) {
    TEST_REG_WRITE(Usart3::txCompleteIntEnable(true));
    TEST_REG_WRITE(Usart3::txCompleteIntEnable(false));
}

TEST(Usart3, dataRegisterEmptyIntEnable) {
    TEST_REG_WRITE(Usart3::dataRegisterEmptyIntEnable(true));
    TEST_REG_WRITE(Usart3::dataRegisterEmptyIntEnable(false));
}

TEST(Usart3, rxCompleteCallback) {
    TEST_REG_WRITE(Usart3::rxCompleteCallback(func,data));
}

TEST(Usart3, txCompleteCallback) {
    TEST_REG_WRITE(Usart3::txCompleteCallback(func,data));
}

TEST(Usart3, dataRegisterEmptyCallback) {
    TEST_REG_WRITE(Usart3::dataRegisterEmptyCallback(func,data));
}

TEST(Usart3, push) {
    TEST_REG_WRITE(Usart3::push(0x33));
}

TEST(Usart3, push9) {
    TEST_REG_WRITE(Usart3::push9(0xf981));
}

TEST(Usart3, pop) {
    TEST_REG_READ_WRITE(Usart3::pop());
}

TEST(Usart3, pop9) {
    TEST_REG_READ_WRITE(Usart3::pop9());
}

TEST(Usart3, frameError) {
    TEST_REG_READ_WRITE(Usart3::frameError());
}

TEST(Usart3, frameErrorClear) {
    TEST_REG_WRITE(Usart3::frameErrorClear());
}

TEST(Usart3, dataOverRun) {
    TEST_REG_READ_WRITE(Usart3::dataOverRun());
}

TEST(Usart3, dataOverRunClear) {
    TEST_REG_WRITE(Usart3::dataOverRunClear());
}

TEST(Usart3, parityError) {
    TEST_REG_READ_WRITE(Usart3::parityError());
}

TEST(Usart3, parityErrorClear) {
    TEST_REG_WRITE(Usart3::parityErrorClear());
}
