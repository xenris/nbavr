# Tasks
## Example
```c++
template <class ledPin>
struct Flash : Task {
    Flash() {
        ledPin::direction(ledPin::Direction::Output);
    }

    void loop(Clock& clock) override {
        ledPin::toggle();

        delay(clock, MS_TO_TICKS(500));
    }
};
```
## Class Task
#### void **delay**(Clock&, uint32_t)
Delay this task for some number of ticks.
#### void **sleep**()
Put this task to sleep.
#### void **wake**()
Wake this task from sleep or delay.
#### virtual void **loop**()
The main loop of the task. Override this and fill with your own code.
