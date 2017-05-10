# Pin Change Interrupts
All functions are static.
#### macro INCLUDE_PCINT_CALLBACK(N)
Include this to use PcInt callbacks.
## Class PCIntN
#### constexpr HardwareType getHardwareType()
Get the type of hardware that this class represents.
#### void enable(bool)
Enable/disable this interrupt.
#### void mask(uint8_t)
Set which pins trigger this interrupt.
#### void callback(void (\*)(void\*), void\*)
Set the callback and data for this interrupt.
#### bool intFlag()
Returns true if the interrupt flag is set.
#### void intFlagClear()
Clear the interrupt flag.
