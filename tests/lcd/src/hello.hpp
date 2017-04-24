#ifndef HELLO_HPP
#define HELLO_HPP

#include <nbavr.hpp>

struct Hello : Task {
    static constexpr const char* msg1 = "Hello!";
    static constexpr const char* msg2 = "                Welcome to nbavr";

    uint8_t scroll = 0;
    Stream<char>& lcdout;

    Hello(Stream<char>& lcdout) : lcdout(lcdout) {
    }

    void loop(Clock& clock) override {
        uint16_t seconds = TICKS_TO_MS(clock.getTicks()) / 1000;

        lcdout << '\r' << msg1 << " (" << seconds << ")\n" << msg2 + scroll;

        scroll++;

        if(scroll >= sizeof(msg2)) {
            scroll = 0;
        }

        delay(clock, MS_TO_TICKS(500));
    }
};

#endif
