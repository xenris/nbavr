static IntCallback mIntCallback;

void intN()(IntTrigger trigger, IntCallback callback) {
    atomic {
        uint8_t* enableReg = (uint8_t*)&INT_N(_ENABLE_REG);
        uint8_t* flagReg = (uint8_t*)&INT_N(_FLAG_REG);
        uint8_t* triggerBit0Reg = (uint8_t*)&INT_N(_TRIGGER_BIT_0_REG);
        uint8_t* triggerBit1Reg = (uint8_t*)&INT_N(_TRIGGER_BIT_1_REG);

        uint8_t enableBit = INT_N(_ENABLE_BIT);
        uint8_t flagBit = INT_N(_FLAG_BIT);
        uint8_t triggerBit0 = INT_N(_TRIGGER_BIT_0);
        uint8_t triggerBit1 = INT_N(_TRIGGER_BIT_1);

        // Register callback.
        mIntCallback = callback;

        if(trigger == IntDisable) {
            // Disable interrupt.
            setBit(enableReg, enableBit, false);
        } else {
            // Configure trigger.
            setBit(triggerBit0Reg, triggerBit0, trigger & 0x01);
            setBit(triggerBit1Reg, triggerBit1, trigger & 0x02);

            // Enable interrupt.
            setBit(enableReg, enableBit, true);
        }

        // Clear interrupt flag.
        setBit(flagReg, flagBit, true);
    }
}

ISR(INT_N(_VECTOR)) {
    if(mIntCallback != NULL) {
        mIntCallback();
    }
}
