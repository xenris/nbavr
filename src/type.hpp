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

#endif
