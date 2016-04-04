#include "adc.h"

#ifdef CHIP_ADC

static ADCCallback mADCCallback;

void adcStart(ADCConfig config) {
    atomic {
        // Define non-volatile versions of the registers for compiler optimisation.
        uint8_t* enableReg = (uint8_t*)&CHIP_ADC_ENABLE_REG;
        uint8_t* startReg = (uint8_t*)&CHIP_ADC_START_REG;
        uint8_t* intFlagReg = (uint8_t*)&CHIP_ADC_INT_FLAG_REG;
        #ifdef CHIP_ADC_TRIGGER
        uint8_t* autoEnableReg = (uint8_t*)&CHIP_ADC_TRIGGER_ENABLE_REG;
        uint8_t* triggerBit0Reg = (uint8_t*)&CHIP_ADC_TRIGGER_BIT_0_REG;
        uint8_t* triggerBit1Reg = (uint8_t*)&CHIP_ADC_TRIGGER_BIT_1_REG;
        uint8_t* triggerBit2Reg = (uint8_t*)&CHIP_ADC_TRIGGER_BIT_2_REG;
        #else
        uint8_t* autoEnableReg = (uint8_t*)&CHIP_ADC_FREE_RUNNING_ENABLE_REG;
        #endif
        uint8_t* leftAdjustReg = (uint8_t*)&CHIP_ADC_LEFT_ADJUST_REG;
        uint8_t* channelBit0Reg = (uint8_t*)&CHIP_ADC_CHANNEL_BIT_0_REG;
        uint8_t* channelBit1Reg = (uint8_t*)&CHIP_ADC_CHANNEL_BIT_1_REG;
        uint8_t* channelBit2Reg = (uint8_t*)&CHIP_ADC_CHANNEL_BIT_2_REG;
        uint8_t* channelBit3Reg = (uint8_t*)&CHIP_ADC_CHANNEL_BIT_3_REG;
        #ifdef CHIP_ADC_PRESCALER
        uint8_t* prescalerBit0Reg = (uint8_t*)&CHIP_ADC_PRESCALER_BIT_0_REG;
        uint8_t* prescalerBit1Reg = (uint8_t*)&CHIP_ADC_PRESCALER_BIT_1_REG;
        uint8_t* prescalerBit2Reg = (uint8_t*)&CHIP_ADC_PRESCALER_BIT_2_REG;
        #endif

        uint8_t enableBit = CHIP_ADC_ENABLE_BIT;
        uint8_t startBit = CHIP_ADC_START_BIT;
        uint8_t intFlagBit = CHIP_ADC_INT_FLAG_BIT;

        #ifdef CHIP_ADC_TRIGGER
        uint8_t autoEnableBit = CHIP_ADC_TRIGGER_ENABLE_BIT;
        uint8_t triggerBit0 = CHIP_ADC_TRIGGER_BIT_0;
        uint8_t triggerBit1 = CHIP_ADC_TRIGGER_BIT_1;
        uint8_t triggerBit2 = CHIP_ADC_TRIGGER_BIT_2;
        #else
        uint8_t autoEnableBit = CHIP_ADC_FREE_RUNNING_ENABLE_BIT;
        #endif
        uint8_t leftAdjustBit = CHIP_ADC_LEFT_ADJUST_BIT;
        uint8_t channelBit0 = CHIP_ADC_CHANNEL_BIT_0;
        uint8_t channelBit1 = CHIP_ADC_CHANNEL_BIT_1;
        uint8_t channelBit2 = CHIP_ADC_CHANNEL_BIT_2;
        uint8_t channelBit3 = CHIP_ADC_CHANNEL_BIT_3;
        #ifdef CHIP_ADC_PRESCALER
        uint8_t prescalerBit0 = CHIP_ADC_PRESCALER_BIT_0;
        uint8_t prescalerBit1 = CHIP_ADC_PRESCALER_BIT_1;
        uint8_t prescalerBit2 = CHIP_ADC_PRESCALER_BIT_2;
        #endif

        // TODO Disable ADC power reduction. (Needed?)

        // Enable ADC.
        setBit(enableReg, enableBit, true);

        // Clear interrupt flag.
        setBit(intFlagReg, intFlagBit, true);

        // Enable auto trigger or free running.
        setBit(autoEnableReg, autoEnableBit, config.trigger != ADC_TRIGGER_SINGLE_CONVERSION);

        // Set auto trigger value.
        #ifdef CHIP_ADC_TRIGGER
        setBit(triggerBit0Reg, triggerBit0, config.trigger & 0x01);
        setBit(triggerBit1Reg, triggerBit1, config.trigger & 0x02);
        setBit(triggerBit2Reg, triggerBit2, config.trigger & 0x04);
        #endif

        // Set left adjust.
        setBit(leftAdjustReg, leftAdjustBit, config.leftAdjust);

        // Set input channel.
        setBit(channelBit0Reg, channelBit0, config.channel & 0x01);
        setBit(channelBit1Reg, channelBit1, config.channel & 0x02);
        setBit(channelBit2Reg, channelBit2, config.channel & 0x04);
        setBit(channelBit3Reg, channelBit3, config.channel & 0x08);

        // Set prescaler
        #ifdef CHIP_ADC_PRESCALER
        setBit(prescalerBit0Reg, prescalerBit0, config.prescaler & 0x01);
        setBit(prescalerBit1Reg, prescalerBit1, config.prescaler & 0x02);
        setBit(prescalerBit2Reg, prescalerBit2, config.prescaler & 0x04);
        #endif

        // Register callback.
        mADCCallback = config.callback;

        // Start ADC.
        if((config.trigger == ADC_TRIGGER_SINGLE_CONVERSION)
        || (config.trigger == ADC_TRIGGER_FREE_RUNNING)) {
            setBit(startReg, startBit, true);
        }
    }
}

void adcStop(void) {
    atomic {
        uint8_t* enableReg = (uint8_t*)&CHIP_ADC_ENABLE_REG;
        uint8_t* intFlagReg = (uint8_t*)&CHIP_ADC_INT_FLAG_REG;

        uint8_t enableBit = CHIP_ADC_ENABLE_BIT;
        uint8_t intFlagBit = CHIP_ADC_INT_FLAG_BIT;

        // Disable ADC
        setBit(enableReg, enableBit, false);

        // Clear interrupt flag
        setBit(intFlagReg, intFlagBit, true);
    }
}

ISR(CHIP_ADC_INT_VECTOR) {
    uint16_t value = CHIP_ADC_DATA_REG;

    if(mADCCallback != NULL) {
        mADCCallback(value);
    }
}

#endif // #ifdef CHIP_ADC
