# Array

## class Array<class T, int S>

#### type size_t
The smallest signed integer type which can index the entire array.

#### type type
The type that the array contains.

#### T& operator[](size_t i)
Element access operator.<br>
i is clipped to array length.

#### void fill(T t)
Fills the array with value t.

#### size_t size()
Returns the length of the array.
