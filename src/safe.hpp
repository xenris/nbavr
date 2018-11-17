/// [[Index]]

/// # {{Safe}}

/// TODO

#ifndef NBOS_SAFE_HPP
#define NBOS_SAFE_HPP

#include "primitive.hpp"
#include "basic.hpp"

struct Bool {
    using T = primitive_bool;

private:

    T _value;

public:

    constexpr Bool() : _value(false) {
    }

    constexpr Bool(T value) : _value(value) {
    }

    explicit constexpr operator T() const {
        return _value;
    }

    constexpr Bool operator ==(const Bool o) const {
        return _value == o._value;
    }

    constexpr Bool operator !=(const Bool o) const {
        return _value != o._value;
    }

    constexpr T& operator *() {
        return _value;
    }

    constexpr const T& operator *() const {
        return _value;
    }

    constexpr Bool operator ^(const Bool o) const {
        return _value ^ o._value;
    }

    constexpr Bool operator |(const Bool o) const {
        return _value | o._value;
    }

    constexpr Bool operator &(const Bool o) const {
        return _value & o._value;
    }

    constexpr Bool operator !() const {
        return !_value;
    }

    constexpr Bool& operator ^=(const Bool o) {
        _value ^= o._value;

        return *this;
    }

    constexpr Bool& operator |=(const Bool o) {
        _value |= o._value;

        return *this;
    }

    constexpr Bool& operator &=(const Bool o) {
        _value &= o._value;

        return *this;
    }

    explicit constexpr operator Int() const {
        return _value;
    }

    explicit constexpr operator Integer() const {
        return _value;
    }
};

#define STANDARD_OPERATORS(NAME) \
    constexpr Bool operator ==(const NAME o) const { \
        return _value == o._value; \
    } \
    constexpr Bool operator !=(const NAME o) const { \
        return _value != o._value; \
    } \
    constexpr Bool operator <(const NAME o) const { \
        return _value < o._value; \
    } \
    constexpr Bool operator <=(const NAME o) const { \
        return _value <= o._value; \
    } \
    constexpr Bool operator >(const NAME o) const { \
        return _value > o._value; \
    } \
    constexpr Bool operator >=(const NAME o) const { \
        return _value >= o._value; \
    } \
    constexpr NAME operator +(const NAME o) const { \
        return _value + o._value; \
    } \
    constexpr NAME& operator +=(const NAME o) { \
        _value += o._value; \
        return *this; \
    } \
    constexpr NAME operator -(const NAME o) const { \
        return _value - o._value; \
    } \
    constexpr NAME& operator -=(const NAME o) { \
        _value -= o._value; \
        return *this; \
    } \
    constexpr NAME operator *(const NAME o) const { \
        return _value * o._value; \
    } \
    constexpr NAME& operator *=(const NAME o) { \
        _value *= o._value; \
        return *this; \
    } \
    constexpr NAME operator /(const NAME o) const { \
        return _value / o._value; \
    } \
    constexpr NAME& operator /=(const NAME o) { \
        _value /= o._value; \
        return *this; \
    } \
    constexpr NAME& operator ++() { \
        ++_value; \
        return *this; \
    } \
    constexpr NAME operator ++(primitive_signed_int) { \
        const NAME result = *this; \
        _value++; \
        return result; \
    } \
    constexpr NAME& operator --() { \
        --_value; \
        return *this; \
    } \
    constexpr NAME operator --(primitive_signed_int) { \
        const NAME result = *this; \
        _value--; \
        return result; \
    } \
    constexpr NAME operator -() const { \
        return -_value; \
    } \
    constexpr T& operator *() { \
        return _value; \
    } \
    constexpr const T& operator *() const { \
        return _value; \
    }

#define MODULOUS_OPERATORS(NAME) \
    constexpr NAME operator %(const NAME o) const { \
        return _value % o._value; \
    } \
    constexpr NAME& operator %=(const NAME o) { \
        _value %= o._value; \
        return *this; \
    } \

