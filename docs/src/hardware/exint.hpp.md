[Index](../../index.hpp.md#index)

# External Interrupts

```c++
Callback<void> f = [](void*) {
    nbos::hw::PortB::Pin5::toggle();
};

atomic {
    nbos::hw::ExInt0::trigger(nbos::hw::ExInt0::Trigger::rising);
    nbos::hw::ExInt0::setCallback(f);
    nbos::hw::ExInt0::intEnable(true);
}
```

## class ExIntN

#### enum ExIntN::Trigger
* low
* change
* falling
* rising

#### static [HardwareType](hardwaretype.hpp.md#enum-hardwaretype) getHardwareType()

#### static void intEnable(Bool e)

#### static void trigger([ExIntN::Trigger](exint.hpp.md#enum-exintntrigger) t)

#### static void setCallback([Callback](../callback.hpp.md#callbackt--void-t)<T\> function, T\* data)

#### static void callCallback()

#### static Bool intFlag()

#### static void intFlagClear()
