#ifndef ATMEGA328P_H
#define ATMEGA328P_H

#define HARDWARE_DEFINED

static inline void setupSystemClock() {
    // Enable compare match interrupt.
    TIMSK1 |= _BV(OCIE1A);
    // Set compare match point.
    OCR1A = 16000;
    // Enable clock with no prescaling, and waveform mode 4 (CTC).
    TCCR1B = _BV(CS10) | _BV(WGM12);
}

#define tickInterrupt ISR(TIMER1_COMPA_vect)
#define MS_PER_TICK 1

static inline void enableUsart() {
    // Set baud rate as defined by BAUD.
    UBRR0 = UBRR_VALUE;

    // Use 2x baud rate if needed.
    #if USE_2X
        UCSR0A |= _BV(U2X0);
    #else
        UCSR0A &= ~_BV(U2X0);
    #endif

    // 8-bit data packets.
    UCSR0C = _BV(UCSZ01) | _BV(UCSZ00);
    // Enable RX, TX. No interrupts.
    UCSR0B = _BV(RXEN0) | _BV(TXEN0);
}

#define usartPush(d) UDR0 = d
#define usartPop() UDR0
#define usartDataRegisterEmpty() UCSR0A & _BV(UDRE0)
#define usartReceiveComplete() UCSR0A & _BV(RXC0)

#endif
