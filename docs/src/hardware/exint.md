# External Interrupts
N is the external interrupt id (1, 2, etc).<br>
All functions are static.
#### macro INCLUDE_EXINT_CALLBACK(N)
Include this to use ExInt callbacks.
## class ExIntN
#### enum Trigger
* Low
* Change
* Falling
* Rising
#### constexpr HardwareType getHardwareType()
Get the type of hardware that this class represents.
#### void enable(bool)
Enable/disable this interrupt.
#### void trigger(Trigger)
Set the trigger action.
#### void callback(void (\*)(void\*), void\*)
Set the callback and data for this interrupt.
#### bool intFlag()
Returns true if the interrupt flag is set.
#### void intFlagClear()
Clear the interrupt flag.
