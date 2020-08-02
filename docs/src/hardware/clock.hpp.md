[Index](../../index.hpp.md#index)

# Clock

```c++
```

## class Clock

#### enum Clock::Source
* internal16M20M
* internal32K
* external

#### enum Clock::Prescaler
* div2
* div4
* div8
* div16
* div32
* div64
* div6
* div10
* div12
* div24
* div48

#### static [HardwareType](hardwaretype.hpp.md#enum-hardwaretype) getHardwareType()

#### static void source([Clock::Source](clock.hpp.md#enum-clocksource))

#### static void prescaler([Clock::Prescaler](clock.hpp.md#enum-clockprescaler))

#### static void prescalerEnable(bool)

#### static void lock()
