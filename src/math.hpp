/// [[Index]]

/// # {{Maths}}

#ifndef NBLIB_MATH_HPP
#define NBLIB_MATH_HPP

#include "primitive.hpp"
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

/// #### float sin(float n)
constexpr force_inline float sin(float n) {
    return BUILTIN(sin(n));
}

/// #### double sin(double n)
constexpr force_inline double sin(double n) {
        return BUILTIN(sin(n));
}

/// #### float cos(float n)
constexpr force_inline float cos(float n) {
        return BUILTIN(cos(n));
}

/// #### double cos(double n)
constexpr force_inline double cos(double n) {
        return BUILTIN(cos(n));
}

/// #### float tan(float n)
constexpr force_inline float tan(float n) {
        return BUILTIN(tanf(n));
}

/// #### double tan(double n)
constexpr force_inline double tan(double n) {
        return BUILTIN(tan(n));
}

/// #### float asin(float n)
constexpr force_inline float asin(float n) {
        return BUILTIN(asinf(n));
}

/// #### double asin(double n)
constexpr force_inline double asin(double n) {
        return BUILTIN(asin(n));
}

/// #### float acos(float n)
constexpr force_inline float acos(float n) {
        return BUILTIN(acosf(n));
}

/// #### double acos(double n)
constexpr force_inline double acos(double n) {
        return BUILTIN(acos(n));
}

/// #### float atan(float n)
constexpr force_inline float atan(float n) {
        return BUILTIN(atanf(n));
}

/// #### double atan(double n)
constexpr force_inline double atan(double n) {
        return BUILTIN(atan(n));
}

/// #### float sinh(float n)
constexpr force_inline float sinh(float n) {
        return BUILTIN(sinhf(n));
}

/// #### double sinh(double n)
constexpr force_inline double sinh(double n) {
        return BUILTIN(sinh(n));
}

/// #### float cosh(float n)
constexpr force_inline float cosh(float n) {
        return BUILTIN(coshf(n));
}

/// #### double cosh(double n)
constexpr force_inline double cosh(double n) {
        return BUILTIN(cosh(n));
}

/// #### float tanh(float n)
constexpr force_inline float tanh(float n) {
        return BUILTIN(tanhf(n));
}

/// #### double tanh(double n)
constexpr force_inline double tanh(double n) {
        return BUILTIN(tanh(n));
}

/// #### float floor(float n)
constexpr force_inline float floor(float n) {
        return BUILTIN(floorf(n));
}

/// #### double floor(double n)
constexpr force_inline double floor(double n) {
        return BUILTIN(floor(n));
}

/// #### float fmod(float n, float p)
constexpr force_inline float fmod(float n, float p) {
        return BUILTIN(fmodf(n, p));
}

/// #### double fmod(double n, double p)
constexpr force_inline double fmod(double n, double p) {
        return BUILTIN(fmod(n, p));
}

/// #### float log(float n)
constexpr force_inline float log(float n) {
        return BUILTIN(logf(n));
}

/// #### double log(double n)
constexpr force_inline double log(double n) {
        return BUILTIN(log(n));
}

/// #### float log10(float n)
constexpr force_inline float log10(float n) {
        return BUILTIN(log10f(n));
}

/// #### double log10(double n)
constexpr force_inline double log10(double n) {
        return BUILTIN(log10(n));
}

/// #### float modf(float n, float* i)
constexpr force_inline float modf(float n, float* i) {
        return BUILTIN(modff(n, i));
}

/// #### double modf(double n, double* i)
constexpr force_inline double modf(double n, double* i) {
        return BUILTIN(modf(n, i));
}

/// #### float pow(float n, float p)
constexpr force_inline float pow(float n, float p) {
        return BUILTIN(powf(n, p));
}

/// #### double pow(double n, double p)
constexpr force_inline double pow(double n, double p) {
        return BUILTIN(pow(n, p));
}

/// #### float round(float n)
constexpr force_inline float round(float n) {
        return BUILTIN(roundf(n));
}

/// #### double round(double n)
constexpr force_inline double round(double n) {
        return BUILTIN(round(n));
}

/// #### float sqrt(float n)
constexpr force_inline float sqrt(float n) {
        return BUILTIN(sqrtf(n));
}

/// #### double sqrt(double n)
constexpr force_inline double sqrt(double n) {
        return BUILTIN(sqrt(n));
}

constexpr double pi = atan(1.0) * 4;

#endif
