#include "ringbuffer.h"

typedef struct RingBuffer {
    uint8_t* data;
    uint8_t size;
    uint8_t head;
    uint8_t tail;
    bool overflowed;
} RingBuffer;

static uint8_t ringBufferNext(RingBuffer* ringBuffer, uint8_t i);

RingBuffer* ringBufferCreate(uint8_t size) {
    RingBuffer* ringBuffer = calloc(1, sizeof(RingBuffer));

    if(ringBuffer == NULL) {
        return NULL;
    }

    ringBuffer->data = calloc(size, sizeof(uint8_t));

    if(ringBuffer->data == NULL) {
        free(ringBuffer);
        return NULL;
    }

    ringBuffer->size = size;

    return ringBuffer;
}

bool ringBufferPush(RingBuffer* ringBuffer, uint8_t in) {
    const uint8_t nextHead = ringBufferNext(ringBuffer, ringBuffer->head);

    if(nextHead == ringBuffer->tail) {
        ringBuffer->overflowed = true;
        return false;
    }

    ringBuffer->data[ringBuffer->head] = in;
    ringBuffer->head = nextHead;

    return true;
}

bool ringBufferPop(RingBuffer* ringBuffer, uint8_t* out) {
    if(ringBuffer->tail == ringBuffer->head) {
        return false;
    }

    const uint8_t nextTail = ringBufferNext(ringBuffer, ringBuffer->tail);

    *out = ringBuffer->data[ringBuffer->tail];
    ringBuffer->tail = nextTail;

    return true;
}

bool ringBufferPeek(RingBuffer* ringBuffer, uint8_t* out) {
    if(ringBuffer->tail == ringBuffer->head) {
        return false;
    }

    *out = ringBuffer->data[ringBuffer->tail];

    return true;
}

bool ringBufferFull(RingBuffer* ringBuffer) {
    const uint8_t nextHead = ringBufferNext(ringBuffer, ringBuffer->head);

    return (nextHead == ringBuffer->tail);
}

bool ringBufferEmpty(RingBuffer* ringBuffer) {
    return (ringBuffer->head == ringBuffer->tail);
}

void ringBufferClear(RingBuffer* ringBuffer) {
    ringBuffer->head = 0;
    ringBuffer->tail = 0;
    ringBuffer->overflowed = false;
}

uint8_t ringBufferUsed(RingBuffer* ringBuffer) {
    const uint8_t head = ringBuffer->head;
    const uint8_t tail = ringBuffer->tail;
    const uint8_t size = ringBuffer->size;

    if(head >= tail) {
        return head - tail;
    } else {
        return (size - tail) + head;
    }
}

uint8_t ringBufferUnused(RingBuffer* ringBuffer) {
    int16_t diff = ringBuffer->tail - ringBuffer->head;

    if(diff < 0) {
        diff += ringBuffer->size;
    }

    return diff;

    const uint8_t head = ringBuffer->head;
    const uint8_t tail = ringBuffer->tail;
    const uint8_t size = ringBuffer->size;

    if(head >= tail) {
        return (size - head) + tail;
    } else {
        return tail - head;
    }
}

bool ringBufferHasOverflowed(RingBuffer* ringBuffer) {
    return ringBuffer->overflowed;
}

static uint8_t ringBufferNext(RingBuffer* ringBuffer, uint8_t i) {
    return (i + 1) % ringBuffer->size;
}
