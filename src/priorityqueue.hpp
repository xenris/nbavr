#ifndef NBOS_PRIORITYQUEUE_HPP
#define NBOS_PRIORITYQUEUE_HPP

#include "algorithm.hpp"
#include "math.hpp"

template <class T, int S, class cmp_t = lesser<T>>
struct PriorityQueue {
    using size_t = typename conditional<S <= 126, int8_t, int16_t>::type;
    using type = T;

    static_assert(is_same<cmp_t, lesser<T>>::value || is_same<cmp_t, greater<T>>::value, "Must use one of lesser<T> or greater<T>");

private:

    T _array[S + 1];
    size_t _head = 1;

public:

    bool push(T t) {
        bool b;

        atomic {
            b = push_(t);
        }

        return b;
    }

    bool push_(const T& t) {
        if(full_()) {
            return false;
        }

        _array[_head] = t;

        size_t c = _head;
        size_t p = c / 2;
        cmp_t cmp;

        _head++;

        while(p != 0) {
            if(cmp(_array[c], _array[p])) {
                swap(_array[c], _array[p]);

                c = p;
                p = c / 2;
            } else {
                break;
            }
        }

        return true;
    }

    bool pop(T* t = nullptr) {
        bool b;

        atomic {
            b = pop_(t);
        }

        return b;
    }

    bool pop_(T* t = nullptr) {
        if(empty_()) {
            return false;
        }

        if(t != nullptr) {
            *t = _array[1];
        }

        _head--;

        _array[1] = _array[_head];

        size_t p = 1;
        cmp_t cmp;

        while((p * 2) <= _head) {
            size_t c1 = p * 2;
            size_t c2 = p * 2 + 1;

            size_t c = (c2 > _head) ? (c1) : (cmp(_array[c1], _array[c2]) ? c1 : c2);

            if(cmp(_array[c], _array[p])) {
                swap(_array[c], _array[p]);

                p = c;
            } else {
                break;
            }
        }

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

        *t = _array[1];

        return true;
    }

    void clear() {
        atomic {
            clear_();
        }
    }

    void clear_() {
        _head = 1;
    }

    size_t size() {
        size_t s;

        atomic {
            s = size_();
        }

        return s;
    }

    size_t size_() {
        return (_head - 1);
    }

    size_t free() {
        size_t s;

        atomic {
            s = free_();
        }

        return s;
    }

    size_t free_() {
        return S - (_head - 1);
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
        return (_head - 1) == 0;
    }

    bool full() {
        bool f;

        atomic {
            f = full_();
        }

        return f;
    }

    bool full_() {
        return (_head - 1) == S;
    }
};

#endif
