#ifndef NBAVR_QUEUE_HPP
#define NBAVR_QUEUE_HPP

#include "math.hpp"
#include "type.hpp"

template <class T, int S>
struct Queue {
    using size_t = typename conditional<S <= 127, int8_t, int16_t>::type;
    using type = T;

private:

    T _array[S];
    size_t _head = 0;
    size_t _tail = 0;
    bool _full = false;
    callback_t notify_func = nullptr;
    void* notify_data = nullptr;

public:

    bool push(T t) {
        bool b;

        atomic {
            b = push_(t);
        }

        return b;
    }

    bool push_(T t) {
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

    bool pop(T* t) {
        bool b;

        atomic {
            b = pop_(t);
        }

        return b;
    }

    bool pop_(T* t) {
        if(empty_()) {
            return false;
        }

        *t = _array[_tail];

        _tail = (_tail + 1) % S;

        _full = false;

        return true;
    }

    bool peek(T* t) {
        bool b;

        atomic {
            b = peek_(t);
        }

        return b;
    }

    bool peek_(T* t) {
        if(empty_()) {
            return false;
        }

        *t = _array[_tail];

        return true;
    }

    void clear() {
        atomic {
            clear_();
        }
    }

    void clear_() {
        _head = _tail;
        _full = false;
    }

    size_t size() {
        size_t s;

        atomic {
            s = size_();
        }

        return s;
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

    size_t free() {
        size_t s;

        atomic {
            s = free_();
        }

        return s;
    }

    size_t free_() {
        return S - size_();
    }

    static constexpr size_t capacity() {
        return S;
    }

    static constexpr size_t capacity_() {
        return S;
    }

    bool empty() {
        bool e;

        atomic {
            e = empty_();
        }

        return e;
    }

    bool empty_() {
        return (_head == _tail) && !full_();
    }

    bool full() {
        return full_();
    }

    bool full_() {
        return _full || (S == 0);
    }

    void setNotify(callback_t f, void* d) {
        atomic {
            notify_func = f;
            notify_data = d;
        }
    }

    void notify() {
        if(notify_func != nullptr) {
            notify_func(notify_data);
        }
    }
};

#endif