#define BITWISE_OPERATORS(NAME) \
    constexpr NAME operator ^(const NAME o) const { \
        return _value ^ o._value; \
    } \
    constexpr NAME operator |(const NAME o) const { \
        return _value | o._value; \
    } \
    constexpr NAME operator &(const NAME o) const { \
        return _value & o._value; \
    } \
    constexpr NAME operator ~() const { \
        return ~_value; \
    } \
    constexpr NAME operator >>(const NAME o) const { \
        return _value >> o._value; \
    } \
    constexpr NAME operator <<(const NAME o) const { \
        return _value << o._value; \
    } \
    constexpr NAME& operator ^=(const NAME o) { \
        _value ^= o._value; \
        return *this; \
    } \
    constexpr NAME& operator |=(const NAME o) { \
        _value |= o._value; \
        return *this; \
    } \
    constexpr NAME& operator &=(const NAME o) { \
        _value &= o._value; \
        return *this; \
    } \
    constexpr NAME& operator >>=(const NAME o) { \
        _value >>= o._value; \
        return *this; \
    } \
    constexpr NAME& operator <<=(const NAME o) { \
        _value <<= o._value; \
        return *this; \
    }

struct Char {
    using T = primitive_signed_char;

private:

    T _value;

public:

    constexpr Char() : _value('\0') {
    }

    constexpr Char(T value) : _value(value) {
    }

    constexpr Bool operator ==(const Char o) const {
        return _value == o._value;
    }

    constexpr Bool operator !=(const Char o) const {
        return _value != o._value;
    }

    constexpr Bool operator <(const Char o) const {
        return _value < o._value;
    }

    constexpr Bool operator <=(const Char o) const {
        return _value <= o._value;
    }

    constexpr Bool operator >(const Char o) const {
        return _value > o._value;
    }

    constexpr Bool operator >=(const Char o) const {
        return _value >= o._value;
    }

    constexpr T& operator *() {
        return _value;
    }

    constexpr const T& operator *() const {
        return _value;
    }

    explicit constexpr operator Bool() const {
        return _value != 0;
    }

    explicit constexpr operator Int() const {
        return _value;
    }

    explicit constexpr operator Integer() const {
        return _value;
    }
};

struct Int8 {
    using T = primitive_signed_char;

private:

    T _value;

public:

    constexpr Int8() : _value(0) {
    }

    constexpr Int8(T value) : _value(value) {
    }

    explicit constexpr Int8(Bool value) : _value(*value) {
    }

    explicit constexpr Int8(Char value) : _value(*value) {
    }

    STANDARD_OPERATORS(Int8)

    MODULOUS_OPERATORS(Int8)

    BITWISE_OPERATORS(Int8)

    explicit constexpr operator Bool() const {
        return _value != 0;
    }

    explicit constexpr operator Char() const {
        return _value;
    }

    explicit constexpr operator Int() const {
        return _value;
    }

    explicit constexpr operator Integer() const {
        return _value;
    }
};

struct Int16 {
    using T = primitive_signed_short;

private:

    T _value;

public:

    constexpr Int16() : _value(0) {
    }

    constexpr Int16(T value) : _value(value) {
    }

    explicit constexpr Int16(Bool value) : _value(*value) {
    }

    explicit constexpr Int16(Char value) : _value(*value) {
    }

    explicit constexpr Int16(Int8 value) : _value(*value) {
    }

    STANDARD_OPERATORS(Int16)

    MODULOUS_OPERATORS(Int16)

    BITWISE_OPERATORS(Int16)

    explicit constexpr operator Int8() const {
        return _value;
    }

    explicit constexpr operator Bool() const {
        return _value != 0;
    }

    explicit constexpr operator Char() const {
        return _value;
    }

    explicit constexpr operator Int() const {
        return _value;
    }

    explicit constexpr operator Integer() const {
        return _value;
    }
};

struct Int32 {
    using T = If<sizeof(primitive_signed_int) == 4, primitive_signed_int, primitive_signed_long>::Value;

private:

    T _value;

public:

    constexpr Int32() : _value(0) {
    }

    constexpr Int32(T value) : _value(value) {
    }

