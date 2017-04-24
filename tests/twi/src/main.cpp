#include "main.hpp"

#include <nbavr.cpp>

void main() {
    typedef TimerCounter1 systemTimer;
    typedef Usart0 serialUsart;

    StreamBuffer<char, 30> stdout;
    StreamBuffer<char, 0> stdin;
    StreamBuffer<TWI::Action, 2> twiout;

    TWI twi(twiout);
    Serial<serialUsart> serial(stdout, stdin);
    LightSensor lightSensor(stdout, twiout);

    Task* tasks[] = {&lightSensor, &twi, &serial};

    nbavr<systemTimer>(tasks);
}
