# Universal Synchronous Asynchronous Receiver Transmitter

```c++
using Usart = nbos::hw::Usart0;

const auto f = [](void*) {
    Usart::push('?')
};

Usart::baud(103);
Usart::use2X(false);

Usart::transmitterEnable(true);
Usart::dataRegisterEmptyIntEnable(true);
Usart::dataRegisterEmptyCallback((callback_t)f);
```

## class UsartN

#### enum Mode
* asynchronous
* synchronous
* masterSpi

#### enum Parity
* disabled
* even
* odd

#### enum StopBits
* bits1
* bits2

#### enum CharacterSize
* size5
* size6
* size7
* size8
* size9

#### enum Polarity
* txRisingRxFalling
* txFallingRxRising

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
