#include "main.hpp"

#include <nbavr.cpp>

void main() {
    typedef PinB5 ledPin;
    typedef TimerCounter1 systemTimer;
    typedef Usart0 serialUsart;

    StreamBuffer<char, 40> stdout;
    StreamBuffer<char, 0> stdin;

    Serial<serialUsart> serial(stdout, stdin);
    Hello hello(stdout);
    Flash<ledPin> flash;

    Task* tasks[] = {&serial, &hello, &flash};

    NBAVR<systemTimer> nbavr(tasks);
}
