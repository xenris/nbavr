#include "main.hpp"

#include <nbavr.cpp>

void main() {
    typedef TimerCounter1 clockTimer;
    typedef PinB5 ledPin;
    typedef Usart0 serialUsart;

    ClockT<clockTimer> clock;

    StreamBuffer<char, 30> stdout;
    StreamBuffer<char, 10> stdin;
    StreamBuffer<uint8_t, 1> stream;

    Serial<serialUsart> serial(stdout, stdin);
    Flash<ledPin> flash(clock, stdin);
    Task1 task1(clock, stream, stdout);
    Task2 task2(clock, stream);

    Task* tasks[] = {&task1, &task2, &flash, &serial};

    nbavr(clock, tasks);
}
