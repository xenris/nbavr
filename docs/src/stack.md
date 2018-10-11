# Stack

```c++
nbos::Stack<int, 6> stack;

stack.push(3);
stack.push(7);
stack.push(1);
stack.push(2);

int s = stack.size(); // s = 4

int a = 0;

stack.pop(&a); // a = 2
stack.pop(&a); // a = 1

s = stack.size(); // s = 2

nbos::Stack<int>* pointer = &stack;

pointer->push(4);

s = stack.size(); // s = 3
```

## class Stack<class Type, int bufferSize\>

#### Stack()
Construct a stack with space on the system stack for the contents.

## class Stack

#### Stack(Type\* buffer, int bufferSize)
Construct a stack with the given buffer.

#### bool push(Type t)
Returns true on success.

#### bool pop(Type\* t)
Returns true on success.

#### bool peek(Type\* t)
Returns true on success.

#### void clear()
Remove all elements from the stack.

#### int size()
Get the number of elements currently in the stack.

#### int free()
Get the amount of free space in the stack.

### int capacity()
Get the total capacity of the stack.

#### bool empty()
Returns true if the stack is empty.

#### bool full()
Returns true if the stack is full.
