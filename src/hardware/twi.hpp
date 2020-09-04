/// [[Index]]

/// # {{Two Wire Serial Interfaces}}

#ifndef NBLIB_TWI_HPP

#include "isr.hpp"
#include "chip.hpp"
#include "hardwaretype.hpp"
#include "macros.hpp"
#include "system.hpp"
#include "callback.hpp"

#include "loopi"

#ifdef _I
    #define N _I
    #define TwiN CAT(Twi, N)
    #define TWI_N(A) CAT(CHIP_TWI_, N, _, A)
    #define _TWI_N(A) UNDERLINE(TWI, N, A)

    #if DEFINED(CAT(CHIP_TWI_, N))

//------------------------------------------------------------------

namespace nblib::hw {

/// ## class {{TwiN}}
struct TwiN {
    TwiN() = delete;
    TwiN& operator=(const TwiN&) = delete;
    TwiN(const TwiN&) = delete;

    /// #### enum {{TwiN::Ack}}
    /// * nack
    /// * ack
    enum class Ack {
        nack = 0,
        ack = 1,
    };

    #if REG_DEFINED(TWI_N(PRESCALER_REG))
        /// #### enum {{TwiN::Prescaler}}
        /// * div1
        /// * div4
        /// * div16
        /// * div64
        enum class Prescaler {
            #if DEFINED(TWI_N(PRESCALER_1_ID))
                div1 = TWI_N(PRESCALER_1_ID),
            #endif

            #if DEFINED(TWI_N(PRESCALER_4_ID))
                div4 = TWI_N(PRESCALER_4_ID),
            #endif

            #if DEFINED(TWI_N(PRESCALER_16_ID))
                div16 = TWI_N(PRESCALER_16_ID),
            #endif

            #if DEFINED(TWI_N(PRESCALER_64_ID))
                div64 = TWI_N(PRESCALER_64_ID),
            #endif
        };
    #endif

    #if REG_DEFINED(TWI_N(MASTER_COMMAND_REG))
        /// #### enum {{TwiN::MasterCommand}}
        /// * noAction
        /// * repeatStart
        /// * receiveTransmit
        /// * acknowledge
        /// * stop
        enum class MasterCommand {
            #if DEFINED(TWI_N(MASTER_COMMAND_NO_ACTION_ID))
                noAction = TWI_N(MASTER_COMMAND_NO_ACTION_ID),
            #endif

            #if DEFINED(TWI_N(MASTER_COMMAND_REPEAT_START_ID))
                repeatStart = TWI_N(MASTER_COMMAND_REPEAT_START_ID),
            #endif

            #if DEFINED(TWI_N(MASTER_COMMAND_RECEIVE_TRANSMIT_ID))
                receiveTransmit = TWI_N(MASTER_COMMAND_RECEIVE_TRANSMIT_ID),
            #endif

            #if DEFINED(TWI_N(MASTER_COMMAND_ACKNOWLEDGE_ID))
                acknowledge = TWI_N(MASTER_COMMAND_ACKNOWLEDGE_ID),
            #endif

            #if DEFINED(TWI_N(MASTER_COMMAND_STOP_ID))
                stop = TWI_N(MASTER_COMMAND_STOP_ID),
            #endif
        };
    #endif

    #if REG_DEFINED(TWI_N(SLAVE_COMMAND_REG))
        /// #### enum {{TwiN::SlaveCommand}}
        /// * noAction
        /// * completeTransaction
        /// * response
        enum class SlaveCommand {
            #if DEFINED(TWI_N(SLAVE_COMMAND_NO_ACTION_ID))
                noAction = TWI_N(SLAVE_COMMAND_NO_ACTION_ID),
            #endif

            #if DEFINED(TWI_N(SLAVE_COMMAND_COMPLETE_TRANSACTION_ID))
                completeTransaction = TWI_N(SLAVE_COMMAND_COMPLETE_TRANSACTION_ID),
            #endif

            // XXX should this be "acknowledge"?

