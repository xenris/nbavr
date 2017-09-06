#ifndef NBAVR_ATOMIC_HPP
#define NBAVR_ATOMIC_HPP

/// # Atomic
/// Used to access variables atomically.<br>

/// ## Example
/// ```c++
/// Atomic<int32_t> counter = 0;

/// void loop {
///     int32_t c = counter;
///     int32_t c = counter.getSet(0);
///     counter += 2;
///     if(counter == 5) {
///     }
/// }

/// // Interrupt.
/// static void callback(void* data) {
///     counter.direct()++;
/// }
/// ```

/// ## class Atomic<class Type>
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
        T r;

        atomic {
            r = _t;
        }

        return r;
    }

    /// #### T getSet(T t)
    /// Sets the value to t, and returns its previous value.
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
        T r;

        atomic {
            r = _t;
            _t++;
        }

        return r;
    }

    force_inline Atomic<T>& operator--() {
        atomic {
            _t--;
        }

        return *this;
    }

    force_inline Atomic<T> operator--(int) {
        T r;

        atomic {
            r = _t;
            _t--;
        }

        return r;
    }

    /// #### T& direct()
    /// Non-atomic access to the value.
    force_inline T& direct() {
        return _t;
    }
};

#endif
