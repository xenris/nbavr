/// [[Index]]

/// # Primitive types

#ifndef NBLIB_PRIMITIVE_HPP
#define NBLIB_PRIMITIVE_HPP

#include "basic.hpp"

using uint = unsigned int;

using int8_t = signed char;
using int16_t = If<sizeof(int) == 2, int, short>::Value;
using int32_t = If<sizeof(int) == 4, int, long>::Value;
using int64_t = If<sizeof(long) == 8, long, long long>::Value;

using uint8_t = unsigned char;
using uint16_t = If<sizeof(unsigned int) == 2, unsigned int, unsigned short>::Value;
using uint32_t = If<sizeof(unsigned int) == 4, unsigned int, unsigned long>::Value;
using uint64_t = If<sizeof(unsigned long) == 8, unsigned long, unsigned long long>::Value;

using size_t = If<sizeof(unsigned int) == 2, unsigned int, unsigned long>::Value;
using ssize_t = If<sizeof(int) == 2, int, long>::Value;

#ifdef __avr__
    using int24_t = __int24;
    using uint24_t = __uint24;
#endif

#ifdef __clang__
    using int24_t = int;
    using uint24_t = uint;
#endif

static_assert(sizeof(int8_t) == 1, "int8_t is not the right size");
static_assert(sizeof(int16_t) == 2, "int16_t is not the right size");
static_assert(sizeof(int32_t) == 4, "int32_t is not the right size");
static_assert(sizeof(int64_t) == 8, "int64_t is not the right size");
static_assert(sizeof(uint8_t) == 1, "uint8_t is not the right size");
static_assert(sizeof(uint16_t) == 2, "uint16_t is not the right size");
static_assert(sizeof(uint32_t) == 4, "uint32_t is not the right size");
static_assert(sizeof(uint64_t) == 8, "uint64_t is not the right size");

template <>
constexpr bool isInteger<char>() {
    return true;
}

template <>
constexpr bool isInteger<short>() {
    return true;
}

template <>
constexpr bool isInteger<int>() {
    return true;
}

template <>
constexpr bool isInteger<long>() {
    return true;
}

template <>
constexpr bool isInteger<long long>() {
    return true;
}

template <>
constexpr bool isInteger<unsigned char>() {
    return true;
}

template <>
constexpr bool isInteger<unsigned short>() {
    return true;
}

template <>
constexpr bool isInteger<unsigned int>() {
    return true;
}

template <>
constexpr bool isInteger<unsigned long>() {
    return true;
}

template <>
constexpr bool isInteger<unsigned long long>() {
    return true;
}

template <>
constexpr bool isFloating<float>() {
    return true;
}

template <>
constexpr bool isFloating<double>() {
    return true;
}

template <>
constexpr bool isFloating<long double>() {
    return true;
}

template <>
constexpr bool isBoolean<bool>() {
    return true;
}

template <>
constexpr bool isSigned<char>() {
    return true;
}

template <>
constexpr bool isSigned<signed char>() {
    return true;
}

template <>
constexpr bool isSigned<short>() {
    return true;
}

template <>
constexpr bool isSigned<int>() {
    return true;
}

template <>
constexpr bool isSigned<long>() {
    return true;
}

template <>
constexpr bool isSigned<long long>() {
    return true;
}

template <>
constexpr bool isSigned<float>() {
    return true;
}

template <>
constexpr bool isSigned<double>() {
    return true;
}

template <>
constexpr bool isSigned<long double>() {
    return true;
}

template <>
constexpr bool isUnsigned<unsigned char>() {
    return true;
}

template <>
constexpr bool isUnsigned<unsigned short>() {
    return true;
}

template <>
constexpr bool isUnsigned<unsigned int>() {
    return true;
}

template <>
constexpr bool isUnsigned<unsigned long>() {
    return true;
}

template <>
constexpr bool isUnsigned<unsigned long long>() {
    return true;
}

template <>
struct AsSigned<char> : ConstantType<char> {};

template <>
struct AsSigned<short> : ConstantType<short> {};

template <>
struct AsSigned<int> : ConstantType<int> {};

template <>
struct AsSigned<long> : ConstantType<long> {};

template <>
struct AsSigned<long long> : ConstantType<long long> {};

template <>
struct AsSigned<unsigned char> : ConstantType<char> {};

