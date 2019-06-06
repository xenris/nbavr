[Index](../../index.hpp.md#index)

# Serial Peripheral Interfaces

```c++
atomic {
    nbos::hw::Spi0::PinMosi::mode(nbos::hw::Spi0::PinMosi::Mode::output);
    nbos::hw::Spi0::PinSck::mode(nbos::hw::Spi0::PinSck::Mode::output);
});

atomic {
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

#### enum SpiN::DataOrder
* msbFirst
* lsbFirst

#### enum SpiN::MasterSlave
* master
* slave

#### enum SpiN::Polarity
* leadingRisingTrailingFalling
* leadingFallingTrailingRising

#### enum SpiN::Phase
* leadingSampleTrailingSetup
* leadingSetupTrailingSample

#### enum SpiN::Clock
* div2
* div4
* div8
* div16
* div32
* div64
* div128

#### static [HardwareType](hardwaretype.hpp.md#enum-hardwaretype) getHardwareType()

#### static void enable(bool b)

#### static void intEnable(bool b)

#### static void setCallback([Callback](../callback.hpp.md#callbackt--void-t)<T\> function, T\* data)
Set the callback for when the serial transfer is complete.

#### static void callCallback()

#### static void dataOrder([SpiN::DataOrder](spi.hpp.md#enum-spindataorder) d)

#### static void masterSlave([SpiN::MasterSlave](spi.hpp.md#enum-spinmasterslave) m)

#### static void polarity([SpiN::Polarity](spi.hpp.md#enum-spinpolarity) p)

#### static void phase([SpiN::Phase](spi.hpp.md#enum-spinphase) p)

#### static void clock([SpiN::Clock](spi.hpp.md#enum-spinclock) c)

#### static bool intFlag()

#### static bool collisionFlag()

#### static void data(uint8_t d)

#### static uint8_t data()
