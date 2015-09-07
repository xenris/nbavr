#ifndef HARDWARE_H
#define HARDWARE_H

#include "../config.h"
#include <avr/io.h>
#include <stdbool.h>
#include <util/setbaud.h>

#if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega328__)
    #include "hardware/atmega328p.h"
#endif

#ifndef HARDWARE_DEFINED
    #error Hardware specific code has not been defined for this AVR
#endif

#endif
