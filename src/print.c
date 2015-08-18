#include "print.h"

static const char* digits = "0123456789ABCDEF";

bool print(OutputStream* outputStream, const char* format, ...) {
    va_list arglist;
    va_start(arglist, format);
    bool special = false;

    for(char* p = (char*)format; *p != '\0'; p++) {
        char c = *p;
        bool success = true;

        if(!special && (c == '%')) {
            special = true;
        } else {
            if(special) {
                switch(c) {
                case 'i':
                    success = printint(outputStream, true, va_arg(arglist, int16_t), 10);
                    break;
                case 'u':
                    success = printint(outputStream, false, va_arg(arglist, uint16_t), 10);
                    break;
                case 'x':
                    success = printint(outputStream, false, va_arg(arglist, uint16_t), 16);
                    break;
                case 'o':
                    success = printint(outputStream, false, va_arg(arglist, uint16_t), 8);
                    break;
                case 'b':
                    success = printint(outputStream, false, va_arg(arglist, uint16_t), 2);
                    break;
                case 's':
                    success = printstr(outputStream, va_arg(arglist, char*));
                    break;
                case 'c':
                    success = printchar(outputStream, va_arg(arglist, int));
                    break;
                case '%':
                    success = printchar(outputStream, c);
                    break;
                default:
                    success = printchar(outputStream, c);
                    break;
                }
            } else {
                success = printchar(outputStream, c);
            }

            special = false;
        }

        if(!success) {
            return false;
        }
    }

    return true;
}

bool printstr(OutputStream* outputStream, const char* str) {
    for(char* p = (char*)str; *p != '\0'; p++) {
        if(!printchar(outputStream, *p)) {
            return false;
        }
    }

    return true;
}

bool printchar(OutputStream* outputStream, char c) {
    return outputStreamPush(outputStream, c);
}

bool printint(OutputStream* outputStream, bool sign, uint16_t u, uint8_t base) {
    int16_t* s = (int16_t*)&u;
    char stack[16];
    int8_t i = 0;
    bool negative = sign && (*s < 0);

    if(negative) {
        *s *= -1;
    } else if(u == 0) {
        stack[i++] = '0';
    }

    while(u > 0) {
        int8_t d = u % base;
        u /= base;

        stack[i++] = digits[d];
    }

    if(negative) {
        stack[i++] = '-';
    }

    i--;

    while(i >= 0) {
        if(!printchar(outputStream, stack[i])) {
            return false;
        }

        i--;
    }

    return true;
}
