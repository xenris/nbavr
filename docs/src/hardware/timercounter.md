# Timer/Counters
## Example
```c++
// TODO
```
N is the timer/counter id (1, 2, etc).<br>
X is the output compare id (A, B, etc).<br>
T is the type of the timer's counter, either uint8_t or uint16_t.<br>
All functions are static.
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
#### constexpr HardwareType getHardwareType()
Get the type of hardware that this class represents.
#### void counter(T)
Set the counter value.
#### T counter()
Get the counter value.
#### void clock(Clock)
Set the clock source.
#### void waveform(Waveform)
Set the counting method.
#### void overflowCallback(void (\*)(void\*), void\*)
Set the callback and data for the counter overflow interrupt.
#### void overflowIntEnable(bool)
Enable/disable the counter overflow interrupt.
#### bool overflowIntFlag()
Returns true if the counter overflow flag is set.
#### void overflowIntFlagClear()
Clear the counter overflow interrupt flag.
#### void outputX(T)
Set the compare register of output compare X.
#### T outputX()
Get the compare register of output compare X.
#### void outputXMode(OutputMode)
Set the mode of output compare X.
#### void outputXCallback(void (\*)(void\*), void\*)
Set the callback and data for output compare X interrupt.
#### void outputXIntEnable(bool)
Enable/disable the output compare X interrupt.
#### bool outputXIntFlag()
Returns true if the output compare X interrupt flag is set.
#### void outputXIntFlagClear()
Clear the output compare X interrupt flag.
