[Index](../../index.hpp.md#index)

# External Interrupts

```c++
Callback<void> f = [](void*) {
    nblib::hw::PortB::Pin5::toggle();
};

atomic {
    nblib::hw::ExInt0::trigger(nblib::hw::ExInt0::Trigger::rising);
    nblib::hw::ExInt0::setCallback(f);
    nblib::hw::ExInt0::intEnable(true);
}
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

#### static void setCallback([Callback](../callback.hpp.md#callbackt--void-t)<T\> function, T\* data)

#### static void callCallback()

#### static bool intFlag()

#### static void intFlagClear()
