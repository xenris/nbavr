#include "print.h"

static const char* digits = "0123456789ABCDEF";

bool printchar(Stream* stream, char c) {
    return streamPush(stream, c);
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

#define INT_SIZE 8
#include "printin.t"
#undef INT_SIZE

#define INT_SIZE 16
#include "printin.t"
#undef INT_SIZE

#define INT_SIZE 32
#include "printin.t"
#undef INT_SIZE

#define INT_SIZE 64
#include "printin.t"
#undef INT_SIZE
