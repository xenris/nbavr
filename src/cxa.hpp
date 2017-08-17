#ifndef NBAVR_CXA_HPP
#define NBAVR_CXA_HPP

__extension__ typedef int __guard __attribute__((mode (__DI__)));

extern "C" force_inline int __cxa_guard_acquire(__guard *) __attribute__((used));
extern "C" force_inline void __cxa_guard_release (__guard *) __attribute__((used));
extern "C" force_inline void __cxa_guard_abort (__guard *) __attribute__((used));
extern "C" force_inline void __cxa_pure_virtual(void) __attribute__((used));

int __cxa_guard_acquire(__guard *g) {
    return !*reinterpret_cast<char*>(g);
}

void __cxa_guard_release(__guard *g) {
    *reinterpret_cast<char*>(g) = 1;
}

void __cxa_pure_virtual(void) {
}

void __cxa_guard_abort (__guard *) {
}

#endif
