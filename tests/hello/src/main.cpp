#include "main.hpp"

#include <nbavr.cpp>

void main() {
    typedef PinB5 ledPin;
    typedef TimerCounter1 clockTimer;
    typedef Usart0 serialUsart;

    ClockT<clockTimer> clock;

    StreamBuffer<char, 40> stdout;
    StreamBuffer<char, 0> stdin;

    Serial<serialUsart> serial(stdout, stdin);
    Hello hello(clock, stdout);
    Flash<ledPin> flash(clock);

    Task* tasks[] = {&serial, &hello, &flash};

    nbavr(clock, tasks);
}
