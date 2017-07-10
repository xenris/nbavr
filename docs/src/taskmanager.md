# Task Manager
## Example
```c++
typedef TimerCounter1 systemTimer;
typedef PinB5 ledPin;
typedef Nbavr<systemTimer, 16000000> Nbavr;

Flash<Nbavr, ledPin> flash;

Task* tasks[] = {&flash};

TaskManager<Nbavr> tm(tasks);
```
## Class TaskManager\<Nbavr\>
#### TaskManager(Task\*[])
Run an array of tasks.<br>
Requires a 16bit timer/counter.<br>
This constructor does not return.
