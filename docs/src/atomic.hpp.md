[Index](../index.hpp.md#index)

# Atomic

Used to access variables atomically.

```c++
Atomic<Int32> counter = 0;

Int32 c = counter;
counter += 2;
Bool b = (counter == 5);
counter->nonatomic()++;

struct S {
    Int32 f(Int32 n)
        return n + 1;
    }
}

Atomic<S> s;

Int32 i = s.call(&S::f, 100);
```

## class Atomic<class Type\>

#### Atomic()

#### Atomic(Type t)

#### Atomic<Type>& operator=(Type t)

#### operator Type()
Returns a copy of the value.

#### Type getSet(Type t)
Sets the value to t, and returns the previous value.

#### Atomic<Type\>& operator+=(Type t)

#### Atomic<Type\>& operator-=(Type t)

#### Atomic<Type\>& operator*=(Type t)

#### Atomic<Type\>& operator/=(Type t)

#### Atomic<Type\>& operator++()

#### Atomic<Type\>& operator--()

#### Atomic<Type\>& operator<<<U\>(U u)

#### auto call(F f, ...)
Call member function f with arguments atomically.

#### Type& operator \*()
Non-atomic access to the value.
