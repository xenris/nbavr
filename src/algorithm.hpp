#ifndef NBAVR_ALGORITHM_HPP
#define NBAVR_ALGORITHM_HPP

/// # Algorithm

/// #### T\* reverse(T\* array, size_t length)
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

/// #### T\* copy(T\* src, T\* dst, size_t length)
/// Copy an array, from src to dst.<br>
/// Returns the dst array.
template <class T>
force_inline T* copy(T* src, T* dst, size_t length) {
    for(size_t i = 0; i < length; i++) {
        dst[i] = src[i];
    }

    return dst;
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
