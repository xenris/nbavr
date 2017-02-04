#ifndef HELLO_HPP
#define HELLO_HPP

#include <nbavr.hpp>

class Hello : public Task {
    static constexpr const char* msg1 = "Hello!";
    static constexpr const char* msg2 = "                Welcome to nbavr";

    Clock& clock;
    uint8_t scroll = 0;
    Stream<char>& lcdout;

public:
    Hello(Clock& clock, Stream<char>& lcdout) : clock(clock), lcdout(lcdout) {
    }

private:
    void loop() override {
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
