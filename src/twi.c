#include "twi.h"

#define twiEnable() TWCR = _BV(TWEN)
#define twiDisable() TWCR = 0
#define twiSendStart() TWCR = (_BV(TWINT) | _BV(TWSTA) | _BV(TWEN))
#define twiSendACK() TWCR = (_BV(TWINT) | _BV(TWEN) | _BV(TWEA))
#define twiSendNACK() TWCR = (_BV(TWINT) | _BV(TWEN))
#define twiSendStop() TWCR = (_BV(TWINT) | _BV(TWSTO) | _BV(TWEN))
#define twiClearInt() TWCR = (_BV(TWINT) | _BV(TWEN))
#define twiClearError() TWCR = (_BV(TWINT) | _BV(TWSTO) | _BV(TWEN))

static struct {
    bool initialised;
    bool ready;
    uint8_t dataIndex;
    TWIAction* action;
    volatile TWIResult* result;
} mData;

static void setup(Task* task, uint32_t millis);
static void loop(Task* task, uint32_t millis);

static TWIAction* mNextAction;
static volatile TWIResult* mNextResult;

Task twiTask = {&mData, sizeof(mData), setup, NULL, PRIORITY_DRIVER, NULL, 0, NULL, 0};

static void setup(Task* task, uint32_t millis) {
    const uint32_t scaleFactor = 1;
    TWBR = (uint8_t)((((F_CPU / 1000UL) / TWI_BAUD) - 16UL) / (2UL * scaleFactor));

    twiEnable();

    task->function = loop;

    mData.ready = true;
}

static void loop(Task* task, uint32_t millis) {
    if(mData.ready && (mNextAction != NULL)) {
        mData.ready = false;
        mData.dataIndex = 0;
        mData.action = mNextAction;
        mData.result = mNextResult;
        *mData.result = TWI_BUSY;

        mNextAction = NULL;
        mNextResult = NULL;

        twiSendStart();
    }

    uint8_t twStatus = TW_STATUS;

    if(twStatus == TW_NO_INFO) {
        return true;
    }

    // XXX What to do here? Presumably this will only happen in slave mode,
    //  right? So it should be safe to enter the switch with a NULL action...?
    if(mData.action == NULL) {
//        printf("DEBUG: action == NULL (file %s, line: %i)\n", __FILE__, __LINE__);
    }

    switch(twStatus) {
        case TW_START:
        case TW_REP_START:
            TWDR = (uint8_t)(mData.action->addr << 1) | mData.action->rw;
            twiSendNACK();
            break;
        case TW_MT_SLA_ACK:
        case TW_MT_DATA_ACK:
            if(mData.dataIndex < mData.action->count) {
                TWDR = mData.action->data[mData.dataIndex];
                mData.dataIndex++;
                twiSendNACK();
            } else {
                mData.action = mData.action->next;

                if(mData.action != NULL) {
                    mData.dataIndex = 0;
                    twiSendStart();
                } else {
                    *mData.result = TWI_SUCCESS;
                    twiSendStop();
                }
            }
            break;
        case TW_MT_SLA_NACK:
        case TW_MT_DATA_NACK:
            *mData.result = TWI_FAIL;
            twiSendStop();
            break;
        case TW_MT_ARB_LOST: // and TW_MR_ARB_LOST
            *mData.result = TWI_FAIL;
            twiClearInt();
            break;
        case TW_MR_SLA_ACK:
            twiSendACK();
            break;
        case TW_MR_SLA_NACK:
            *mData.result = TWI_FAIL;
            twiSendStop();
            break;
        case TW_MR_DATA_ACK:
            mData.action->data[mData.dataIndex] = TWDR;
            mData.dataIndex++;

            if(mData.dataIndex < mData.action->count) {
                twiSendACK();
            } else {
                twiSendNACK();
            }
            break;
        case TW_MR_DATA_NACK:
            mData.action = mData.action->next;

            if(mData.action != NULL) {
                twiSendStart();
            } else {
                *mData.result = TWI_SUCCESS;
                twiSendStop();
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
            twiSendNACK();
            break;
        case TW_NO_INFO:
            break;
        case TW_BUS_ERROR:
            *mData.result = TWI_FAIL;
            twiClearError();
            break;
    }

    mData.ready = (*mData.result != TWI_BUSY);

    return true;
}

bool twiDoAction(TWIAction* action, volatile TWIResult* result) {
    if(mNextAction != NULL) {
        *result = TWI_FAIL;
        return false;
    }

    mNextAction = action;
    mNextResult = result;

    *result = TWI_QUEUED;

    return true;
}
