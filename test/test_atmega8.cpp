#define __AVR_ATmega8__

#define RECORD_ID "atmega8"

#include "test.hpp"

typedef void (*ft)(void*);

static ft func = (ft)0x3c3c;
static void* data = (void*)0x3c3c;

TEST(Adc, getHardwareType) {
    ASSERT_EQ(Adc::getHardwareType(), HardwareType::ADC);
}

TEST(Adc, enable) {
    TEST_RAM_WRITE(Adc::enable(true));
    TEST_RAM_WRITE(Adc::enable(false));
}

TEST(Adc, start) {
    TEST_RAM_WRITE(Adc::start());
}

TEST(Adc, value) {
    TEST_RAM_READ_WRITE(Adc::value());
}

TEST(Adc, reference) {
    TEST_RAM_WRITE(Adc::reference(Adc::Reference::AREF));
    TEST_RAM_WRITE(Adc::reference(Adc::Reference::AVCC));
    TEST_RAM_WRITE(Adc::reference(Adc::Reference::Internal));
}

TEST(Adc, channel) {
    TEST_RAM_WRITE(Adc::channel(Adc::Channel::ADC0));
    TEST_RAM_WRITE(Adc::channel(Adc::Channel::ADC1));
    TEST_RAM_WRITE(Adc::channel(Adc::Channel::ADC2));
    TEST_RAM_WRITE(Adc::channel(Adc::Channel::ADC3));
    TEST_RAM_WRITE(Adc::channel(Adc::Channel::ADC4));
    TEST_RAM_WRITE(Adc::channel(Adc::Channel::ADC5));
    TEST_RAM_WRITE(Adc::channel(Adc::Channel::ADC6));
    TEST_RAM_WRITE(Adc::channel(Adc::Channel::ADC7));
    TEST_RAM_WRITE(Adc::channel(Adc::Channel::VBG));
    TEST_RAM_WRITE(Adc::channel(Adc::Channel::GND));
}

TEST(Adc, prescaler) {
    TEST_RAM_WRITE(Adc::prescaler(Adc::Prescaler::Div2));
    TEST_RAM_WRITE(Adc::prescaler(Adc::Prescaler::Div4));
    TEST_RAM_WRITE(Adc::prescaler(Adc::Prescaler::Div8));
    TEST_RAM_WRITE(Adc::prescaler(Adc::Prescaler::Div16));
    TEST_RAM_WRITE(Adc::prescaler(Adc::Prescaler::Div32));
    TEST_RAM_WRITE(Adc::prescaler(Adc::Prescaler::Div64));
    TEST_RAM_WRITE(Adc::prescaler(Adc::Prescaler::Div128));
}

TEST(Adc, leftAdjust) {
    TEST_RAM_WRITE(Adc::leftAdjust(true));
    TEST_RAM_WRITE(Adc::leftAdjust(false));
}

TEST(Adc, trigger) {
    TEST_RAM_WRITE(Adc::trigger(Adc::Trigger::SingleConversion));
    TEST_RAM_WRITE(Adc::trigger(Adc::Trigger::FreeRunning));
}

INCLUDE_ADC_CALLBACK;

TEST(Adc, callback) {
    TEST_RAM_WRITE(Adc::callback(func,&data));
}

TEST(Adc, intEnable) {
    TEST_RAM_WRITE(Adc::intEnable(false));
    TEST_RAM_WRITE(Adc::intEnable(true));
}

TEST(Adc, intFlag) {
    TEST_RAM_READ_WRITE(Adc::intFlag());
}

TEST(Adc, intFlagClear) {
    TEST_RAM_WRITE(Adc::intFlagClear());
}

TEST(ExIntN, getHardwareType) {
    ASSERT_EQ(ExInt0::getHardwareType(), HardwareType::ExInt);
    ASSERT_EQ(ExInt1::getHardwareType(), HardwareType::ExInt);
}

