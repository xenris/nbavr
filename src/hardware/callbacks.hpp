#ifndef NBAVR_CALLBACKS_HPP
#define NBAVR_CALLBACKS_HPP

using callback_t = void (*)(void*);

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

#define INCLUDE_DEFAULT_CALLBACK() ISR(VECT(default)) {}

// TODO WDT
// TODO spi,stc
// TODO ee
// TODO analog comp
// TODO twi
// TODO spm mem

#endif
