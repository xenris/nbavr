#ifndef NBAVR_TYPE_INFO_HPP
#define NBAVR_TYPE_INFO_HPP

template <class T>
struct type_info {
    // typedef void as_signed;
    // typedef void as_unsigned;
    // typedef void double_width;
    // typedef void half_width;
    // constexpr static bool is_signed = false;
    // constexpr static bool is_unsigned = !is_signed;
    // constexpr static bool is_integer = true;
    // constexpr static T max = 0;
    // constexpr static T min = 0;
    // constexpr static T num_digits = 0;
};

template <>
struct type_info<int8_t> {
    typedef int8_t as_signed;
    typedef uint8_t as_unsigned;
    typedef int16_t double_width;
    typedef int8_t half_width;
    constexpr static bool is_signed = true;
    constexpr static bool is_unsigned = !is_signed;
    constexpr static bool is_integer = true;
    constexpr static int8_t max = 0x7f;
    constexpr static int8_t min = -max - 1;
    constexpr static int8_t num_digits = 3;
};

template <>
struct type_info<uint8_t> {
    typedef int8_t as_signed;
    typedef uint8_t as_unsigned;
    typedef uint16_t double_width;
    typedef uint8_t half_width;
    constexpr static bool is_signed = false;
    constexpr static bool is_unsigned = !is_signed;
    constexpr static bool is_integer = true;
    constexpr static uint8_t max = type_info<as_signed>::max * 2 + 1;
    constexpr static uint8_t min = 0;
    constexpr static uint8_t num_digits = 3;
};

template <>
struct type_info<int16_t> {
    typedef int16_t as_signed;
    typedef uint16_t as_unsigned;
    typedef int32_t double_width;
    typedef int8_t half_width;
    constexpr static bool is_signed = true;
    constexpr static bool is_unsigned = !is_signed;
    constexpr static bool is_integer = true;
    constexpr static int16_t max = 0x7fff;
    constexpr static int16_t min = -max - 1;
    constexpr static int16_t num_digits = 5;
};

template <>
struct type_info<uint16_t> {
    typedef int16_t as_signed;
    typedef uint16_t as_unsigned;
    typedef uint32_t double_width;
    typedef uint8_t half_width;
    constexpr static bool is_signed = false;
    constexpr static bool is_unsigned = !is_signed;
    constexpr static bool is_integer = true;
    constexpr static uint16_t max = uint16_t(type_info<as_signed>::max) * 2 + 1;
    constexpr static uint16_t min = 0;
    constexpr static uint16_t num_digits = 5;
};

template <>
struct type_info<int32_t> {
    typedef int32_t as_signed;
    typedef uint32_t as_unsigned;
    typedef int64_t double_width;
    typedef int16_t half_width;
    constexpr static bool is_signed = true;
    constexpr static bool is_unsigned = !is_signed;
    constexpr static bool is_integer = true;
    constexpr static int32_t max = 0x7fffffff;
    constexpr static int32_t min = -max - 1;
    constexpr static int32_t num_digits = 10;
};

template <>
struct type_info<uint32_t> {
    typedef int32_t as_signed;
    typedef uint32_t as_unsigned;
    typedef uint64_t double_width;
    typedef uint16_t half_width;
    constexpr static bool is_signed = false;
    constexpr static bool is_unsigned = !is_signed;
    constexpr static bool is_integer = true;
    constexpr static uint32_t max = uint32_t(type_info<as_signed>::max) * 2 + 1;
    constexpr static uint32_t min = 0;
    constexpr static uint32_t num_digits = 10;
};

template <>
struct type_info<int64_t> {
    typedef int64_t as_signed;
    typedef uint64_t as_unsigned;
    typedef void double_width;
    typedef int32_t half_width;
    constexpr static bool is_signed = true;
    constexpr static bool is_unsigned = !is_signed;
    constexpr static bool is_integer = true;
    constexpr static int64_t max = 0x7fffffffffffffff;
    constexpr static int64_t min = -max - 1;
    constexpr static int64_t num_digits = 20;
};

template <>
struct type_info<uint64_t> {
    typedef int64_t as_signed;
    typedef uint64_t as_unsigned;
    typedef void double_width;
    typedef uint32_t half_width;
    constexpr static bool is_signed = false;
    constexpr static bool is_unsigned = !is_signed;
    constexpr static bool is_integer = true;
    constexpr static uint64_t max = uint64_t(type_info<as_signed>::max) * 2 + 1;
    constexpr static uint64_t min = 0;
    constexpr static uint64_t num_digits = 20;
};

template <>
struct type_info<float> {
    typedef float as_signed;
    typedef void as_unsigned;
    typedef double double_width;
    typedef float half_width;
    constexpr static bool is_signed = true;
    constexpr static bool is_unsigned = !is_signed;
    constexpr static bool is_integer = false;
};

template <>
struct type_info<double> {
    typedef double as_signed;
    typedef void as_unsigned;
    typedef void double_width;
    typedef float half_width;
    constexpr static bool is_signed = true;
    constexpr static bool is_unsigned = !is_signed;
    constexpr static bool is_integer = false;
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

template<class T, class U>
struct is_same : integral_constant<bool, false> {
};

template<class T>
struct is_same<T, T> : integral_constant<bool, true> {
};

#endif