TEST(ExIntN, enable) {
    TEST_RAM_WRITE(ExInt0::enable(true));
    TEST_RAM_WRITE(ExInt0::enable(false));
    TEST_RAM_WRITE(ExInt1::enable(true));
    TEST_RAM_WRITE(ExInt1::enable(false));
}

TEST(ExIntN, trigger) {
    TEST_RAM_WRITE(ExInt0::trigger(ExInt0::Trigger::Low));
    TEST_RAM_WRITE(ExInt0::trigger(ExInt0::Trigger::Change));
    TEST_RAM_WRITE(ExInt0::trigger(ExInt0::Trigger::Falling));
    TEST_RAM_WRITE(ExInt0::trigger(ExInt0::Trigger::Rising));

    TEST_RAM_WRITE(ExInt1::trigger(ExInt1::Trigger::Low));
    TEST_RAM_WRITE(ExInt1::trigger(ExInt1::Trigger::Change));
    TEST_RAM_WRITE(ExInt1::trigger(ExInt1::Trigger::Falling));
    TEST_RAM_WRITE(ExInt1::trigger(ExInt1::Trigger::Rising));
}

INCLUDE_EXINT_CALLBACK(0);
INCLUDE_EXINT_CALLBACK(1);

TEST(ExIntN, callback) {
    TEST_RAM_WRITE(ExInt0::callback(func,&data));
    TEST_RAM_WRITE(ExInt1::callback(func,&data));
}

TEST(ExIntN, intFlag) {
    TEST_RAM_READ_WRITE(ExInt0::intFlag());
    TEST_RAM_READ_WRITE(ExInt1::intFlag());
}

TEST(ExIntN, intFlagClear) {
    TEST_RAM_WRITE(ExInt0::intFlagClear());
    TEST_RAM_WRITE(ExInt1::intFlagClear());
}

TEST(PinXN, getHardwareType) {
    ASSERT_EQ(PinB0::getHardwareType(), HardwareType::Pin);
    ASSERT_EQ(PinB7::getHardwareType(), HardwareType::Pin);
    ASSERT_EQ(PinC0::getHardwareType(), HardwareType::Pin);
    ASSERT_EQ(PinC6::getHardwareType(), HardwareType::Pin);
    ASSERT_EQ(PinD0::getHardwareType(), HardwareType::Pin);
    ASSERT_EQ(PinD7::getHardwareType(), HardwareType::Pin);
}

TEST(PinXN, direction) {
    TEST_RAM_WRITE(PinB0::direction(Direction::Input));
    TEST_RAM_WRITE(PinB0::direction(Direction::Output));
    TEST_RAM_READ_WRITE(PinB0::direction());

    TEST_RAM_WRITE(PinC6::direction(Direction::Input));
    TEST_RAM_WRITE(PinC6::direction(Direction::Output));
    TEST_RAM_READ_WRITE(PinC6::direction());

    TEST_RAM_WRITE(PinD3::direction(Direction::Input));
    TEST_RAM_WRITE(PinD3::direction(Direction::Output));
    TEST_RAM_READ_WRITE(PinD3::direction());
}

TEST(PinXN, pullup) {
    TEST_RAM_WRITE(PinB1::pullup(true));
    TEST_RAM_WRITE(PinB1::pullup(false));
    TEST_RAM_READ_WRITE(PinB1::pullup());

    TEST_RAM_WRITE(PinC5::pullup(true));
    TEST_RAM_WRITE(PinC5::pullup(false));
    TEST_RAM_READ_WRITE(PinC5::pullup());

    TEST_RAM_WRITE(PinD4::pullup(true));
    TEST_RAM_WRITE(PinD4::pullup(false));
    TEST_RAM_READ_WRITE(PinD4::pullup());
}

TEST(PinXN, output) {
    TEST_RAM_READ_WRITE(PinB2::output());

    TEST_RAM_READ_WRITE(PinC4::output());

    TEST_RAM_READ_WRITE(PinD4::output());
}

