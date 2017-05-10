#ifndef NBAVR_UTIL_HPP
#define NBAVR_UTIL_HPP

/// # Util

/// #### macro CONCAT(...)
/// Concatinates a list of identifiers together.<br>
/// e.g. CONCAT(Foo, Bar) -> FooBar
#define CONCAT(...) GET_CONCAT(__VA_ARGS__, CONCAT8, CONCAT7, CONCAT6, CONCAT5, CONCAT4, CONCAT3, CONCAT2, CONCAT1)(__VA_ARGS__)

#define CONCAT1(A) A
#define CONCAT2(A, B) A ## B
#define CONCAT3(A, B, C) A ## B ## C
#define CONCAT4(A, B, C, D) A ## B ## C ## D
#define CONCAT5(A, B, C, D, E) A ## B ## C ## D ## E
#define CONCAT6(A, B, C, D, E, F) A ## B ## C ## D ## E ## F
#define CONCAT7(A, B, C, D, E, F, G) A ## B ## C ## D ## E ## F ## G
#define CONCAT8(A, B, C, D, E, F, G, H) A ## B ## C ## D ## E ## F ## G ## H

#define GET_CONCAT(_1, _2, _3, _4, _5, _6, _7, _8, NAME,...) NAME

#define UNDERLINE(...) GET_UNDERLINE(__VA_ARGS__, UNDERLINE8, UNDERLINE7, UNDERLINE6, UNDERLINE5, UNDERLINE4, UNDERLINE3, UNDERLINE2, UNDERLINE1)(__VA_ARGS__)

#define UNDERLINE1(A) _ ## A ## _
#define UNDERLINE2(A, B) _ ## A ## _ ## B ## _
#define UNDERLINE3(A, B, C) _ ## A ## _ ## B ## _ ## C ## _
#define UNDERLINE4(A, B, C, D) _ ## A ## _ ## B ## _ ## C ## _ ## D ## _
#define UNDERLINE5(A, B, C, D, E) _ ## A ## _ ## B ## _ ## C ## _ ## D ## _ ## E ## _
#define UNDERLINE6(A, B, C, D, E, F) _ ## A ## _ ## B ## _ ## C ## _ ## D ## _ ## E ## _ ## F ## _
#define UNDERLINE7(A, B, C, D, E, F, G) _ ## A ## _ ## B ## _ ## C ## _ ## D ## _ ## E ## _ ## F ## _ ## G ## _
#define UNDERLINE8(A, B, C, D, E, F, G, H) _ ## A ## _ ## B ## _ ## C ## _ ## D ## _ ## E ## _ ## F ## _ ## G ## _ ## H  ## _

#define GET_UNDERLINE(_1, _2, _3, _4, _5, _6, _7, _8, NAME,...) NAME

#define TO_LETTER(N) CONCAT(TO_LETTER_, N)
#define TO_LETTER_0 A
#define TO_LETTER_1 B
#define TO_LETTER_2 C
#define TO_LETTER_3 D
#define TO_LETTER_4 E
#define TO_LETTER_5 F
#define TO_LETTER_6 G
#define TO_LETTER_7 H
#define TO_LETTER_8 I
#define TO_LETTER_9 J
#define TO_LETTER_10 K
#define TO_LETTER_11 L
#define TO_LETTER_12 M
#define TO_LETTER_13 N
#define TO_LETTER_14 O
#define TO_LETTER_15 P
#define TO_LETTER_16 Q
#define TO_LETTER_17 R
#define TO_LETTER_18 S
#define TO_LETTER_19 T
#define TO_LETTER_20 U
#define TO_LETTER_21 V
#define TO_LETTER_22 W
#define TO_LETTER_23 X
#define TO_LETTER_24 Y
#define TO_LETTER_25 Z

#define bv(n) (1 << (n))

/// #### macro force_inline
/// Force a function to always be inlined. Use like "inline".
#define force_inline inline __attribute__((always_inline))

force_inline void nop() {
    __asm__ __volatile__ ("nop");
}

force_inline void _MemoryBarrier(const uint8_t *s = nullptr) {
    __asm__ __volatile__("":::"memory");
}

/// #### void cli()
/// Clear the global interrupt flag.
force_inline void cli() {
    __asm__ __volatile__ ("cli" ::: "memory");
}

/// #### void sei()
/// Set the global interrupt flag.
force_inline void sei() {
    __asm__ __volatile__ ("sei" ::: "memory");
}

force_inline uint8_t __cli() {
    uint8_t s = *CHIP_STATUS_REG;
    cli();
    return s;
}

force_inline uint8_t __sei() {
    uint8_t s = *CHIP_STATUS_REG;
    sei();
    return s;
}

force_inline void __ssreg(const uint8_t *s) {
    *CHIP_STATUS_REG = *s;
}

/// #### macro atomic
/// Make sure an expression or block of expressions run with global interrupts disabled.
#define atomic for(uint8_t __sreg __attribute__((cleanup(__ssreg))) = __cli(), __once = 1; __once; __once = 0)

/// #### macro nonatomic
/// Make sure an expression or block of expressions run with global interrupts enabled.
#define nonatomic for(uint8_t __sreg __attribute__((cleanup(__ssreg))) = __sei(), __once = 1; __once; __once = 0)

/// #### macro block
/// Make sure an expression or block of expressions is compiled in the order it is written in.
/// i.e. Prevents the compiler from doing memory accesses optimisations that reorder code.
#define block for(uint8_t __once __attribute__((cleanup(_MemoryBarrier))) = 1; __once; __once = 0)

#define ISR(vector, ...) \
    extern "C" void vector(void) __attribute__((signal,used,externally_visible)) __VA_ARGS__; \
    void vector(void)

/// #### T max(T, T)
/// Get the bigger of the two values.
template<class T>
constexpr force_inline T max(T a, T b) {
    return a > b ? a : b;
}

/// #### T max(T, T)
/// Get the smaller of the two values.
template<class T>
constexpr force_inline T min(T a, T b) {
    return a < b ? a : b;
}

/// #### T clip(T x, T l, T h)
/// Clip x between l and h.
template<class T>
constexpr force_inline T clip(T x, T l, T h) {
    return max(min(x, h), l);
}

/// #### T abs(T)
/// Get the absolute (positive) value.
template<class T>
constexpr force_inline T abs(T a) {
    return a >= 0 ? a : -a;
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

/// #### void setBit(volatile uint8_t* register, uint8_t bit, bool)
/// Set or clear a bit in a volatile register immediately.
force_inline void setBit(volatile uint8_t* reg, uint8_t bit, bool value) {
    if(value) {
        *reg |= bv(bit);
    } else {
        *reg &= ~bv(bit);
    }
}

/// #### void setBit_(volatile uint8_t* register, uint8_t bit, bool)
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
