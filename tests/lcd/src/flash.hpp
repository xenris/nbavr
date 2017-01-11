#ifndef FLASH_HPP
#define FLASH_HPP

#include <nbavr.hpp>

class Flash : public Task {
    Clock& clock;
    Pin& ledPin;

    public:

    Flash(Clock& clock, Pin& ledPin) : clock(clock), ledPin(ledPin) {
        ledPin.direction(Pin::Direction::Output);
    }

    protected:

    void loop() override {
        ledPin.toggle();
        delay(clock, MS_TO_TICKS(500));
    }
};

#endif
