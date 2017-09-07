#ifndef NBAVR_UTIL_HPP
#define NBAVR_UTIL_HPP

/// # Util

/// #### T bv(T n)
/// Equivalent to "1 << n", but works with types bigger than int.
template <typename T>
force_inline T bv(T n) {
    return T(1) << n;
}

force_inline void nop() {
    #ifndef TEST
    __asm__ __volatile__ ("nop");
    #endif
}

/// #### void cli()
/// Clear the global interrupt flag.
force_inline void cli() {
    #ifndef TEST
    __asm__ __volatile__ ("cli" ::: "memory");
    #endif
}

/// #### void sei()
/// Set the global interrupt flag.
force_inline void sei() {
    #ifndef TEST
    __asm__ __volatile__ ("sei" ::: "memory");
    #endif
}

/// #### void setBit(volatile uint8_t\* register, uint8_t bit, bool value)
/// Set or clear a bit in a volatile register immediately.
force_inline void setBit(volatile uint8_t* reg, uint8_t bit, bool value) {
    if(value) {
        *reg |= bv(bit);
    } else {
        *reg &= ~bv(bit);
    }
}

/// #### void setBit_(volatile uint8_t\* register, uint8_t bit, bool value)
/// Set or clear a bit in a volatile register lazily.
/// (i.e. Allow compiler to rearrange instructions.)
force_inline void setBit_(volatile uint8_t* reg, uint8_t bit, bool value) {
    uint8_t* reg_ = const_cast<uint8_t*>(reg);

    if(value) {
        *reg_ |= bv(bit);
    } else {
        *reg_ &= ~bv(bit);
    }
}

#endif
