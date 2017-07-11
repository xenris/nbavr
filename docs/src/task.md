# Tasks
## Example
```c++
template <class Nbavr, class ledPin>
struct Flash : Task {
    Flash() {
        ledPin::direction(ledPin::Direction::Output);
    }

    void loop(Clock& clock) override {
        ledPin::toggle();

        sleep(Nbavr::getTicks() + Nbavr::millisToTicks(500));
    }
};
```
## Class Task
#### void **sleep**(uint32_t tick)
Put this task to sleep until tick.
#### void **sleep**()
Put this task to sleep until woken with wake().
#### void **wake**()
Wake this task from sleep.
#### virtual void **loop**()
The main loop of the task. Override this and fill with your own code.
