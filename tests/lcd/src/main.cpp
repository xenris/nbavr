#include "main.hpp"

#include <nbavr.cpp>

void main() {
    TimerCounter1 timerCounter1;
    PinB5 ledPin;
    PinC4 pinD4;
    PinC5 pinD5;
    PinD6 pinD6;
    PinD7 pinD7;
    PinD5 pinRW;
    PinD4 pinRS;
    PinB1 pinE;
    ClockT<TimerCounter1> clock(timerCounter1);

    StreamBuffer<char, 30> lcdout;

    LCD lcd(clock, lcdout, pinD4, pinD5, pinD6, pinD7, pinRW, pinRS, pinE);
    Hello hello(clock, lcdout);
    Flash flash(clock, ledPin);

    Task* tasks[] = {&hello, &flash, &lcd, nullptr};

    nbavr(clock, tasks);
}
