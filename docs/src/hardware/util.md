# Util

#### T bv(T n)
Equivalent to "1 << n", but works with types bigger than int.

#### void setBit(volatile T\* register, uint8_t bit, bool value)
Set or clear a bit in a volatile register immediately.

#### void setBit_(volatile T\* register, uint8_t bit, bool value)
Set or clear a bit in a volatile register lazily.
(i.e. Allow compiler to rearrange and combine instructions.)

#### void getBit(volatile T\* register, uint8_t bit)
Get a bit from a volatile register.

#### void interruptsEnable()
Globally enable interrupts.

#### void interruptsEnabled()
Globally enable interrupts.

#### macro block
Make sure an expression or block of expressions is compiled in the order it is written in.
i.e. Prevents the compiler from doing memory access optimisations which reorder code.
