/// [[Index]]

/// # {{Maths}}

#ifndef NBOS_MATH_HPP
#define NBOS_MATH_HPP

#include "safe.hpp"
#include "macros.hpp"

/// #### T max(T a, T b)
template<class T>
constexpr force_inline T max(T a, T b) {
    return a > b ? a : b;
}

/// #### T min(T a, T b)
template<class T>
constexpr force_inline T min(T a, T b) {
    return a < b ? a : b;
}

/// #### T clip(T n, T l, T h)
template<class T>
constexpr force_inline T clip(T n, T l, T h) {
    return max(min(n, h), l);
}

/// #### T abs(T a)
template<class T>
constexpr force_inline T abs(T a) {
    return a >= 0 ? a : -a;
}

// Used to stop clang complaining about non constexpr built in functions.
#ifdef __clang__
    #define BUILTIN(N) 0
#else
    #define BUILTIN(N) __builtin_##N
#endif

/// #### Float sin(Float n)
constexpr force_inline Float sin(Float n) {
    return BUILTIN(sin(*n));
}

/// #### Double sin(Double n)
constexpr force_inline Double sin(Double n) {
        return BUILTIN(sin(*n));
}

/// #### Float cos(Float n)
constexpr force_inline Float cos(Float n) {
        return BUILTIN(cos(*n));
}

/// #### Double cos(Double n)
constexpr force_inline Double cos(Double n) {
        return BUILTIN(cos(*n));
}

/// #### Float tan(Float n)
constexpr force_inline Float tan(Float n) {
        return BUILTIN(tanf(*n));
}

/// #### Double tan(Double n)
constexpr force_inline Double tan(Double n) {
        return BUILTIN(tan(*n));
}

/// #### Float asin(Float n)
constexpr force_inline Float asin(Float n) {
        return BUILTIN(asinf(*n));
}

/// #### Double asin(Double n)
constexpr force_inline Double asin(Double n) {
        return BUILTIN(asin(*n));
}

/// #### Float acos(Float n)
constexpr force_inline Float acos(Float n) {
        return BUILTIN(acosf(*n));
}

/// #### Double acos(Double n)
constexpr force_inline Double acos(Double n) {
        return BUILTIN(acos(*n));
}

/// #### Float atan(Float n)
constexpr force_inline Float atan(Float n) {
        return BUILTIN(atanf(*n));
}

/// #### Double atan(Double n)
constexpr force_inline Double atan(Double n) {
        return BUILTIN(atan(*n));
}

/// #### Float sinh(Float n)
constexpr force_inline Float sinh(Float n) {
        return BUILTIN(sinhf(*n));
}

/// #### Double sinh(Double n)
constexpr force_inline Double sinh(Double n) {
        return BUILTIN(sinh(*n));
}

/// #### Float cosh(Float n)
constexpr force_inline Float cosh(Float n) {
        return BUILTIN(coshf(*n));
}

/// #### Double cosh(Double n)
constexpr force_inline Double cosh(Double n) {
        return BUILTIN(cosh(*n));
}

/// #### Float tanh(Float n)
constexpr force_inline Float tanh(Float n) {
        return BUILTIN(tanhf(*n));
}

/// #### Double tanh(Double n)
constexpr force_inline Double tanh(Double n) {
        return BUILTIN(tanh(*n));
}

/// #### Float floor(Float n)
constexpr force_inline Float floor(Float n) {
        return BUILTIN(floorf(*n));
}

/// #### Double floor(Double n)
constexpr force_inline Double floor(Double n) {
        return BUILTIN(floor(*n));
}

/// #### Float fmod(Float n, Float p)
constexpr force_inline Float fmod(Float n, Float p) {
        return BUILTIN(fmodf(*n, *p));
}

/// #### Double fmod(Double n, Double p)
constexpr force_inline Double fmod(Double n, Double p) {
        return BUILTIN(fmod(*n, *p));
}

/// #### Float log(Float n)
constexpr force_inline Float log(Float n) {
        return BUILTIN(logf(*n));
}

/// #### Double log(Double n)
constexpr force_inline Double log(Double n) {
        return BUILTIN(log(*n));
}

/// #### Float log10(Float n)
constexpr force_inline Float log10(Float n) {
        return BUILTIN(log10f(*n));
}

/// #### Double log10(Double n)
constexpr force_inline Double log10(Double n) {
        return BUILTIN(log10(*n));
}

/// #### Float modf(Float n, Float* i)
constexpr force_inline Float modf(Float n, Float* i) {
        return BUILTIN(modff(*n, &**i));
}

/// #### Double modf(Double n, Double* i)
constexpr force_inline Double modf(Double n, Double* i) {
        return BUILTIN(modf(*n, &**i));
}

/// #### Float pow(Float n, Float p)
constexpr force_inline Float pow(Float n, Float p) {
        return BUILTIN(powf(*n, *p));
}

/// #### Double pow(Double n, Double p)
constexpr force_inline Double pow(Double n, Double p) {
        return BUILTIN(pow(*n, *p));
}

/// #### Float round(Float n)
constexpr force_inline Float round(Float n) {
        return BUILTIN(roundf(*n));
}

/// #### Double round(Double n)
constexpr force_inline Double round(Double n) {
        return BUILTIN(round(*n));
}

/// #### Float sqrt(Float n)
constexpr force_inline Float sqrt(Float n) {
        return BUILTIN(sqrtf(*n));
}

/// #### Double sqrt(Double n)
constexpr force_inline Double sqrt(Double n) {
        return BUILTIN(sqrt(*n));
}

constexpr Float pi = atan(1_f) * 4;

#endif
