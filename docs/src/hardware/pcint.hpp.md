[Index](../../index.hpp.md#index)

# Pin Change Interrupts

```c++
Callback<void> f = [](void*) {
    nblib::hw::PortB::Pin5::toggle();
};

atomic {
    nblib::hw::PcInt0::mask(0x0F);
    nblib::hw::PcInt0::setCallback(f);
    nblib::hw::PcInt0::intEnable(true);
}
```

## Class PcIntN

#### static [HardwareType](hardwaretype.hpp.md#enum-hardwaretype) getHardwareType()

#### static void intEnable(bool e)

#### static void mask(uint8_t m)
Set which pins trigger this interrupt.

#### static bool intFlag()

#### static void intFlagClear()
