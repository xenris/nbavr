#ifndef NBAVR_RATIONAL_HPP
#define NBAVR_RATIONAL_HPP

#include "stream.hpp"
#include "print.hpp"
#include "util/type_info.hpp"

template <class T, int64_t range>
class Rational {
    static constexpr T limit = type_info<T>::max / 2 + 1;

    T _n;

    typedef typename type_info<T>::double_width T2;

    static_assert(type_info<T>::is_signed && type_info<T>::is_integer, "Rational requires a signed integer");

public:
    constexpr Rational(const double n) : _n(encode(n)) {
    }

    constexpr Rational() : _n(0) {
    }

    // constexpr void operator=(const Rational<T, range>& other) {
    //     _n = other._n;
    // }

    constexpr Rational<T, range> operator+(const Rational<T, range>& other) {
        T2 n = T2(_n) + T2(other._n);

        n = clip(n, T2(-limit), T2(limit));

        return Rational<T, range>(T(n));
    }

    constexpr Rational<T, range> operator-(const Rational<T, range>& other) {
        T2 n = T2(_n) - T2(other._n);

        n = clip(n, T2(-limit), T2(limit));

        return Rational<T, range>(T(n));
    }

    constexpr Rational<T, range> operator*(const Rational<T, range>& other) {
        T2 n = (T2(_n) * T2(other._n) * T2(range)) / T2(limit);

        n = clip(n, -T2(limit), T2(limit));

        return Rational<T, range>(T(n));
    }

    constexpr Rational<T, range> operator/(const Rational<T, range>& other) {
        T2 n = (T2(_n) * T2(limit)) / (T2(other._n) * T2(range));

        n = clip(n, T2(-limit), T2(limit));

        return Rational<T, range>(T(n));
    }

    constexpr Rational<T, range> operator-() {
        return Rational<T, range>(-_n);
    }

    constexpr bool operator==(const Rational<T, range> other) {
        return _n == other._n;
    }

    template <class I>
    constexpr friend I operator*(const I a, const Rational<T, range>& r) {
        typedef typename type_info<I>::double_width I2;

        I2 n = I2(a) * I2(r._n) * I2(range);

        if(n < 0) {
            n -= I2(limit) / 2;
        } else {
            n += I2(limit) / 2;
        }

        n /= I2(limit);

        n = clip(n, I2(type_info<I>::min), I2(type_info<I>::max));

        return I(n);
    }

    template <class I>
    constexpr friend I operator/(const I a, const Rational<T, range>& r) {
        typedef typename type_info<I>::double_width I2;

        I2 n = I2(a) * I2(limit);

        if(n < 0) {
            n -= I2(r._n) * I2(range) / 2;
        } else {
            n += I2(r._n) * I2(range) / 2;
        }

        n /= I2(r._n) * I2(range);

        n = clip(n, I2(type_info<I>::min), I2(type_info<I>::max));

        return I(n);
    }

    friend Stream<char>& operator<<(Stream<char>& stream, const Rational<T, range>& f) {
        bool negative = f.data() < 0;
        T2 n = abs(f.data());
        T2 limit = Rational<T, range>::limit;

        T2 u = (n * range) / limit;
        T2 l = (n * range * pow10(6) / limit) - (u * pow10(6));

        if(negative) {
            stream << '-';
        }

        stream << u;

        stream << '.';

        for(int8_t c = 6 - numDigits(l); c != 0; c--) {
            stream << '0';
        }

        stream << l;

        return stream;
    }

    static constexpr Rational<T, range> resolution() {
        return Rational<T, range>(T(1));
    }

    static constexpr Rational<T, range> fromInt(T x, T m) {
        T2 n = (T2(x) * T2(limit)) / (T2(range) * T2(m));

        n = clip(n, T2(-limit), T2(limit));

        return Rational<T, range>(T(n));
    }

    constexpr T data() const {
        return _n;
    }

private:
    constexpr Rational(const T n) : _n(n) {
    }

    constexpr T encode(double n) {
        double r = range;
        double l = limit;

        return (clip(n, -r, r) / r) * l;
    }

    template <class U>
    constexpr static int8_t numDigits(U n) {
        int8_t count = 1;

        while(true) {
            n /= 10;

            if(n == 0) {
                break;
            }

            count++;
        }

        return count;
    }

    constexpr static int64_t pow10(int64_t x) {
        int64_t r = 1;

        while(x != 0) {
            r *= 10;

            x--;
        }

        return r;
    }
};

template <int64_t range>
struct rational8 : Rational<int8_t, range> {
    using Rational<int8_t, range>::Rational;
};

template <int64_t range>
struct rational16 : Rational<int16_t, range> {
    using Rational<int16_t, range>::Rational;
};

template <int64_t range>
struct rational32 : Rational<int32_t, range> {
    using Rational<int32_t, range>::Rational;
};

#endif
