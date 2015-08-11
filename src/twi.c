#include "twi.h"

#define twiEnable() TWCR = _BV(TWEN)
#define twiDisable() TWCR = 0
#define twiSendStart() TWCR = (_BV(TWINT) | _BV(TWSTA) | _BV(TWEN))
#define twiSendACK() TWCR = (_BV(TWINT) | _BV(TWEN) | _BV(TWEA))
#define twiSendNACK() TWCR = (_BV(TWINT) | _BV(TWEN))
#define twiSendStop() TWCR = (_BV(TWINT) | _BV(TWSTO) | _BV(TWEN))
#define twiClearInt() TWCR = (_BV(TWINT) | _BV(TWEN))
#define twiClearError() TWCR = (_BV(TWINT) | _BV(TWSTO) | _BV(TWEN))

typedef struct {
    bool initialised;
    bool ready;
    uint8_t dataIndex;
    TWIAction* action;
    volatile TWIResult* result;
} TWIData;

bool twiTask(void* data, uint32_t millis);

static TWIAction* mNextAction;
static volatile TWIResult* mNextResult;

void twiInit(TaskManager* taskManager, uint16_t kHz) {
    const uint32_t scaleFactor = 1;
    TWBR = (uint8_t)((((F_CPU / 1000UL) / kHz) - 16UL) / (2UL * scaleFactor));

    twiEnable();

    taskManagerAddTask(taskManager, twiTask, sizeof(TWIData), "twiTask", PRIORITY_HIGH);
}

bool twiTask(void* data, uint32_t millis) {
    TWIData* twiData = (TWIData*)data;
    (void)millis;

    if(!twiData->initialised) {
        twiData->ready = true;
        twiData->initialised = true;
    }

    if(twiData->ready && (mNextAction != NULL)) {
        twiData->ready = false;
        twiData->dataIndex = 0;
        twiData->action = mNextAction;
        twiData->result = mNextResult;
        *twiData->result = TWI_BUSY;

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
    if(twiData->action == NULL) {
        printf("DEBUG: action == NULL (file %s, line: %i)\n", __FILE__, __LINE__);
    }

    switch(twStatus) {
        case TW_START:
        case TW_REP_START:
            TWDR = (uint8_t)(twiData->action->addr << 1) | twiData->action->rw;
            twiSendNACK();
            break;
        case TW_MT_SLA_ACK:
        case TW_MT_DATA_ACK:
            if(twiData->dataIndex < twiData->action->count) {
                TWDR = twiData->action->data[twiData->dataIndex];
                twiData->dataIndex++;
                twiSendNACK();
            } else {
                twiData->action = twiData->action->next;

                if(twiData->action != NULL) {
                    twiData->dataIndex = 0;
                    twiSendStart();
                } else {
                    *twiData->result = TWI_SUCCESS;
                    twiSendStop();
                }
            }
            break;
        case TW_MT_SLA_NACK:
        case TW_MT_DATA_NACK:
            *twiData->result = TWI_FAIL;
            twiSendStop();
            break;
        case TW_MT_ARB_LOST: // and TW_MR_ARB_LOST
            *twiData->result = TWI_FAIL;
            twiClearInt();
            break;
        case TW_MR_SLA_ACK:
            twiSendACK();
            break;
        case TW_MR_SLA_NACK:
            *twiData->result = TWI_FAIL;
            twiSendStop();
            break;
        case TW_MR_DATA_ACK:
            twiData->action->data[twiData->dataIndex] = TWDR;
            twiData->dataIndex++;

            if(twiData->dataIndex < twiData->action->count) {
                twiSendACK();
            } else {
                twiSendNACK();
            }
            break;
        case TW_MR_DATA_NACK:
            twiData->action = twiData->action->next;

            if(twiData->action != NULL) {
                twiSendStart();
            } else {
                *twiData->result = TWI_SUCCESS;
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
            *twiData->result = TWI_FAIL;
            twiClearError();
            break;
    }

    twiData->ready = (*twiData->result != TWI_BUSY);

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
