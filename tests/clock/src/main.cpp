#include "main.hpp"

INCLUDE_DEFAULT_CALLBACK;
INCLUDE_TIMERCOUNTER_OUTPUT_CALLBACK(1, A);
INCLUDE_TIMERCOUNTER_OUTPUT_CALLBACK(1, B);
INCLUDE_TIMERCOUNTER_OVERFLOW_CALLBACK(1);

void main() {
    typedef PinB5 ledPin;
    typedef TimerCounter1 systemTimer;

    Flash<ledPin> flash;

    Task* tasks[] = {&flash};

    NBAVR<systemTimer> nbavr(tasks);
}
