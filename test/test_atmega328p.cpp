#define __AVR_ATmega328P__

#define RECORD_ID "atmega328p"

#include "test.hpp"

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
    TEST_RAM_READ(Adc::value());
    TEST_RAM_WRITE(Adc::value());
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
    TEST_RAM_WRITE(Adc::channel(Adc::Channel::ADC8));
    TEST_RAM_WRITE(Adc::channel(Adc::Channel::VBG));
    TEST_RAM_WRITE(Adc::channel(Adc::Channel::GND));
}
