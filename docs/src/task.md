# Tasks
## Example
```c++
template <class Nbavr, class ledPin>
struct Flash : Task<Nbavr> {
    Flash() {
        ledPin::direction(ledPin::Direction::Output);
    }

    void loop(Clock& clock) override {
        ledPin::toggle();

        this->sleep(Nbavr::millisToTicks(500));
    }
};
```
## Class Task<class Nbavr>
#### void **sleep**(uint32_t ticks)
Put this task to sleep until the given number of ticks have passed.
#### void **sleep**()
Put this task to sleep until woken with wake().
#### void **wake**()
Wake this task from sleep.
#### virtual void **loop**()
The main loop of the task. Override this and fill with your own code.
