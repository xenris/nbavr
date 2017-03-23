#ifndef NBAVR_FIXED_HPP
#define NBAVR_FIXED_HPP

// #include "stream.hpp"
// #include "print.hpp"
#include "util/type_info.hpp"

template <class T>
class Fixed {
    T _n;
    static constexpr T range = (type_info<T>::max >> 1) + 1;
    static constexpr T limit = type_info<T>::max - 3;
    static constexpr T infValue = type_info<T>::max - 1;
    static constexpr T nanValue = type_info<T>::max - 2;
    typedef typename type_info<T>::double_width TT;

public:
    constexpr Fixed(const float n) : _n(encode(n)) {
    }

    constexpr Fixed(const double n) : _n(encode(n)) {
    }

    constexpr Fixed() : _n(0) {
    }

    operator float() {
        if(isNan()) {
            return 0.0 / 0.0;
        } else if(_n == infValue) {
            return 1.0 / 0.0;
        } else if(_n == -infValue) {
            return -1.0 / 0.0;
        } else {
            return float(_n) / range;
        }
    }

    operator double() {
        if(isNan()) {
            return 0.0 / 0.0;
        } else if(_n == infValue) {
            return 1.0 / 0.0;
        } else if(_n == -infValue) {
            return -1.0 / 0.0;
        } else {
            return double(_n) / range;
        }
    }

    Fixed<T> operator+(const Fixed<T> other) const {
        if(isNan() || other.isNan()) {
            return nan();
        }

        if(isInf() && other.isInf()) {
            if(*this != other) {
                return nan();
            } else {
                return *this;
            }
        } else if(isInf()) {
            return *this;
        } else if(other.isInf()) {
            return other;
        }

        T a = _n;
        T b = other._n;

        if((b > 0) && (a > (limit - b))) {
            return inf();
        }

        if((b < 0) && (a < (-limit - b))) {
            return -inf();
        }

        return fromBits(a + b);
    }

    Fixed<T> operator-(const Fixed<T> other) const {
        if(isNan() || other.isNan()) {
            return nan();
        }

        if(isInf() && other.isInf()) {
            if(*this == other) {
                return nan();
            } else {
                return *this;
            }
        } else if(isInf()) {
            return *this;
        } else if(other.isInf()) {
            return -other;
        }

        T a = _n;
        T b = other._n;

        if((b < 0) && (a > (limit + b))) {
            return inf();
        }

        if((b > 0) && (a < (-limit + b))) {
            return -inf();
        }

        return fromBits(a - b);
    }

    Fixed<T> operator*(const Fixed<T> other) const {
        if(isNan() || other.isNan()) {
            return nan();
        }

        if(isInf() || other.isInf()) {
            if((_n < 0) != (other._n < 0)) {
                return -inf();
            } else {
                return inf();
            }
        }

        TT a = _n;
        TT b = other._n;

        TT n = a * b / range;

        if(n > limit) {
            return inf();
        }

        if(n < -limit) {
            return -inf();
        }

        return fromBits(n);
    }

    Fixed<T> operator/(const Fixed<T> other) const {
        if(isNan() || other.isNan()) {
            return nan();
        }

        if(isInf() || other.isInf()) {
            return inf((_n < 0) != (other._n < 0));
        }

        if(other._n == 0) {
            if(_n == 0) {
                return nan();
            } else if(_n < 0) {
                return -inf();
            } else {
                return inf();
            }
        }

        TT a = _n;
        TT b = other._n;
        TT n = a * range / b;

        if(n > limit) {
            return inf();
        }

        if(n < -limit) {
            return -inf();
        }

        return fromBits(n);
    }

    void operator=(const Fixed<T>& other) {
        _n = other._n;
    }

    void operator+=(const Fixed<T>& other) {
        *this = *this + other;
    }

    void operator-=(const Fixed<T>& other) {
        *this = *this - other;
    }

    void operator*=(const Fixed<T>& other) {
        *this = *this * other;
    }

    void operator/=(const Fixed<T>& other) {
        *this = *this / other;
    }

    bool operator==(const Fixed<T>& other) const {
        return _n == other._n;
    }

    bool operator!=(const Fixed<T>& other) const {
        return _n != other._n;
    }

    bool operator>(const Fixed<T>& other) {
        return _n > other._n;
    }

    bool operator<(const Fixed<T>& other) {
        return _n < other._n;
    }

    Fixed<T> operator-() const {
        if(isNan()) {
            return nan();
        } else {
            return fromBits(-_n);
        }
    }

//     // template <class I>
//     constexpr T mul(const T i) {
//         TT n = (TT(i) * TT(_n) / TT(limit)) * TT(range);

//         // typedef typename type_info<I>::double_width I2;

//         // I2 n = I2(i) * I2(r._n) * I2(range);

//         // if(n < 0) {
//         //     n -= I2(limit) / 2;
//         // } else {
//         //     n += I2(limit) / 2;
//         // }

//         // n /= I2(limit);

//         n = clip(n, TT(type_info<T>::min), TT(type_info<T>::max));

//         // return I(n);
//         return n;
//     }

    // TODO
    friend Stream<char>& operator<<(Stream<char>& stream, const Fixed<T>& f) {
        bool negative = f._n < 0;

        if(f.isNan()) {
            stream << "nan";
        } else if(f.isInf()) {
            if(negative) {
                stream << '-';
            }

            stream << "inf";
        } else {
            stream << f._n << " / " << range;
        }

        return stream;
    }

    bool isInf() const {
        return (_n == infValue) || (_n == -infValue);
    }

    bool isNan() const {
        return _n == nanValue;
    }

    static Fixed<T> inf() {
        return fromBits(infValue);
    }

    static Fixed<T> nan() {
        return fromBits(nanValue);
    }

    static Fixed<T> max() {
        return fromBits(limit);
    }

    static Fixed<T> min() {
        return fromBits(1);
    }

    static Fixed<T> frac(T a, T b) {
        return 0.0;
    }

private:
    constexpr T encode(float n) {
        float l = float(limit) / float(range);

        if(n < -l) {
            return -infValue;
        } else if(n > l) {
            return infValue;
        }

        return n * range;
    }

    constexpr T encode(double n) {
        double l = double(limit) / double(range);

        if(n < -l) {
            return -infValue;
        } else if(n > l) {
            return infValue;
        }

        return n * range;
    }

    static Fixed<T> fromBits(T n) {
        Fixed<T> result;
        result._n = n;
        return result;
    }
};

typedef Fixed<int8_t> fix8_t;
typedef Fixed<int16_t> fix16_t;
typedef Fixed<int32_t> fix32_t;

#endif
