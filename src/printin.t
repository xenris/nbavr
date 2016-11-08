#define CONCAT_(A,B,C) A ## B ## C
#define CONCAT(A,B,C) CONCAT_(A,B,C)

#define printiN CONCAT(printi, INT_SIZE, )
#define TS CONCAT(int, INT_SIZE, _t)
#define TU CONCAT(uint, INT_SIZE, _t)

bool printiN(Stream* stream, TU n, PrintFormat format) {
    if(stream == NULL) {
        return false;
    }

    TS* s = (TS*)&n;
    char stack[INT_SIZE + 1];
    int8_t i = 0;
    bool negative = (format & 0x10) && (*s < 0);
    int8_t base = format & 0x0F;

    if(negative) {
        *s *= -1;
    } else if(n == 0) {
        stack[i++] = '0';
    }

    while(n != 0) {
        int8_t d;

        switch(base) {
            case 0x00:
                d = n % 2;
                n /= 2;
                break;
            case 0x01:
                d = n % 8;
                n /= 8;
                break;
            case 0x02:
                d = n % 10;
                n /= 10;
                break;
            default:
                d = n % 16;
                n /= 16;
                break;
        }


        stack[i++] = digits[d];
    }

    if(negative) {
        stack[i++] = '-';
    }

    i--;

    for(; i >= 0; i--) {
        if(!printchar(stream, stack[i])) {
            return false;
        }
    }

    return true;
}

#undef printiN
#undef TS
#undef TU
