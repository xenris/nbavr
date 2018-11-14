[Index](../index.hpp.md#index)

# Serial

```c++
const uint64_t cpuFreq = 16000000;
const Word32 baud = 115200;

nbos::Queue<Char, 40> coutQueue;
nbos::Atomic<nbos::Queue<Char>> cout(coutQueue);

nbos::Serial<nbos::hw::Usart0>::init(cpuFreq, baud, &cout.nonatomic());

cout << "5 * 3 = " << (5 * 3) << '\n';
```

## class Serial<class Usart>

#### static void init(Integer cpuFreq, Word32 baud, Queue<Char>* out, Queue<Char>* in);
