#ifndef NBOS_PRINT_HPP
#define NBOS_PRINT_HPP

#include "algorithm.hpp"
#include "array.hpp"
#include "libc.hpp"
#include "queue.hpp"
#include "string.hpp"

namespace nbos {

inline bool printChar(Queue<char>& queue, char c) {
    const bool result = queue.push(c);

    if(c == '\n') {
        queue.callCallback();
    }

    return result;
}

// inline bool printString(Queue<char>& queue, const Array<char> str) {
inline bool printString(Queue<char>& queue, const String<>& str) {
    for(const char p : str) {
        if(!printChar(queue, p)) {
            return false;
        }
    }

    return true;
}

template <class Type, int base = 10>
inline constexpr int itoa(char* buffer, Type n) {
    static_assert((base >= 2) && (base <= 36), "Base must be between 2 and 36 inclusive");

    int i = 0;

    if(n == 0) {
        buffer[i++] = '0';
    } else {
        const bool negative = n < 0;

        n = abs(n);

        while(n != 0) {
            const int d = int(n % base);

            n /= base;

            if(d < 10) {
                buffer[i++] = char('0' + d);
            } else {
                buffer[i++] = char('A' + (d - 10));
            }
        }

        if(negative) {
            buffer[i++] = '-';
        }
    }

    buffer[i] = '\0';

    reverse(buffer, i);

    return i;
}

// TODO Make efficient float to ascii function with output like:
// 1.0, 1.0004, 1000.002, 10000.01, 100000.0, 1.0e6, 0.001, -1.0e-50
// i.e. If more than ~13 characters, use scientific notation.
// int8_t ftoa(char* buffer, float n) {
//     union {
//         float f;
//         int i;
//     } u;
//
//     u.f = n;
//
//     int8_t k = 0;
//
//     if(u.i & bv(31)) {
//         buffer[k++] = '-';
//         n = -n;
//     }
//
//     if(n == 0) {
//         buffer[k++] = '0';
//         buffer[k++] = '.';
//         buffer[k++] = '0';
//     } else {
//         float e = floor(log10(n));
//         float s = pow(10, -e) * n;
//
//         float i;
//         float f;
//
//         f = round(modff(s, &i) * 1e6);
//
//         buffer[k++] = '0' + int8_t(i);
//
//         buffer[k++] = '.';
//
//         char bf[6];
//
//         // itoa(&buffer[k], int32_t(f), 10);
//         int8_t l = _itoa(bf, int32_t(f), 10);
//
//         // for(int8_t j = l; j < 6; j++) {
//         //     buffer[k++] = '0';
//         // }
//
//         for(int8_t j = 0; j < l; j++) {
//             char c = bf[(l - 1) - j];
//             if(c != '0') {
//                 buffer[k++] = c; // XXX XXX XXX
//             }
//         }
//
//         // k += 6;
//         //
//         // for(int8_t j = 0; j < 5; j++) {
//         //     char c = buffer[k - 1];
//         //     if(('1' <= c) && (c <= '9')) {
//         //         break;
//         //     } else {
//         //         k--;
//         //     }
//         // }
//
//         if(int16_t(e) != 0) {
//             buffer[k++] = 'e';
//             k += itoa(&buffer[k], int16_t(e), 10);
//         }
//     }
//
//     buffer[k] = '\0';
//
//     return k;
// }

template <class T, int base = 10>
inline bool printInt(Queue<char>& queue, T n) {
    // FIXME This shouldn't compile so easily. (Cast from float to int.)
    constexpr int maxDigits = int(float(1) + (floor(log(float(max<T>())) / log(float(base)))));
    // constexpr int maxDigits = int(float(1) + (floor(log(float(Max<T>::value)) / log(float(base)))));

    char buffer[maxDigits + isSigned<T>() + 1];

    itoa<T, base>(buffer, n);

    return printString(queue, buffer);
}

inline bool printFloat(Queue<char>& queue, float n) {
    char buffer[14];

    libc::dtostre(double(double(n)), buffer, 6, 0);

    return printString(queue, buffer);
}

inline Queue<char>& operator<<(Queue<char>& queue, const char c) {
    printChar(queue, c);

    return queue;
}

inline Queue<char>& operator<<(Queue<char>& queue, const char* str) {
    for(const char* c = str; *c != '\0'; c++) {
        printChar(queue, *c);
    }

    return queue;
}

inline Queue<char>& operator<<(Queue<char>& queue, const String<>& s) {
    printString(queue, s);

    return queue;
}

// inline Queue<char>& operator<<(Queue<char>& queue, int8_t n) {
//     printInt(queue, n);

//     return queue;
// }

inline Queue<char>& operator<<(Queue<char>& queue, int16_t n) {
    printInt(queue, n);

    return queue;
}

inline Queue<char>& operator<<(Queue<char>& queue, int32_t n) {
    printInt(queue, n);

    return queue;
}

inline Queue<char>& operator<<(Queue<char>& queue, int64_t n) {
    printInt(queue, n);

    return queue;
}

inline Queue<char>& operator<<(Queue<char>& queue, uint8_t n) {
    printInt(queue, n);

    return queue;
}

inline Queue<char>& operator<<(Queue<char>& queue, uint16_t n) {
    printInt(queue, n);

    return queue;
}

inline Queue<char>& operator<<(Queue<char>& queue, uint32_t n) {
    printInt(queue, n);

    return queue;
}

inline Queue<char>& operator<<(Queue<char>& queue, uint64_t n) {
    printInt(queue, n);

    return queue;
}

inline Queue<char>& operator<<(Queue<char>& queue, bool n) {
    printString(queue, n ? "true" : "false");

    return queue;
}

template <class T>
inline Queue<char>& operator<<(Queue<char>& queue, T* p) {
    printInt<uint16_t, 16>(queue, p);

    return queue;
}

inline Queue<char>& operator<<(Queue<char>& queue, float n) {
    printFloat(queue, n);

    return queue;
}

// inline Queue<char>& operator<<(Queue<char>& queue, double n) {
//     printFloat(queue, n);

//     return queue;
// }

#ifdef TEST

TEST(Print, itoa) {
    char str[64];

    itoa(str, uint8_t(0));
    EXPECT_STREQ(str, "0");

    itoa(str, uint8_t(147));
    EXPECT_STREQ(str, "147");

    itoa(str, int16_t(1476));
    EXPECT_STREQ(str, "1476");

    itoa(str, int16_t(-1476));
    EXPECT_STREQ(str, "-1476");

    itoa<int16_t, 2>(str, int16_t(764));
    EXPECT_STREQ(str, "1011111100");

    itoa<int16_t, 16>(str, int16_t(847));
    EXPECT_STREQ(str, "34F");

    itoa<int16_t, 16>(str, int16_t(-847));
    EXPECT_STREQ(str, "-34F");

    itoa<int32_t, 36>(str, int32_t(36));
    EXPECT_STREQ(str, "10");

    itoa(str, int32_t(65535));
    EXPECT_STREQ(str, "65535");

    itoa(str, uint32_t(65535));
    EXPECT_STREQ(str, "65535");

    itoa(str, int32_t(32768));
    EXPECT_STREQ(str, "32768");
}

#endif

} // nbos

#endif
