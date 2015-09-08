#ifndef ATMEGA328P_H
#define ATMEGA328P_H

#define HARDWARE_DEFINED

static inline void setupSystemClock() {
    // No compare match. Normal waveform.
    TCCR0A = 0;
    // Normal waveform. clk/8 prescaler.
    TCCR0B = _BV(CS01);
    // Overflow interrupt.
    TIMSK0 = _BV(TOIE0);
}

#define tickInterrupt ISR(TIMER0_OVF_vect)
#define US_PER_TICK (256LL * 8LL * 1000000LL) / F_CPU

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