    explicit constexpr Int32(Bool value) : _value(*value) {
    }

    explicit constexpr Int32(Char value) : _value(*value) {
    }

    explicit constexpr Int32(Int8 value) : _value(*value) {
    }

    explicit constexpr Int32(Int16 value) : _value(*value) {
    }

    STANDARD_OPERATORS(Int32)

    MODULOUS_OPERATORS(Int32)

    BITWISE_OPERATORS(Int32)

    explicit constexpr operator Int8() const {
        return _value;
    }

    explicit constexpr operator Int16() const {
        return _value;
    }

    explicit constexpr operator Bool() const {
        return _value != 0;
    }

    explicit constexpr operator Char() const {
        return _value;
    }

    explicit constexpr operator Int() const {
        return _value;
    }

    explicit constexpr operator Integer() const {
        return _value;
    }
};

struct Int64 {
    using T = primitive_signed_long_long;

private:

    T _value;

public:

    constexpr Int64() : _value(0) {
    }

    constexpr Int64(T value) : _value(value) {
    }

    explicit constexpr Int64(Bool value) : _value(*value) {
    }

    explicit constexpr Int64(Char value) : _value(*value) {
    }

    explicit constexpr Int64(Int8 value) : _value(*value) {
    }

    explicit constexpr Int64(Int16 value) : _value(*value) {
    }

    explicit constexpr Int64(Int32 value) : _value(*value) {
    }

    STANDARD_OPERATORS(Int64)

    MODULOUS_OPERATORS(Int64)

    BITWISE_OPERATORS(Int64)

    explicit constexpr operator Int8() const {
        return _value;
    }

    explicit constexpr operator Int16() const {
        return _value;
    }

    explicit constexpr operator Int32() const {
        return _value;
    }

    explicit constexpr operator Bool() const {
        return _value != 0;
    }

    explicit constexpr operator Char() const {
        return _value;
    }

    explicit constexpr operator Int() const {
        return _value;
    }

    explicit constexpr operator Integer() const {
        return _value;
    }
};

struct Word8 {
    using T = primitive_unsigned_char;

private:

    T _value;

public:

    constexpr Word8() : _value(0) {
    }

    constexpr Word8(T value) : _value(value) {
    }

    explicit constexpr Word8(Bool value) : _value(*value) {
    }

    explicit constexpr Word8(Char value) : _value(*value) {
    }

    explicit constexpr Word8(Int8 value) : _value(*value) {
    }

    explicit constexpr Word8(Int16 value) : _value(*value) {
    }

    explicit constexpr Word8(Int32 value) : _value(*value) {
    }

    explicit constexpr Word8(Int64 value) : _value(*value) {
    }

    STANDARD_OPERATORS(Word8)

    MODULOUS_OPERATORS(Word8)

    BITWISE_OPERATORS(Word8)

    explicit constexpr operator Int8() const {
        return _value;
    }

    explicit constexpr operator Int16() const {
        return _value;
    }

    explicit constexpr operator Int32() const {
        return _value;
    }

    explicit constexpr operator Int64() const {
        return _value;
    }

    explicit constexpr operator Bool() const {
        return _value != 0;
    }

    explicit constexpr operator Char() const {
        return _value;
    }

    explicit constexpr operator Int() const {
        return _value;
    }

    explicit constexpr operator Integer() const {
        return _value;
    }
};

struct Word16 {
    using T = primitive_unsigned_short;

private:

    T _value;

public:

    constexpr Word16() : _value(0) {
    }

    constexpr Word16(T value) : _value(value) {
    }

    explicit constexpr Word16(Bool value) : _value(*value) {
    }

    explicit constexpr Word16(Char value) : _value(*value) {
    }

    explicit constexpr Word16(Int8 value) : _value(*value) {
    }

    explicit constexpr Word16(Int16 value) : _value(*value) {
    }

    explicit constexpr Word16(Int32 value) : _value(*value) {
    }

    explicit constexpr Word16(Int64 value) : _value(*value) {
    }

