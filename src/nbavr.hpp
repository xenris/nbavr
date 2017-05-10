#ifndef NBAVR_HPP
#define NBAVR_HPP

#include <stddef.h>
#include <stdint.h>

#include "util/type_info.hpp"

#include "hardware.hpp"
#include "atomic.hpp"
#include "rational.hpp"
#include "fixed.hpp"
#include "half.hpp"
#include "stream.hpp"
#include "array.hpp"
#include "clock.hpp"
#include "print.hpp"
#include "task.hpp"

#include "tasks/lcd.hpp"
#include "tasks/serial.hpp"
#include "tasks/servo.hpp"
#include "tasks/twi.hpp"

/// # Task Manager

/// ## Example

/// ```c++
/// typedef TimerCounter1 systemTimer;
/// typedef PinB5 ledPin;
///
/// Flash<ledPin> flash;
///
/// Task* tasks[] = {&flash};
///
/// NBAVR<systemTimer> nbavr(tasks);
/// ```

/// ## Class NBAVR\<TimerCounterN\>

/// #### NBAVR(Task\*[])
/// Run an array of tasks.<br>
/// Requires a 16bit timer/counter.<br>
/// This constructor does not return.


#define TASK_TIMEOUT MS_TO_TICKS(6)

template <class Timer>
class NBAVR {
    Task** tasks;
    const uint8_t numTasks;
    uint8_t taskI = 0;
    ClockT<Timer> clock;

public:

    template <uint8_t S>
    NBAVR(Task* (&tasks)[S]) : tasks(tasks), numTasks(S) {
        block Timer::outputBCallback(haltCallback, this);

        block WDT::enable();

        while(true) {
            stepAll();
        }
    }

private:

    // Run each task once.
    void stepAll() {
        for(uint8_t i = 0; i < numTasks; i++) {
            stepOne();
        }

        // TODO Sleep the cpu if all tasks are asleep.
    }

    // Run the next task.
    void stepOne() {
        Task& task = *tasks[taskI];

        WDT::reset();

        cli();

        if(task.state == Task::State::Delay) {
            // Check if it is time for this task to wake up.
            if(int32_t(clock.getTicks_() - task.wakeTick) >= 0) {
                task.state = Task::State::Awake;
            }
        }

        // Setup halt callback.
        atomic {
            Timer::outputB(clock.getTicks16() + TASK_TIMEOUT);
            Timer::outputBIntFlagClear();
            Timer::outputBIntEnable(true);
        }

        sei();

        if(task.state == Task::State::Awake) {
            task.loop(clock);
        }

        // Disable halt callback.
        block Timer::outputBIntEnable(true);

        taskI = (taskI + 1) % numTasks;
    }

    // Run each task once, excluding the crashed one.
    void handleHalt() {
        Task& task = *tasks[taskI];

        task.state = Task::State::Halt;

        stepAll();

        task.state = Task::State::Awake;
    }

    static void haltCallback(void* data) {
        NBAVR* self = static_cast<NBAVR*>(data);

        self->handleHalt();
    }
};

__extension__ typedef int __guard __attribute__((mode (__DI__)));

extern "C" force_inline int __cxa_guard_acquire(__guard *) __attribute__((used));
extern "C" force_inline void __cxa_guard_release (__guard *) __attribute__((used));
extern "C" force_inline void __cxa_guard_abort (__guard *) __attribute__((used));
extern "C" force_inline void __cxa_pure_virtual(void) __attribute__((used));

int __cxa_guard_acquire(__guard *g) {
    return !*reinterpret_cast<char*>(g);
}

void __cxa_guard_release(__guard *g) {
    *reinterpret_cast<char*>(g) = 1;
}

void __cxa_pure_virtual(void) {
}

void __cxa_guard_abort (__guard *) {
}

#endif
