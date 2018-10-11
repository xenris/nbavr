/// # {{Hardware Types}}

#ifndef NBOS_HARDWARE_TYPE_HPP
#define NBOS_HARDWARE_TYPE_HPP

#include <type.hpp>

// TODO Move to system.hpp.
namespace nbos::hw {

/// #### enum {{HardwareType}}
/// * adc
/// * exInt
/// * eeprom
/// * pcInt
/// * pin
/// * port
/// * spi
/// * timer
/// * twi
/// * usart
/// * usi
/// * wdt
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

} // nbos::hw

#endif
