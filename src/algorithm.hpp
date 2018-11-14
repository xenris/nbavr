/// [[Index]]

/// # {{Algorithms}}

#ifndef NBOS_ALGORITHM_HPP
#define NBOS_ALGORITHM_HPP

#include "safe.hpp"

namespace nbos {

template <class T>
inline void reverse(const T* from, T* to, Int length);

/// #### void reverse<T\>(T\* array, Int length)
template <class T>
inline void reverse(T* array, Int length) {
    reverse(array, array, length);
}

/// #### void reverse<T\>(const T\* from, T\* to, Int length)
template <class T>
inline void reverse(const T* from, T* to, Int length) {
    for(Int i = 0; i < (length + 1) / 2; i++) {
        const Int j = (length - 1) - i;

        const T a = from[i];
        const T b = from[j];

        to[i] = b;
        to[j] = a;
    }
}

/// #### void copy<T\>(const T\* from, T\* to, Int length)
template <class T>
inline void copy(const T* from, T* to, Int length) {
    for(Int i = 0; i < length; i++) {
        to[i] = from[i];
    }
}

/// #### void swap<T\>(T\* a, T\* b)
template <class T>
inline void swap(T* a, T* b) {
    T t = *a;
    *a = *b;
    *b = t;
}

template <class T>
inline Int partition(T* array, Int low, Int high) {
    const T& pivot = array[high];

    Int i = low - 1;

    for(Int j = low; j < high; j++) {
        if(array[j] < pivot) {
            i += 1;

            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);

    return i + 1;
}

template <class T>
inline void quicksort(T* array, Int low, Int high) {
    if(low < high) {
        const Int p = partition(array, low, high);

        quicksort(array, low, p - 1);
        quicksort(array, p + 1, high);
    }
}

/// #### void quicksort(T\* array, Int size)
template <class T>
inline void quicksort(T* array, Int size) {
    quicksort(array, 0, size - 1);
}

} // nbos

#endif
