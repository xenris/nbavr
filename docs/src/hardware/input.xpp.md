[Index](../../index.hpp.md#index)

# Timer Input

```c++
using Timer = nblib::hw::Timer1;

nblib::hw::Pin::Value value = 0;

Callback<nblib::hw::Pin::Value> f = [](nblib::hw::Pin::Value* value) {
    *value = Timer::Input::value();
};

atomic {
    Timer::waveform(Timer::Waveform::normal);
    Timer::clock(Timer::Clock::div1);
    Timer::Input::edge(Timer::Edge::rising);
    Timer::Input::intEnable(true);
    Timer::Input::callback(f, &value);
}
```

## class TimerN::Input

#### type Pin
The IO pin which relates to this input.

#### enum TimerN::Edge
* rising
* falling

#### static void value(T v)

#### static T value()

#### static void edge([TimerN::Edge](input.xpp.md#enum-timernedge) e)

#### static void setCallback([Callback](../callback.hpp.md#callbackt--void-t)<T\> function, T\* data)

#### static void callCallback()

#### static void intEnable(bool b)

#### static bool intFlag()

#### static void intFlagClear()
