[Index](../index.hpp.md#index)

# Clock

Useful class for managing the passing of time.<br>
Required by TaskManager.

```c++
const Word64 cpuFreq = 16000000;

using SystemTimer = nbos::hw::Timer1;

using Clock = nbos::Clock<SystemTimer, cpuFreq>;

Word64 ticks = Clock::getTicks();
Word64 millis = Clock::ticksToMillis(ticks);
```

Every cpu clock cycle is 1 / freq seconds. (62.5ns at 16MHz)<br>
Every 64 clock cycles is a tick. (4us at 16MHz)<br>
Every 2^64 ticks the clock overflows. (~2339769 years at 16Mhz)

If Clock is given an 8 bit timer (rather than 16 bit) each tick will be
4x longer.

## class Clock<class Timer, Integer cpuFreq, Integer maxCalls = 8\>

#### static constexpr Word64 millisToTicks(Word64 ms)
Convert milliseconds to ticks.

#### static constexpr Word64 microsToTicks(Word64 us)
Convert microseconds to ticks.

#### static constexpr Word64 ticksToMillis(Word64 ticks)
Convert ticks to milliseconds.

#### static constexpr Word64 ticksToMicros(Word64 ticks)
Convert ticks to microseconds.

#### static Word64 getTicks()
Get the current value of the 64 bit tick counter.

#### static Word64 getTicks_()
Non-atomic version of getTicks().

#### static Bool delayedCall(Callback callback, void\* data, Word64 delay)
Add a callback to call after delay ticks.<br>
Returns true if successfully added.

#### static Bool delayedCall_(Callback callback, void\* data, Word64 delay)
Non-atomic version of delayedCall().

#### static void delay<Word64 ns\>()
Delays the cpu for the given number of nanoseconds.<br>
Should only be used for very short delays.<br>
Limited to 2 milliseconds.<br>
Rounds to the nearest possible delay. E.g. at 16MHz, delay<50\>() will
delay for 62.5 nanoseconds (1 cpu clock cycle).
