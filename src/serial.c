#include "serial.h"

static void setup(void);
static void loop(void);
static void stdoutCallback();

Task serialTask = {
    .setup = setup,
    .loop = loop,
    .priority = PRIORITY_LOW,
};

static Stream serialOut = streamInitCallback(30, stdoutCallback);
static Stream serialIn = streamInit(10);

Stream* stdout = &serialOut;
Stream* stdin = &serialIn;

static void setup(void) {
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

static void loop(void) {
    if(streamHasData(stdout)) {
        serialFlush();
    }

    serialTask.priority = PRIORITY_LOW;
}

static void stdoutCallback() {
    serialTask.priority = PRIORITY_DRIVER;
}

void serialFlush() {
    usart0DataRegisterEmptyInterruptEnable(true);
}

ISR(USART_UDRE_vect) {
    uint8_t data;

    if(streamPop(stdout, &data)) {
        usart0Push(data);
    } else {
        usart0DataRegisterEmptyInterruptEnable(false);
    }
}

ISR(USART_RX_vect) {
    streamPush(stdin, usart0Pop());
}
