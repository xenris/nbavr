#ifndef NBAVR_PRIORITYQUEUE_HPP
#define NBAVR_PRIORITYQUEUE_HPP

template <typename T, int S, typename cmp_t = lesser<T>>
struct PriorityQueue {
    using size_t = typename conditional<S <= 126, int8_t, int16_t>::type;
    using type = T;

    static_assert(is_same<cmp_t, lesser<T>>::value || is_same<cmp_t, greater<T>>::value, "Must use one of lesser<T> or greater<T>");

private:

    T _array[S + 1];
    size_t _head = 1;

public:

    bool push(const T& t) {
        if(full()) {
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

    bool pop(T* t) {
        if(empty()) {
            return false;
        }

        *t = _array[1];

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
        if(empty()) {
            return false;
        }

        *t = _array[1];

        return true;
    }

    void clear() {
        _head = 1;
    }

    size_t size() {
        return (_head - 1);
    }

    size_t free() {
        return S - (_head - 1);
    }

    size_t capacity() {
        return S;
    }

    bool empty() {
        return (_head - 1) == 0;
    }

    bool full() {
        return (_head - 1) == S;
    }
};

#endif
