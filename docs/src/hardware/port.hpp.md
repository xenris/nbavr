[Index](../../index.hpp.md#index)

# Digital IO Ports

```c++
using PortC = nblib::hw::PortC;

nblib::hw::PortC::mode(nblib::hw::Pin::Mode::output);

nblib::hw::PortC::output(0x03);

nblib::hw::PortC::Pin15::output(nblib::hw::Pin::Value::low);

while(true) {
    nblib::hw::PortC::toggle(0x0C);
    nblib::block();
}
```

## Class PortX

#### static [HardwareType](hardwaretype.hpp.md#enum-hardwaretype) getHardwareType()

#### static void enableClock(bool e)

#### static void mode([Pin::Mode](pin.xpp.md#enum-pinmode) m)

#### static void output(T value)

#### static void setOutputs(T bits)

#### static void clearOutputs(T bits)

#### static T output()

#### static T input()

#### static void toggle(T bits)
