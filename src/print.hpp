#ifndef NBOS_PRINT_HPP
#define NBOS_PRINT_HPP

#include "algorithm.hpp"
#include "array.hpp"
#include "libc.hpp"
#include "queue.hpp"
#include "string.hpp"

namespace nbos {

inline Bool printChar(Queue<Char>& queue, Char c) {
    const Bool result = queue.push(c);

    if(c == '\n') {
        queue.callCallback();
    }

    return result;
}

// inline Bool printString(Queue<Char>& queue, const Array<Char> str) {
inline Bool printString(Queue<Char>& queue, const String<>& str) {
    for(const Char p : str) {
        if(!printChar(queue, p)) {
            return false;
        }
    }

    return true;
}

template <class Type, Int base = 10>
inline constexpr Int itoa(Char* buffer, Type n) {
    static_assert((base >= 2) && (base <= 36), "Base must be between 2 and 36 inclusive");

    Int i = 0;

    if(n == 0) {
        buffer[i++] = '0';
    } else {
        const Bool negative = n < 0;

        n = abs(n);

        while(n != 0) {
            const Int d = Int(n % base);

            n /= base;

            if(d < 10) {
                buffer[i++] = '0' + d;
            } else {
                buffer[i++] = 'A' + (d - 10);
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

// TODO Make efficient Float to ascii function with output like:
// 1.0, 1.0004, 1000.002, 10000.01, 100000.0, 1.0e6, 0.001, -1.0e-50
// i.e. If more than ~13 characters, use scientific notation.
// int8_t ftoa(Char* buffer, Float n) {
//     union {
//         Float f;
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
//         Float e = floor(log10(n));
//         Float s = pow(10, -e) * n;
//
//         Float i;
//         Float f;
//
//         f = round(modff(s, &i) * 1e6);
//
//         buffer[k++] = '0' + int8_t(i);
//
//         buffer[k++] = '.';
//
//         Char bf[6];
//
//         // itoa(&buffer[k], int32_t(f), 10);
//         int8_t l = _itoa(bf, int32_t(f), 10);
//
//         // for(int8_t j = l; j < 6; j++) {
//         //     buffer[k++] = '0';
//         // }
//
//         for(int8_t j = 0; j < l; j++) {
//             Char c = bf[(l - 1) - j];
//             if(c != '0') {
//                 buffer[k++] = c; // XXX XXX XXX
//             }
//         }
//
//         // k += 6;
//         //
//         // for(int8_t j = 0; j < 5; j++) {
//         //     Char c = buffer[k - 1];
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

template <class T, Int base = 10>
inline Bool printInt(Queue<Char>& queue, T n) {
    // FIXME This shouldn't compile so easily. (Cast from float to int.)
    constexpr Int maxDigits = *(Float(1) + (floor(log(Float(Max<T>::value)) / log(Float(base)))));

    Char buffer[maxDigits + IsSigned<T>::value + 1];

    itoa<T, base>(buffer, n);

    return printString(queue, (const Char*)buffer);
}

inline Bool printFloat(Queue<Char>& queue, Float n) {
    Char buffer[14];

    libc::dtostre(primitive_double(Double(n)), (primitive_signed_char*)buffer, 6, 0);

    return printString(queue, buffer);
}

inline Queue<Char>& operator<<(Queue<Char>& queue, const Char c) {
    printChar(queue, c);

    return queue;
}

inline Queue<Char>& operator<<(Queue<Char>& queue, const primitive_signed_char* str) {
    for(const primitive_signed_char* c = str; *c != '\0'; c++) {
        printChar(queue, *c);
    }

    return queue;
}

inline Queue<Char>& operator<<(Queue<Char>& queue, Int8 n) {
    printInt(queue, n);

    return queue;
}

inline Queue<Char>& operator<<(Queue<Char>& queue, Int16 n) {
    printInt(queue, n);

    return queue;
}

inline Queue<Char>& operator<<(Queue<Char>& queue, Int32 n) {
    printInt(queue, n);

    return queue;
}

inline Queue<Char>& operator<<(Queue<Char>& queue, Int64 n) {
    printInt(queue, n);

    return queue;
}

inline Queue<Char>& operator<<(Queue<Char>& queue, Word8 n) {
    printInt(queue, n);

    return queue;
}

inline Queue<Char>& operator<<(Queue<Char>& queue, Word16 n) {
    printInt(queue, n);

    return queue;
}

inline Queue<Char>& operator<<(Queue<Char>& queue, Word32 n) {
    printInt(queue, n);

    return queue;
}

inline Queue<Char>& operator<<(Queue<Char>& queue, Word64 n) {
    printInt(queue, n);

    return queue;
}

inline Queue<Char>& operator<<(Queue<Char>& queue, Bool n) {
    printString(queue, n ? "true" : "false");

    return queue;
}

template <class T>
inline Queue<Char>& operator<<(Queue<Char>& queue, T* p) {
    printInt<Word16, 16>(queue, *p);

    return queue;
}

inline Queue<Char>& operator<<(Queue<Char>& queue, Float n) {
    printFloat(queue, *n);

    return queue;
}

inline Queue<Char>& operator<<(Queue<Char>& queue, Double n) {
    printFloat(queue, *n);

    return queue;
}

#ifdef TEST

TEST(Print, itoa) {
    Char str[64];

    itoa(str, Int8(0));
    EXPECT_STREQ((Char::T*)str, "0");

    itoa(str, Word8(147));
    EXPECT_STREQ((Char::T*)str, "147");

    itoa(str, Int16(1476));
    EXPECT_STREQ((Char::T*)str, "1476");

    itoa(str, Int16(-1476));
    EXPECT_STREQ((Char::T*)str, "-1476");

    itoa<Int16, 2>(str, Int16(764));
    EXPECT_STREQ((Char::T*)str, "1011111100");

    itoa<Int16, 16>(str, Int16(847));
    EXPECT_STREQ((Char::T*)str, "34F");

    itoa<Int16, 16>(str, Int16(-847));
    EXPECT_STREQ((Char::T*)str, "-34F");

    itoa<Int32, 36>(str, Int32(36));
    EXPECT_STREQ((Char::T*)str, "10");

    itoa(str, Int32(65535));
    EXPECT_STREQ((Char::T*)str, "65535");

    itoa(str, Word32(65535));
    EXPECT_STREQ((Char::T*)str, "65535");

    itoa(str, Int32(32768));
    EXPECT_STREQ((Char::T*)str, "32768");
}

#endif

} // nbos

#endif
