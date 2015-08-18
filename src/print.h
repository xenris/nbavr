#ifndef PRINT_H
#define PRINT_H

#include <stdbool.h>
#include <stdarg.h>
#include "stream.h"

bool print(OutputStream* outputStream, const char* format, ...);
bool printstr(OutputStream* outputStream, const char* str);
bool printchar(OutputStream* outputStream, char c);
bool printint(OutputStream* outputStream, bool sign, uint16_t u, uint8_t base);

#endif
