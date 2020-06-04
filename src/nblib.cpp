#include <nblib.hpp>

ISR(__vector_default) {}

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
