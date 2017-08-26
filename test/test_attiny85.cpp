#define __AVR_ATtiny85__

#define RECORD_ID "attiny85"

#include "test.hpp"

typedef void (*ft)(void*);

static ft func = (ft)0x1234;
static void* data = (void*)0x5678;

//------------------------------------------------
// Analog to Digital

INCLUDE_ADC_CALLBACK();

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
    TEST_REG_WRITE(Adc::channel(Adc::Channel::VBG));
    TEST_REG_WRITE(Adc::channel(Adc::Channel::GND));
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
    // TEST_REG_WRITE(Adc::trigger(Adc::Trigger::Timer0CompareMatchB));
    // TEST_REG_WRITE(Adc::trigger(Adc::Trigger::PinChangeInterrupt));
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

TEST(ExIntN, getHardwareType) {
    ASSERT_EQ(ExInt0::getHardwareType(), HardwareType::ExInt);
}

TEST(ExIntN, enable) {
    TEST_REG_WRITE(ExInt0::enable(true));
    TEST_REG_WRITE(ExInt0::enable(false));
}

TEST(ExIntN, trigger) {
    TEST_REG_WRITE(ExInt0::trigger(ExInt0::Trigger::Low));
    TEST_REG_WRITE(ExInt0::trigger(ExInt0::Trigger::Change));
    TEST_REG_WRITE(ExInt0::trigger(ExInt0::Trigger::Falling));
    TEST_REG_WRITE(ExInt0::trigger(ExInt0::Trigger::Rising));
}

TEST(ExIntN, callback) {
    TEST_REG_WRITE(ExInt0::callback(func,data));
}

TEST(ExIntN, intFlag) {
    TEST_REG_READ_WRITE(ExInt0::intFlag());
}

TEST(ExIntN, intFlagClear) {
    TEST_REG_WRITE(ExInt0::intFlagClear());
}

//------------------------------------------------
// Pin Change Interrupts

INCLUDE_PCINT_CALLBACK(0);

TEST(PcIntN, getHardwareType) {
    ASSERT_EQ(PcInt0::getHardwareType(), HardwareType::PcInt);
}

TEST(PcIntN, enable) {
    TEST_REG_WRITE(PcInt0::enable(true));
    TEST_REG_WRITE(PcInt0::enable(false));
}

TEST(PcIntN, mask) {
    TEST_REG_WRITE(PcInt0::mask(0x64));
}

TEST(PcIntN, callback) {
    TEST_REG_WRITE(PcInt0::callback(func,data));
}

TEST(PcIntN, intFlag) {
    TEST_REG_READ_WRITE(PcInt0::intFlag());
}

TEST(PcIntN, intFlagClear) {
    TEST_REG_WRITE(PcInt0::intFlagClear());
}

//------------------------------------------------
// Digital Pins

TEST(PinXN, getHardwareType) {
    ASSERT_EQ(PinB0::getHardwareType(), HardwareType::Pin);
    ASSERT_EQ(PinB5::getHardwareType(), HardwareType::Pin);
}

TEST(PinXN, direction) {
    TEST_REG_WRITE(PinB0::direction(Direction::Input));
    TEST_REG_WRITE(PinB0::direction(Direction::Output));
    TEST_REG_READ_WRITE(PinB0::direction());
}

TEST(PinXN, pullup) {
    TEST_REG_WRITE(PinB1::pullup(true));
    TEST_REG_WRITE(PinB1::pullup(false));
    TEST_REG_READ_WRITE(PinB1::pullup());
}

TEST(PinXN, output) {
    TEST_REG_READ_WRITE(PinB2::output());
}

TEST(PinXN, input) {
    TEST_REG_READ_WRITE(PinB3::input());
}

TEST(PinXN, toggle) {
    TEST_REG_WRITE(PinB4::toggle());
}

//------------------------------------------------
// Digital Ports

TEST(PortX, getHardwareType) {
    ASSERT_EQ(PortB::getHardwareType(), HardwareType::Port);
}

TEST(PortX, direction) {
    TEST_REG_WRITE(PortB::direction(0x3c));
    TEST_REG_READ_WRITE(PortB::direction());
}

TEST(PortX, pullup) {
    TEST_REG_WRITE(PortB::pullup(0x12));
    TEST_REG_READ_WRITE(PortB::pullup());
}

TEST(PortX, output) {
    TEST_REG_WRITE(PortB::output(0x27));
    TEST_REG_READ_WRITE(PortB::output());
}

TEST(PortX, input) {
    TEST_REG_READ_WRITE(PortB::input());
}

TEST(PortX, toggle) {
    TEST_REG_WRITE(PortB::toggle(0x26));
}

//------------------------------------------------
// Timer/Counters

INCLUDE_TIMERCOUNTER_OVERFLOW_CALLBACK(0);
INCLUDE_TIMERCOUNTER_OUTPUT_CALLBACK(0, A);
INCLUDE_TIMERCOUNTER_OUTPUT_CALLBACK(0, B);

