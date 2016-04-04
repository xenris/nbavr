#ifndef STREAM_H
#define STREAM_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <util/atomic.h>

typedef void (*StreamCallback)();

typedef struct Stream {
    uint16_t size;
    uint16_t head;
    uint16_t tail;
    bool overflowed;
    StreamCallback callback;
    uint8_t data[];
} Stream;

// For initialising a stream statically.
// +1 in size to compensate for one lost byte.
// One byte is lost in the process of detecting overflow.
#define streamInit(n) {n + 1, 0, 0, false, NULL, {[n]0}}
#define streamInitCallback(n,f) {n + 1, 0, 0, false, f, {[n]0}}

bool streamPush_(Stream* stream, uint8_t n);
bool streamPop_(Stream* stream, uint8_t* n);
bool streamPeek_(Stream* stream, uint8_t* n);
bool streamPush16_(Stream* stream, uint16_t n);
bool streamPop16_(Stream* stream, uint16_t* n);
bool streamPeek16_(Stream* stream, uint16_t* n);
bool streamPushBuffer_(Stream* stream, uint16_t count, uint8_t* buffer);
bool streamPopBuffer_(Stream* stream, uint16_t count, uint8_t* buffer);
int16_t streamUsed_(Stream* stream);
int16_t streamUnused_(Stream* stream);
void streamClear_(Stream* stream);

static inline bool streamHasOverflowed_(Stream* stream) {
    if(stream == NULL) {
        return false;
    }

    return stream->overflowed;
}

static inline bool streamEmpty_(Stream* stream) {
    if(stream == NULL) {
        return true;
    }

    return (stream->head == stream->tail);
}


static inline bool streamHasData_(Stream* stream) {
    if(stream == NULL) {
        return false;
    }

    return (stream->head != stream->tail);
}

static inline bool streamPush(Stream* stream, uint8_t n) {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        return streamPush_(stream, n);
    }

    return false;
}

static inline bool streamPop(Stream* stream, uint8_t* n) {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        return streamPop_(stream, n);
    }

    return false;
}

static inline bool streamPeek(Stream* stream, uint8_t* n) {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        return streamPeek_(stream, n);
    }

    return false;
}

static inline bool streamPush16(Stream* stream, uint16_t n) {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        return streamPush16_(stream, n);
    }

    return false;
}

static inline bool streamPop16(Stream* stream, uint16_t* n) {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        return streamPop16_(stream, n);
    }

    return false;
}

static inline bool streamPeek16(Stream* stream, uint16_t* n) {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        return streamPeek16_(stream, n);
    }

    return false;
}

static inline bool streamPushBuffer(Stream* stream, uint16_t count, uint8_t* buffer) {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        return streamPushBuffer_(stream, count, buffer);
    }

    return false;
}

static inline bool streamPopBuffer(Stream* stream, uint16_t count, uint8_t* buffer) {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        return streamPopBuffer_(stream, count, buffer);
    }

    return false;
}


static inline int16_t streamUsed(Stream* stream) {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        return streamUsed_(stream);
    }

    return 0;
}

static inline int16_t streamUnused(Stream* stream) {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        return streamUnused_(stream);
    }

    return 0;
}

static inline void streamClear(Stream* stream) {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        streamClear_(stream);
    }
}

static inline bool streamHasOverflowed(Stream* stream) {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        return streamHasOverflowed_(stream);
    }

    return false;
}

static inline bool streamEmpty(Stream* stream) {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        return streamEmpty_(stream);
    }

    return false;
}

static inline bool streamHasData(Stream* stream) {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        return streamHasData_(stream);
    }

    return false;
}

#endif
