#include "main.hpp"

#include <nbavr.cpp>

void main() {
    PinB5 ledPin;
    TimerCounter1 timerCounter1;
    Usart0 usart0;
    ClockT<TimerCounter1> clock(timerCounter1);

    StreamBuffer<char, 40> stdout;
    StreamBuffer<char, 0> stdin;

    Serial<Usart0> serial(usart0, stdout, stdin);
    Hello hello(clock, stdout);
    Flash flash(clock, ledPin);

    Task* tasks[] = {&serial, &hello, &flash};

    nbavr(clock, tasks);
}
