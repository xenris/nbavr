#define __atmega2560__

#define RECORD_ID "atmega2560"

#include "test.hpp"

typedef void (*ft)(void*);

static ft func = (ft)0x1234;
static void* data = (void*)0x5678;

//------------------------------------------------
// Analog to Digital

INCLUDE_ADC_CALLBACK(0);

TEST(Adc, getHardwareType) {
    ASSERT_EQ(Adc0::getHardwareType(), HardwareType::adc);
}

TEST(Adc, enable) {
    TEST_REG_WRITE(Adc0::enable(true));
    TEST_REG_WRITE(Adc0::enable(false));
}

TEST(Adc, start) {
    TEST_REG_WRITE(Adc0::start());
}

TEST(Adc, value) {
    TEST_REG_READ_WRITE(Adc0::value());
}

TEST(Adc, reference) {
    TEST_REG_WRITE(Adc0::reference(Adc0::Reference::AREF));
    TEST_REG_WRITE(Adc0::reference(Adc0::Reference::AVCC));
    TEST_REG_WRITE(Adc0::reference(Adc0::Reference::Internal));
}

TEST(Adc, channel) {
    TEST_REG_WRITE(Adc0::channel(Adc0::Channel::ADC0));
    TEST_REG_WRITE(Adc0::channel(Adc0::Channel::ADC1));
    TEST_REG_WRITE(Adc0::channel(Adc0::Channel::ADC2));
    TEST_REG_WRITE(Adc0::channel(Adc0::Channel::ADC3));
    TEST_REG_WRITE(Adc0::channel(Adc0::Channel::ADC4));
    TEST_REG_WRITE(Adc0::channel(Adc0::Channel::ADC5));
    TEST_REG_WRITE(Adc0::channel(Adc0::Channel::ADC6));
    TEST_REG_WRITE(Adc0::channel(Adc0::Channel::ADC7));
    // TEST_REG_WRITE(Adc0::channel(Adc0::Channel::ADC8));
    // TEST_REG_WRITE(Adc0::channel(Adc0::Channel::VBG));
    // TEST_REG_WRITE(Adc0::channel(Adc0::Channel::GND));
}

TEST(Adc, prescaler) {
    TEST_REG_WRITE(Adc0::prescaler(Adc0::Prescaler::Div2));
    TEST_REG_WRITE(Adc0::prescaler(Adc0::Prescaler::Div4));
    TEST_REG_WRITE(Adc0::prescaler(Adc0::Prescaler::Div8));
    TEST_REG_WRITE(Adc0::prescaler(Adc0::Prescaler::Div16));
    TEST_REG_WRITE(Adc0::prescaler(Adc0::Prescaler::Div32));
    TEST_REG_WRITE(Adc0::prescaler(Adc0::Prescaler::Div64));
    TEST_REG_WRITE(Adc0::prescaler(Adc0::Prescaler::Div128));
}

TEST(Adc, leftAdjust) {
    TEST_REG_WRITE(Adc0::leftAdjust(true));
    TEST_REG_WRITE(Adc0::leftAdjust(false));
}

TEST(Adc, trigger) {
    TEST_REG_WRITE(Adc0::trigger(Adc0::Trigger::SingleConversion));
    TEST_REG_WRITE(Adc0::trigger(Adc0::Trigger::FreeRunning));
    TEST_REG_WRITE(Adc0::trigger(Adc0::Trigger::AnalogComparator));
    TEST_REG_WRITE(Adc0::trigger(Adc0::Trigger::ExternalInt0));
    TEST_REG_WRITE(Adc0::trigger(Adc0::Trigger::Timer0CompareMatchA));
    TEST_REG_WRITE(Adc0::trigger(Adc0::Trigger::Timer0Overflow));
    TEST_REG_WRITE(Adc0::trigger(Adc0::Trigger::Timer1CompareMatchB));
    TEST_REG_WRITE(Adc0::trigger(Adc0::Trigger::Timer1Overflow));
    TEST_REG_WRITE(Adc0::trigger(Adc0::Trigger::Timer1CaptureEvent));
}

TEST(Adc, callback) {
    TEST_REG_WRITE(Adc0::callback(func,data));
}

TEST(Adc, intEnable) {
    TEST_REG_WRITE(Adc0::intEnable(false));
    TEST_REG_WRITE(Adc0::intEnable(true));
}

TEST(Adc, intFlag) {
    TEST_REG_READ_WRITE(Adc0::intFlag());
}

