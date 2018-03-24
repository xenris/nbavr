#ifndef NBOS_MATH_HPP
#define NBOS_MATH_HPP

/// # Maths

#include "macros.hpp"
#include "type.hpp"

namespace nbos {

/// #### T max(T a, T b)
/// Get the bigger of the two values.
template<class T>
constexpr force_inline T max(T a, T b) {
    return a > b ? a : b;
}

/// #### T min(T a, T b)
/// Get the smaller of the two values.
template<class T>
constexpr force_inline T min(T a, T b) {
    return a < b ? a : b;
}

/// #### T clip(T n, T l, T h)
/// Clip x between l and h.
template<class T>
constexpr force_inline T clip(T n, T l, T h) {
    return max(min(n, h), l);
}

/// #### T abs(T a)
/// Get the absolute (positive) value.
template<class T>
constexpr force_inline T abs(T a) {
    return a >= 0 ? a : -a;
}

template <class T>
T cos(T n) {
    static_assert(is_floating<T>::value, "cos requires either float or double");

    return __builtin_cos(n);
}

template <class T>
T floor(T n) {
    static_assert(is_floating<T>::value, "floor requires either float or double");

    return __builtin_floor(n);
}

template <class T>
T fmod(T n, T p) {
    static_assert(is_floating<T>::value, "fmod requires either float or double");

    return __builtin_fmod(n, p);
}

template <class T>
T log10(T n) {
    static_assert(is_floating<T>::value, "log10 requires either float or double");

    return __builtin_log10(n);
}

template <class T>
T modf(T n, T* i) {
    static_assert(is_floating<T>::value, "modf requires either float or double");

    if constexpr (is_same<T, float>::value) {
        return __builtin_modff(n, i);
    } else if constexpr (is_same<T, double>::value) {
        return __builtin_modf(n, i);
    }
}

template <class T>
T pow(T n, T p) {
    static_assert(is_floating<T>::value, "pow requires either float or double");

    return __builtin_pow(n, p);
}

template <class T>
T round(T n) {
    static_assert(is_floating<T>::value, "round requires either float or double");

    return __builtin_round(n);
}

template <class T>
T sin(T n) {
    static_assert(is_floating<T>::value, "sin requires either float or double");

    return __builtin_sin(n);
}

template <class T>
T tan(T n) {
    static_assert(is_floating<T>::value, "tan requires either float or double");

    return __builtin_tan(n);
}

template <typename T>
struct lesser {
    constexpr bool operator()(const T &a, const T &b) const {
        return a < b;
    }
};

template <typename T>
struct greater {
    constexpr bool operator()(const T &a, const T &b) const {
        return a > b;
    }
};

} // nbos

#endif
