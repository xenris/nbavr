#ifndef NBAVR_ARRAY_HPP
#define NBAVR_ARRAY_HPP

/// # Array

#include "math.hpp"
#include "type.hpp"

/// ## class Array<class T, int S>
template <class T, int S>
struct Array {
    /// #### type size_t
    /// The smallest signed integer type which can index the entire array.
    using size_t = typename conditional<S <= 127, int8_t, int16_t>::type;
    /// #### type type
    /// The type that the array contains.
    using type = T;

private:

    T _array[S];

public:

    /// #### T& operator[](size_t i)
    /// Element access operator.<br>
    /// i is clipped to array length.
    T& operator[](size_t i) {
        i = clip(i, size_t(0), size_t(S - 1));

        return _array[i];
    }

    /// #### void fill(T t)
    /// Fills the array with value t.
    void fill(T t) {
        for(T& n : this) {
            n = t;
        }
    }

    /// #### size_t size()
    /// Returns the length of the array.
    size_t size() {
        return S;
    }

    T* begin() {
        return &_array[0];
    }

    T* end() {
        return &_array[S];
    }
};

#endif
