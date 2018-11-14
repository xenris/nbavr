/// [[Index]]

/// # {{Basic}}

#ifndef NBOS_BASIC_HPP
#define NBOS_BASIC_HPP

#include "primitive.hpp"

template <class T, Integer v>
struct ConstantIntegral {
    static constexpr T value = v;
};

template <class T>
struct ConstantType {
    using Value = T;
};

struct ConstantTrue : ConstantIntegral<primitive_bool, true> {};

struct ConstantFalse : ConstantIntegral<primitive_bool, false> {};

template <primitive_bool B, class T, class F>
struct If : ConstantType<T> {};

template <class T, class F>
struct If<false, T, F> : ConstantType<F> {};

template <class T, class U>
struct IsSame : ConstantFalse {};

template <class T>
struct IsSame<T, T> : ConstantTrue {};

template <class T>
struct IsInteger {};

template <class T>
struct IsFloating {};

template <class T>
struct IsBool {};

template <class T>
struct IsSigned {};

template <class T>
struct IsUnsigned {};

template <class T>
struct Max {};

template <class T>
struct Min {};

template <class T>
struct TypeName {};

#endif
