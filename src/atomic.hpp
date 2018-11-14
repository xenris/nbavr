/// [[Index]]

/// # {{Atomic}}

/// Used to access variables atomically.
///
/// ```c++
/// Atomic<Int32> counter = 0;
///
/// Int32 c = counter;
/// counter += 2;
/// Bool b = (counter == 5);
/// counter->nonatomic()++;
///
/// struct S {
///     Int32 f(Int32 n)
///         return n + 1;
///     }
/// }
///
/// Atomic<S> s;
///
/// Int32 i = s.call(&S::f, 100);
/// ```

#ifndef NBOS_ATOMIC_HPP
#define NBOS_ATOMIC_HPP

#include "hardware/system.hpp"

namespace nbos {

/// ## class Atomic<class Type\>
template <class Type>
class Atomic {
    Type _t;

public:
    /// #### Atomic()
    Atomic() : _t() {
    }

    /// #### Atomic(Type t)
    Atomic(Type t) : _t(t) {
    }

    /// #### Atomic<Type>& operator=(Type t)
    force_inline Atomic<Type>& operator=(const Type& t) {
        atomic {
            _t = t;
        }

        return *this;
    }

    /// #### operator Type()
    /// Returns a copy of the value.
    force_inline operator Type() const {
        atomic {
            return _t;
        }
    }

    /// #### Type getSet(Type t)
    /// Sets the value to t, and returns the previous value.
    force_inline Type getSet(Type t) {
        atomic {
            const Type r = _t;

            _t = t;

            return r;
        }
    }

    /// #### Atomic<Type\>& operator+=(Type t)
    force_inline Atomic<Type>& operator+=(Type t) {
        atomic {
            _t += t;
        }

        return *this;
    }

    /// #### Atomic<Type\>& operator-=(Type t)
    force_inline Atomic<Type>& operator-=(Type t) {
        atomic {
            _t -= t;
        }

        return *this;
    }

    /// #### Atomic<Type\>& operator*=(Type t)
    force_inline Atomic<Type>& operator*=(Type t) {
        atomic {
            _t *= t;
        }

        return *this;
    }

    /// #### Atomic<Type\>& operator/=(Type t)
    force_inline Atomic<Type>& operator/=(Type t) {
        atomic {
            _t /= t;
        }

        return *this;
    }

    /// #### Atomic<Type\>& operator++()
    force_inline Atomic<Type>& operator++() {
        atomic {
            ++_t;
        }

        return *this;
    }

    force_inline Atomic<Type> operator++(Int) {
        atomic {
            return _t++;
        }
    }

    /// #### Atomic<Type\>& operator--()
    force_inline Atomic<Type>& operator--() {
        atomic {
            --_t;
        }

        return *this;
    }

    force_inline Atomic<Type> operator--(Int) {
        atomic {
            return _t--;
        }
    }

    /// #### Atomic<Type\>& operator<<<U\>(U u)
    template <class U>
    force_inline Atomic<Type>& operator<<(const U u) {
        atomic {
            _t << u;
        }

        return *this;
    }

    // template <class ...A, class R>
    // R call(R (Type::* f)(A...), A&& ...args) {
    //     return (_t.*f)(args...);
    // }

    /// #### auto call(F f, ...)
    /// Call member function f with arguments atomically.
    template <class F>
    force_inline auto call(F f) -> decltype((_t.*f)()) {
        atomic {
            return (_t.*f)();
        }
    }

    template <class F, class A1>
    force_inline auto call(F f, A1 a1) -> decltype((_t.*f)(a1)) {
        atomic {
            return (_t.*f)(a1);
        }
    }

    template <class F, class A1, class A2>
    force_inline auto call(F f, A1 a1, A2 a2) -> decltype((_t.*f)(a1, a2)) {
        atomic {
            return (_t.*f)(a1, a2);
        }
    }

    template <class F, class A1, class A2, class A3>
    force_inline auto call(F f, A1 a1, A2 a2, A3 a3) -> decltype((_t.*f)(a1, a2, a3)) {
        atomic {
            return (_t.*f)(a1, a2, a3);
        }
    }

    template <class F, class A1, class A2, class A3, class A4>
    force_inline auto call(F f, A1 a1, A2 a2, A3 a3, A4 a4) -> decltype((_t.*f)(a1, a2, a3, a4)) {
        atomic {
            return (_t.*f)(a1, a2, a3, a4);
        }
    }

    template <class F, class A1, class A2, class A3, class A4, class A5>
    force_inline auto call(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5) -> decltype((_t.*f)(a1, a2, a3, a4, a5)) {
        atomic {
            return (_t.*f)(a1, a2, a3, a4, a5);
        }
    }

    template <class F, class A1, class A2, class A3, class A4, class A5, class A6>
    force_inline auto call(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6) -> decltype((_t.*f)(a1, a2, a3, a4, a5, a6)) {
        atomic {
            return (_t.*f)(a1, a2, a3, a4, a5, a6);
        }
    }

    template <class F, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
    force_inline auto call(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7) -> decltype((_t.*f)(a1, a2, a3, a4, a5, a6, a7)) {
        atomic {
            return (_t.*f)(a1, a2, a3, a4, a5, a6, a7);
        }
    }

    template <class F, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
    force_inline auto call(F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8) -> decltype((_t.*f)(a1, a2, a3, a4, a5, a6, a7, a8)) {
        atomic {
            return (_t.*f)(a1, a2, a3, a4, a5, a6, a7, a8);
        }
    }

    /// #### Type& operator \*()
    /// Non-atomic access to the value.
    force_inline Type& operator*() {
        return _t;
    }
};

} // nbos

#endif
