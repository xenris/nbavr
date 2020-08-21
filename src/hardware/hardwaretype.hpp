/// [[Index]]

/// # {{Hardware Types}}

#ifndef NBLIB_HARDWARE_TYPE_HPP
#define NBLIB_HARDWARE_TYPE_HPP

// TODO Move to system.hpp.
namespace nblib::hw {

/// #### enum {{HardwareType}}
/// * ac
/// * adc
/// * clock
/// * dac
/// * exInt
/// * eeprom
/// * pcInt
/// * pin
/// * port
/// * spi
/// * tc
/// * tcA
/// * tcB
/// * tcC
/// * tcD
/// * timer
/// * twi
/// * usart
/// * usi
/// * vref
/// * wdt
enum class HardwareType {
    ac,
    adc,
    clock,
    dac,
    exInt,
    eeprom,
    pcInt,
    pin,
    port,
    sleep,
    spi,
    tc,
    tcA,
    tcB,
    tcC,
    tcD,
    timer,
    twi,
    usart,
    usi,
    vref,
    wdt
};

} // nblib::hw

#endif
