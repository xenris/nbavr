[Index](../../index.hpp.md#index)

# Digital IO Pins

N is the pin id (0, 1, 2, etc).

## Example

```c++
PortB::Pin5::mode(Pin::Mode::output);

PortB::Pin5::output(Pin::Value::high);

while(true) {
    PortB::Pin5::toggle();
    nbos::block();
}
```

## class Pin

#### enum Pin::Mode
* input
* inputPullup
* output
* inputAnalog
* inputFloating
* inputPullUpDown
* outputGeneralPushPull10MHz
* outputGeneralOpenDrain10MHz
* outputAlternatePushPull10MHz
* outputAlternateOpenDrain10MHz
* outputGeneralPushPull2MHz
* outputGeneralOpenDrain2MHz
* outputAlternatePushPull2MHz
* outputAlternateOpenDrain2MHz
* outputGeneralPushPull50MHz
* outputGeneralOpenDrain50MHz
* outputAlternatePushPull50MHz
* outputAlternateOpenDrain50MHz

#### enum Pin::Value
* low
* high

## Class PinN : Pin

#### static [HardwareType](hardwaretype.hpp.md#enum-hardwaretype) getHardwareType()

#### static void mode([Pin::Mode](pin.hpp.md#enum-pinmode) m)

#### static [Pin::Mode](pin.hpp.md#enum-pinmode) mode()

#### static void output([Pin::Value](pin.hpp.md#enum-pinvalue) v)

#### static [Pin::Value](pin.hpp.md#enum-pinvalue) output()

#### static [Pin::Value](pin.hpp.md#enum-pinvalue) input()

#### static void toggle()
