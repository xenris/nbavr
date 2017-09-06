# Digital IO Pins

X is the port id (A, B, etc).<br>
N is the pin id (1, 2, etc).

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

#### static constexpr [HardwareType](../hardware.md) getHardwareType()
Get the type of hardware that this class represents.

#### static void direction(Direction d)
Set the direction. (Input/Output)

#### static Direction direction()
Get the direction. (Input/Output)
paragraph

#### static void pullup(bool p)
Enable/disable the pullup resistor.

#### static bool pullup()
Returns true if the pullup resistor is enabled.

#### static void output(Value v)
Set the output state. (High/Low)

#### static Value output()
Get the output state. (High/Low)

#### static Value input()
Get the input state. (High/Low)

#### static void toggle()
Toggle the output state. (High/Low)
