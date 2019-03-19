/// [[Index]]

/// # {{Queue}}

/// ```c++
/// nbos::Queue<Int32, 6> queue;
///
/// queue.push(3);
/// queue.push(7);
/// queue.push(1);
/// queue.push(2);
///
/// Int s = queue.size(); // s = 4
///
/// Int32 a = 0;
///
/// queue.pop(&a); // a = 3
/// queue.pop(&a); // a = 7
///
/// s = queue.size(); // s = 2
///
/// nbos::Queue<Int32>* pointer = &queue;
///
/// pointer->push(4);
///
/// s = queue.size(); // s = 3
/// ```

#ifndef NBOS_QUEUE_HPP
#define NBOS_QUEUE_HPP

#include "optional.hpp"
#include "callback.hpp"

namespace nbos {

/// ## class Queue<class Type, Int bufferSize\>
template <class Type, Int bufferSize = -1>
class Queue : public Queue<Type> {
    Type _buffer[bufferSize];

public:

    /// #### Queue()
    /// Construct a queue with space on the stack for the contents.
    explicit Queue() : Queue<Type>(_buffer, bufferSize) {
    }
};

/// ## class Queue<class Type\>
template <class Type>
class Queue<Type, -1> {
    Type*const _buffer;
    Int _bufferSize;
    Int _head = 0;
    Int _tail = 0;
    Bool _full = false;
    Callback<void> _callback;
    void* _callback_data;

public:

    /// #### Queue(Type\* buffer, Int bufferSize)
    /// Construct a queue with the given buffer.
    Queue(Type* buffer, Int bufferSize) : _buffer(buffer) {
        _bufferSize = bufferSize;
    }

    /// #### Bool push(Type t)
    /// Returns true on success.
    Bool push(const Type& t) {
        if(full()) {
            return false;
        }

        _buffer[_head] = t;

        _head = (_head + 1) % _bufferSize;

        if(_head == _tail) {
            _full = true;
        }

        return true;
    }

    /// #### [[Optional]]<Type\> pop()
    Optional<Type> pop() {
        if(empty()) {
            return {};
        }

        const Optional<Type> result = _buffer[_tail];

        _tail = (_tail + 1) % _bufferSize;

        _full = false;

        return result;
    }

    /// #### [[Optional]]<Type\> peek()
    Optional<Type> peek() const {
        if(empty()) {
            return {};
        }

        return _buffer[_tail];
    }

    /// #### void clear()
    /// Remove all elements from the queue.
    void clear() {
        _head = _tail;
        _full = false;
    }

    /// #### Int size()
    /// Get the number of elements currently in the queue.
    Int size() {
        if(full()) {
            return _bufferSize;
        }

        Int s = _head - _tail;

        if(s < 0) {
            s += _bufferSize;
        }

        return s;
    }

    /// #### Int free()
    /// Get the amount of free space in the queue.
    Int free() {
        return _bufferSize - size();
    }

    /// ### Int capacity()
    /// Get the total capacity of the queue.
    Int capacity() {
        return _bufferSize;
    }

    /// #### Bool empty()
    /// Returns true if the queue is empty.
    Bool empty() {
        return (_head == _tail) && !full();
    }

    /// #### Bool full()
    /// Returns true if the queue is full.
    Bool full() {
        return _full || (_bufferSize == 0);
    }

    // void setCallback(void (*callback)(void*), void* data = nullptr) {
    //     callback_func = callback;
    //     callback_data = data;
    // }

    /// #### void setCallback(Callback callback, T\* data)
    /// Set the callback function and data for queue notifications.
    template<class T>
    void setCallback(Callback<T> callback, T* data) {
        _callback = (Callback<void>)callback;
        _callback_data = data;
    }

    /// #### void callCallback()
    /// Call the callback notification function.
    void callCallback() {
        if(_callback != nullptr) {
            _callback(_callback_data);
        }
    }

    Queue<Type>* p() {
        return this;
    }

    const Queue<Type>* p() const {
        return this;
    }
};

#ifdef TEST

TEST(Container, Queue) {
    Queue<Int16, 3> queue;

    EXPECT_EQ(queue.size(), 0);
    EXPECT_EQ(queue.capacity(), 3);

    EXPECT_EQ(queue.full(), false);

    EXPECT_EQ(queue.push(1), true);
    EXPECT_EQ(queue.size(), 1);
    EXPECT_EQ(queue.push(2), true);
    EXPECT_EQ(queue.size(), 2);
    EXPECT_EQ(queue.push(3), true);
    EXPECT_EQ(queue.size(), 3);
    EXPECT_EQ(queue.full(), true);
    EXPECT_EQ(queue.push(4), false);
    EXPECT_EQ(queue.size(), 3);
    EXPECT_EQ(queue.capacity(), 3);

    Optional<Int16> n;
    EXPECT_EQ(n = queue.pop(), true);
    EXPECT_EQ(queue.size(), 2);
    EXPECT_EQ(*n, 1);
    EXPECT_EQ(n = queue.pop(), true);
    EXPECT_EQ(queue.size(), 1);
    EXPECT_EQ(*n, 2);

    EXPECT_EQ(queue.full(), false);

    EXPECT_EQ(queue.push(5), true);
    EXPECT_EQ(queue.size(), 2);

    EXPECT_EQ(n = queue.pop(), true);
    EXPECT_EQ(queue.size(), 1);
    EXPECT_EQ(*n, 3);

    EXPECT_EQ(n = queue.pop(), true);
    EXPECT_EQ(queue.size(), 0);
    EXPECT_EQ(*n, 5);

    EXPECT_EQ(queue.empty(), true);

    EXPECT_EQ(n = queue.pop(), false);
    EXPECT_EQ(queue.size(), 0);

    EXPECT_EQ(queue.push(6), true);
    EXPECT_EQ(queue.size(), 1);
    EXPECT_EQ(queue.empty(), false);
    queue.clear();
    EXPECT_EQ(queue.empty(), true);

    // Make sure notify callbacks don't interfere.

    Queue<Int16, 3> queueF;
    Queue<Int16, 3> queueG;

    Callback<Char> f = [](Char* c) {
        *c = 'f';
    };

    Callback<Char> g = [](Char* c) {
        *c = 'g';
    };

    Char c = 'a';

    queueF.setCallback(f, &c);
    queueG.setCallback(g, &c);

    EXPECT_EQ(c, 'a');

    queueF.callCallback();

    EXPECT_EQ(c, 'f');

    queueG.callCallback();

    EXPECT_EQ(c, 'g');
}

#endif

} // nbos

#endif
