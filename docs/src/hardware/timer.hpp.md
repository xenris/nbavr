[Index](../../index.hpp.md#index)

# Timers

```c++
// Constant interval.

using Timer = nblib::hw::Timer1;

nblib::hw::Pin::Value value = nblib::hw::Pin::Value::low;

const auto f = [](nblib::hw::Pin::Value* value) {
    *value = nblib::hw::PortB::Pin5::input();
};

atomic([]() {
    Timer::waveform(Timer::Waveform::ctcOcra);
    Timer::OutputA::value(2036);
    Timer::clock(Timer::Clock::Div16);
    Timer::intEnable(true);
    Timer::callback((callback_t)f, &value);
});
```

## Class TimerN

#### Type
The underlying type of this timer/counter. (uint8_t or uint16_t)

#### enum TimerN::Clock
* none
* div1
* div2
* div4
* div8
* div16
* div32
* div64
* div128
* div256
* div512
* div1024
* div2048
* div4096
* div8192
* div16384
* extFalling
* extRising

#### enum TimerN::Waveform
* normal
* pwm
* ctcOcra
* fastPwm
* pwmOcra
* fastPwmOcra

#### static [HardwareType](hardwaretype.hpp.md#enum-hardwaretype) getHardwareType()

#### static void counter(T value)

#### static T counter()

#### static void clock([TimerN::Clock](timer.hpp.md#enum-timernclock) c)

#### static void waveform([TimerN::Waveform](timer.hpp.md#enum-timernwaveform) w)

#### static void intEnable(bool b)

#### static bool intFlag()

#### static void intFlagClear()

#### static void prescalerReset()
Resets the *shared* timer prescaler to zero.

#### static void synchronizeMode(bool b)
Set to true then call prescalerReset() to hold the timers' prescalers at zero, effectively pausing the timers.
Set back to false to start all timers at exactly the same time.

## class OutputX
See [TimerN::OutputX](output.xpp.md#class-timernoutputx)

## class Input
See [TimerN::Input](input.xpp.md#class-timerninput)
