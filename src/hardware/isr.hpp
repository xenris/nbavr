#ifndef NBLIB_ISR_HPP
#define NBLIB_ISR_HPP

#ifndef TEST
    #define ISR(vector, ...) \
        extern "C" void vector(void) __attribute__((signal,used,externally_visible)) __VA_ARGS__; \
        void vector(void)
#else
    #define ISR(vector, ...) void vector(void)
#endif

#endif
