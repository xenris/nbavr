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

#### static void enable(Bool e)
Enable/disable the Twi.

#### static void sendStart(Bool intEnable = true)
Send a start condition.

#### static void sendStop(Bool intEnable = true)
Send stop condition.

#### static void sendAck(Bool intEnable = true)
Send acknowledge condition.

#### static void sendNack(Bool intEnable = true)
Send not acknowledge condition.

#### static void bitRate(Word8 b)
Set Twi bitRate.

#### static Bool intFlag()
Returns true if the interrupt flag is set.

#### static Bool active()
Returns true if the twi hardware is busy.

#### static Bool writeCollisionFlag()
Returns true if the write collision flag is set.

#### static void writeCollisionFlagClear()
Clear the write collision flag.

#### static void intEnable(Bool e)
Enable/disable the Twi interrupt.

#### static void setCallback([Callback](../callback.hpp.md#callbackt--void-t)<T\> function, T\* data)
Set the callback for Twi interrupts.

#### static void callCallback()

#### static [TwiN::Status](twi.hpp.md#enum-twinstatus) status()
Get the Twi status.

#### static void prescaler([TwiN::Prescaler](twi.hpp.md#enum-twinprescaler) p)
Set the prescaler.

#### static void push(Word8 b)
Put byte in data buffer.

#### static Word8 pop()
Get byte from data buffer.

#### static void slaveAddress(Word8 b)
Set the address for transmitting and receiving as a slave.

#### static void slaveAddressMask(Word8 b)
Set the slave address mask.

#### static void generalCallRecognitionEnable(Bool e)
Enable/disable the recognition of a Twi general call.
