# Output Compares

## Example
```c++
// TODO
```

X is the output compare id (A, B, etc).<br>
T is the type of the output compare's register, either uint8_t or uint16_t.<br>

## class OutputCompareX

#### type Pin
The IO pin which relates to this output compare.

#### enum Mode
* Disconnected
* Toggle
* Clear
* Set

#### static void value(T v)
Set the compare register of output compare X.

#### static T value()
Get the compare register of output compare X.

#### static void mode(Mode m)
Set the mode of output compare X.

#### static void callback(callback_t callback, void\* data)
Set the callback and data for output compare X interrupt.

#### static void intEnable(bool b)
Enable/disable the output compare X interrupt.

#### static bool intFlag()
Returns true if the output compare X interrupt flag is set.

#### static void intFlagClear()
Clear the output compare X interrupt flag.
