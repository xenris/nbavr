# Pin Change Interrupt

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

#### static HardwareType getHardwareType()

#### static void intEnable(bool e)

#### static void mask(uint8_t m)
Set which pins trigger this interrupt.

#### static void callback(callback_t callback, void\* data)

#### static bool intFlag()

#### static void intFlagClear()
