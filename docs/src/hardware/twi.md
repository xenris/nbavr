# Two Wire Serial Interface

#### macro INCLUDE_TWI_CALLBACK(N)
Include this to use Twi callbacks.

## class TwiN

#### enum Prescaler
* Div1
* Div4
* Div16
* Div64

#### enum Status
* StartTransmitted
* RepeatedStartTransmitted
* SLAWTransmittedAck
* SLAWTransmittedNack
* DataTransmittedAck
* DataTransmittedNack
* ArbitrationLost
* SLARTransmittedAck
* SLARTransmittedNack
* DataReceivedAck
* DataReceivedNack
* OwnSLAWReceivedAck
* ArbitrationLostOwnSLAWAck
* GeneralCallAddressReceivedAck
* ArbitrationLostGeneralCallAddressReceivedAck
* PrevAddressedOwnSLAWDataReceivedAck
* PrevAddressedOwnSLAWDataReceivedNack
* PrevAddressedGeneralCallDataReceivedAck
* PrevAddressedGeneralCallDataReceivedNack
* StopOrRepeatedStartWhileAddressedAsSlave
* OwnSLARReceivedAck
* ArbitrationLostOwnSLARAck
* DataInTWDRTransmittedAck
* DataInTWDRTransmittedNack
* LastDataTransmittedAck
* NoState
* BusError

#### static constexpr HardwareType getHardwareType()
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

#### static void writeCollisionFlagClear()
Clear the write collision flag.

#### static void intEnable(bool e)
Enable/disable the Twi interrupt.

#### static void callback(callback_t callback, void\* data)
Set the callback and data for Twi interrupts.

#### static Status status()
Get the Twi status.

#### static void prescaler(Prescaler p)
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
