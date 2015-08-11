#include "serial.h"

// setbaud.h provides UBRRH_VALUE, UBRRL_VALUE, and USE_2X.
#include <util/setbaud.h>

void serialPutChar(char c, FILE* stream);
char serialGetChar(FILE* stream);

bool serialTask(void* data, uint32_t millis);

static RingBuffer mOutBuffer;
static RingBuffer mInBuffer;
static FILE mSerialFILE;

void serialInit(TaskManager* taskManager) {
    // Set baud rate as defined by BAUD.
    UBRR0H = UBRRH_VALUE;
    UBRR0L = UBRRL_VALUE;

    // Use 2x rate if needed.
    #if USE_2X
        UCSR0A |= _BV(U2X0);
    #else
        UCSR0A &= (uint8_t)~(_BV(U2X0));
    #endif

    // 8-bit data packets.
    UCSR0C = _BV(UCSZ01) | _BV(UCSZ00);
    // Enable RX, TX.
    UCSR0B = _BV(RXEN0) | _BV(TXEN0);

    taskManagerAddTask(taskManager, serialTask, 0, "serialTask", PRIORITY_HIGH);
}

void serialStdioInit() {
    fdev_setup_stream(&mSerialFILE, serialPutChar, serialGetChar, _FDEV_SETUP_RW);

    stdin = &mSerialFILE;
    stdout = &mSerialFILE;
    stderr = &mSerialFILE;
}

bool serialTask(void* data, uint32_t millis) {
    (void)data;
    (void)millis;

    if(UCSR0A & _BV(UDRE0)) {
        uint8_t data;

        if(ringBufferPop(&mOutBuffer, &data)) {
            UDR0 = data;
        }
    }

    if(UCSR0A & _BV(RXC0)) {
        const uint8_t data = UDR0;

        ringBufferPush(&mInBuffer, data);
    }

    return true;
}

bool serialSendByte(uint8_t c) {
    return ringBufferPush(&mOutBuffer, c);
}

bool serialReceiveByte(uint8_t* c) {
    return ringBufferPop(&mInBuffer, c);
}

void serialPutChar(char c, FILE* stream) {
    if(c == '\n') {
        serialPutChar('\r', stream);
    }

    if(serialSendByte(c)) {
        return;
    }
}

// XXX This function blocks indefinitely.
char serialGetChar(FILE* stream __attribute__ ((unused))) {
    uint8_t c;

    while(!serialReceiveByte(&c));

    c = (c == '\r') ? '\n' : c;

    return (char)c;
}
