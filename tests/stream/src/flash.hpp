#ifndef FLASH_HPP
#define FLASH_HPP

#include <nbavr.hpp>

template <class ledPin>
struct Flash : Task {
    Stream<char>& stdin;
    static const uint32_t pulseLength = MS_TO_TICKS(50);

    Flash(Stream<char>& stdin) : stdin(stdin) {
        ledPin::direction(ledPin::Direction::Output);
    }

    void loop(Clock& clock) override {
        ledPin::value(ledPin::Value::Low);

        char c;

        if(stdin.pop(&c)) {
            stdin.clear();
            ledPin::value(ledPin::Value::High);
            delay(clock, pulseLength);
        }
    }
};

#endif
