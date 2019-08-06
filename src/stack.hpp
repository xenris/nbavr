/// [[Index]]

/// # {{Stack}}

/// ```c++
/// nblib::Stack<int, 6> stack;
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
/// nblib::Stack<int>* pointer = &stack;
///
/// pointer->push(4);
///
/// s = stack.size(); // s = 3
/// ```

#ifndef NBLIB_STACK_HPP
#define NBLIB_STACK_HPP

#include "primitive.hpp"
#include "optional.hpp"

namespace nblib {

/// ## class Stack<class Type, int bufferSize\>
template <class Type, int bufferSize = -1>
class Stack : public Stack<Type> {
    Type _buffer[uint(bufferSize)];

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

#ifdef TEST

TEST(Container, Stack) {
    Stack<int16_t, 3> stack;

    EXPECT_EQ(stack.size(), 0);
    EXPECT_EQ(stack.capacity(), 3);

    EXPECT_EQ(stack.full(), false);

    EXPECT_EQ(stack.push(1), true);
    EXPECT_EQ(stack.size(), 1);
    EXPECT_EQ(stack.push(2), true);
    EXPECT_EQ(stack.size(), 2);
    EXPECT_EQ(stack.push(3), true);
    EXPECT_EQ(stack.size(), 3);
    EXPECT_EQ(stack.full(), true);
    EXPECT_EQ(stack.push(4), false);
    EXPECT_EQ(stack.size(), 3);
    EXPECT_EQ(stack.capacity(), 3);

    Optional<int16_t> n;
    EXPECT_EQ(bool(n = stack.pop()), true);
    EXPECT_EQ(stack.size(), 2);
    EXPECT_EQ(*n, 3);
    EXPECT_EQ(bool(n = stack.pop()), true);
    EXPECT_EQ(stack.size(), 1);
    EXPECT_EQ(*n, 2);

    EXPECT_EQ(stack.full(), false);

    EXPECT_EQ(stack.push(5), true);
    EXPECT_EQ(stack.size(), 2);

    EXPECT_EQ(bool(n = stack.pop()), true);
    EXPECT_EQ(stack.size(), 1);
    EXPECT_EQ(*n, 5);

    EXPECT_EQ(bool(n = stack.pop()), true);
    EXPECT_EQ(stack.size(), 0);
    EXPECT_EQ(*n, 1);

    EXPECT_EQ(stack.empty(), true);

    EXPECT_EQ(bool(n = stack.pop()), false);
    EXPECT_EQ(stack.size(), 0);

    EXPECT_EQ(stack.push(6), true);
    EXPECT_EQ(stack.size(), 1);
    EXPECT_EQ(stack.empty(), false);
    stack.clear();
    EXPECT_EQ(stack.empty(), true);
}

#endif // TEST

} // nblib

#endif
