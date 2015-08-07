#include "twi.h"

#define TWI_SEND_START (_BV(TWINT) | _BV(TWSTA) | _BV(TWEN) | _BV(TWIE))
#define TWI_SEND_ACK (_BV(TWINT) | _BV(TWEN) | _BV(TWIE) | _BV(TWEA))
#define TWI_SEND_NACK (_BV(TWINT) | _BV(TWEN) | _BV(TWIE))
#define TWI_SEND_STOP (_BV(TWINT) | _BV(TWSTO) | _BV(TWEN) | _BV(TWIE))
#define TWI_CLEAR_INT (_BV(TWINT) | _BV(TWEN) | _BV(TWIE))
#define TWI_CLEAR_ERROR (_BV(TWINT) | _BV(TWSTO) | _BV(TWEN) | _BV(TWIE))

static bool mReady;
static uint8_t mDataIndex;
static TWIAction* mAction;
static uint8_t* mStatus;

void twiInit(uint16_t kHz) {
    const uint32_t scaleFactor = 1;
    TWBR = (uint8_t)((((F_CPU / 1000UL) / kHz) - 16UL) / (2UL * scaleFactor));

    mReady = true;
}

bool twiDoAction(TWIAction* action, uint8_t* status) {
    if(!mReady) {
        return false;
    }

    mReady = false;
    mAction = action;
    mStatus = status;

    *mStatus = TWI_BUSY;

    TWCR = TWI_SEND_START;

    return true;
}

#ifdef INCLUDE_TWI

ISR(TWI_vect) {
    const uint8_t twStatus = TW_STATUS;
    uint8_t tempTWCR = 0;

    switch(twStatus) {
        case TW_START:
        case TW_REP_START:
            TWDR = (uint8_t)(mAction->addr << 1) | mAction->rw;
            tempTWCR = TWI_CLEAR_INT;
            break;
        case TW_MT_SLA_ACK:
        case TW_MT_DATA_ACK:
            if(mDataIndex < mAction->count) {
                TWDR = mAction->data[mDataIndex];
                mDataIndex++;
                tempTWCR = TWI_CLEAR_INT;
            } else {
                mAction = mAction->next;

                if(mAction != NULL) {
                    mDataIndex = 0;
                    tempTWCR = TWI_SEND_START;
                } else {
                    *mStatus = TWI_SUCCESS;
                    tempTWCR = TWI_SEND_STOP;
                }
            }
            break;
        case TW_MT_SLA_NACK:
        case TW_MT_DATA_NACK:
            *mStatus = TWI_FAIL;
            tempTWCR = TWI_SEND_STOP;
            break;
        case TW_MT_ARB_LOST: // and TW_MR_ARB_LOST
            *mStatus = TWI_FAIL;
            tempTWCR = TWI_CLEAR_INT;
            break;
        case TW_MR_SLA_ACK:
            if(mAction->count > 1) {
                tempTWCR = TWI_SEND_ACK;
            } else {
                tempTWCR = TWI_SEND_NACK;
            }
            break;
        case TW_MR_SLA_NACK:
            *mStatus = TWI_FAIL;
            tempTWCR = TWI_SEND_STOP;
            break;
        case TW_MR_DATA_ACK:
            mAction->data[mDataIndex] = TWDR;
            mDataIndex++;

            if(mDataIndex < (mAction->count - 1)) {
                tempTWCR = TWI_SEND_ACK;
            } else {
                tempTWCR = TWI_SEND_NACK;
            }
            break;
        case TW_MR_DATA_NACK:
            mAction->data[mDataIndex] = TWDR;
            mAction = mAction->next;

            if(mAction != NULL) {
                tempTWCR = TWI_SEND_START;
            } else {
                *mStatus = TWI_SUCCESS;
                tempTWCR = TWI_SEND_STOP;
            }
            break;
        case TW_ST_SLA_ACK:
        case TW_ST_ARB_LOST_SLA_ACK:
        case TW_ST_DATA_ACK:
        case TW_ST_DATA_NACK:
        case TW_ST_LAST_DATA:
        case TW_SR_SLA_ACK:
        case TW_SR_ARB_LOST_SLA_ACK:
        case TW_SR_GCALL_ACK:
        case TW_SR_ARB_LOST_GCALL_ACK:
        case TW_SR_DATA_ACK:
        case TW_SR_DATA_NACK:
        case TW_SR_GCALL_DATA_ACK:
        case TW_SR_GCALL_DATA_NACK:
        case TW_SR_STOP:
            tempTWCR = TWI_SEND_NACK;
            break;
        case TW_NO_INFO:
            break;
        case TW_BUS_ERROR:
            *mStatus = TWI_FAIL;
            tempTWCR = TWI_CLEAR_ERROR;
            break;
    }

    TWCR = tempTWCR;

    mReady = (*mStatus != TWI_BUSY);
}

#endif