TEST(PinXN, input) {
    TEST_RAM_READ_WRITE(PinB3::input());

    TEST_RAM_READ_WRITE(PinC3::input());

    TEST_RAM_READ_WRITE(PinD4::input());
}

TEST(PinXN, toggle) {
    TEST_RAM_WRITE(PinB4::toggle());
    TEST_RAM_WRITE(PinC2::toggle());
    TEST_RAM_WRITE(PinD5::toggle());
}

TEST(PortX, getHardwareType) {
    ASSERT_EQ(PortB::getHardwareType(), HardwareType::Port);
    ASSERT_EQ(PortC::getHardwareType(), HardwareType::Port);
    ASSERT_EQ(PortD::getHardwareType(), HardwareType::Port);
}

TEST(PortX, direction) {
    TEST_RAM_WRITE(PortB::direction(0x00));
    TEST_RAM_WRITE(PortB::direction(0x3c));
    TEST_RAM_WRITE(PortB::direction(0xff));
    TEST_RAM_READ_WRITE(PortB::direction());

    TEST_RAM_WRITE(PortC::direction(0x00));
    TEST_RAM_WRITE(PortC::direction(0x3c));
    TEST_RAM_WRITE(PortC::direction(0xff));
    TEST_RAM_READ_WRITE(PortC::direction());

    TEST_RAM_WRITE(PortD::direction(0x00));
    TEST_RAM_WRITE(PortD::direction(0x3c));
    TEST_RAM_WRITE(PortD::direction(0xff));
    TEST_RAM_READ_WRITE(PortD::direction());
}

TEST(PortX, pullup) {
    TEST_RAM_WRITE(PortB::pullup(0x00));
    TEST_RAM_WRITE(PortB::pullup(0x3c));
    TEST_RAM_WRITE(PortB::pullup(0xff));
    TEST_RAM_READ_WRITE(PortB::pullup());

    TEST_RAM_WRITE(PortC::pullup(0x00));
    TEST_RAM_WRITE(PortC::pullup(0x3c));
    TEST_RAM_WRITE(PortC::pullup(0xff));
    TEST_RAM_READ_WRITE(PortC::pullup());

    TEST_RAM_WRITE(PortD::pullup(0x00));
    TEST_RAM_WRITE(PortD::pullup(0x3c));
    TEST_RAM_WRITE(PortD::pullup(0xff));
    TEST_RAM_READ_WRITE(PortD::pullup());
}

TEST(PortX, output) {
    TEST_RAM_WRITE(PortB::output(0x00));
    TEST_RAM_WRITE(PortB::output(0x3c));
    TEST_RAM_WRITE(PortB::output(0xff));
    TEST_RAM_READ_WRITE(PortB::output());

    TEST_RAM_WRITE(PortC::output(0x00));
    TEST_RAM_WRITE(PortC::output(0x3c));
    TEST_RAM_WRITE(PortC::output(0xff));
    TEST_RAM_READ_WRITE(PortC::output());

    TEST_RAM_WRITE(PortD::output(0x00));
    TEST_RAM_WRITE(PortD::output(0x3c));
    TEST_RAM_WRITE(PortD::output(0xff));
    TEST_RAM_READ_WRITE(PortD::output());
}

TEST(PortX, input) {
    TEST_RAM_READ_WRITE(PortB::input());

    TEST_RAM_READ_WRITE(PortC::input());

    TEST_RAM_READ_WRITE(PortD::input());
}

TEST(PortX, toggle) {
    TEST_RAM_WRITE(PortB::toggle(0x00));
    TEST_RAM_WRITE(PortB::toggle(0x3c));
    TEST_RAM_WRITE(PortB::toggle(0xff));

    TEST_RAM_WRITE(PortC::toggle(0x00));
    TEST_RAM_WRITE(PortC::toggle(0x3c));
    TEST_RAM_WRITE(PortC::toggle(0xff));

    TEST_RAM_WRITE(PortD::toggle(0x00));
    TEST_RAM_WRITE(PortD::toggle(0x3c));
    TEST_RAM_WRITE(PortD::toggle(0xff));
}

