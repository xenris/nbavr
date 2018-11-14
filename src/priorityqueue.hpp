/// [[Index]]

/// # {{Priority Queue}}

/// ```c++
/// nbos::PriorityQueue<Int32, 6> priorityQueue;
///
/// priorityQueue.push(6);
/// priorityQueue.push(8);
/// priorityQueue.push(4);
/// priorityQueue.push(5);
/// priorityQueue.push(1);
/// priorityQueue.push(2);
///
/// nbos::PriorityQueue<Int32>* pointer = &priorityQueue;
///
/// Int32 n;
///
/// while(pointer->pop(&n)) {
///     // 1, 2, 4, 5, 6, 8
/// }
/// ```

#ifndef NBOS_PRIORITYQUEUE_HPP
#define NBOS_PRIORITYQUEUE_HPP

#include "optional.hpp"

namespace nbos {

/// ## class PriorityQueue<class Type, Int size\>
template <class Type, Int size = -1>
class PriorityQueue : public PriorityQueue<Type> {
    Type _buffer[size];

public:

    /// #### PriorityQueue()
    /// Construct a priority queue with space on the stack for the contents.
    explicit PriorityQueue() : PriorityQueue<Type>(_buffer, size) {
    }
};

/// ## class PriorityQueue<class Type\>
template <class T>
struct PriorityQueue<T, -1> {
    using Type = T;

private:

    T*const _buffer;
    const Int _size;
    Int _head;
    Bool (*_compare)(const T& a, const T& b);

public:

    /// #### PriorityQueue(T\* buffer, Int size)
    /// Construct a priority queue with the given buffer.
    PriorityQueue(T* buffer, Int size) : _buffer(buffer - 1), _size(size) {
        _head = 1;
        _compare = defaultCompare;
    }

    /// #### Bool push(T t)
    /// Returns true on success.
    Bool push(const T& t) {
        if(full()) {
            return false;
        }

        _buffer[_head] = t;

        Int c = _head;
        Int p = c / 2;

        _head++;

        while(p != 0) {
            if(_compare(_buffer[c], _buffer[p])) {
                swap(&_buffer[c], &_buffer[p]);

                c = p;
                p = c / 2;
            } else {
                break;
            }
        }

        return true;
    }

    /// #### [[Optional]]<Type> pop()
    Optional<Type> pop() {
        if(empty()) {
            return {};
        }

        const Optional<Type> result = _buffer[1];

        _head--;

        _buffer[1] = _buffer[_head];

        Int p = 1;

        while((p * 2) <= _head) {
            Int c1 = p * 2;
            Int c2 = p * 2 + 1;

            Int c = (c2 > _head) ? (c1) : (_compare(_buffer[c1], _buffer[c2]) ? c1 : c2);

            if(_compare(_buffer[c], _buffer[p])) {
                swap(&_buffer[c], &_buffer[p]);

                p = c;
            } else {
                break;
            }
        }

        return result;
    }

    /// #### [[Optional]]<Type\> peek()
    Optional<Type> peek() const {
        if(empty()) {
            return {};
        }

        return _buffer[1];
    }

    /// #### void clear()
    /// Remove all elements from the priority queue.
    void clear() {
        _head = 1;
    }

    /// #### Int size()
    /// Get the number of elements currently in the priority queue.
    Int size() const {
        return (_head - 1);
    }

    /// #### Int free()
    /// Get the amount of free space in the priority queue.
    Int free() const {
        return _size - (_head - 1);
    }

    /// #### Int capacity()
    /// Get the total capacity of the priority queue.
    Int capacity() const {
        return _size;
    }

    /// #### Bool empty()
    /// Returns true if the priority queue is empty.
    Bool empty() const {
        return (_head - 1) == 0;
    }

    /// #### Bool full()
    /// Returns true if the priority queue is full.
    Bool full() const {
        return (_head - 1) == _size;
    }

    /// #### void compare(Bool (*f)(const T& a, const T& b))
    /// Set the function used to compare elements.
    void compare(Bool (*f)(const T& a, const T& b)) {
        _compare = f;
    }

    /// #### Bool compare(T a, T b)
    /// Returns true if a comes before b.
    Bool compare(const T& a, const T& b) const {
        return _compare(a, b);
    }

private:

    static Bool defaultCompare(const T& a, const T& b) {
        return a < b;
    }
};

} // nbos

#endif
