[Index](../../index.hpp.md#index)

# Universal Synchronous Asynchronous Receiver Transmitters

```c++
using Usart = nblib::hw::Usart0;

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

#### static void baud(uint16_t b)

#### static void use2X(bool u)

#### static void setBaudRate<cpuFreq, baudRate>()
Set the baud and 2x registers from the given CPU frequency and baud rate.

#### static void receiverEnable(bool e)

#### static void transmitterEnable(bool e)

#### static void multiprocessorCummunicationMode(bool e)

#### static void rxCompleteIntEnable(bool e)

#### static void txCompleteIntEnable(bool e)

#### static void dataRegisterEmptyIntEnable(bool e)

#### static bool rxCompleteIntFlag()

#### static bool txCompleteIntFlag()

#### static bool dataRegisterEmptyIntFlag()

#### static void rxCompleteIntFlagClear()

#### static void txCompleteIntFlagClear()

#### static void dataRegisterEmptyIntFlagClear()

#### static void setRxCallback([Callback](../callback.hpp.md#callbackt--void-t)<T\> function, T\* data)

#### static void callRxCallback()

#### static void setTxCallback([Callback](../callback.hpp.md#callbackt--void-t)<T\> function, T\* data)

#### static void callTxCallback()

#### static void setDeCallback([Callback](../callback.hpp.md#callbackt--void-t)<T\> function, T\* data)

#### static void callDeCallback()

#### static void push(uint8_t b)

#### static void push9(uint16_t b)

#### static uint8_t pop()

#### static uint16_t pop9()

#### static bool frameError()

#### static bool dataOverRun()

#### static bool parityError()
