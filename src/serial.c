#include "serial.h"

// setbaud.h provides UBRRH_VALUE, UBRRL_VALUE, and USE_2X.
#include <util/setbaud.h>

void enableDataRegisterEmptyInterrupts();
void disableDataRegisterEmptyInterrupts();

RingBuffer mOutBuffer;
RingBuffer mInBuffer;

void serialInit() {
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
    // Enable RX, TX, and RX interrupt.
    UCSR0B = _BV(RXEN0) | _BV(TXEN0) | _BV(RXCIE0);
}

bool serialSendByte(uint8_t c) {
    bool success;

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        success = ringBufferPush(&mOutBuffer, c);
    }

    enableDataRegisterEmptyInterrupts();

    return success;
}

bool serialReceiveByte(uint8_t* c) {
    bool success;

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        success = ringBufferPop(&mInBuffer, c);
    }

    return success;
}

void enableDataRegisterEmptyInterrupts() {
    UCSR0B |= _BV(UDRIE0);
}

void disableDataRegisterEmptyInterrupts() {
    UCSR0B &= (uint8_t)~(_BV(UDRIE0));
}

#ifdef INCLUDE_SERIAL

ISR(USART_RX_vect) {
    const uint8_t data = UDR0;
    ringBufferPush(&mInBuffer, data);
}

ISR(USART_UDRE_vect) {
    uint8_t data;

    if(ringBufferPop(&mOutBuffer, &data)) {
        UDR0 = data;
    } else {
        disableDataRegisterEmptyInterrupts();
    }
}

#endif
