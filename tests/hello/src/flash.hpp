#ifndef FLASH_HPP
#define FLASH_HPP

#include <nbavr.hpp>

template <class ledPin>
class Flash : public Task {
    Clock& clock;

public:
    Flash(Clock& clock) : clock(clock) {
        ledPin::direction(ledPin::Direction::Output);
    }

private:
    void loop() override {

        ledPin::toggle();
        delay(clock, MS_TO_TICKS(500));
    }
};

#endif
