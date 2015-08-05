#include "ringbuffer.h"

uint8_t ringBufferNext(uint8_t i);

bool ringBufferPush(RingBuffer* buffer, uint8_t in) {
    const uint8_t nextHead = ringBufferNext(buffer->head);

    if(nextHead == buffer->tail) {
        return false;
    }

    buffer->data[buffer->head] = in;
    buffer->head = nextHead;

    return true;
}

bool ringBufferPop(RingBuffer* buffer, uint8_t* out) {
    if(buffer->tail == buffer->head) {
        return false;
    }

    const uint8_t nextTail = ringBufferNext(buffer->tail);

    *out = buffer->data[buffer->tail];
    buffer->tail = nextTail;

    return true;
}

bool ringBufferPeek(RingBuffer* buffer, uint8_t* out) {
    if(buffer->tail == buffer->head) {
        return false;
    }

    *out = buffer->data[buffer->tail];

    return true;
}

bool ringBufferFull(RingBuffer* buffer) {
    const uint8_t nextHead = ringBufferNext(buffer->head);

    return (nextHead == buffer->tail);
}

bool ringBufferEmpty(RingBuffer* buffer) {
    return (buffer->head == buffer->tail);
}

void ringBufferClear(RingBuffer* buffer) {
    buffer->head = 0;
    buffer->tail = 0;
}

uint8_t ringBufferNext(uint8_t i) {
    return (i + 1) % RING_BUFFER_SIZE;
}
