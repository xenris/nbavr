#include "main.hpp"

#include <nbavr.cpp>

void main() {
    typedef TimerCounter1 systemTimer;
    typedef PinC4 lcdD4;
    typedef PinC5 lcdD5;
    typedef PinD6 lcdD6;
    typedef PinD7 lcdD7;
    typedef PinD5 lcdRW;
    typedef PinD4 lcdRS;
    typedef PinB1 lcdE;

    StreamBuffer<char, 30> lcdout;

    LCD<lcdD4, lcdD5, lcdD6, lcdD7, lcdRW, lcdRS, lcdE> lcd(lcdout);
    Hello hello(lcdout);

    Task* tasks[] = {&hello, &lcd};

    NBAVR<systemTimer> nbavr(tasks);
}
