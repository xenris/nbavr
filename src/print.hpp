#ifndef NBOS_PRINT_HPP
#define NBOS_PRINT_HPP

#include "algorithm.hpp"
#include "libc.hpp"
#include "math.hpp"
#include "queue.hpp"

namespace nbos {

template<int S>
inline bool printchar(Queue<char, S>& queue, const char c) {
    bool result = queue.push(c);

    if(c == '\n') {
        queue.notify();
    }

    return result;
}

template<int S>
inline bool printstr(Queue<char, S>& queue, const char* str) {
    for(const char* p = str; *p != '\0'; p++) {
        if(!printchar(queue, *p)) {
            return false;
        }
    }

    return true;
}

// Converts integer T to reverse ascii string.
template <class T>
inline int8_t _itoa(char* buffer, T n, int8_t base) {
    int8_t i = 0;

    if(n == 0) {
        buffer[i++] = '0';
    } else {
        const bool negative = n < 0;

        base = clip(base, int8_t(2), int8_t(36));
        n = abs(n);

        while(n != 0) {
            int8_t d = n % base;

            n /= base;

            if(d < 10) {
                buffer[i++] = '0' + d;
            } else {
                buffer[i++] = 'a' + (d - 10);
            }
        }

        if(negative) {
            buffer[i++] = '-';
        }
    }

    buffer[i] = '\0';

    return i;
}

// Converts integer T to ascii string.
template <class T>
inline int8_t itoa(char* buffer, T n, int8_t base) {
    const int8_t l = _itoa(buffer, n, base);

    reverse(buffer, buffer, l);

    return l;
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

template <int S, class T>
inline bool printint(Queue<char, S>& queue, T n, int8_t base) {
    char buffer[sizeof(T) * 8 + 1 + 1];

    itoa(buffer, n, base);

    return printstr(queue, buffer);
}

template<int S>
inline bool printfloat(Queue<char, S>& queue, float n) {
    char buffer[14];

    libc::dtostre(n, buffer, 6, 0);

    return printstr(queue, buffer);
}

template<int S>
inline Queue<char, S>& operator<<(Queue<char, S>& queue, const char c) {
    printchar(queue, c);
    return queue;
}

template<int S>
inline Queue<char, S>& operator<<(Queue<char, S>& queue, const char* str) {
    printstr(queue, str);
    return queue;
}

template<int S>
inline Queue<char, S>& operator<<(Queue<char, S>& queue, int8_t n) {
    printint(queue, n, 10);
    return queue;
}

template<int S>
inline Queue<char, S>& operator<<(Queue<char, S>& queue, int16_t n) {
    printint(queue, n, 10);
    return queue;
}

template<int S>
inline Queue<char, S>& operator<<(Queue<char, S>& queue, int32_t n) {
    printint(queue, n, 10);
    return queue;
}

template<int S>
inline Queue<char, S>& operator<<(Queue<char, S>& queue, int64_t n) {
    printint(queue, n, 10);
    return queue;
}

template<int S>
inline Queue<char, S>& operator<<(Queue<char, S>& queue, uint8_t n) {
    printint(queue, n, 10);
    return queue;
}

template<int S>
inline Queue<char, S>& operator<<(Queue<char, S>& queue, uint16_t n) {
    printint(queue, n, 10);
    return queue;
}

template<int S>
inline Queue<char, S>& operator<<(Queue<char, S>& queue, uint32_t n) {
    printint(queue, n, 10);
    return queue;
}

template<int S>
inline Queue<char, S>& operator<<(Queue<char, S>& queue, uint64_t n) {
    printint(queue, n, 10);
    return queue;
}

template<int S>
inline Queue<char, S>& operator<<(Queue<char, S>& queue, bool n) {
    printstr(queue, n ? "true" : "false");
    return queue;
}

template <int S, class T>
inline Queue<char, S>& operator<<(Queue<char, S>& queue, T* p) {
    printint(queue, uint16_t(p), 16);
    return queue;
}

template<int S>
inline Queue<char, S>& operator<<(Queue<char, S>& queue, float n) {
    printfloat(queue, n);
    return queue;
}

template<int S>
inline Queue<char, S>& operator<<(Queue<char, S>& queue, double n) {
    printfloat(queue, float(n));
    return queue;
}

} // nbos

#endif
