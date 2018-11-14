/// [[Index]]

/// # {{Stack}}

/// ```c++
/// nbos::Stack<Int, 6> stack;
///
/// stack.push(3);
/// stack.push(7);
/// stack.push(1);
/// stack.push(2);
///
/// Int s = stack.size(); // s = 4
///
/// Int a = 0;
///
/// stack.pop(&a); // a = 2
/// stack.pop(&a); // a = 1
///
/// s = stack.size(); // s = 2
///
/// nbos::Stack<Int>* pointer = &stack;
///
/// pointer->push(4);
///
/// s = stack.size(); // s = 3
/// ```

#ifndef NBOS_STACK_HPP
#define NBOS_STACK_HPP

#include "safe.hpp"
#include "optional.hpp"

namespace nbos {

/// ## class Stack<class Type, Int bufferSize\>
template <class Type, Int bufferSize = -1>
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
    const Int _bufferSize;
    Int _head;

public:

    /// #### Stack(Type\* buffer, Int bufferSize)
    /// Construct a stack with the given buffer.
    Stack(Type* buffer, Int bufferSize) : _buffer(buffer), _bufferSize(bufferSize) {
        _head = 0;;
    }

    /// #### Bool push(Type t)
    /// Returns true on success.
    Bool push(T t) {
        if(full()) {
            return false;
        }

        _buffer[_head] = t;

        _head += 1;

        return true;
    }

    /// #### [[Optional]]<Type\> pop()
    Optional<Type> pop() {
        if(empty()) {
            return {};
        }

        _head -= 1;

        return _buffer[_head];
    }

    /// #### [[Optional]]<Type\> peek()
    Optional<Type> peek() const {
        if(empty()) {
            return false;
        }

        return _buffer[_head - 1];
    }

    /// #### void clear()
    /// Remove all elements from the stack.
    void clear() {
        _head = 0;
    }

    /// #### Int size()
    /// Get the number of elements currently in the stack.
    Int size() const {
        return _head;
    }

    /// #### Int free()
    /// Get the amount of free space in the stack.
    Int free() const {
        return _bufferSize - _head;
    }

    /// ### Int capacity()
    /// Get the total capacity of the stack.
    Int capacity() const {
        return _bufferSize;
    }

    /// #### Bool empty()
    /// Returns true if the stack is empty.
    Bool empty() const {
        return _head == 0;
    }

    /// #### Bool full()
    /// Returns true if the stack is full.
    Bool full() const {
        return _head == _bufferSize;
    }
};

} // nbos

#endif
