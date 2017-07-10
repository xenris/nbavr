#ifndef NBAVR_TASK_HPP
#define NBAVR_TASK_HPP

/// # Tasks

/// ## Example

/// ```c++
/// template <class Nbavr, class ledPin>
/// struct Flash : Task {
///     Flash() {
///         ledPin::direction(ledPin::Direction::Output);
///     }
///
///     void loop(Clock& clock) override {
///         ledPin::toggle();
///
///         sleep(Nbavr::getTicks() + Nbavr::millisToTicks(500));
///     }
/// };
/// ```

/// ## Class Task
struct Task {
    enum class State : int8_t {
        Awake,
        Delay,
        Asleep,
        Halt,
    };

    State state = State::Awake;
    uint32_t wakeTick = 0;

    /// #### void **sleep**(uint32_t time)
    /// Put this task to sleep until time.
    void sleep(uint32_t time) {
        wakeTick = time;
        state = State::Delay;
    }

    /// #### void **sleep**()
    /// Put this task to sleep until woken with wake().
    void sleep() {
        state = State::Asleep;
    }

    /// #### void **wake**()
    /// Wake this task from sleep or delay.
    void wake() {
        if(state != State::Halt) {
            state = State::Awake;
        }
    }

    /// #### virtual void **loop**()
    /// The main loop of the task. Override this and fill with your own code.
    virtual void loop() {};
};

#endif
