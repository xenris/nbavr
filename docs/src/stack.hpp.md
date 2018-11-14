[Index](../index.hpp.md#index)

# Stack

```c++
nbos::Stack<Int, 6> stack;

stack.push(3);
stack.push(7);
stack.push(1);
stack.push(2);

Int s = stack.size(); // s = 4

Int a = 0;

stack.pop(&a); // a = 2
stack.pop(&a); // a = 1

s = stack.size(); // s = 2

nbos::Stack<Int>* pointer = &stack;

pointer->push(4);

s = stack.size(); // s = 3
```

## class Stack<class Type, Int bufferSize\>

#### Stack()
Construct a stack with space on the system stack for the contents.

## class Stack

#### Stack(Type\* buffer, Int bufferSize)
Construct a stack with the given buffer.

#### Bool push(Type t)
Returns true on success.

#### [Optional](optional.hpp.md#class-optionalclass-t)<Type\> pop()

#### [Optional](optional.hpp.md#class-optionalclass-t)<Type\> peek()

#### void clear()
Remove all elements from the stack.

#### Int size()
Get the number of elements currently in the stack.

#### Int free()
Get the amount of free space in the stack.

### Int capacity()
Get the total capacity of the stack.

#### Bool empty()
Returns true if the stack is empty.

#### Bool full()
Returns true if the stack is full.
