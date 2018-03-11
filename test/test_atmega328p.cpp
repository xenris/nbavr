#define __atmega328p__

#define RECORD_ID "atmega328p"

#include "test.hpp"

typedef void (*ft)(void*);

static ft func = (ft)0x1234;
static void* data = (void*)0x5678;

//------------------------------------------------
// Analog to Digital

INCLUDE_ADC_CALLBACK(0);

TEST(Adc0, getHardwareType) {
    ASSERT_EQ(Adc0::getHardwareType(), HardwareType::adc);
}

TEST(Adc0, enable) {
    TEST_REG_WRITE(Adc0::enable(true));
    TEST_REG_WRITE(Adc0::enable(false));
}

TEST(Adc0, start) {
    TEST_REG_WRITE(Adc0::start());
}

TEST(Adc0, value) {
    TEST_REG_READ_WRITE(Adc0::value());
}

TEST(Adc0, reference) {
    TEST_REG_WRITE(Adc0::reference(Adc0::Reference::AREF));
    TEST_REG_WRITE(Adc0::reference(Adc0::Reference::AVCC));
    TEST_REG_WRITE(Adc0::reference(Adc0::Reference::Internal));
}

TEST(Adc0, channel) {
    TEST_REG_WRITE(Adc0::channel(Adc0::Channel::ADC0));
    TEST_REG_WRITE(Adc0::channel(Adc0::Channel::ADC1));
    TEST_REG_WRITE(Adc0::channel(Adc0::Channel::ADC2));
    TEST_REG_WRITE(Adc0::channel(Adc0::Channel::ADC3));
    TEST_REG_WRITE(Adc0::channel(Adc0::Channel::ADC4));
    TEST_REG_WRITE(Adc0::channel(Adc0::Channel::ADC5));
    TEST_REG_WRITE(Adc0::channel(Adc0::Channel::ADC6));
    TEST_REG_WRITE(Adc0::channel(Adc0::Channel::ADC7));
    TEST_REG_WRITE(Adc0::channel(Adc0::Channel::ADC8));
    TEST_REG_WRITE(Adc0::channel(Adc0::Channel::VBG));
    TEST_REG_WRITE(Adc0::channel(Adc0::Channel::GND));
}

TEST(Adc0, prescaler) {
    TEST_REG_WRITE(Adc0::prescaler(Adc0::Prescaler::Div2));
    TEST_REG_WRITE(Adc0::prescaler(Adc0::Prescaler::Div4));
    TEST_REG_WRITE(Adc0::prescaler(Adc0::Prescaler::Div8));
    TEST_REG_WRITE(Adc0::prescaler(Adc0::Prescaler::Div16));
    TEST_REG_WRITE(Adc0::prescaler(Adc0::Prescaler::Div32));
    TEST_REG_WRITE(Adc0::prescaler(Adc0::Prescaler::Div64));
    TEST_REG_WRITE(Adc0::prescaler(Adc0::Prescaler::Div128));
}

TEST(Adc0, leftAdjust) {
    TEST_REG_WRITE(Adc0::leftAdjust(true));
    TEST_REG_WRITE(Adc0::leftAdjust(false));
}

