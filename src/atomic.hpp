#ifndef NBAVR_ATOMIC_HPP
#define NBAVR_ATOMIC_HPP

template <class T>
class Atomic {
    T _t;

public:
    Atomic(T t) : _t(t) {
    }

    Atomic() : _t() {
    }

    force_inline Atomic<T>& operator=(const T t) {
        atomic {
            _t = t;
        }

        return *this;
    }

    force_inline operator T() const {
        T t;

        atomic {
            t = _t;
        }

        return t;
    }

    force_inline Atomic<T>& operator+=(T t) {
        atomic {
            _t += t;
        }

        return *this;
    }

    force_inline Atomic<T>& operator-=(T t) {
        atomic {
            _t -= t;
        }

        return *this;
    }

    force_inline Atomic<T>& operator*=(T t) {
        atomic {
            _t *= t;
        }

        return *this;
    }

    force_inline Atomic<T>& operator/=(T t) {
        atomic {
            _t /= t;
        }

        return *this;
    }

    force_inline T& direct() {
        return _t;
    }
};

#endif
