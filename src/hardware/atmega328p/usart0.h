#ifndef NBAVR_USART0_H
#define NBAVR_USART0_H

typedef enum {
    USART0_ASYNCHRONOUS = 0,
    USART0_SYNCHRONOUS = _BV(UMSEL00),
    USART0_MASTER_SPI = _BV(UMSEL01) | _BV(UMSEL00),
} USART0Mode;

typedef enum {
    USART0_PARITY_DISABLED = 0,
    USART0_PARITY_EVEN = _BV(UPM01),
    USART0_PARITY_ODD = _BV(UPM01) | _BV(UPM00),
} USART0ParityMode;

typedef enum {
    USART0_1_BIT = 0,
    USART0_2_BIT = _BV(USBS0),
} USART0StopBit;

typedef enum {
    USART0_5_BIT = 0,
    USART0_6_BIT = 1,
    USART0_7_BIT = 2,
    USART0_8_BIT = 3,
    USART0_9_BIT = 7,
} USART0CharacterSize;

typedef enum {
    USART0_TX_RISING_RX_FALLING = 0,
    USART0_TX_FALLING_RX_RISING,
} USART0ClockPolarity;

typedef struct {
    bool receiverEnable;
    bool transmitterEnable;
    bool multiprocessorCummunicationMode;
    bool rxCompleteIntEnable;
    bool txCompleteIntEnable;
    bool dataRegisterEmptyIntEnable;
    USART0Mode usartMode;
    USART0ParityMode parityMode;
    USART0StopBit stopBit;
    USART0CharacterSize characterSize;
    USART0ClockPolarity clockPolarity;
    uint16_t baud;
    bool use2X;
} USART0Config;

inline void usart0(USART0Config config) {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        uint8_t a = 0;
        uint8_t b = 0;
        uint8_t c = 0;

        if(config.use2X) {
            a |= _BV(U2X0);
        }

        if(config.multiprocessorCummunicationMode) {
            a |= _BV(MPCM0);
        }

        if(config.rxCompleteIntEnable) {
            b |= _BV(RXCIE0);
        }

        if(config.txCompleteIntEnable) {
            b |= _BV(TXCIE0);
        }

        if(config.dataRegisterEmptyIntEnable) {
            b |= _BV(UDRIE0);
        }

        if(config.receiverEnable) {
            b |= _BV(RXEN0);
        }

        if(config.transmitterEnable) {
            b |= _BV(TXEN0);
        }

        if(config.characterSize == USART0_9_BIT) {
            b |= _BV(UCSZ02);
        }

        c |= config.usartMode;

        c |= config.parityMode;

        c |= config.stopBit;

        c |= (config.characterSize & USART0_8_BIT) << UCSZ00;

        if(config.clockPolarity == USART0_TX_FALLING_RX_RISING) {
            c |= _BV(UCPOL0);
        }

        UBRR0 = config.baud;

        UCSR0A = a;
        UCSR0C = c;
        UCSR0B = b;
    }
}

inline void usart0Push(uint8_t b) {
    UDR0 = b;
}

inline void usart0Push9(uint16_t b) {
    if(b & 0x0100) {
        UCSR0B |= _BV(TXB80);
    } else {
        UCSR0B &= ~_BV(TXB80);
    }

    UDR0 = (uint8_t)b;
}

inline uint8_t usart0Pop() {
    return UDR0;
}

inline uint16_t usart0Pop9() {
    uint8_t h = (UCSR0B >> _BV(RXB80)) & 0x01;
    uint8_t l = UDR0;

    return (h << 8) | l;
}

inline bool usart0ReceiveComplete() {
    return UCSR0A & _BV(RXC0);
}

inline bool usart0TransmitComplete() {
    return UCSR0A & _BV(TXC0);
}

inline bool usart0DataRegisterEmpty() {
    return UCSR0A & _BV(UDRE0);
}

inline bool usart0FrameError() {
    return UCSR0A & _BV(FE0);
}

inline bool usart0DataOverRun() {
    return UCSR0A & _BV(DOR0);
}

inline bool usart0ParityError() {
    return UCSR0A & _BV(UPE0);
}

inline void usart0DoubleTransmissionSpeed(bool b) {
    if(b) {
        UCSR0A |= _BV(U2X0);
    } else {
        UCSR0A &= ~_BV(U2X0);
    }
}

inline void usart0MultiprocessorCummunicationMode(bool b) {
    if(b) {
        UCSR0A |= _BV(MPCM0);
    } else {
        UCSR0A &= ~_BV(MPCM0);
    }
}

inline void usart0RXCompleteInterruptEnable(bool b) {
    if(b) {
        UCSR0B |= _BV(RXCIE0);
    } else {
        UCSR0B &= ~_BV(RXCIE0);
    }
}

inline void usart0TXCompleteInterruptEnable(bool b) {
    if(b) {
        UCSR0B |= _BV(TXCIE0);
    } else {
        UCSR0B &= ~_BV(TXCIE0);
    }
}

inline void usart0DataRegisterEmptyInterruptEnable(bool b) {
    if(b) {
        UCSR0B |= _BV(UDRIE0);
    } else {
        UCSR0B &= ~_BV(UDRIE0);
    }
}

inline void usart0ReceiverEnable(bool b) {
    if(b) {
        UCSR0B |= _BV(RXEN0);
    } else {
        UCSR0B &= ~_BV(RXEN0);
    }
}

inline void usart0TransmitterEnable(bool b) {
    if(b) {
        UCSR0B |= _BV(TXEN0);
    } else {
        UCSR0B &= ~_BV(TXEN0);
    }
}

inline void usart0ModeSelect(USART0Mode mode) {
    UCSR0C &= ~(_BV(UMSEL01) | _BV(UMSEL00));
    UCSR0C |= mode;
}

inline void usart0ParityMode(USART0ParityMode mode) {
    UCSR0C &= ~(_BV(UPM01) | _BV(UPM00));
    UCSR0C |= mode;
}

inline void usart0StopBitSelect(USART0StopBit stopBit) {
    if(stopBit == USART0_1_BIT) {
        UCSR0C &= ~_BV(USBS0);
    } else {
        UCSR0C |= _BV(USBS0);
    }
}

inline void usart0CharacterSize(USART0CharacterSize size) {
    if(size == USART0_9_BIT) {
        UCSR0B |= _BV(UCSZ02);
    } else {
        UCSR0B &= ~_BV(UCSZ02);
    }
    UCSR0C &= ~(_BV(UCSZ01) | _BV(UCSZ00));
    UCSR0C |= (size & USART0_8_BIT) << UCSZ00;;
}

inline void usart0ClockPolarity(USART0ClockPolarity polarity) {
    if(polarity == USART0_TX_RISING_RX_FALLING) {
        UCSR0C &= ~_BV(UCPOL0);
    } else {
        UCSR0C |= _BV(UCPOL0);
    }
}

inline void usart0BaudRate(uint16_t baud) {
    UBRR0H = (baud >> 8) & 0x0F;
    UBRR0L = baud;
}

#endif
