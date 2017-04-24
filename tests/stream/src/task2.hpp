#ifndef TASK2_HPP
#define TASK2_HPP

#include <nbavr.hpp>

struct Task2 : Task {
    bool firstRun = true;
    uint8_t count = 0;
    Stream<uint8_t>& stream;

    Task2(Stream<uint8_t>& stream) : stream(stream) {
    }

    void loop(Clock& clock) override {
        if(firstRun) {
            firstRun = false;
        } else {
            stream << count;

            count += 25;
        }

        delay(clock, MS_TO_TICKS(4100));
    }
};

#endif
