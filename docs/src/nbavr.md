# Task Manager
## Example
```c++
typedef TimerCounter1 systemTimer;
typedef PinB5 ledPin;

Flash<ledPin> flash;

Task* tasks[] = {&flash};

NBAVR<systemTimer> nbavr(tasks);
```
## Class NBAVR\<TimerCounterN\>
#### NBAVR(Task\*[])
Run an array of tasks.<br>
Requires a 16bit timer/counter.<br>
This constructor does not return.
