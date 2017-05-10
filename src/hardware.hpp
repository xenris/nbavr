#ifndef NBAVR_HARDWARE_HPP
#define NBAVR_HARDWARE_HPP

enum class HardwareType : uint8_t {
    ADC,
    ExInt,
    PcInt,
    Pin,
    Port,
    TimerCounter,
    Usart,
    WDT
};

#include "hardware/chip.hpp"
#include "hardware/util.hpp"
#include "hardware/callbacks.hpp"

#include "hardware/adc.hpp"
#include "hardware/exint.hpp"
#include "hardware/pcint.hpp"
#include "hardware/pin.hpp"
#include "hardware/port.hpp"
#include "hardware/timercounter.hpp"
#include "hardware/usart.hpp"
#include "hardware/watchdog.hpp"

#endif
