# Nbavr

## Example
```c++
const uint32_t CpuFreq = 16000000;

typedef TimerCounter1 systemTimer;

typedef Nbavr<systemTimer, CpuFreq> Nbavr;

uint32_t ticks = Nbavr::getTicks();

uint32_t millis = Nbavr::ticksToMillis(tick);
```
Every clock cycle is 1 / freq seconds. (62.5ns at 16MHz)<br>
Every 64 clock cycles is a tick. (4us at 16MHz)<br>
Every 2^16 ticks is a tock. (262.144ms at 16MHz)<br>
Every 2^32 ticks the clock overflows. (4.77 hours at 16Mhz)
## class Nbavr<class TimerCounter, uint32_t CpuFreq>
#### static void init()
Initialises the Nbavr singleton and the clock.
#### static constexpr uint32_t millisToTicks(uint32_t ms)
Converts milliseconds to ticks.
#### static constexpr uint32_t ticksToMillis(uint32_t ms)
Converts ticks to milliseconds.
#### static uint16_t getTicks16()
Gets the current value of the 16 bit tick counter.<br>
Wraps every 2^16 ticks. (262.144ms at 16MHz)
#### static uint32_t getTicks()
Gets the current value of the 32 bit tick counter.<br>
Wraps every 2^32 ticks. (4.77 hours at 16Mhz)
#### static uint16_t getTocks()
Gets the current value of the 16 bit tock counter.<br>
Wraps every 2^16 tocks. (4.77 hours at 16Mhz)
#### static bool addInterrupt(void (*callback)(void*), void* data, uint16_t delay)
Add a tick precision interrupt.<br>
Returns true if successful.
