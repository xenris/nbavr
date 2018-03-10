# Timer Output

## Example
```c++
// TODO
```

X is the output id (A, B, etc).<br>
T is the type of the output's register, either uint8_t or uint16_t.<br>

## class OutputX

#### type Pin
The IO pin which relates to this output.

#### enum Mode
* Disconnected
* Toggle
* Clear
* Set

#### static void value(T v)
Set the register of output X.

#### static T value()
Get the register of output X.

#### static void mode(Mode m)
Set the mode of output X.

#### static void callback(callback_t callback, void\* data)
Set the callback and data for output X interrupt.

#### static void intEnable(bool b)
Enable/disable the output X interrupt.

#### static bool intFlag()
Returns true if the output X interrupt flag is set.

#### static void intFlagClear()
Clear the output X interrupt flag.
