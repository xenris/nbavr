# Timers

## Example
```c++
// TODO
```

N is the timer's id (1, 2, etc).<br>
T is the type of the timer's counter, either uint8_t or uint16_t.<br>

#### macro INCLUDE_TIMER_OUTPUT_CALLBACK(N, X)
Include this to use Timer output callbacks.

#### macro INCLUDE_TIMER_OVERFLOW_CALLBACK(N)
Include this to use Timer overflow callbacks.

#### macro INCLUDE_TIMER_INPUT_CALLBACK(N)
Include this to use Timer input callbacks.

## Class TimerN

#### using type = T
The underlying type of this timer/counter. (uint8_t or uint16_t)

#### enum Clock
* none (No clock)
* div1 (cpu frequency / 1)
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
* extFalling (clock on external pin falling edge)
* extRising

#### enum Waveform
* normal
* pwm
* ctcOcra
* fastPwm
* pwmOcra
* fastPwmOcra

#### static constexpr HardwareType getHardwareType()
Get the type of hardware that this class represents.

#### static void counter(T value)
Set the counter value.

#### static T counter()
Get the counter value.

#### static void clock(Clock c)
Set the clock source.

#### static void waveform(Waveform w)
Set the counting method.

#### static void overflowCallback(callback_t callback, void\* data)
Set the callback and data for the counter overflow interrupt.

#### static void overflowIntEnable(bool b)
Enable/disable the counter overflow interrupt.

#### static bool overflowIntFlag()
Returns true if the counter overflow flag is set.

#### static void overflowIntFlagClear()
Clear the counter overflow interrupt flag.

## class OutputX
See [OutputX](output.md)

## class Input
See [Input](input.md)
