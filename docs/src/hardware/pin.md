# Digital IO Pins

N is the pin id (0, 1, 2, etc).

## Example

```c++
PortB::Pin5::mode(Pin::Mode::output);
PortB::Pin5::output(Pin::Value::high);
```

## Class PinN

#### static constexpr [HardwareType](../hardware.md) getHardwareType()
Get the type of hardware that this class represents.

#### static void mode(Mode m)
Set the pin mode. (e.g. input/output)

#### static Mode mode()
Get the pin mode. (e.g. input/output)
paragraph

#### static void output(Value v)
Set the output state. (High/Low)

#### static Value output()
Get the output value.

#### static Value input()
Get the input value.

#### static void toggle()
Toggle the output state. (High/Low)
