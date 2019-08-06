#ifndef NBLIB_POINTER_HPP
#define NBLIB_POINTER_HPP

// TODO
// Non-null pointer

template <class T>
class Pointer {
    T* _value;

public:

    Pointer(T& value) : _value(&value) {
    }

    // TODO Work out what would happen here.

    // Pointer(T&& value) : _value(value) {
    // }

    // TODO Work out what would happen here.

    // Pointer(T&& value) : _value(new T(value)) {
    // }

    T& operator *() {
        return *_value;
    }

    const T& operator *() const {
        return *_value;
    }

    T* operator ->() {
        return _value;
    }

    const T* operator ->() const {
        return _value;
    }
};

#endif
