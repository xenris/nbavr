# Util

#### macro force_inline
Force a function to always be inlined. Use like "inline".

#### T bv(T n)
Equivalent to "1 << n", but works with types bigger than int.

#### void cli()
Clear the global interrupt flag.

#### void sei()
Set the global interrupt flag.

#### macro atomic
Make sure an expression or block of expressions run with global interrupts disabled.

#### macro nonatomic
Make sure an expression or block of expressions run with global interrupts enabled.

#### macro block
Make sure an expression or block of expressions is compiled in the order it is written in.
i.e. Prevents the compiler from doing memory accesses optimisations that reorder code.

#### void setBit(volatile uint8_t\* register, uint8_t bit, bool value)
Set or clear a bit in a volatile register immediately.

#### void setBit_(volatile uint8_t\* register, uint8_t bit, bool value)
Set or clear a bit in a volatile register lazily.
(i.e. Allow compiler to rearrange instructions.)
