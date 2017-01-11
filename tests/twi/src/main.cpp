#include "main.hpp"

#include <nbavr.cpp>

void main() {
    TimerCounter1 timerCounter1;
    Usart0 usart0;
    ClockT<TimerCounter1> clock(timerCounter1);

    StreamBuffer<char, 30> stdout;
    StreamBuffer<char, 0> stdin;
    StreamBuffer<TWI::Action, 2> twiout;

    TWI twi(twiout);
    Serial<Usart0> serial(usart0, stdout, stdin);
    LightSensor lightSensor(clock, stdout, twiout);

    Task* tasks[] = {&lightSensor, &twi, &serial, nullptr};

    nbavr(clock, tasks);
}
