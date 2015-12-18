#ifndef STREAM_H
#define STREAM_H

#include <stdbool.h>
#include <stdint.h>

typedef struct Stream {
    uint16_t size;
    uint16_t head;
    uint16_t tail;
    bool overflowed;
    uint8_t data[];
} Stream;

// For initialising a stream statically.
// +1 in size to compensate for one lost byte.
// One byte is lost in the process of detecting overflow.
#define streamInit(n) {n + 1, 0, 0, false, {[n]0}}

bool streamPush(Stream* stream, uint8_t n);
bool streamPop(Stream* stream, uint8_t* n);
bool streamPeek(Stream* stream, uint8_t* n);
int16_t streamUsed(Stream* stream);
int16_t streamUnused(Stream* stream);

inline bool streamHasOverflowed(Stream* stream) {
    return stream->overflowed;
}

inline bool streamEmpty(Stream* stream) {
    return (stream->head == stream->tail);
}


inline bool streamHasData(Stream* stream) {
    return !streamEmpty(stream);
}

#endif
