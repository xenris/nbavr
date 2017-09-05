#ifndef NBAVR_CALLBACKS_HPP
#define NBAVR_CALLBACKS_HPP

#ifndef TEST

#define ISR(vector, ...) \
    extern "C" void vector(void) __attribute__((signal,used,externally_visible)) __VA_ARGS__; \
    void vector(void)
#else

#define ISR(vector, ...) void vector(void)

#endif

#define MAKE_CALLBACK_HEADER(...) \
    extern void (*UNDERLINE(__VA_ARGS__, Callback))(void*); \
    extern void* UNDERLINE(__VA_ARGS__, CallbackData);

#define MAKE_CALLBACK(...) \
    void (*UNDERLINE(__VA_ARGS__, Callback))(void*); \
    void* UNDERLINE(__VA_ARGS__, CallbackData); \
    ISR(CONCAT(CHIP, UNDERLINE(__VA_ARGS__), INT_VECTOR)) { \
        if(UNDERLINE(__VA_ARGS__, Callback) != nullptr) { \
            UNDERLINE(__VA_ARGS__, Callback)(UNDERLINE(__VA_ARGS__, CallbackData)); \
        } \
    }

#define INCLUDE_DEFAULT_CALLBACK() ISR(__vector_default) {}

#endif
