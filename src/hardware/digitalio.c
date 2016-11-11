#include "digitalio.h"

#define PINN_REGISTER_OFFSET 0
#define DDRN_REGISTER_OFFSET 1
#define PORTN_REGISTER_OFFSET 2

#define PIN_REG(p) (volatile uint8_t*)((uint8_t)p.value + PINN_REGISTER_OFFSET)
#define DDR_REG(p) (volatile uint8_t*)((uint8_t)p.value + DDRN_REGISTER_OFFSET)
#define PORT_REG(p) (volatile uint8_t*)((uint8_t)p.value + PORTN_REGISTER_OFFSET)

#define PIN_ID(p) (p.value >> 8)

void pinDirection(Pin pin, Direction direction) {
    volatile uint8_t* ddrn = DDR_REG(pin);
    uint8_t p = PIN_ID(pin);

    if(direction == Output) {
        *ddrn |= _BV(p);
    } else {
        *ddrn &= ~_BV(p);
    }
}

Value pinValue(Pin pin) {
    volatile uint8_t* pinn = PIN_REG(pin);
    uint8_t p = PIN_ID(pin);

    return ((*pinn) & _BV(p)) ? High : Low;
}

void pinSet(Pin pin, Value value) {
    volatile uint8_t* portn = PORT_REG(pin);
    uint8_t p = PIN_ID(pin);

    if(value == High) {
        *portn |= _BV(p);
    } else {
        *portn &= ~_BV(p);
    }
}

void pinPullup(Pin pin, bool b) {
    pinSet(pin, b ? High : Low);
}

// Writing a logic one to PINxn toggles PORTxn.
void pinToggle(Pin pin) {
    volatile uint8_t* pinn = PIN_REG(pin);
    uint8_t p = PIN_ID(pin);

    *pinn |= _BV(p);
}

void portDirection(Port port, uint8_t directions) {
    volatile uint8_t* ddrn = DDR_REG(port);

    *ddrn = directions;
}

uint8_t portValue(Port port) {
    volatile uint8_t* pinn = PIN_REG(port);

    return *pinn;
}

void portSet(Port port, uint8_t values) {
    volatile uint8_t* portn = PORT_REG(port);

    *portn = values;
}

void portPullup(Port port, uint8_t values) {
    portSet(port, values);
}

// Writing a logic one to PINxn toggles PORTxn.
void portToggle(Port port, uint8_t selection) {
    volatile uint8_t* pinn = PIN_REG(port);

    *pinn = selection;
}
