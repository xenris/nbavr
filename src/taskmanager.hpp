/// # TaskManager

/// ## Example

/// ```c++
/// const uint32_t CpuFreq = 16000000;

/// using LedPin = nbavr::PinB5;
/// using SystemTimer = nbavr::TimerCounter1;

/// using Clock = nbavr::Clock<SystemTimer, CpuFreq>;

/// Flash<Clock, LedPin> flash;

/// nbavr::Task<Clock>* tasks[] = {&flash};

/// nbavr::TaskManager<Clock> tm(tasks);
/// ```

#ifndef NBAVR_TASKMANAGER_HPP
#define NBAVR_TASKMANAGER_HPP

#include "clock.hpp"
#include "hardware.hpp"
#include "macros.hpp"
#include "task.hpp"
#include "type.hpp"

/// ## class TaskManager\<class Clock\>
template <class Clock>
class TaskManager {
    typedef Task<Clock> TaskT;

    static constexpr uint32_t TaskTimeout = Clock::millisToTicks(4);
    static constexpr uint32_t TaskTimeoutHalted = Clock::microsToTicks(100);

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

        interruptsEnable();

        if(task.state == TaskT::State::Delay) {
            // Check if it is time for this task to wake up.
            uint32_t wakeTick;

            atomic {
                wakeTick = task.wakeTick;
            }

            if(int32_t(Clock::getTicks() - wakeTick) >= 0) {
                task.state = TaskT::State::Awake;
            }
        }

        if(task.state == TaskT::State::Awake) {
            Clock::haltStart(TaskTimeout);

            task.loop();

            Clock::haltEnd();
        }

        taskI = (taskI + 1) % numTasks;
    }

    // Run each task once, excluding the crashed one.
    void handleHalt() {
        TaskT& task = *tasks[taskI];

        task.state = TaskT::State::Halt;

        stepAll();

        task.state = TaskT::State::Awake;

        Clock::haltStart(TaskTimeoutHalted);
    }

    static void haltCallback(void* data) {
        TaskManager* self = static_cast<TaskManager*>(data);

        self->handleHalt();
    }
};

#endif
