#ifndef NBAVR_TASKMANAGER_HPP
#define NBAVR_TASKMANAGER_HPP

#include "task.hpp"

// Milliseconds until a task is considered to have halted.
#define TASK_TIMEOUT_MS 6
#define TASK_TIMEOUT_HALTED_MS 1

template <class Nbavr>
class TaskManager {
    typedef Task<Nbavr> TaskT;

    TaskT** tasks;
    const uint8_t numTasks;
    uint8_t taskI = 0;

public:

    template <uint8_t S>
    TaskManager(TaskT* (&tasks)[S]) : tasks(tasks), numTasks(S) {
        block Nbavr::timer::OutputCompareB::callback(haltCallback, this);

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
        TaskT& task = *tasks[taskI];

        WDT::reset();

        sei();

        if(task.state == TaskT::State::Delay) {
            // Check if it is time for this task to wake up.
            uint32_t wakeTick;

            atomic {
                wakeTick = task.wakeTick;
            }

            if(int32_t(Nbavr::getTicks() - wakeTick) >= 0) {
                task.state = TaskT::State::Awake;
            }
        }

        if(task.state == TaskT::State::Awake) {
            // Setup halt callback.
            block Nbavr::timer::OutputCompareB::value(Nbavr::getTicks16() + Nbavr::millisToTicks(TASK_TIMEOUT_MS));
            block Nbavr::timer::OutputCompareB::intFlagClear();
            block Nbavr::timer::OutputCompareB::intEnable(true);

            task.loop();

            // Disable halt callback.
            block Nbavr::timer::OutputCompareB::intEnable(false);
        }

        taskI = (taskI + 1) % numTasks;
    }

    // Run each task once, excluding the crashed one.
    void handleHalt() {
        TaskT& task = *tasks[taskI];

        task.state = TaskT::State::Halt;

        stepAll();

        task.state = TaskT::State::Awake;

        // Setup halt callback.
        block Nbavr::timer::OutputCompareB::value(Nbavr::getTicks16() + Nbavr::millisToTicks(TASK_TIMEOUT_HALTED_MS));
        block Nbavr::timer::OutputCompareB::intFlagClear();
        block Nbavr::timer::OutputCompareB::intEnable(true);
    }

    static void haltCallback(void* data) {
        TaskManager* self = static_cast<TaskManager*>(data);

        self->handleHalt();
    }
};

#endif
