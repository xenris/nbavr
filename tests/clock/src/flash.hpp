#ifndef FLASH_HPP
#define FLASH_HPP

#include <nbavr.hpp>

template <class ledPin>
class Flash : public Task {
    bool intOccurred = false;

public:
    Flash() {
        ledPin::direction(ledPin::Direction::Output);
    }

private:
    void loop(Clock& clock) override {
        if(intOccurred) {
            intOccurred = false;

            delay(clock, MS_TO_TICKS(500));
        } else {
            ledPin::value(ledPin::Value::High);

            clock.addInterrupt(interrupt, this, MS_TO_TICKS(50));

            sleep();
        }
    }

    static void interrupt(void* data) {
        Flash* self = reinterpret_cast<Flash*>(data);

        ledPin::value(ledPin::Value::Low);

        self->intOccurred = true;
        self->wake();
    }
};

#endif
