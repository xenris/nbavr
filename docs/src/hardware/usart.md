# USARTs

N is the usart id (1, 2, etc).

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

#### static constexpr HardwareType getHardwareType()
Get the type of hardware that this class represents.

#### static void mode(Mode m)
Set USART mode.

#### static void parity(Parity p)
Set USART parity.

#### static void stopBits(StopBits b)
Set number of stop bits.

#### static void characterSize(CharacterSize s)
Set USART character size.

#### static void polarity(Polarity p)
Set USART clock polarity.

#### static void baud(uint16_t b)
Set USART baud rate.

#### static void use2X(bool u)
Enable/disable baud rate 2x speed.

#### static void receiverEnable(bool e)
Enable/disable receiver.

#### static void transmitterEnable(bool e)
Enable/disable transmitter.

#### static void multiprocessorCummunicationMode(bool e)
Enable/disable multiprocessor cummunication mode.

#### static void rxCompleteIntEnable(bool e)
Enable/disable receive complete interrupt.

#### static void txCompleteIntEnable(bool e)
Enable/disable transmit complete interrupt.

#### static void dataRegisterEmptyIntEnable(bool e)
Enable/disable data register empty interrupt.

#### static void rxCompleteCallback(callback_t callback, void\* data)
Set callback for receive complete interrupt.

#### static void txCompleteCallback(callback_t callback, void\* data)
Set callback for transmit complete interrupt.

#### static void dataRegisterEmptyCallback(callback_t callback, void\* data)
Set callback for data register empty interrupt.

#### static void push(uint8_t b)
Send a byte.

#### static void push9(uint16_t b)
Send a 9 bit byte.

#### static uint8_t pop()
Get the last received byte.

#### static uint16_t pop9()
Get the last received 9 bit byte.

#### static bool frameError()
Returns true if there was a frame error.

#### static void frameErrorClear()
Clear the frame error flag.

#### static bool dataOverRun()
Returns true if there was a data over run.

#### static void dataOverRunClear()
Clear the data over run flag.

#### static bool parityError()
Returns true if there was a parity error.

#### static void parityErrorClear()
Clear the parity error flag.
