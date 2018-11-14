## class Optional<class T\>
Class who's value can be either something or nothing.

```c++
Optional<Int32> o;

Bool b = o; // b = false

o = 5;

b = o; // b = true

Int32 a = *b; // a = 5
Int32 x = b; // x = 1 (a.k.a. true)

o = {};

b = o; // b = false
```

#### Optional()
Constructor for "nothing"

#### Optional(T value)
Constructor for "something"

#### operator primitive_bool()
True if "something", false if "nothing".

#### T operator *()
Returns the stored value.

#### T\* operator ->()
Pointer access to the stored value.
