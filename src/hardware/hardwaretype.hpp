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
    spi,
    timer,
    twi,
    usart,
    usi,
    wdt
};

#endif
