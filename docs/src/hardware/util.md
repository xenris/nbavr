# Util

#### T bv(T n)
Equivalent to "1 << n", but works with types bigger than int.

#### void cli()
Clear the global interrupt flag.

#### void sei()
Set the global interrupt flag.

#### void setBit(volatile uint8_t\* register, uint8_t bit, bool value)
Set or clear a bit in a volatile register immediately.

#### void setBit_(volatile uint8_t\* register, uint8_t bit, bool value)
Set or clear a bit in a volatile register lazily.
(i.e. Allow compiler to rearrange instructions.)
