# Digital IO Ports

X is the port id (A, B, etc).

## Example

```c++
// Set pins 0 and 1 as outputs and all others as inputs.
PortC::direction(0x03);
// Set pin 0 high and all others low.
PortC::output(0x01);
```

## Class PortX

#### static constexpr HardwareType getHardwareType()
Get the type of hardware that this class represents.

#### static void enableClock(bool e)
Enable/disable the hardware clock for this port.

#### static void mode(Pin::Mode m)
Set the mode of all the pins on this port.

#### static void output(T value)
Set the output value of the port.

#### static void setOutputs(T bits)
Set the given bits of the port.

#### static void clearOutputs(T bits)
Clear the given bits of the port.

#### static T output()
Get the output state of the port.

#### static T input()
Get the input state of the port.

#### static void toggle(T bits)
Toggle the given bits of the port.
