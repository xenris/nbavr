[Index](../../index.hpp.md#index)

# External Interrupts

```c++
const auto f = [](void*) {
    nbos::hw::PortB::Pin5::toggle();
};

atomic([]() {
    nbos::hw::ExInt0::trigger(nbos::hw::ExInt0::Trigger::rising);
    nbos::hw::ExInt0::callback((callback_t)f);
    nbos::hw::ExInt0::intEnable(true);
});
```

## class ExIntN

#### enum ExIntN::Trigger
* low
* change
* falling
* rising

#### static [HardwareType](hardwaretype.hpp.md#enum-hardwaretype) getHardwareType()

#### static void intEnable(bool e)

#### static void trigger([ExIntN::Trigger](exint.hpp.md#enum-exintntrigger) t)

#### static void callback([callback_t](../type.hpp.md#using-callbackt--void-void) callback, void\* data)

#### static bool intFlag()

#### static void intFlagClear()
