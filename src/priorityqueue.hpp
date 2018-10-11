/// [[Index]]

/// # {{Priority Queue}}

/// ```c++
/// nbos::PriorityQueue<int, 6> priorityQueue;
///
/// priorityQueue.push(6);
/// priorityQueue.push(8);
/// priorityQueue.push(4);
/// priorityQueue.push(5);
/// priorityQueue.push(1);
/// priorityQueue.push(2);
///
/// nbos::PriorityQueue<int>* pointer = &priorityQueue;
///
/// int n;
///
/// while(pointer->pop(&n)) {
///     // 1, 2, 4, 5, 6, 8
/// }
/// ```

#ifndef NBOS_PRIORITYQUEUE_HPP
#define NBOS_PRIORITYQUEUE_HPP

#include "algorithm.hpp"
#include "math.hpp"

namespace nbos {

/// ## class PriorityQueue<class Type, int size\>
template <class Type, int size = -1>
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
    const int _size;
    int _head;
    bool (*_compare)(const T& a, const T& b);

public:

    /// #### PriorityQueue(T\* buffer, int size)
    /// Construct a priority queue with the given buffer.
    PriorityQueue(T* buffer, int size) : _buffer(buffer - 1), _size(size) {
        _head = 1;
        _compare = defaultCompare;
    }

    /// #### bool push(T t)
    /// Returns true on success.
    bool push(const T& t) {
        if(full()) {
            return false;
        }

        _buffer[_head] = t;

        int c = _head;
        int p = c / 2;

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

    /// #### bool pop(T\* t)
    /// Returns true on success.
    bool pop(T*const t = nullptr) {
        if(empty()) {
            return false;
        }

        if(t != nullptr) {
            *t = _buffer[1];
        }

        _head--;

        _buffer[1] = _buffer[_head];

        int p = 1;

        while((p * 2) <= _head) {
            int c1 = p * 2;
            int c2 = p * 2 + 1;

            int c = (c2 > _head) ? (c1) : (_compare(_buffer[c1], _buffer[c2]) ? c1 : c2);

            if(_compare(_buffer[c], _buffer[p])) {
                swap(&_buffer[c], &_buffer[p]);

                p = c;
            } else {
                break;
            }
        }

        return true;
    }

    /// #### bool peek(T\* t)
    /// Returns true on success.
    bool peek(T* t) const {
        if(empty()) {
            return false;
        }

        *t = _buffer[1];

        return true;
    }

    /// #### void clear()
    /// Remove all elements from the priority queue.
    void clear() {
        _head = 1;
    }

    /// #### int size()
    /// Get the number of elements currently in the priority queue.
    int size() const {
        return (_head - 1);
    }

    /// #### int free()
    /// Get the amount of free space in the priority queue.
    int free() const {
        return _size - (_head - 1);
    }

    /// #### int capacity()
    /// Get the total capacity of the priority queue.
    int capacity() const {
        return _size;
    }

    /// #### bool empty()
    /// Returns true if the priority queue is empty.
    bool empty() const {
        return (_head - 1) == 0;
    }

    /// #### bool full()
    /// Returns true if the priority queue is full.
    bool full() const {
        return (_head - 1) == _size;
    }

    /// #### void compare(bool (*f)(const T& a, const T& b))
    /// Set the function used to compare elements.
    void compare(bool (*f)(const T& a, const T& b)) {
        _compare = f;
    }

    /// #### bool compare(T a, T b)
    /// Returns true if a comes before b.
    bool compare(const T& a, const T& b) const {
        return _compare(a, b);
    }

private:

    static bool defaultCompare(const T& a, const T& b) {
        return a < b;
    }
};

} // nbos

#endif
