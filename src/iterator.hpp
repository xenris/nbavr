#ifndef NBOS_ITERATOR_HPP
#define NBOS_ITERATOR_HPP

template<class T>
auto begin(T& t) -> decltype(t.begin()) {
    return t.begin();
}

template<class T>
auto end(T& t) -> decltype(t.end()) {
    return t.end();
}

template<class T>
auto begin(T* t) -> decltype(t->begin()) {
    return t->begin();
}

template<class T>
auto end(T* t) -> decltype(t->end()) {
    return t->end();
}

#endif
