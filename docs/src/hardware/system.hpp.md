[Index](../../index.hpp.md#index)

# System

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
