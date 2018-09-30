# SPI

N is the SPI id (0, 1, 2, etc).

## Example

```c++
// TODO
```

#### macro INCLUDE_SPI_CALLBACK(N)
Include this to use Spi callback.<br>
N is the Spi id.

## class SpiN

#### type PinMiso
The MISO IO pin.

#### type PinMosi
The MOSI IO pin.

#### type PinSck
The SCK IO pin.

#### type PinSs
The SS IO pin.

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

#### static constexpr HardwareType getHardwareType()
Get the type of hardware that this class represents.

#### static void enable(bool b)
Enable the SPI hardware.

#### static void intEnable(bool b)
Enable the SPI interrupt.

#### static void callback(callback_t callback, void\* data)
Set callback for serial transfer complete interrupt.

#### static void dataOrder(DataOrder d)
Set the data order msb/lsb first

#### static void masterSlave(MasterSlave m)
Set master or slave mode

#### static void polarity(Polarity p)
Set the clock polarity.

#### static void phase(Phase p)
Set the clock phase.

#### static void clock(Clock c)
Set the clock speed.

#### static bool intFlag()
Get the interrupt flag's state.

#### static void intFlagClear()
Clear the interrupt flag.

#### static bool collisionFlag()
Get the write collision flag's state.

#### static void collisionFlagClear()
Clear the write collision flag.

#### static void data(uint8_t d)
Put value d into the data register.

#### static uint8_t data()
Get value from the data register.
