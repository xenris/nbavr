static PCIntCallback mPCIntCallback;

void pcintN()(uint8_t active, PCIntCallback callback) {
    atomic {
        uint8_t* enableReg = (uint8_t*)&PC_INT_N(_ENABLE_REG);
        uint8_t* flagReg = (uint8_t*)&PC_INT_N(_FLAG_REG);
        uint8_t* maskReg = (uint8_t*)&PC_INT_N(_MASK_REG);

        uint8_t enableBit = PC_INT_N(_ENABLE_BIT);
        uint8_t flagBit = PC_INT_N(_FLAG_BIT);
        uint8_t maskBits = PC_INT_N(_MASK_BITS);

        mPCIntCallback = callback;

        *maskReg = active & maskBits;

        setBit(enableReg, enableBit, active != 0x00);

        setBit(flagReg, flagBit, true);
    }
}

ISR(PC_INT_N(_VECTOR)) {
    if(mPCIntCallback != NULL) {
        mPCIntCallback();
    }
}
