#ifndef NBOS_HARDWARE_HPP
#define NBOS_HARDWARE_HPP

#include "hardware/chip.hpp"
#include "hardware/util.hpp"
#include "hardware/callbacks.hpp"

namespace hw {
    #include "hardware/adc.hpp"
    #include "hardware/eeprom.hpp"
    #include "hardware/exint.hpp"
    #include "hardware/pcint.hpp"
    #include "hardware/pin.hpp"
    #include "hardware/port.hpp"
    #include "hardware/spi.hpp"
    #include "hardware/timer.hpp"
    #include "hardware/twi.hpp"
    #include "hardware/usart.hpp"
    #include "hardware/usi.hpp"
    #include "hardware/watchdog.hpp"
}

#endif