            #if DEFINED(TWI_N(SLAVE_COMMAND_RESPONSE_ID))
                response = TWI_N(SLAVE_COMMAND_RESPONSE_ID),
            #endif
        };
    #endif

    #if REG_DEFINED(TWI_N(BUS_STATE_REG))
        /// #### enum {{TwiN::BusState}}
        /// * unknown
        /// * idle
        /// * owner
        /// * busy
        enum class BusState {
            #if DEFINED(TWI_N(BUS_STATE_UNKNOWN_ID))
                unknown = TWI_N(BUS_STATE_UNKNOWN_ID),
            #endif

            #if DEFINED(TWI_N(BUS_STATE_IDLE_ID))
                idle = TWI_N(BUS_STATE_IDLE_ID),
            #endif

            #if DEFINED(TWI_N(BUS_STATE_OWNER_ID))
                owner = TWI_N(BUS_STATE_OWNER_ID),
            #endif

            #if DEFINED(TWI_N(BUS_STATE_BUSY_ID))
                busy = TWI_N(BUS_STATE_BUSY_ID),
            #endif
        };
    #endif

    #if REG_DEFINED(TWI_N(TIMEOUT_REG))
        /// #### enum {{TwiN::Timeout}}
        /// * disabled
        /// * us50
        /// * us100
        /// * us200
        enum class Timeout {
            #if DEFINED(TWI_N(TIMEOUT_DISABLED_ID))
                disabled = TWI_N(TIMEOUT_DISABLED_ID),
            #endif

            #if DEFINED(TWI_N(TIMEOUT_50_US_ID))
                us50 = TWI_N(TIMEOUT_50_US_ID),
            #endif

            #if DEFINED(TWI_N(TIMEOUT_100_US_ID))
                us100 = TWI_N(TIMEOUT_100_US_ID),
            #endif

            #if DEFINED(TWI_N(TIMEOUT_200_US_ID))
                us200 = TWI_N(TIMEOUT_200_US_ID),
            #endif
        };
    #endif

    /// #### enum {{TwiN::Status}}
    /// * startTransmitted
    /// * repeatedStartTransmitted
    /// * slawTransmittedAck
    /// * slawTransmittedNack
    /// * dataTransmittedAck
    /// * dataTransmittedNack
    /// * arbitrationLost
    /// * slarTransmittedAck
    /// * slarTransmittedNack
    /// * dataReceivedAck
    /// * dataReceivedNack
    /// * ownSlawReceivedAck
    /// * arbitrationLostOwnSlawAck
    /// * generalCallAddressReceivedAck
    /// * arbitrationLostGeneralCallAddressReceivedAck
    /// * prevAddressedOwnSlawDataReceivedAck
    /// * prevAddressedOwnSlawDataReceivedNack
    /// * prevAddressedGeneralCallDataReceivedAck
    /// * prevAddressedGeneralCallDataReceivedNack
    /// * stopOrRepeatedStartWhileAddressedAsSlave
    /// * ownSlarReceivedAck
    /// * arbitrationLostOwnSlarAck
    /// * dataInTwdrTransmittedAck
    /// * dataInTwdrTransmittedNack
    /// * lastDataTransmittedAck
    /// * noState
    /// * busError
    // TODO Look at status bits in other microcontrollers to see if they are all
    //  the same or if they need to be defined in the chip description.
    // TODO Split into master/slave receive/transmit.
    // enum class Status : uint8_t {
    //     busError = 0x00,
    //     startTransmitted = 0x08,
    //     repeatedStartTransmitted = 0x10,
    //     slawTransmittedAck = 0x18,
    //     slawTransmittedNack = 0x20,
    //     dataTransmittedAck = 0x28,
    //     dataTransmittedNack = 0x30,
    //     arbitrationLost = 0x38,
    //     slarTransmittedAck = 0x40,
    //     slarTransmittedNack = 0x48,
    //     dataReceivedAck = 0x50,
    //     dataReceivedNack = 0x58,
    //     ownSlawReceivedAck = 0x60,
    //     arbitrationLostOwnSlawAck = 0x68,
    //     generalCallAddressReceivedAck = 0x70,
    //     arbitrationLostGeneralCallAddressReceivedAck = 0x78,
    //     prevAddressedOwnSlawDataReceivedAck = 0x80,
    //     prevAddressedOwnSlawDataReceivedNack = 0x88,
    //     prevAddressedGeneralCallDataReceivedAck = 0x90,
    //     prevAddressedGeneralCallDataReceivedNack = 0x98,
    //     stopOrRepeatedStartWhileAddressedAsSlave = 0xA0,
    //     ownSlarReceivedAck = 0xA8,
    //     arbitrationLostOwnSLARAck = 0xB0,
    //     dataInTwdrTransmittedAck = 0xB8,
    //     dataInTwdrTransmittedNack = 0xC0,
    //     lastDataTransmittedAck = 0xC8,
    //     noState = 0xF8,
    // };

