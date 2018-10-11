/// # TaskManager

/// ```c++
/// const uint64_t cpuFreq = 16000000;

/// using LedPin = nbos::hw::PortB::Pin5;
/// using SystemTimer = nbos::hw::Timer1;

/// using Clock = nbos::Clock<SystemTimer, cpuFreq>;

/// Flash<Clock, LedPin> flash;

/// nbos::Task<Clock>* tasks[] = {&flash};

/// nbos::TaskManager<Clock> tm(tasks);
/// ```

#ifndef NBOS_TASKMANAGER_HPP
#define NBOS_TASKMANAGER_HPP

#include "clock.hpp"
#include "macros.hpp"
#include "task.hpp"
#include "type.hpp"

namespace nbos {

/// ## class TaskManager\<class Clock\>
template <class Clock>
class TaskManager {
    typedef Task<Clock> TaskT;

    static constexpr typename Clock::Timer::type taskTimeout = Clock::millisToTicks(4);
    static constexpr typename Clock::Timer::type taskTimeoutHalted = Clock::microsToTicks(100);

    TaskT** tasks;
    const uint8_t numTasks;
    uint8_t taskI = 0;

public:

    /// #### TaskManager(TaskT\* (&tasks)[])
    /// Runs the given array of tasks. Does not return.
    template <uint8_t S>
    TaskManager(TaskT* (&tasks)[S]) : tasks(tasks), numTasks(S) {
        Clock::haltCallback(haltCallback, this);

        Clock::init();

        #ifdef CHIP_WATCHDOG_TIMER_CONTROL_REG
            block hw::WDT::enable();
        #endif

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
        TaskT& task = *tasks[taskI];

        #ifdef CHIP_WATCHDOG_TIMER_CONTROL_REG
            hw::WDT::reset();
        #endif

        interruptsEnable(true);

        if(task.state == TaskT::State::delay) {
            // Check if it is time for this task to wake up.
            if(int64_t(Clock::getTicks() - task.wakeTick) >= 0) {
                task.state = TaskT::State::awake;
            }
        }

        if(task.state == TaskT::State::awake) {
            Clock::haltStart(taskTimeout);

            task.loop();

            Clock::haltEnd();
        }

        taskI = (taskI + 1) % numTasks;
    }

    // Run each task once, excluding the crashed one.
    void handleHalt() {
        TaskT& task = *tasks[taskI];

        task.state = TaskT::State::halt;

        stepAll();

        task.state = TaskT::State::awake;

        Clock::haltStart(taskTimeoutHalted);
    }

    static void haltCallback(void* data) {
        TaskManager* self = static_cast<TaskManager*>(data);

        self->handleHalt();
    }
};

} // nbos

#endif
