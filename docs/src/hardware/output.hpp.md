# Timer Output

```c++
// PWM.

using Timer = nbos::hw::Timer0;

Timer::OutputA::Pin::mode(nbos::hw::Pin::Mode::output);
Timer::OutputB::Pin::mode(nbos::hw::Pin::Mode::output);

atomic([]() {
    Timer::waveform(Timer::Waveform::fastPWM);
    Timer::OutputA::mode(Timer::OutputA::Mode::set);
    Timer::OutputB::mode(Timer::OutputB::Mode::set);
    Timer::OutputA::value(128);
    Timer::OutputB::value(128);
    Timer::clock(Timer::Clock::div8);
});
```

## class TimerN::OutputX

#### type Pin
The IO pin which relates to this output.

#### enum TimerN::Mode
* disconnected
* toggle
* clear
* set

#### static void value(T v)

#### static T value()

#### static void mode([TimerN::Mode](output.hpp.md#enum-timernmode) m)

#### static void callback([callback_t](../type.hpp.md#using-callbackt--void-void) callback, void\* data)

#### static void intEnable(bool b)

#### static bool intEnabled()

#### static bool intFlag()

#### static void intFlagClear()