    /// #### static [[HardwareType]] getHardwareType()
    /// Get the type of hardware that this class represents.
    static constexpr HardwareType getHardwareType() {
        return HardwareType::twi;
    }

    #if REG_DEFINED(TWI_N(ENABLE_REG))
        /// #### static void enable(bool)
        static force_inline void enable(bool e) {
            TWI_N(ENABLE_REG)::setBit(TWI_N(ENABLE_BIT), e);
        }
    #endif

    #if REG_DEFINED(TWI_N(MASTER_ENABLE_REG))
        /// #### static void masterEnable(bool)
        static force_inline void masterEnable(bool e) {
            TWI_N(MASTER_ENABLE_REG)::setBit(TWI_N(MASTER_ENABLE_BIT), e);
        }
    #endif

    #if REG_DEFINED(TWI_N(SLAVE_ENABLE_REG))
        /// #### static void slaveEnable(bool)
        static force_inline void slaveEnable(bool e) {
            TWI_N(SLAVE_ENABLE_REG)::setBit(TWI_N(SLAVE_ENABLE_BIT), e);
        }
    #endif

    #if REG_DEFINED(TWI_N(ENABLE_ACK_REG))
        /// #### static void enableAck(bool)
        static force_inline void enableAck(bool e) {
            TWI_N(ENABLE_ACK_REG)::setBit(TWI_N(ENABLE_ACK_BIT), e);
        }
    #endif

    #if REG_DEFINED(TWI_N(START_CONDITION_REG))
        /// #### static void startCondition(bool)
        static force_inline void startCondition(bool e) {
            TWI_N(START_CONDITION_REG)::setBit(TWI_N(START_CONDITION_BIT), e);
        }
    #endif

    #if REG_DEFINED(TWI_N(STOP_CONDITION_REG))
        /// #### static void stopCondition(bool)
        static force_inline void stopCondition(bool e) {
            TWI_N(STOP_CONDITION_REG)::setBit(TWI_N(STOP_CONDITION_BIT), e);
        }
    #endif

    #if REG_DEFINED(TWI_N(BIT_RATE_REG))
        /// #### static void bitRate(uint8_t b)
        static force_inline void bitRate(uint8_t b) {
            TWI_N(BIT_RATE_REG)::setReg(b);
        }
    #endif

    #if REG_DEFINED(TWI_N(BAUD_REG))
        /// #### static void baud(uint8_t b)
        static force_inline void baud(uint8_t b) {
            TWI_N(BAUD_REG)::setReg(b);
        }
    #endif

    #if REG_DEFINED(TWI_N(INT_ENABLE_REG))
        /// #### static void intEnable(bool e)
        static force_inline void intEnable(bool e) {
            TWI_N(INT_ENABLE_REG)::setBit(TWI_N(INT_ENABLE_BIT), e);
        }
    #endif

    #if REG_DEFINED(TWI_N(INT_FLAG_REG))
        /// #### static bool intFlag()
        static force_inline bool intFlag() {
            return TWI_N(INT_FLAG_REG)::getBit(TWI_N(INT_FLAG_BIT));
        }