    explicit constexpr Word16(Word8 value) : _value(*value) {
    }

    STANDARD_OPERATORS(Word16)

    MODULOUS_OPERATORS(Word16)

    BITWISE_OPERATORS(Word16)

    explicit constexpr operator Int8() const {
        return _value;
    }

    explicit constexpr operator Int16() const {
        return _value;
    }

    explicit constexpr operator Int32() const {
        return _value;
    }

    explicit constexpr operator Int64() const {
        return _value;
    }

    explicit constexpr operator Word8() const {
        return _value;
    }

    explicit constexpr operator Bool() const {
        return _value != 0;
    }

    explicit constexpr operator Char() const {
        return _value;
    }

    explicit constexpr operator Int() const {
        return _value;
    }

    explicit constexpr operator Integer() const {
        return _value;
    }
};

struct Word32 {
    using T = If<sizeof(primitive_unsigned_int) == 4, primitive_unsigned_int, primitive_unsigned_long>::Value;

private:

    T _value;

public:

    constexpr Word32() : _value(0) {
    }

    constexpr Word32(T value) : _value(value) {
    }

    explicit constexpr Word32(Bool value) : _value(*value) {
    }

    explicit constexpr Word32(Char value) : _value(*value) {
    }

    explicit constexpr Word32(Int8 value) : _value(*value) {
    }

    explicit constexpr Word32(Int16 value) : _value(*value) {
    }

    explicit constexpr Word32(Int32 value) : _value(*value) {
    }

    explicit constexpr Word32(Int64 value) : _value(*value) {
    }

    explicit constexpr Word32(Word8 value) : _value(*value) {
    }

    explicit constexpr Word32(Word16 value) : _value(*value) {
    }

    STANDARD_OPERATORS(Word32)

    MODULOUS_OPERATORS(Word32)

    BITWISE_OPERATORS(Word32)

    explicit constexpr operator Int8() const {
        return _value;
    }

    explicit constexpr operator Int16() const {
        return _value;
    }

    explicit constexpr operator Int32() const {
        return _value;
    }

    explicit constexpr operator Int64() const {
        return _value;
    }

    explicit constexpr operator Word8() const {
        return _value;
    }

    explicit constexpr operator Word16() const {
        return _value;
    }

    explicit constexpr operator Bool() const {
        return _value != 0;
    }

    explicit constexpr operator Char() const {
        return _value;
    }

    explicit constexpr operator Int() const {
        return _value;
    }

    explicit constexpr operator Integer() const {
        return _value;
    }
};

struct Word64 {
    using T = primitive_unsigned_long_long;

private:

    T _value;

public:

    constexpr Word64() : _value(0) {
    }

    constexpr Word64(T value) : _value(value) {
    }

    explicit constexpr Word64(Bool value) : _value(*value) {
    }

    explicit constexpr Word64(Char value) : _value(*value) {
    }

    explicit constexpr Word64(Int8 value) : _value(*value) {
    }

    explicit constexpr Word64(Int16 value) : _value(*value) {
    }

    explicit constexpr Word64(Int32 value) : _value(*value) {
    }

    explicit constexpr Word64(Int64 value) : _value(*value) {
    }

    explicit constexpr Word64(Word8 value) : _value(*value) {
    }

    explicit constexpr Word64(Word16 value) : _value(*value) {
    }

    explicit constexpr Word64(Word32 value) : _value(*value) {
    }

    STANDARD_OPERATORS(Word64)

    MODULOUS_OPERATORS(Word64)

    BITWISE_OPERATORS(Word64)

    explicit constexpr operator Int8() const {
        return _value;
    }

    explicit constexpr operator Int16() const {
        return _value;
    }

    explicit constexpr operator Int32() const {
        return _value;
    }

    explicit constexpr operator Int64() const {
        return _value;
    }

    explicit constexpr operator Word8() const {
        return _value;
    }

    explicit constexpr operator Word16() const {
        return _value;
    }

    explicit constexpr operator Word32() const {
        return _value;
    }

    explicit constexpr operator Bool() const {
        return _value != 0;
    }

