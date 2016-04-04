#ifndef NBAVR_DIGITALIO_H
#define NBAVR_DIGITALIO_H

#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>

typedef enum {
    #ifdef PINA
        PortA = (uint16_t)&PINA,
    #endif
    #ifdef PINB
        PortB = (uint16_t)&PINB,
    #endif
    #ifdef PINC
        PortC = (uint16_t)&PINC,
    #endif
    #ifdef PIND
        PortD = (uint16_t)&PIND,
    #endif
} Port;

typedef enum {
    #ifdef PINA0
        PinA0 = (PortA << 8) | PINA0,
    #endif
    #ifdef PINA1
        PinA1 = (PortA << 8) | PINA1,
    #endif
    #ifdef PINA2
        PinA2 = (PortA << 8) | PINA2,
    #endif
    #ifdef PINA3
        PinA3 = (PortA << 8) | PINA3,
    #endif
    #ifdef PINA4
        PinA4 = (PortA << 8) | PINA4,
    #endif
    #ifdef PINA5
        PinA5 = (PortA << 8) | PINA5,
    #endif
    #ifdef PINA6
        PinA6 = (PortA << 8) | PINA6,
    #endif
    #ifdef PINA7
        PinA7 = (PortA << 8) | PINA7,
    #endif
    #ifdef PINB0
        PinB0 = (PortB << 8) | PINB0,
    #endif
    #ifdef PINB1
        PinB1 = (PortB << 8) | PINB1,
    #endif
    #ifdef PINB2
        PinB2 = (PortB << 8) | PINB2,
    #endif
    #ifdef PINB3
        PinB3 = (PortB << 8) | PINB3,
    #endif
    #ifdef PINB4
        PinB4 = (PortB << 8) | PINB4,
    #endif
    #ifdef PINB5
        PinB5 = (PortB << 8) | PINB5,
    #endif
    #ifdef PINB6
        PinB6 = (PortB << 8) | PINB6,
    #endif
    #ifdef PINB7
        PinB7 = (PortB << 8) | PINB7,
    #endif
    #ifdef PINC0
        PinC0 = (PortC << 8) | PINC0,
    #endif
    #ifdef PINC1
        PinC1 = (PortC << 8) | PINC1,
    #endif
    #ifdef PINC2
        PinC2 = (PortC << 8) | PINC2,
    #endif
    #ifdef PINC3
        PinC3 = (PortC << 8) | PINC3,
    #endif
    #ifdef PINC4
        PinC4 = (PortC << 8) | PINC4,
    #endif
    #ifdef PINC5
        PinC5 = (PortC << 8) | PINC5,
    #endif
    #ifdef PINC6
        PinC6 = (PortC << 8) | PINC6,
    #endif
    #ifdef PINC7
        PinC7 = (PortC << 8) | PINC7,
    #endif
    #ifdef PIND0
        PinD0 = (PortD << 8) | PIND0,
    #endif
    #ifdef PIND1
        PinD1 = (PortD << 8) | PIND1,
    #endif
    #ifdef PIND2
        PinD2 = (PortD << 8) | PIND2,
    #endif
    #ifdef PIND3
        PinD3 = (PortD << 8) | PIND3,
    #endif
    #ifdef PIND4
        PinD4 = (PortD << 8) | PIND4,
    #endif
    #ifdef PIND5
        PinD5 = (PortD << 8) | PIND5,
    #endif
    #ifdef PIND6
        PinD6 = (PortD << 8) | PIND6,
    #endif
    #ifdef PIND7
        PinD7 = (PortD << 8) | PIND7,
    #endif
} Pin;

typedef enum {
    Input,
    Output,
} Direction;

typedef enum {
    Low,
    High,
} Value;

void pinDirection(Pin pin, Direction direction) __attribute__((always_inline));
Value pinValue(Pin pin) __attribute__((always_inline));
void pinSet(Pin pin, Value value) __attribute__((always_inline));
void pinPullup(Pin pin, bool b) __attribute__((always_inline));
void pinToggle(Pin pin) __attribute__((always_inline));
void portDirection(Port port, uint8_t directions) __attribute__((always_inline));
uint8_t portValue(Port port) __attribute__((always_inline));
void portSet(Port port, uint8_t values) __attribute__((always_inline));
void portPullup(Port port, uint8_t values) __attribute__((always_inline));
void portToggle(Port port, uint8_t selection) __attribute__((always_inline));

#endif
