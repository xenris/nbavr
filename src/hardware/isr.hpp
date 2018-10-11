#ifndef NBOS_ISR_HPP
#define NBOS_ISR_HPP

#ifndef TEST
    #define ISR(vector, ...) \
        extern "C" void vector(void) __attribute__((signal,used,externally_visible)) __VA_ARGS__; \
        void vector(void)
#else
    #define ISR(vector, ...) void vector(void)
#endif

ISR(__vector_default) {}

#endif
