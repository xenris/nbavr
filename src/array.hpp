/// [[Index]]

/// # {{Array}}

/// ```c++
/// nblib::Array<int32_t, 6> array;
///
/// array[0] = 6;
/// array[1] = 8;
/// array[2] = 4;
/// array[3] = 5;
/// array[4] = 1;
/// array[5] = 2;
///
/// nblib::quicksort(array->begin(), array->size());
///
/// nblib::Array<int32_t>* pointer = &array;
///
/// int32_t n = pointer->get(0); // n = 1
///
/// pointer->fill(0);
///
/// for(auto n& : pointer) {
///     n += 5;
/// }
/// ```

#ifndef NBLIB_ARRAY_HPP
#define NBLIB_ARRAY_HPP

#include "initializer_list.hpp"
#include "iterator.hpp"
#include "math.hpp"

namespace nblib {

/// ## class Array<class Type, int size\>
template <class Type, int size = -1>
class Array : public Array<Type> {
    Type _buffer[uint(size)];

public:

    /// #### Array()
    explicit Array() : Array<Type>(_buffer, size) {
    }
};

/// ## class Array<class Type\>
template <class Type>
class Array<Type, -1> {
    Type*const _buffer;
    const int _size;

public:

    /// #### Array(Type\* buffer, int size)
    Array(Type* buffer, int size) : _buffer(buffer), _size(size) {
    }

    Array(initializer_list<Type> buffer) : _buffer(buffer), _size(size) {
    }

    /// #### void fill(Type t)
    void fill(const Type& t) {
        for(auto& n : *this) {
            n = t;
        }
    }

    /// #### int size()
    int size() const {
        return _size;
    }

    /// #### Type& operator \[\](int i)
    Type& operator [](int i) {
        return _buffer[i];
    }

    const Type& operator [](int i) const {
        return _buffer[i];
    }

    /// #### Type& get(int i)
    Type& get(int i) {
        return _buffer[i];
    }

    const Type& get(int i) const {
        return _buffer[i];
    }

    /// #### Array<Type\>& operator =(Array<Type\> other)
    Array<Type>& operator =(const Array<Type>& other) {
        const int count = min(size(), other.size());

        for(int i = 0; i < count; i++) {
            _buffer[i] = other[i];
        }

        return *this;
    }

    /// #### Type\* begin()
    Type* begin() {
        return &_buffer[0];
    }

    const Type* begin() const {
        return &_buffer[0];
    }

    /// #### Type\* end()
    Type* end() {
        return &_buffer[_size];
    }

    const Type* end() const {
        return &_buffer[_size];
    }

    Array<Type>* ptr() {
        return this;
    }

    const Array<Type>* ptr() const {
        return this;
    }
};

#ifdef TEST

TEST(Container, Array) {
    Array<int16_t, 3> array;

    EXPECT_EQ(array.size(), 3);

    array[0] = 6;
    array[1] = 7;
    array[2] = 8;

    EXPECT_EQ(array[0], 6);
    EXPECT_EQ(array[1], 7);
    EXPECT_EQ(array[2], 8);

    for(auto& n : array) {
        n = 0;
    }

    EXPECT_EQ(array[0], 0);
    EXPECT_EQ(array[1], 0);
    EXPECT_EQ(array[2], 0);

    array.fill(3);

    EXPECT_EQ(array[0], 3);
    EXPECT_EQ(array[1], 3);
    EXPECT_EQ(array[2], 3);

    Array<int16_t, 3> array2 = array;

    EXPECT_EQ(array2[0], 3);
    EXPECT_EQ(array2[1], 3);
    EXPECT_EQ(array2[2], 3);
}

#endif // TEST

} // nblib

#endif
