# System

#### T bv(T n)
Equivalent to "1 << n", but works with types bigger than int.

#### void setBit(volatile T\* register, uint8_t bit, bool value)
Set or clear a bit in a volatile register immediately.

#### void setBit_(volatile T\* register, uint8_t bit, bool value)
Set or clear a bit in a volatile register lazily.
(i.e. Allow compiler to rearrange and combine instructions.)

#### void getBit(volatile T\* register, uint8_t bit)
Get a bit from a volatile register.

#### void interruptsEnable(bool)
Globally enable/disable interrupts.

#### void interruptsEnabled()
Globally enable interrupts.

#### auto atomic<F>(F f)
Run function f atomically.<br>
Returns the value returned by f.

#### void block()
Make sure an expression or block of expressions is compiled in the order it is written in.
i.e. Prevents the compiler from doing memory access optimisations which reorder code.

#### auto block<F>(F f)

#### void delay<uint64_t cpuFreq, uint64_t ns>()
Delays the cpu for the given number of nanoseconds.<br>
Should only be used for very short delays.<br>
Limited to 10 milliseconds.<br>
Rounds to the nearest possible delay time. e.g. at 16MHz, delay<50>() will
delay for 62.5 nanoseconds (1 cpu clock cycle).<br>
Is limited further by faster clock speeds. e.g. at 100MHz it will be limited to 2621434ns.
