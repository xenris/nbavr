#ifndef PRINT_H
#define PRINT_H

#include <stdbool.h>
#include <stddef.h>
#include "stream.h"

// High nibble indicates whether it is signed.
// Low nibble indicates the base.
typedef enum __attribute__((packed)) {
    PrintUBin = 0x00,
    PrintUOct = 0x01,
    PrintUDec = 0x02,
    PrintUHex = 0x04,
    PrintSBin = 0x10,
    PrintSOct = 0x11,
    PrintSDec = 0x12,
    PrintSHex = 0x14,
} PrintFormat;

// These macros create a print function which takes a stream and up to 10 values
//  to be printed.
#define print(S, ...) GET_PRINT_N(__VA_ARGS__, \
    printA,print9,print8,print7,print6,print5,print4,print3,print2,print1\
    )(S, __VA_ARGS__)

#define GET_PRINT_N(_1,_2,_3,_4,_5,_6,_7,_8,_9,_A,NAME,...) NAME

#define print1(S, X) _Generic((X), \
    char: printchar(S, (char)X), \
    char*: printstr(S, (char*)X), \
    int8_t: printi8(S, (int8_t)X, PrintSDec), \
    int16_t: printi16(S, (int16_t)X, PrintSDec), \
    int32_t: printi32(S, (int32_t)X, PrintSDec), \
    int64_t: printi64(S, (int64_t)X, PrintSDec), \
    uint8_t: printi8(S, (uint8_t)X, PrintUDec), \
    uint16_t: printi16(S, (uint16_t)X, PrintUDec), \
    uint32_t: printi32(S, (uint32_t)X, PrintUDec), \
    uint64_t: printi64(S, (uint64_t)X, PrintUDec), \
    default: printchar(S, (char)X) \
    )

#define print2(S, A, B) print1(S, A); print1(S, B)
#define print3(S, A, B, C) print1(S, A); print2(S, B, C)
#define print4(S, A, B, C, D) print1(S, A); print3(S, B, C, D)
#define print5(S, A, B, C, D, E) print1(S, A); print4(S, B, C, D, E)
#define print6(S, A, B, C, D, E, F) print1(S, A); print5(S, B, C, D, E, F)
#define print7(S, A, B, C, D, E, F, G) print1(S, A); print6(S, B, C, D, E, F, G)
#define print8(S, A, B, C, D, E, F, G, H) print1(S, A); print7(S, B, C, D, E, F, G, H)
#define print9(S, A, B, C, D, E, F, G, H, I) print1(S, A); print8(S, B, C, D, E, F, G, H, I)
#define printA(S, A, B, C, D, E, F, G, H, I, J) print1(S, A); print9(S, B, C, D, E, F, G, H, I, J)

// Generic integer printing function.
// Integer printing is divided into multiple functions for time and memory efficiency.
#define printint(S, X, F) _Generic((X), \
    int8_t: printi8, \
    int16_t: printi16, \
    int32_t: printi32, \
    int64_t: printi64, \
    uint8_t: printi8, \
    uint16_t: printi16, \
    uint32_t: printi32, \
    uint64_t: printi64, \
    default: printi8 \
    )(S, X, F)

bool printchar(Stream* stream, char c) __attribute__((always_inline));
bool printstr(Stream* stream, const char* str);
bool printi8(Stream* stream, uint8_t n, PrintFormat format);
bool printi16(Stream* stream, uint16_t n, PrintFormat format);
bool printi32(Stream* stream, uint32_t n, PrintFormat format);
bool printi64(Stream* stream, uint64_t n, PrintFormat format);

#endif
