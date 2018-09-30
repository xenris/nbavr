# Clock

Useful class for managing the passing of time.<br>
Required by TaskManager.

## Example

```c++
const uint64_t cpuFreq = 16000000;

using SystemTimer = nbos::hw::Timer1;

using Clock = nbos::Clock<SystemTimer, cpuFreq>;

uint64_t ticks = Clock::getTicks();
uint64_t millis = Clock::ticksToMillis(ticks);
```

Every cpu clock cycle is 1 / freq seconds. (62.5ns at 16MHz)<br>
Every 64 clock cycles is a tick. (4us at 16MHz)<br>
Every 2^16 ticks is a tock. (262.144ms at 16MHz)<br>
Every 2^32 ticks the clock overflows. (4.77 hours at 16Mhz)

If Clock is given an 8 bit timer (rather than 16 bit) each tick will be
4x longer.

## class Clock\<class Timer, uint64_t cpuFreq, int maxCalls = 8\>

#### static constexpr uint64_t millisToTicks(uint64_t ms)
Convert milliseconds to ticks.

#### static constexpr uint64_t microsToTicks(uint64_t us)
Convert microseconds to ticks.

#### static constexpr uint64_t ticksToMillis(uint64_t ticks)
Convert ticks to milliseconds.

#### static constexpr uint64_t ticksToMicros(uint64_t ticks)
Convert ticks to microseconds.

#### static uint64_t getTicks()
Gets the current value of the 32 bit tick counter.<br>
Wraps every 2^32 ticks. (4.77 hours at 16Mhz)

#### static uint64_t getTicks_()
Non-atomic version of getTicks().<br>
Only use this when the global interrupt flag is clear, such
as during hardware interrupts.

#### static bool delayedCall(callback_t callback, void* data, uint64_t delay)
Add a callback to call after delay ticks.<br>
Returns true if successful added.

#### static bool delayedCall_(callback_t callback, void* data, uint64_t delay)
Non-atomic version of delayedCall().
Returns true if successful added.

#### static void delay<uint64_t ns>()
Delays the cpu for the given number of nanoseconds.<br>
Should only be used for very short delays.<br>
Limited to 2 milliseconds.<br>
Rounds to the nearest possible delay. E.g. at 16MHz, delay<50>() will
delay for 62.5 nanoseconds (1 cpu clock cycle).
