#define __atmega2560__

#define RECORD_ID "atmega2560"

#include "test.hpp"

typedef void (*ft)(void*);

static ft func = (ft)0x1234;
static void* data = (void*)0x5678;

//------------------------------------------------
// Analog to Digital

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
    TEST_REG_WRITE(Adc0::reference(Adc0::Reference::aref));
    TEST_REG_WRITE(Adc0::reference(Adc0::Reference::avcc));
    TEST_REG_WRITE(Adc0::reference(Adc0::Reference::internal));
}

TEST(Adc, channel) {
    TEST_REG_WRITE(Adc0::channel(Adc0::Channel::adc0));
    TEST_REG_WRITE(Adc0::channel(Adc0::Channel::adc1));
    TEST_REG_WRITE(Adc0::channel(Adc0::Channel::adc2));
    TEST_REG_WRITE(Adc0::channel(Adc0::Channel::adc3));
    TEST_REG_WRITE(Adc0::channel(Adc0::Channel::adc4));
    TEST_REG_WRITE(Adc0::channel(Adc0::Channel::adc5));
    TEST_REG_WRITE(Adc0::channel(Adc0::Channel::adc6));
    TEST_REG_WRITE(Adc0::channel(Adc0::Channel::adc7));
    // TEST_REG_WRITE(Adc0::channel(Adc0::Channel::adc8));
    // TEST_REG_WRITE(Adc0::channel(Adc0::Channel::vbg));
    // TEST_REG_WRITE(Adc0::channel(Adc0::Channel::gnd));
}

TEST(Adc, prescaler) {
    TEST_REG_WRITE(Adc0::prescaler(Adc0::Prescaler::div2));
    TEST_REG_WRITE(Adc0::prescaler(Adc0::Prescaler::div4));
    TEST_REG_WRITE(Adc0::prescaler(Adc0::Prescaler::div8));
    TEST_REG_WRITE(Adc0::prescaler(Adc0::Prescaler::div16));
    TEST_REG_WRITE(Adc0::prescaler(Adc0::Prescaler::div32));
    TEST_REG_WRITE(Adc0::prescaler(Adc0::Prescaler::div64));
    TEST_REG_WRITE(Adc0::prescaler(Adc0::Prescaler::div128));
}

TEST(Adc, leftAdjust) {
    TEST_REG_WRITE(Adc0::leftAdjust(true));
    TEST_REG_WRITE(Adc0::leftAdjust(false));
}

