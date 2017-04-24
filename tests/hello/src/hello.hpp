#ifndef HELLO_HPP
#define HELLO_HPP

#include <nbavr.hpp>

struct Hello : Task {
    Stream<char>& stdout;
    uint16_t count = 0;

    Hello(Stream<char>& stdout) : stdout(stdout) {
    }

    void loop(Clock& clock) override {
        stdout << "hello! (" << count << ')' << endl;

        count++;

        delay(clock, MS_TO_TICKS(1000));
    }
};

#endif
