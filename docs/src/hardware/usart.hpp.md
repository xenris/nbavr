[Index](../../index.hpp.md#index)

# Universal Synchronous Asynchronous Receiver Transmitters

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

#### enum UsartN::Mode
* asynchronous
* synchronous
* masterSpi

#### enum UsartN::Parity
* disabled
* even
* odd

#### enum UsartN::StopBits
* bits1
* bits2

#### enum UsartN::CharacterSize
* size5
* size6
* size7
* size8
* size9

#### enum UsartN::Polarity
* txRisingRxFalling
* txFallingRxRising

#### static [HardwareType](hardwaretype.hpp.md#enum-hardwaretype) getHardwareType()

#### static void mode([UsartN::Mode](usart.hpp.md#enum-usartnmode) m)

#### static void parity([UsartN::Parity](usart.hpp.md#enum-usartnparity) p)

#### static void stopBits([UsartN::StopBits](usart.hpp.md#enum-usartnstopbits) b)

#### static void characterSize([UsartN::CharacterSize](usart.hpp.md#enum-usartncharactersize) s)

#### static void polarity([UsartN::Polarity](usart.hpp.md#enum-usartnpolarity) p)

#### static void baud(Word16 b)

#### static void use2X(Bool u)

#### static void receiverEnable(Bool e)

#### static void transmitterEnable(Bool e)

#### static void multiprocessorCummunicationMode(Bool e)

#### static void rxCompleteIntEnable(Bool e)

#### static void txCompleteIntEnable(Bool e)

#### static void dataRegisterEmptyIntEnable(Bool e)

#### static void setRxCallback([Callback](../callback.hpp.md#callbackt--void-t)<T\> function, T\* data)

#### static void callRxCallback()

#### static void setTxCallback([Callback](../callback.hpp.md#callbackt--void-t)<T\> function, T\* data)

#### static void callTxCallback()

#### static void setDeCallback([Callback](../callback.hpp.md#callbackt--void-t)<T\> function, T\* data)

#### static void callDeCallback()

#### static void push(Word8 b)

#### static void push9(Word16 b)

#### static Word8 pop()

#### static Word16 pop9()

#### static Bool frameError()

#### static void frameErrorClear()

#### static Bool dataOverRun()

#### static void dataOverRunClear()

#### static Bool parityError()

#### static void parityErrorClear()
