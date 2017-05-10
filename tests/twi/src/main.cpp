#include "main.hpp"

INCLUDE_DEFAULT_CALLBACK;
INCLUDE_TIMERCOUNTER_OUTPUT_CALLBACK(1, A);
INCLUDE_TIMERCOUNTER_OUTPUT_CALLBACK(1, B);
INCLUDE_TIMERCOUNTER_OVERFLOW_CALLBACK(1);
INCLUDE_USART_CALLBACK(0, RX);
INCLUDE_USART_CALLBACK(0, DE);

void main() {
    typedef TimerCounter1 systemTimer;
    typedef Usart0 serialUsart;

    StreamBuffer<char, 30> stdout;
    StreamBuffer<char, 0> stdin;
    StreamBuffer<TWI::Action, 2> twiout;

    TWI twi(twiout);
    Serial<serialUsart> serial(stdout, stdin);
    LightSensor lightSensor(stdout, twiout);

    Task* tasks[] = {&lightSensor, &twi, &serial};

    NBAVR<systemTimer> nbavr(tasks);
}
