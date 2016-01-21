#include "serial.h"

static struct {
    uint8_t currentInputStream;
} mData;

static void setup(Task* task);
static void loop(Task* task);

Task serialTask = {
    .data = &mData,
    .dataSize = sizeof(mData),
    .setup = setup,
    .loop = loop,
    .priority = PRIORITY_DRIVER,
};

static void setup(Task* task) {
    USART0Config config = {
        .receiverEnable = true,
        .transmitterEnable = true,
        .characterSize = USART0_8_BIT,
        .baud = UBRR_VALUE,
        .use2X = USE_2X,
    };

    usart0(config);
}

static void loop(Task* task) {
    if(usart0DataRegisterEmpty()) {
        Stream* stream = task->inputStreams[mData.currentInputStream];
        uint8_t data;

        if((stream != NULL) && streamPop(stream, &data)) {
            usart0Push(data);
        } else {
            mData.currentInputStream = (mData.currentInputStream + 1) % task->inputStreamCount;
        }
    }

    if(usart0ReceiveComplete()) {
        const uint8_t data = usart0Pop();

        for(uint8_t i = 0; i < task->outputStreamCount; i++) {
            Stream* stream = task->outputStreams[i];

            if(stream != NULL) {
                streamPush(stream, data);
            }
        }
    }
}
