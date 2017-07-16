# Timer/Counters
## Example
```c++
// TODO
```
N is the timer/counter id (1, 2, etc).<br>
T is the type of the timer's counter, either uint8_t or uint16_t.<br>
#### macro INCLUDE_TIMERCOUNTER_OUTPUT_CALLBACK(N, X)
Include this to use TimerCounter output compare callbacks.
#### macro INCLUDE_TIMERCOUNTER_OVERFLOW_CALLBACK(N)
Include this to use TimerCounter overflow callbacks.
## Class TimerCounterN
#### typedef T type
The underlying type of this timer/counter. (uint8_t or uint16_t)

#### enum Clock
* None (No clock)
* Div1 (cpu frequency / 1)
* Div8
* Div32
* Div64
* Div128
* Div256
* Div1024
* ExtFalling (clock on external pin falling edge)
* ExtRising

#### enum Waveform
* Normal
* PWM
* CTCOCRA
* FastPWM
* PWMOCRA
* FastPWMOCRA

#### enum OutputMode
* Disconnected
* Toggle
* Clear
* Set

#### static constexpr HardwareType getHardwareType()
Get the type of hardware that this class represents.

#### static void counter(T)
Set the counter value.

#### static T counter()
Get the counter value.

#### static void clock(Clock)
Set the clock source.

#### static void waveform(Waveform)
Set the counting method.

#### static void overflowCallback(void (\*)(void\*), void\*)
Set the callback and data for the counter overflow interrupt.

#### static void overflowIntEnable(bool)
Enable/disable the counter overflow interrupt.

#### static bool overflowIntFlag()
Returns true if the counter overflow flag is set.

#### static void overflowIntFlagClear()
Clear the counter overflow interrupt flag.

## class OutputCompareX
See [OutputCompareX](outputcompare.md)
