/// [[Index]]

/// # {{Queue}}

/// ```c++
/// nbos::Queue<int, 6> queue;
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
/// nbos::Queue<int>* pointer = &queue;
///
/// pointer->push(4);
///
/// s = queue.size(); // s = 3
/// ```

#ifndef NBOS_QUEUE_HPP
#define NBOS_QUEUE_HPP

#include "math.hpp"
#include "type.hpp"

namespace nbos {

/// ## class Queue<class Type, int bufferSize\>
template <class Type, int bufferSize = -1>
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
    int _bufferSize;
    int _head = 0;
    int _tail = 0;
    bool _full = false;
    callback_t notify_func = nullptr;
    void* notify_data = nullptr;

public:

    /// #### Queue(Type\* buffer, int bufferSize)
    /// Construct a queue with the given buffer.
    Queue(Type* buffer, int bufferSize) : _buffer(buffer) {
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

    /// #### int size()
    /// Get the number of elements currently in the queue.
    int size() {
        if(full()) {
            return _bufferSize;
        }

        int s = _head - _tail;

        if(s < 0) {
            s += _bufferSize;
        }

        return s;
    }

    /// #### int free()
    /// Get the amount of free space in the queue.
    int free() {
        return _bufferSize - size();
    }

    /// ### int capacity()
    /// Get the total capacity of the queue.
    int capacity() {
        return _bufferSize;
    }

    /// #### bool empty()
    /// Returns true if the queue is empty.
    bool empty() {
        return (_head == _tail) && !full();
    }

    /// #### bool full()
    /// Returns true if the queue is full.
    bool full() {
        return _full || (_bufferSize == 0);
    }

    /// #### void notify(callback_t callback, void\* data)
    /// Set the callback function and data for queue notifications.

    /// #### void notify()
    /// Call the callback function previously given.
    void notify(callback_t callback = nullptr, void* data = nullptr) {
        if(callback == nullptr) {
            if(notify_func != nullptr) {
                notify_func(notify_data);
            }
        } else {
            notify_func = callback;
            notify_data = data;
        }
    }
};

} // nbos

#endif
