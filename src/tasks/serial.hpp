#ifndef NBAVR_SERIAL_HPP
#define NBAVR_SERIAL_HPP

#define BAUD 9600

#include <nbavr.hpp>

#ifndef TEST
#include <util/setbaud.h>
#else
#define UBRR_VALUE 1
#define USE_2X 1
#endif

template <class Usart>
class Serial : public Task {
    Stream<char>& stdout;
    Stream<char>& stdin;

public:
    Serial(Stream<char>& stdout, Stream<char>& stdin) : stdout(stdout), stdin(stdin) {
        static_assert(Usart::getHardwareType() == HardwareType::Usart, "Serial requires a Usart");

        stdout.setCallback(streamCallback, this);

        atomic {
            Usart::receiverEnable(true);
            Usart::transmitterEnable(true);
            Usart::baud(UBRR_VALUE);
            Usart::use2X(USE_2X);
            Usart::rxCompleteIntEnable(true);
            Usart::rxCompleteCallback(usartRxComplete, this);
            Usart::dataRegisterEmptyCallback(usartDataRegisterEmpty, this);
        }
    }

private:
    void loop() override {
        if(!stdout.empty()) {
            Usart::dataRegisterEmptyIntEnable(true);
        }

        sleep();
    }

    static void usartRxComplete(void* data) {
        Serial* self = reinterpret_cast<Serial*>(data);

        self->stdin << Usart::pop();
    }

    static void usartDataRegisterEmpty(void* data) {
        Serial* self = reinterpret_cast<Serial*>(data);

        char d;

        if(self->stdout.pop_(&d)) {
            Usart::push(d);
        } else {
            Usart::dataRegisterEmptyIntEnable(false);
        }
    }

    static void streamCallback(void* data) {
        Serial* self = reinterpret_cast<Serial*>(data);

        self->wake();
    }
};

#endif
