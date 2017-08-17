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
#### static constexpr HardwareType getHardwareType()
Get the type of hardware that this class represents.
#### static void enable(bool)
Enable/disable this interrupt.
#### static void trigger(Trigger)
Set the trigger action.
#### static void callback(void (\*)(void\*), void\*)
Set the callback and data for this interrupt.
#### static bool intFlag()
Returns true if the interrupt flag is set.
#### static void intFlagClear()
Clear the interrupt flag.
