/// # {{Adding Chips}}
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

// TODO Elaborate.
// What to define in chip definitions:
// REG, memory ADDR and TYPE
// MASK, the bits of the register to include
// ID, the value and meaning of the bits
// PURE, if this register is write only or a flag register

#ifndef NBLIB_CHIP_HPP
#define NBLIB_CHIP_HPP

#include "../primitive.hpp"

namespace nblib {

template <class T, size_t addr>
struct _reg {
    T*const p = (T*)(addr);
};

} // nblib

// Use of _reg makes the compiler throw a more meaningful message if _TYPE or _ADDR isn't defined.
#define REG(R) nblib::_reg<REG_TYPE(R), REG_ADDR(R)>().p
#define REG_TYPE(R) CAT(R, _TYPE)
#define REG_ADDR(R) CAT(R, _ADDR)

#if defined(__atmega328__)
    #include "chips/avr/atmega328.hpp"
#elif defined(__atmega328p__)
    #include "chips/avr/atmega328p.hpp"
#elif defined(__atmega328pb__)
    #include "chips/avr/atmega328pb.hpp"
#elif defined(__atmega48__)
    #include "chips/avr/atmega48.hpp"
#elif defined(__atmega8__)
    #include "chips/avr/atmega8.hpp"
#elif defined(__attiny85__)
    #include "chips/avr/attiny85.hpp"
#elif defined(__atmega2560__)
    #include "chips/avr/atmega2560.hpp"
#elif defined(__attiny402__)
    #include "chips/avr/attiny402.hpp"
#elif defined(__attiny1614__)
    #include "chips/avr/attiny1614.hpp"
#elif defined(__stm32f103c8__)
    #include "chips/stm32/stm32f103c8.hpp"
#else
    #error The hardware has not been defined for this chip
#endif

#endif
