/// [[Index]]

/// # {{Vector}}

/// ```c++
/// nbos::Vector<Int, 6> vector;
///
/// vector.add(3);
/// vector.add(7);
/// vector.add(1);
/// vector.add(2);
///
/// Int s = vector.size(); // s = 4
///
/// const Int a = vector[1]; // a = 7
///
/// nbos::Vector<Int>* pointer = &vector;
///
/// pointer->add(4);
///
/// const Int b = pointer->get(2); // b = 1
///
/// s = vector.size(); // s = 5
/// ```

#ifndef NBOS_VECTOR_HPP
#define NBOS_VECTOR_HPP

#include "math.hpp"
#include "type.hpp"

namespace nbos {

/// ## class Vector<class Type, Int bufferSize\>
template <class Type, Int bufferSize = -1>
class Vector : public Vector<Type> {
    Type _buffer[bufferSize];

public:

    /// #### Vector()
    /// Construct a vector with space on the stack for the contents.
    explicit Vector() : Vector<Type>(_buffer, bufferSize) {
    }
};

/// ## class Vector<class Type\>
template <class Type>
class Vector<Type, -1> {
    Type*const _buffer;
    const Int _bufferSize;
    Int _size;

public:

    /// #### Vector(Type\* buffer, Int bufferSize)
    /// Construct a vector with the given buffer.
    Vector(Type* buffer, Int bufferSize) : _buffer(buffer), _bufferSize(bufferSize) {
        _size = 0;
    }

    /// #### Bool add(Type t)
    /// Returns true on success.
    Bool add(const Type& t) {
        if(full()) {
            return false;
        }

        _buffer[_size] = t;

        _size += 1;

        return true;
    }

    /// #### void fill(const Type& t) {
    /// Fills the entire buffer with the given value.
    void fill(const Type& t) {
        for(Int i = 0; i < _bufferSize; i++) {
            _buffer[i] = t;
        }

        _size = _bufferSize;
    }

    /// #### void clear() {
    /// Remove all elements from the vector.
    void clear() {
        _size = 0;
    }

    /// #### Int size()
    /// Get the number of elements currently in the vector.
    Int size() const {
        return _size;
    }

    /// #### Bool resize(Int size)
    /// Set the size of the vector.<br>
    /// Returns false, and doesn't change the size if the given size is larger than the buffer.
    Bool resize(Int size) const {
        if(size > _bufferSize) {
            return false;
        } else {
            _size = size;

            return true;
        }
    }

    /// #### Int free()
    /// Get the amount of free space in the vector.
    Int free() const {
        return _bufferSize - _size;
    }

    /// ### Int capacity()
    /// Get the total capacity of the vector.
    Int capacity() const {
        return _bufferSize;
    }

    /// #### Bool empty()
    /// Returns true if the vector is empty.
    Bool empty() const {
        return _size == 0;
    }

    /// #### Bool full()
    /// Returns true if the vector is full.
    Bool full() const {
        return _size == _bufferSize;
    }

    /// #### Type& operator [](Int n)
    Type& operator [](Int n) {
        return _buffer[n];
    }

    const Type& operator [](Int n) const {
        return _buffer[n];
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

    /// #### Vector<Type\>& operator =(Vector<Type\> other)
    Vector<Type>& operator =(const Vector<Type>& other) {
        const Int count = nbos::min(_bufferSize, other.size());

        for(Int i = 0; i < count; i++) {
            _buffer[i] = other[i];
        }

        _size = other.size();

        return *this;
    }
};

} // nbos

#endif
