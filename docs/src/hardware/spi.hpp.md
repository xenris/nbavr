[Index](../../index.hpp.md#index)

# Serial Peripheral Interfaces

```c++
atomic {
    nblib::hw::Spi0::PinMosi::mode(nblib::hw::Spi0::PinMosi::Mode::output);
    nblib::hw::Spi0::PinSck::mode(nblib::hw::Spi0::PinSck::Mode::output);
});

atomic {
    nblib::hw::Spi0::clock(nblib::hw::Spi0::Clock::div16);
    nblib::hw::Spi0::masterSlave(nblib::hw::Spi0::MasterSlave::master);
    nblib::hw::Spi0::enable(true);
});

nblib::hw::Spi0::data(0x31);

while(!nblib::hw::Spi0::intFlag());

nblib::hw::Spi0::data(0x44);

while(!nblib::hw::Spi0::intFlag());
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

#### static void dataOrder([SpiN::DataOrder](spi.hpp.md#enum-spindataorder) d)

#### static void masterSlave([SpiN::MasterSlave](spi.hpp.md#enum-spinmasterslave) m)

#### static void polarity([SpiN::Polarity](spi.hpp.md#enum-spinpolarity) p)

#### static void phase([SpiN::Phase](spi.hpp.md#enum-spinphase) p)

#### static void clock([SpiN::Clock](spi.hpp.md#enum-spinclock) c)

#### static bool intFlag()

#### static bool collisionFlag()

#### static void data(uint8_t d)

#### static uint8_t data()
