#ifndef RINGBUFFER_H
#define RINGBUFFER_H

// Ring buffer (circular buffer).
// Indexing variables are uint8_t so the largest buffer size possible is 256
//  bytes. I'm making the assumption that anything larger than that is unlikely
//  to be needed on an 8 bit microcontroller.
// Due to maths, the actual storage available is the buffer size - 1.

// FIXME Make it so that all the buffer is used. Currently ringBufferUnused is
//  off by +1;

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct RingBuffer RingBuffer;

RingBuffer* ringBufferCreate(uint8_t bufferSize);
bool ringBufferPush(RingBuffer* buffer, uint8_t in);
bool ringBufferPop(RingBuffer* buffer, uint8_t* out);
bool ringBufferPeek(RingBuffer* buffer, uint8_t* out);
bool ringBufferFull(RingBuffer* buffer);
bool ringBufferEmpty(RingBuffer* buffer);
void ringBufferClear(RingBuffer* buffer);
uint8_t ringBufferUsed(RingBuffer* ringBuffer);
uint8_t ringBufferUnused(RingBuffer* ringBuffer);
bool ringBufferHasOverflowed(RingBuffer* ringBuffer);

#endif
