#ifndef HELLO_HPP
#define HELLO_HPP

#include <nbavr.hpp>

class Hello : public Task {
    Clock& clock;
    Stream<char>& stdout;
    uint16_t count = 0;

public:
    Hello(Clock& clock, Stream<char>& stdout) : clock(clock), stdout(stdout) {
    }

private:
    void loop() override {
        stdout << "hello! (" << count << ')' << endl;

        count++;

        delay(clock, MS_TO_TICKS(1000));
    }
};

#endif
