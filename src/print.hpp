#ifndef NBAVR_PRINT_HPP
#define NBAVR_PRINT_HPP

// High nibble indicates whether it is signed.
// Low nibble indicates the base.
enum class PrintFormat : uint8_t {
    UBin = 0x00,
    UOct = 0x01,
    UDec = 0x02,
    UHex = 0x04,
    SBin = 0x10,
    SOct = 0x11,
    SDec = 0x12,
    SHex = 0x14,
};

constexpr char endl = '\n';

inline bool printchar(Stream<char>& stream, char c) {
    return stream.push(c);
}

inline bool printstr(Stream<char>& stream, const char* str) {
    for(char* p = (char*)str; *p != '\0'; p++) {
        if(!stream.push(*p)) {
            return false;
        }
    }

    return true;
}

#define INT_SIZE 8
#include "printin.tpp"
#undef INT_SIZE

#define INT_SIZE 16
#include "printin.tpp"
#undef INT_SIZE

#define INT_SIZE 32
#include "printin.tpp"
#undef INT_SIZE

#define INT_SIZE 64
#include "printin.tpp"
#undef INT_SIZE

inline Stream<char>& operator<<(Stream<char>& stream, const char* str) {
    printstr(stream, str);
    return stream;
}

inline Stream<char>& operator<<(Stream<char>& stream, int8_t n) {
    printint(stream, n, PrintFormat::SDec);
    return stream;
}

inline Stream<char>& operator<<(Stream<char>& stream, int16_t n) {
    printint(stream, n, PrintFormat::SDec);
    return stream;
}

inline Stream<char>& operator<<(Stream<char>& stream, int32_t n) {
    printint(stream, n, PrintFormat::SDec);
    return stream;
}

inline Stream<char>& operator<<(Stream<char>& stream, int64_t n) {
    printint(stream, n, PrintFormat::SDec);
    return stream;
}

inline Stream<char>& operator<<(Stream<char>& stream, uint8_t n) {
    printint(stream, n, PrintFormat::UDec);
    return stream;
}

inline Stream<char>& operator<<(Stream<char>& stream, uint16_t n) {
    printint(stream, n, PrintFormat::UDec);
    return stream;
}

inline Stream<char>& operator<<(Stream<char>& stream, uint32_t n) {
    printint(stream, n, PrintFormat::UDec);
    return stream;
}

inline Stream<char>& operator<<(Stream<char>& stream, uint64_t n) {
    printint(stream, n, PrintFormat::UDec);
    return stream;
}

inline Stream<char>& operator<<(Stream<char>& stream, bool n) {
    printstr(stream, n ? "true" : "false");
    return stream;
}

template <class T>
inline Stream<char>& operator<<(Stream<char>& stream, T* p) {
    printint(stream, (uint16_t)p, PrintFormat::UHex);
    return stream;
}

#endif
