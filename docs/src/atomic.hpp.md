# Atomic

Used to access variables atomically.

```c++
Atomic<int32_t> counter = 0;

int32_t c = counter;
counter += 2;
bool b = (counter == 5);
counter->nonatomic()++;

struct S {
    int f(int n)
        return n + 1;
    }
}

Atomic<S> s;

int i = s.call(&S::f, 100);
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

#### Type& nonatomic()
Non-atomic access to the value.