TEST(Adc0, trigger) {
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

TEST(Adc0, callback) {
    TEST_REG_WRITE(Adc0::callback(func,data));
}

TEST(Adc0, intEnable) {
    TEST_REG_WRITE(Adc0::intEnable(false));
    TEST_REG_WRITE(Adc0::intEnable(true));
}

TEST(Adc0, intFlag) {
    TEST_REG_READ_WRITE(Adc0::intFlag());
}

TEST(Adc0, intFlagClear) {
    TEST_REG_WRITE(Adc0::intFlagClear());
}

//------------------------------------------------
// External Interrupts

INCLUDE_EXINT_CALLBACK(0);
INCLUDE_EXINT_CALLBACK(1);

TEST(ExIntN, getHardwareType) {
    ASSERT_EQ(ExInt0::getHardwareType(), HardwareType::exInt);
    ASSERT_EQ(ExInt1::getHardwareType(), HardwareType::exInt);
}

TEST(ExIntN, enable) {
    TEST_REG_WRITE(ExInt0::enable(true));
    TEST_REG_WRITE(ExInt0::enable(false));
    TEST_REG_WRITE(ExInt1::enable(true));
    TEST_REG_WRITE(ExInt1::enable(false));
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
}

TEST(ExIntN, callback) {
    TEST_REG_WRITE(ExInt0::callback(func,data));
    TEST_REG_WRITE(ExInt1::callback(func,data));
}

TEST(ExIntN, intFlag) {
    TEST_REG_READ_WRITE(ExInt0::intFlag());
    TEST_REG_READ_WRITE(ExInt1::intFlag());
}

TEST(ExIntN, intFlagClear) {
    TEST_REG_WRITE(ExInt0::intFlagClear());
    TEST_REG_WRITE(ExInt1::intFlagClear());
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
    ASSERT_EQ(PortB::Pin0::getHardwareType(), HardwareType::pin);
    ASSERT_EQ(PortB::Pin7::getHardwareType(), HardwareType::pin);
    ASSERT_EQ(PortC::Pin0::getHardwareType(), HardwareType::pin);
    ASSERT_EQ(PortC::Pin6::getHardwareType(), HardwareType::pin);
    ASSERT_EQ(PortD::Pin0::getHardwareType(), HardwareType::pin);
    ASSERT_EQ(PortD::Pin7::getHardwareType(), HardwareType::pin);
}

TEST(PortXPinN, mode) {
    TEST_REG_WRITE(PortB::Pin0::mode(Pin::Mode::input));
    TEST_REG_WRITE(PortB::Pin0::mode(Pin::Mode::inputPullup));
    TEST_REG_WRITE(PortB::Pin0::mode(Pin::Mode::output));
    TEST_REG_READ_WRITE(PortB::Pin0::mode());

    TEST_REG_WRITE(PortC::Pin6::mode(Pin::Mode::input));
    TEST_REG_WRITE(PortC::Pin6::mode(Pin::Mode::inputPullup));
    TEST_REG_WRITE(PortC::Pin6::mode(Pin::Mode::output));
    TEST_REG_READ_WRITE(PortC::Pin6::mode());

    TEST_REG_WRITE(PortD::Pin3::mode(Pin::Mode::input));
    TEST_REG_WRITE(PortD::Pin3::mode(Pin::Mode::inputPullup));
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
    ASSERT_EQ(PortB::getHardwareType(), HardwareType::port);
    ASSERT_EQ(PortC::getHardwareType(), HardwareType::port);
    ASSERT_EQ(PortD::getHardwareType(), HardwareType::port);
}

TEST(PortX, mode) {
    TEST_REG_WRITE(PortB::mode(Pin::Mode::input));
    TEST_REG_WRITE(PortC::mode(Pin::Mode::inputPullup));
    TEST_REG_WRITE(PortD::mode(Pin::Mode::output));
}

TEST(PortX, output) {
    TEST_REG_WRITE(PortB::output(0x27));
    TEST_REG_READ_WRITE(PortB::output());

    TEST_REG_WRITE(PortC::output(0xf4));
    TEST_REG_READ_WRITE(PortC::output());

    TEST_REG_WRITE(PortD::output(0xa4));
    TEST_REG_READ_WRITE(PortD::output());
}

TEST(PortX, input) {
    TEST_REG_READ_WRITE(PortB::input());

    TEST_REG_READ_WRITE(PortC::input());

    TEST_REG_READ_WRITE(PortD::input());
}

TEST(PortX, toggle) {
    TEST_REG_WRITE(PortB::toggle(0x26));

    TEST_REG_WRITE(PortC::toggle(0xb4));

    TEST_REG_WRITE(PortD::toggle(0x82));
}

//------------------------------------------------
// Timer/Counters

INCLUDE_TIMER_OVERFLOW_CALLBACK(0);
INCLUDE_TIMER_OVERFLOW_CALLBACK(1);
INCLUDE_TIMER_OVERFLOW_CALLBACK(2);
INCLUDE_TIMER_OUTPUT_CALLBACK(0, A);
INCLUDE_TIMER_OUTPUT_CALLBACK(0, B);
INCLUDE_TIMER_OUTPUT_CALLBACK(1, A);
INCLUDE_TIMER_OUTPUT_CALLBACK(1, B);
INCLUDE_TIMER_OUTPUT_CALLBACK(2, A);
INCLUDE_TIMER_OUTPUT_CALLBACK(2, B);

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

TEST(Timer1, outputACallback) {
    TEST_REG_WRITE(Timer1::OutputA::callback(func,data));
}

TEST(Timer1, outputBCallback) {
    TEST_REG_WRITE(Timer1::OutputB::callback(func,data));
}

TEST(Timer1, outputAIntEnable) {
    TEST_REG_WRITE(Timer1::OutputA::intEnable(true));
    TEST_REG_WRITE(Timer1::OutputA::intEnable(false));
}

TEST(Timer1, outputBIntEnable) {
    TEST_REG_WRITE(Timer1::OutputB::intEnable(true));
    TEST_REG_WRITE(Timer1::OutputB::intEnable(false));
}

TEST(Timer1, outputAIntFlag) {
    TEST_REG_READ_WRITE(Timer1::OutputA::intFlag());
}

TEST(Timer1, outputBIntFlag) {
    TEST_REG_READ_WRITE(Timer1::OutputB::intFlag());
}

TEST(Timer1, outputAIntFlagClear) {
    TEST_REG_WRITE(Timer1::OutputA::intFlagClear());
}

TEST(Timer1, outputBIntFlagClear) {
    TEST_REG_WRITE(Timer1::OutputB::intFlagClear());
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

//------------------------------------------------
// Usart

INCLUDE_USART_CALLBACK(0, RX);
INCLUDE_USART_CALLBACK(0, TX);
INCLUDE_USART_CALLBACK(0, DE);

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

//------------------------------------------------
// Spi

INCLUDE_SPI_CALLBACK(0);

TEST(Spi0, getHardwareType) {
    ASSERT_EQ(Spi0::getHardwareType(), HardwareType::spi);
}

TEST(Spi0, enable) {
    TEST_REG_WRITE(Spi0::enable(true));
    TEST_REG_WRITE(Spi0::enable(false));
}

TEST(Spi0, intEnable) {
    TEST_REG_WRITE(Spi0::intEnable(true));
    TEST_REG_WRITE(Spi0::intEnable(false));
}

TEST(Spi0, dataOrder) {
    TEST_REG_WRITE(Spi0::dataOrder(Spi0::DataOrder::msbFirst));
    TEST_REG_WRITE(Spi0::dataOrder(Spi0::DataOrder::lsbFirst));
}

TEST(Spi0, masterSlave) {
    TEST_REG_WRITE(Spi0::masterSlave(Spi0::MasterSlave::master));
    TEST_REG_WRITE(Spi0::masterSlave(Spi0::MasterSlave::slave));
}

TEST(Spi0, polarity) {
    TEST_REG_WRITE(Spi0::polarity(Spi0::Polarity::leadingRisingTrailingFalling));
    TEST_REG_WRITE(Spi0::polarity(Spi0::Polarity::leadingFallingTrailingRising));
}

TEST(Spi0, phase) {
    TEST_REG_WRITE(Spi0::phase(Spi0::Phase::leadingSampleTrailingSetup));
    TEST_REG_WRITE(Spi0::phase(Spi0::Phase::leadingSetupTrailingSample));
}

TEST(Spi0, clock) {
    TEST_REG_WRITE(Spi0::clock(Spi0::Clock::div2));
    TEST_REG_WRITE(Spi0::clock(Spi0::Clock::div4));
    TEST_REG_WRITE(Spi0::clock(Spi0::Clock::div8));
    TEST_REG_WRITE(Spi0::clock(Spi0::Clock::div16));
    TEST_REG_WRITE(Spi0::clock(Spi0::Clock::div32));
    TEST_REG_WRITE(Spi0::clock(Spi0::Clock::div64));
}

TEST(Spi0, intFlag) {
    TEST_REG_READ_WRITE(Spi0::intFlag());
}

TEST(Spi0, intFlagClear) {
    TEST_REG_WRITE(Spi0::intFlagClear());
}

TEST(Spi0, collisionFlag) {
    TEST_REG_READ_WRITE(Spi0::collisionFlag());
}

TEST(Spi0, collisionFlagClear) {
    TEST_REG_WRITE(Spi0::collisionFlagClear());
}

TEST(Spi0, data) {
    TEST_REG_READ_WRITE(Spi0::data());
    TEST_REG_WRITE(Spi0::data(0x00));
    TEST_REG_WRITE(Spi0::data(0xFF));
    TEST_REG_WRITE(Spi0::data(0x4E));
}