    explicit constexpr operator Char() const {
        return _value;
    }

    explicit constexpr operator Int() const {
        return _value;
    }

    explicit constexpr operator Integer() const {
        return _value;
    }
};

struct Float {
    using T = primitive_float;

private:

    T _value;

public:

    constexpr Float() : _value(0) {
    }

    constexpr Float(T value) : _value(value) {
    }

    explicit constexpr Float(Bool value) : _value(*value) {
    }

    explicit constexpr Float(Char value) : _value(*value) {
    }

    explicit constexpr Float(Int8 value) : _value(*value) {
    }

    explicit constexpr Float(Int16 value) : _value(*value) {
    }

    explicit constexpr Float(Int32 value) : _value(*value) {
    }

    explicit constexpr Float(Int64 value) : _value(*value) {
    }

    explicit constexpr Float(Word8 value) : _value(*value) {
    }

    explicit constexpr Float(Word16 value) : _value(*value) {
    }

    explicit constexpr Float(Word32 value) : _value(*value) {
    }

    explicit constexpr Float(Word64 value) : _value(*value) {
    }

    STANDARD_OPERATORS(Float)

    explicit constexpr operator Int8() const {
        return _value;
    }

    explicit constexpr operator Int16() const {
        return _value;
    }

    explicit constexpr operator Int32() const {
        return _value;
    }

    explicit constexpr operator Int64() const {
        return _value;
    }

    explicit constexpr operator Word8() const {
        return _value;
    }

    explicit constexpr operator Word16() const {
        return _value;
    }

    explicit constexpr operator Word32() const {
        return _value;
    }

    explicit constexpr operator Word64() const {
        return _value;
    }

    explicit constexpr operator Bool() const {
        return _value != 0;
    }

    explicit constexpr operator Char() const {
        return _value;
    }

    explicit constexpr operator Int() const {
        return _value;
    }

    explicit constexpr operator Integer() const {
        return _value;
    }
};

struct Double {
    using T = primitive_double;

private:

    T _value;

public:

    constexpr Double() : _value(0) {
    }

    constexpr Double(T value) : _value(value) {
    }

    explicit constexpr Double(Bool value) : _value(*value) {
    }

    explicit constexpr Double(Char value) : _value(*value) {
    }

    explicit constexpr Double(Int8 value) : _value(*value) {
    }

    explicit constexpr Double(Int16 value) : _value(*value) {
    }

    explicit constexpr Double(Int32 value) : _value(*value) {
    }

    explicit constexpr Double(Int64 value) : _value(*value) {
    }

    explicit constexpr Double(Word8 value) : _value(*value) {
    }

    explicit constexpr Double(Word16 value) : _value(*value) {
    }

    explicit constexpr Double(Word32 value) : _value(*value) {
    }

    explicit constexpr Double(Word64 value) : _value(*value) {
    }

    explicit constexpr Double(Float value) : _value(*value) {
    }

    STANDARD_OPERATORS(Double)

    explicit constexpr operator T() const {
        return _value;
    }

    explicit constexpr operator Int8() const {
        return _value;
    }

    explicit constexpr operator Int16() const {
        return _value;
    }

    explicit constexpr operator Int32() const {
        return _value;
    }

    explicit constexpr operator Int64() const {
        return _value;
    }

    explicit constexpr operator Word8() const {
        return _value;
    }

    explicit constexpr operator Word16() const {
        return _value;
    }

    explicit constexpr operator Word32() const {
        return _value;
    }

    explicit constexpr operator Word64() const {
        return _value;
    }

    explicit constexpr operator Float() const {
        return _value;
    }

    explicit constexpr operator Bool() const {
        return _value != 0;
    }

    explicit constexpr operator Char() const {
        return _value;
    }

    explicit constexpr operator Int() const {
        return _value;
    }

    explicit constexpr operator Integer() const {
        return _value;
    }
};

template <>
struct IsInteger<Int> : ConstantTrue {};

template <>
struct IsInteger<Integer> : ConstantTrue {};

template <>
struct IsInteger<Int8> : ConstantTrue {};

