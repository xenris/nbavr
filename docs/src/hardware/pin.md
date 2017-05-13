# Digital IO Pins
X is the port id (A, B, etc).<br>
N is the pin id (1, 2, etc).<br>
All functions are static.
## Example
```c++
PinB5::direction(Direction::Output);
PinB5::output(Value::High);
```
#### enum Direction
* Input
* Output
#### enum Value
* Low
* High
## Class PinXN
#### constexpr [HardwareType](../hardware.hpp.md) getHardwareType()
Get the type of hardware that this class represents.
#### void direction(Direction)
Set the direction. (Input/Output)
#### Direction direction()
Get the direction. (Input/Output)
paragraph
#### void pullup(bool)
Enable/disable the pullup resistor.
#### bool pullup()
Returns true if the pullup resistor is enabled.
#### void output(Value)
Set the output state. (High/Low)
#### Value output()
Get the output state. (High/Low)
#### Value input()
Get the input state. (High/Low)
#### void toggle()
Toggle the output state. (High/Low)
