# Input Capture

## class InputCapture

#### enum Edge
* Rising
* Falling

#### static void value(uint16_t v)
Set the input capture register.

#### static uint16_t value()
Get the input capture register.

#### static void edge(Edge e)
Set the trigger edge.

#### static void callback(callback_t callback, void\* data)
Set the callback and data for int input capture interrupt.

#### static void intEnable(bool b)
Enable/disable the input capture interrupt.

#### static bool intFlag()
Returns true if the input capture interrupt flag is set.

#### static void intFlagClear()
Clear the input capture interrupt flag.
