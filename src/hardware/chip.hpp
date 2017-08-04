/// # Adding Chips
/// 1. Copy src/hardware/chips/xxx.hpp for the new chip.
/// 1. Change values to suit.
/// 1. Add header to src/hardware/chip.hpp
///
/// # Adding Tests
/// 1. Copy test/test_*.hpp for the new test.
/// 1. Change values to suit. (Make sure RECORD_ID is unique.)
/// 1. Run runtests.sh [chip]. (e.g. "./runtests.sh atmega328p")
/// 1. Fix compilation errors.
/// 1. Copy record printout to test/record_[RECORD_ID].
///
/// # About Chip Records
/// The chip record is a record of memory reads and writes. It doesn't
/// guarantee correct hardware use, but does help to show when something has
/// changed, preventing accidental introduction of bugs. It can also help to
/// debug problems. It's not foolproof, but it's much better than nothing.
///
/// The two kinds of records are:
/// * read: "r [function name and args] [return values]"
///
///   e.g. "r PortB::direction() cf1d6ab8653a1ee3c8a"
///
/// * write: "w [function name and args] ([address]:[value before]:[value after]:)*"
///
///   e.g. "w Adc::channel(Adc::Channel::ADC4) 7c:00:04:7c:ff:f4:"

#ifndef NBAVR_CHIP_HPP
#define NBAVR_CHIP_HPP

#define CHIP_REGISTER_SIZE 0x200

#ifdef TEST
    uint8_t __test_fake_register[CHIP_REGISTER_SIZE];
#else
    #define __test_fake_register 0
#endif

#define REG8(addr) reinterpret_cast<volatile uint8_t*>(__test_fake_register + addr)
#define REG16(addr) reinterpret_cast<volatile uint16_t*>(__test_fake_register + addr)
#define REG32(addr) reinterpret_cast<volatile uint32_t*>(__test_fake_register + addr)

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

#if defined(__AVR_ATtiny85__)
    #include "chips/attiny85.hpp"
#endif

//#if defined(__AVR_XXX__)
//    #include "chips/xxx.hpp"
//#endif

#ifndef NBAVR_CHIP_DEFINED
    #error The hardware has not been defined for this chip
#endif

#endif
