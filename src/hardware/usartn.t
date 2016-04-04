static UsartCallback mRXCompleteCallback;
static UsartCallback mTXCompleteCallback;
static UsartCallback mDataRegEmptyCallback;

void usartN()(UsartN(Config) config) {
    atomic {
        uint8_t* frameErrorReg = (uint8_t*)&USART_N(_FRAME_ERROR_REG);
        uint8_t* dataOverRunReg = (uint8_t*)&USART_N(_DATA_OVERRUN_REG);
        uint8_t* parityErrorReg = (uint8_t*)&USART_N(_PARITY_ERROR_REG);
        uint8_t* doubleSpeedReg = (uint8_t*)&USART_N(_DOUBLE_SPEED_REG);
        uint8_t* multiProcessorComReg = (uint8_t*)&USART_N(_MULTI_PROCESSOR_COMMUNICATION_REG);
        uint8_t* rxCompleteIntEnableReg = (uint8_t*)&USART_N(_RX_COMPLETE_INT_ENABLE_REG);
        uint8_t* txCompleteIntEnableReg = (uint8_t*)&USART_N(_TX_COMPLETE_INT_ENABLE_REG);
        uint8_t* dataRegEmptyIntEnableReg = (uint8_t*)&USART_N(_DATA_REG_EMPTY_INT_ENABLE_REG);
        uint8_t* rxEnableReg = (uint8_t*)&USART_N(_RX_ENABLE_REG);
        uint8_t* txEnableReg = (uint8_t*)&USART_N(_TX_ENABLE_REG);
        uint8_t* modeBit0Reg = (uint8_t*)&USART_N(_MODE_BIT_0_REG);
        #if USART_N(_MODE_BIT_COUNT) > 1
        uint8_t* modeBit1Reg = (uint8_t*)&USART_N(_MODE_BIT_1_REG);
        #endif
        uint8_t* parityBit0Reg = (uint8_t*)&USART_N(_PARITY_BIT_0_REG);
        uint8_t* parityBit1Reg = (uint8_t*)&USART_N(_PARITY_BIT_1_REG);
        uint8_t* stopBitReg = (uint8_t*)&USART_N(_STOP_BITS_REG);
        uint8_t* characterSizeBit0Reg = (uint8_t*)&USART_N(_CHARACTER_SIZE_BIT_0_REG);
        uint8_t* characterSizeBit1Reg = (uint8_t*)&USART_N(_CHARACTER_SIZE_BIT_1_REG);
        uint8_t* characterSizeBit2Reg = (uint8_t*)&USART_N(_CHARACTER_SIZE_BIT_2_REG);
        uint8_t* clockPolarityReg = (uint8_t*)&USART_N(_CLOCK_POLARITY_REG);
        uint8_t* baudRateRegHigh = (uint8_t*)&USART_N(_BAUD_RATE_REG_HIGH);
        uint8_t* baudRateRegLow = (uint8_t*)&USART_N(_BAUD_RATE_REG_LOW);

        uint8_t frameErrorBit = USART_N(_FRAME_ERROR_BIT);
        uint8_t dataOverRunBit = USART_N(_DATA_OVERRUN_BIT);
        uint8_t parityErrorBit = USART_N(_PARITY_ERROR_BIT);
        uint8_t doubleSpeedBit = USART_N(_DOUBLE_SPEED_BIT);
        uint8_t multiProcessorComBit = USART_N(_MULTI_PROCESSOR_COMMUNICATION_BIT);
        uint8_t rxCompleteIntEnableBit = USART_N(_RX_COMPLETE_INT_ENABLE_BIT);
        uint8_t txCompleteIntEnableBit = USART_N(_TX_COMPLETE_INT_ENABLE_BIT);
        uint8_t dataRegEmptyIntEnableBit = USART_N(_DATA_REG_EMPTY_INT_ENABLE_BIT);
        uint8_t rxEnableBit = USART_N(_RX_ENABLE_BIT);
        uint8_t txEnableBit = USART_N(_TX_ENABLE_BIT);
        uint8_t modeBit0 = USART_N(_MODE_BIT_0);
        #if USART_N(_MODE_BIT_COUNT) > 1
        uint8_t modeBit1 = USART_N(_MODE_BIT_1);
        #endif
        uint8_t parityBit0 = USART_N(_PARITY_BIT_0);
        uint8_t parityBit1 = USART_N(_PARITY_BIT_1);
        uint8_t stopBitBit = USART_N(_STOP_BITS_BIT);
        uint8_t characterSizeBit0 = USART_N(_CHARACTER_SIZE_BIT_0);
        uint8_t characterSizeBit1 = USART_N(_CHARACTER_SIZE_BIT_1);
        uint8_t characterSizeBit2 = USART_N(_CHARACTER_SIZE_BIT_2);
        uint8_t clockPolarityBit = USART_N(_CLOCK_POLARITY_BIT);

        setBit(doubleSpeedReg, doubleSpeedBit, config.use2X);

        setBit(multiProcessorComReg, multiProcessorComBit, config.multiprocessorCummunicationMode);

        setBit(rxCompleteIntEnableReg, rxCompleteIntEnableBit, config.rxCompleteIntEnable);
        setBit(txCompleteIntEnableReg, txCompleteIntEnableBit, config.txCompleteIntEnable);
        setBit(dataRegEmptyIntEnableReg, dataRegEmptyIntEnableBit, config.dataRegisterEmptyIntEnable);

        setBit(rxEnableReg, rxEnableBit, config.receiverEnable);
        setBit(txEnableReg, txEnableBit, config.transmitterEnable);

        setBit(characterSizeBit0Reg, characterSizeBit0, config.characterSize & 0x01);
        setBit(characterSizeBit1Reg, characterSizeBit1, config.characterSize & 0x02);
        setBit(characterSizeBit2Reg, characterSizeBit2, config.characterSize & 0x04);

        setBit(modeBit0Reg, modeBit0, config.usartMode & 0x01);
        #if USART_N(_MODE_BIT_COUNT) > 1
        setBit(modeBit1Reg, modeBit1, config.usartMode & 0x02);
        #endif

        setBit(parityBit0Reg, parityBit0, config.parityMode & 0x01);
        setBit(parityBit1Reg, parityBit1, config.parityMode & 0x02);

        setBit(stopBitReg, stopBitBit, config.stopBit);

        setBit(clockPolarityReg, clockPolarityBit, config.clockPolarity);

        setBit(frameErrorReg, frameErrorBit, false);
        setBit(dataOverRunReg, dataOverRunBit, false);
        setBit(parityErrorReg, parityErrorBit, false);

        *baudRateRegHigh = config.baud >> 8;
        *baudRateRegLow = config.baud;

        mRXCompleteCallback = config.rxCompleteCallback;
        mTXCompleteCallback = config.txCompleteCallback;
        mDataRegEmptyCallback = config.dataRegisterEmptyCallback;
    }
}

