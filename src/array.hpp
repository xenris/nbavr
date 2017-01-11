#ifndef NBAVR_ARRAY_HPP
#define NBAVR_ARRAY_HPP

template <class T>
class Array {
    T* const _datap;
    const uint8_t _size;

public:
    Array(T* datap, uint8_t size) : _datap(datap), _size(size) {
    }

    constexpr force_inline uint8_t size() const {
        return _size;
    }

    force_inline T& operator[](int16_t i) {
        if(i >= _size) {
            i = _size - 1;
        } else if(i < 0) {
            i = max(i + _size, 0);
        }

        return _datap[i];
    }

    force_inline T& operator[](uint8_t i) {
        if(i >= _size) {
            i = _size - 1;
        }

        return _datap[i];
    }

    force_inline T* begin() const {
        return _datap;
    }

    force_inline T* end() const {
        return &_datap[_size];
    }
};

template <class T, uint8_t S>
class ArrayBuffer : public Array<T> {
    T _data[S];

    public:

    ArrayBuffer() : Array<T>(_data, S) {
    }
};

#endif
