#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "util.h"

#define usartN(A) CONCAT(usart,USART_ID,A)
#define UsartN(A) CONCAT(Usart,USART_ID,A)
#define USART_N(A) CONCAT(CHIP_USART_,USART_ID,A)

typedef void (*UsartCallback)(void);

typedef enum {
    UsartN(Asynchronous) = USART_N(_MODE_ASYNCHRONOUS_ID),
    UsartN(Synchronous) = USART_N(_MODE_SYNCHRONOUS_ID),
    #if USART_N(_MODE_MASTER_SPI_ID)
    UsartN(MasterSpi) = USART_N(_MODE_MASTER_SPI_ID),
    #endif
} UsartN(Mode);

typedef enum {
    UsartN(ParityDisabled) = USART_N(_PARITY_DISABLE_ID),
    UsartN(ParityEven) = USART_N(_PARITY_EVEN_ID),
    UsartN(ParityOdd) = USART_N(_PARITY_ODD_ID),
} UsartN(Parity);

typedef enum {
    UsartN(StopBits1) = USART_N(_STOP_BITS_1_ID),
    UsartN(StopBits2) = USART_N(_STOP_BITS_2_ID),
} UsartN(StopBits);

typedef enum {
    UsartN(CharacterSize5) = USART_N(_CHARACTER_SIZE_5_ID),
    UsartN(CharacterSize6) = USART_N(_CHARACTER_SIZE_6_ID),
    UsartN(CharacterSize7) = USART_N(_CHARACTER_SIZE_7_ID),
    UsartN(CharacterSize8) = USART_N(_CHARACTER_SIZE_8_ID),
    UsartN(CharacterSize9) = USART_N(_CHARACTER_SIZE_9_ID),
} UsartN(CharacterSize);

typedef enum {
    UsartN(ClockPolarityTxRisingRxFalling) = USART_N(_CLOCK_POLARITY_TX_RISING_RX_FALLING_ID),
    UsartN(ClockPolarityTxFallingRxRising) = USART_N(_CLOCK_POLARITY_TX_FALLING_RX_RISING_ID),
} UsartN(ClockPolarity);

typedef struct {
    bool receiverEnable;
    bool transmitterEnable;
    bool multiprocessorCummunicationMode;
    bool rxCompleteIntEnable;
    UsartCallback rxCompleteCallback;
    bool txCompleteIntEnable;
    UsartCallback txCompleteCallback;
    bool dataRegisterEmptyIntEnable;
    UsartCallback dataRegisterEmptyCallback;
    UsartN(Mode) usartMode;
    UsartN(Parity) parityMode;
    UsartN(StopBits) stopBit;
    UsartN(CharacterSize) characterSize;
    UsartN(ClockPolarity) clockPolarity;
    uint16_t baud;
    bool use2X;
} UsartN(Config);

void usartN()(UsartN(Config) config) __attribute__((always_inline));
void usartN(Push)(uint8_t b) __attribute__((always_inline));
void usartN(Push9)(uint16_t b) __attribute__((always_inline));
uint8_t usartN(Pop)() __attribute__((always_inline));
uint16_t usartN(Pop9)() __attribute__((always_inline));
void usartN(ReceiverEnable)(bool b) __attribute__((always_inline));
void usartN(TransmitterEnable)(bool b) __attribute__((always_inline));
void usartN(RXCompleteInterruptEnable)(bool b) __attribute__((always_inline));
void usartN(TXCompleteInterruptEnable)(bool b) __attribute__((always_inline));
void usartN(DataRegisterEmptyInterruptEnable)(bool b) __attribute__((always_inline));
bool usartN(FrameError)() __attribute__((always_inline));
bool usartN(DataOverRun)() __attribute__((always_inline));
bool usartN(ParityError)() __attribute__((always_inline));
