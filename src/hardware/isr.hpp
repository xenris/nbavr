#ifndef NBLIB_ISR_HPP
#define NBLIB_ISR_HPP

#if defined(__AVR__)
    #define ISR(vector, ...) \
        extern "C" void vector(void) __attribute__((signal,used,externally_visible)) __VA_ARGS__; \
        void vector(void)
#elif defined(__ARM__)
    #define ISR(vector, ...) \
        extern "C" void vector(void) __attribute__((used,externally_visible)) __VA_ARGS__; \
        void vector(void)
#elif defined(TEST)
    #define ISR(vector, ...) void vector(void)
#endif

#endif