TEST(TimerCounter0, getHardwareType) {
    ASSERT_EQ(TimerCounter0::getHardwareType(), HardwareType::TimerCounter);
}

TEST(TimerCounter1, getHardwareType) {
    ASSERT_EQ(TimerCounter1::getHardwareType(), HardwareType::TimerCounter);
}

TEST(TimerCounter2, getHardwareType) {
    ASSERT_EQ(TimerCounter2::getHardwareType(), HardwareType::TimerCounter);
}

TEST(TimerCounter0, type) {
    ::testing::StaticAssertTypeEq<TimerCounter0::type, uint8_t>();
}

TEST(TimerCounter1, type) {
    ::testing::StaticAssertTypeEq<TimerCounter1::type, uint16_t>();
}

TEST(TimerCounter2, type) {
    ::testing::StaticAssertTypeEq<TimerCounter2::type, uint8_t>();
}

TEST(TimerCounter0, counter) {
    TEST_RAM_WRITE(TimerCounter0::counter(0x00));
    TEST_RAM_WRITE(TimerCounter0::counter(0x3c));
    TEST_RAM_WRITE(TimerCounter0::counter(0xff));
    TEST_RAM_READ_WRITE(TimerCounter0::counter());
}

TEST(TimerCounter1, counter) {
    TEST_RAM_WRITE(TimerCounter1::counter(0x0000));
    TEST_RAM_WRITE(TimerCounter1::counter(0x3c3c));
    TEST_RAM_WRITE(TimerCounter1::counter(0xffff));
    TEST_RAM_READ_WRITE(TimerCounter1::counter());
}

TEST(TimerCounter2, counter) {
    TEST_RAM_WRITE(TimerCounter2::counter(0x00));
    TEST_RAM_WRITE(TimerCounter2::counter(0x3c));
    TEST_RAM_WRITE(TimerCounter2::counter(0xff));
    TEST_RAM_READ_WRITE(TimerCounter2::counter());
}

TEST(TimerCounter0, clock) {
    TEST_RAM_WRITE(TimerCounter0::clock(TimerCounter0::Clock::None));
    TEST_RAM_WRITE(TimerCounter0::clock(TimerCounter0::Clock::Div1));
    TEST_RAM_WRITE(TimerCounter0::clock(TimerCounter0::Clock::Div8));
    TEST_RAM_WRITE(TimerCounter0::clock(TimerCounter0::Clock::Div64));
    TEST_RAM_WRITE(TimerCounter0::clock(TimerCounter0::Clock::Div256));
    TEST_RAM_WRITE(TimerCounter0::clock(TimerCounter0::Clock::Div1024));
    TEST_RAM_WRITE(TimerCounter0::clock(TimerCounter0::Clock::ExtFalling));
    TEST_RAM_WRITE(TimerCounter0::clock(TimerCounter0::Clock::ExtRising));
}

TEST(TimerCounter1, clock) {
    TEST_RAM_WRITE(TimerCounter1::clock(TimerCounter1::Clock::None));
    TEST_RAM_WRITE(TimerCounter1::clock(TimerCounter1::Clock::Div1));
    TEST_RAM_WRITE(TimerCounter1::clock(TimerCounter1::Clock::Div8));
    TEST_RAM_WRITE(TimerCounter1::clock(TimerCounter1::Clock::Div64));
    TEST_RAM_WRITE(TimerCounter1::clock(TimerCounter1::Clock::Div256));
    TEST_RAM_WRITE(TimerCounter1::clock(TimerCounter1::Clock::Div1024));
    TEST_RAM_WRITE(TimerCounter1::clock(TimerCounter1::Clock::ExtFalling));
    TEST_RAM_WRITE(TimerCounter1::clock(TimerCounter1::Clock::ExtRising));
}

