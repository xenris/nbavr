#include "main.hpp"

#include <nbavr.cpp>

void main() {
    typedef PinB5 ledPin;
    typedef TimerCounter1 systemTimer;

    Flash<ledPin> flash;

    Task* tasks[] = {&flash};

    NBAVR<systemTimer> nbavr(tasks);
}
