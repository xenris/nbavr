#ifndef NBAVR_TASK_HPP
#define NBAVR_TASK_HPP

/// # Tasks

/// ## Example

/// ```c++
/// template <class Nbavr, class ledPin>
/// struct Flash : Task<Nbavr> {
///     Flash() {
///         ledPin::direction(ledPin::Direction::Output);
///     }
///
///     void loop() override {
///         ledPin::toggle();
///
///         this->sleep(Nbavr::millisToTicks(500));
///     }
/// };
/// ```

/// ## Class Task<class Nbavr>
template <class Nbavr>
struct Task {
    enum class State : int8_t {
        Awake,
        Delay,
        Asleep,
        Halt,
    };

    State state = State::Awake;
    uint32_t wakeTick = 0;

    /// #### void **sleep**(uint32_t ticks)
    /// Put this task to sleep until the given number of ticks have passed.
    void sleep(uint32_t ticks) {
        wakeTick = Nbavr::getTicks() + ticks;
        state = State::Delay;
    }

    /// #### void **sleep**()
    /// Put this task to sleep until woken with wake().
    void sleep() {
        state = State::Asleep;
    }

    /// #### void **wake**()
    /// Wake this task from sleep.
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