TEST(TimerCounter2, clock) {
    TEST_RAM_WRITE(TimerCounter2::clock(TimerCounter2::Clock::None));
    TEST_RAM_WRITE(TimerCounter2::clock(TimerCounter2::Clock::Div1));
    TEST_RAM_WRITE(TimerCounter2::clock(TimerCounter2::Clock::Div8));
    TEST_RAM_WRITE(TimerCounter2::clock(TimerCounter2::Clock::Div32));
    TEST_RAM_WRITE(TimerCounter2::clock(TimerCounter2::Clock::Div64));
    TEST_RAM_WRITE(TimerCounter2::clock(TimerCounter2::Clock::Div128));
    TEST_RAM_WRITE(TimerCounter2::clock(TimerCounter2::Clock::Div256));
    TEST_RAM_WRITE(TimerCounter2::clock(TimerCounter2::Clock::Div1024));
}

TEST(TimerCounter1, waveform) {
    TEST_RAM_WRITE(TimerCounter1::waveform(TimerCounter1::Waveform::Normal));
    TEST_RAM_WRITE(TimerCounter1::waveform(TimerCounter1::Waveform::PWM));
    TEST_RAM_WRITE(TimerCounter1::waveform(TimerCounter1::Waveform::CTCOCRA));
    TEST_RAM_WRITE(TimerCounter1::waveform(TimerCounter1::Waveform::FastPWM));
    TEST_RAM_WRITE(TimerCounter1::waveform(TimerCounter1::Waveform::PWMOCRA));
    TEST_RAM_WRITE(TimerCounter1::waveform(TimerCounter1::Waveform::FastPWMOCRA));
}

TEST(TimerCounter2, waveform) {
    TEST_RAM_WRITE(TimerCounter2::waveform(TimerCounter2::Waveform::Normal));
    TEST_RAM_WRITE(TimerCounter2::waveform(TimerCounter2::Waveform::PWM));
    TEST_RAM_WRITE(TimerCounter2::waveform(TimerCounter2::Waveform::CTCOCRA));
    TEST_RAM_WRITE(TimerCounter2::waveform(TimerCounter2::Waveform::FastPWM));
}

INCLUDE_TIMERCOUNTER_OVERFLOW_CALLBACK(0);
INCLUDE_TIMERCOUNTER_OVERFLOW_CALLBACK(1);
INCLUDE_TIMERCOUNTER_OVERFLOW_CALLBACK(2);

TEST(TimerCounter0, overflowCallback) {
    TEST_RAM_WRITE(TimerCounter0::overflowCallback(func,&data));
}

TEST(TimerCounter1, overflowCallback) {
    TEST_RAM_WRITE(TimerCounter1::overflowCallback(func,&data));
}

TEST(TimerCounter2, overflowCallback) {
    TEST_RAM_WRITE(TimerCounter2::overflowCallback(func,&data));
}

TEST(TimerCounter0, overflowIntEnable) {
    TEST_RAM_WRITE(TimerCounter0::overflowIntEnable(true));
    TEST_RAM_WRITE(TimerCounter0::overflowIntEnable(false));
}

TEST(TimerCounter1, overflowIntEnable) {
    TEST_RAM_WRITE(TimerCounter1::overflowIntEnable(true));
    TEST_RAM_WRITE(TimerCounter1::overflowIntEnable(false));
}

TEST(TimerCounter2, overflowIntEnable) {
    TEST_RAM_WRITE(TimerCounter2::overflowIntEnable(true));
    TEST_RAM_WRITE(TimerCounter2::overflowIntEnable(false));
}

TEST(TimerCounter0, overflowIntFlag) {
    TEST_RAM_READ_WRITE(TimerCounter0::overflowIntFlag());
}

TEST(TimerCounter1, overflowIntFlag) {
    TEST_RAM_READ_WRITE(TimerCounter1::overflowIntFlag());
}

TEST(TimerCounter2, overflowIntFlag) {
    TEST_RAM_READ_WRITE(TimerCounter2::overflowIntFlag());
}

TEST(TimerCounter0, overflowIntFlagClear) {
    TEST_RAM_WRITE(TimerCounter0::overflowIntFlagClear());
}