        /// #### static bool intFlagClear()
        static force_inline void intFlagClear() {
            TWI_N(INT_FLAG_REG)::setBit(TWI_N(INT_FLAG_BIT), true);
        }
    #endif

    #if REG_DEFINED(TWI_N(MASTER_READ_INT_ENABLE_REG))
        /// #### static void masterReadIntEnable(bool e)
        static force_inline void masterReadIntEnable(bool e) {
            TWI_N(MASTER_READ_INT_ENABLE_REG)::setBit(TWI_N(MASTER_READ_INT_ENABLE_BIT), e);
        }
    #endif

    #if REG_DEFINED(TWI_N(MASTER_READ_INT_FLAG_REG))
        /// #### static bool masterReadIntFlag()
        static force_inline bool masterReadIntFlag() {
            return TWI_N(MASTER_READ_INT_FLAG_REG)::getBit(TWI_N(MASTER_READ_INT_FLAG_BIT));
        }

        /// #### static bool masterReadIntFlagClear()
        static force_inline void masterReadIntFlagClear() {
            TWI_N(MASTER_READ_INT_FLAG_REG)::setBit(TWI_N(MASTER_READ_INT_FLAG_BIT), true);
        }
    #endif

    #if REG_DEFINED(TWI_N(MASTER_WRITE_INT_ENABLE_REG))
        /// #### static void masterWriteIntEnable(bool e)
        static force_inline void masterWriteIntEnable(bool e) {
            TWI_N(MASTER_WRITE_INT_ENABLE_REG)::setBit(TWI_N(MASTER_WRITE_INT_ENABLE_BIT), e);
        }
    #endif

    #if REG_DEFINED(TWI_N(MASTER_WRITE_INT_FLAG_REG))
        /// #### static bool masterWriteIntFlag()
        static force_inline bool masterWriteIntFlag() {
            return TWI_N(MASTER_WRITE_INT_FLAG_REG)::getBit(TWI_N(MASTER_WRITE_INT_FLAG_BIT));
        }

        /// #### static bool masterWriteIntFlagClear()
        static force_inline void masterWriteIntFlagClear() {
            TWI_N(MASTER_WRITE_INT_FLAG_REG)::setBit(TWI_N(MASTER_WRITE_INT_FLAG_BIT), true);
        }
    #endif

    #if REG_DEFINED(TWI_N(SLAVE_DATA_INT_ENABLE_REG))
        /// #### static void slaveDataIntEnable(bool e)
        static force_inline void slaveDataIntEnable(bool e) {
            TWI_N(SLAVE_DATA_INT_ENABLE_REG)::setBit(TWI_N(SLAVE_DATA_INT_ENABLE_BIT), e);
        }
    #endif

    #if REG_DEFINED(TWI_N(SLAVE_DATA_INT_FLAG_REG))
        /// #### static bool slaveDataIntFlag()
        static force_inline bool slaveDataIntFlag() {
            return TWI_N(SLAVE_DATA_INT_FLAG_REG)::getBit(TWI_N(SLAVE_DATA_INT_FLAG_BIT));
        }

        /// #### static bool slaveDataIntFlagClear()
        static force_inline void slaveDataIntFlagClear() {
            TWI_N(SLAVE_DATA_INT_FLAG_REG)::setBit(TWI_N(SLAVE_DATA_INT_FLAG_BIT), true);
        }
    #endif

    #if REG_DEFINED(TWI_N(SLAVE_ADDR_INT_ENABLE_REG))
        /// #### static void slaveAddrIntEnable(bool e)
        static force_inline void slaveAddrIntEnable(bool e) {
            TWI_N(SLAVE_ADDR_INT_ENABLE_REG)::setBit(TWI_N(SLAVE_ADDR_INT_ENABLE_BIT), e);
        }
    #endif

