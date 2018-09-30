# SPI

N is the USI id (0, 1, 2, etc).

#### macro INCLUDE_USI_CALLBACK(N, X)
Include this to use Usi callbacks.<br>
N is the Usi id, X is one of START or OVERFLOW.

## class UsiN

#### type PinDo
The DO IO pin.

#### type PinDi
The DI IO pin.

#### type PinSda
The SDA IO pin.

#### type PinScl
The SCL IO pin.

#### type PinUsck
The USCK IO pin.

#### enum WireMode
* disabled
* threeWire
* twoWire
* twoWireOverflow

#### enum Clock
* none
* timer0CompareMatch
* externalPositiveEdge
* externalNegativeEdge

#### static constexpr HardwareType getHardwareType()
Get the type of hardware that this class represents.

#### static void data(uint8_t d)
Put value d into the data register.

#### static uint8_t data()
Get value from the data register.

#### static void startConditionIntEnable(bool b)
Enable the start condition interrupt.

#### static void counterOverflowIntEnable(bool b)
Enable the counter overflow interrupt.

#### static void wireMode(WireMode m)
Set the USI interface mode.

#### static void clock(Clock c)
Set the clock source.

#### static void clockStrobe()
Increment counter and Shift the USI data register.

#### static void toggleClockPin()
Toggle the clock pin or increment the counter

#### static void startConditionIntFlag()
Get the start condition interrupt flag's state.

#### static void startConditionIntFlagClear()
Clear the start condition interrupt flag.

#### static void stopConditionIntFlag()
Get the stop condition interrupt flag's state.

#### static void stopConditionIntFlagClear()
Clear the stop condition interrupt flag.

#### static bool counterOverflowIntFlag()
Get the counter overflow interrupt flag's state.

#### static void counterOverflowIntFlagClear()
Clear the counter overflow interrupt flag.

#### static bool collisionFlag()
Get the data output collision flag's state.

#### static void counter(uint8_t c)
Set the counter register.

#### static uint8_t counter()
Get the counter register.

#### static void startConditionCallback(callback_t callback, void\* data)
Set callback for start condition interrupt.

#### static void counterOverflowCallback(callback_t callback, void\* data)
Set callback for timer overflow interrupt.
