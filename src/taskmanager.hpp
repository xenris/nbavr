#ifndef NBAVR_TASKMANAGER_HPP
#define NBAVR_TASKMANAGER_HPP

#include "task.hpp"

// Milliseconds until a task is considered to have halted.
#define TASK_TIMEOUT_MS 6

/// # Task Manager

/// ## Example

/// ```c++
/// typedef TimerCounter1 systemTimer;
/// typedef PinB5 ledPin;
/// typedef Nbavr<systemTimer, 16000000> Nbavr;
///
/// Flash<Nbavr, ledPin> flash;
///
/// Task* tasks[] = {&flash};
///
/// TaskManager<Nbavr> tm(tasks);
/// ```

/// ## Class TaskManager\<Nbavr\>

/// #### TaskManager(Task\*[])
/// Run an array of tasks.<br>
/// Requires a 16bit timer/counter.<br>
/// This constructor does not return.

template <class Nbavr>
class TaskManager {
    Task** tasks;
    const uint8_t numTasks;
    uint8_t taskI = 0;

public:

    template <uint8_t S>
    TaskManager(Task* (&tasks)[S]) : tasks(tasks), numTasks(S) {
        block Nbavr::timer::outputBCallback(haltCallback, this);

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
            if(int32_t(Nbavr::getTicks() - task.wakeTick) >= 0) {
                task.state = Task::State::Awake;
            }
        }

        // Setup halt callback.
        block Nbavr::timer::outputB(Nbavr::getTicks16() + Nbavr::millisToTicks(TASK_TIMEOUT_MS));
        block Nbavr::timer::outputBIntFlagClear();
        block Nbavr::timer::outputBIntEnable(true);

        sei();

        if(task.state == Task::State::Awake) {
            task.loop();
        }

        // Disable halt callback.
        block Nbavr::timer::outputBIntEnable(false);

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
        TaskManager* self = static_cast<TaskManager*>(data);

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