    #if REG_DEFINED(TWI_N(SLAVE_ADDR_INT_FLAG_REG))
        /// #### static bool slaveAddrIntFlag()
        static force_inline bool slaveAddrIntFlag() {
            return TWI_N(SLAVE_ADDR_INT_FLAG_REG)::getBit(TWI_N(SLAVE_ADDR_INT_FLAG_BIT));
        }

        /// #### static bool slaveAddrIntFlagClear()
        static force_inline void slaveAddrIntFlagClear() {
            TWI_N(SLAVE_ADDR_INT_FLAG_REG)::setBit(TWI_N(SLAVE_ADDR_INT_FLAG_BIT), true);
        }
    #endif

    #if REG_DEFINED(TWI_N(SLAVE_STOP_INT_ENABLE_REG))
        /// #### static void slaveStopIntEnable(bool e)
        static force_inline void slaveStopIntEnable(bool e) {
            TWI_N(SLAVE_STOP_INT_ENABLE_REG)::setBit(TWI_N(SLAVE_STOP_INT_ENABLE_BIT), e);
        }
    #endif

    #if REG_DEFINED(TWI_N(SLAVE_STOP_INT_FLAG_REG))
        /// #### static bool slaveStopIntFlag()
        static force_inline bool slaveStopIntFlag() {
            return TWI_N(SLAVE_STOP_INT_FLAG_REG)::getBit(TWI_N(SLAVE_STOP_INT_FLAG_BIT));
        }

        /// #### static bool slaveStopIntFlagClear()
        static force_inline void slaveStopIntFlagClear() {
            TWI_N(SLAVE_STOP_INT_FLAG_REG)::setBit(TWI_N(SLAVE_STOP_INT_FLAG_BIT), true);
        }
    #endif

    #if REG_DEFINED(TWI_N(SLAVE_ADDR_OR_STOP_FLAG_REG))
        /// #### static bool slaveAddrOrStopFlag()
        static force_inline bool slaveAddrOrStopFlag() {
            return TWI_N(SLAVE_ADDR_OR_STOP_FLAG_REG)::getBit(TWI_N(SLAVE_ADDR_OR_STOP_FLAG_BIT));
        }
    #endif

    #if REG_DEFINED(TWI_N(WRITE_COLLISION_FLAG_REG))
        /// #### static bool writeCollisionFlag()
        static force_inline bool writeCollisionFlag() {
            return TWI_N(WRITE_COLLISION_FLAG_REG)::getBit(TWI_N(WRITE_COLLISION_FLAG_BIT));
        }
    #endif

    #if REG_DEFINED(TWI_N(STATUS_REG))
        // /// #### static [[TwiN::Status]] status()
        /// #### static uint8_t status()
        static force_inline uint8_t status() {
            return TWI_N(STATUS_REG)::getReg() & TWI_N(STATUS_MASK);
        }
    #endif

    #if REG_DEFINED(TWI_N(PRESCALER_REG))
        /// #### static void prescaler([[TwiN::Prescaler]] p)
        static force_inline void prescaler(Prescaler p) {
            TWI_N(PRESCALER_REG)::setBits(TWI_N(PRESCALER_MASK), p);
        }
    #endif

    #if REG_DEFINED(TWI_N(MASTER_ACK_ACTION_REG))
        /// #### static void masterAckAction([[TwiN::Ack]])
        static force_inline void masterAckAction(Ack a) {
            TWI_N(MASTER_ACK_ACTION_REG)::setBits(TWI_N(MASTER_ACK_ACTION_MASK), bool(a) ? TWI_N(MASTER_ACK_ACTION_ACK_ID) : TWI_N(MASTER_ACK_ACTION_NACK_ID));
        }
    #endif

    #if REG_DEFINED(TWI_N(MASTER_ACK_RECEIVED_REG)) || REG_DEFINED(TWI_N(MASTER_NACK_RECEIVED_REG))
        /// #### static bool masterAckReceived()
        static force_inline bool masterAckReceived() {
            #if REG_DEFINED(TWI_N(MASTER_ACK_RECEIVED_REG))
                return TWI_N(MASTER_ACK_RECEIVED_REG)::getBit(TWI_N(MASTER_ACK_RECEIVED_BIT));
            #else
                return !TWI_N(MASTER_NACK_RECEIVED_REG)::getBit(TWI_N(MASTER_NACK_RECEIVED_BIT));
            #endif
        }
    #endif

