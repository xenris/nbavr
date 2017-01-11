#ifndef NBAVR_SERIAL_HPP
#define NBAVR_SERIAL_HPP

#define BAUD 9600

#include <nbavr.hpp>
#include <util/setbaud.h>

template <class U>
class Serial : public Task {
    U& usart;
    Stream<char>& stdout;
    Stream<char>& stdin;

    public:

    Serial(U usart, Stream<char>& stdout, Stream<char>& stdin)
    : usart(usart), stdout(stdout), stdin(stdin) {
        stdout.setCallback(streamCallback, this);

        typename U::Config config;
        config.receiverEnable = true,
        config.transmitterEnable = true,
        config.baud = UBRR_VALUE,
        config.use2X = USE_2X,
        config.rxCompleteIntEnable = true,
        config.rxCompleteInterrupt = usartRxComplete;
        config.rxCompleteInterruptData = this;
        config.dataRegisterEmptyInterrupt = usartDataRegisterEmpty;
        config.dataRegisterEmptyInterruptData = this;

        usart.apply(config);
    }

    protected:

    void loop() override {
        if(!stdout.empty()) {
            usart.dataRegisterEmptyInterruptEnable(true);
        }

        sleep();
    }

    private:

    static void usartRxComplete(void* data) {
        Serial* self = (Serial*)data;

        self->stdin << self->usart.pop();
    }

    static void usartDataRegisterEmpty(void* data) {
        Serial* self = (Serial*)data;

        char d;

        if(self->stdout.pop_(&d)) {
            self->usart.push(d);
        } else {
            self->usart.dataRegisterEmptyInterruptEnable(false);
        }
    }

    static void streamCallback(void* data) {
        Serial* self = (Serial*)data;

        self->wake();
    }
};

#endif
