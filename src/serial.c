#include "serial.h"

static struct {
    uint8_t currentInputStream;
    uint8_t currentOutputStream;
} mData;

static void setup(Task* task, uint32_t millis);
static void loop(Task* task, uint32_t millis);

Task serialTask = {
    .data = &mData,
    .dataSize = sizeof(mData),
    .setup = setup,
    .loop = loop,
    .priority = PRIORITY_DRIVER,
};

static void setup(Task* task, uint32_t millis) {
    enableUsart();
}

static void loop(Task* task, uint32_t millis) {
    if(usartDataRegisterEmpty()) {
        Stream* stream = task->inputStreams[mData.currentInputStream];
        uint8_t data;

        if((stream != NULL) && streamPop(stream, &data)) {
            usartPush(data);
        } else {
            mData.currentInputStream = (mData.currentInputStream + 1) % task->inputStreamCount;
        }
    }

    if(usartReceiveComplete()) {
        const uint8_t data = usartPop();

        for(uint8_t i = 0; i < task->outputStreamCount; i++) {
            Stream* stream = task->outputStreams[i];

            if(stream != NULL) {
                streamPush(stream, data);
            }
        }
    }

    return true;
}
