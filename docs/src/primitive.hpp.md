# Primitive types

All the standard c/c++ primitive types (e.g. int, char, bool, float, etc) have been disabled.
Use [Safe](safe.hpp.md#safe) types instead.

If access to primitive types is required they are available through the following aliases:

* primitive_bool
* primitive_signed_char
* primitive_unsigned_char
* primitive_signed_short
* primitive_unsigned_short
* primitive_signed_int
* primitive_unsigned_int
* primitive_signed_long
* primitive_unsigned_long
* primitive_signed_long_long
* primitive_unsigned_long_long
* primitive_float
* primitive_double
* primitive_long_double
* primitive_size_t
* primitive_ssize_t

The following primitive types are also available for particular use cases, such as for fast code or
for large numbers. These can be used as template parameters, where as the [Safe](safe.hpp.md#safe) types can not.

* Int
    Fastest integer type. "signed int". Only guaranteed to be at least 8 bits (-128 to +127). Generally should be 8, 16, 32, 64 bits on 8, 16, 32, 64 bit processors respectively.
    Useful when speed is priority.
* Integer
    Largest integer type. "signed long long". 64 bits (probably).