INCLUDE_TIMERCOUNTER_OVERFLOW_CALLBACK(1);
INCLUDE_TIMERCOUNTER_OUTPUT_CALLBACK(1, A);
INCLUDE_TIMERCOUNTER_OUTPUT_CALLBACK(1, B);

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
    ::testing::StaticAssertTypeEq<TimerCounter1::type, uint8_t>();
}

TEST(TimerCounter1, counter) {
    TEST_REG_WRITE(TimerCounter1::counter(0x8a));
    TEST_REG_READ_WRITE(TimerCounter1::counter());
}

TEST(TimerCounter1, clock) {
    TEST_REG_WRITE(TimerCounter1::clock(TimerCounter1::Clock::None));
    TEST_REG_WRITE(TimerCounter1::clock(TimerCounter1::Clock::Div1));
    // TEST_REG_WRITE(TimerCounter1::clock(TimerCounter1::Clock::Div2));
    // TEST_REG_WRITE(TimerCounter1::clock(TimerCounter1::Clock::Div4));
    TEST_REG_WRITE(TimerCounter1::clock(TimerCounter1::Clock::Div8));
    // TEST_REG_WRITE(TimerCounter1::clock(TimerCounter1::Clock::Div16));
    // TEST_REG_WRITE(TimerCounter1::clock(TimerCounter1::Clock::Div32));
    TEST_REG_WRITE(TimerCounter1::clock(TimerCounter1::Clock::Div64));
    // TEST_REG_WRITE(TimerCounter1::clock(TimerCounter1::Clock::Div128));
    TEST_REG_WRITE(TimerCounter1::clock(TimerCounter1::Clock::Div256));
    // TEST_REG_WRITE(TimerCounter1::clock(TimerCounter1::Clock::Div512));
    TEST_REG_WRITE(TimerCounter1::clock(TimerCounter1::Clock::Div1024));
    // TEST_REG_WRITE(TimerCounter1::clock(TimerCounter1::Clock::Div2048));
    // TEST_REG_WRITE(TimerCounter1::clock(TimerCounter1::Clock::Div4096));
    // TEST_REG_WRITE(TimerCounter1::clock(TimerCounter1::Clock::Div8192));
    // TEST_REG_WRITE(TimerCounter1::clock(TimerCounter1::Clock::Div16384));
}

TEST(TimerCounter1, waveform) {
    TEST_REG_WRITE(TimerCounter1::waveform(TimerCounter1::Waveform::Normal));
    TEST_REG_WRITE(TimerCounter1::waveform(TimerCounter1::Waveform::CTCOCRA));
    // TODO Check if it should be fast or phase correct PWM.
    // TEST_REG_WRITE(TimerCounter1::waveform(TimerCounter1::Waveform::PWMOCRA));
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
    TEST_REG_WRITE(TimerCounter1::OutputCompareA::value(0xd9));
    TEST_REG_READ_WRITE(TimerCounter1::OutputCompareA::value());
}

TEST(TimerCounter1, outputB) {
    TEST_REG_WRITE(TimerCounter1::OutputCompareB::value(0x8d));
    TEST_REG_READ_WRITE(TimerCounter1::OutputCompareB::value());
}

