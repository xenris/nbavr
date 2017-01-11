#ifndef NBAVR_TWI_HPP
#define NBAVR_TWI_HPP

#include <nbavr.hpp>

#define TW_START		0x08
#define TW_REP_START		0x10
#define TW_MT_SLA_ACK		0x18
#define TW_MT_SLA_NACK		0x20
#define TW_MT_DATA_ACK		0x28
#define TW_MT_DATA_NACK		0x30
#define TW_MT_ARB_LOST		0x38
#define TW_MR_ARB_LOST		0x38
#define TW_MR_SLA_ACK		0x40
#define TW_MR_SLA_NACK		0x48
#define TW_MR_DATA_ACK		0x50
#define TW_MR_DATA_NACK		0x58
#define TW_ST_SLA_ACK		0xA8
#define TW_ST_ARB_LOST_SLA_ACK	0xB0
#define TW_ST_DATA_ACK		0xB8
#define TW_ST_DATA_NACK		0xC0
#define TW_ST_LAST_DATA		0xC8
#define TW_SR_SLA_ACK		0x60
#define TW_SR_ARB_LOST_SLA_ACK	0x68
#define TW_SR_GCALL_ACK		0x70
#define TW_SR_ARB_LOST_GCALL_ACK 0x78
#define TW_SR_DATA_ACK		0x80
#define TW_SR_DATA_NACK		0x88
#define TW_SR_GCALL_DATA_ACK	0x90
#define TW_SR_GCALL_DATA_NACK	0x98
#define TW_SR_STOP		0xA0
#define TW_NO_INFO		0xF8
#define TW_BUS_ERROR		0x00
#define TW_STATUS_MASK		(_BV(TWS7)|_BV(TWS6)|_BV(TWS5)|_BV(TWS4)|\
				_BV(TWS3))
#define TW_STATUS		(TWSR & TW_STATUS_MASK)
#define TW_READ		1
#define TW_WRITE	0

#define TWCR REG8(0xBC)
#define TWIE 0
#define TWEN 2
#define TWWC 3
#define TWSTO 4
#define TWSTA 5
#define TWEA 6
#define TWINT 7

#define TWBR REG8(0xB8)
#define TWBR0 0
#define TWBR1 1
#define TWBR2 2
#define TWBR3 3
#define TWBR4 4
#define TWBR5 5
#define TWBR6 6
#define TWBR7 7

#define TWSR REG8(0xB9)
#define TWPS0 0
#define TWPS1 1
#define TWS3 3
#define TWS4 4
#define TWS5 5
#define TWS6 6
#define TWS7 7

#define TWDR REG8(0xBB)

#define TWI_BAUD 400
#define twiEnable() TWCR = _BV(TWEN)
#define twiDisable() TWCR = 0
#define twiSendStart() TWCR = (_BV(TWINT) | _BV(TWSTA) | _BV(TWEN))
#define twiSendACK() TWCR = (_BV(TWINT) | _BV(TWEN) | _BV(TWEA))
#define twiSendNACK() TWCR = (_BV(TWINT) | _BV(TWEN))
#define twiSendStop() TWCR = (_BV(TWINT) | _BV(TWSTO) | _BV(TWEN))
#define twiClearInt() TWCR = (_BV(TWINT) | _BV(TWEN))
#define twiClearError() TWCR = (_BV(TWINT) | _BV(TWSTO) | _BV(TWEN))

class TWI : public Task {
    public:
        enum class Mode : uint8_t {
            Read = TW_READ,
            Write = TW_WRITE,
        };

        enum class Result : uint8_t {
            None,
            Queued,
            Busy,
            Success,
            Fail,
        };

        struct Action {
            Mode rw;
            uint8_t addr;
            uint8_t count;
            uint8_t* data;
            Result* result;
            bool repeatStart;
        };

        bool ready;
        bool repeatStartRequested;
        uint8_t dataIndex;
        Action action;

/*        bool twiDo(Action& action) {*/
/*            if(twiout.push(action)) {*/
/*                *action.result = Result::Queued;*/
/*                return true;*/
/*            } else {*/
/*                *action.result = Result::Fail;*/
/*                return false;*/
/*            }*/
/*        }*/

        Stream<Action>& twiout;

        TWI(Stream<Action>& twiout) : twiout(twiout) {
            const uint32_t scaleFactor = 1;
            TWBR = (uint8_t)((((F_CPU / 1000UL) / TWI_BAUD) - 16UL) / (2UL * scaleFactor));

            twiEnable();

            ready = true;
            repeatStartRequested = false;
            dataIndex = 0;
        }

    protected:

        void loop() override {
            if(ready || repeatStartRequested) {
                if(twiout.pop(&action)) {
                    ready = false;
                    dataIndex = 0;
                    if(action.result != NULL) {
                        *action.result = Result::Busy;
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
                    TWDR = (uint8_t)(action.addr << 1) | (uint8_t)action.rw;
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
                            *action.result = Result::Success;
                            twiSendStop();
                        }
                    }
                    break;
                case TW_MT_SLA_NACK:
                case TW_MT_DATA_NACK:
                    *action.result = Result::Fail;
                    twiSendStop();
                    break;
                case TW_MT_ARB_LOST: // and TW_MR_ARB_LOST
                    *action.result = Result::Fail;
                    twiClearInt();
                    break;
                case TW_MR_SLA_ACK:
                    twiSendACK();
                    break;
                case TW_MR_SLA_NACK:
                    *action.result = Result::Fail;
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
                        *action.result = Result::Success;
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
                    *action.result = Result::Fail;
                    twiClearError();
                    break;
            }

            ready = (*action.result != Result::Busy);
        }
};

#endif
