#ifndef NBAVR_MEMORYBARRIER_HPP
#define NBAVR_MEMORYBARRIER_HPP

// These need to be outside nbavr namespace so they can be used in cleanup().

force_inline uint8_t __cli() {
    uint8_t s = *CHIP_STATUS_REG;
    nbavr::cli();
    return s;
}

force_inline uint8_t __sei() {
    uint8_t s = *CHIP_STATUS_REG;
    nbavr::sei();
    return s;
}

force_inline void __ssreg(const uint8_t *s) {
    *CHIP_STATUS_REG = *s;
}

force_inline uint8_t _MemoryBarrier(const uint8_t *s) {
    #ifndef TEST
    __asm__ __volatile__("":::"memory");
    #endif

    return 1;
}

#endif
