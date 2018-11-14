[Index](../index.hpp.md#index)

# Vector

```c++
nbos::Vector<Int, 6> vector;

vector.add(3);
vector.add(7);
vector.add(1);
vector.add(2);

Int s = vector.size(); // s = 4

const Int a = vector[1]; // a = 7

nbos::Vector<Int>* pointer = &vector;

pointer->add(4);

const Int b = pointer->get(2); // b = 1

s = vector.size(); // s = 5
```

## class Vector<class Type, Int bufferSize\>

#### Vector()
Construct a vector with space on the stack for the contents.

## class Vector<class Type\>

#### Vector(Type\* buffer, Int bufferSize)
Construct a vector with the given buffer.

#### Bool add(Type t)
Returns true on success.

#### void fill(const Type& t) {
Fills the entire buffer with the given value.

#### void clear() {
Remove all elements from the vector.

#### Int size()
Get the number of elements currently in the vector.

#### Bool resize(Int size)
Set the size of the vector.<br>
Returns false, and doesn't change the size if the given size is larger than the buffer.

#### Int free()
Get the amount of free space in the vector.

### Int capacity()
Get the total capacity of the vector.

#### Bool empty()
Returns true if the vector is empty.

#### Bool full()
Returns true if the vector is full.

#### Type& operator [](Int n)

#### Type\* begin()

#### Type\* end()

#### Vector<Type\>& operator =(Vector<Type\> other)
