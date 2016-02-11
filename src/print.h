#ifndef PRINT_H
#define PRINT_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdarg.h>
#include "stream.h"

bool print(Stream* stream, const char* format, ...);
bool printstr(Stream* stream, const char* str);
bool printchar(Stream* stream, char c);
bool printvalue(Stream* stream, int c);
bool printint(Stream* stream, bool sign, uint16_t u, uint8_t base);

#endif
