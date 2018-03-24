/// # Adding Chips
/// 1. Copy src/hardware/chips/xxx.hpp for the new chip.
/// 1. Change values to suit.
/// 1. Add header to src/hardware/chip.hpp

/// # Adding Tests
/// 1. Copy test/test_*.hpp for the new test.
/// 1. Change values to suit. (Make sure RECORD_ID is unique.)
/// 1. Run runtests.sh [chip]. (e.g. "./runtests.sh atmega328p")
/// 1. Fix compilation errors.
/// 1. Copy record printout to test/record_[RECORD_ID].

/// # About Chip Records
/// The chip record is a record of memory reads and writes. It doesn't
/// guarantee correct hardware use, but does help to show when something has
/// changed, preventing accidental introduction of bugs. It can also help to
/// debug problems. It's not foolproof, but it's much better than nothing.

/// The two kinds of records are:
/// * read: "r [function name and args] [return values]"

///   e.g. "r PortB::direction() cf1d6ab8653a1ee3c8a"

/// * write: "w [function name and args] ([address]:[value before]:[value after]:)*"

///   e.g. "w Adc::channel(Adc::Channel::ADC4) 7c:00:04:7c:ff:f4:"

#ifndef NBOS_CHIP_HPP
#define NBOS_CHIP_HPP

#include "type.hpp"

#ifndef register_offset
    #define register_offset 0
#endif

namespace nbos {

template <class T>
struct _reg {
    volatile T* p;

    _reg(size_t addr) : p((T*)(addr + register_offset)) {}
};

} // nbos

// Use of _reg makes the compiler throw a more meaningful message if _TYPE or _ADDR isn't defined.
#define REG(R) _reg<volatile CAT(R, _TYPE)>(CAT(R, _ADDR)).p
#define REGL(R) _reg<CAT(R, _TYPE)>(CAT(R, _ADDR)).p

#define REGTYPE(R) CAT(R, _TYPE)

#define VECT(N) VECT_(DEC(N))
#define VECT_(N) VECT__(N)
#define VECT__(N) __vector_ ## N

#define TRUE 1

#if defined(__atmega328__)
    #include "chips/avr/atmega328.hpp"
#endif

#if defined(__atmega328p__)
    #include "chips/avr/atmega328p.hpp"
#endif

#if defined(__atmega48__)
    #include "chips/avr/atmega48.hpp"
#endif

#if defined(__atmega8__)
    #include "chips/avr/atmega8.hpp"
#endif

#if defined(__attiny85__)
    #include "chips/avr/attiny85.hpp"
#endif

#if defined(__atmega2560__)
    #include "chips/avr/atmega2560.hpp"
#endif

#if defined(__stm32f103c8_md__)
    #include "chips/stm32/stm32f103c8_md.hpp"
#endif

//#if defined(__AVR_XXX__)
//    #include "chips/xxx.hpp"
//#endif

#ifndef NBOS_CHIP_DEFINED
    #error The hardware has not been defined for this chip
#endif

#endif
