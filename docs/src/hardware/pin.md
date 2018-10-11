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

#### enum Mode
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

#### enum Value
* low
* high

## Class PinN : Pin

#### static constexpr [HardwareType](../hardware.md) getHardwareType()

#### static void mode(Mode m)

#### static Mode mode()

#### static void output(Value v)

#### static Value output()

#### static Value input()

#### static void toggle()