TEST(TimerCounter1, overflowIntFlagClear) {
    TEST_RAM_WRITE(TimerCounter1::overflowIntFlagClear());
}

TEST(TimerCounter2, overflowIntFlagClear) {
    TEST_RAM_WRITE(TimerCounter2::overflowIntFlagClear());
}

TEST(TimerCounter1, outputX) {
    TEST_RAM_WRITE(TimerCounter1::OutputCompareA::value(0x3c3c));
    TEST_RAM_READ_WRITE(TimerCounter1::OutputCompareA::value());
    TEST_RAM_WRITE(TimerCounter1::OutputCompareB::value(0x3c3c));
    TEST_RAM_READ_WRITE(TimerCounter1::OutputCompareB::value());
}

TEST(TimerCounter2, outputX) {
    TEST_RAM_WRITE(TimerCounter2::OutputCompareA::value(0x3c));
    TEST_RAM_READ_WRITE(TimerCounter2::OutputCompareA::value());
}

TEST(TimerCounter1, outputXMode) {
    TEST_RAM_WRITE(TimerCounter1::OutputCompareA::mode(TimerCounter1::OutputMode::Disconnected));
    TEST_RAM_WRITE(TimerCounter1::OutputCompareA::mode(TimerCounter1::OutputMode::Toggle));
    TEST_RAM_WRITE(TimerCounter1::OutputCompareA::mode(TimerCounter1::OutputMode::Clear));
    TEST_RAM_WRITE(TimerCounter1::OutputCompareA::mode(TimerCounter1::OutputMode::Set));
    TEST_RAM_WRITE(TimerCounter1::OutputCompareB::mode(TimerCounter1::OutputMode::Disconnected));
    TEST_RAM_WRITE(TimerCounter1::OutputCompareB::mode(TimerCounter1::OutputMode::Toggle));
    TEST_RAM_WRITE(TimerCounter1::OutputCompareB::mode(TimerCounter1::OutputMode::Clear));
    TEST_RAM_WRITE(TimerCounter1::OutputCompareB::mode(TimerCounter1::OutputMode::Set));
}

TEST(TimerCounter2, outputXMode) {
    TEST_RAM_WRITE(TimerCounter2::OutputCompareA::mode(TimerCounter2::OutputMode::Disconnected));
    TEST_RAM_WRITE(TimerCounter2::OutputCompareA::mode(TimerCounter2::OutputMode::Toggle));
    TEST_RAM_WRITE(TimerCounter2::OutputCompareA::mode(TimerCounter2::OutputMode::Clear));
    TEST_RAM_WRITE(TimerCounter2::OutputCompareA::mode(TimerCounter2::OutputMode::Set));
}

//------------------------------------------------
// Usart

INCLUDE_USART_CALLBACK(0, RX);
INCLUDE_USART_CALLBACK(0, TX);
INCLUDE_USART_CALLBACK(0, DE);

TEST(Usart0, getHardwareType) {
    ASSERT_EQ(Usart0::getHardwareType(), HardwareType::Usart);
}

TEST(Usart0, mode) {
    TEST_RAM_WRITE(Usart0::mode(Usart0::Mode::Asynchronous));
    TEST_RAM_WRITE(Usart0::mode(Usart0::Mode::Synchronous));
}

TEST(Usart0, parity) {
    TEST_RAM_WRITE(Usart0::parity(Usart0::Parity::Disabled));
    TEST_RAM_WRITE(Usart0::parity(Usart0::Parity::Even));
    TEST_RAM_WRITE(Usart0::parity(Usart0::Parity::Odd));
}

TEST(Usart0, stopBits) {
    TEST_RAM_WRITE(Usart0::stopBits(Usart0::StopBits::Bits1));
    TEST_RAM_WRITE(Usart0::stopBits(Usart0::StopBits::Bits2));
}

