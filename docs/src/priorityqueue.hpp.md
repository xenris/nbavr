[Index](../index.hpp.md#index)

# Priority Queue

```c++
nbos::PriorityQueue<int, 6> priorityQueue;

priorityQueue.push(6);
priorityQueue.push(8);
priorityQueue.push(4);
priorityQueue.push(5);
priorityQueue.push(1);
priorityQueue.push(2);

nbos::PriorityQueue<int>* pointer = &priorityQueue;

int n;

while(pointer->pop(&n)) {
    // 1, 2, 4, 5, 6, 8
}
```

## class PriorityQueue<class Type, int size\>

#### PriorityQueue()
Construct a priority queue with space on the stack for the contents.

## class PriorityQueue<class Type\>

#### PriorityQueue(T\* buffer, int size)
Construct a priority queue with the given buffer.

#### bool push(T t)
Returns true on success.

#### bool pop(T\* t)
Returns true on success.

#### bool peek(T\* t)
Returns true on success.

#### void clear()
Remove all elements from the priority queue.

#### int size()
Get the number of elements currently in the priority queue.

#### int free()
Get the amount of free space in the priority queue.

#### int capacity()
Get the total capacity of the priority queue.

#### bool empty()
Returns true if the priority queue is empty.

#### bool full()
Returns true if the priority queue is full.

#### void compare(bool (*f)(const T& a, const T& b))
Set the function used to compare elements.

#### bool compare(T a, T b)
Returns true if a comes before b.
