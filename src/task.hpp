#ifndef NBAVR_TASK_HPP
#define NBAVR_TASK_HPP

class Task {
public:
    enum class State : int8_t {
        Awake,
        Delay,
        Asleep,
        Halt,
    };

    State state = State::Awake;
    uint32_t wakeTick = 0;

    void delay(Clock& clock, uint32_t ticks) {
        wakeTick = clock.getTicks() + ticks;
        state = State::Delay;
    }

    void sleep() {
        state = State::Asleep;
    }

    void wake() {
        if(state != State::Halt) {
            state = State::Awake;
        }
    }

    virtual void loop(Clock& clock) {};
};

#endif
