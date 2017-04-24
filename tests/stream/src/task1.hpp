#ifndef TASK1_HPP
#define TASK1_HPP

#include <nbavr.hpp>

class Task1 : public Task {
    uint32_t mDelay = 0;
    uint16_t count = 0;
    Stream<uint8_t>& stream;
    Stream<char>& stdout;

    public:

    Task1(Stream<uint8_t>& stream, Stream<char>& stdout) : stream(stream), stdout(stdout) {
    }

    void loop(Clock& clock) override {
        uint32_t ticks = clock.getTicks();

        if(ticks >= mDelay) {
            stdout << "Task1 running (" << count << ')' << endl;
            mDelay = ticks + MS_TO_TICKS(1000);
            count++;
        }

        uint8_t b;

        if(stream.pop(&b)) {
            stdout << "Task1 received byte 0x";
            printint(stdout, b, PrintFormat::Hex);
            stdout << endl;
        }
    }
};

#endif