TEST(Adc, intFlagClear) {
    TEST_REG_WRITE(Adc0::intFlagClear());
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
    ASSERT_EQ(ExInt0::getHardwareType(), HardwareType::exInt);
    ASSERT_EQ(ExInt1::getHardwareType(), HardwareType::exInt);
    ASSERT_EQ(ExInt2::getHardwareType(), HardwareType::exInt);
    ASSERT_EQ(ExInt3::getHardwareType(), HardwareType::exInt);
    ASSERT_EQ(ExInt4::getHardwareType(), HardwareType::exInt);
    ASSERT_EQ(ExInt5::getHardwareType(), HardwareType::exInt);
    ASSERT_EQ(ExInt6::getHardwareType(), HardwareType::exInt);
    ASSERT_EQ(ExInt7::getHardwareType(), HardwareType::exInt);
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
    ASSERT_EQ(PcInt0::getHardwareType(), HardwareType::pcInt);
    ASSERT_EQ(PcInt1::getHardwareType(), HardwareType::pcInt);
    ASSERT_EQ(PcInt2::getHardwareType(), HardwareType::pcInt);
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

TEST(PortXPinN, getHardwareType) {
    ASSERT_EQ(PortA::Pin0::getHardwareType(), HardwareType::pin);
    ASSERT_EQ(PortA::Pin7::getHardwareType(), HardwareType::pin);
    ASSERT_EQ(PortB::Pin0::getHardwareType(), HardwareType::pin);
    ASSERT_EQ(PortB::Pin7::getHardwareType(), HardwareType::pin);
    ASSERT_EQ(PortC::Pin0::getHardwareType(), HardwareType::pin);
    ASSERT_EQ(PortC::Pin6::getHardwareType(), HardwareType::pin);
    ASSERT_EQ(PortD::Pin0::getHardwareType(), HardwareType::pin);
    ASSERT_EQ(PortD::Pin7::getHardwareType(), HardwareType::pin);
    ASSERT_EQ(PortE::Pin0::getHardwareType(), HardwareType::pin);
    ASSERT_EQ(PortE::Pin7::getHardwareType(), HardwareType::pin);
    ASSERT_EQ(PortF::Pin0::getHardwareType(), HardwareType::pin);
    ASSERT_EQ(PortF::Pin7::getHardwareType(), HardwareType::pin);
    ASSERT_EQ(PortG::Pin0::getHardwareType(), HardwareType::pin);
    ASSERT_EQ(PortG::Pin5::getHardwareType(), HardwareType::pin);
    ASSERT_EQ(PortH::Pin0::getHardwareType(), HardwareType::pin);
    ASSERT_EQ(PortH::Pin7::getHardwareType(), HardwareType::pin);
    ASSERT_EQ(PortJ::Pin0::getHardwareType(), HardwareType::pin);
    ASSERT_EQ(PortJ::Pin7::getHardwareType(), HardwareType::pin);
    ASSERT_EQ(PortK::Pin0::getHardwareType(), HardwareType::pin);
    ASSERT_EQ(PortK::Pin7::getHardwareType(), HardwareType::pin);
    ASSERT_EQ(PortL::Pin0::getHardwareType(), HardwareType::pin);
    ASSERT_EQ(PortL::Pin7::getHardwareType(), HardwareType::pin);
}

TEST(PortXPinN, mode) {
    TEST_REG_WRITE(PortB::Pin0::mode(Pin::Mode::input));
    TEST_REG_WRITE(PortB::Pin0::mode(Pin::Mode::output));
    TEST_REG_READ_WRITE(PortB::Pin0::mode());

    TEST_REG_WRITE(PortC::Pin6::mode(Pin::Mode::input));
    TEST_REG_WRITE(PortC::Pin6::mode(Pin::Mode::output));
    TEST_REG_READ_WRITE(PortC::Pin6::mode());

    TEST_REG_WRITE(PortD::Pin3::mode(Pin::Mode::input));
    TEST_REG_WRITE(PortD::Pin3::mode(Pin::Mode::output));
    TEST_REG_READ_WRITE(PortD::Pin3::mode());
}

TEST(PortXPinN, output) {
    TEST_REG_READ_WRITE(PortB::Pin2::output());

    TEST_REG_READ_WRITE(PortC::Pin4::output());

    TEST_REG_READ_WRITE(PortD::Pin4::output());
}

TEST(PortXPinN, input) {
    TEST_REG_READ_WRITE(PortB::Pin3::input());

    TEST_REG_READ_WRITE(PortC::Pin3::input());

    TEST_REG_READ_WRITE(PortD::Pin4::input());
}

TEST(PortXPinN, toggle) {
    TEST_REG_WRITE(PortB::Pin4::toggle());
    TEST_REG_WRITE(PortC::Pin2::toggle());
    TEST_REG_WRITE(PortD::Pin5::toggle());
}

//------------------------------------------------
// Digital Ports

TEST(PortX, getHardwareType) {
    ASSERT_EQ(PortA::getHardwareType(), HardwareType::port);
    ASSERT_EQ(PortB::getHardwareType(), HardwareType::port);
    ASSERT_EQ(PortC::getHardwareType(), HardwareType::port);
    ASSERT_EQ(PortD::getHardwareType(), HardwareType::port);
    ASSERT_EQ(PortE::getHardwareType(), HardwareType::port);
    ASSERT_EQ(PortF::getHardwareType(), HardwareType::port);
    ASSERT_EQ(PortG::getHardwareType(), HardwareType::port);
    ASSERT_EQ(PortH::getHardwareType(), HardwareType::port);
    ASSERT_EQ(PortJ::getHardwareType(), HardwareType::port);
    ASSERT_EQ(PortK::getHardwareType(), HardwareType::port);
    ASSERT_EQ(PortL::getHardwareType(), HardwareType::port);
}

TEST(PortX, direction) {
    TEST_REG_WRITE(PortA::mode(Pin::Mode::input));
    TEST_REG_WRITE(PortB::mode(Pin::Mode::input));
    TEST_REG_WRITE(PortC::mode(Pin::Mode::input));
    TEST_REG_WRITE(PortD::mode(Pin::Mode::output));
    TEST_REG_WRITE(PortE::mode(Pin::Mode::output));
    TEST_REG_WRITE(PortF::mode(Pin::Mode::output));
    TEST_REG_WRITE(PortG::mode(Pin::Mode::inputPullup));
    TEST_REG_WRITE(PortH::mode(Pin::Mode::inputPullup));
    TEST_REG_WRITE(PortJ::mode(Pin::Mode::inputPullup));
    TEST_REG_WRITE(PortK::mode(Pin::Mode::input));
    TEST_REG_WRITE(PortL::mode(Pin::Mode::output));
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
INCLUDE_TIMER_OVERFLOW_CALLBACK(0);
INCLUDE_TIMER_OVERFLOW_CALLBACK(1);
INCLUDE_TIMER_OVERFLOW_CALLBACK(2);
INCLUDE_TIMER_OVERFLOW_CALLBACK(3);
INCLUDE_TIMER_OVERFLOW_CALLBACK(4);
INCLUDE_TIMER_OVERFLOW_CALLBACK(5);
INCLUDE_TIMER_OUTPUT_CALLBACK(0, A);
INCLUDE_TIMER_OUTPUT_CALLBACK(0, B);
INCLUDE_TIMER_OUTPUT_CALLBACK(1, A);
INCLUDE_TIMER_OUTPUT_CALLBACK(1, B);
INCLUDE_TIMER_OUTPUT_CALLBACK(1, C);
INCLUDE_TIMER_OUTPUT_CALLBACK(2, A);
INCLUDE_TIMER_OUTPUT_CALLBACK(2, B);
INCLUDE_TIMER_OUTPUT_CALLBACK(3, A);
INCLUDE_TIMER_OUTPUT_CALLBACK(3, B);
INCLUDE_TIMER_OUTPUT_CALLBACK(3, C);
INCLUDE_TIMER_OUTPUT_CALLBACK(4, A);
INCLUDE_TIMER_OUTPUT_CALLBACK(4, B);
INCLUDE_TIMER_OUTPUT_CALLBACK(4, C);
INCLUDE_TIMER_OUTPUT_CALLBACK(5, A);
INCLUDE_TIMER_OUTPUT_CALLBACK(5, B);
INCLUDE_TIMER_OUTPUT_CALLBACK(5, C);

TEST(Timer0, getHardwareType) {
    ASSERT_EQ(Timer0::getHardwareType(), HardwareType::timer);
}

TEST(Timer0, type) {
    ::testing::StaticAssertTypeEq<Timer0::type, uint8_t>();
}

TEST(Timer0, counter) {
    TEST_REG_WRITE(Timer0::counter(0xc4));
    TEST_REG_READ_WRITE(Timer0::counter());
}

TEST(Timer0, clock) {
    TEST_REG_WRITE(Timer0::clock(Timer0::Clock::None));
    TEST_REG_WRITE(Timer0::clock(Timer0::Clock::Div1));
    TEST_REG_WRITE(Timer0::clock(Timer0::Clock::Div8));
    TEST_REG_WRITE(Timer0::clock(Timer0::Clock::Div64));
    TEST_REG_WRITE(Timer0::clock(Timer0::Clock::Div256));
    TEST_REG_WRITE(Timer0::clock(Timer0::Clock::Div1024));
    TEST_REG_WRITE(Timer0::clock(Timer0::Clock::ExtFalling));
    TEST_REG_WRITE(Timer0::clock(Timer0::Clock::ExtRising));
}

TEST(Timer0, waveform) {
    TEST_REG_WRITE(Timer0::waveform(Timer0::Waveform::Normal));
    TEST_REG_WRITE(Timer0::waveform(Timer0::Waveform::PWM));
    TEST_REG_WRITE(Timer0::waveform(Timer0::Waveform::CTCOCRA));
    TEST_REG_WRITE(Timer0::waveform(Timer0::Waveform::FastPWM));
    TEST_REG_WRITE(Timer0::waveform(Timer0::Waveform::PWMOCRA));
    TEST_REG_WRITE(Timer0::waveform(Timer0::Waveform::FastPWMOCRA));
}

TEST(Timer0, overflowCallback) {
    TEST_REG_WRITE(Timer0::overflowCallback(func,data));
}

TEST(Timer0, overflowIntEnable) {
    TEST_REG_WRITE(Timer0::overflowIntEnable(true));
    TEST_REG_WRITE(Timer0::overflowIntEnable(false));
}

TEST(Timer0, overflowIntFlag) {
    TEST_REG_READ_WRITE(Timer0::overflowIntFlag());
}

TEST(Timer0, overflowIntFlagClear) {
    TEST_REG_WRITE(Timer0::overflowIntFlagClear());
}

TEST(Timer0, outputA) {
    TEST_REG_WRITE(Timer0::OutputA::value(0xc8));
    TEST_REG_READ_WRITE(Timer0::OutputA::value());
}

TEST(Timer0, outputB) {
    TEST_REG_WRITE(Timer0::OutputB::value(0x7a));
    TEST_REG_READ_WRITE(Timer0::OutputB::value());
}

TEST(Timer0, outputAMode) {
    TEST_REG_WRITE(Timer0::OutputA::mode(Timer0::OutputA::Mode::Disconnected));
    TEST_REG_WRITE(Timer0::OutputA::mode(Timer0::OutputA::Mode::Toggle));
    TEST_REG_WRITE(Timer0::OutputA::mode(Timer0::OutputA::Mode::Clear));
    TEST_REG_WRITE(Timer0::OutputA::mode(Timer0::OutputA::Mode::Set));
}

TEST(Timer0, outputBMode) {
    TEST_REG_WRITE(Timer0::OutputB::mode(Timer0::OutputB::Mode::Disconnected));
    TEST_REG_WRITE(Timer0::OutputB::mode(Timer0::OutputB::Mode::Toggle));
    TEST_REG_WRITE(Timer0::OutputB::mode(Timer0::OutputB::Mode::Clear));
    TEST_REG_WRITE(Timer0::OutputB::mode(Timer0::OutputB::Mode::Set));
}

TEST(Timer0, outputACallback) {
    TEST_REG_WRITE(Timer0::OutputA::callback(func,data));
}

TEST(Timer0, outputBCallback) {
    TEST_REG_WRITE(Timer0::OutputB::callback(func,data));
}

TEST(Timer0, outputAIntEnable) {
    TEST_REG_WRITE(Timer0::OutputA::intEnable(true));
    TEST_REG_WRITE(Timer0::OutputA::intEnable(false));
}

TEST(Timer0, outputBIntEnable) {
    TEST_REG_WRITE(Timer0::OutputB::intEnable(true));
    TEST_REG_WRITE(Timer0::OutputB::intEnable(false));
}

TEST(Timer0, outputAIntFlag) {
    TEST_REG_READ_WRITE(Timer0::OutputA::intFlag());
}

TEST(Timer0, outputBIntFlag) {
    TEST_REG_READ_WRITE(Timer0::OutputB::intFlag());
}

TEST(Timer0, outputAIntFlagClear) {
    TEST_REG_WRITE(Timer0::OutputA::intFlagClear());
}

TEST(Timer0, outputBIntFlagClear) {
    TEST_REG_WRITE(Timer0::OutputB::intFlagClear());
}

TEST(Timer1, getHardwareType) {
    ASSERT_EQ(Timer1::getHardwareType(), HardwareType::timer);
}

TEST(Timer1, type) {
    ::testing::StaticAssertTypeEq<Timer1::type, uint16_t>();
}

TEST(Timer1, counter) {
    TEST_REG_WRITE(Timer1::counter(0x7c8a));
    TEST_REG_READ_WRITE(Timer1::counter());
}

TEST(Timer1, clock) {
    TEST_REG_WRITE(Timer1::clock(Timer1::Clock::None));
    TEST_REG_WRITE(Timer1::clock(Timer1::Clock::Div1));
    TEST_REG_WRITE(Timer1::clock(Timer1::Clock::Div8));
    TEST_REG_WRITE(Timer1::clock(Timer1::Clock::Div64));
    TEST_REG_WRITE(Timer1::clock(Timer1::Clock::Div256));
    TEST_REG_WRITE(Timer1::clock(Timer1::Clock::Div1024));
    TEST_REG_WRITE(Timer1::clock(Timer1::Clock::ExtFalling));
    TEST_REG_WRITE(Timer1::clock(Timer1::Clock::ExtRising));
}

TEST(Timer1, waveform) {
    TEST_REG_WRITE(Timer1::waveform(Timer1::Waveform::Normal));
    TEST_REG_WRITE(Timer1::waveform(Timer1::Waveform::PWM));
    TEST_REG_WRITE(Timer1::waveform(Timer1::Waveform::CTCOCRA));
    TEST_REG_WRITE(Timer1::waveform(Timer1::Waveform::FastPWM));
    TEST_REG_WRITE(Timer1::waveform(Timer1::Waveform::PWMOCRA));
    TEST_REG_WRITE(Timer1::waveform(Timer1::Waveform::FastPWMOCRA));
}

TEST(Timer1, overflowCallback) {
    TEST_REG_WRITE(Timer1::overflowCallback(func,data));
}

TEST(Timer1, overflowIntEnable) {
    TEST_REG_WRITE(Timer1::overflowIntEnable(true));
    TEST_REG_WRITE(Timer1::overflowIntEnable(false));
}

TEST(Timer1, overflowIntFlag) {
    TEST_REG_READ_WRITE(Timer1::overflowIntFlag());
}

TEST(Timer1, overflowIntFlagClear) {
    TEST_REG_WRITE(Timer1::overflowIntFlagClear());
}

TEST(Timer1, outputA) {
    TEST_REG_WRITE(Timer1::OutputA::value(0xe8d9));
    TEST_REG_READ_WRITE(Timer1::OutputA::value());
}

TEST(Timer1, outputB) {
    TEST_REG_WRITE(Timer1::OutputB::value(0x7a8d));
    TEST_REG_READ_WRITE(Timer1::OutputB::value());
}

TEST(Timer1, outputC) {
    TEST_REG_WRITE(Timer1::OutputC::value(0x6c8a));
    TEST_REG_READ_WRITE(Timer1::OutputC::value());
}

TEST(Timer1, outputAMode) {
    TEST_REG_WRITE(Timer1::OutputA::mode(Timer1::OutputA::Mode::Disconnected));
    TEST_REG_WRITE(Timer1::OutputA::mode(Timer1::OutputA::Mode::Toggle));
    TEST_REG_WRITE(Timer1::OutputA::mode(Timer1::OutputA::Mode::Clear));
    TEST_REG_WRITE(Timer1::OutputA::mode(Timer1::OutputA::Mode::Set));
}

TEST(Timer1, outputBMode) {
    TEST_REG_WRITE(Timer1::OutputB::mode(Timer1::OutputB::Mode::Disconnected));
    TEST_REG_WRITE(Timer1::OutputB::mode(Timer1::OutputB::Mode::Toggle));
    TEST_REG_WRITE(Timer1::OutputB::mode(Timer1::OutputB::Mode::Clear));
    TEST_REG_WRITE(Timer1::OutputB::mode(Timer1::OutputB::Mode::Set));
}

TEST(Timer1, outputCMode) {
    TEST_REG_WRITE(Timer1::OutputC::mode(Timer1::OutputC::Mode::Disconnected));
    TEST_REG_WRITE(Timer1::OutputC::mode(Timer1::OutputC::Mode::Toggle));
    TEST_REG_WRITE(Timer1::OutputC::mode(Timer1::OutputC::Mode::Clear));
    TEST_REG_WRITE(Timer1::OutputC::mode(Timer1::OutputC::Mode::Set));
}

TEST(Timer1, outputACallback) {
    TEST_REG_WRITE(Timer1::OutputA::callback(func,data));
}

TEST(Timer1, outputBCallback) {
    TEST_REG_WRITE(Timer1::OutputB::callback(func,data));
}

TEST(Timer1, outputCCallback) {
    TEST_REG_WRITE(Timer1::OutputC::callback(func,data));
}

TEST(Timer1, outputAIntEnable) {
    TEST_REG_WRITE(Timer1::OutputA::intEnable(true));
    TEST_REG_WRITE(Timer1::OutputA::intEnable(false));
}

TEST(Timer1, outputBIntEnable) {
    TEST_REG_WRITE(Timer1::OutputB::intEnable(true));
    TEST_REG_WRITE(Timer1::OutputB::intEnable(false));
}

TEST(Timer1, outputCIntEnable) {
    TEST_REG_WRITE(Timer1::OutputC::intEnable(true));
    TEST_REG_WRITE(Timer1::OutputC::intEnable(false));
}

TEST(Timer1, outputAIntFlag) {
    TEST_REG_READ_WRITE(Timer1::OutputA::intFlag());
}

TEST(Timer1, outputBIntFlag) {
    TEST_REG_READ_WRITE(Timer1::OutputB::intFlag());
}

TEST(Timer1, outputCIntFlag) {
    TEST_REG_READ_WRITE(Timer1::OutputC::intFlag());
}

TEST(Timer1, outputAIntFlagClear) {
    TEST_REG_WRITE(Timer1::OutputA::intFlagClear());
}

TEST(Timer1, outputBIntFlagClear) {
    TEST_REG_WRITE(Timer1::OutputB::intFlagClear());
}

TEST(Timer1, outputCIntFlagClear) {
    TEST_REG_WRITE(Timer1::OutputC::intFlagClear());
}

TEST(Timer2, getHardwareType) {
    ASSERT_EQ(Timer2::getHardwareType(), HardwareType::timer);
}

TEST(Timer2, type) {
    ::testing::StaticAssertTypeEq<Timer2::type, uint8_t>();
}

TEST(Timer2, counter) {
    TEST_REG_WRITE(Timer2::counter(0x23));
    TEST_REG_READ_WRITE(Timer2::counter());
}

TEST(Timer2, clock) {
    TEST_REG_WRITE(Timer2::clock(Timer2::Clock::None));
    TEST_REG_WRITE(Timer2::clock(Timer2::Clock::Div1));
    TEST_REG_WRITE(Timer2::clock(Timer2::Clock::Div8));
    TEST_REG_WRITE(Timer2::clock(Timer2::Clock::Div32));
    TEST_REG_WRITE(Timer2::clock(Timer2::Clock::Div64));
    TEST_REG_WRITE(Timer2::clock(Timer2::Clock::Div128));
    TEST_REG_WRITE(Timer2::clock(Timer2::Clock::Div256));
    TEST_REG_WRITE(Timer2::clock(Timer2::Clock::Div1024));
}

TEST(Timer2, waveform) {
    TEST_REG_WRITE(Timer2::waveform(Timer2::Waveform::Normal));
    TEST_REG_WRITE(Timer2::waveform(Timer2::Waveform::PWM));
    TEST_REG_WRITE(Timer2::waveform(Timer2::Waveform::CTCOCRA));
    TEST_REG_WRITE(Timer2::waveform(Timer2::Waveform::FastPWM));
    TEST_REG_WRITE(Timer2::waveform(Timer2::Waveform::PWMOCRA));
    TEST_REG_WRITE(Timer2::waveform(Timer2::Waveform::FastPWMOCRA));
}

TEST(Timer2, overflowCallback) {
    TEST_REG_WRITE(Timer2::overflowCallback(func,data));
}

TEST(Timer2, overflowIntEnable) {
    TEST_REG_WRITE(Timer2::overflowIntEnable(true));
    TEST_REG_WRITE(Timer2::overflowIntEnable(false));
}

TEST(Timer2, overflowIntFlag) {
    TEST_REG_READ_WRITE(Timer2::overflowIntFlag());
}

TEST(Timer2, overflowIntFlagClear) {
    TEST_REG_WRITE(Timer2::overflowIntFlagClear());
}

TEST(Timer2, outputA) {
    TEST_REG_WRITE(Timer2::OutputA::value(0xed));
    TEST_REG_READ_WRITE(Timer2::OutputA::value());
}

TEST(Timer2, outputB) {
    TEST_REG_WRITE(Timer2::OutputB::value(0xd8));
    TEST_REG_READ_WRITE(Timer2::OutputB::value());
}

TEST(Timer2, outputAMode) {
    TEST_REG_WRITE(Timer2::OutputA::mode(Timer2::OutputA::Mode::Disconnected));
    TEST_REG_WRITE(Timer2::OutputA::mode(Timer2::OutputA::Mode::Toggle));
    TEST_REG_WRITE(Timer2::OutputA::mode(Timer2::OutputA::Mode::Clear));
    TEST_REG_WRITE(Timer2::OutputA::mode(Timer2::OutputA::Mode::Set));
}

TEST(Timer2, outputBMode) {
    TEST_REG_WRITE(Timer2::OutputB::mode(Timer2::OutputB::Mode::Disconnected));
    TEST_REG_WRITE(Timer2::OutputB::mode(Timer2::OutputB::Mode::Toggle));
    TEST_REG_WRITE(Timer2::OutputB::mode(Timer2::OutputB::Mode::Clear));
    TEST_REG_WRITE(Timer2::OutputB::mode(Timer2::OutputB::Mode::Set));
}

TEST(Timer2, outputACallback) {
    TEST_REG_WRITE(Timer2::OutputA::callback(func,data));
}

TEST(Timer2, outputBCallback) {
    TEST_REG_WRITE(Timer2::OutputB::callback(func,data));
}

TEST(Timer2, outputAIntEnable) {
    TEST_REG_WRITE(Timer2::OutputA::intEnable(true));
    TEST_REG_WRITE(Timer2::OutputA::intEnable(false));
}

TEST(Timer2, outputBIntEnable) {
    TEST_REG_WRITE(Timer2::OutputB::intEnable(true));
    TEST_REG_WRITE(Timer2::OutputB::intEnable(false));
}

TEST(Timer2, outputAIntFlag) {
    TEST_REG_READ_WRITE(Timer2::OutputA::intFlag());
}

TEST(Timer2, outputBIntFlag) {
    TEST_REG_READ_WRITE(Timer2::OutputB::intFlag());
}

TEST(Timer2, outputAIntFlagClear) {
    TEST_REG_WRITE(Timer2::OutputA::intFlagClear());
}

TEST(Timer2, outputBIntFlagClear) {
    TEST_REG_WRITE(Timer2::OutputB::intFlagClear());
}


TEST(Timer3, getHardwareType) {
    ASSERT_EQ(Timer3::getHardwareType(), HardwareType::timer);
}

TEST(Timer3, type) {
    ::testing::StaticAssertTypeEq<Timer3::type, uint16_t>();
}

TEST(Timer3, counter) {
    TEST_REG_WRITE(Timer3::counter(0x378f));
    TEST_REG_READ_WRITE(Timer3::counter());
}

TEST(Timer3, clock) {
    TEST_REG_WRITE(Timer3::clock(Timer3::Clock::None));
    TEST_REG_WRITE(Timer3::clock(Timer3::Clock::Div1));
    TEST_REG_WRITE(Timer3::clock(Timer3::Clock::Div8));
    TEST_REG_WRITE(Timer3::clock(Timer3::Clock::Div64));
    TEST_REG_WRITE(Timer3::clock(Timer3::Clock::Div256));
    TEST_REG_WRITE(Timer3::clock(Timer3::Clock::Div1024));
    TEST_REG_WRITE(Timer3::clock(Timer3::Clock::ExtFalling));
    TEST_REG_WRITE(Timer3::clock(Timer3::Clock::ExtRising));
}

TEST(Timer3, waveform) {
    TEST_REG_WRITE(Timer3::waveform(Timer3::Waveform::Normal));
    TEST_REG_WRITE(Timer3::waveform(Timer3::Waveform::PWM));
    TEST_REG_WRITE(Timer3::waveform(Timer3::Waveform::CTCOCRA));
    TEST_REG_WRITE(Timer3::waveform(Timer3::Waveform::FastPWM));
    TEST_REG_WRITE(Timer3::waveform(Timer3::Waveform::PWMOCRA));
    TEST_REG_WRITE(Timer3::waveform(Timer3::Waveform::FastPWMOCRA));
}

TEST(Timer3, overflowCallback) {
    TEST_REG_WRITE(Timer3::overflowCallback(func,data));
}

TEST(Timer3, overflowIntEnable) {
    TEST_REG_WRITE(Timer3::overflowIntEnable(true));
    TEST_REG_WRITE(Timer3::overflowIntEnable(false));
}

TEST(Timer3, overflowIntFlag) {
    TEST_REG_READ_WRITE(Timer3::overflowIntFlag());
}

TEST(Timer3, overflowIntFlagClear) {
    TEST_REG_WRITE(Timer3::overflowIntFlagClear());
}

TEST(Timer3, outputA) {
    TEST_REG_WRITE(Timer3::OutputA::value(0x65d2));
    TEST_REG_READ_WRITE(Timer3::OutputA::value());
}

TEST(Timer3, outputB) {
    TEST_REG_WRITE(Timer3::OutputB::value(0x78ee));
    TEST_REG_READ_WRITE(Timer3::OutputB::value());
}

TEST(Timer3, outputC) {
    TEST_REG_WRITE(Timer3::OutputC::value(0x178f));
    TEST_REG_READ_WRITE(Timer3::OutputC::value());
}

TEST(Timer3, outputAMode) {
    TEST_REG_WRITE(Timer3::OutputA::mode(Timer3::OutputA::Mode::Disconnected));
    TEST_REG_WRITE(Timer3::OutputA::mode(Timer3::OutputA::Mode::Toggle));
    TEST_REG_WRITE(Timer3::OutputA::mode(Timer3::OutputA::Mode::Clear));
    TEST_REG_WRITE(Timer3::OutputA::mode(Timer3::OutputA::Mode::Set));
}

TEST(Timer3, outputBMode) {
    TEST_REG_WRITE(Timer3::OutputB::mode(Timer3::OutputB::Mode::Disconnected));
    TEST_REG_WRITE(Timer3::OutputB::mode(Timer3::OutputB::Mode::Toggle));
    TEST_REG_WRITE(Timer3::OutputB::mode(Timer3::OutputB::Mode::Clear));
    TEST_REG_WRITE(Timer3::OutputB::mode(Timer3::OutputB::Mode::Set));
}

TEST(Timer3, outputCMode) {
    TEST_REG_WRITE(Timer3::OutputC::mode(Timer3::OutputC::Mode::Disconnected));
    TEST_REG_WRITE(Timer3::OutputC::mode(Timer3::OutputC::Mode::Toggle));
    TEST_REG_WRITE(Timer3::OutputC::mode(Timer3::OutputC::Mode::Clear));
    TEST_REG_WRITE(Timer3::OutputC::mode(Timer3::OutputC::Mode::Set));
}

TEST(Timer3, outputACallback) {
    TEST_REG_WRITE(Timer3::OutputA::callback(func,data));
}

TEST(Timer3, outputBCallback) {
    TEST_REG_WRITE(Timer3::OutputB::callback(func,data));
}

TEST(Timer3, outputCCallback) {
    TEST_REG_WRITE(Timer3::OutputC::callback(func,data));
}

TEST(Timer3, outputAIntEnable) {
    TEST_REG_WRITE(Timer3::OutputA::intEnable(true));
    TEST_REG_WRITE(Timer3::OutputA::intEnable(false));
}

TEST(Timer3, outputBIntEnable) {
    TEST_REG_WRITE(Timer3::OutputB::intEnable(true));
    TEST_REG_WRITE(Timer3::OutputB::intEnable(false));
}

TEST(Timer3, outputCIntEnable) {
    TEST_REG_WRITE(Timer3::OutputC::intEnable(true));
    TEST_REG_WRITE(Timer3::OutputC::intEnable(false));
}

TEST(Timer3, outputAIntFlag) {
    TEST_REG_READ_WRITE(Timer3::OutputA::intFlag());
}

TEST(Timer3, outputBIntFlag) {
    TEST_REG_READ_WRITE(Timer3::OutputB::intFlag());
}

TEST(Timer3, outputCIntFlag) {
    TEST_REG_READ_WRITE(Timer3::OutputC::intFlag());
}

TEST(Timer3, outputAIntFlagClear) {
    TEST_REG_WRITE(Timer3::OutputA::intFlagClear());
}

TEST(Timer3, outputBIntFlagClear) {
    TEST_REG_WRITE(Timer3::OutputB::intFlagClear());
}

TEST(Timer3, outputCIntFlagClear) {
    TEST_REG_WRITE(Timer3::OutputC::intFlagClear());
}


TEST(Timer4, getHardwareType) {
    ASSERT_EQ(Timer4::getHardwareType(), HardwareType::timer);
}

TEST(Timer4, type) {
    ::testing::StaticAssertTypeEq<Timer4::type, uint16_t>();
}

TEST(Timer4, counter) {
    TEST_REG_WRITE(Timer4::counter(0x78ac));
    TEST_REG_READ_WRITE(Timer4::counter());
}

TEST(Timer4, clock) {
    TEST_REG_WRITE(Timer4::clock(Timer4::Clock::None));
    TEST_REG_WRITE(Timer4::clock(Timer4::Clock::Div1));
    TEST_REG_WRITE(Timer4::clock(Timer4::Clock::Div8));
    TEST_REG_WRITE(Timer4::clock(Timer4::Clock::Div64));
    TEST_REG_WRITE(Timer4::clock(Timer4::Clock::Div256));
    TEST_REG_WRITE(Timer4::clock(Timer4::Clock::Div1024));
    TEST_REG_WRITE(Timer4::clock(Timer4::Clock::ExtFalling));
    TEST_REG_WRITE(Timer4::clock(Timer4::Clock::ExtRising));
}

TEST(Timer4, waveform) {
    TEST_REG_WRITE(Timer4::waveform(Timer4::Waveform::Normal));
    TEST_REG_WRITE(Timer4::waveform(Timer4::Waveform::PWM));
    TEST_REG_WRITE(Timer4::waveform(Timer4::Waveform::CTCOCRA));
    TEST_REG_WRITE(Timer4::waveform(Timer4::Waveform::FastPWM));
    TEST_REG_WRITE(Timer4::waveform(Timer4::Waveform::PWMOCRA));
    TEST_REG_WRITE(Timer4::waveform(Timer4::Waveform::FastPWMOCRA));
}

TEST(Timer4, overflowCallback) {
    TEST_REG_WRITE(Timer4::overflowCallback(func,data));
}

TEST(Timer4, overflowIntEnable) {
    TEST_REG_WRITE(Timer4::overflowIntEnable(true));
    TEST_REG_WRITE(Timer4::overflowIntEnable(false));
}

TEST(Timer4, overflowIntFlag) {
    TEST_REG_READ_WRITE(Timer4::overflowIntFlag());
}

TEST(Timer4, overflowIntFlagClear) {
    TEST_REG_WRITE(Timer4::overflowIntFlagClear());
}

TEST(Timer4, outputA) {
    TEST_REG_WRITE(Timer4::OutputA::value(0x91ff));
    TEST_REG_READ_WRITE(Timer4::OutputA::value());
}

TEST(Timer4, outputB) {
    TEST_REG_WRITE(Timer4::OutputB::value(0xaa72));
    TEST_REG_READ_WRITE(Timer4::OutputB::value());
}

TEST(Timer4, outputC) {
    TEST_REG_WRITE(Timer4::OutputC::value(0xf7f8));
    TEST_REG_READ_WRITE(Timer4::OutputC::value());
}

TEST(Timer4, outputAMode) {
    TEST_REG_WRITE(Timer4::OutputA::mode(Timer4::OutputA::Mode::Disconnected));
    TEST_REG_WRITE(Timer4::OutputA::mode(Timer4::OutputA::Mode::Toggle));
    TEST_REG_WRITE(Timer4::OutputA::mode(Timer4::OutputA::Mode::Clear));
    TEST_REG_WRITE(Timer4::OutputA::mode(Timer4::OutputA::Mode::Set));
}

TEST(Timer4, outputBMode) {
    TEST_REG_WRITE(Timer4::OutputB::mode(Timer4::OutputB::Mode::Disconnected));
    TEST_REG_WRITE(Timer4::OutputB::mode(Timer4::OutputB::Mode::Toggle));
    TEST_REG_WRITE(Timer4::OutputB::mode(Timer4::OutputB::Mode::Clear));
    TEST_REG_WRITE(Timer4::OutputB::mode(Timer4::OutputB::Mode::Set));
}

TEST(Timer4, outputCMode) {
    TEST_REG_WRITE(Timer4::OutputC::mode(Timer4::OutputC::Mode::Disconnected));
    TEST_REG_WRITE(Timer4::OutputC::mode(Timer4::OutputC::Mode::Toggle));
    TEST_REG_WRITE(Timer4::OutputC::mode(Timer4::OutputC::Mode::Clear));
    TEST_REG_WRITE(Timer4::OutputC::mode(Timer4::OutputC::Mode::Set));
}

TEST(Timer4, outputACallback) {
    TEST_REG_WRITE(Timer4::OutputA::callback(func,data));
}

TEST(Timer4, outputBCallback) {
    TEST_REG_WRITE(Timer4::OutputB::callback(func,data));
}

TEST(Timer4, outputCCallback) {
    TEST_REG_WRITE(Timer4::OutputC::callback(func,data));
}

TEST(Timer4, outputAIntEnable) {
    TEST_REG_WRITE(Timer4::OutputA::intEnable(true));
    TEST_REG_WRITE(Timer4::OutputA::intEnable(false));
}

TEST(Timer4, outputBIntEnable) {
    TEST_REG_WRITE(Timer4::OutputB::intEnable(true));
    TEST_REG_WRITE(Timer4::OutputB::intEnable(false));
}

TEST(Timer4, outputCIntEnable) {
    TEST_REG_WRITE(Timer4::OutputC::intEnable(true));
    TEST_REG_WRITE(Timer4::OutputC::intEnable(false));
}

TEST(Timer4, outputAIntFlag) {
    TEST_REG_READ_WRITE(Timer4::OutputA::intFlag());
}

TEST(Timer4, outputBIntFlag) {
    TEST_REG_READ_WRITE(Timer4::OutputB::intFlag());
}

TEST(Timer4, outputCIntFlag) {
    TEST_REG_READ_WRITE(Timer4::OutputC::intFlag());
}

TEST(Timer4, outputAIntFlagClear) {
    TEST_REG_WRITE(Timer4::OutputA::intFlagClear());
}

TEST(Timer4, outputBIntFlagClear) {
    TEST_REG_WRITE(Timer4::OutputB::intFlagClear());
}

TEST(Timer4, outputCIntFlagClear) {
    TEST_REG_WRITE(Timer4::OutputC::intFlagClear());
}


TEST(Timer5, getHardwareType) {
    ASSERT_EQ(Timer5::getHardwareType(), HardwareType::timer);
}

TEST(Timer5, type) {
    ::testing::StaticAssertTypeEq<Timer5::type, uint16_t>();
}

TEST(Timer5, counter) {
    TEST_REG_WRITE(Timer5::counter(0x028d));
    TEST_REG_READ_WRITE(Timer5::counter());
}

TEST(Timer5, clock) {
    TEST_REG_WRITE(Timer5::clock(Timer5::Clock::None));
    TEST_REG_WRITE(Timer5::clock(Timer5::Clock::Div1));
    TEST_REG_WRITE(Timer5::clock(Timer5::Clock::Div8));
    TEST_REG_WRITE(Timer5::clock(Timer5::Clock::Div64));
    TEST_REG_WRITE(Timer5::clock(Timer5::Clock::Div256));
    TEST_REG_WRITE(Timer5::clock(Timer5::Clock::Div1024));
    TEST_REG_WRITE(Timer5::clock(Timer5::Clock::ExtFalling));
    TEST_REG_WRITE(Timer5::clock(Timer5::Clock::ExtRising));
}

TEST(Timer5, waveform) {
    TEST_REG_WRITE(Timer5::waveform(Timer5::Waveform::Normal));
    TEST_REG_WRITE(Timer5::waveform(Timer5::Waveform::PWM));
    TEST_REG_WRITE(Timer5::waveform(Timer5::Waveform::CTCOCRA));
    TEST_REG_WRITE(Timer5::waveform(Timer5::Waveform::FastPWM));
    TEST_REG_WRITE(Timer5::waveform(Timer5::Waveform::PWMOCRA));
    TEST_REG_WRITE(Timer5::waveform(Timer5::Waveform::FastPWMOCRA));
}

TEST(Timer5, overflowCallback) {
    TEST_REG_WRITE(Timer5::overflowCallback(func,data));
}

TEST(Timer5, overflowIntEnable) {
    TEST_REG_WRITE(Timer5::overflowIntEnable(true));
    TEST_REG_WRITE(Timer5::overflowIntEnable(false));
}

TEST(Timer5, overflowIntFlag) {
    TEST_REG_READ_WRITE(Timer5::overflowIntFlag());
}

TEST(Timer5, overflowIntFlagClear) {
    TEST_REG_WRITE(Timer5::overflowIntFlagClear());
}

TEST(Timer5, outputA) {
    TEST_REG_WRITE(Timer5::OutputA::value(0x102f));
    TEST_REG_READ_WRITE(Timer5::OutputA::value());
}

TEST(Timer5, outputB) {
    TEST_REG_WRITE(Timer5::OutputB::value(0xff12));
    TEST_REG_READ_WRITE(Timer5::OutputB::value());
}

TEST(Timer5, outputC) {
    TEST_REG_WRITE(Timer5::OutputC::value(0x2267));
    TEST_REG_READ_WRITE(Timer5::OutputC::value());
}

TEST(Timer5, outputAMode) {
    TEST_REG_WRITE(Timer5::OutputA::mode(Timer5::OutputA::Mode::Disconnected));
    TEST_REG_WRITE(Timer5::OutputA::mode(Timer5::OutputA::Mode::Toggle));
    TEST_REG_WRITE(Timer5::OutputA::mode(Timer5::OutputA::Mode::Clear));
    TEST_REG_WRITE(Timer5::OutputA::mode(Timer5::OutputA::Mode::Set));
}

TEST(Timer5, outputBMode) {
    TEST_REG_WRITE(Timer5::OutputB::mode(Timer5::OutputB::Mode::Disconnected));
    TEST_REG_WRITE(Timer5::OutputB::mode(Timer5::OutputB::Mode::Toggle));
    TEST_REG_WRITE(Timer5::OutputB::mode(Timer5::OutputB::Mode::Clear));
    TEST_REG_WRITE(Timer5::OutputB::mode(Timer5::OutputB::Mode::Set));
}

TEST(Timer5, outputCMode) {
    TEST_REG_WRITE(Timer5::OutputC::mode(Timer5::OutputC::Mode::Disconnected));
    TEST_REG_WRITE(Timer5::OutputC::mode(Timer5::OutputC::Mode::Toggle));
    TEST_REG_WRITE(Timer5::OutputC::mode(Timer5::OutputC::Mode::Clear));
    TEST_REG_WRITE(Timer5::OutputC::mode(Timer5::OutputC::Mode::Set));
}

TEST(Timer5, outputACallback) {
    TEST_REG_WRITE(Timer5::OutputA::callback(func,data));
}

TEST(Timer5, outputBCallback) {
    TEST_REG_WRITE(Timer5::OutputB::callback(func,data));
}

TEST(Timer5, outputCCallback) {
    TEST_REG_WRITE(Timer5::OutputC::callback(func,data));
}

TEST(Timer5, outputAIntEnable) {
    TEST_REG_WRITE(Timer5::OutputA::intEnable(true));
    TEST_REG_WRITE(Timer5::OutputA::intEnable(false));
}

TEST(Timer5, outputBIntEnable) {
    TEST_REG_WRITE(Timer5::OutputB::intEnable(true));
    TEST_REG_WRITE(Timer5::OutputB::intEnable(false));
}

TEST(Timer5, outputCIntEnable) {
    TEST_REG_WRITE(Timer5::OutputC::intEnable(true));
    TEST_REG_WRITE(Timer5::OutputC::intEnable(false));
}

TEST(Timer5, outputAIntFlag) {
    TEST_REG_READ_WRITE(Timer5::OutputA::intFlag());
}

TEST(Timer5, outputBIntFlag) {
    TEST_REG_READ_WRITE(Timer5::OutputB::intFlag());
}

TEST(Timer5, outputCIntFlag) {
    TEST_REG_READ_WRITE(Timer5::OutputC::intFlag());
}

TEST(Timer5, outputAIntFlagClear) {
    TEST_REG_WRITE(Timer5::OutputA::intFlagClear());
}

TEST(Timer5, outputBIntFlagClear) {
    TEST_REG_WRITE(Timer5::OutputB::intFlagClear());
}

TEST(Timer5, outputCIntFlagClear) {
    TEST_REG_WRITE(Timer5::OutputC::intFlagClear());
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
    ASSERT_EQ(Usart0::getHardwareType(), HardwareType::usart);
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
    ASSERT_EQ(Usart1::getHardwareType(), HardwareType::usart);
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
    ASSERT_EQ(Usart2::getHardwareType(), HardwareType::usart);
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
    ASSERT_EQ(Usart3::getHardwareType(), HardwareType::usart);
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
