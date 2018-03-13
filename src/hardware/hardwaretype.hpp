#ifndef NBOS_HARDWARE_TYPE_HPP
#define NBOS_HARDWARE_TYPE_HPP

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
