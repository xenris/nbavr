#ifndef NBOS_SYSTEM_HPP
#define NBOS_SYSTEM_HPP

#include "macros.hpp"
#include "type.hpp"
#include "chip.hpp"

/// # System

namespace nbos {

/// #### T bv(T n)
/// Equivalent to "1 << n", but works with types bigger than int.
template <class T>
force_inline T bv(T n) {
    static_assert(is_integer<T>::value, "bv requires an integer");

    return T(1) << n;
}

/// #### void setBit(volatile T\* register, uint8_t bit, bool value)
/// Set or clear a bit in a volatile register immediately.
template <class T>
force_inline void setBit(volatile T* reg, uint8_t bit, bool value) {
    static_assert(!is_signed<T>::value, "setBit requires a pointer to an unsigned integer");

    if(value) {
        *reg |= bv<T>(bit);
    } else {
        *reg &= ~bv<T>(bit);
    }
}

/// #### void setBit_(volatile T\* register, uint8_t bit, bool value)
/// Set or clear a bit in a volatile register lazily.
/// (i.e. Allow compiler to rearrange and combine instructions.)
template <class T>
force_inline void setBit_(volatile T* reg, uint8_t bit, bool value) {
    static_assert(!is_signed<T>::value, "setBit_ requires a pointer to an unsigned integer");

    T* reg_ = (T*)(reg);

    if(value) {
        *reg_ |= bv<T>(bit);
    } else {
        *reg_ &= ~bv<T>(bit);
    }
}

/// #### void getBit(volatile T\* register, uint8_t bit)
/// Get a bit from a volatile register.
template <class T>
force_inline bool getBit(volatile T* reg, uint8_t bit) {
    static_assert(!is_signed<T>::value, "getBit requires a pointer to an unsigned integer");

    return *reg & bv<T>(bit);
}

force_inline void nop() {
    #if defined(__AVR__) || defined(__ARM__)
        asm volatile("nop" ::: "memory");
    #endif
}

// TODO Check that these three functions work for arm.

/// #### void interruptsEnable()
/// Globally enable interrupts.
force_inline void interruptsEnable(bool enable) {
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
    #endif
}

/// #### void interruptsEnabled()
/// Globally enable interrupts.
force_inline bool interruptsEnabled() {
    bool t = false;

    #if defined(__AVR__)
        #if REG_DEFINED(CHIP_SYSTEM_GLOBAL_INTERRUPT_BIT_0_REG)
            t = getBit(REG(CHIP_SYSTEM_GLOBAL_INTERRUPT_BIT_0_REG), CHIP_SYSTEM_GLOBAL_INTERRUPT_BIT_0_BIT);
        #else
            #error CHIP_SYSTEM_GLOBAL_INTERRUPT_BIT_0_REG/BIT not defined.
        #endif
    #elif defined(__ARM__)
        asm volatile("mrs %[t], PRIMASK" : [t] "=r" (t) :: "memory");
    #endif

    return t;
}

template <class F>
force_inline auto atomic(F f) -> decltype(f()) {
    const bool i = interruptsEnabled();

    interruptsEnable(false);

    if constexpr(is_same<decltype(f()), void>::value) {
        f();

        interruptsEnable(i);
    } else {
        auto r = f();

        interruptsEnable(i);

        return r;
    }
}

/// #### macro block
/// Make sure an expression or block of expressions is compiled in the order it is written in.
/// i.e. Prevents the compiler from doing memory access optimisations which reorder code.
force_inline void block() {
    asm volatile("" ::: "memory");
}

template <class F>
force_inline auto block(F f) -> decltype(f()) {
    if constexpr(is_same<decltype(f()), void>::value) {
        block();
        f();
        block();
    } else {
        block();
        auto r = f();
        block();

        return r;
    }
}

template <class F>
force_inline auto nonatomic(F f) -> decltype(f()) {
    const bool i = interruptsEnabled();

    interruptsEnable(true);

    if constexpr(is_same<decltype(f()), void>::value) {
        f();

        interruptsEnable(i);
    } else {
        auto r = f();

        interruptsEnable(i);

        return r;
    }
}

    /// #### void delay<uint64_t ns>()
    /// Delays the cpu for the given number of nanoseconds.<br>
    /// Should only be used for very short delays.<br>
    /// Limited to 10 milliseconds.<br>
    /// Rounds to the nearest possible delay time. e.g. at 16MHz, delay<50>() will
    /// delay for 62.5 nanoseconds (1 cpu clock cycle).<br>
    /// Is limited further by faster clock speeds. e.g. at 100MHz it will be limited to 2621434ns.
    template <uint64_t cpuFreq, uint64_t ns>
    force_inline void delay() {
        static_assert(ns <= 10000000, "Delay limited to 10 milliseconds (10000000 ns)");

        // Ensure that this delay separates hardware actions, even when 0ns.
        block();

        const uint64_t clocks = (uint64_t(ns) * cpuFreq + 500000000) / 1000000000;
        const uint64_t clocksPerLoop = 4;

        // TODO Handle higher cpu frequencies.
        static_assert(clocks / 4 <= integer_max<uint16_t>::value, "Cannot handle this length of delay at this cpu frequency");

        const uint16_t loops = (clocks <= 0) ? (0) : ((clocks - 1) / clocksPerLoop);
        const uint16_t nops = (clocks <= 4) ? (clocks) : ((clocks - 1) % clocksPerLoop);

        if constexpr (loops != 0) {
            const uint16_t c = loops;

            asm volatile (
                "ldi r30, %0\n"
                "ldi r31, %1\n"
                "1: sbiw r30, 1\n"
                "brne 1b\n"
                :
                : "" (uint8_t(c)), "" (uint8_t(c >> 8))
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

} // nbos::hw

#endif
