[Index](../../index.hpp.md#index)

# Timer Input

```c++
using Timer = nbos::hw::Timer1;

uint16_t value = 0;

const auto f = [](nbos::hw::Pin::Value* value) {
    *value = Timer::Input::value();
};

atomic([]() {
    Timer::waveform(Timer::Waveform::normal);
    Timer::clock(Timer::Clock::Div1);
    Timer::Input::edge(Timer::Edge::rising);
    Timer::Input::intEnable(true);
    Timer::Input::callback((callback_t)f, &value);
});
```

## class TimerN::Input

#### type Pin
The IO pin which relates to this input.

#### enum TimerN::Edge
* rising
* falling

#### static void value(T v)

#### static T value()

#### static void edge([TimerN::Edge](input.hpp.md#enum-timernedge) e)

#### static void callback([callback_t](../type.hpp.md#callbackt--void-void) callback, void\* data)

#### static void intEnable(bool b)

#### static bool intFlag()

#### static void intFlagClear()
