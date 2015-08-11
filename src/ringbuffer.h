#ifndef RINGBUFFER_H
#define RINGBUFFER_H

// Ring buffer (circular buffer).
// Indexing variables are uint8_t so the largest buffer size possible is 256
//  bytes. I'm making the assumption that anything larger than that is unlikely
//  to be needed on an 8 bit microcontroller.
// Due to maths, the actual storage available is the buffer size - 1.

// TODO Contemplate the pros and cons of mallocing the data array:
//  Pros:
//      Can be any size, which means more efficient momory use.
//      The struct can be defined in the c file.
//  Cons:
//      Requires using malloc, which can make things a bit messier... I think.

#include "../config.h"
#include <stdbool.h>
#include <stdint.h>

typedef struct {
    uint8_t data[RING_BUFFER_SIZE];
    uint8_t head;
    uint8_t tail;
} RingBuffer;

bool ringBufferPush(RingBuffer* buffer, uint8_t in);
bool ringBufferPop(RingBuffer* buffer, uint8_t* out);
bool ringBufferPeek(RingBuffer* buffer, uint8_t* out);
bool ringBufferFull(RingBuffer* buffer);
bool ringBufferEmpty(RingBuffer* buffer);
void ringBufferClear(RingBuffer* buffer);

#endif