TEST(Adc, trigger) {
    TEST_REG_WRITE(Adc0::trigger(Adc0::Trigger::singleConversion));
    TEST_REG_WRITE(Adc0::trigger(Adc0::Trigger::freeRunning));
    TEST_REG_WRITE(Adc0::trigger(Adc0::Trigger::analogComparator));
    TEST_REG_WRITE(Adc0::trigger(Adc0::Trigger::externalInt0));
    TEST_REG_WRITE(Adc0::trigger(Adc0::Trigger::timer0CompareMatchA));
    TEST_REG_WRITE(Adc0::trigger(Adc0::Trigger::timer0Overflow));
    TEST_REG_WRITE(Adc0::trigger(Adc0::Trigger::timer1CompareMatchB));
    TEST_REG_WRITE(Adc0::trigger(Adc0::Trigger::timer1Overflow));
    TEST_REG_WRITE(Adc0::trigger(Adc0::Trigger::timer1CaptureEvent));
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

TEST(ExIntN, intEnable) {
    TEST_REG_WRITE(ExInt0::intEnable(true));
    TEST_REG_WRITE(ExInt0::intEnable(false));
    TEST_REG_WRITE(ExInt1::intEnable(true));
    TEST_REG_WRITE(ExInt1::intEnable(false));
    TEST_REG_WRITE(ExInt2::intEnable(true));
    TEST_REG_WRITE(ExInt2::intEnable(false));
    TEST_REG_WRITE(ExInt3::intEnable(true));
    TEST_REG_WRITE(ExInt3::intEnable(false));
    TEST_REG_WRITE(ExInt4::intEnable(true));
    TEST_REG_WRITE(ExInt4::intEnable(false));
    TEST_REG_WRITE(ExInt5::intEnable(true));
    TEST_REG_WRITE(ExInt5::intEnable(false));
    TEST_REG_WRITE(ExInt6::intEnable(true));
    TEST_REG_WRITE(ExInt6::intEnable(false));
    TEST_REG_WRITE(ExInt7::intEnable(true));
    TEST_REG_WRITE(ExInt7::intEnable(false));
}

TEST(ExIntN, trigger) {
    TEST_REG_WRITE(ExInt0::trigger(ExInt0::Trigger::low));
    TEST_REG_WRITE(ExInt0::trigger(ExInt0::Trigger::change));
    TEST_REG_WRITE(ExInt0::trigger(ExInt0::Trigger::falling));
    TEST_REG_WRITE(ExInt0::trigger(ExInt0::Trigger::rising));

    TEST_REG_WRITE(ExInt1::trigger(ExInt1::Trigger::low));
    TEST_REG_WRITE(ExInt1::trigger(ExInt1::Trigger::change));
    TEST_REG_WRITE(ExInt1::trigger(ExInt1::Trigger::falling));
    TEST_REG_WRITE(ExInt1::trigger(ExInt1::Trigger::rising));

    TEST_REG_WRITE(ExInt2::trigger(ExInt2::Trigger::low));
    TEST_REG_WRITE(ExInt2::trigger(ExInt2::Trigger::change));
    TEST_REG_WRITE(ExInt2::trigger(ExInt2::Trigger::falling));
    TEST_REG_WRITE(ExInt2::trigger(ExInt2::Trigger::rising));

    TEST_REG_WRITE(ExInt3::trigger(ExInt3::Trigger::low));
    TEST_REG_WRITE(ExInt3::trigger(ExInt3::Trigger::change));
    TEST_REG_WRITE(ExInt3::trigger(ExInt3::Trigger::falling));
    TEST_REG_WRITE(ExInt3::trigger(ExInt3::Trigger::rising));

    TEST_REG_WRITE(ExInt4::trigger(ExInt4::Trigger::low));
    TEST_REG_WRITE(ExInt4::trigger(ExInt4::Trigger::change));
    TEST_REG_WRITE(ExInt4::trigger(ExInt4::Trigger::falling));
    TEST_REG_WRITE(ExInt4::trigger(ExInt4::Trigger::rising));

    TEST_REG_WRITE(ExInt5::trigger(ExInt5::Trigger::low));
    TEST_REG_WRITE(ExInt5::trigger(ExInt5::Trigger::change));
    TEST_REG_WRITE(ExInt5::trigger(ExInt5::Trigger::falling));
    TEST_REG_WRITE(ExInt5::trigger(ExInt5::Trigger::rising));

    TEST_REG_WRITE(ExInt6::trigger(ExInt6::Trigger::low));
    TEST_REG_WRITE(ExInt6::trigger(ExInt6::Trigger::change));
    TEST_REG_WRITE(ExInt6::trigger(ExInt6::Trigger::falling));
    TEST_REG_WRITE(ExInt6::trigger(ExInt6::Trigger::rising));

    TEST_REG_WRITE(ExInt7::trigger(ExInt7::Trigger::low));
    TEST_REG_WRITE(ExInt7::trigger(ExInt7::Trigger::change));
    TEST_REG_WRITE(ExInt7::trigger(ExInt7::Trigger::falling));
    TEST_REG_WRITE(ExInt7::trigger(ExInt7::Trigger::rising));
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

TEST(PcIntN, getHardwareType) {
    ASSERT_EQ(PcInt0::getHardwareType(), HardwareType::pcInt);
    ASSERT_EQ(PcInt1::getHardwareType(), HardwareType::pcInt);
    ASSERT_EQ(PcInt2::getHardwareType(), HardwareType::pcInt);
}

TEST(PcIntN, intEnable) {
    TEST_REG_WRITE(PcInt0::intEnable(true));
    TEST_REG_WRITE(PcInt0::intEnable(false));
    TEST_REG_WRITE(PcInt1::intEnable(true));
    TEST_REG_WRITE(PcInt1::intEnable(false));
    TEST_REG_WRITE(PcInt2::intEnable(true));
    TEST_REG_WRITE(PcInt2::intEnable(false));
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
    TEST_REG_WRITE(Timer0::clock(Timer0::Clock::none));
    TEST_REG_WRITE(Timer0::clock(Timer0::Clock::div1));
    TEST_REG_WRITE(Timer0::clock(Timer0::Clock::div8));
    TEST_REG_WRITE(Timer0::clock(Timer0::Clock::div64));
    TEST_REG_WRITE(Timer0::clock(Timer0::Clock::div256));
    TEST_REG_WRITE(Timer0::clock(Timer0::Clock::div1024));
    TEST_REG_WRITE(Timer0::clock(Timer0::Clock::extFalling));
    TEST_REG_WRITE(Timer0::clock(Timer0::Clock::extRising));
}

TEST(Timer0, waveform) {
    TEST_REG_WRITE(Timer0::waveform(Timer0::Waveform::normal));
    TEST_REG_WRITE(Timer0::waveform(Timer0::Waveform::pwm));
    TEST_REG_WRITE(Timer0::waveform(Timer0::Waveform::ctcOcra));
    TEST_REG_WRITE(Timer0::waveform(Timer0::Waveform::fastPwm));
    TEST_REG_WRITE(Timer0::waveform(Timer0::Waveform::pwmOcra));
    TEST_REG_WRITE(Timer0::waveform(Timer0::Waveform::fastPwmOcra));
}

TEST(Timer0, callback) {
    TEST_REG_WRITE(Timer0::callback(func,data));
}

TEST(Timer0, intEnable) {
    TEST_REG_WRITE(Timer0::intEnable(true));
    TEST_REG_WRITE(Timer0::intEnable(false));
}

TEST(Timer0, intFlag) {
    TEST_REG_READ_WRITE(Timer0::intFlag());
}

TEST(Timer0, intFlagClear) {
    TEST_REG_WRITE(Timer0::intFlagClear());
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
    TEST_REG_WRITE(Timer0::OutputA::mode(Timer0::OutputA::Mode::disconnected));
    TEST_REG_WRITE(Timer0::OutputA::mode(Timer0::OutputA::Mode::toggle));
    TEST_REG_WRITE(Timer0::OutputA::mode(Timer0::OutputA::Mode::clear));
    TEST_REG_WRITE(Timer0::OutputA::mode(Timer0::OutputA::Mode::set));
}

TEST(Timer0, outputBMode) {
    TEST_REG_WRITE(Timer0::OutputB::mode(Timer0::OutputB::Mode::disconnected));
    TEST_REG_WRITE(Timer0::OutputB::mode(Timer0::OutputB::Mode::toggle));
    TEST_REG_WRITE(Timer0::OutputB::mode(Timer0::OutputB::Mode::clear));
    TEST_REG_WRITE(Timer0::OutputB::mode(Timer0::OutputB::Mode::set));
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
    TEST_REG_WRITE(Timer1::clock(Timer1::Clock::none));
    TEST_REG_WRITE(Timer1::clock(Timer1::Clock::div1));
    TEST_REG_WRITE(Timer1::clock(Timer1::Clock::div8));
    TEST_REG_WRITE(Timer1::clock(Timer1::Clock::div64));
    TEST_REG_WRITE(Timer1::clock(Timer1::Clock::div256));
    TEST_REG_WRITE(Timer1::clock(Timer1::Clock::div1024));
    TEST_REG_WRITE(Timer1::clock(Timer1::Clock::extFalling));
    TEST_REG_WRITE(Timer1::clock(Timer1::Clock::extRising));
}

TEST(Timer1, waveform) {
    TEST_REG_WRITE(Timer1::waveform(Timer1::Waveform::normal));
    TEST_REG_WRITE(Timer1::waveform(Timer1::Waveform::pwm));
    TEST_REG_WRITE(Timer1::waveform(Timer1::Waveform::ctcOcra));
    TEST_REG_WRITE(Timer1::waveform(Timer1::Waveform::fastPwm));
    TEST_REG_WRITE(Timer1::waveform(Timer1::Waveform::pwmOcra));
    TEST_REG_WRITE(Timer1::waveform(Timer1::Waveform::fastPwmOcra));
}

TEST(Timer1, callback) {
    TEST_REG_WRITE(Timer1::callback(func,data));
}

TEST(Timer1, intEnable) {
    TEST_REG_WRITE(Timer1::intEnable(true));
    TEST_REG_WRITE(Timer1::intEnable(false));
}

TEST(Timer1, intFlag) {
    TEST_REG_READ_WRITE(Timer1::intFlag());
}

TEST(Timer1, intFlagClear) {
    TEST_REG_WRITE(Timer1::intFlagClear());
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
    TEST_REG_WRITE(Timer1::OutputA::mode(Timer1::OutputA::Mode::disconnected));
    TEST_REG_WRITE(Timer1::OutputA::mode(Timer1::OutputA::Mode::toggle));
    TEST_REG_WRITE(Timer1::OutputA::mode(Timer1::OutputA::Mode::clear));
    TEST_REG_WRITE(Timer1::OutputA::mode(Timer1::OutputA::Mode::set));
}

TEST(Timer1, outputBMode) {
    TEST_REG_WRITE(Timer1::OutputB::mode(Timer1::OutputB::Mode::disconnected));
    TEST_REG_WRITE(Timer1::OutputB::mode(Timer1::OutputB::Mode::toggle));
    TEST_REG_WRITE(Timer1::OutputB::mode(Timer1::OutputB::Mode::clear));
    TEST_REG_WRITE(Timer1::OutputB::mode(Timer1::OutputB::Mode::set));
}

TEST(Timer1, outputCMode) {
    TEST_REG_WRITE(Timer1::OutputC::mode(Timer1::OutputC::Mode::disconnected));
    TEST_REG_WRITE(Timer1::OutputC::mode(Timer1::OutputC::Mode::toggle));
    TEST_REG_WRITE(Timer1::OutputC::mode(Timer1::OutputC::Mode::clear));
    TEST_REG_WRITE(Timer1::OutputC::mode(Timer1::OutputC::Mode::set));
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
    TEST_REG_WRITE(Timer2::clock(Timer2::Clock::none));
    TEST_REG_WRITE(Timer2::clock(Timer2::Clock::div1));
    TEST_REG_WRITE(Timer2::clock(Timer2::Clock::div8));
    TEST_REG_WRITE(Timer2::clock(Timer2::Clock::div32));
    TEST_REG_WRITE(Timer2::clock(Timer2::Clock::div64));
    TEST_REG_WRITE(Timer2::clock(Timer2::Clock::div128));
    TEST_REG_WRITE(Timer2::clock(Timer2::Clock::div256));
    TEST_REG_WRITE(Timer2::clock(Timer2::Clock::div1024));
}

TEST(Timer2, waveform) {
    TEST_REG_WRITE(Timer2::waveform(Timer2::Waveform::normal));
    TEST_REG_WRITE(Timer2::waveform(Timer2::Waveform::pwm));
    TEST_REG_WRITE(Timer2::waveform(Timer2::Waveform::ctcOcra));
    TEST_REG_WRITE(Timer2::waveform(Timer2::Waveform::fastPwm));
    TEST_REG_WRITE(Timer2::waveform(Timer2::Waveform::pwmOcra));
    TEST_REG_WRITE(Timer2::waveform(Timer2::Waveform::fastPwmOcra));
}

TEST(Timer2, callback) {
    TEST_REG_WRITE(Timer2::callback(func,data));
}

TEST(Timer2, intEnable) {
    TEST_REG_WRITE(Timer2::intEnable(true));
    TEST_REG_WRITE(Timer2::intEnable(false));
}

TEST(Timer2, intFlag) {
    TEST_REG_READ_WRITE(Timer2::intFlag());
}

TEST(Timer2, intFlagClear) {
    TEST_REG_WRITE(Timer2::intFlagClear());
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
    TEST_REG_WRITE(Timer2::OutputA::mode(Timer2::OutputA::Mode::disconnected));
    TEST_REG_WRITE(Timer2::OutputA::mode(Timer2::OutputA::Mode::toggle));
    TEST_REG_WRITE(Timer2::OutputA::mode(Timer2::OutputA::Mode::clear));
    TEST_REG_WRITE(Timer2::OutputA::mode(Timer2::OutputA::Mode::set));
}

TEST(Timer2, outputBMode) {
    TEST_REG_WRITE(Timer2::OutputB::mode(Timer2::OutputB::Mode::disconnected));
    TEST_REG_WRITE(Timer2::OutputB::mode(Timer2::OutputB::Mode::toggle));
    TEST_REG_WRITE(Timer2::OutputB::mode(Timer2::OutputB::Mode::clear));
    TEST_REG_WRITE(Timer2::OutputB::mode(Timer2::OutputB::Mode::set));
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
    TEST_REG_WRITE(Timer3::clock(Timer3::Clock::none));
    TEST_REG_WRITE(Timer3::clock(Timer3::Clock::div1));
    TEST_REG_WRITE(Timer3::clock(Timer3::Clock::div8));
    TEST_REG_WRITE(Timer3::clock(Timer3::Clock::div64));
    TEST_REG_WRITE(Timer3::clock(Timer3::Clock::div256));
    TEST_REG_WRITE(Timer3::clock(Timer3::Clock::div1024));
    TEST_REG_WRITE(Timer3::clock(Timer3::Clock::extFalling));
    TEST_REG_WRITE(Timer3::clock(Timer3::Clock::extRising));
}

TEST(Timer3, waveform) {
    TEST_REG_WRITE(Timer3::waveform(Timer3::Waveform::normal));
    TEST_REG_WRITE(Timer3::waveform(Timer3::Waveform::pwm));
    TEST_REG_WRITE(Timer3::waveform(Timer3::Waveform::ctcOcra));
    TEST_REG_WRITE(Timer3::waveform(Timer3::Waveform::fastPwm));
    TEST_REG_WRITE(Timer3::waveform(Timer3::Waveform::pwmOcra));
    TEST_REG_WRITE(Timer3::waveform(Timer3::Waveform::fastPwmOcra));
}

TEST(Timer3, callback) {
    TEST_REG_WRITE(Timer3::callback(func,data));
}

TEST(Timer3, intEnable) {
    TEST_REG_WRITE(Timer3::intEnable(true));
    TEST_REG_WRITE(Timer3::intEnable(false));
}

TEST(Timer3, intFlag) {
    TEST_REG_READ_WRITE(Timer3::intFlag());
}

TEST(Timer3, intFlagClear) {
    TEST_REG_WRITE(Timer3::intFlagClear());
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
    TEST_REG_WRITE(Timer3::OutputA::mode(Timer3::OutputA::Mode::disconnected));
    TEST_REG_WRITE(Timer3::OutputA::mode(Timer3::OutputA::Mode::toggle));
    TEST_REG_WRITE(Timer3::OutputA::mode(Timer3::OutputA::Mode::clear));
    TEST_REG_WRITE(Timer3::OutputA::mode(Timer3::OutputA::Mode::set));
}

TEST(Timer3, outputBMode) {
    TEST_REG_WRITE(Timer3::OutputB::mode(Timer3::OutputB::Mode::disconnected));
    TEST_REG_WRITE(Timer3::OutputB::mode(Timer3::OutputB::Mode::toggle));
    TEST_REG_WRITE(Timer3::OutputB::mode(Timer3::OutputB::Mode::clear));
    TEST_REG_WRITE(Timer3::OutputB::mode(Timer3::OutputB::Mode::set));
}

TEST(Timer3, outputCMode) {
    TEST_REG_WRITE(Timer3::OutputC::mode(Timer3::OutputC::Mode::disconnected));
    TEST_REG_WRITE(Timer3::OutputC::mode(Timer3::OutputC::Mode::toggle));
    TEST_REG_WRITE(Timer3::OutputC::mode(Timer3::OutputC::Mode::clear));
    TEST_REG_WRITE(Timer3::OutputC::mode(Timer3::OutputC::Mode::set));
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
    TEST_REG_WRITE(Timer4::clock(Timer4::Clock::none));
    TEST_REG_WRITE(Timer4::clock(Timer4::Clock::div1));
    TEST_REG_WRITE(Timer4::clock(Timer4::Clock::div8));
    TEST_REG_WRITE(Timer4::clock(Timer4::Clock::div64));
    TEST_REG_WRITE(Timer4::clock(Timer4::Clock::div256));
    TEST_REG_WRITE(Timer4::clock(Timer4::Clock::div1024));
    TEST_REG_WRITE(Timer4::clock(Timer4::Clock::extFalling));
    TEST_REG_WRITE(Timer4::clock(Timer4::Clock::extRising));
}

TEST(Timer4, waveform) {
    TEST_REG_WRITE(Timer4::waveform(Timer4::Waveform::normal));
    TEST_REG_WRITE(Timer4::waveform(Timer4::Waveform::pwm));
    TEST_REG_WRITE(Timer4::waveform(Timer4::Waveform::ctcOcra));
    TEST_REG_WRITE(Timer4::waveform(Timer4::Waveform::fastPwm));
    TEST_REG_WRITE(Timer4::waveform(Timer4::Waveform::pwmOcra));
    TEST_REG_WRITE(Timer4::waveform(Timer4::Waveform::fastPwmOcra));
}

TEST(Timer4, callback) {
    TEST_REG_WRITE(Timer4::callback(func,data));
}

TEST(Timer4, intEnable) {
    TEST_REG_WRITE(Timer4::intEnable(true));
    TEST_REG_WRITE(Timer4::intEnable(false));
}

TEST(Timer4, intFlag) {
    TEST_REG_READ_WRITE(Timer4::intFlag());
}

TEST(Timer4, intFlagClear) {
    TEST_REG_WRITE(Timer4::intFlagClear());
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
    TEST_REG_WRITE(Timer4::OutputA::mode(Timer4::OutputA::Mode::disconnected));
    TEST_REG_WRITE(Timer4::OutputA::mode(Timer4::OutputA::Mode::toggle));
    TEST_REG_WRITE(Timer4::OutputA::mode(Timer4::OutputA::Mode::clear));
    TEST_REG_WRITE(Timer4::OutputA::mode(Timer4::OutputA::Mode::set));
}

TEST(Timer4, outputBMode) {
    TEST_REG_WRITE(Timer4::OutputB::mode(Timer4::OutputB::Mode::disconnected));
    TEST_REG_WRITE(Timer4::OutputB::mode(Timer4::OutputB::Mode::toggle));
    TEST_REG_WRITE(Timer4::OutputB::mode(Timer4::OutputB::Mode::clear));
    TEST_REG_WRITE(Timer4::OutputB::mode(Timer4::OutputB::Mode::set));
}

TEST(Timer4, outputCMode) {
    TEST_REG_WRITE(Timer4::OutputC::mode(Timer4::OutputC::Mode::disconnected));
    TEST_REG_WRITE(Timer4::OutputC::mode(Timer4::OutputC::Mode::toggle));
    TEST_REG_WRITE(Timer4::OutputC::mode(Timer4::OutputC::Mode::clear));
    TEST_REG_WRITE(Timer4::OutputC::mode(Timer4::OutputC::Mode::set));
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
    TEST_REG_WRITE(Timer5::clock(Timer5::Clock::none));
    TEST_REG_WRITE(Timer5::clock(Timer5::Clock::div1));
    TEST_REG_WRITE(Timer5::clock(Timer5::Clock::div8));
    TEST_REG_WRITE(Timer5::clock(Timer5::Clock::div64));
    TEST_REG_WRITE(Timer5::clock(Timer5::Clock::div256));
    TEST_REG_WRITE(Timer5::clock(Timer5::Clock::div1024));
    TEST_REG_WRITE(Timer5::clock(Timer5::Clock::extFalling));
    TEST_REG_WRITE(Timer5::clock(Timer5::Clock::extRising));
}

TEST(Timer5, waveform) {
    TEST_REG_WRITE(Timer5::waveform(Timer5::Waveform::normal));
    TEST_REG_WRITE(Timer5::waveform(Timer5::Waveform::pwm));
    TEST_REG_WRITE(Timer5::waveform(Timer5::Waveform::ctcOcra));
    TEST_REG_WRITE(Timer5::waveform(Timer5::Waveform::fastPwm));
    TEST_REG_WRITE(Timer5::waveform(Timer5::Waveform::pwmOcra));
    TEST_REG_WRITE(Timer5::waveform(Timer5::Waveform::fastPwmOcra));
}

TEST(Timer5, callback) {
    TEST_REG_WRITE(Timer5::callback(func,data));
}

TEST(Timer5, intEnable) {
    TEST_REG_WRITE(Timer5::intEnable(true));
    TEST_REG_WRITE(Timer5::intEnable(false));
}

TEST(Timer5, intFlag) {
    TEST_REG_READ_WRITE(Timer5::intFlag());
}

TEST(Timer5, intFlagClear) {
    TEST_REG_WRITE(Timer5::intFlagClear());
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
    TEST_REG_WRITE(Timer5::OutputA::mode(Timer5::OutputA::Mode::disconnected));
    TEST_REG_WRITE(Timer5::OutputA::mode(Timer5::OutputA::Mode::toggle));
    TEST_REG_WRITE(Timer5::OutputA::mode(Timer5::OutputA::Mode::clear));
    TEST_REG_WRITE(Timer5::OutputA::mode(Timer5::OutputA::Mode::set));
}

TEST(Timer5, outputBMode) {
    TEST_REG_WRITE(Timer5::OutputB::mode(Timer5::OutputB::Mode::disconnected));
    TEST_REG_WRITE(Timer5::OutputB::mode(Timer5::OutputB::Mode::toggle));
    TEST_REG_WRITE(Timer5::OutputB::mode(Timer5::OutputB::Mode::clear));
    TEST_REG_WRITE(Timer5::OutputB::mode(Timer5::OutputB::Mode::set));
}

TEST(Timer5, outputCMode) {
    TEST_REG_WRITE(Timer5::OutputC::mode(Timer5::OutputC::Mode::disconnected));
    TEST_REG_WRITE(Timer5::OutputC::mode(Timer5::OutputC::Mode::toggle));
    TEST_REG_WRITE(Timer5::OutputC::mode(Timer5::OutputC::Mode::clear));
    TEST_REG_WRITE(Timer5::OutputC::mode(Timer5::OutputC::Mode::set));
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

TEST(Usart0, getHardwareType) {
    ASSERT_EQ(Usart0::getHardwareType(), HardwareType::usart);
}

TEST(Usart0, mode) {
    TEST_REG_WRITE(Usart0::mode(Usart0::Mode::asynchronous));
    TEST_REG_WRITE(Usart0::mode(Usart0::Mode::synchronous));
    TEST_REG_WRITE(Usart0::mode(Usart0::Mode::masterSpi));
}

TEST(Usart0, parity) {
    TEST_REG_WRITE(Usart0::parity(Usart0::Parity::disabled));
    TEST_REG_WRITE(Usart0::parity(Usart0::Parity::even));
    TEST_REG_WRITE(Usart0::parity(Usart0::Parity::odd));
}

TEST(Usart0, stopBits) {
    TEST_REG_WRITE(Usart0::stopBits(Usart0::StopBits::bits1));
    TEST_REG_WRITE(Usart0::stopBits(Usart0::StopBits::bits2));
}

TEST(Usart0, characterSize) {
    TEST_REG_WRITE(Usart0::characterSize(Usart0::CharacterSize::size5));
    TEST_REG_WRITE(Usart0::characterSize(Usart0::CharacterSize::size6));
    TEST_REG_WRITE(Usart0::characterSize(Usart0::CharacterSize::size7));
    TEST_REG_WRITE(Usart0::characterSize(Usart0::CharacterSize::size8));
    TEST_REG_WRITE(Usart0::characterSize(Usart0::CharacterSize::size9));
}

TEST(Usart0, polarity) {
    TEST_REG_WRITE(Usart0::polarity(Usart0::Polarity::txRisingRxFalling));
    TEST_REG_WRITE(Usart0::polarity(Usart0::Polarity::txFallingRxRising));
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
    TEST_REG_WRITE(Usart1::mode(Usart1::Mode::asynchronous));
    TEST_REG_WRITE(Usart1::mode(Usart1::Mode::synchronous));
    TEST_REG_WRITE(Usart1::mode(Usart1::Mode::masterSpi));
}

TEST(Usart1, parity) {
    TEST_REG_WRITE(Usart1::parity(Usart1::Parity::disabled));
    TEST_REG_WRITE(Usart1::parity(Usart1::Parity::even));
    TEST_REG_WRITE(Usart1::parity(Usart1::Parity::odd));
}

TEST(Usart1, stopBits) {
    TEST_REG_WRITE(Usart1::stopBits(Usart1::StopBits::bits1));
    TEST_REG_WRITE(Usart1::stopBits(Usart1::StopBits::bits2));
}

TEST(Usart1, characterSize) {
    TEST_REG_WRITE(Usart1::characterSize(Usart1::CharacterSize::size5));
    TEST_REG_WRITE(Usart1::characterSize(Usart1::CharacterSize::size6));
    TEST_REG_WRITE(Usart1::characterSize(Usart1::CharacterSize::size7));
    TEST_REG_WRITE(Usart1::characterSize(Usart1::CharacterSize::size8));
    TEST_REG_WRITE(Usart1::characterSize(Usart1::CharacterSize::size9));
}

TEST(Usart1, polarity) {
    TEST_REG_WRITE(Usart1::polarity(Usart1::Polarity::txRisingRxFalling));
    TEST_REG_WRITE(Usart1::polarity(Usart1::Polarity::txFallingRxRising));
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
    TEST_REG_WRITE(Usart2::mode(Usart2::Mode::asynchronous));
    TEST_REG_WRITE(Usart2::mode(Usart2::Mode::synchronous));
    TEST_REG_WRITE(Usart2::mode(Usart2::Mode::masterSpi));
}

TEST(Usart2, parity) {
    TEST_REG_WRITE(Usart2::parity(Usart2::Parity::disabled));
    TEST_REG_WRITE(Usart2::parity(Usart2::Parity::even));
    TEST_REG_WRITE(Usart2::parity(Usart2::Parity::odd));
}

TEST(Usart2, stopBits) {
    TEST_REG_WRITE(Usart2::stopBits(Usart2::StopBits::bits1));
    TEST_REG_WRITE(Usart2::stopBits(Usart2::StopBits::bits2));
}

TEST(Usart2, characterSize) {
    TEST_REG_WRITE(Usart2::characterSize(Usart2::CharacterSize::size5));
    TEST_REG_WRITE(Usart2::characterSize(Usart2::CharacterSize::size6));
    TEST_REG_WRITE(Usart2::characterSize(Usart2::CharacterSize::size7));
    TEST_REG_WRITE(Usart2::characterSize(Usart2::CharacterSize::size8));
    TEST_REG_WRITE(Usart2::characterSize(Usart2::CharacterSize::size9));
}

TEST(Usart2, polarity) {
    TEST_REG_WRITE(Usart2::polarity(Usart2::Polarity::txRisingRxFalling));
    TEST_REG_WRITE(Usart2::polarity(Usart2::Polarity::txFallingRxRising));
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
    TEST_REG_WRITE(Usart3::mode(Usart3::Mode::asynchronous));
    TEST_REG_WRITE(Usart3::mode(Usart3::Mode::synchronous));
    TEST_REG_WRITE(Usart3::mode(Usart3::Mode::masterSpi));
}

TEST(Usart3, parity) {
    TEST_REG_WRITE(Usart3::parity(Usart3::Parity::disabled));
    TEST_REG_WRITE(Usart3::parity(Usart3::Parity::even));
    TEST_REG_WRITE(Usart3::parity(Usart3::Parity::odd));
}

TEST(Usart3, stopBits) {
    TEST_REG_WRITE(Usart3::stopBits(Usart3::StopBits::bits1));
    TEST_REG_WRITE(Usart3::stopBits(Usart3::StopBits::bits2));
}

TEST(Usart3, characterSize) {
    TEST_REG_WRITE(Usart3::characterSize(Usart3::CharacterSize::size5));
    TEST_REG_WRITE(Usart3::characterSize(Usart3::CharacterSize::size6));
    TEST_REG_WRITE(Usart3::characterSize(Usart3::CharacterSize::size7));
    TEST_REG_WRITE(Usart3::characterSize(Usart3::CharacterSize::size8));
    TEST_REG_WRITE(Usart3::characterSize(Usart3::CharacterSize::size9));
}

TEST(Usart3, polarity) {
    TEST_REG_WRITE(Usart3::polarity(Usart3::Polarity::txRisingRxFalling));
    TEST_REG_WRITE(Usart3::polarity(Usart3::Polarity::txFallingRxRising));
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
