#ifndef NBAVR_TYPE_HPP
#define NBAVR_TYPE_HPP

#ifndef TEST

using int8_t = signed char;
using uint8_t = unsigned char;

using int16_t = signed int;
using uint16_t = unsigned int;

using int32_t = signed long;
using uint32_t = unsigned long;

using int64_t = signed long long;
using uint64_t = unsigned long long;

using size_t = unsigned int;
using ssize_t = signed int;

#endif

using callback_t = void (*)(void*);

struct nulltype {
    nulltype(auto n) {}
};

template <class A, class B = A>
struct tuple2 {
    A a;
    B b;

    tuple2(A a, B b)
        : a(a), b(b) {}
};

template <class A, class B = A>
using tuple = tuple2<A, B>;

template <class A, class B = A, class C = B>
struct tuple3 {
    A a;
    B b;
    C c;

    tuple3(A a, B b, C c)
        : a(a), b(b), c(c) {}
};

template <class A, class B = A, class C = B, class D = C>
struct tuple4 {
    A a;
    B b;
    C c;
    D d;

    tuple4(A a, B b, C c, D d)
        : a(a), b(b), c(c), d(d) {}
};

template <class A, class B = A, class C = B, class D = C, class E = D>
struct tuple5 {
    A a;
    B b;
    C c;
    D d;
    E e;

    tuple5(A a, B b, C c, D d, E e)
        : a(a), b(b), c(c), d(d), e(e) {}
};

template<bool B, class T, class F>
struct conditional {
    typedef T type;
};

template<class T, class F>
struct conditional<false, T, F> {
    typedef F type;
};

template<class T, T v>
struct integral_constant {
    static constexpr T value = v;
};

template<class T>
struct type_constant {
    using type = T;
};

template<class T, class U>
struct is_same : integral_constant<bool, false> {};

template<class T>
struct is_same<T, T> : integral_constant<bool, true> {};

template<class T>
struct as_signed {};

template<>
struct as_signed<int8_t> : type_constant<int8_t> {};

template<>
struct as_signed<uint8_t> : type_constant<int8_t> {};

template<>
struct as_signed<int16_t> : type_constant<int16_t> {};

template<>
struct as_signed<uint16_t> : type_constant<int16_t> {};

template<>
struct as_signed<int32_t> : type_constant<int32_t> {};

template<>
struct as_signed<uint32_t> : type_constant<int32_t> {};

template<>
struct as_signed<int64_t> : type_constant<int64_t> {};

template<>
struct as_signed<uint64_t> : type_constant<int64_t> {};

template<class T>
struct as_unsigned {};

template<>
struct as_unsigned<int8_t> : type_constant<uint8_t> {};

template<>
struct as_unsigned<uint8_t> : type_constant<uint8_t> {};

template<>
struct as_unsigned<int16_t> : type_constant<uint16_t> {};

template<>
struct as_unsigned<uint16_t> : type_constant<uint16_t> {};

template<>
struct as_unsigned<int32_t> : type_constant<uint32_t> {};

template<>
struct as_unsigned<uint32_t> : type_constant<uint32_t> {};

template<>
struct as_unsigned<int64_t> : type_constant<uint64_t> {};

template<>
struct as_unsigned<uint64_t> : type_constant<uint64_t> {};

template<class T>
struct is_signed {};

template<>
struct is_signed<int8_t> : integral_constant<bool, true> {};

template<>
struct is_signed<uint8_t> : integral_constant<bool, false> {};

template<>
struct is_signed<int16_t> : integral_constant<bool, true> {};

template<>
struct is_signed<uint16_t> : integral_constant<bool, false> {};

template<>
struct is_signed<int32_t> : integral_constant<bool, true> {};

template<>
struct is_signed<uint32_t> : integral_constant<bool, false> {};

template<>
struct is_signed<int64_t> : integral_constant<bool, true> {};

template<>
struct is_signed<uint64_t> : integral_constant<bool, false> {};

template<class T>
struct is_integer : integral_constant<bool, false> {};

template<>
struct is_integer<int8_t> : integral_constant<bool, true> {};

template<>
struct is_integer<uint8_t> : integral_constant<bool, true> {};

template<>
struct is_integer<int16_t> : integral_constant<bool, true> {};

template<>
struct is_integer<uint16_t> : integral_constant<bool, true> {};

template<>
struct is_integer<int32_t> : integral_constant<bool, true> {};

template<>
struct is_integer<uint32_t> : integral_constant<bool, true> {};

template<>
struct is_integer<int64_t> : integral_constant<bool, true> {};

