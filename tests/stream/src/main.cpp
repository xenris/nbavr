#include "main.hpp"

#include <nbavr.cpp>

void main() {
    TimerCounter1 timerCounter1;
    PinB5 ledPin;
    Usart0 usart0;
    ClockT<TimerCounter1> clock(timerCounter1);

    StreamBuffer<char, 30> stdout;
    StreamBuffer<char, 10> stdin;
    StreamBuffer<uint8_t, 1> stream;

    Serial<Usart0> serial(usart0, stdout, stdin);
    Flash flash(clock, stdin, ledPin);
    Task1 task1(clock, stream, stdout);
    Task2 task2(clock, stream);

    Task* tasks[] = {&task1, &task2, &flash, &serial, nullptr};

    nbavr(clock, tasks);
}
