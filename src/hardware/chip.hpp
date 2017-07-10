#ifndef NBAVR_CHIP_HPP
#define NBAVR_CHIP_HPP

#define REG8(addr) reinterpret_cast<volatile uint8_t*>(fake_ram + addr)
#define REG16(addr) reinterpret_cast<volatile uint16_t*>(fake_ram + addr)
#define REG32(addr) reinterpret_cast<volatile uint32_t*>(fake_ram + addr)

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

#ifdef TEST
    uint8_t fake_ram[CHIP_RAM_SIZE];
#else
    #define fake_ram 0
#endif

#ifndef NBAVR_CHIP_DEFINED
    #error The hardware has not been defined for this chip
#endif

#endif
