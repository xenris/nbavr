#ifndef NBAVR_TASK_HPP
#define NBAVR_TASK_HPP

extern inline void resumeFromYield();
extern inline void resumeFromHalt();

#define TASK_TIMEOUT MS_TO_TICKS(6)

#define CRASH_LIMIT 5

class Task {
public:
    enum class State : int8_t {
        Awake,
        Delay,
        Asleep,
        Crash,
        Dead,
    };

    State state = State::Awake;
    uint32_t wakeTick = 0;
    int8_t crashCount = 0;

    void step(Clock& clock) {
        if(state == State::Delay) {
            // Check if it is time for this task to wake up.
            if(int32_t(clock.getTicks() - wakeTick) >= 0) {
                state = State::Awake;
            }
        }

        clock.enableHaltInterrupt(TASK_TIMEOUT, crashCallback, this);

        switch(state) {
        case State::Awake:
            loop();
            crashCount = 0;
            break;
        case State::Crash:
            crash();
            if(crashCount >= CRASH_LIMIT) {
                state = Task::State::Dead;
            } else {
                state = State::Awake;
            }
            break;
        default: // asleep or dead.
            break;
        }

        clock.disableHaltInterrupt();
    }

    void delay(Clock& clock, uint32_t ticks) {
        wakeTick = clock.getTicks() + ticks;
        state = State::Delay;
    }

    void sleep() {
        state = State::Asleep;
    }

    void wake() {
        if(state != State::Dead) {
            state = State::Awake;
        }
    }

protected:
    virtual void loop() {};
    virtual void crash() {};

private:
    static void crashCallback(void* data) {
        Task* self = reinterpret_cast<Task*>(data);

        self->state = State::Crash;
        self->crashCount++;

        resumeFromHalt();
    }
};

#endif
