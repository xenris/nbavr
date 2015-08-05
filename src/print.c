#include "print.h"

#define PRINT_TIMEOUT_MS 5

bool printStr(const char* str) {
    for(uint8_t i = 0; (i < 255) && (str[i] != '\0'); i++) {
        if(!printChar(str[i])) {
            return false;
        }
    }

    return true;
}

bool printChar(char c) {
    if(c == '\n') {
        if(!printChar('\r')) {
            return false;
        }
    }

    if(!serialSendByte(c)) {
        const uint32_t timeout = millis() + PRINT_TIMEOUT_MS;

        while(true) {
            if(serialSendByte(c)) {
                break;
            } else if(millis() >= timeout) {
                return false;
            }
        }
    }

    return true;
}
