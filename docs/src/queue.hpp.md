[Index](../index.hpp.md#index)

# Queue

```c++
nbos::Queue<Int32, 6> queue;

queue.push(3);
queue.push(7);
queue.push(1);
queue.push(2);

Int s = queue.size(); // s = 4

Int32 a = 0;

queue.pop(&a); // a = 3
queue.pop(&a); // a = 7

s = queue.size(); // s = 2

nbos::Queue<Int32>* pointer = &queue;

pointer->push(4);

s = queue.size(); // s = 3
```

## class Queue<class Type, Int bufferSize\>

#### Queue()
Construct a queue with space on the stack for the contents.

## class Queue<class Type\>

#### Queue(Type\* buffer, Int bufferSize)
Construct a queue with the given buffer.

#### Bool push(Type t)
Returns true on success.

#### [Optional](optional.hpp.md#class-optionalclass-t)<Type\> pop()

#### [Optional](optional.hpp.md#class-optionalclass-t)<Type\> peek()

#### void clear()
Remove all elements from the queue.

#### Int size()
Get the number of elements currently in the queue.

#### Int free()
Get the amount of free space in the queue.

### Int capacity()
Get the total capacity of the queue.

#### Bool empty()
Returns true if the queue is empty.

#### Bool full()
Returns true if the queue is full.

#### void setCallback(Callback callback, T\* data)
Set the callback function and data for queue notifications.

#### void callCallback()
Call the callback notification function.
