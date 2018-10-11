[Index](../../index.hpp.md#index)

# Digital IO Ports

```c++
using PortC = nbos::hw::PortC;

nbos::hw::PortC::mode(nbos::hw::Pin::Mode::output);

nbos::hw::PortC::output(0x03);

nbos::hw::PortC::Pin15::output(nbos::hw::Pin::Value::low);

while(true) {
    nbos::hw::PortC::toggle(0x0C);
    nbos::block();
}
```

## Class PortX

#### static [HardwareType](hardwaretype.hpp.md#enum-hardwaretype) getHardwareType()

#### static void enableClock(bool e)

#### static void mode([Pin::Mode](pin.hpp.md#enum-pinmode) m)

#### static void output(T value)

#### static void setOutputs(T bits)

#### static void clearOutputs(T bits)

#### static T output()

#### static T input()

#### static void toggle(T bits)
