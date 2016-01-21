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
    bool ready;
    bool repeatStartRequested;
    uint8_t dataIndex;
    TWIAction action;
    uint8_t currentInputStream;
} mData;

static void setup(Task* task);
static void loop(Task* task);

Task twiTask = {
    .data = &mData,
    .dataSize = sizeof(mData),
    .setup = setup,
    .loop = loop,
    .priority = PRIORITY_DRIVER,
};

static void setup(Task* task) {
    const uint32_t scaleFactor = 1;
    TWBR = (uint8_t)((((F_CPU / 1000UL) / TWI_BAUD) - 16UL) / (2UL * scaleFactor));

    twiEnable();

    mData.ready = true;
    mData.repeatStartRequested = false;
    mData.currentInputStream = 0;
}

static void loop(Task* task) {
    if(mData.ready || mData.repeatStartRequested) {
        Stream* stream = task->inputStreams[mData.currentInputStream];

        if(streamPopBuffer(stream, sizeof(TWIAction), (uint8_t*)&mData.action)) {
            mData.ready = false;
            mData.dataIndex = 0;
            if(mData.action.result != NULL) {
                *mData.action.result = TWI_BUSY;
            }
            mData.repeatStartRequested = false;

            twiSendStart();
        } else {
            if(!mData.repeatStartRequested) { // Only go to next input if not waiting on repeated start.
                mData.currentInputStream = (mData.currentInputStream + 1) % task->inputStreamCount;
            }
        }
    }

    uint8_t twStatus = TW_STATUS;

    if(twStatus == TW_NO_INFO) {
        return;
    }

    switch(twStatus) {
        case TW_START:
        case TW_REP_START:
            TWDR = (uint8_t)(mData.action.addr << 1) | mData.action.rw;
            twiSendNACK();
            break;
        case TW_MT_SLA_ACK:
        case TW_MT_DATA_ACK:
            if(mData.dataIndex < mData.action.count) {
                TWDR = mData.action.data[mData.dataIndex];
                mData.dataIndex++;
                twiSendNACK();
            } else {
                if(mData.action.repeatStart) {
                    mData.repeatStartRequested = true;
                    twiSendStart();
                } else {
                    *mData.action.result = TWI_SUCCESS;
                    twiSendStop();
                }
            }
            break;
        case TW_MT_SLA_NACK:
        case TW_MT_DATA_NACK:
            *mData.action.result = TWI_FAIL;
            twiSendStop();
            break;
        case TW_MT_ARB_LOST: // and TW_MR_ARB_LOST
            *mData.action.result = TWI_FAIL;
            twiClearInt();
            break;
        case TW_MR_SLA_ACK:
            twiSendACK();
            break;
        case TW_MR_SLA_NACK:
            *mData.action.result = TWI_FAIL;
            twiSendStop();
            break;
        case TW_MR_DATA_ACK:
            mData.action.data[mData.dataIndex] = TWDR;
            mData.dataIndex++;

            if(mData.dataIndex < mData.action.count) {
                twiSendACK();
            } else {
                twiSendNACK();
            }
            break;
        case TW_MR_DATA_NACK:
            if(mData.action.repeatStart) {
                mData.repeatStartRequested = true;
                twiSendStart();
            } else {
                *mData.action.result = TWI_SUCCESS;
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
            *mData.action.result = TWI_FAIL;
            twiClearError();
            break;
    }

    mData.ready = (*mData.action.result != TWI_BUSY);
}

bool twiDo(Stream* stream, TWIAction* action) {
    if(streamPushBuffer(stream, sizeof(TWIAction), (uint8_t*)action)) {
        *action->result = TWI_QUEUED;
        return true;
    } else {
        *action->result = TWI_FAIL;
        return false;
    }
}