    #if REG_DEFINED(TWI_N(MASTER_ARBITRATION_LOST_FLAG_REG))
        /// #### static bool masterArbitrationLostFlag()
        static force_inline bool masterArbitrationLostFlag() {
            return TWI_N(MASTER_ARBITRATION_LOST_FLAG_REG)::getBit(TWI_N(MASTER_ARBITRATION_LOST_FLAG_BIT));
        }

        /// #### static void masterArbitrationLostFlagClear()
        static force_inline void masterArbitrationLostFlagClear() {
            TWI_N(MASTER_ARBITRATION_LOST_FLAG_REG)::setBit(TWI_N(MASTER_ARBITRATION_LOST_FLAG_BIT), true);
        }
    #endif

    #if REG_DEFINED(TWI_N(MASTER_BUS_ERROR_FLAG_REG))
        /// #### static bool masterBusErrorFlag()
        static force_inline bool masterBusErrorFlag() {
            return TWI_N(MASTER_BUS_ERROR_FLAG_REG)::getBit(TWI_N(MASTER_BUS_ERROR_FLAG_BIT));
        }

        /// #### static void masterBusErrorFlagClear()
        static force_inline void masterBusErrorFlagClear() {
            TWI_N(MASTER_BUS_ERROR_FLAG_REG)::setBit(TWI_N(MASTER_BUS_ERROR_FLAG_BIT), true);
        }
    #endif

    #if REG_DEFINED(TWI_N(SLAVE_ACK_ACTION_REG))
        /// #### static void slaveAckAction([[TwiN::Ack]])
        static force_inline void slaveAckAction(Ack a) {
            TWI_N(SLAVE_ACK_ACTION_REG)::setBits(TWI_N(SLAVE_ACK_ACTION_MASK), bool(a) ? TWI_N(SLAVE_ACK_ACTION_ACK_ID) : TWI_N(SLAVE_ACK_ACTION_NACK_ID));
        }
    #endif

    #if REG_DEFINED(TWI_N(MASTER_COMMAND_REG))
        /// #### static void masterCommand([[TwiN::MasterCommand]])
        static force_inline void masterCommand(MasterCommand c) {
            TWI_N(MASTER_COMMAND_REG)::setBits(TWI_N(MASTER_COMMAND_MASK), c);
        }
    #endif

    #if REG_DEFINED(TWI_N(SLAVE_COMMAND_REG))
        /// #### static void slaveCommand([[TwiN::SlaveCommand]])
        static force_inline void slaveCommand(SlaveCommand c) {
            TWI_N(SLAVE_COMMAND_REG)::setBits(TWI_N(SLAVE_COMMAND_MASK), c);
        }
    #endif

    #if REG_DEFINED(TWI_N(BUS_STATE_REG))
        /// #### static void busState([[TwiN::BusState]])
        static force_inline void busState(BusState s) {
            TWI_N(BUS_STATE_REG)::setBits(TWI_N(BUS_STATE_MASK), s);
        }

        /// #### static [[TwiN::BusState]] busState()
        static force_inline BusState busState() {
            return BusState(TWI_N(BUS_STATE_REG)::getBits(TWI_N(BUS_STATE_MASK)));
        }
    #endif

    #if REG_DEFINED(TWI_N(TIMEOUT_REG))
        /// #### static void timeout([[TwiN::Timeout]])
        static force_inline void timeout(Timeout t) {
            TWI_N(TIMEOUT_REG)::setBits(TWI_N(TIMEOUT_MASK), t);
        }
    #endif

    #if REG_DEFINED(TWI_N(DATA_REG))
        /// #### static void data(uint8_t b)
        static force_inline void data(uint8_t b) {
            TWI_N(DATA_REG)::setReg(b);
        }

