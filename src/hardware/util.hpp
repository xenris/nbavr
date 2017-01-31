#ifndef NBAVR_UTIL_HPP
#define NBAVR_UTIL_HPP

#define CONCAT_(A,B,C) A ## B ## C
#define CONCAT(A,B,C) CONCAT_(A,B,C)

#define bv(n) (1 << (n))
#define _BV(n) bv(n)

#define force_inline inline __attribute__((always_inline))

force_inline
void nop() {
    __asm__ __volatile__ ("nop");
}

#define _MemoryBarrier() __asm__ __volatile__("":::"memory")

force_inline
void cli() {
    __asm__ __volatile__ ("cli" ::: "memory");
}

force_inline
void sei() {
    __asm__ __volatile__ ("sei" ::: "memory");
}

force_inline
uint8_t __cli() {
    uint8_t s = CHIP_STATUS_REG;
    cli();
    return s;
}

force_inline
uint8_t __sei() {
    uint8_t s = CHIP_STATUS_REG;
    sei();
    return s;
}

force_inline
void __ssreg(const uint8_t *s) {
    CHIP_STATUS_REG = *s;
}

#define atomic for(uint8_t __sreg __attribute__((cleanup(__ssreg))) = __cli(), __once = 1; __once; __once = 0)
#define nonatomic for(uint8_t __sreg __attribute__((cleanup(__ssreg))) = __sei(), __once = 1; __once; __once = 0)

#define ISR(vector, ...) \
    extern "C" void vector(void) __attribute__((signal,used,externally_visible)) __VA_ARGS__; \
    void vector(void)

template<class T>
force_inline
T max(T a, T b) {
    return a > b ? a : b;
}

template<class T>
force_inline
T min(T a, T b) {
    return a < b ? a : b;
}

template<class T>
force_inline
T clip(T x, T l, T h) {
    return max(min(x, h), l);
}

template<class T>
auto begin(T& t) -> decltype(t.begin()) {
    return t.begin();
}

template<class T>
auto end(T& t) -> decltype(t.end()) {
    return t.end();
}

template<class T>
auto begin(T* t) -> decltype(t->begin()) {
    return t->begin();
}

template<class T>
auto end(T* t) -> decltype(t->end()) {
    return t->end();
}

// TODO Move to hardware section.
/// Set or clear a volatile register bit.
force_inline void setBit(volatile uint8_t& reg, uint8_t bit, uint8_t value) {
    if(value) {
        reg |= _BV(bit);
    } else {
        reg &= ~_BV(bit);
    }
}

/// Set or clear a volatile register bit.
force_inline void setBit(volatile uint8_t* reg, uint8_t bit, uint8_t value) {
    if(value) {
        *reg |= _BV(bit);
    } else {
        *reg &= ~_BV(bit);
    }
}

/// Lazily set or clear a volatile register bit, for better compiler optimisation.
force_inline void setBit_(volatile uint8_t& reg, uint8_t bit, bool value) {
    if(value) {
        (uint8_t&)reg |= _BV(bit);
    } else {
        (uint8_t&)reg &= ~_BV(bit);
    }
}

/// Lazily set or clear a volatile register bit, for better compiler optimisation.
force_inline void setBit_(volatile uint8_t* reg, uint8_t bit, bool value) {
    if(value) {
        *(uint8_t*)reg |= _BV(bit);
    } else {
        *(uint8_t*)reg &= ~_BV(bit);
    }
}

#endif