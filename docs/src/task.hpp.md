[Index](../index.hpp.md#index)

# Task

```c++
template <class Clock, class ledPin>
struct Flash : Task<Clock> {
    Flash() {
        ledPin::direction(ledPin::Direction::Output);
    }

    void loop() override {
        ledPin::toggle();

        this->sleep(Clock::millisToTicks(500));
    }
};
```

## Class Task\<class Clock\>

#### void sleep(uint64_t ticks)
Put this task to sleep until the given number of ticks have passed.

#### void sleep()
Put this task to sleep until woken with wake().

#### void wake()
Wake this task from sleep.

#### virtual void loop()
The main loop of the task.<br>
Override this and fill with your own code.
