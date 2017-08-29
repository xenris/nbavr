#ifndef NBAVR_QUEUE_HPP
#define NBAVR_QUEUE_HPP

template <typename T, int S>
struct Queue {
    using size_t = typename conditional<S <= 127, int8_t, int16_t>::type;
    using type = T;

private:

    T _array[S];
    size_t _head = 0;
    size_t _tail = 0;
    bool _full = false;

public:

    bool push(T t) {
        if(_full) {
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
        if(empty()) {
            return false;
        }

        *t = _array[_tail];

        _tail = (_tail + 1) % S;

        _full = false;

        return true;
    }

    bool peek(T* t) {
        if(empty()) {
            return false;
        }

        *t = _array[_tail];

        return true;
    }

    void clear() {
        _head = _tail;
        _full = false;
    }

    size_t size() {
        if(_full) {
            return S;
        }

        size_t s = _head - _tail;

        if(s < 0) {
            s += S;
        }

        return s;
    }

    size_t free() {
        return S - size();
    }

    size_t capacity() {
        return S;
    }

    bool empty() {
        return (_head == _tail) && !_full;
    }

    bool full() {
        return _full;
    }
};

#endif
