#ifndef STREAM_H
#define STREAM_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <util/atomic.h>

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
bool streamPush16(Stream* stream, uint16_t n);
bool streamPop16(Stream* stream, uint16_t* n);
bool streamPeek16(Stream* stream, uint16_t* n);
bool streamPushBuffer(Stream* stream, uint16_t count, uint8_t* buffer);
bool streamPopBuffer(Stream* stream, uint16_t count, uint8_t* buffer);
int16_t streamUsed(Stream* stream);
int16_t streamUnused(Stream* stream);
void streamClear(Stream* stream);

static inline bool streamHasOverflowed(Stream* stream) {
    if(stream == NULL) {
        return false;
    }

    bool result;

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        result = stream->overflowed;
    }

    return result;
}

static inline bool streamEmpty(Stream* stream) {
    if(stream == NULL) {
        return true;
    }

    bool result;

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        result = (stream->head == stream->tail);
    }

    return result;
}


static inline bool streamHasData(Stream* stream) {
    if(stream == NULL) {
        return false;
    }

    bool result;

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        result = (stream->head != stream->tail);
    }

    return result;
}

#endif
