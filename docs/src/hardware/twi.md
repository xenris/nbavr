# Two Wire Serial Interface

## Example

TODO
#### macro INCLUDE_TWI_CALLBACK()
Include this to use Twi callbacks.
## class Twi

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

#### static void enable(bool)
Enable/disable the two wire serial interface.

#### static void baud(uint16_t)
Set USART baud rate.

#### static bool intFlag()
Returns true if the interrupt flag is set.

#### static void intFlagClear()
Clear the interrupt flag.

#### static void enableAcknowledge(bool e)
Enable/disable acknowledge pulse.
#### static void startCondition(bool e)
Enable/disable start condition.

#### static bool startCondition()
Returns true if start condition is set.

#### static void stopCondition(bool e)
Enable/disable stop condition.

#### static bool stopCondition()
Returns true if stop condition is set.

#### static bool writeCollisionFlag()
Returns true if the write collision flag is set.

#### static void writeCollisionFlagClear()
Clear the write collision flag.

#### static void intEnable(bool e)
Enable/disable the Twi interrupt.

#### static void callback(void (\*)(void\*), void\*)
Set the callback and data for Twi interrupts.

#### static Status status()
Get the Twi status.

#### static void prescaler(Prescaler)
Set the prescaler.

#### static void push(uint8_t)
Send a byte.

#### static uint8_t pop()
Get the last received byte.

#### static void slaveAddress(uint8_t)
Set the address for transmitting and receiving as a slave.

#### static void slaveAddressMask(uint8_t)
Set the slave address mask.

#### static void generalCallRecognitionEnable(bool e)
Enable/disable the recognition of a Twi general call.
