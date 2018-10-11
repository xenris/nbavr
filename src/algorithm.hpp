/// # Algorithm

#ifndef NBOS_ALGORITHM_HPP
#define NBOS_ALGORITHM_HPP

#include "math.hpp"

namespace nbos {

template <class T>
force_inline void reverse(const T* from, T* to, int length);

/// #### void reverse<T\>(T\* array, int length)
template <class T>
force_inline void reverse(T* array, int length) {
    reverse(array, array, length);
}

/// #### void reverse<T\>(const T\* from, T\* to, int length)
template <class T>
force_inline void reverse(const T* from, T* to, int length) {
    for(int i = 0; i < (length + 1) / 2; i++) {
        const int j = (length - 1) - i;

        const T a = from[i];
        const T b = from[j];

        to[i] = b;
        to[j] = a;
    }
}

/// #### void copy<T\>(const T\* from, T\* to, int length)
template <class T>
force_inline void copy(const T* from, T* to, int length) {
    for(int i = 0; i < length; i++) {
        to[i] = from[i];
    }
}

/// #### void swap<T\>(T& a, T& b)
template <class T>
force_inline void swap(T* a, T* b) {
    T t = *a;
    *a = *b;
    *b = t;
}

template <class T>
int partition(T* array, int low, int high) {
    const T& pivot = array[high];

    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(array[j] < pivot) {
            i += 1;

            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);

    return i + 1;
}

template <class T>
void quicksort(T* array, int low, int high) {
    if(low < high) {
        const int p = partition(array, low, high);

        quicksort(array, low, p - 1);
        quicksort(array, p + 1, high);
    }
}

/// #### void quicksort(T\* array, int size)
template <class T>
void quicksort(T* array, int size) {
    quicksort(array, 0, size - 1);
}

} // nbos

#endif
