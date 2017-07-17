#ifndef NBAVR_PRINT_HPP
#define NBAVR_PRINT_HPP

enum class PrintFormat : uint8_t {
    Bin = 0x00,
    Oct = 0x01,
    Dec = 0x02,
    Hex = 0x04,
};

constexpr char endl = '\n';

inline bool printchar(Stream<char>& stream, const char c) {
    bool result = stream.push(c);

    if(c == '\n') {
        stream.flush();
    }

    return result;
}

inline bool printstr(Stream<char>& stream, const char* str) {
    for(const char* p = str; *p != '\0'; p++) {
        if(!printchar(stream, *p)) {
            return false;
        }
    }

    return true;
}

template <class T>
inline bool printint(Stream<char>& stream, T n, PrintFormat format = PrintFormat::Dec) {
    char stack[type_info<T>::num_digits + 1];
    int8_t i = 0;
    bool negative = n < 0;
    int8_t base = uint8_t(format) & 0x0F;

    if(n == 0) {
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

        d = abs(d);

        if(d < 10) {
            stack[i++] = '0' + d;
        } else {
            stack[i++] = 'A' + d - 10;
        }
    }

    if(negative) {
        stack[i++] = '-';
    }

    i--;

    for(; i >= 0; i--) {
        if(!stream.push(stack[i])) {
            return false;
        }
    }

    return true;
}

inline Stream<char>& operator<<(Stream<char>& stream, const char c) {
    printchar(stream, c);
    return stream;
}

inline Stream<char>& operator<<(Stream<char>& stream, const char* str) {
    printstr(stream, str);
    return stream;
}

inline Stream<char>& operator<<(Stream<char>& stream, int8_t n) {
    printint(stream, n, PrintFormat::Dec);
    return stream;
}

inline Stream<char>& operator<<(Stream<char>& stream, int16_t n) {
    printint(stream, n, PrintFormat::Dec);
    return stream;
}

inline Stream<char>& operator<<(Stream<char>& stream, int32_t n) {
    printint(stream, n, PrintFormat::Dec);
    return stream;
}

inline Stream<char>& operator<<(Stream<char>& stream, int64_t n) {
    printint(stream, n, PrintFormat::Dec);
    return stream;
}

inline Stream<char>& operator<<(Stream<char>& stream, uint8_t n) {
    printint(stream, n, PrintFormat::Dec);
    return stream;
}

inline Stream<char>& operator<<(Stream<char>& stream, uint16_t n) {
    printint(stream, n, PrintFormat::Dec);
    return stream;
}

inline Stream<char>& operator<<(Stream<char>& stream, uint32_t n) {
    printint(stream, n, PrintFormat::Dec);
    return stream;
}

inline Stream<char>& operator<<(Stream<char>& stream, uint64_t n) {
    printint(stream, n, PrintFormat::Dec);
    return stream;
}

inline Stream<char>& operator<<(Stream<char>& stream, bool n) {
    printstr(stream, n ? "true" : "false");
    return stream;
}

template <class T>
inline Stream<char>& operator<<(Stream<char>& stream, T* p) {
    printint(stream, uint16_t(p), PrintFormat::Hex);
    return stream;
}

#endif
