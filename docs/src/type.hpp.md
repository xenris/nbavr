[Index](../index.hpp.md#index)

# Types

#### using callback_t = void (*)(void*)

## class Optional<class T>
Class who's value can be either something or nothing.

```c++
Optional<int> o;

bool b = o; // b = false

o = 5;

b = o; // b = true

int a = *b; // a = 5
int x = b; // x = 1 (a.k.a. true)

o = {};

b = o; // b = false
```

#### Optional()
Constructor for "nothing"

#### Optional(T value)
Constructor for "something"

#### operator bool()
True if "something", false if "nothing".

#### T operator *()
Returns the stored value.
