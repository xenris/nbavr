#include "stream.h"

typedef struct OutputStream {
    const char* id;
    RingBuffer* ringBuffer;
} OutputStream;

typedef struct InputStream {
    const char* id;
    RingBuffer* ringBuffer;
} InputStream;

OutputStream* outputStreamCreate(const char* id, RingBuffer* ringBuffer) {
    OutputStream* outputStream = calloc(1, sizeof(OutputStream));

    if(outputStream == NULL) {
        return NULL;
    }

    outputStream->id = id;
    outputStream->ringBuffer = ringBuffer;

    return outputStream;
}

bool outputStreamPush(OutputStream* outputStream, uint8_t n) {
    return ringBufferPush(outputStream->ringBuffer, n);
}

int16_t outputStreamAvailable(OutputStream* outputStream) {
    return ringBufferUnused(outputStream->ringBuffer);
}

const char* outputStreamId(OutputStream* outputStream) {
    return outputStream->id;
}

bool outputStreamHasOverflowed(OutputStream* outputStream) {
    return ringBufferHasOverflowed(outputStream->ringBuffer);
}

InputStream* inputStreamCreate(const char* id, RingBuffer* ringBuffer) {
    InputStream* inputStream = calloc(1, sizeof(InputStream));

    if(inputStream == NULL) {
        return NULL;
    }

    inputStream->id = id;
    inputStream->ringBuffer = ringBuffer;

    return inputStream;
}

bool inputStreamPop(InputStream* inputStream, uint8_t* n) {
    return ringBufferPop(inputStream->ringBuffer, n);
}

bool inputStreamPeek(InputStream* inputStream, uint8_t* n) {
    return ringBufferPeek(inputStream->ringBuffer, n);
}

int16_t inputStreamAvailable(InputStream* inputStream) {
    return ringBufferUsed(inputStream->ringBuffer);
}

bool inputStreamHasData(InputStream* inputStream) {
    return !ringBufferEmpty(inputStream->ringBuffer);
}

const char* inputStreamId(InputStream* inputStream) {
    return inputStream->id;
}

bool inputStreamHasOverflowed(InputStream* inputStream) {
    return ringBufferHasOverflowed(inputStream->ringBuffer);
}
