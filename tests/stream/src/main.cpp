#include "main.hpp"

INCLUDE_DEFAULT_CALLBACK;
INCLUDE_TIMERCOUNTER_OUTPUT_CALLBACK(1, A);
INCLUDE_TIMERCOUNTER_OUTPUT_CALLBACK(1, B);
INCLUDE_TIMERCOUNTER_OVERFLOW_CALLBACK(1);
INCLUDE_USART_CALLBACK(0, RX);
INCLUDE_USART_CALLBACK(0, DE);

void main() {
    typedef TimerCounter1 systemTimer;
    typedef PinB5 ledPin;
    typedef Usart0 serialUsart;

    StreamBuffer<char, 30> stdout;
    StreamBuffer<char, 10> stdin;
    StreamBuffer<uint8_t, 1> stream;

    Serial<serialUsart> serial(stdout, stdin);
    Flash<ledPin> flash(stdin);
    Task1 task1(stream, stdout);
    Task2 task2(stream);

    Task* tasks[] = {&task1, &task2, &flash, &serial};

    NBAVR<systemTimer> nbavr(tasks);
}
