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
#### constexpr HardwareType getHardwareType()
Get the type of hardware that this class represents.
#### void direction(uint8_t)
Set the direction of each pin. 0 = input, 1 = output.
#### uint8_t direction()
Get the direction of each pin. 0 = input, 1 = output.
#### void pullup(uint8_t)
Enable/disable the pullup resistor of each pin.
#### uint8_t pullup()
Get the pullup resistor state of each pin.
#### void output(uint8_t)
Set the output state of each pin.
#### uint8_t output()
Get the output state of each pin.
#### uint8_t input()
Get the input state of each pin.
#### void toggle(uint8_t)
Toggle the output state of each pin.
