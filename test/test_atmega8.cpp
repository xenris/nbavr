#define __AVR_ATmega8__

#define RECORD_ID "atmega8"

#include "test.hpp"

TEST(Adc, getHardwareType) {
    ASSERT_EQ(Adc::getHardwareType(), HardwareType::ADC);
}

TEST(Adc, enable) {
    TEST_MEM_WRITE(Adc::enable(true));
    TEST_MEM_WRITE(Adc::enable(false));
}

TEST(Adc, start) {
    TEST_MEM_WRITE(Adc::start());
}

TEST(Adc, value) {
    TEST_MEM_READ(Adc::value());
    TEST_MEM_WRITE(Adc::value());
}

TEST(Adc, reference) {
    TEST_MEM_WRITE(Adc::reference(Adc::Reference::AREF));
    TEST_MEM_WRITE(Adc::reference(Adc::Reference::AVCC));
    TEST_MEM_WRITE(Adc::reference(Adc::Reference::Internal));
}

TEST(Adc, channel) {
    TEST_MEM_WRITE(Adc::channel(Adc::Channel::ADC0));
    TEST_MEM_WRITE(Adc::channel(Adc::Channel::ADC1));
    TEST_MEM_WRITE(Adc::channel(Adc::Channel::ADC2));
    TEST_MEM_WRITE(Adc::channel(Adc::Channel::ADC3));
    TEST_MEM_WRITE(Adc::channel(Adc::Channel::ADC4));
    TEST_MEM_WRITE(Adc::channel(Adc::Channel::ADC5));
    TEST_MEM_WRITE(Adc::channel(Adc::Channel::ADC6));
    TEST_MEM_WRITE(Adc::channel(Adc::Channel::ADC7));
    TEST_MEM_WRITE(Adc::channel(Adc::Channel::VBG));
    TEST_MEM_WRITE(Adc::channel(Adc::Channel::GND));
}
