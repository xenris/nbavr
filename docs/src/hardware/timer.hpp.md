[Index](../../index.hpp.md#index)

# Timers

```c++
// Constant interval.

using Timer = nbos::hw::Timer1;

nbos::hw::Pin::Value value = nbos::hw::Pin::Value::low;

const auto f = [](nbos::hw::Pin::Value* value) {
    *value = nbos::hw::PortB::Pin5::input();
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

#### using type = T
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

#### static void callback([callback_t](../type.hpp.md#callback_t--void-void) callback, void\* data)
Set the timer overflow callback.

#### static void intEnable(bool b)

#### static bool intFlag()

#### static void intFlagClear()

## class OutputX
See [TimerN::OutputX](output.hpp.md#class-timernoutputx)

## class Input
See [TimerN::Input](input.hpp.md#class-timerninput)
