# Clock

## Example

```c++
const uint32_t CpuFreq = 16000000;

using LedPin = nbos::PinB5;
using SystemTimer = nbos::TimerCounter1;

using Clock = nbos::Clock<SystemTimer, CpuFreq>;

Flash<Clock, LedPin> flash;

nbos::Task<Clock>* tasks[] = {&flash};

nbos::TaskManager<Clock> tm(tasks);

// Within Flash::loop()
uint32_t ticks = Clock::getTicks();
uint32_t millis = Clock::ticksToMillis(ticks);
```

Every cpu clock cycle is 1 / freq seconds. (62.5ns at 16MHz)<br>
Every 64 clock cycles is a tick. (4us at 16MHz)<br>
Every 2^16 ticks is a tock. (262.144ms at 16MHz)<br>
Every 2^32 ticks the clock overflows. (4.77 hours at 16Mhz)

If Clock is given an 8 bit timer (rather than 16 bit) each tick will be
4x longer.

## class Clock\<class Timer, uint32_t CpuFreq, int MaxCalls = 8\>

#### static constexpr uint32_t millisToTicks(uint32_t ms)
Convert milliseconds to ticks.

#### static constexpr uint32_t microsToTicks(uint32_t us)
Convert microseconds to ticks.

#### static constexpr uint32_t ticksToMillis(uint32_t ticks)
Convert ticks to milliseconds.

#### static constexpr uint32_t ticksToMicros(uint32_t ticks)
Convert ticks to microseconds.

#### static uint16_t getTicks16()
Gets the current value of the 16 bit tick counter.<br>
Wraps every 2^16 ticks. (262.144ms at 16MHz)

#### static uint32_t getTicks()
Gets the current value of the 32 bit tick counter.<br>
Wraps every 2^32 ticks. (4.77 hours at 16Mhz)

#### static uint32_t getTicks_()
Non-atomic version of getTicks().

#### static uint16_t getTocks()
Gets the current value of the 16 bit tock counter.<br>
Wraps every 2^16 tocks. (4.77 hours at 16Mhz)

#### static uint16_t getTocks_()
Non-atomic version of getTocks().

#### static bool delayedCall(callback_t callback, void* data, int32_t delay)
Add a callback to call after delay ticks.<br>
Returns true if successful added.

#### static bool delayedCall_(callback_t callback, void* data, int32_t delay)
Non-atomic version of delayedCall().
Returns true if successful added.

#### static void delay<uint32_t ns>()
Delays the cpu for the given number of nanoseconds.<br>
Should only be used for very short delays.<br>
Limited to 2 milliseconds.<br>
Rounds to the nearest possible delay. E.g. at 16MHz, delay<50>() will
delay for 62.5 nanoseconds (1 cpu clock cycle).
