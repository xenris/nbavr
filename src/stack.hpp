#ifndef NBOS_STACK_HPP
#define NBOS_STACK_HPP

template <class T, int S>
struct Stack {
    using size_t = typename conditional<S <= 127, int8_t, int16_t>::type;
    using type = T;

private:

    T _array[S];
    size_t _head = 0;

public:

    bool push(T t) {
        if(full()) {
            return false;
        }

        _array[_head] = t;

        _head += 1;

        return true;
    }

    bool pop(T* t) {
        if(empty()) {
            return false;
        }

        _head -= 1;

        *t = _array[_head];

        return true;
    }

    bool peek(T* t) {
        if(empty()) {
            return false;
        }

        *t = _array[_head - 1];

        return true;
    }

    void clear() {
        _head = 0;
    }

    size_t size() {
        return _head;
    }

    size_t free() {
        return S - _head;
    }

    size_t capacity() {
        return S;
    }

    bool empty() {
        return _head == 0;
    }

    bool full() {
        return _head == S;
    }
};

#endif
