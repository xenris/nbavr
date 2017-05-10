#include <nbavr.hpp>

INCLUDE_DEFAULT_CALLBACK;

void main() {
    typedef PinB5 ledPin;

    ledPin::direction(ledPin::Direction::Output);

    while(true) {
        block ledPin::toggle();
        _delay_ms(500);
    }
}
