#ifndef HELLO_HPP
#define HELLO_HPP

#include <nbavr.hpp>

class Hello : public Task {
    Stream<char>& stdout;
    uint16_t count = 0;

public:
    Hello(Stream<char>& stdout) : stdout(stdout) {
    }

private:
    void loop(Clock& clock) override {
        stdout << "hello! (" << count << ')' << endl;

        count++;

        delay(clock, MS_TO_TICKS(1000));
    }
};

#endif
