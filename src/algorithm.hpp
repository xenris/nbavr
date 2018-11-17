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

#ifdef TEST

TEST(Algorithm, reverse) {
    Char str[8];

    strcpy((Char::T*)str, "");
    reverse(str, 0);
    EXPECT_STREQ((Char::T*)str, "");

    strcpy((Char::T*)str, "a");
    reverse(str, 1);
    EXPECT_STREQ((Char::T*)str, "a");

    strcpy((Char::T*)str, "ab");
    reverse(str, 2);
    EXPECT_STREQ((Char::T*)str, "ba");

    strcpy((Char::T*)str, "abc");
    reverse(str, 3);
    EXPECT_STREQ((Char::T*)str, "cba");

    strcpy((Char::T*)str, "abc");
    reverse(str, 2);
    EXPECT_STREQ((Char::T*)str, "bac");
}

TEST(Algorithm, quicksort) {
    Int array1[6];

    array1[0] = 6;
    array1[1] = 8;
    array1[2] = 4;
    array1[3] = 5;
    array1[4] = 1;
    array1[5] = 2;

    quicksort(array1, 6);

    EXPECT_EQ(array1[0], 1);
    EXPECT_EQ(array1[1], 2);
    EXPECT_EQ(array1[2], 4);
    EXPECT_EQ(array1[3], 5);
    EXPECT_EQ(array1[4], 6);
    EXPECT_EQ(array1[5], 8);
}

#endif

} // nbos

#endif
