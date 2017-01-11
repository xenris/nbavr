#ifndef TASK2_HPP
#define TASK2_HPP

#include <nbavr.hpp>

class Task2 : public Task {
    Clock& clock;
    uint8_t count = 0;
    Stream<uint8_t>& stream;

    public:

    Task2(Clock& clock, Stream<uint8_t>& stream) : clock(clock), stream(stream) {
        delay(clock, MS_TO_TICKS(4100));
    }

    protected:

    void loop() override {
        stream << count;

        count += 25;

        delay(clock, MS_TO_TICKS(4100));
    }
};

#endif