template<>
struct is_integer<uint64_t> : integral_constant<bool, true> {};

template<class T>
struct is_floating : integral_constant<bool, false> {};

template<>
struct is_floating<float> : integral_constant<bool, true> {};

template<>
struct is_floating<double> : integral_constant<bool, true> {};

template<class T>
struct double_width {};

template<>
struct double_width<int8_t> : type_constant<int16_t> {};

template<>
struct double_width<uint8_t> : type_constant<uint16_t> {};

template<>
struct double_width<int16_t> : type_constant<int32_t> {};

template<>
struct double_width<uint16_t> : type_constant<uint32_t> {};

template<>
struct double_width<int32_t> : type_constant<int64_t> {};

template<>
struct double_width<uint32_t> : type_constant<uint64_t> {};

template<class T>
struct half_width {};

template<>
struct half_width<int8_t> : type_constant<int8_t> {};

template<>
struct half_width<uint8_t> : type_constant<uint8_t> {};

template<>
struct half_width<int16_t> : type_constant<int8_t> {};

template<>
struct half_width<uint16_t> : type_constant<uint8_t> {};

template<>
struct half_width<int32_t> : type_constant<int16_t> {};

template<>
struct half_width<uint32_t> : type_constant<uint16_t> {};

template<>
struct half_width<int64_t> : type_constant<int32_t> {};

template<>
struct half_width<uint64_t> : type_constant<uint32_t> {};

template<class T>
struct type_name {};

template<>
struct type_name<int8_t> {
    static constexpr const char* value = "int8_t";
};

template<>
struct type_name<uint8_t> {
    static constexpr const char* value = "uint8_t";
};

template<>
struct type_name<int16_t> {
    static constexpr const char* value = "int16_t";
};

template<>
struct type_name<uint16_t> {
    static constexpr const char* value = "uint16_t";
};

template<>
struct type_name<int32_t> {
    static constexpr const char* value = "int32_t";
};

template<>
struct type_name<uint32_t> {
    static constexpr const char* value = "uint32_t";
};

template<>
struct type_name<int64_t> {
    static constexpr const char* value = "int64_t";
};

template<>
struct type_name<uint64_t> {
    static constexpr const char* value = "uint64_t";
};

template<>
struct type_name<float> {
    static constexpr const char* value = "float";
};

template<>
struct type_name<double> {
    static constexpr const char* value = "double";
};

template<>
struct type_name<bool> {
    static constexpr const char* value = "bool";
};

template<class T>
struct integer_max {};

template<>
struct integer_max<int8_t> : integral_constant<int8_t, 0x7F> {};

template<>
struct integer_max<uint8_t> : integral_constant<uint8_t, 0xFF> {};

template<>
struct integer_max<int16_t> : integral_constant<int16_t, 0x7FFF> {};

template<>
struct integer_max<uint16_t> : integral_constant<uint16_t, 0xFFFF> {};

template<>
struct integer_max<int32_t> : integral_constant<int32_t, 0x7FFFFFFF> {};

template<>
struct integer_max<uint32_t> : integral_constant<uint32_t, 0xFFFFFFFF> {};

template<>
struct integer_max<int64_t> : integral_constant<int64_t, 0x7FFFFFFFFFFFFFFF> {};

template<>
struct integer_max<uint64_t> : integral_constant<uint64_t, 0xFFFFFFFFFFFFFFFF> {};

template<class T>
struct integer_min {};

template<>
struct integer_min<int8_t> : integral_constant<int8_t, 0xFF> {};

template<>
struct integer_min<uint8_t> : integral_constant<uint8_t, 0x00> {};

template<>
struct integer_min<int16_t> : integral_constant<int16_t, 0xFFFF> {};

template<>
struct integer_min<uint16_t> : integral_constant<uint16_t, 0x0000> {};

template<>
struct integer_min<int32_t> : integral_constant<int32_t, 0xFFFFFFFF> {};

template<>
struct integer_min<uint32_t> : integral_constant<uint32_t, 0x00000000> {};

template<>
struct integer_min<int64_t> : integral_constant<int64_t, 0xFFFFFFFFFFFFFFFF> {};

template<>
struct integer_min<uint64_t> : integral_constant<uint64_t, 0x0000000000000000> {};

template <class T>
class optional {
    bool hasValue;
    T value;

public:

    optional() : hasValue(false) {
    }

    optional(T v) : hasValue(true), value(v) {
    }

    operator bool() const {
        return hasValue;
    }

    T& operator *() {
        return value;
    }
};

#endif
