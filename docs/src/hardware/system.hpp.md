[Index](../../index.hpp.md#index)

# System

### atomic\(expr\)
Disables interrupts while accessing/evaluating "expr".<br>
Required when accessing variables which are shared with interrupt callbacks. e.g.
```c++
int localVariable = atomic(globalVariable);
// Or
int localVariable = atomic(globalVariable, 0);
// to get and set the value atomically.
```

### atomic\(\) \{expr1; expr2; expr3; etc...\}
Disables interrupts while running a block of code.

### non_atomic\(expr\)
Inverse of atomic.

### non_atomic\(\) \{expr1; expr2; expr3; etc...\}
Inverse of atomic.

### block\(expr\)
Prevents the expression from being optimised into the code around it. e.g.
```c++
LedPin::output(LedPin::Value::high);
LedPin::output(LedPin::Value::low);
```
will only set the pin low, because the compiler saw that this was the overall effect of the expressions. Whereas:
```c++
block(LedPin::output(LedPin::Value::high));
block(LedPin::output(LedPin::Value::low));
```
will set the pin high, then low:

### block\(\) \{expr1; expr2; expr3; etc...\}
Same as block(expr), but allows several expressions to be optimised together, separate to any code around it.

#### T bv(int n)
Equivalent to "1 << n".

#### void setBit(T\* register, uint8_t bit, bool value)
Set or clear a bit in a register immediately.

#### void setBit_(T\* register, uint8_t bit, bool value)
Set or clear a bit in a register lazily.
(i.e. Allow compiler to rearrange and combine instructions for faster code.)

#### void getBit(T\* register, uint8_t bit)
Get a bit in a register immediately.

#### void getBit_(T\* register, uint8_t bit)
Get a bit in a register lazily.
(i.e. Allow compiler to rearrange and combine instructions for faster code.)

#### void clearFlagBit(T\* register, uint8_t bit)
Clear a flag bit in a flag register.

#### void setReg(T\* register, T value)
Set the value of a register immediately.

#### void setReg_(T\* register, T value)
Set the value of a register lazily.
(i.e. Allow compiler to rearrange and combine instructions for faster code.)

#### void getReg(T\* register)
Get the value of a register immediately.

#### void getReg_(T\* register)
Get the value of a register lazily.
(i.e. Allow compiler to rearrange and combine instructions for faster code.)

#### void delay<uint64_t cpuFreq, uint64_t ns>()
Delays the cpu for the given number of nanoseconds.<br>
Should only be used for very short delays.<br>
Limited to 10 milliseconds.<br>
Rounds to the nearest possible delay time. e.g. at 16MHz, delay<50>() will
delay for 62.5 nanoseconds (1 cpu clock cycle).<br>
Is limited further by faster clock speeds. e.g. at 100MHz it will be limited to 2621434ns.

#### void interruptsEnable(bool)
Enable/disable interrupts.

#### bool interruptsEnabled()
Returns true if interrupts are enabled.
