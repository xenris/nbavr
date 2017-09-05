#ifndef NBAVR_UTIL_HPP
#define NBAVR_UTIL_HPP

/// # Util

/// #### macro force_inline
/// Force a function to always be inlined. Use like "inline".
#define force_inline inline __attribute__((always_inline))

template <typename T>
force_inline T bv(T n) {
    return T(1) << n;
}

force_inline void nop() {
    #ifndef TEST
    __asm__ __volatile__ ("nop");
    #endif
}

force_inline uint8_t _MemoryBarrier(const uint8_t *s = nullptr) {
    #ifndef TEST
    __asm__ __volatile__("":::"memory");
    #endif

    return 1;
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
#define block for(uint8_t __once __attribute__((cleanup(_MemoryBarrier))) = _MemoryBarrier(); __once; __once = 0)

#ifndef TEST
#define ISR(vector, ...) \
    extern "C" void vector(void) __attribute__((signal,used,externally_visible)) __VA_ARGS__; \
    void vector(void)
#else
#define ISR(vector, ...) void vector(void)
#endif

// /// #### T max(T, T)
// /// Get the bigger of the two values.
// template<class T>
// constexpr force_inline T max(T a, T b) {
//     return a > b ? a : b;
// }
//
// /// #### T max(T, T)
// /// Get the smaller of the two values.
// template<class T>
// constexpr force_inline T min(T a, T b) {
//     return a < b ? a : b;
// }
//
// /// #### T clip(T x, T l, T h)
// /// Clip x between l and h.
// template<class T>
// constexpr force_inline T clip(T x, T l, T h) {
//     return max(min(x, h), l);
// }
//
// /// #### T abs(T)
// /// Get the absolute (positive) value.
// template<class T>
// constexpr force_inline T abs(T a) {
//     return a >= 0 ? a : -a;
// }
//
// /// #### T* reverse(T* array, size_t length)
// /// Reverse an array.
// template <typename T>
// force_inline T* reverse(T* array, size_t length) {
//     for(size_t i = 0; i < (length + 1) / 2; i++) {
//         const size_t j = (length - 1) - i;
//         const T temp = array[i];
//         array[i] = array[j];
//         array[j] = temp;
//     }
//
//     return array;
// }
//
// /// #### void swap(T& a, T& b)
// /// Swap two variables.
// template <typename T>
// force_inline void swap(T& a, T& b) {
//     T t = a;
//     a = b;
//     b = t;
// }
//
// template<class T>
// auto begin(T& t) -> decltype(t.begin()) {
//     return t.begin();
// }
//
// template<class T>
// auto end(T& t) -> decltype(t.end()) {
//     return t.end();
// }
//
// template<class T>
// auto begin(T* t) -> decltype(t->begin()) {
//     return t->begin();
// }
//
// template<class T>
// auto end(T* t) -> decltype(t->end()) {
//     return t->end();
// }

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

// template <typename T>
// struct lesser {
//     constexpr bool operator()(const T &a, const T &b) const {
//         return a < b;
//     }
// };
//
// template <typename T>
// struct greater {
//     constexpr bool operator()(const T &a, const T &b) const {
//         return a > b;
//     }
// };

#endif
