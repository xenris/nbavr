# TaskManager

## Example

```c++
const uint32_t CpuFreq = 16000000;

using LedPin = nbavr::PinB5;
using SystemTimer = nbavr::TimerCounter1;

using Clock = nbavr::Clock<SystemTimer, CpuFreq>;

Flash<Clock, LedPin> flash;

nbavr::Task<Clock>* tasks[] = {&flash};

nbavr::TaskManager<Clock> tm(tasks);
```

## class TaskManager\<class Clock\>

#### TaskManager(TaskT\* (&tasks)[])
Runs the given array of tasks. Does not return.