        /// #### static uint8_t data()
        static force_inline uint8_t data() {
            return TWI_N(DATA_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(TWI_N(MASTER_DATA_REG))
        /// #### static void masterData(uint8_t b)
        static force_inline void masterData(uint8_t b) {
            TWI_N(MASTER_DATA_REG)::setReg(b);
        }

        /// #### static uint8_t masterData()
        static force_inline uint8_t masterData() {
            return TWI_N(MASTER_DATA_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(TWI_N(SLAVE_DATA_REG))
        /// #### static void slaveData(uint8_t b)
        static force_inline void slaveData(uint8_t b) {
            TWI_N(SLAVE_DATA_REG)::setReg(b);
        }

        /// #### static uint8_t slaveData()
        static force_inline uint8_t slaveData() {
            return TWI_N(SLAVE_DATA_REG)::getReg();
        }
    #endif

    #if REG_DEFINED(TWI_N(ADDRESS_REG))
        /// #### static void address(uint8_t b)
        static force_inline void address(uint8_t b) {
            TWI_N(ADDRESS_REG)::setReg(b & TWI_N(ADDRESS_MASK));
        }
    #endif

    #if REG_DEFINED(TWI_N(MASTER_ADDRESS_REG))
        /// #### static void masterAddress(uint8_t)
        static force_inline void masterAddress(uint8_t b) {
            TWI_N(MASTER_ADDRESS_REG)::setReg(b);
        }
    #endif

    #if REG_DEFINED(TWI_N(SLAVE_ADDRESS_REG))
        /// #### static void slaveAddress(uint8_t)
        static force_inline void slaveAddress(uint8_t b) {
            TWI_N(SLAVE_ADDRESS_REG)::setReg(b);
        }
    #endif

    #if REG_DEFINED(TWI_N(ADDRESS_MASK_REG))
        /// #### static void addressMask(uint8_t b)
        static force_inline void addressMask(uint8_t b) {
            TWI_N(ADDRESS_MASK_REG)::setReg(b & TWI_N(ADDRESS_MASK_MASK));
        }
    #endif

    #if REG_DEFINED(TWI_N(GEN_CALL_REC_ENABLE_REG))
        /// #### static void generalCallRecognitionEnable(bool e)
        static force_inline void generalCallRecognitionEnable(bool e) {
            TWI_N(GEN_CALL_REC_ENABLE_REG)::setBit(TWI_N(GEN_CALL_REC_ENABLE_BIT), e);
        }
    #endif

    #if REG_DEFINED(TWI_N(MASTER_SMART_MODE_ENABLE_REG))
        /// #### static void masterSmartModeEnable(bool e)
        static force_inline void masterSmartModeEnable(bool e) {
            TWI_N(MASTER_SMART_MODE_ENABLE_REG)::setBit(TWI_N(MASTER_SMART_MODE_ENABLE_BIT), e);
        }
    #endif

    #if REG_DEFINED(TWI_N(SLAVE_SMART_MODE_ENABLE_REG))
        /// #### static void slaveSmartModeEnable(bool e)
        static force_inline void slaveSmartModeEnable(bool e) {
            TWI_N(SLAVE_SMART_MODE_ENABLE_REG)::setBit(TWI_N(SLAVE_SMART_MODE_ENABLE_BIT), e);
        }
    #endif

    #if REG_DEFINED(TWI_N(ALTERNATE_PINS_ENABLE_REG))
        /// #### static void alternatePinsEnable(bool e)
        static force_inline void alternatePinsEnable(bool e) {
            TWI_N(ALTERNATE_PINS_ENABLE_REG)::setBit(TWI_N(ALTERNATE_PINS_ENABLE_BIT), e);
        }
    #endif
};

#ifdef TEST

TEST(TwiN, getHardwareType) {
    ASSERT_EQ(TwiN::getHardwareType(), HardwareType::twi);
}

#if REG_DEFINED(TWI_N(ENABLE_REG))
    TEST(TwiN, enable) {
        TEST_REG_WRITE(TwiN::enable(true));
        TEST_REG_WRITE(TwiN::enable(false));
    }
#endif

#if REG_DEFINED(TWI_N(ENABLE_ACK_REG))
    TEST(TwiN, enableAck) {
        TEST_REG_WRITE(TwiN::enableAck(true));
        TEST_REG_WRITE(TwiN::enableAck(false));
    }
#endif

#if REG_DEFINED(TWI_N(START_CONDITION_REG))
    TEST(TwiN, startCondition) {
        TEST_REG_WRITE(TwiN::startCondition(true));
        TEST_REG_WRITE(TwiN::startCondition(false));
    }
#endif

#if REG_DEFINED(TWI_N(STOP_CONDITION_REG))
    TEST(TwiN, stopCondition) {
        TEST_REG_WRITE(TwiN::stopCondition(true));
        TEST_REG_WRITE(TwiN::stopCondition(false));
    }
#endif

#if REG_DEFINED(TWI_N(BIT_RATE_REG))
    TEST(TwiN, bitRate) {
        TEST_REG_WRITE(TwiN::bitRate(0x12));
    }
#endif

#if REG_DEFINED(TWI_N(INT_ENABLE_REG))
    TEST(TwiN, intEnable) {
        TEST_REG_WRITE(TwiN::intEnable(true));
        TEST_REG_WRITE(TwiN::intEnable(false));
    }
#endif

#if REG_DEFINED(TWI_N(INT_FLAG_REG))
    TEST(TwiN, intFlag) {
        TEST_REG_READ_WRITE(TwiN::intFlag());
    }

    TEST(TwiN, intFlagClear) {
        TEST_REG_WRITE(TwiN::intFlagClear());
    }
#endif

#if REG_DEFINED(TWI_N(WRITE_COLLISION_FLAG_REG))
    TEST(TwiN, writeCollisionFlag) {
        TEST_REG_READ_WRITE(TwiN::writeCollisionFlag());
    }
#endif

#if REG_DEFINED(TWI_N(STATUS_REG))
    TEST(TwiN, status) {
        TEST_REG_READ_WRITE(TwiN::status());
    }
#endif

#if REG_DEFINED(TWI_N(PRESCALER_REG))
    TEST(TwiN, prescaler) {
        TEST_REG_WRITE(TwiN::prescaler(TwiN::Prescaler::div1));
        TEST_REG_WRITE(TwiN::prescaler(TwiN::Prescaler::div4));
        TEST_REG_WRITE(TwiN::prescaler(TwiN::Prescaler::div16));
        TEST_REG_WRITE(TwiN::prescaler(TwiN::Prescaler::div64));
    }
#endif

#if REG_DEFINED(TWI_N(ADDRESS_REG))
    TEST(TwiN, data) {
        TEST_REG_WRITE(TwiN::data(0x12));
        TEST_REG_READ_WRITE(TwiN::data());
    }
#endif

#if REG_DEFINED(TWI_N(ADDRESS_REG))
    TEST(TwiN, address) {
        TEST_REG_WRITE(TwiN::address(0x12));
    }
#endif

#if REG_DEFINED(TWI_N(ADDRESS_MASK_REG))
    TEST(TwiN, addressMask) {
        TEST_REG_WRITE(TwiN::addressMask(0x12));
    }
#endif

#if REG_DEFINED(TWI_N(GEN_CALL_REC_ENABLE_REG))
    TEST(TwiN, generalCallRecognitionEnable) {
        TEST_REG_WRITE(TwiN::generalCallRecognitionEnable(true));
        TEST_REG_WRITE(TwiN::generalCallRecognitionEnable(false));
    }
#endif

#endif // TEST

} // nblib::hw

//--------------------------------------------------------

    #endif

    #undef N
    #undef TwiN
    #undef TWI_N
    #undef _TWI_N

    #include "twi.hpp"
#else
    #define NBLIB_TWI_HPP
#endif

#endif
