# TaskManager

## Example
```c++
const uint32_t CpuFreq = 16000000;

typedef PinB5 ledPin;
typedef TimerCounter1 systemTimer;

typedef Clock<systemTimer, CpuFreq> Clock;

Clock::init();

Flash<Clock, ledPin> flash;

Task* tasks[] = {&flash};

TaskManager tm(tasks);
```
## class TaskManager<class Clock>
#### TaskManager(TaskT* (&tasks)[])
Runs the given array of tasks. Does not return.
