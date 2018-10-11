# Queue

```c++
nbos::Queue<int, 6> queue;

queue.push(3);
queue.push(7);
queue.push(1);
queue.push(2);

int s = queue.size(); // s = 4

int a = 0;

queue.pop(&a); // a = 3
queue.pop(&a); // a = 7

s = queue.size(); // s = 2

nbos::Queue<int>* pointer = &queue;

pointer->push(4);

s = queue.size(); // s = 3
```

## class Queue<class Type, int bufferSize\>

#### Queue()
Construct a queue with space on the stack for the contents.

## class Queue<class Type\>

#### Queue(Type\* buffer, int bufferSize)
Construct a queue with the given buffer.

#### bool push(Type t)
Returns true on success.

#### bool pop(Type\* t)
Returns true on success.

#### bool peek(Type\* t)
Returns true on success.

#### void clear()
Remove all elements from the queue.

#### int size()
Get the number of elements currently in the queue.

#### int free()
Get the amount of free space in the queue.

### int capacity()
Get the total capacity of the queue.

#### bool empty()
Returns true if the queue is empty.

#### bool full()
Returns true if the queue is full.

#### void notify(callback_t callback, void\* data)
Set the callback function and data for queue notifications.

#### void notify()
Call the callback function previously given.
