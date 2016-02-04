#ifndef NBAVR_DIGITALIO_H
#define NBAVR_DIGITALIO_H

typedef enum {
    PortB,
    PortC,
    PortD,
} Port;

typedef enum {
    PinB0,
    PinB1,
    PinB2,
    PinB3,
    PinB4,
    PinB5,
    PinB6,
    PinB7,
    PinC0,
    PinC1,
    PinC2,
    PinC3,
    PinC4,
    PinC5,
    PinC6,
    PinD0,
    PinD1,
    PinD2,
    PinD3,
    PinD4,
    PinD5,
    PinD6,
    PinD7,
} Pin;

typedef enum {
    Input,
    Output,
} Direction;

typedef enum {
    Low,
    High,
} Value;

static inline void pinDirection(Pin pin, Direction direction) {
    volatile uint8_t* ddrn;
    uint8_t p;

    if(pin <= PinB7) {
        ddrn = &DDRB;
        p = pin;
    } else if(pin <= PinC6) {
        ddrn = &DDRC;
        p = pin - PinC0;
    } else {
        ddrn = &DDRD;
        p = pin - PinD0;
    }

    if(direction == Output) {
        *ddrn |= _BV(p);
    } else {
        *ddrn &= ~_BV(p);
    }
}

static inline Value pinValue(Pin pin) {
    volatile uint8_t* pinn;
    uint8_t p;

    if(pin <= PinB7) {
        pinn = &PINB;
        p = pin;
    } else if(pin <= PinC6) {
        pinn = &PINC;
        p = pin - PinC0;
    } else {
        pinn = &PIND;
        p = pin - PinD0;
    }

    return ((*pinn) & _BV(p)) ? High : Low;
}

static inline void pinSet(Pin pin, Value value) {
    volatile uint8_t* portn;
    uint8_t p;

    if(pin <= PinB7) {
        portn = &PORTB;
        p = pin;
    } else if(pin <= PinC6) {
        portn = &PORTC;
        p = pin - PinC0;
    } else {
        portn = &PORTD;
        p = pin - PinD0;
    }

    if(value == High) {
        *portn |= _BV(p);
    } else {
        *portn &= ~_BV(p);
    }
}

static inline void pinPullup(Pin pin, bool b) {
    pinSet(pin, b ? High : Low);
}

// Writing a logic one to PINxn toggles PORTxn.
// (atmega328p documentation 13.2.2)
static inline void pinToggle(Pin pin) {
    volatile uint8_t* pinn;
    uint8_t p;

    if(pin <= PinB7) {
        pinn = &PINB;
        p = pin;
    } else if(pin <= PinC6) {
        pinn = &PINC;
        p = pin - PinC0;
    } else {
        pinn = &PIND;
        p = pin - PinD0;
    }

    *pinn |= _BV(p);
}

static inline void portDirection(Port port, uint8_t directions) {
    volatile uint8_t* ddrn;

    if(port == PortB) {
        ddrn = &DDRB;
    } else if(port == PortC) {
        ddrn = &DDRC;
    } else {
        ddrn = &DDRD;
    }

    *ddrn = directions;
}

static inline uint8_t portValue(Port port) {
    volatile uint8_t* pinn;

    if(port == PortB) {
        pinn = &PINB;
    } else if(port == PortC) {
        pinn = &PINC;
    } else {
        pinn = &PIND;
    }

    return *pinn;
}

static inline void portSet(Port port, uint8_t values) {
    volatile uint8_t* portn;

    if(port == PortB) {
        portn = &PORTB;
    } else if(port == PortC) {
        portn = &PORTC;
    } else {
        portn = &PORTD;
    }

    *portn = values;
}

static inline void portPullup(Port port, uint8_t values) {
    portSet(port, values);
}

// Writing a logic one to PINxn toggles PORTxn.
// (atmega328p documentation 13.2.2)
static inline void portToggle(Port port, uint8_t selection) {
    volatile uint8_t* pinn;

    if(port == PortB) {
        pinn = &PINB;
    } else if(port == PortC) {
        pinn = &PINC;
    } else {
        pinn = &PIND;
    }

    *pinn = selection;
}

#endif
