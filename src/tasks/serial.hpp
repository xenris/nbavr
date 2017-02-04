#ifndef NBAVR_SERIAL_HPP
#define NBAVR_SERIAL_HPP

#define BAUD 9600

#include <nbavr.hpp>
#include <util/setbaud.h>

template <class Usart>
class Serial : public Task {
    Stream<char>& stdout;
    Stream<char>& stdin;

public:
    Serial(Stream<char>& stdout, Stream<char>& stdin) : stdout(stdout), stdin(stdin) {
        static_assert(Usart::getHardwareType() == HardwareType::Usart, "Serial requires a Usart");

        stdout.setCallback(streamCallback, this);

        typename Usart::Config config;
        config.receiverEnable = true,
        config.transmitterEnable = true,
        config.baud = UBRR_VALUE,
        config.use2X = USE_2X,
        config.rxCompleteIntEnable = true,
        config.rxCompleteInterrupt = usartRxComplete;
        config.rxCompleteInterruptData = this;
        config.dataRegisterEmptyInterrupt = usartDataRegisterEmpty;
        config.dataRegisterEmptyInterruptData = this;

        Usart::apply(config);
    }

private:
    void loop() override {
        if(!stdout.empty()) {
            Usart::dataRegisterEmptyInterruptEnable(true);
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
            Usart::dataRegisterEmptyInterruptEnable(false);
        }
    }

    static void streamCallback(void* data) {
        Serial* self = reinterpret_cast<Serial*>(data);

        self->wake();
    }
};

#endif
