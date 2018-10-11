/// [[Index]]

/// # {{Stack}}

/// ```c++
/// nbos::Stack<int, 6> stack;
///
/// stack.push(3);
/// stack.push(7);
/// stack.push(1);
/// stack.push(2);
///
/// int s = stack.size(); // s = 4
///
/// int a = 0;
///
/// stack.pop(&a); // a = 2
/// stack.pop(&a); // a = 1
///
/// s = stack.size(); // s = 2
///
/// nbos::Stack<int>* pointer = &stack;
///
/// pointer->push(4);
///
/// s = stack.size(); // s = 3
/// ```

#ifndef NBOS_STACK_HPP
#define NBOS_STACK_HPP

#include "type.hpp"

namespace nbos {

/// ## class Stack<class Type, int bufferSize\>
template <class Type, int bufferSize = -1>
class Stack : public Stack<Type> {
    Type _buffer[bufferSize];

public:

    /// #### Stack()
    /// Construct a stack with space on the system stack for the contents.
    explicit Stack() : Stack<Type>(_buffer, bufferSize) {
    }
};

/// ## class Stack
template <class T>
struct Stack<T, -1> {
    using Type = T;

private:

    T*const _buffer;
    const int _bufferSize;
    int _head;

public:

    /// #### Stack(Type\* buffer, int bufferSize)
    /// Construct a stack with the given buffer.
    Stack(Type* buffer, int bufferSize) : _buffer(buffer), _bufferSize(bufferSize) {
        _head = 0;;
    }

    /// #### bool push(Type t)
    /// Returns true on success.
    bool push(T t) {
        if(full()) {
            return false;
        }

        _buffer[_head] = t;

        _head += 1;

        return true;
    }

    /// #### bool pop(Type\* t)
    /// Returns true on success.
    bool pop(T* t) {
        if(empty()) {
            return false;
        }

        _head -= 1;

        *t = _buffer[_head];

        return true;
    }

    /// #### bool peek(Type\* t)
    /// Returns true on success.
    bool peek(T* t) {
        if(empty()) {
            return false;
        }

        *t = _buffer[_head - 1];

        return true;
    }

    /// #### void clear()
    /// Remove all elements from the stack.
    void clear() {
        _head = 0;
    }

    /// #### int size()
    /// Get the number of elements currently in the stack.
    int size() const {
        return _head;
    }

    /// #### int free()
    /// Get the amount of free space in the stack.
    int free() const {
        return _bufferSize - _head;
    }

    /// ### int capacity()
    /// Get the total capacity of the stack.
    int capacity() const {
        return _bufferSize;
    }

    /// #### bool empty()
    /// Returns true if the stack is empty.
    bool empty() const {
        return _head == 0;
    }

    /// #### bool full()
    /// Returns true if the stack is full.
    bool full() const {
        return _head == _bufferSize;
    }
};

} // nbos

#endif
