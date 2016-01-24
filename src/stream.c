#include "stream.h"

static uint8_t streamNextIndex(Stream* stream, uint8_t i);

bool streamPush(Stream* stream, uint8_t in) {
    if(stream == NULL) {
        return false;
    }

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        const uint8_t nextHead = streamNextIndex(stream, stream->head);

        if(nextHead == stream->tail) {
            stream->overflowed = true;
            return false;
        }

        stream->data[stream->head] = in;
        stream->head = nextHead;
    }

    return true;
}

bool streamPop(Stream* stream, uint8_t* out) {
    if(stream == NULL) {
        return false;
    }

    if(out == NULL) {
        return false;
    }

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        if(stream->tail == stream->head) {
            return false;
        }

        const uint8_t nextTail = streamNextIndex(stream, stream->tail);

        *out = stream->data[stream->tail];
        stream->tail = nextTail;
    }

    return true;
}

bool streamPeek(Stream* stream, uint8_t* out) {
    if(stream == NULL) {
        return false;
    }

    if(out == NULL) {
        return false;
    }

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        if(stream->tail == stream->head) {
            return false;
        }

        *out = stream->data[stream->tail];
    }

    return true;
}

bool streamPush16(Stream* stream, uint16_t n) {
    if(stream == NULL) {
        return false;
    }

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        if(streamUnused(stream) < 2) {
            return false;
        }

        streamPush(stream, (n >> 8));
        streamPush(stream, n);
    }

    return true;
}

bool streamPop16(Stream* stream, uint16_t* n) {
    if(stream == NULL) {
        return false;
    }

    if(n == NULL) {
        return false;
    }

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        if(streamUsed(stream) < 2) {
            return false;
        }

        uint8_t* t = (uint8_t*)n;
        streamPop(stream, t + 1);
        streamPop(stream, t);
    }

    return true;
}

bool streamPeek16(Stream* stream, uint16_t* n) {
    if(stream == NULL) {
        return false;
    }

    if(n == NULL) {
        return false;
    }

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        if(streamUsed(stream) < 2) {
            return false;
        }

        uint8_t* t = (uint8_t*)n;
        *(t + 1) = stream->data[stream->tail];
        *t = stream->data[streamNextIndex(stream, stream->tail)];
    }

    return true;
}

bool streamPushBuffer(Stream* stream, uint16_t count, uint8_t* buffer) {
    if(buffer == NULL) {
        return false;
    }

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        for(uint16_t i = 0; i < count; i++) {
            if(!streamPush(stream, buffer[i])) {
                return false;
            }
        }
    }

    return true;
}

bool streamPopBuffer(Stream* stream, uint16_t count, uint8_t* buffer) {
    if(buffer == NULL) {
        return false;
    }

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        for(uint16_t i = 0; i < count; i++) {
            uint8_t t;
            if(!streamPop(stream, &t)) {
                return false;
            }
            buffer[i] = t;
        }
    }

    return true;
}

int16_t streamUsed(Stream* stream) {
    if(stream == NULL) {
        return 0;
    }

    uint16_t result;

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        const uint8_t head = stream->head;
        const uint8_t tail = stream->tail;
        const uint8_t size = stream->size;

        if(head >= tail) {
            result = head - tail;
        } else {
            result = (size - tail) + head;
        }
    }

    return result;
}

int16_t streamUnused(Stream* stream) {
    if(stream == NULL) {
        return 0;
    }

    uint16_t result;

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        result = stream->size - streamUsed(stream) - 1;
    }

    return result;
}

static uint8_t streamNextIndex(Stream* stream, uint8_t i) {
    return (i + 1) % stream->size;
}
