#ifndef NBAVR_MATH_HPP
#define NBAVR_MATH_HPP

/// # Maths

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

#endif
