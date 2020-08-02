[Index](../index.hpp.md#index)

# Macros

#### force_inline
Force a function to always be inlined. Use like "inline".

#### ssize_t ssizeof(T)
Signed version of sizeof.

#### CAT(...)
Concatenates a list of identifiers together.<br>
e.g. CAT(Foo, Bar) -> FooBar

#### UNDERLINE(...)
Concatenates a list of identifiers together with underlines.<br>
e.g. UNDERLINE(Foo, Bar) -> _Foo_Bar_

#### TO_LETTER(N)
Convert a number to its equivalent letter. Starts at 0.<br>
e.g. TO_LETTER(4) -> E

#### TO_NUMBER(L)
Convert a letter to its equivalent number.<br>
e.g. TO_NUMBER(E) -> 4

#### INC(N)
Increment a number. Input ranges from 0 to 39.<br>
e.g. INC(4) -> 5

#### DEC(N)
Decrement a number. Input ranges from 1 to 40.<br>
e.g. DEC(4) -> 3

#### DEFINED(A)
If A evaluates to any number or nothing -> true<br>
If A evaluates to something which is not defined -> false<br>
e.g. DEFINED(CAT(SOME_, MACRO_, THING)) -> false (unless "SOME_MACRO_THING" is #defined somewhere).<br>
Only usable when the value evaluates to a number, nothing, or is not defined.<br>
e.g. DEFINED(force_inline) -> error! Use "defined(force_inline)" instead<br>
0 is also true.<br>
e.g. DEFINED(0) -> true

#### REG_DEFINED(A)
If A evaluates to a register -> true<br>
e.g. REG_DEFINED(CHIP_REG_ADC) -> true (On devices with that register.)<br>
Note: Register at address 0x00 will always return false.
