#include "serial.h"

static void setup(Task* task);
static void loop(Task* task);

Task serialTask = {
    .setup = setup,
    .loop = loop,
    .priority = PRIORITY_LOW,
};

Stream stdout = streamInit(30);
Stream stdin = streamInit(10);

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
    if(streamHasData(&stdout)) {
        serialFlush();
    }
}

void serialFlush() {
    usart0DataRegisterEmptyInterruptEnable(true);
}

ISR(USART_UDRE_vect) {
    uint8_t data;

    if(streamPop(&stdout, &data)) {
        usart0Push(data);
    } else {
        usart0DataRegisterEmptyInterruptEnable(false);
    }
}

ISR(USART_RX_vect) {
    streamPush(&stdin, usart0Pop());
}
