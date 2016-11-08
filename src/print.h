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

bool printchar(Stream* stream, char c) __attribute__((always_inline));
bool printstr(Stream* stream, const char* str);
bool printi8(Stream* stream, uint8_t n, PrintFormat format);
bool printi16(Stream* stream, uint16_t n, PrintFormat format);
bool printi32(Stream* stream, uint32_t n, PrintFormat format);
bool printi64(Stream* stream, uint64_t n, PrintFormat format);

#endif
