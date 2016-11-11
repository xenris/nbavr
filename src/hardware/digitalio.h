#ifndef NBAVR_DIGITALIO_H
#define NBAVR_DIGITALIO_H

#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct __attribute__((packed)) {
    uint8_t value;
} Port;

typedef struct __attribute__((packed)) {
    // High byte for pin, Low byte for port.
    uint16_t value;
} Pin;

#ifdef PINA
    #define PortA ((Port){(uint16_t)&PINA})
#endif
#ifdef PINB
    #define PortB ((Port){(uint16_t)&PINB})
#endif
#ifdef PINC
    #define PortC ((Port){(uint16_t)&PINC})
#endif
#ifdef PIND
    #define PortD ((Port){(uint16_t)&PIND})
#endif

#ifdef PINA0
    #define PinA0 ((Pin){PINA0 << 8 | (uint8_t)(uint16_t)&PINA})
#endif
#ifdef PINA1
    #define PinA1 ((Pin){PINA1 << 8 | (uint8_t)(uint16_t)&PINA})
#endif
#ifdef PINA2
    #define PinA2 ((Pin){PINA2 << 8 | (uint8_t)(uint16_t)&PINA})
#endif
#ifdef PINA3
    #define PinA3 ((Pin){PINA3 << 8 | (uint8_t)(uint16_t)&PINA})
#endif
#ifdef PINA4
    #define PinA4 ((Pin){PINA4 << 8 | (uint8_t)(uint16_t)&PINA})
#endif
#ifdef PINA5
    #define PinA5 ((Pin){PINA5 << 8 | (uint8_t)(uint16_t)&PINA})
#endif
#ifdef PINA6
    #define PinA6 ((Pin){PINA6 << 8 | (uint8_t)(uint16_t)&PINA})
#endif
#ifdef PINA7
    #define PinA7 ((Pin){PINA7 << 8 | (uint8_t)(uint16_t)&PINA})
#endif
#ifdef PINB0
    #define PinB0 ((Pin){PINB0 << 8 | (uint8_t)(uint16_t)&PINB})
#endif
#ifdef PINB1
    #define PinB1 ((Pin){PINB1 << 8 | (uint8_t)(uint16_t)&PINB})
#endif
#ifdef PINB2
    #define PinB2 ((Pin){PINB2 << 8 | (uint8_t)(uint16_t)&PINB})
#endif
#ifdef PINB3
    #define PinB3 ((Pin){PINB3 << 8 | (uint8_t)(uint16_t)&PINB})
#endif
#ifdef PINB4
    #define PinB4 ((Pin){PINB4 << 8 | (uint8_t)(uint16_t)&PINB})
#endif
#ifdef PINB5
    #define PinB5 ((Pin){PINB5 << 8 | (uint8_t)(uint16_t)&PINB})
#endif
#ifdef PINB6
    #define PinB6 ((Pin){PINB6 << 8 | (uint8_t)(uint16_t)&PINB})
#endif
#ifdef PINB7
    #define PinB7 ((Pin){PINB7 << 8 | (uint8_t)(uint16_t)&PINB})
#endif
#ifdef PINC0
    #define PinC0 ((Pin){PINC0 << 8 | (uint8_t)(uint16_t)&PINC})
#endif
#ifdef PINC1
    #define PinC1 ((Pin){PINC1 << 8 | (uint8_t)(uint16_t)&PINC})
#endif
#ifdef PINC2
    #define PinC2 ((Pin){PINC2 << 8 | (uint8_t)(uint16_t)&PINC})
#endif
#ifdef PINC3
    #define PinC3 ((Pin){PINC3 << 8 | (uint8_t)(uint16_t)&PINC})
#endif
#ifdef PINC4
    #define PinC4 ((Pin){PINC4 << 8 | (uint8_t)(uint16_t)&PINC})
#endif
#ifdef PINC5
    #define PinC5 ((Pin){PINC5 << 8 | (uint8_t)(uint16_t)&PINC})
#endif
#ifdef PINC6
    #define PinC6 ((Pin){PINC6 << 8 | (uint8_t)(uint16_t)&PINC})
#endif
#ifdef PINC7
    #define PinC7 ((Pin){PINC7 << 8 | (uint8_t)(uint16_t)&PINC})
#endif
#ifdef PIND0
    #define PinD0 ((Pin){PIND0 << 8 | (uint8_t)(uint16_t)&PIND})
#endif
#ifdef PIND1
    #define PinD1 ((Pin){PIND1 << 8 | (uint8_t)(uint16_t)&PIND})
#endif
#ifdef PIND2
    #define PinD2 ((Pin){PIND2 << 8 | (uint8_t)(uint16_t)&PIND})
#endif
#ifdef PIND3
    #define PinD3 ((Pin){PIND3 << 8 | (uint8_t)(uint16_t)&PIND})
#endif
#ifdef PIND4
    #define PinD4 ((Pin){PIND4 << 8 | (uint8_t)(uint16_t)&PIND})
#endif
#ifdef PIND5
    #define PinD5 ((Pin){PIND5 << 8 | (uint8_t)(uint16_t)&PIND})
#endif
#ifdef PIND6
    #define PinD6 ((Pin){PIND6 << 8 | (uint8_t)(uint16_t)&PIND})
#endif
#ifdef PIND7
    #define PinD7 ((Pin){PIND7 << 8 | (uint8_t)(uint16_t)&PIND})
#endif

typedef enum __attribute__((packed)) {
    Input,
    Output,
} Direction;

typedef enum __attribute__((packed)) {
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
