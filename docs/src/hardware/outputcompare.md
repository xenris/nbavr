# Output Compares
## Example
```c++
// TODO
```
X is the output compare id (A, B, etc).<br>
T is the type of the output compare's register, either uint8_t or uint16_t.<br>
## class OutputCompareX
#### static void value(T)
Set the compare register of output compare X.

#### static T value()
Get the compare register of output compare X.

#### static void mode(OutputMode)
Set the mode of output compare X.

#### static void callback(void (\*)(void\*), void\*)
Set the callback and data for output compare X interrupt.

#### static void intEnable(bool)
Enable/disable the output compare X interrupt.

#### static bool intFlag()
Returns true if the output compare X interrupt flag is set.

#### static void intFlagClear()
Clear the output compare X interrupt flag.
