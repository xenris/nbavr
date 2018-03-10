#### macro force_inline
Force a function to always be inlined. Use like "inline".

#### macro atomic
Make sure an expression or block of expressions run with global interrupts disabled.

#### macro nonatomic
Make sure an expression or block of expressions run with global interrupts enabled.

#### macro block
Make sure an expression or block of expressions is compiled in the order it is written in.
i.e. Prevents the compiler from doing memory accesses optimisations that reorder code.

#### macro CAT(...)
Concatinates a list of identifiers together.<br>
e.g. CAT(Foo, Bar) -> FooBar
