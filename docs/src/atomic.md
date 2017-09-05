# Atomic
Used to access variables atomically.<br>

## Example
```c++
Atomic<int32_t> counter = 0;

void loop {
    int32_t c = counter;
    int32_t c = counter.getSet(0);
    counter += 2;
    if(counter == 5) {

    }
}

// Interrupt.
static void callback(void* data) {
    counter.direct()++;
}
```
## class Atomic<class T>
#### T getSet(T t)
Sets the value to t, and returns its previous value.
#### T& direct()
Non-atomic access to the value.
