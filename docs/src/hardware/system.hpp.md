[Index](../../index.hpp.md#index)

# System

#### T bv(T n)
Equivalent to "1 << n".

#### void setBit(T\* register, Word8 bit, Bool value)
Set or clear a bit in a register immediately.

#### void setBit_(T\* register, Word8 bit, Bool value)
Set or clear a bit in a register lazily.
(i.e. Allow compiler to rearrange and combine instructions for faster code.)

#### void delay<Word64 cpuFreq, Word64 ns>()
Delays the cpu for the given number of nanoseconds.<br>
Should only be used for very short delays.<br>
Limited to 10 milliseconds.<br>
Rounds to the nearest possible delay time. e.g. at 16MHz, delay<50>() will
delay for 62.5 nanoseconds (1 cpu clock cycle).<br>
Is limited further by faster clock speeds. e.g. at 100MHz it will be limited to 2621434ns.

#### void interruptsEnable(Bool)
Enable/disable interrupts.

#### Bool interruptsEnabled()
Returns true if interrupts are enabled.
