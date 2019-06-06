[Index](../../index.hpp.md#index)

# Two Wire Serial Interfaces

## class TwiN

#### enum TwiN::Prescaler
* div1
* div4
* div16
* div64

#### enum TwiN::Status
* startTransmitted
* repeatedStartTransmitted
* slawTransmittedAck
* slawTransmittedNack
* dataTransmittedAck
* dataTransmittedNack
* arbitrationLost
* slarTransmittedAck
* slarTransmittedNack
* dataReceivedAck
* dataReceivedNack
* ownSlawReceivedAck
* arbitrationLostOwnSlawAck
* generalCallAddressReceivedAck
* arbitrationLostGeneralCallAddressReceivedAck
* prevAddressedOwnSlawDataReceivedAck
* prevAddressedOwnSlawDataReceivedNack
* prevAddressedGeneralCallDataReceivedAck
* prevAddressedGeneralCallDataReceivedNack
* stopOrRepeatedStartWhileAddressedAsSlave
* ownSlarReceivedAck
* arbitrationLostOwnSlarAck
* dataInTwdrTransmittedAck
* dataInTwdrTransmittedNack
* lastDataTransmittedAck
* noState
* busError

#### static [HardwareType](hardwaretype.hpp.md#enum-hardwaretype) getHardwareType()
Get the type of hardware that this class represents.

#### static void enable(bool e)
Enable/disable the Twi.

#### static void sendStart(bool intEnable = true)
Send a start condition.

#### static void sendStop(bool intEnable = true)
Send stop condition.

#### static void sendAck(bool intEnable = true)
Send acknowledge condition.

#### static void sendNack(bool intEnable = true)
Send not acknowledge condition.

#### static void bitRate(uint8_t b)
Set Twi bitRate.

#### static bool intFlag()
Returns true if the interrupt flag is set.

#### static bool active()
Returns true if the twi hardware is busy.

#### static bool writeCollisionFlag()
Returns true if the write collision flag is set.

#### static void intEnable(bool e)
Enable/disable the Twi interrupt.

#### static void setCallback([Callback](../callback.hpp.md#callbackt--void-t)<T\> function, T\* data)
Set the callback for Twi interrupts.

#### static void callCallback()

#### static [TwiN::Status](twi.hpp.md#enum-twinstatus) status()
Get the Twi status.

#### static void prescaler([TwiN::Prescaler](twi.hpp.md#enum-twinprescaler) p)
Set the prescaler.

#### static void push(uint8_t b)
Put byte in data buffer.

#### static uint8_t pop()
Get byte from data buffer.

#### static void slaveAddress(uint8_t b)
Set the address for transmitting and receiving as a slave.

#### static void slaveAddressMask(uint8_t b)
Set the slave address mask.

#### static void generalCallRecognitionEnable(bool e)
Enable/disable the recognition of a Twi general call.
