#ifndef STRONG_TYPEDEF_HPP
#define STRONG_TYPEDEF_HPP

template <class T, class Tag>
class strong_typedef {
    T _t;

public:

    constexpr strong_typedef() {
    }

    constexpr explicit strong_typedef(T t) : _t(t) {
    }

    explicit operator T() const {
        return _t;
    }

    // strong_typedef<T, Tag> operator =(const T& t) {
    //     _t = t;
    //     return *this;
    // }

    strong_typedef<T, Tag> operator +(const strong_typedef<T, Tag>& o) const {
        return strong_typedef<T, Tag>(_t + o._t);
    }

    strong_typedef<T, Tag>& operator +=(const strong_typedef<T, Tag>& o) {
        _t += o._t;
        return *this;
    }

    strong_typedef<T, Tag> operator -(const strong_typedef<T, Tag>& o) const {
        return strong_typedef<T, Tag>(_t - o._t);
    }

    strong_typedef<T, Tag>& operator -=(const strong_typedef<T, Tag>& o) {
        _t -= o._t;
        return *this;
    }

    strong_typedef<T, Tag> operator *(const strong_typedef<T, Tag>& o) const {
        return strong_typedef<T, Tag>(_t * o._t);
    }

    strong_typedef<T, Tag>& operator *=(const strong_typedef<T, Tag>& o) {
        _t *= o._t;
        return *this;
    }

    strong_typedef<T, Tag> operator /(const strong_typedef<T, Tag>& o) const {
        return strong_typedef<T, Tag>(_t / o._t);
    }

    strong_typedef<T, Tag>& operator /=(const strong_typedef<T, Tag>& o) {
        _t /= o._t;
        return *this;
    }

    strong_typedef<T, Tag> operator &(const strong_typedef<T, Tag>& o) const {
        return strong_typedef<T, Tag>(_t & o._t);
    }

    strong_typedef<T, Tag> operator |(const strong_typedef<T, Tag>& o) const {
        return strong_typedef<T, Tag>(_t | o._t);
    }

    strong_typedef<T, Tag> operator -() const {
        return strong_typedef<T, Tag>(-_t);
    }

    bool operator ==(const strong_typedef<T, Tag>& o) const {
        return _t == o._t;
    }

    bool operator !=(const strong_typedef<T, Tag>& o) const {
        return _t != o._t;
    }

    bool operator >(const strong_typedef<T, Tag>& o) const {
        return _t > o._t;
    }

    bool operator <(const strong_typedef<T, Tag>& o) const {
        return _t < o._t;
    }

    bool operator >=(const strong_typedef<T, Tag>& o) const {
        return _t >= o._t;
    }

    bool operator <=(const strong_typedef<T, Tag>& o) const {
        return _t <= o._t;
    }
};

#endif