TEST(TimerCounter1, outputC) {
    TEST_REG_WRITE(TimerCounter1::OutputCompareC::value(0x15));
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

TEST(TimerCounter1, outputACallback) {
    TEST_REG_WRITE(TimerCounter1::OutputCompareA::callback(func,data));
}

TEST(TimerCounter1, outputBCallback) {
    TEST_REG_WRITE(TimerCounter1::OutputCompareB::callback(func,data));
}

TEST(TimerCounter1, outputAIntEnable) {
    TEST_REG_WRITE(TimerCounter1::OutputCompareA::intEnable(true));
    TEST_REG_WRITE(TimerCounter1::OutputCompareA::intEnable(false));
}

TEST(TimerCounter1, outputBIntEnable) {
    TEST_REG_WRITE(TimerCounter1::OutputCompareB::intEnable(true));
    TEST_REG_WRITE(TimerCounter1::OutputCompareB::intEnable(false));
}

TEST(TimerCounter1, outputAIntFlag) {
    TEST_REG_READ_WRITE(TimerCounter1::OutputCompareA::intFlag());
}

TEST(TimerCounter1, outputBIntFlag) {
    TEST_REG_READ_WRITE(TimerCounter1::OutputCompareB::intFlag());
}

TEST(TimerCounter1, outputAIntFlagClear) {
    TEST_REG_WRITE(TimerCounter1::OutputCompareA::intFlagClear());
}

TEST(TimerCounter1, outputBIntFlagClear) {
    TEST_REG_WRITE(TimerCounter1::OutputCompareB::intFlagClear());
}

//------------------------------------------------
// Usart

// TODO Work out how to integrate the USI into nbavr.

// INCLUDE_USART_CALLBACK(0, RX);
// INCLUDE_USART_CALLBACK(0, TX);
// INCLUDE_USART_CALLBACK(0, DE);

// TEST(Usart0, getHardwareType) {
//     ASSERT_EQ(Usart0::getHardwareType(), HardwareType::Usart);
// }
//
// TEST(Usart0, mode) {
//     TEST_REG_WRITE(Usart0::mode(Usart0::Mode::Asynchronous));
//     TEST_REG_WRITE(Usart0::mode(Usart0::Mode::Synchronous));
//     TEST_REG_WRITE(Usart0::mode(Usart0::Mode::MasterSpi));
// }
//
// TEST(Usart0, parity) {
//     TEST_REG_WRITE(Usart0::parity(Usart0::Parity::Disabled));
//     TEST_REG_WRITE(Usart0::parity(Usart0::Parity::Even));
//     TEST_REG_WRITE(Usart0::parity(Usart0::Parity::Odd));
// }
//
// TEST(Usart0, stopBits) {
//     TEST_REG_WRITE(Usart0::stopBits(Usart0::StopBits::Bits1));
//     TEST_REG_WRITE(Usart0::stopBits(Usart0::StopBits::Bits2));
// }
//
// TEST(Usart0, characterSize) {
//     TEST_REG_WRITE(Usart0::characterSize(Usart0::CharacterSize::Size5));
//     TEST_REG_WRITE(Usart0::characterSize(Usart0::CharacterSize::Size6));
//     TEST_REG_WRITE(Usart0::characterSize(Usart0::CharacterSize::Size7));
//     TEST_REG_WRITE(Usart0::characterSize(Usart0::CharacterSize::Size8));
//     TEST_REG_WRITE(Usart0::characterSize(Usart0::CharacterSize::Size9));
// }
//
// TEST(Usart0, polarity) {
//     TEST_REG_WRITE(Usart0::polarity(Usart0::Polarity::TxRisingRxFalling));
//     TEST_REG_WRITE(Usart0::polarity(Usart0::Polarity::TxFallingRxRising));
// }
//
// TEST(Usart0, baud) {
//     TEST_REG_WRITE(Usart0::baud(0xe819));
// }
//
// TEST(Usart0, use2X) {
//     TEST_REG_WRITE(Usart0::use2X(true));
//     TEST_REG_WRITE(Usart0::use2X(false));
// }
//
// TEST(Usart0, receiverEnable) {
//     TEST_REG_WRITE(Usart0::receiverEnable(true));
//     TEST_REG_WRITE(Usart0::receiverEnable(false));
// }
//
// TEST(Usart0, transmitterEnable) {
//     TEST_REG_WRITE(Usart0::transmitterEnable(true));
//     TEST_REG_WRITE(Usart0::transmitterEnable(false));
// }
//
// TEST(Usart0, multiprocessorCummunicationMode) {
//     TEST_REG_WRITE(Usart0::multiprocessorCummunicationMode(true));
//     TEST_REG_WRITE(Usart0::multiprocessorCummunicationMode(false));
// }
//
// TEST(Usart0, rxCompleteIntEnable) {
//     TEST_REG_WRITE(Usart0::rxCompleteIntEnable(true));
//     TEST_REG_WRITE(Usart0::rxCompleteIntEnable(false));
// }
//
// TEST(Usart0, txCompleteIntEnable) {
//     TEST_REG_WRITE(Usart0::txCompleteIntEnable(true));
//     TEST_REG_WRITE(Usart0::txCompleteIntEnable(false));
// }
//
// TEST(Usart0, dataRegisterEmptyIntEnable) {
//     TEST_REG_WRITE(Usart0::dataRegisterEmptyIntEnable(true));
//     TEST_REG_WRITE(Usart0::dataRegisterEmptyIntEnable(false));
// }
//
// TEST(Usart0, rxCompleteCallback) {
//     TEST_REG_WRITE(Usart0::rxCompleteCallback(func,data));
// }
//
// TEST(Usart0, txCompleteCallback) {
//     TEST_REG_WRITE(Usart0::txCompleteCallback(func,data));
// }
//
// TEST(Usart0, dataRegisterEmptyCallback) {
//     TEST_REG_WRITE(Usart0::dataRegisterEmptyCallback(func,data));
// }
//
// TEST(Usart0, push) {
//     TEST_REG_WRITE(Usart0::push(0x18));
// }
//
// TEST(Usart0, push9) {
//     TEST_REG_WRITE(Usart0::push9(0x3261));
// }
//
// TEST(Usart0, pop) {
//     TEST_REG_READ_WRITE(Usart0::pop());
// }
//
// TEST(Usart0, pop9) {
//     TEST_REG_READ_WRITE(Usart0::pop9());
// }
//
// TEST(Usart0, frameError) {
//     TEST_REG_READ_WRITE(Usart0::frameError());
// }
//
// TEST(Usart0, frameErrorClear) {
//     TEST_REG_WRITE(Usart0::frameErrorClear());
// }
//
// TEST(Usart0, dataOverRun) {
//     TEST_REG_READ_WRITE(Usart0::dataOverRun());
// }
//
// TEST(Usart0, dataOverRunClear) {
//     TEST_REG_WRITE(Usart0::dataOverRunClear());
// }
//
// TEST(Usart0, parityError) {
//     TEST_REG_READ_WRITE(Usart0::parityError());
// }
//
// TEST(Usart0, parityErrorClear) {
//     TEST_REG_WRITE(Usart0::parityErrorClear());
// }
