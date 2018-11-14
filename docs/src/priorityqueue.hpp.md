[Index](../index.hpp.md#index)

# Priority Queue

```c++
nbos::PriorityQueue<Int32, 6> priorityQueue;

priorityQueue.push(6);
priorityQueue.push(8);
priorityQueue.push(4);
priorityQueue.push(5);
priorityQueue.push(1);
priorityQueue.push(2);

nbos::PriorityQueue<Int32>* pointer = &priorityQueue;

Int32 n;

while(pointer->pop(&n)) {
    // 1, 2, 4, 5, 6, 8
}
```

## class PriorityQueue<class Type, Int size\>

#### PriorityQueue()
Construct a priority queue with space on the stack for the contents.

## class PriorityQueue<class Type\>

#### PriorityQueue(T\* buffer, Int size)
Construct a priority queue with the given buffer.

#### Bool push(T t)
Returns true on success.

#### [Optional](optional.hpp.md#class-optionalclass-t)<Type> pop()

#### [Optional](optional.hpp.md#class-optionalclass-t)<Type\> peek()

#### void clear()
Remove all elements from the priority queue.

#### Int size()
Get the number of elements currently in the priority queue.

#### Int free()
Get the amount of free space in the priority queue.

#### Int capacity()
Get the total capacity of the priority queue.

#### Bool empty()
Returns true if the priority queue is empty.

#### Bool full()
Returns true if the priority queue is full.

#### void compare(Bool (*f)(const T& a, const T& b))
Set the function used to compare elements.

#### Bool compare(T a, T b)
Returns true if a comes before b.
