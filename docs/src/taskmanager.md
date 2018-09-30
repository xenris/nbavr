# TaskManager

## Example

```c++
const uint64_t cpuFreq = 16000000;

using LedPin = nbos::hw::PortB::Pin5;
using SystemTimer = nbos::hw::Timer1;

using Clock = nbos::Clock<SystemTimer, cpuFreq>;

Flash<Clock, LedPin> flash;

nbos::Task<Clock>* tasks[] = {&flash};

nbos::TaskManager<Clock> tm(tasks);
```

## class TaskManager\<class Clock\>

#### TaskManager(TaskT\* (&tasks)[])
Runs the given array of tasks. Does not return.
