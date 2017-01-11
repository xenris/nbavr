#ifndef NBAVR_CHIP_HPP
#define NBAVR_CHIP_HPP

#define REG8(addr) (*(volatile uint8_t*)(addr))
#define REG16(addr) (*(volatile uint16_t*)(addr))
#define REG32(addr) (*(volatile uint32_t*)(addr))

#define VECT(n) __vector_ ## n

#define TRUE 1

#if defined(__AVR_ATmega328__)
    #include "chips/atmega328.hpp"
#endif

#if defined(__AVR_ATmega328P__)
    #include "chips/atmega328p.hpp"
#endif

#if defined(__AVR_ATmega8__)
    #include "chips/atmega8.hpp"
#endif

//#if defined(__AVR_XXX__)
//    #include "chips/xxx.hpp"
//#endif

#ifndef NBAVR_CHIP_DEFINED
    #error The hardware has not been defined for this chip
#endif

#endif
