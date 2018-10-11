# Timer

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

#### enum Clock
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

#### enum Waveform
* normal
* pwm
* ctcOcra
* fastPwm
* pwmOcra
* fastPwmOcra

#### static HardwareType getHardwareType()

#### static void counter(T value)

#### static T counter()

#### static void clock(Clock c)

#### static void waveform(Waveform w)

#### static void callback(callback_t callback, void\* data)
Set the timer overflow callback.

#### static void intEnable(bool b)

#### static bool intFlag()

#### static void intFlagClear()

## class OutputX
See [OutputX](output.md)

## class Input
See [Input](input.md)
