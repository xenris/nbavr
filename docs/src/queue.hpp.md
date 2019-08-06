[Index](../index.hpp.md#index)

# Queue

```c++
nblib::Queue<int, 6> queue;

queue.push(3);
queue.push(7);
queue.push(1);
queue.push(2);

int s = queue.size(); // s = 4

int a = 0;

queue.pop(&a); // a = 3
queue.pop(&a); // a = 7

s = queue.size(); // s = 2

nblib::Queue<int>* pointer = &queue;

pointer->push(4);

s = queue.size(); // s = 3
```

## class Queue<class Type, size_t bufferSize\>

#### Queue()
Construct a queue with space on the stack for the contents.

## class Queue<class Type\>

#### Queue(Type\* buffer, size_t bufferSize)
Construct a queue with the given buffer.

#### bool push(Type t)
Returns true on success.

#### T\* push()
Pushes an uninitialised element to the queue and returns a pointer to it.<br>
Useful to avoid copying large blocks of memory if the elements are large.<br>
Returns nullptr if the queue is full.

#### [Optional](optional.hpp.md#class-optionalclass-t)<Type\> pop()

#### [Optional](optional.hpp.md#class-optionalclass-t)<Type\> peek()

#### Type\* peek()

#### void clear()
Remove all elements from the queue.

#### size_t size()
Get the number of elements currently in the queue.

#### size_t free()
Get the amount of free space in the queue.

### size_t capacity()
Get the total capacity of the queue.

#### bool empty()
Returns true if the queue is empty.

#### bool full()
Returns true if the queue is full.

#### void setCallback(Callback callback, T\* data)
Set the callback function and data for queue notifications.

#### void callCallback()
Call the callback notification function.
