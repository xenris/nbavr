[Index](../../index.hpp.md#index)

# System Sleep

```c++
using Sleep = nbos::hw::Sleep;

Sleep::mode(Sleep::Mode::idle);
Sleep::enable(true);

Sleep::sleep();
```

## class Sleep

#### enum Sleep::Mode
* idle
* adcNoiseReduction
* powerDown
* powerSave
* standby
* externalStandby

#### static [HardwareType](hardwaretype.hpp.md#enum-hardwaretype) getHardwareType()

#### static void mode([Sleep::Mode](sleep.hpp.md#enum-sleepmode) m)
Set the level of sleep that happens when sleep() is called.

#### static void enable(bool b)
Set this to true to let the CPU sleep when sleep() is called.

#### static bool isEnabled()

#### static void sleep()
Put the CPU to sleep.
