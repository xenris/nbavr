#ifndef PRINT_H
#define PRINT_H

#include <stdbool.h>
#include "serial.h"
#include "millis.h"

bool printStr(const char* str);
bool printChar(char c);

#endif
