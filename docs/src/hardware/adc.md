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

#### macro INCLUDE_ADC_CALLBACK()
Include this to use Adc callbacks.

## class Adc

#### enum Reference
* AREF
* AVCC
* Internal

#### enum Channel
* ADC0
* ADC1
* ADC2
* ADC3
* ADC4
* ADC5
* ADC6
* ADC7
* ADC8
* VBG
* GND

#### enum Prescaler
* Div2
* Div4
* Div8
* Div16
* Div32
* Div64
* Div128

#### enum Trigger
* SingleConversion
* FreeRunning
* AnalogComparator
* ExternalInt0
* Timer0CompareMatchA
* Timer0Overflow
* Timer1CompareMatchB
* Timer1Overflow
* Timer1CaptureEvent
* FreeRunning

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