template <>
struct IsInteger<Int16> : ConstantTrue {};

template <>
struct IsInteger<Int32> : ConstantTrue {};

template <>
struct IsInteger<Int64> : ConstantTrue {};

template <>
struct IsInteger<Word8> : ConstantTrue {};

template <>
struct IsInteger<Word16> : ConstantTrue {};

template <>
struct IsInteger<Word32> : ConstantTrue {};

template <>
struct IsInteger<Word64> : ConstantTrue {};

template <>
struct IsFloating<Bool> : ConstantFalse {};

template <>
struct IsFloating<Char> : ConstantFalse {};

template <>
struct IsFloating<Int> : ConstantFalse {};

template <>
struct IsFloating<Integer> : ConstantFalse {};

template <>
struct IsFloating<Int8> : ConstantFalse {};

template <>
struct IsFloating<Int16> : ConstantFalse {};

template <>
struct IsFloating<Int32> : ConstantFalse {};

template <>
struct IsFloating<Int64> : ConstantFalse {};

template <>
struct IsFloating<Word8> : ConstantFalse {};

template <>
struct IsFloating<Word16> : ConstantFalse {};

template <>
struct IsFloating<Word32> : ConstantFalse {};

template <>
struct IsFloating<Word64> : ConstantFalse {};

template <>
struct IsFloating<Float> : ConstantTrue {};

template <>
struct IsFloating<Double> : ConstantTrue {};

template <>
struct IsBool<Bool> : ConstantTrue {};

template <>
struct IsSigned<Int> : ConstantTrue {};

template <>
struct IsSigned<Integer> : ConstantTrue {};

template <>
struct IsSigned<Bool> : ConstantFalse {};

template <>
struct IsSigned<Char> : ConstantTrue {};

template <>
struct IsSigned<Int8> : ConstantTrue {};

template <>
struct IsSigned<Int16> : ConstantTrue {};

template <>
struct IsSigned<Int32> : ConstantTrue {};

template <>
struct IsSigned<Int64> : ConstantTrue {};

template <>
struct IsSigned<Word8> : ConstantFalse {};

template <>
struct IsSigned<Word16> : ConstantFalse {};

template <>
struct IsSigned<Word32> : ConstantFalse {};

template <>
struct IsSigned<Word64> : ConstantFalse {};

template <>
struct IsSigned<Float> : ConstantTrue {};

template <>
struct IsSigned<Double> : ConstantTrue {};

template<>
struct Max<Int8> : ConstantIntegral<Int8, 127> {};

template<>
struct Max<Int16> : ConstantIntegral<Int16, 32767> {};

template<>
struct Max<Int32> : ConstantIntegral<Int32, 2147483647> {};

template<>
struct Max<Int64> : ConstantIntegral<Int64, 9223372036854775807> {};

template<>
struct Max<Word8> : ConstantIntegral<Word8, 255> {};

template<>
struct Max<Word16> : ConstantIntegral<Word16, 65535> {};

template<>
struct Max<Word32> : ConstantIntegral<Word32, 4294967295> {};

template<>
struct Max<Word64> {
    static constexpr Word64 value = 18446744073709551615u;
};

template<>
struct Min<Int8> : ConstantIntegral<Int8, -128> {};

template<>
struct Min<Int16> : ConstantIntegral<Int16, -32768> {};

template<>
struct Min<Int32> : ConstantIntegral<Int32, -2147483648> {};

template<>
struct Min<Int64> : ConstantIntegral<Int64, -9223372036854775807 - 1> {};

template<>
struct Min<Word8> : ConstantIntegral<Word8, 0> {};

template<>
struct Min<Word16> : ConstantIntegral<Word16, 0> {};

template<>
struct Min<Word32> : ConstantIntegral<Word32, 0> {};

template<>
struct Min<Word64> : ConstantIntegral<Word64, 0> {};

// template <>
// struct TypeName<Bool> {
//     static constexpr CString value = "Bool";
// };

// template <>
// struct TypeName<Char> {
//     static constexpr CString value = "Char";
// };

