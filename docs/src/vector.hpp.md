[Index](../index.hpp.md#index)

# Vector

```c++
nbos::Vector<int, 6> vector;

vector.add(3);
vector.add(7);
vector.add(1);
vector.add(2);

int s = vector.size(); // s = 4

const int a = vector[1]; // a = 7

nbos::Vector<int>* pointer = &vector;

pointer->add(4);

const int b = pointer->get(2); // b = 1

s = vector.size(); // s = 5
```

## class Vector<class Type, int bufferSize\>

#### Vector()
Construct a vector with space on the stack for the contents.

## class Vector<class Type\>

#### Vector(Type\* buffer, int bufferSize)
Construct a vector with the given buffer.

#### bool add(Type t)
Returns true on success.

#### void fill(const Type& t) {
Fills the entire buffer with the given value.

#### void clear() {
Remove all elements from the vector.

#### int size()
Get the number of elements currently in the vector.

#### bool resize(int size)
Set the size of the vector.<br>
Returns false, and doesn't change the size if the given size is larger than the buffer.

#### int free()
Get the amount of free space in the vector.

### int capacity()
Get the total capacity of the vector.

#### bool empty()
Returns true if the vector is empty.

#### bool full()
Returns true if the vector is full.

#### Type& operator [](int n)

#### Type\* begin()

#### Type\* end()

#### Vector<Type\>& operator =(Vector<Type\> other)
