#include "twi.h"

#define twiEnable() TWCR = _BV(TWEN)
#define twiDisable() TWCR = 0
#define twiSendStart() TWCR = (_BV(TWINT) | _BV(TWSTA) | _BV(TWEN))
#define twiSendACK() TWCR = (_BV(TWINT) | _BV(TWEN) | _BV(TWEA))
#define twiSendNACK() TWCR = (_BV(TWINT) | _BV(TWEN))
#define twiSendStop() TWCR = (_BV(TWINT) | _BV(TWSTO) | _BV(TWEN))
#define twiClearInt() TWCR = (_BV(TWINT) | _BV(TWEN))
#define twiClearError() TWCR = (_BV(TWINT) | _BV(TWSTO) | _BV(TWEN))

static void setup(void);
static void loop(void);

static bool ready;
static bool repeatStartRequested;
static uint8_t dataIndex;
static TWIAction action;

Stream twiStream = streamInit(2 * sizeof(TWIAction));

Task twiTask = {
    .setup = setup,
    .loop = loop,
    .priority = PRIORITY_DRIVER,
};

static void setup(void) {
    const uint32_t scaleFactor = 1;
    TWBR = (uint8_t)((((F_CPU / 1000UL) / TWI_BAUD) - 16UL) / (2UL * scaleFactor));

    twiEnable();

    ready = true;
    repeatStartRequested = false;
    dataIndex = 0;
}

static void loop(void) {
    if(ready || repeatStartRequested) {
        if(streamPopBuffer(&twiStream, sizeof(TWIAction), (uint8_t*)&action)) {
            ready = false;
            dataIndex = 0;
            if(action.result != NULL) {
                *action.result = TWI_BUSY;
            }
            repeatStartRequested = false;

            twiSendStart();
        }
    }

    uint8_t twStatus = TW_STATUS;

    if(twStatus == TW_NO_INFO) {
        return;
    }

    switch(twStatus) {
        case TW_START:
        case TW_REP_START:
            TWDR = (uint8_t)(action.addr << 1) | action.rw;
            twiSendNACK();
            break;
        case TW_MT_SLA_ACK:
        case TW_MT_DATA_ACK:
            if(dataIndex < action.count) {
                TWDR = action.data[dataIndex];
                dataIndex++;
                twiSendNACK();
            } else {
                if(action.repeatStart) {
                    repeatStartRequested = true;
                    twiSendStart();
                } else {
                    *action.result = TWI_SUCCESS;
                    twiSendStop();
                }
            }
            break;
        case TW_MT_SLA_NACK:
        case TW_MT_DATA_NACK:
            *action.result = TWI_FAIL;
            twiSendStop();
            break;
        case TW_MT_ARB_LOST: // and TW_MR_ARB_LOST
            *action.result = TWI_FAIL;
            twiClearInt();
            break;
        case TW_MR_SLA_ACK:
            twiSendACK();
            break;
        case TW_MR_SLA_NACK:
            *action.result = TWI_FAIL;
            twiSendStop();
            break;
        case TW_MR_DATA_ACK:
            action.data[dataIndex] = TWDR;
            dataIndex++;

            if(dataIndex < action.count) {
                twiSendACK();
            } else {
                twiSendNACK();
            }
            break;
        case TW_MR_DATA_NACK:
            if(action.repeatStart) {
                repeatStartRequested = true;
                twiSendStart();
            } else {
                *action.result = TWI_SUCCESS;
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
            *action.result = TWI_FAIL;
            twiClearError();
            break;
    }

    ready = (*action.result != TWI_BUSY);
}

bool twiDo(TWIAction* action) {
    if(streamPushBuffer(&twiStream, sizeof(TWIAction), (uint8_t*)action)) {
        *action->result = TWI_QUEUED;
        return true;
    } else {
        *action->result = TWI_FAIL;
        return false;
    }
}