// template <>
// struct TypeName<Int8> {
//     static constexpr CString value = "Int8";
// };

// template <>
// struct TypeName<Int16> {
//     static constexpr CString value = "Int16";
// };

// template <>
// struct TypeName<Int32> {
//     static constexpr CString value = "Int32";
// };

// template <>
// struct TypeName<Int64> {
//     static constexpr CString value = "Int64";
// };

// template <>
// struct TypeName<Word8> {
//     static constexpr CString value = "Word8";
// };

// template <>
// struct TypeName<Word16> {
//     static constexpr CString value = "Word16";
// };

// template <>
// struct TypeName<Word32> {
//     static constexpr CString value = "Word32";
// };

// template <>
// struct TypeName<Word64> {
//     static constexpr CString value = "Word64";
// };

// template <>
// struct TypeName<Float> {
//     static constexpr CString value = "Float";
// };

// template <>
// struct TypeName<Double> {
//     static constexpr CString value = "Double";
// };

// TODO doubleWidth, halfWidth, asSigned, asUnsigned

constexpr Int8 operator "" _i8(primitive_unsigned_long_long n) {
    return Int8(n);
}

constexpr Int16 operator "" _i16(primitive_unsigned_long_long n) {
    return Int16(n);
}

constexpr Int32 operator "" _i32(primitive_unsigned_long_long n) {
    return Int32(n);
}

constexpr Int64 operator "" _i64(primitive_unsigned_long_long n) {
    return Int64(n);
}

constexpr Word8 operator "" _w8(primitive_unsigned_long_long n) {
    return Word8(n);
}

constexpr Word16 operator "" _w16(primitive_unsigned_long_long n) {
    return Word16(n);
}

constexpr Word32 operator "" _w32(primitive_unsigned_long_long n) {
    return Word32(n);
}

constexpr Word64 operator "" _w64(primitive_unsigned_long_long n) {
    return Word64(n);
}

constexpr Float operator "" _f(primitive_long_double n) {
    return Float(n);
}

constexpr Float operator "" _f(primitive_unsigned_long_long n) {
    return Float(n);
}

constexpr Double operator "" _d(primitive_long_double n) {
    return Double(n);
}

constexpr Double operator "" _d(primitive_unsigned_long_long n) {
    return Double(n);
}

static_assert(sizeof(Int8) == 1, "Int8 is not the right size");
static_assert(sizeof(Int16) == 2, "Int16 is not the right size");
static_assert(sizeof(Int32) == 4, "Int32 is not the right size");
static_assert(sizeof(Int64) == 8, "Int64 is not the right size");
static_assert(sizeof(Word8) == 1, "Word8 is not the right size");
static_assert(sizeof(Word16) == 2, "Word16 is not the right size");
static_assert(sizeof(Word32) == 4, "Word32 is not the right size");
static_assert(sizeof(Word64) == 8, "Word64 is not the right size");

#ifdef TEST

TEST(Safe, Types) {
    Int8 a;
    Int8 b = 5;

    EXPECT_EQ(a + b, 5);

    Int16 c = Int16(b) + 4;

    EXPECT_EQ(c, 9);

    Int16 d = 5;

    d = 1;

    false && (d++ == 0);

    EXPECT_EQ(d, 1);

    Word8 e = 0x30;
    Word16 f = 0x0010;

    Word16 g = Word16(e) | f;

    EXPECT_EQ(g, 0x0030);

    EXPECT_FALSE(IsFloating<decltype(g)>::value);
    EXPECT_TRUE(IsFloating<Float>::value);

    EXPECT_TRUE((IsSame<Float, Float>::value));
    EXPECT_TRUE((IsSame<Int, Int>::value));
    EXPECT_TRUE((IsSame<decltype(g), decltype(f)>::value));
    EXPECT_TRUE((IsSame<decltype(a), decltype(b)>::value));

    EXPECT_FALSE((IsSame<decltype(a), decltype(d)>::value));

    Int h = IsSigned<Int8>::value;

    (void)h;
}

#endif // TEST

#endif
