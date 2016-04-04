#include "digitalio.h"

#define PINN_REGISTER_OFFSET 0
#define DDRN_REGISTER_OFFSET 1
#define PORTN_REGISTER_OFFSET 2

uint8_t* portToPINN(Port port) __attribute__((always_inline));
uint8_t* portToDDRN(Port port) __attribute__((always_inline));
uint8_t* portToPORTN(Port port) __attribute__((always_inline));
uint8_t* pinToPINN(Pin pin) __attribute__((always_inline));
uint8_t* pinToDDRN(Pin pin) __attribute__((always_inline));
uint8_t* pinToPORTN(Pin pin) __attribute__((always_inline));

void pinDirection(Pin pin, Direction direction) {
    volatile uint8_t* ddrn = pinToDDRN(pin);
    uint8_t p = pin;

    if(direction == Output) {
        *ddrn |= _BV(p);
    } else {
        *ddrn &= ~_BV(p);
    }
}

Value pinValue(Pin pin) {
    volatile uint8_t* pinn = pinToPINN(pin);
    uint8_t p = pin;

    return ((*pinn) & _BV(p)) ? High : Low;
}

void pinSet(Pin pin, Value value) {
    volatile uint8_t* portn = pinToPORTN(pin);
    uint8_t p = pin;

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
    volatile uint8_t* pinn = pinToPINN(pin);
    uint8_t p = pin;

    *pinn |= _BV(p);
}

void portDirection(Port port, uint8_t directions) {
    volatile uint8_t* ddrn = portToDDRN(port);

    *ddrn = directions;
}

uint8_t portValue(Port port) {
    volatile uint8_t* pinn = portToPINN(port);

    return *pinn;
}

void portSet(Port port, uint8_t values) {
    volatile uint8_t* portn = portToPORTN(port);

    *portn = values;
}

void portPullup(Port port, uint8_t values) {
    portSet(port, values);
}

// Writing a logic one to PINxn toggles PORTxn.
void portToggle(Port port, uint8_t selection) {
    volatile uint8_t* pinn = portToPINN(port);

    *pinn = selection;
}

uint8_t* portToPINN(Port port) {
    return (uint8_t*)port + PINN_REGISTER_OFFSET;
}

uint8_t* portToDDRN(Port port) {
    return (uint8_t*)port + DDRN_REGISTER_OFFSET;
}

uint8_t* portToPORTN(Port port) {
    return (uint8_t*)port + PORTN_REGISTER_OFFSET;
}

uint8_t* pinToPINN(Pin pin) {
    return (uint8_t*)(pin >> 8) + PINN_REGISTER_OFFSET;
}

uint8_t* pinToDDRN(Pin pin) {
    return (uint8_t*)(pin >> 8) + DDRN_REGISTER_OFFSET;
}

uint8_t* pinToPORTN(Pin pin) {
    return (uint8_t*)(pin >> 8) + PORTN_REGISTER_OFFSET;
}
