/// [[Index]]

/// # {{Queue}}

/// ```c++
/// nblib::Queue<int, 6> queue;
///
/// queue.push(3);
/// queue.push(7);
/// queue.push(1);
/// queue.push(2);
///
/// int s = queue.size(); // s = 4
///
/// int a = 0;
///
/// queue.pop(&a); // a = 3
/// queue.pop(&a); // a = 7
///
/// s = queue.size(); // s = 2
///
/// nblib::Queue<int>* pointer = &queue;
///
/// pointer->push(4);
///
/// s = queue.size(); // s = 3
/// ```

#ifndef NBLIB_QUEUE_HPP
#define NBLIB_QUEUE_HPP

#include "callback.hpp"
#include "optional.hpp"
#include "primitive.hpp"

namespace nblib {

// XXX FIXME Should it be ssize_t instead?

/// ## class Queue<class Type, size_t bufferSize\>
template <class Type, size_t bufferSize = 0>
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
class Queue<Type, 0> {
    Type*const _buffer;
    size_t _bufferSize;
    size_t _head = 0;
    size_t _tail = 0;
    bool _full = false;
    Callback<void> _callback;
    void* _callback_data;

public:

    /// #### Queue(Type\* buffer, size_t bufferSize)
    /// Construct a queue with the given buffer.
    Queue(Type* buffer, size_t bufferSize) : _buffer(buffer) {
        _bufferSize = bufferSize;
    }

    /// #### bool push(Type t)
    /// Returns true on success.
    bool push(const Type& t) {
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

    /// #### T\* push()
    /// Pushes an uninitialised element to the queue and returns a pointer to it.<br>
    /// Useful to avoid copying large blocks of memory if the elements are large.<br>
    /// Returns nullptr if the queue is full.
    Type* push() {
        if(full()) {
            return nullptr;
        }

        Type*const t = &_buffer[_head];

        _head = (_head + 1) % _bufferSize;

        if(_head == _tail) {
            _full = true;
        }

        return t;
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

    /// #### Type\* peek()
    Type* peek(int) const {
        if(empty()) {
            return nullptr;
        }

        return &_buffer[_tail];
    }

    /// #### void clear()
    /// Remove all elements from the queue.
    void clear() {
        _head = _tail;
        _full = false;
    }

    /// #### size_t size()
    /// Get the number of elements currently in the queue.
    size_t size() const {
        if(full()) {
            return _bufferSize;
        }

        ssize_t s = ssize_t(_head - _tail);

        if(s < 0) {
            s += ssize_t(_bufferSize);
        }

        return size_t(s);
    }

    /// #### size_t free()
    /// Get the amount of free space in the queue.
    size_t free() const {
        return _bufferSize - size();
    }

    /// ### size_t capacity()
    /// Get the total capacity of the queue.
    size_t capacity() const {
        return _bufferSize;
    }

    /// #### bool empty()
    /// Returns true if the queue is empty.
    bool empty() const {
        return (_head == _tail) && !full();
    }

    /// #### bool full()
    /// Returns true if the queue is full.
    bool full() const {
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

    Queue<Type>* ptr() {
        return this;
    }

    const Queue<Type>* ptr() const {
        return this;
    }
};

#ifdef TEST

TEST(Container, Queue) {
    Queue<int16_t, 3> queue;

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

    Optional<int16_t> n;
    EXPECT_EQ(bool(n = queue.pop()), true);
    EXPECT_EQ(queue.size(), 2);
    EXPECT_EQ(*n, 1);
    EXPECT_EQ(bool(n = queue.pop()), true);
    EXPECT_EQ(queue.size(), 1);
    EXPECT_EQ(*n, 2);

    EXPECT_EQ(queue.full(), false);

    EXPECT_EQ(queue.push(5), true);
    EXPECT_EQ(queue.size(), 2);

    EXPECT_EQ(bool(n = queue.pop()), true);
    EXPECT_EQ(queue.size(), 1);
    EXPECT_EQ(*n, 3);

    EXPECT_EQ(bool(n = queue.pop()), true);
    EXPECT_EQ(queue.size(), 0);
    EXPECT_EQ(*n, 5);

    EXPECT_EQ(queue.empty(), true);

    EXPECT_EQ(bool(n = queue.pop()), false);
    EXPECT_EQ(queue.size(), 0);

    EXPECT_EQ(queue.push(6), true);
    EXPECT_EQ(queue.size(), 1);
    EXPECT_EQ(queue.empty(), false);
    queue.clear();
    EXPECT_EQ(queue.empty(), true);

    // Make sure notify callbacks don't interfere.

    Queue<int16_t, 3> queueF;
    Queue<int16_t, 3> queueG;

    Callback<char> f = [](char* c) {
        *c = 'f';
    };

    Callback<char> g = [](char* c) {
        *c = 'g';
    };

    char c = 'a';

    queueF.setCallback(f, &c);
    queueG.setCallback(g, &c);

    EXPECT_EQ(c, 'a');

    queueF.callCallback();

    EXPECT_EQ(c, 'f');

    queueG.callCallback();

    EXPECT_EQ(c, 'g');
}

#endif

} // nblib

#endif
