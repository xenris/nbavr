/// [[Index]]

/// # {{Basic}}

#ifndef NBLIB_BASIC_HPP
#define NBLIB_BASIC_HPP

template <class _T>
struct ConstantType {
    using Value = _T;
    using T = _T;
};

template <bool B, class T, class F>
struct If : ConstantType<T> {};

template <class T, class F>
struct If<false, T, F> : ConstantType<F> {};

template <class T, class U>
struct IsSame {
    static constexpr bool t = false;
};

template <class T>
struct IsSame<T, T> {
    static constexpr bool t = true;
};

template <class T, class U>
constexpr bool isSame() {
    return IsSame<T, U>::t;
}

template <class T>
constexpr bool isInteger() {
    return false;
}

template <class T>
constexpr bool isFloating() {
    return false;
}

template <class T>
constexpr bool isBoolean() {
    return false;
}

template <class T>
constexpr bool isSigned() {
    return false;
}

template <class T>
constexpr bool isUnsigned() {
    return false;
}

template <class T>
struct AsSigned {};

template <class T>
struct AsUnsigned {};

template <class T>
constexpr T max();

template <class T>
constexpr T min();

#endif
