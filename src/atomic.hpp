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

    force_inline T getSet(T t) {
        T r;

        atomic {
            r = _t;
            _t = t;
        }

        return r;
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

    force_inline Atomic<T>& operator++() {
        atomic {
            _t++;
        }

        return *this;
    }

    force_inline Atomic<T> operator++(int) {
        T t = *this;

        atomic {
            ++*this;
        }

        return t;
    }

    force_inline Atomic<T>& operator--() {
        atomic {
            _t--;
        }

        return *this;
    }

    force_inline Atomic<T> operator--(int) {
        T t = *this;

        atomic {
            --*this;
        }

        return t;
    }

    force_inline T& direct() {
        return _t;
    }
};

#endif