template <>
struct AsSigned<unsigned short> : ConstantType<short> {};

template <>
struct AsSigned<unsigned int> : ConstantType<int> {};

template <>
struct AsSigned<unsigned long> : ConstantType<long> {};

template <>
struct AsSigned<unsigned long long> : ConstantType<long long> {};

template <>
struct AsUnsigned<char> : ConstantType<unsigned char> {};

template <>
struct AsUnsigned<short> : ConstantType<unsigned short> {};

template <>
struct AsUnsigned<int> : ConstantType<unsigned int> {};

template <>
struct AsUnsigned<long> : ConstantType<unsigned long> {};

template <>
struct AsUnsigned<long long> : ConstantType<unsigned long long> {};

template <>
struct AsUnsigned<unsigned char> : ConstantType<unsigned char> {};

template <>
struct AsUnsigned<unsigned short> : ConstantType<unsigned short> {};

template <>
struct AsUnsigned<unsigned int> : ConstantType<unsigned int> {};

template <>
struct AsUnsigned<unsigned long> : ConstantType<unsigned long> {};

template <>
struct AsUnsigned<unsigned long long> : ConstantType<unsigned long long> {};

template <>
constexpr unsigned char max<unsigned char>() {
    return (unsigned char)(~0ull);
}

template <>
constexpr signed char max<signed char>() {
    return max<unsigned char>() >> 1;
}

template <>
constexpr unsigned short max<unsigned short>() {
    return (unsigned short)(~0ull);
}

template <>
constexpr short max<short>() {
    return max<unsigned short>() >> 1;
}

template <>
constexpr unsigned int max<unsigned int>() {
    return (unsigned int)(~0ull);
}

template <>
constexpr int max<int>() {
    return max<unsigned int>() >> 1;
}

template <>
constexpr unsigned long max<unsigned long>() {
    return (unsigned long)(~0ull);
}

template <>
constexpr long max<long>() {
    return max<unsigned long>() >> 1;
}

template <>
constexpr unsigned long long max<unsigned long long>() {
    return (unsigned long long)(~0ull);
}

template <>
constexpr long long max<long long>() {
    return max<unsigned long long>() >> 1;
}

template <>
constexpr unsigned char min<unsigned char>() {
    return 0;
}

template <>
constexpr signed char min<signed char>() {
    return (signed char)(1ll << (sizeof(signed char) * 8 - 1));
}

template <>
constexpr unsigned short min<unsigned short>() {
    return 0;
}

template <>
constexpr short min<short>() {
    return short(1ll << (sizeof(short) * 8 - 1));
}

template <>
constexpr unsigned int min<unsigned int>() {
    return 0;
}

template <>
constexpr int min<int>() {
    return int(1ll << (sizeof(int) * 8 - 1));
}

template <>
constexpr unsigned long min<unsigned long>() {
    return 0;
}

template <>
constexpr long min<long>() {
    return long(1ll << (sizeof(long) * 8 - 1));
}

template <>
constexpr unsigned long long min<unsigned long long>() {
    return 0;
}

template <>
constexpr long long min<long long>() {
    return (long long)(1ll << (sizeof(long long) * 8 - 1));
}

static_assert(max<int8_t>() == 0x7F, "");
static_assert(max<int16_t>() == 0x7FFF, "");
static_assert(max<int32_t>() == 0x7FFFFFFF, "");
static_assert(max<int64_t>() == 0x7FFFFFFFFFFFFFFF, "");
static_assert(max<uint8_t>() == 0xFF, "");
static_assert(max<uint16_t>() == 0xFFFF, "");
static_assert(max<uint32_t>() == 0xFFFFFFFF, "");
static_assert(max<uint64_t>() == 0xFFFFFFFFFFFFFFFF, "");

static_assert(min<int8_t>() == int8_t(0x80), "");
static_assert(min<int16_t>() == int16_t(0x8000), "");
static_assert(min<int32_t>() == int32_t(0x80000000), "");
static_assert(min<int64_t>() == int64_t(0x8000000000000000), "");
static_assert(min<uint8_t>() == 0, "");
static_assert(min<uint16_t>() == 0, "");
static_assert(min<uint32_t>() == 0, "");
static_assert(min<uint64_t>() == 0, "");

#endif
