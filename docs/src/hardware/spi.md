# Serial Peripheral Interface

```c++
atomic([]() {
    nbos::hw::Spi0::PinMosi::mode(nbos::hw::Spi0::PinMosi::Mode::output);
    nbos::hw::Spi0::PinSck::mode(nbos::hw::Spi0::PinSck::Mode::output);
});

atomic([]() {
    nbos::hw::Spi0::clock(nbos::hw::Spi0::Clock::div16);
    nbos::hw::Spi0::masterSlave(nbos::hw::Spi0::MasterSlave::master);
    nbos::hw::Spi0::enable(true);
});

nbos::hw::Spi0::data(0x31);

while(!nbos::hw::Spi0::intFlag());

nbos::hw::Spi0::data(0x44);

while(!nbos::hw::Spi0::intFlag());
```

## class SpiN

#### type PinMiso

#### type PinMosi

#### type PinSck

#### type PinSs

#### enum DataOrder
* msbFirst
* lsbFirst

#### enum MasterSlave
* master
* slave

#### enum Polarity
* leadingRisingTrailingFalling
* leadingFallingTrailingRising

#### enum Phase
* leadingSampleTrailingSetup
* leadingSetupTrailingSample

#### enum Clock
* div2
* div4
* div8
* div16
* div32
* div64
* div128

#### static HardwareType getHardwareType()

#### static void enable(bool b)

#### static void intEnable(bool b)

#### static void callback(callback_t callback, void\* data)
Set the callback for when the serial transfer is complete.

#### static void dataOrder(DataOrder d)

#### static void masterSlave(MasterSlave m)

#### static void polarity(Polarity p)

#### static void phase(Phase p)

#### static void clock(Clock c)

#### static bool intFlag()

#### static void intFlagClear()

#### static bool collisionFlag()

#### static void collisionFlagClear()

#### static void data(uint8_t d)

#### static uint8_t data()
