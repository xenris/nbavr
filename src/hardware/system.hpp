/// [[Index]]

/// # System

#ifndef NBOS_SYSTEM_HPP
#define NBOS_SYSTEM_HPP

#include "chip.hpp"
#include "macros.hpp"
#include "safe.hpp"

#define block if(__Block(); true)

struct __Block {
    __Block() {
        asm volatile("" ::: "memory");
    }

    ~__Block() {
        asm volatile("" ::: "memory");
    }
};

namespace nbos {

/// #### T bv(T n)
/// Equivalent to "1 << n".
template <class T>
force_inline T bv(T n) {
    static_assert(IsInteger<T>::value, "bv requires an integer");

    return T(1) << n;
}

/// #### void setBit(T\* register, Word8 bit, Bool value)
/// Set or clear a bit in a register immediately.
template <class T>
force_inline void setBit(T* reg, Word8 bit, Bool value) {
    static_assert(!IsSigned<T>::value, "setBit requires a pointer to an unsigned integer");

    block {
        setBit_(reg, bit, value);
    }
}

/// #### void setBit_(T\* register, Word8 bit, Bool value)
/// Set or clear a bit in a register lazily.
/// (i.e. Allow compiler to rearrange and combine instructions for faster code.)
template <class T>
force_inline void setBit_(T* reg, Word8 bit, Bool value) {
    static_assert(!IsSigned<T>::value, "setBit_ requires a pointer to an unsigned integer");

    if(value) {
        *reg |= bv<T>(bit);
    } else {
        *reg &= ~bv<T>(bit);
    }
}

template <class T>
force_inline Bool getBit(T* reg, Word8 bit) {
    static_assert(!IsSigned<T>::value, "getBit requires a pointer to an unsigned integer");

    block {
        return Bool(*reg & bv<T>(bit));
    };
}

force_inline void nop() {
    #if defined(__AVR__) || defined(__ARM__)
        asm volatile("nop" ::: "memory");
    #elif defined(TEST)
        // Ignore this function.
    #else
        #warning nop() not defined for this architecture.
    #endif
}

/// #### void delay<Word64 cpuFreq, Word64 ns>()
/// Delays the cpu for the given number of nanoseconds.<br>
/// Should only be used for very short delays.<br>
/// Limited to 10 milliseconds.<br>
/// Rounds to the nearest possible delay time. e.g. at 16MHz, delay<50>() will
/// delay for 62.5 nanoseconds (1 cpu clock cycle).<br>
/// Is limited further by faster clock speeds. e.g. at 100MHz it will be limited to 2621434ns.
template <Integer cpuFreq, Integer ns>
force_inline void delay() {
    static_assert(ns <= 10000000, "Delay limited to 10 milliseconds (10000000 ns)");

    // Ensure that this delay separates hardware actions, even when 0ns.
    block {};

    constexpr Word64 clocks = (Word64(ns) * cpuFreq + 500000000) / 1000000000;
    constexpr Word64 clocksPerLoop = 4;

    // TODO Handle higher cpu frequencies.
    static_assert(clocks / 4 <= Word64(Max<Word16>::value), "Cannot handle this length of delay at this cpu frequency");

    constexpr Word16 loops = Word16((clocks <= 0) ? (0) : ((clocks - 1) / clocksPerLoop));
    constexpr Word16 nops = Word16((clocks <= 4) ? (clocks) : ((clocks - 1) % clocksPerLoop));

    if constexpr (loops != 0) {
        const Word16 c = loops;

        asm volatile (
            "ldi r30, %0\n"
            "ldi r31, %1\n"
            "1: sbiw r30, 1\n"
            "brne 1b\n"
            :
            : "" (Word8(c)), "" (Word8(c >> 8))
            : "r30", "r31"
        );
    }

    if constexpr (nops == 1) {
        nop();
    } else if constexpr (nops == 2) {
        nop(); nop();
    } else if constexpr (nops == 3) {
        nop(); nop(); nop();
    } else if constexpr (nops == 4) {
        nop(); nop(); nop(); nop();
    }
}

// TODO Check that these functions work for arm.

/// #### void interruptsEnable(Bool)
/// Enable/disable interrupts.
force_inline void interruptsEnable(Bool enable) {
    #if defined(__AVR__)
        if(enable) {
            asm volatile("sei" ::: "memory");
        } else {
            asm volatile("cli" ::: "memory");
        }
    #elif defined(__ARM__)
        if(enable) {
            asm volatile("cpsie i" ::: "memory");
        } else {
            asm volatile("cpsid i" ::: "memory");
        }
    #elif defined(TEST)
        // Ignore this function.
    #else
        #warning interruptsEnable(Bool) not defined for this architecture.
    #endif
}

/// #### Bool interruptsEnabled()
/// Returns true if interrupts are enabled.
force_inline Bool interruptsEnabled() {
    Bool t = false;

    #if defined(__AVR__)
        #if REG_DEFINED(CHIP_SYSTEM_GLOBAL_INTERRUPT_BIT_0_REG)
            t = getBit(REG(CHIP_SYSTEM_GLOBAL_INTERRUPT_BIT_0_REG), CHIP_SYSTEM_GLOBAL_INTERRUPT_BIT_0_BIT);
        #else
            #error CHIP_SYSTEM_GLOBAL_INTERRUPT_BIT_0_REG/BIT not defined.
        #endif
    #elif defined(__ARM__)
        asm volatile("mrs %[t], PRIMASK" : [t] "=r" (t) :: "memory");
    #elif defined(TEST)
        // Ignore this function.
    #else
        #warning interruptsEnabled() not defined for this architecture.
    #endif

    return t;
}

}

#define atomic if(__Atomic(); true)

#define nonatomic if(__NonAtomic(); true)

struct __Atomic {
    Bool _i;

    __Atomic() {
        _i = nbos::interruptsEnabled();

        nbos::interruptsEnable(false);

        block {};
    }

    ~__Atomic() {
        nbos::interruptsEnable(_i);

        block {};
    }
};

struct __NonAtomic {
    Bool _i;

    __NonAtomic() {
        _i = nbos::interruptsEnabled();

        nbos::interruptsEnable(true);

        block {};
    }

    ~__NonAtomic() {
        nbos::interruptsEnable(_i);

        block {};
    }
};

#endif