TEST(Usart0, characterSize) {
    TEST_RAM_WRITE(Usart0::characterSize(Usart0::CharacterSize::Size5));
    TEST_RAM_WRITE(Usart0::characterSize(Usart0::CharacterSize::Size6));
    TEST_RAM_WRITE(Usart0::characterSize(Usart0::CharacterSize::Size7));
    TEST_RAM_WRITE(Usart0::characterSize(Usart0::CharacterSize::Size8));
    TEST_RAM_WRITE(Usart0::characterSize(Usart0::CharacterSize::Size9));
}

TEST(Usart0, polarity) {
    TEST_RAM_WRITE(Usart0::polarity(Usart0::Polarity::TxRisingRxFalling));
    TEST_RAM_WRITE(Usart0::polarity(Usart0::Polarity::TxFallingRxRising));
}

TEST(Usart0, baud) {
    TEST_RAM_WRITE(Usart0::baud(0xe819));
}

TEST(Usart0, use2X) {
    TEST_RAM_WRITE(Usart0::use2X(true));
    TEST_RAM_WRITE(Usart0::use2X(false));
}

TEST(Usart0, receiverEnable) {
    TEST_RAM_WRITE(Usart0::receiverEnable(true));
    TEST_RAM_WRITE(Usart0::receiverEnable(false));
}

TEST(Usart0, transmitterEnable) {
    TEST_RAM_WRITE(Usart0::transmitterEnable(true));
    TEST_RAM_WRITE(Usart0::transmitterEnable(false));
}

TEST(Usart0, multiprocessorCummunicationMode) {
    TEST_RAM_WRITE(Usart0::multiprocessorCummunicationMode(true));
    TEST_RAM_WRITE(Usart0::multiprocessorCummunicationMode(false));
}

TEST(Usart0, rxCompleteIntEnable) {
    TEST_RAM_WRITE(Usart0::rxCompleteIntEnable(true));
    TEST_RAM_WRITE(Usart0::rxCompleteIntEnable(false));
}

TEST(Usart0, txCompleteIntEnable) {
    TEST_RAM_WRITE(Usart0::txCompleteIntEnable(true));
    TEST_RAM_WRITE(Usart0::txCompleteIntEnable(false));
}

TEST(Usart0, dataRegisterEmptyIntEnable) {
    TEST_RAM_WRITE(Usart0::dataRegisterEmptyIntEnable(true));
    TEST_RAM_WRITE(Usart0::dataRegisterEmptyIntEnable(false));
}

TEST(Usart0, rxCompleteCallback) {
    TEST_RAM_WRITE(Usart0::rxCompleteCallback(func,data));
}

TEST(Usart0, txCompleteCallback) {
    TEST_RAM_WRITE(Usart0::txCompleteCallback(func,data));
}

TEST(Usart0, dataRegisterEmptyCallback) {
    TEST_RAM_WRITE(Usart0::dataRegisterEmptyCallback(func,data));
}

TEST(Usart0, push) {
    TEST_RAM_WRITE(Usart0::push(0x18));
}

TEST(Usart0, push9) {
    TEST_RAM_WRITE(Usart0::push9(0x3261));
}

TEST(Usart0, pop) {
    TEST_RAM_READ_WRITE(Usart0::pop());
}

TEST(Usart0, pop9) {
    TEST_RAM_READ_WRITE(Usart0::pop9());
}

TEST(Usart0, frameError) {
    TEST_RAM_READ_WRITE(Usart0::frameError());
}

TEST(Usart0, frameErrorClear) {
    TEST_RAM_WRITE(Usart0::frameErrorClear());
}

TEST(Usart0, dataOverRun) {
    TEST_RAM_READ_WRITE(Usart0::dataOverRun());
}

TEST(Usart0, dataOverRunClear) {
    TEST_RAM_WRITE(Usart0::dataOverRunClear());
}

TEST(Usart0, parityError) {
    TEST_RAM_READ_WRITE(Usart0::parityError());
}

TEST(Usart0, parityErrorClear) {
    TEST_RAM_WRITE(Usart0::parityErrorClear());
}
