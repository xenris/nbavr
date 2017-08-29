#ifndef NBAVR_ARRAY_HPP
#define NBAVR_ARRAY_HPP

template <typename T, int S>
struct Array {
    using size_t = typename conditional<S <= 127, int8_t, int16_t>::type;
    using type = T;

private:

    T _array[S];

public:

    T& operator[](size_t i) {
        i = clip(i, 0, S - 1);

        return _array[i];
    }

    void fill(T t) {
        for(T& n : this) {
            n = t;
        }
    }

    size_t size() {
        return S;
    }

    T* begin() {
        return &_array[0];
    }

    T* end() {
        return &_array[S];
    }
};

#endif
