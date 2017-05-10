# Util
#### macro CONCAT(...)
Concatinates a list of identifiers together.<br>
e.g. CONCAT(Foo, Bar) -> FooBar
#### macro force_inline
Force a function to always be inlined. Use like "inline".
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
#### T max(T, T)
Get the bigger of the two values.
#### T max(T, T)
Get the smaller of the two values.
#### T clip(T x, T l, T h)
Clip x between l and h.
#### T abs(T)
Get the absolute (positive) value.
#### void setBit(volatile uint8_t* register, uint8_t bit, bool)
Set or clear a bit in a volatile register immediately.
#### void setBit_(volatile uint8_t* register, uint8_t bit, bool)
Set or clear a bit in a volatile register lazily.
(i.e. Allow compiler to rearrange instructions.)
