/// [[Index]]

/// # {{Task}}

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

#include "atomic.hpp"

namespace nbos {

/// ## Class Task\<class Clock\>
template <class Clock>
struct Task {
    enum class State {
        awake,
        delay,
        asleep,
        halt,
    };

    State state = State::awake;
    Atomic<Word64> wakeTick;

    /// #### void sleep(Word64 ticks)
    /// Put this task to sleep until the given number of ticks have passed.
    void sleep(Word64 ticks) {
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

#ifdef TEST

#ifdef CHIP_TIMER_1
    template <typename Clock>
    struct Taskk : Task<Clock> {
        Queue<Char>& cout;
        Queue<Char>& cin;

        Taskk(Queue<Char>& cout, Queue<Char>& cin) : cout(cout), cin(cin) {
        }
    };

    TEST(Task, General) {
        Queue<Char, 10> cout;
        Queue<Char, 10> cin;

        typedef Clock<hw::Timer1, 16000000> Clock;

        Taskk<Clock> t(cout, cin);
    }
#endif // CHIP_TIMER_1

#endif // TEST

} // nbos

#endif
