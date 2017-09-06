# Pin Change Interrupts

#### macro INCLUDE_PCINT_CALLBACK(N)
Include this to use PcInt callbacks.

## Class PCIntN

#### static constexpr HardwareType getHardwareType()
Get the type of hardware that this class represents.

#### static void enable(bool e)
Enable/disable this interrupt.

#### static void mask(uint8_t m)
Set which pins trigger this interrupt.

#### static void callback(callback_t callback, void\* data)
Set the callback and data for this interrupt.

#### static bool intFlag()
Returns true if the interrupt flag is set.

#### static void intFlagClear()
Clear the interrupt flag.
