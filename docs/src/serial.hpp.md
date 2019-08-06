[Index](../index.hpp.md#index)

# Serial

```c++
const uint64_t cpuFreq = 16000000;
const uint32_t baud = 115200;

nblib::Queue<char, 40> coutQueue;
nblib::Atomic<nblib::Queue<char>> cout(coutQueue);

nblib::Serial<nblib::hw::Usart0>::init(cpuFreq, baud, &cout.nonatomic());

cout << "5 * 3 = " << (5 * 3) << '\n';
```

## class Serial<class Usart>

#### static void init(uint64_t cpuFreq, uint32_t baud, Queue<char>* out, Queue<char>* in);
