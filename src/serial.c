#include "serial.h"

static struct {
    Stream* currentInput;
    uint8_t nextIndex;
} mData;

static void setup(Task* task);
static void loop(Task* task);

Task serialTask = {
    .data = &mData,
    .dataSize = sizeof(mData),
    .setup = setup,
    .loop = loop,
    .priority = PRIORITY_LOW,
};

static void setup(Task* task) {
    USART0Config config = {
        .receiverEnable = true,
        .transmitterEnable = true,
        .characterSize = USART0_8_BIT,
        .baud = UBRR_VALUE,
        .use2X = USE_2X,
        .dataRegisterEmptyIntEnable = true,
        .rxCompleteIntEnable = true,
    };

    usart0(config);
}

static void loop(Task* task) {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        if(task->inputStreamCount > 0) {
            if(streamHasData(mData.currentInput)) {
                usart0DataRegisterEmptyInterruptEnable(true);
            } else {
                mData.nextIndex = (mData.nextIndex + 1) % task->inputStreamCount;
                mData.currentInput = task->inputStreams[mData.nextIndex];
            }
        }
    }
}

ISR(USART_UDRE_vect) {
    uint8_t data;

    if(streamPop(mData.currentInput, &data)) {
        usart0Push(data);
    } else {
        usart0DataRegisterEmptyInterruptEnable(false);
    }
}

ISR(USART_RX_vect) {
    const uint8_t data = usart0Pop();

    for(uint8_t i = 0; i < serialTask.outputStreamCount; i++) {
        Stream* stream = serialTask.outputStreams[i];

        streamPush(stream, data);
    }
}
