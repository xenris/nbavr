#ifndef NBOS_MEMORYBARRIER_HPP
#define NBOS_MEMORYBARRIER_HPP

// These need to be outside nbos namespace so they can be used in cleanup().
#include "hardware/util.hpp"

#ifdef CHIP_STATUS_REG

force_inline uint8_t __cli() {
    uint8_t s = *CHIP_STATUS_REG;
    nbos::interruptsDisable();
    return s;
}

force_inline uint8_t __sei() {
    uint8_t s = *CHIP_STATUS_REG;
    nbos::interruptsEnable();
    return s;
}

force_inline void __ssreg(const uint8_t *s) {
    *CHIP_STATUS_REG = *s;
}

#endif

force_inline uint8_t _MemoryBarrier(const uint8_t *s) {
    __asm__ __volatile__("":::"memory");

    return 1;
}

#endif
