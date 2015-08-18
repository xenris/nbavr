#include "serial.h"

// setbaud.h provides UBRRH_VALUE, UBRRL_VALUE, and USE_2X.
#include <util/setbaud.h>

typedef struct {
    bool initialised;
    OutputStream** outputStreams;
    InputStream** inputStreams;

    uint8_t currentInputStream;
    uint8_t currentOutputStream;
} SerialData;

bool serialTask(void* data, uint32_t millis);

const char* serialInit(TaskManager* taskManager) {
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

    const char* serialTaskId = "serialTask";

    taskManagerAddTask(taskManager, serialTask, sizeof(SerialData), serialTaskId, PRIORITY_DRIVER);

    return serialTaskId;
}

bool serialTask(void* data, uint32_t millis) {
    SerialData* serialData = data;
    (void)millis;

    if(!serialData->initialised) {
        serialData->initialised = true;
        serialData->outputStreams = getOutputStreams();
        serialData->inputStreams = getInputStreams();
    }

    if(UCSR0A & _BV(UDRE0)) {
        InputStream* inputStream = serialData->inputStreams[serialData->currentInputStream];
        uint8_t data;

        if((inputStream != NULL) && inputStreamPop(inputStream, &data)) {
            UDR0 = data;
        } else {
            serialData->currentInputStream = (serialData->currentInputStream + 1) % 6;
        }
    }

    if(UCSR0A & _BV(RXC0)) {
        const uint8_t data = UDR0;

        for(uint8_t i = 0; i < 6; i++) {
            OutputStream* outputStream = serialData->outputStreams[i];

            if(outputStream != NULL) {
                outputStreamPush(outputStream, data);
            }
        }
    }

    return true;
}
