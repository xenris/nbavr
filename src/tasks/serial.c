#include "serial.h"

static void setup(void);
static void loop(void);
static void stdoutCallback();
static void dataRegEmptyCallback(void);
static void rxCompleteCallback(void);

Task serialTask = {
    .setup = setup,
    .loop = loop,
};

static Stream serialOut = streamInitCallback(30, stdoutCallback);
static Stream serialIn = streamInit(10);

Stream* stdout = &serialOut;
Stream* stdin = &serialIn;

static void setup(void) {
    Usart0Config config = {
        .receiverEnable = true,
        .transmitterEnable = true,
        .characterSize = Usart0CharacterSize8,
        .baud = UBRR_VALUE,
        .use2X = USE_2X,
        .dataRegisterEmptyCallback = dataRegEmptyCallback,
        .rxCompleteIntEnable = true,
        .rxCompleteCallback = rxCompleteCallback,
    };

    usart0(config);
}

static void loop(void) {
    if(streamHasData(stdout)) {
        serialFlush();
    }

    sleep(&serialTask);
}

static void stdoutCallback() {
    wake(&serialTask);
}

void serialFlush() {
    usart0DataRegisterEmptyInterruptEnable(true);
}

static void dataRegEmptyCallback(void) {
    uint8_t data;

    if(streamPop_(stdout, &data)) {
        usart0Push(data);
    } else {
        usart0DataRegisterEmptyInterruptEnable(false);
    }
}

static void rxCompleteCallback(void) {
    streamPush_(stdin, usart0Pop());
}
