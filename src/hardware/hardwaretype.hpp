/// [[Index]]

/// # {{Hardware Types}}

#ifndef NBOS_HARDWARE_TYPE_HPP
#define NBOS_HARDWARE_TYPE_HPP

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
enum class HardwareType {
    adc,
    exInt,
    eeprom,
    pcInt,
    pin,
    port,
    sleep,
    spi,
    timer,
    twi,
    usart,
    usi,
    wdt
};

} // nbos::hw

#endif
