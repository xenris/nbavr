#ifndef NBLIB_HEAP_HPP
#define NBLIB_HEAP_HPP

#include <primitive.hpp>
#include <macros.hpp>
#include <math.hpp>

namespace nblib {

// Allows dynamic object allocation.
// Create with Type* t = heap.create<Type>(...)
// Delete with heap.destroy(&t)

class Heap {
    class Control {
        ssize_t _leftSize; // Size, in bytes, of previous data. 0 if this is an end. Negative if in use.
        ssize_t _rightSize; // Size, in bytes, of next data. 0 if this is an end. Negative if in use.

    public:

        void init(Control* left, Control* right) {
            _leftSize = left ? (ssize_t(this) - ssize_t(left) - ssizeof(Control)) : 0;
            _rightSize = right ? (ssize_t(right) - ssize_t(this) - ssizeof(Control)) : 0;
        }

        void split(ssize_t newSize) {
            if(newSize > 0) {
                const ssize_t currentSize = size();
                const ssize_t newSizeRight = currentSize - newSize - ssizeof(Control);

                if(newSizeRight >= 1) {
                    Control*const newControl = (Control*)(ssize_t(this) + ssizeof(Control) + newSize);

                    newControl->_leftSize = newSize;
                    newControl->_rightSize = newSizeRight;

                    next()->_leftSize = newSizeRight;

                    _rightSize = newSize;
                }
            }
        }

        void join() {
            if((_leftSize > 0) && (_rightSize > 0)) {
                ssize_t newSize = _leftSize + _rightSize + ssizeof(Control);

                previous()->_rightSize = newSize;
                next()->_leftSize = newSize;

                next()->join();
            }
        }

        bool available() const {
            return _rightSize > 0;
        }

        void available(bool b) {
            if(_rightSize) {
                if(b) {
                    _rightSize = abs(_rightSize);
                } else {
                    _rightSize = -abs(_rightSize);
                }

                next()->_leftSize = _rightSize;
            }
        }

        ssize_t size() const {
            return _rightSize;
        }

        Control* previous() const {
            return _leftSize ? (Control*)(ssize_t(this) - abs(_leftSize) - ssizeof(Control)) : nullptr;
        }

        Control* next() const {
            return _rightSize ? (Control*)(ssize_t(this) + ssizeof(Control) + abs(_rightSize)) : nullptr;
        }

        void* data() {
            return this + 1;
        }

        const void* data() const {
            return this + 1;
        }
    };

    uint8_t* _buffer;
    ssize_t _numBytes;
    // Control* _first; // TODO Speed up allocation by storing a pointer to the first free space.

public:

    Heap(uint8_t* buffer, ssize_t numBytes) {
        _buffer = buffer;
        _numBytes = numBytes;

        Control*const c1 = (Control*)&_buffer[0];
        Control*const c2 = (Control*)&_buffer[numBytes - ssizeof(Control)];

        c1->init(nullptr, c2);
        c2->init(c1, nullptr);
    }

    void* malloc(ssize_t s) {
        if(s <= 0) {
            return nullptr;
        }

        Control* c = (Control*)_buffer;

        while(c) {
            if(c->size() >= s) {
                c->split(s);

                c->available(false);

                return c->data();
            } else {
                c = c->next();
            }
        }

        return nullptr;
    }

    void free(void* p) {
        if(p == nullptr) {
            return;
        }

        Control*const c = (Control*)p - 1;

        c->available(true);

        c->join();
    }
};

template <size_t bufferSize>
class HeapBuffer : public Heap {
    uint8_t _buffer[bufferSize];

public:

    HeapBuffer() : Heap(_buffer, bufferSize) {
    }
};

}

#ifndef TEST

extern nblib::Heap* _globalHeap;

void* operator new (size_t s) {
    // TODO check s.
    return _globalHeap->malloc(ssize_t(s));
}

void* operator new (size_t s, void* p) noexcept {
    return p;
}

void operator delete (void* p) noexcept {
    return _globalHeap->free(p);
}

void operator delete (void* p, size_t s) noexcept {
    return _globalHeap->free(p);
}

void* operator new [] (size_t s) {
    // TODO check s.
    return _globalHeap->malloc(ssize_t(s));
}

void* operator new [] (size_t s, void* p) noexcept {
    return p;
}

void operator delete [] (void* p) noexcept {
    return _globalHeap->free(p);
}

void operator delete [] (void* p, size_t s) noexcept {
    return _globalHeap->free(p);
}

#endif

#ifdef TEST

namespace nblib {

TEST(Container, Heap) {
    srand(0);

    uint8_t buffer[102];

    buffer[0] = 69;
    buffer[101] = 69;

    Heap heap(&buffer[1], 100);

    {
        uint8_t* p1 = (uint8_t*)heap.malloc(10);
        uint8_t* p2 = (uint8_t*)heap.malloc(25);
        EXPECT_TRUE(p1 != nullptr);
        EXPECT_TRUE(p2 != nullptr);

        heap.free(p1);
        heap.free(p2);
    }

    uint8_t* ps[100];
    int ls[100];

    for(int i = 0; i < 500; i++) {
        const int n = rand() % 100;

        for(int j = 0; j < n; j++) {
            const int l = rand() % 100;

            ps[j] = (uint8_t*)heap.malloc(l);
            ls[j] = l;

            if(ps[j] != nullptr) {
                for(int k = 0; k < l; k++) {
                    ps[j][k] = k + 10;
                }
            }
        }

        for(int j = 0; j < n; j++) {
            if(ps[j] != nullptr) {
                for(int k = 0; k < ls[j]; k++) {
                    EXPECT_EQ(ps[j][k], k + 10);
                }
            }
        }

        for(int j = 0; j < n; j++) {
            heap.free(ps[j]);

            ps[j] = nullptr;
        }
    }

    EXPECT_EQ(buffer[0], 69);
    EXPECT_EQ(buffer[101], 69);
}

}

#endif // TEST

#endif
