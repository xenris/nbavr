#ifndef NBOS_PRIMITIVE_HPP
#define NBOS_PRIMITIVE_HPP

/// # Primitive types

/// All the standard c/c++ primitive types (e.g. int, char, bool, float, etc) have been disabled.
/// Use [[Safe]] types instead.

/// If access to primitive types is required they are available through the following aliases:

/// * primitive_bool
/// * primitive_signed_char
/// * primitive_unsigned_char
/// * primitive_signed_short
/// * primitive_unsigned_short
/// * primitive_signed_int
/// * primitive_unsigned_int
/// * primitive_signed_long
/// * primitive_unsigned_long
/// * primitive_signed_long_long
/// * primitive_unsigned_long_long
/// * primitive_float
/// * primitive_double
/// * primitive_long_double
/// * primitive_size_t
/// * primitive_ssize_t

/// The following primitive types are also available for particular use cases, such as for fast code or
/// for large numbers. These can be used as template parameters, where as the [[Safe]] types can not.

/// * Int
///     Fastest integer type. "signed int". Only guaranteed to be at least 8 bits (-128 to +127). Generally should be 8, 16, 32, 64 bits on 8, 16, 32, 64 bit processors respectively.
///     Useful when speed is priority.
/// * Integer
///     Largest integer type. "signed long long". 64 bits (probably).

using Int = int;
using Integer = long long;

using primitive_bool = bool;
using primitive_signed_char = char;
using primitive_unsigned_char = unsigned char;
using primitive_signed_short = short;
using primitive_unsigned_short = unsigned short;
using primitive_signed_int = int;
using primitive_unsigned_int = unsigned int;
using primitive_signed_long = long;
using primitive_unsigned_long = unsigned long;
using primitive_signed_long_long = long long;
using primitive_unsigned_long_long = unsigned long long;
using primitive_float = float;
using primitive_double = double;
using primitive_long_double = long double;
using primitive_size_t = unsigned int;
using primitive_ssize_t = int;

#define bool do_not_use_primitive_types
#define char do_not_use_primitive_types
#define wchar_t do_not_use_primitive_types
#define short do_not_use_primitive_types
#define int do_not_use_primitive_types
#define long do_not_use_primitive_types
#define float do_not_use_primitive_types
#define double do_not_use_primitive_types
#define signed do_not_use_primitive_types
#define unsigned do_not_use_primitive_types
#define int8_t do_not_use_primitive_types
#define uint8_t do_not_use_primitive_types
#define int16_t do_not_use_primitive_types
#define uint16_t do_not_use_primitive_types
#define int32_t do_not_use_primitive_types
#define uint32_t do_not_use_primitive_types
#define int64_t do_not_use_primitive_types
#define uint64_t do_not_use_primitive_types
#define size_t do_not_use_primitive_types
#define ssize_t do_not_use_primitive_types

#endif
