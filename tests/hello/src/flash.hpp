#ifndef FLASH_HPP
#define FLASH_HPP

#include <nbavr.hpp>

template <class ledPin>
class Flash : public Task {
public:
    Flash() {
        ledPin::direction(ledPin::Direction::Output);
    }

private:
    void loop(Clock& clock) override {

        ledPin::toggle();
        delay(clock, MS_TO_TICKS(500));
    }
};

#endif
