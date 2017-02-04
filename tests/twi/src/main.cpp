#include "main.hpp"

#include <nbavr.cpp>

void main() {
    typedef TimerCounter1 clockTimer;
    typedef Usart0 serialUsart;

    ClockT<clockTimer> clock;

    StreamBuffer<char, 30> stdout;
    StreamBuffer<char, 0> stdin;
    StreamBuffer<TWI::Action, 2> twiout;

    TWI twi(twiout);
    Serial<serialUsart> serial(stdout, stdin);
    LightSensor lightSensor(clock, stdout, twiout);

    Task* tasks[] = {&lightSensor, &twi, &serial};

    nbavr(clock, tasks);
}
