# Timer Input

## class Input

#### type Pin
The IO pin which relates to this input.

#### enum Edge
* rising
* falling

#### static void value(T v)
Set the input register.

#### static T value()
Get the input register.

#### static void edge(Edge e)
Set the trigger edge.

#### static void callback(callback_t callback, void\* data)
Set the callback and data for int input interrupt.

#### static void intEnable(bool b)
Enable/disable the input interrupt.

#### static bool intFlag()
Returns true if the input interrupt flag is set.

#### static void intFlagClear()
Clear the input interrupt flag.
