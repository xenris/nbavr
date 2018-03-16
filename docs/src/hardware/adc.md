# Analog to Digital Converter

## Example

```c++
// Start the analog to digital converter.

atomic {
    Adc::reference(Adc::Reference::AVCC);
    Adc::channel(Adc::Channel::ADC1);
    Adc::prescaler(Adc::Prescaler::Div128);
    Adc::trigger(Adc::Trigger::SingleConversion);
}

Adc::start();

// In the main loop.

if(Adc::intFlag()) {
    adcValue = Adc::value();

    Adc::intFlagClear();
} else {
    // Conversion not done yet.
}
```

#### macro INCLUDE_ADC_CALLBACK(N)
Include this to use Adc callbacks.

## class Adc

#### enum Reference
* aref
* avcc
* internal
* internal_1_1
* internal_2_56
* internal_2_56_cap

#### enum Channel
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

#### enum Prescaler
* div2
* div4
* div8
* div16
* div32
* div64
* div128

#### enum Trigger
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

#### static constexpr HardwareType getHardwareType()
Get the type of hardware that this class represents.

#### static void enable(bool e)
Enable/disable the analog to digital converter.

#### static void start()
Start a convertion if set to single conversion or free running modes.

#### static uint16_t value()
Get the the most recent conversion.

#### static void reference(Reference r)
Set the reference voltage source.

#### static void channel(Channel c)
Set the input channel.

#### static void prescaler(Prescaler p)
Set the clock prescaler.

#### static void leftAdjust(bool l)
Enable/disable left adjustment of 10 bit data in 16 bit register.

#### static void trigger(Trigger t)
Set the conversion trigger source.

#### static void callback(callback_t callback, void\* data)
Set the callback and data for when a conversion is complete.

#### static void intEnable(bool e)
Enable/disable the ADC interrupt.

#### static bool intFlag()
Returns true if the interrupt flag is set.

#### static void intFlagClear()
Clear the interrupt flag.
