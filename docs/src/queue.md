# Queue

Queues are first in first out containers.

All functions are atomic (i.e. interrupt safe). Equivalient non-atomic functions
have \_ after the function name, e.g. queue.push\_(t).

## class Queue\<class Type, int Size\>

#### size_t
The smallest signed integer type which can represent the queue's size.

#### type
The type of the Queue.

#### bool push(T t)
Add a value to the queue.<br>
Returns true on success.

#### bool pop(T\* t)
Get the next value from the queue.<br>
Returns true on success.

#### bool pop()
Removes the next value from the queue.<br>
Returns true on success.

#### bool peek(T\* t)
Get the next value from the queue, but don't remove it.<br>
Returns true on success.

#### void clear()
Remove all elements from the queue.

#### size_t size()
Get the number of elements currently in the queue.

#### size_t free()
Get the amount of free space in the queue.

### static constexpr size_t capacity()
Get the total capacity of the queue.

#### bool empty()
Returns true if the queue is empty.

#### bool full()
Returns true if the queue is full.

#### void setNotify(callback_t callback, void\* data)
Set the callback function and data for queue notifications.

#### void notify()
Call the notification callback.
