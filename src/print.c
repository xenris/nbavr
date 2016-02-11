#include "print.h"

static const char* digits = "0123456789ABCDEF";

bool print(Stream* stream, const char* format, ...) {
    if(stream == NULL) {
        return false;
    }

    va_list arglist;
    va_start(arglist, format);
    bool special = false;
    bool result = true;

    for(char* p = (char*)format; *p != '\0'; p++) {
        char c = *p;
        bool success = true;

        if(!special && (c == '%')) {
            special = true;
        } else {
            if(special) {
                switch(c) {
                case 'i':
                    success = printint(stream, true, va_arg(arglist, int16_t), 10);
                    break;
                case 'u':
                    success = printint(stream, false, va_arg(arglist, uint16_t), 10);
                    break;
                case 'x':
                    success = printint(stream, false, va_arg(arglist, uint16_t), 16);
                    break;
                case 'o':
                    success = printint(stream, false, va_arg(arglist, uint16_t), 8);
                    break;
                case 'b':
                    success = printint(stream, false, va_arg(arglist, uint16_t), 2);
                    break;
                case 's':
                    success = printstr(stream, va_arg(arglist, char*));
                    break;
                case 'c':
                    success = printchar(stream, va_arg(arglist, int));
                    break;
                case 'v':
                    success = printvalue(stream, va_arg(arglist, int));
                    break;
                case 'n':
                    // TODO
                    break;
                case '%':
                    success = printchar(stream, c);
                    break;
                default:
                    success = printchar(stream, c);
                    break;
                }
            } else {
                success = printchar(stream, c);
            }

            special = false;
        }

        if(!success) {
            result = false;
            break;
        }
    }

    va_end(arglist);

    return result;
}

bool printstr(Stream* stream, const char* str) {
    if(stream == NULL) {
        return false;
    }

    for(char* p = (char*)str; *p != '\0'; p++) {
        if(!printchar(stream, *p)) {
            return false;
        }
    }

    return true;
}

bool printchar(Stream* stream, char c) {
    return streamPush(stream, c);
}

bool printvalue(Stream* stream, int c) {
    return streamPush(stream, c);
}

bool printint(Stream* stream, bool sign, uint16_t u, uint8_t base) {
    if(stream == NULL) {
        return false;
    }

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
        if(!printchar(stream, stack[i])) {
            return false;
        }

        i--;
    }

    return true;
}