void usartN(Push)(uint8_t b) {
    USART_N(_DATA_REG) = b;
}

void usartN(Push9)(uint16_t b) {
    if(b & 0x0100) {
        USART_N(_TX_DATA_BIT_8_REG) |= _BV(USART_N(_TX_DATA_BIT_8_BIT));
    } else {
        USART_N(_TX_DATA_BIT_8_REG) &= ~_BV(USART_N(_TX_DATA_BIT_8_BIT));
    }

    USART_N(_DATA_REG) = b;
}

uint8_t usartN(Pop)(void) {
    return USART_N(_DATA_REG);
}

uint16_t usartN(Pop9)(void) {
    uint8_t bit8 = USART_N(_RX_DATA_BIT_8_REG) & _BV(USART_N(_RX_DATA_BIT_8_BIT));
    uint8_t result = USART_N(_DATA_REG);

    if(bit8) {
        result |= 0x0100;
    }

    return result;
}

bool usartN(FrameError)() {
    bool result = USART_N(_FRAME_ERROR_REG) & _BV(USART_N(_FRAME_ERROR_BIT));

    USART_N(_FRAME_ERROR_REG) &= ~_BV(USART_N(_FRAME_ERROR_BIT));

    return result;
}

bool usartN(DataOverRun)() {
    bool result = USART_N(_DATA_OVERRUN_REG) & _BV(USART_N(_DATA_OVERRUN_BIT));

    USART_N(_DATA_OVERRUN_REG) &= ~_BV(USART_N(_DATA_OVERRUN_BIT));

    return result;
}

bool usartN(ParityError)() {
    bool result = USART_N(_PARITY_ERROR_REG) & _BV(USART_N(_PARITY_ERROR_BIT));

    USART_N(_PARITY_ERROR_REG) &= ~_BV(USART_N(_PARITY_ERROR_BIT));

    return result;
}

void usartN(RXCompleteInterruptEnable)(bool b) {
    if(b) {
        USART_N(_RX_COMPLETE_INT_ENABLE_REG) |= _BV(USART_N(_RX_COMPLETE_INT_ENABLE_BIT));
    } else {
        USART_N(_RX_COMPLETE_INT_ENABLE_REG) &= ~_BV(USART_N(_RX_COMPLETE_INT_ENABLE_BIT));
    }
}

void usartN(TXCompleteInterruptEnable)(bool b) {
    if(b) {
        USART_N(_TX_COMPLETE_INT_ENABLE_REG) |= _BV(USART_N(_TX_COMPLETE_INT_ENABLE_BIT));
    } else {
        USART_N(_TX_COMPLETE_INT_ENABLE_REG) &= ~_BV(USART_N(_TX_COMPLETE_INT_ENABLE_BIT));
    }
}

void usartN(DataRegisterEmptyInterruptEnable)(bool b) {
    if(b) {
        USART_N(_DATA_REG_EMPTY_INT_ENABLE_REG) |= _BV(USART_N(_DATA_REG_EMPTY_INT_ENABLE_BIT));
    } else {
        USART_N(_DATA_REG_EMPTY_INT_ENABLE_REG) &= ~_BV(USART_N(_DATA_REG_EMPTY_INT_ENABLE_BIT));
    }
}

void usartN(ReceiverEnable)(bool b) {
    if(b) {
        USART_N(_RX_ENABLE_REG) |= _BV(USART_N(_RX_ENABLE_BIT));
    } else {
        USART_N(_RX_ENABLE_REG) &= ~_BV(USART_N(_RX_ENABLE_BIT));
    }
}

void usartN(TransmitterEnable)(bool b) {
    if(b) {
        USART_N(_TX_ENABLE_REG) |= _BV(USART_N(_TX_ENABLE_BIT));
    } else {
        USART_N(_TX_ENABLE_REG) &= ~_BV(USART_N(_TX_ENABLE_BIT));
    }
}

ISR(USART_N(_RX_COMPLETE_INT_VECTOR)) {
    if(mRXCompleteCallback != NULL) {
        mRXCompleteCallback();
    }
}

ISR(USART_N(_TX_COMPLETE_INT_VECTOR)) {
    if(mTXCompleteCallback != NULL) {
        mTXCompleteCallback();
    }
}

ISR(USART_N(_DATA_REG_EMPTY_INT_VECTOR)) {
    if(mDataRegEmptyCallback != NULL) {
        mDataRegEmptyCallback();
    }
}
