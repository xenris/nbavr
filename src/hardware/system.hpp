/// [[Index]]

/// # {{System}}

#ifndef NBLIB_SYSTEM_HPP
#define NBLIB_SYSTEM_HPP

#include "chip.hpp"
#include "register.hpp"
#include "../macros.hpp"
#include "../primitive.hpp"

/// ### atomic\(expr\)
/// Disables interrupts while accessing/evaluating "expr".<br>
/// Required when accessing variables which are shared with interrupt callbacks. e.g.
/// ```c++
/// int localVariable = atomic(globalVariable);
/// // Or
/// int localVariable = atomic(globalVariable, 0);
/// // to get and set the value atomically.
/// ```

/// ### atomic\(\) \{expr1; expr2; expr3; etc...\}
/// Disables interrupts while running a block of code.

#ifdef __clang__
    #define atomic(A, ...) A
#else
    #define atomic(...) CAT(atomic_, LENGTH(__VA_ARGS__))(__VA_ARGS__)
    #define atomic_0() if(nblib::__Atomic __a; true)
    #define atomic_1(A) (nblib::__Atomic(), A)
    #define atomic_2(A, B) (nblib::__Atomic(), nblib::__getThenSet(A, B))
#endif

/// ### non_atomic\(expr\)
/// Inverse of atomic.

/// ### non_atomic\(\) \{expr1; expr2; expr3; etc...\}
/// Inverse of atomic.

#ifdef __clang__
    #define non_atomic(...) __VA_ARGS__
#else
    #define non_atomic(...) CAT(non_atomic_, LENGTH(__VA_ARGS__))(__VA_ARGS__)
    #define non_atomic_0() if(nblib::__NonAtomic __n; true)
    #define non_atomic_1(A) (nblib::__NonAtomic(), A)
    #define non_atomic_2(A, B) (nblib::__NonAtomic(), nblib::__getThenSet(A, B))
#endif

namespace nblib {

force_inline void nop() {
    #if defined(__AVR__) || defined(__ARM__)
        asm volatile("nop" ::: "memory");
    #elif defined(TEST)
        // Ignore this function.
    #else
        #warning nop() not defined for this architecture.
    #endif
}

/// #### void delay<uint64_t cpuFreq, uint64_t ns>()
/// Delays the cpu for the given number of nanoseconds.<br>
/// Should only be used for very short delays.<br>
/// Limited to 10 milliseconds.<br>
/// Rounds to the nearest possible delay time. e.g. at 16MHz, delay<50>() will
/// delay for 62.5 nanoseconds (1 cpu clock cycle).<br>
/// Is limited further by faster clock speeds. e.g. at 100MHz it will be limited to 2621434ns.
template <uint64_t cpuFreq, uint64_t ns>
force_inline void delay() {
    // Ensure that this delay separates hardware actions, even when 0ns.
    block() {}

    #if defined(__AVR__)
        static_assert(ns <= 10000000, "Delay limited to 10 milliseconds (10000000 ns)");

        constexpr uint64_t clocks = (uint64_t(ns) * cpuFreq + 500000000) / 1000000000;
        constexpr uint64_t clocksPerLoop = 4;

        // TODO Handle higher cpu frequencies.
        static_assert(clocks / 4 <= uint64_t(max<uint16_t>()), "Cannot handle this length of delay at this cpu frequency");

        constexpr uint16_t loops = uint16_t((clocks <= 0) ? (0) : ((clocks - 1) / clocksPerLoop));
        constexpr uint16_t nops = uint16_t((clocks <= 4) ? (clocks) : ((clocks - 1) % clocksPerLoop));

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
    #elif defined(__ARM__)
        // TODO Currently this is only an approximation and only works under -Os.
        // Need inline assembly.
        constexpr uint64_t clocks = (uint64_t(ns) * cpuFreq + 500000000) / 1000000000;
        constexpr uint64_t clocksPerLoop = 3;

        constexpr uint32_t loops = uint32_t((clocks == 0) ? (0) : ((clocks - 1) / clocksPerLoop));

        for(uint32_t i = 0; i < loops; ++i) {
            block() {}
        }
    #elif defined(TEST)
    #else

    #endif
}

// TODO Check that these functions work for arm.

/// #### void interruptsEnable(bool)
/// Enable/disable interrupts.
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
    #elif defined(TEST)
        // Ignore this function.
    #else
        #warning interruptsEnable(bool) not defined for this architecture.
    #endif
}

/// #### bool interruptsEnabled()
/// Returns true if interrupts are enabled.
force_inline bool interruptsEnabled() {
    bool t = false;

    #if defined(__AVR__)
        t = CHIP_SYSTEM_GLOBAL_INTERRUPT_REG::getBit(CHIP_SYSTEM_GLOBAL_INTERRUPT_BIT);
    #elif defined(__ARM__)
        asm volatile("mrs %[t], PRIMASK" : [t] "=r" (t) :: "memory");
    #elif defined(TEST)
        // Ignore this function.
    #else
        #warning interruptsEnabled() not defined for this architecture.
    #endif

    return t;
}

struct __Atomic {
    bool _i;

    force_inline __Atomic() {
        block() {
            _i = nblib::interruptsEnabled();

            nblib::interruptsEnable(false);
        }
    }

    force_inline ~__Atomic() {
        block() {
            if(_i) {
                nblib::interruptsEnable(true);
            }
        }
    }
};

struct __NonAtomic {
    bool _i;

    __NonAtomic() {
        block() {
            _i = nblib::interruptsEnabled();

            nblib::interruptsEnable(true);
        };
    }

    ~__NonAtomic() {
        block() {
            if(!_i) {
                nblib::interruptsEnable(false);
            }
        }
    }
};

}

#endif
