# External Interrupts

N is the external interrupt id (1, 2, etc).

#### macro INCLUDE_EXINT_CALLBACK(N)
Include this to use ExInt callbacks.

## class ExIntN

#### enum Trigger
* low
* change
* falling
* rising

#### static constexpr HardwareType getHardwareType()
Get the type of hardware that this class represents.

#### static void enable(bool e)
Enable/disable this interrupt.

#### static void trigger(Trigger t)
Set the trigger action.

#### static void callback(callback_t callback, void\* data)
Set the callback and data for this interrupt.

#### static bool intFlag()
Returns true if the interrupt flag is set.

#### static void intFlagClear()
Clear the interrupt flag.
