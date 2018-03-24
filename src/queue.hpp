#ifndef NBOS_QUEUE_HPP
#define NBOS_QUEUE_HPP

#include "math.hpp"
#include "type.hpp"

/// # Queue

/// Queues are first in first out containers.

/// All functions are atomic (i.e. interrupt safe). Equivalient non-atomic functions
/// have \_ after the function name, e.g. queue.push\_(t).

namespace nbos {

/// ## class Queue\<class Type, int Size\>
template <class T, int S>
struct Queue {
    /// #### size_t
    /// The smallest signed integer type which can represent the queue's size.
    using size_t = typename conditional<S <= 127, int8_t, int16_t>::type;
    /// #### type
    /// The type of the Queue.
    using type = T;

private:

    T _array[S];
    size_t _head = 0;
    size_t _tail = 0;
    bool _full = false;
    callback_t notify_func = nullptr;
    void* notify_data = nullptr;

public:

    /// #### bool push(T t)
    /// Add a value to the queue.<br>
    /// Returns true on success.
    bool push(const T& t) {
        return atomic([&]() {
            return push_(t);
        });
    }

    bool push_(const T& t) {
        if(full_()) {
            return false;
        }

        _array[_head] = t;

        _head = (_head + 1) % S;

        if(_head == _tail) {
            _full = true;
        }

        return true;
    }

    /// #### bool pop(T\* t)
    /// Get the next value from the queue.<br>
    /// Returns true on success.
    bool pop(T*const t = nullptr) {
        return atomic([&]() {
            return pop_(t);
        });
    }

    bool pop_(T*const t = nullptr) {
        if(empty_()) {
            return false;
        }

        if(t != nullptr) {
            *t = _array[_tail];
        }

        _tail = (_tail + 1) % S;

        _full = false;

        return true;
    }

    /// #### bool peek(T\* t)
    /// Get the next value from the queue, but don't remove it.<br>
    /// Returns true on success.
    bool peek(T*const t) {
        return atomic([&]() {
            return peek_(t);
        });
    }

    bool peek_(T* t) {
        if(empty_()) {
            return false;
        }

        *t = _array[_tail];

        return true;
    }

    /// #### void clear()
    /// Remove all elements from the queue.
    void clear() {
        atomic([&]() {
            clear_();
        });
    }

    void clear_() {
        _head = _tail;
        _full = false;
    }

    /// #### size_t size()
    /// Get the number of elements currently in the queue.
    size_t size() {
        return atomic([&]() {
            return size_();
        });
    }

    size_t size_() {
        if(full_()) {
            return S;
        }

        size_t s = _head - _tail;

        if(s < 0) {
            s += S;
        }

        return s;
    }

    /// #### size_t free()
    /// Get the amount of free space in the queue.
    size_t free() {
        return atomic([&]() {
            return free_();
        });
    }

    size_t free_() {
        return S - size_();
    }

    /// ### static constexpr size_t capacity()
    /// Get the total capacity of the queue.
    static constexpr size_t capacity() {
        return S;
    }

    /// #### bool empty()
    /// Returns true if the queue is empty.
    bool empty() {
        return atomic([&]() {
            return empty_();
        });
    }

    bool empty_() {
        return (_head == _tail) && !full_();
    }

    /// #### bool full()
    /// Returns true if the queue is full.
    bool full() {
        return full_();
    }

    bool full_() {
        return _full || (S == 0);
    }

    /// #### void setNotify(callback_t callback, void\* data)
    /// Set the callback function and data for queue notifications.
    void setNotify(callback_t callback, void* data) {
        atomic([&]() {
            notify_func = callback;
            notify_data = data;
        });
    }

    /// #### void notify()
    /// Call the notification callback.
    void notify() {
        if(notify_func != nullptr) {
            notify_func(notify_data);
        }
    }
};

} // nbos

#endif
