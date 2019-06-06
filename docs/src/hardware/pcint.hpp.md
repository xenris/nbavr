[Index](../../index.hpp.md#index)

# Pin Change Interrupts

```c++
Callback<void> f = [](void*) {
    nbos::hw::PortB::Pin5::toggle();
};

atomic {
    nbos::hw::PcInt0::mask(0x0F);
    nbos::hw::PcInt0::setCallback(f);
    nbos::hw::PcInt0::intEnable(true);
}
```

## Class PcIntN

#### static [HardwareType](hardwaretype.hpp.md#enum-hardwaretype) getHardwareType()

#### static void intEnable(bool e)

#### static void mask(uint8_t m)
Set which pins trigger this interrupt.

#### static void setCallback([Callback](../callback.hpp.md#callbackt--void-t)<T\> function, T\* data)

#### static void callCallback()

#### static bool intFlag()

#### static void intFlagClear()
