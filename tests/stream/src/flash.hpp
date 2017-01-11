#ifndef FLASH_HPP
#define FLASH_HPP

#include <nbavr.hpp>

class Flash : public Task {
    Clock& clock;
    Stream<char>& stdin;
    Pin& ledPin;
    static const uint32_t pulseLength = MS_TO_TICKS(50);

    public:

    Flash(Clock& clock, Stream<char>& stdin, Pin& ledPin) : clock(clock), stdin(stdin), ledPin(ledPin) {
        ledPin.direction(Pin::Direction::Output);
    }

    protected:

    void loop() override {
        ledPin.value(Pin::Value::Low);

        char c;

        if(stdin.pop(&c)) {
            stdin.clear();
            ledPin.value(Pin::Value::High);
            delay(clock, pulseLength);
        }
    }
};

#endif
