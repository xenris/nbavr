[Index](../index.hpp.md#index)

# Task Manager

```c++
const uint64_t cpuFreq = 16000000;

using LedPin = nblib::hw::PortB::Pin5;
using SystemTimer = nblib::hw::Timer1;

using Clock = nblib::Clock<SystemTimer, cpuFreq>;

Flash<Clock, LedPin> flash;

nblib::Task<Clock>* tasks[] = {&flash};

nblib::TaskManager<Clock> tm(tasks);
```

## class TaskManager\<class Clock\>

#### TaskManager(TaskT\* (&tasks)[])
Runs the given array of tasks. Does not return.
