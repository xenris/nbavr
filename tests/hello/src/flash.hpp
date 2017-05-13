#ifndef FLASH_HPP
#define FLASH_HPP

#include <nbavr.hpp>

template <class ledPin>
struct Flash : Task {
    Flash() {
        ledPin::direction(Direction::Output);
    }

    void loop(Clock& clock) override {
        ledPin::toggle();
        delay(clock, MS_TO_TICKS(500));
    }
};

#endif
