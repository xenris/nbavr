# USARTs
N is the usart id (1, 2, etc).<br>
All functions are static.
## Example
```c++
// TODO
```
#### macro INCLUDE_USART_CALLBACK(N, X)
Include this to use Usart callbacks.<br>
N is the Usart id, and X is one of RX (receive complete), TX (transmit
complete), or DE (data register empty).
## class UsartN
#### enum Mode
* Asynchronous
* Synchronous
* MasterSpi

#### enum Parity
* Disabled
* Even
* Odd

#### enum StopBits
* Bits1
* Bits2

#### enum CharacterSize
* Size5
* Size6
* Size7
* Size8
* Size9
#### enum Polarity
* TxRisingRxFalling
* TxFallingRxRising
#### constexpr HardwareType getHardwareType()
Get the type of hardware that this class represents.
#### void mode(Mode)
Set USART mode.
#### void parity(Parity)
Set USART parity.
#### void stopBits(StopBits)
Set number of stop bits.
#### void characterSize(CharacterSize)
Set USART character size.
#### void polarity(Polarity)
Set USART clock polarity.
#### void baud(uint16_t)
Set USART baud rate.
#### void use2X(bool)
Enable/disable baud rate 2x speed.
#### void receiverEnable(bool)
Enable/disable receiver.
#### void transmitterEnable(bool)
Enable/disable transmitter.
#### void multiprocessorCummunicationMode(bool)
Enable/disable multiprocessor cummunication mode.
#### void rxCompleteIntEnable(bool)
Enable/disable receive complete interrupt.
#### void txCompleteIntEnable(bool)
Enable/disable transmit complete interrupt.
#### void dataRegisterEmptyIntEnable(bool)
Enable/disable data register empty interrupt.
#### void rxCompleteCallback(void (\*)(void\*), void\*)
Set callback for receive complete interrupt.
#### void txCompleteCallback(void (\*)(void\*), void\*)
Set callback for transmit complete interrupt.
#### void dataRegisterEmptyCallback(void (\*)(void\*), void\*)
Set callback for data register empty interrupt.
#### void push(uint8_t)
Send a byte.
#### void push9(uint16_t)
Send a 9 bit byte.
#### uint8_t pop()
Get the last received byte.
#### uint16_t pop9()
Get the last received 9 bit byte.
#### bool frameError()
Returns true if there was a frame error.
#### void frameErrorClear()
Clear the frame error flag.
#### bool dataOverRun()
Returns true if there was a data over run.
#### void dataOverRunClear()
Clear the data over run flag.
#### bool parityError()
Returns true if there was a parity error.
#### void parityErrorClear()
Clear the parity error flag.
