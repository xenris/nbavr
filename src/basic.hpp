/// [[Index]]

/// # {{Basic}}

#ifndef NBLIB_BASIC_HPP
#define NBLIB_BASIC_HPP

/// ### block\(expr\)
/// Prevents the expression from being optimised into the code around it. e.g.
/// ```c++
/// LedPin::output(LedPin::Value::high);
/// LedPin::output(LedPin::Value::low);
/// ```
/// will only set the pin low, because the compiler saw that this was the overall effect of the expressions. Whereas:
/// ```c++
/// block(LedPin::output(LedPin::Value::high));
/// block(LedPin::output(LedPin::Value::low));
/// ```
/// will set the pin high, then low:

/// ### block\(\) \{expr1; expr2; expr3; etc...\}
/// Same as block(expr), but allows several expressions to be optimised together, separate to any code around it.
#ifdef __clang__
    #define block(...) __VA_ARGS__
#else
    #define block(...) CAT(block_, LENGTH(__VA_ARGS__))(__VA_ARGS__)
    #define block_0() if(nblib::__Block __b; true)
    #define block_1(A) (nblib::__Block(), A)
    #define block_2(A, B) (nblib::__Block(), nblib::__getThenSet(A, B))
#endif

namespace nblib {

template <class T>
T __getThenSet(T& a, const T& b) {
    const T t = a;
    a = b;
    return t;
}

struct __Block {
    __Block() {
        asm volatile("" ::: "memory");
    }

    ~__Block() {
        asm volatile("" ::: "memory");
    }
};

}

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
