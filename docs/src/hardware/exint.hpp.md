# External Interrupt

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

#### enum Trigger
* low
* change
* falling
* rising

#### static HardwareType getHardwareType()

#### static void intEnable(bool e)

#### static void trigger(Trigger t)

#### static void callback(callback_t callback, void\* data)

#### static bool intFlag()

#### static void intFlagClear()
