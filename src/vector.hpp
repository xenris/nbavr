/// [[Index]]

/// # {{Vector}}

/// ```c++
/// nbos::Vector<int, 6> vector;
///
/// vector.add(3);
/// vector.add(7);
/// vector.add(1);
/// vector.add(2);
///
/// int s = vector.size(); // s = 4
///
/// const int a = vector[1]; // a = 7
///
/// nbos::Vector<int>* pointer = &vector;
///
/// pointer->add(4);
///
/// const int b = pointer->get(2); // b = 1
///
/// s = vector.size(); // s = 5
/// ```

#ifndef NBOS_VECTOR_HPP
#define NBOS_VECTOR_HPP

#include "math.hpp"
#include "type.hpp"

namespace nbos {

/// ## class Vector<class Type, int bufferSize\>
template <class Type, int bufferSize = -1>
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
    const int _bufferSize;
    int _size;

public:

    /// #### Vector(Type\* buffer, int bufferSize)
    /// Construct a vector with the given buffer.
    Vector(Type* buffer, int bufferSize) : _buffer(buffer), _bufferSize(bufferSize) {
        _size = 0;
    }

    /// #### bool add(Type t)
    /// Returns true on success.
    bool add(const Type& t) {
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
        for(int i = 0; i < _bufferSize; i++) {
            _buffer[i] = t;
        }

        _size = _bufferSize;
    }

    /// #### void clear() {
    /// Remove all elements from the vector.
    void clear() {
        _size = 0;
    }

    /// #### int size()
    /// Get the number of elements currently in the vector.
    int size() const {
        return _size;
    }

    /// #### bool resize(int size)
    /// Set the size of the vector.<br>
    /// Returns false, and doesn't change the size if the given size is larger than the buffer.
    bool resize(int size) const {
        if(size > _bufferSize) {
            return false;
        } else {
            _size = size;

            return true;
        }
    }

    /// #### int free()
    /// Get the amount of free space in the vector.
    int free() const {
        return _bufferSize - _size;
    }

    /// ### int capacity()
    /// Get the total capacity of the vector.
    int capacity() const {
        return _bufferSize;
    }

    /// #### bool empty()
    /// Returns true if the vector is empty.
    bool empty() const {
        return _size == 0;
    }

    /// #### bool full()
    /// Returns true if the vector is full.
    bool full() const {
        return _size == _bufferSize;
    }

    /// #### Type& operator [](int n)
    Type& operator [](int n) {
        return _buffer[n];
    }

    const Type& operator [](int n) const {
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
        const int count = nbos::min(_bufferSize, other.size());

        for(int i = 0; i < count; i++) {
            _buffer[i] = other[i];
        }

        _size = other.size();

        return *this;
    }
};

} // nbos

#endif
