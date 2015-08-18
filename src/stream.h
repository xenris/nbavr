#ifndef STREAM_H
#define STREAM_H

#include <stdbool.h>
#include <stdint.h>

#include "ringbuffer.h"

typedef struct OutputStream OutputStream;
typedef struct InputStream InputStream;

OutputStream* outputStreamCreate(const char* id, RingBuffer* ringBuffer);
bool outputStreamPush(OutputStream* outputStream, uint8_t n);
int16_t outputStreamAvailable(OutputStream* outputStream);
const char* outputStreamId(OutputStream* outputStream);
bool outputStreamHasOverflowed(OutputStream* outputStream);
InputStream* inputStreamCreate(const char* id, RingBuffer* ringBuffer);
bool inputStreamPop(InputStream* inputStream, uint8_t* n);
bool inputStreamPeek(InputStream* inputStream, uint8_t* n);
int16_t inputStreamAvailable(InputStream* inputStream);
bool inputStreamHasData(InputStream* inputStream);
const char* inputStreamId(InputStream* inputStream);
bool inputStreamHasOverflowed(InputStream* inputStream);

#endif
