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

#define bool Do_not_use_primitive_types__Try_Bool_instead
#define char Do_not_use_primitive_types__Try_Char_instead
#define wchar_t Do_not_use_primitive_types__Try_Word16_or_Char_instead
#define short Do_not_use_primitive_types__Try_Int16_instead
#define int Do_not_use_primitive_types__Try_Int32_instead
#define long Do_not_use_primitive_types__Try_Int64_instead
#define float Do_not_use_primitive_types__Try_Float_instead
#define double Do_not_use_primitive_types__Try_Double_instead
#define signed Do_not_use_primitive_types__Try_Int32_instead
#define unsigned Do_not_use_primitive_types__Try_Word32_instead
#define int8_t Do_not_use_primitive_types__Try_Int8_instead
#define uint8_t Do_not_use_primitive_types__Try_Word8_instead
#define int16_t Do_not_use_primitive_types__Try_Int16_instead
#define uint16_t Do_not_use_primitive_types__Try_Word16_instead
#define int32_t Do_not_use_primitive_types__Try_Int32_instead
#define uint32_t Do_not_use_primitive_types__Try_Word32_instead
#define int64_t Do_not_use_primitive_types__Try_Int64_instead
#define uint64_t Do_not_use_primitive_types__Try_Word64_instead
#define size_t Do_not_use_primitive_types__Try_Int_instead
#define ssize_t Do_not_use_primitive_types__Try_Int_instead

#endif
