#ifndef NBAVR_HARDWARE_TYPE_HPP
#define NBAVR_HARDWARE_TYPE_HPP

#include <type.hpp>

enum class HardwareType : uint8_t {
    adc,
    exInt,
    eeprom,
    pcInt,
    pin,
    port,
    timer,
    twi,
    usart,
    wdt
};

#endif
