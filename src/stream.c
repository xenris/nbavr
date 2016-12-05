#include "stream.h"

static uint8_t streamNextIndex(Stream* stream, uint8_t i);

bool streamPush_(Stream* stream, uint8_t in) {
    if(stream == NULL) {
        return false;
    }

    if(streamEmpty_(stream)) {
        if(stream->callback != NULL) {
            stream->callback();
        }
    }

    const uint8_t nextHead = streamNextIndex(stream, stream->head);

    if(nextHead == stream->tail) {
        stream->overflowed = true;
        return false;
    }

    stream->data[stream->head] = in;
    stream->head = nextHead;

    return true;
}

bool streamPop_(Stream* stream, uint8_t* out) {
    if(stream == NULL) {
        return false;
    }

    if(out == NULL) {
        return false;
    }

    if(stream->tail == stream->head) {
        return false;
    }

    const uint8_t nextTail = streamNextIndex(stream, stream->tail);

    *out = stream->data[stream->tail];
    stream->tail = nextTail;

    return true;
}

bool streamPeek_(Stream* stream, uint8_t* out) {
    if(stream == NULL) {
        return false;
    }

    if(out == NULL) {
        return false;
    }

    if(stream->tail == stream->head) {
        return false;
    }

    *out = stream->data[stream->tail];

    return true;
}

bool streamPush16_(Stream* stream, uint16_t n) {
    if(stream == NULL) {
        return false;
    }

    if(streamEmpty_(stream)) {
        if(stream->callback != NULL) {
            stream->callback();
        }
    }

    if(streamUnused_(stream) < 2) {
        return false;
    }

    streamPush_(stream, (n >> 8));
    streamPush_(stream, n);

    return true;
}

bool streamPop16_(Stream* stream, uint16_t* n) {
    if(stream == NULL) {
        return false;
    }

    if(n == NULL) {
        return false;
    }

    if(streamUsed_(stream) < 2) {
        return false;
    }

    uint8_t* t = (uint8_t*)n;
    streamPop_(stream, t + 1);
    streamPop_(stream, t);

    return true;
}

bool streamPeek16_(Stream* stream, uint16_t* n) {
    if(stream == NULL) {
        return false;
    }

    if(n == NULL) {
        return false;
    }

    if(streamUsed_(stream) < 2) {
        return false;
    }

    uint8_t* t = (uint8_t*)n;
    *(t + 1) = stream->data[stream->tail];
    *t = stream->data[streamNextIndex(stream, stream->tail)];

    return true;
}

bool streamPushBuffer_(Stream* stream, uint16_t count, uint8_t* buffer) {
    if(buffer == NULL) {
        return false;
    }

    if(streamEmpty_(stream)) {
        if(stream->callback != NULL) {
            stream->callback();
        }
    }

    for(uint16_t i = 0; i < count; i++) {
        if(!streamPush_(stream, buffer[i])) {
            return false;
        }
    }

    return true;
}

bool streamPopBuffer_(Stream* stream, uint16_t count, uint8_t* buffer) {
    if(buffer == NULL) {
        return false;
    }

    for(uint16_t i = 0; i < count; i++) {
        uint8_t t;
        if(!streamPop_(stream, &t)) {
            return false;
        }
        buffer[i] = t;
    }

    return true;
}

int16_t streamUsed_(Stream* stream) {
    if(stream == NULL) {
        return 0;
    }

    const uint8_t head = stream->head;
    const uint8_t tail = stream->tail;
    const uint8_t size = stream->size;

    if(head >= tail) {
        return head - tail;
    } else {
        return (size - tail) + head;
    }
}

int16_t streamUnused_(Stream* stream) {
    if(stream == NULL) {
        return 0;
    }

    return stream->size - streamUsed_(stream) - 1;
}

void streamClear_(Stream* stream) {
    if(stream == NULL) {
        return;
    }

    stream->head = 0;
    stream->tail = 0;
}

static uint8_t streamNextIndex(Stream* stream, uint8_t i) {
    return (i + 1) % stream->size;
}
