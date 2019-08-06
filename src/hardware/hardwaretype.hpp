/// [[Index]]

/// # {{Hardware Types}}

#ifndef NBLIB_HARDWARE_TYPE_HPP
#define NBLIB_HARDWARE_TYPE_HPP

// TODO Move to system.hpp.
namespace nblib::hw {

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

} // nblib::hw

#endif
