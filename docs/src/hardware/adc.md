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
#### constexpr HardwareType getHardwareType()
Get the type of hardware that this class represents.
#### void enable(bool)
Enable/disable the analog to digital converter.
#### void start()
Start a convertion if set to single conversion or free running modes.
#### uint16_t value()
Get the the most recent conversion.
#### void reference(Reference)
Set the reference voltage source.
#### void channel(Channel)
Set the input channel.
#### void prescaler(Prescaler)
Set the clock prescaler.
#### void leftAdjust(bool)
Enable/disable left adjustment of 10 bit data in 16 bit register.
#### void trigger(Trigger)
Set the conversion trigger source.
#### void callback(void (\*)(void\*), void\*)
Set the callback and data for when a conversion is complete.
#### void intEnable(bool)
Enable/diable the ADC interrupt.
#### bool intFlag()
Returns true if the interrupt flag is set.
#### void intFlagClear()
Clear the interrupt flag.
