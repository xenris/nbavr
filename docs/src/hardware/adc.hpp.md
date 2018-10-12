[Index](../../index.hpp.md#index)

# Analog to Digital Converters

```c++
atomic([]() {
    Adc::reference(Adc::Reference::AVCC);
    Adc::channel(Adc::Channel::ADC1);
    Adc::prescaler(Adc::Prescaler::Div128);
    Adc::trigger(Adc::Trigger::SingleConversion);
    Adc::intFlagClear();
});

Adc::start();

while(!Adc::intFlag());

const uint16_t value = Adc::value();
```

## class AdcN

#### enum AdcN::Reference
* aref
* avcc
* internal
* internal_1_1
* internal_2_56
* internal_2_56_cap

#### enum AdcN::Channel
* adc0
* adc1
* adc2
* adc3
* adc4
* adc5
* adc6
* adc7
* adc8
* vbg
* gnd

#### enum AdcN::Prescaler
* div2
* div4
* div8
* div16
* div32
* div64
* div128

#### enum AdcN::Trigger
* singleConversion
* freeRunning
* analogComparator
* externalInt0
* timer0CompareMatchA
* timer0Overflow
* timer1CompareMatchB
* timer1Overflow
* timer1CaptureEvent
* freeRunning

#### static [HardwareType](hardwaretype.hpp.md#enum-hardwaretype) getHardwareType()

#### static void enable(bool e)

#### static void start()

#### static uint16_t value()

#### static void reference([AdcN::Reference](adc.hpp.md#enum-adcnreference) r)

#### static void channel([AdcN::Channel](adc.hpp.md#enum-adcnchannel) c)

#### static void prescaler([AdcN::Prescaler](adc.hpp.md#enum-adcnprescaler) p)

#### static void leftAdjust(bool l)

#### static void trigger([AdcN::Trigger](adc.hpp.md#enum-adcntrigger) t)

#### static void callback([callback_t](../type.hpp.md#callbackt--void-void) callback, void\* data)

#### static void intEnable(bool e)

#### static bool intFlag()

#### static void intFlagClear()
