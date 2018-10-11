/// # Task

/// ```c++
/// template <class Clock, class ledPin>
/// struct Flash : Task<Clock> {
///     Flash() {
///         ledPin::direction(ledPin::Direction::Output);
///     }

///     void loop() override {
///         ledPin::toggle();

///         this->sleep(Clock::millisToTicks(500));
///     }
/// };
/// ```

#ifndef NBOS_TASK_HPP
#define NBOS_TASK_HPP

#include "type.hpp"
#include "atomic.hpp"

namespace nbos {

/// ## Class Task\<class Clock\>
template <class Clock>
struct Task {
    enum class State : int8_t {
        awake,
        delay,
        asleep,
        halt,
    };

    State state = State::awake;
    Atomic<uint64_t> wakeTick = 0;

    /// #### void sleep(uint64_t ticks)
    /// Put this task to sleep until the given number of ticks have passed.
    void sleep(uint64_t ticks) {
        wakeTick = Clock::getTicks() + ticks;
        state = State::delay;
    }

    /// #### void sleep()
    /// Put this task to sleep until woken with wake().
    void sleep() {
        state = State::asleep;
    }

    /// #### void wake()
    /// Wake this task from sleep.
    void wake() {
        if(state != State::halt) {
            state = State::awake;
        }
    }

    /// #### virtual void loop()
    /// The main loop of the task.<br>
    /// Override this and fill with your own code.
    virtual void loop() {};
};

} // nbos

#endif
