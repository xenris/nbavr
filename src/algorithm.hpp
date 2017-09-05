#ifndef NBAVR_ALGORITHM_HPP
#define NBAVR_ALGORITHM_HPP

/// # Algorithm

/// #### T* reverse(T* array, size_t length)
/// Reverse an array.<br>
/// Returns the given array.
template <class T>
force_inline T* reverse(T* array, size_t length) {
    for(size_t i = 0; i < (length + 1) / 2; i++) {
        const size_t j = (length - 1) - i;
        const T temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    return array;
}

/// #### void swap(T& a, T& b)
/// Swap two variables.
template <class T>
force_inline void swap(T& a, T& b) {
    T t = a;
    a = b;
    b = t;
}

#endif
