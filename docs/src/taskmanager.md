# TaskManager

## Example

```c++
const uint32_t CpuFreq = 16000000;

using LedPin = nbos::PinB5;
using SystemTimer = nbos::TimerCounter1;

using Clock = nbos::Clock<SystemTimer, CpuFreq>;

Flash<Clock, LedPin> flash;

nbos::Task<Clock>* tasks[] = {&flash};

nbos::TaskManager<Clock> tm(tasks);
```

## class TaskManager\<class Clock\>

#### TaskManager(TaskT\* (&tasks)[])
Runs the given array of tasks. Does not return.
