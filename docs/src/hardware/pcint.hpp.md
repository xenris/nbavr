[Index](../../index.hpp.md#index)

# Pin Change Interrupts

```c++
const auto f = [](void*) {
    nbos::hw::PortB::Pin5::toggle();
};

atomic([]() {
    nbos::hw::PcInt1::mask(0x0F);
    nbos::hw::PcInt1::callback((callback_t)f);
    nbos::hw::PcInt1::intEnable(true);
});
```

## Class PcIntN

#### static [HardwareType](hardwaretype.hpp.md#enum-hardwaretype) getHardwareType()

#### static void intEnable(Bool e)

#### static void mask(Word8 m)
Set which pins trigger this interrupt.

#### static void setCallback([Callback](../callback.hpp.md#callbackt--void-t)<T\> function, T\* data)

#### static void callCallback()

#### static Bool intFlag()

#### static void intFlagClear()
