#include "lightsensor.h"

static struct {
    uint32_t delay;
    Stream* serialOut;
    Stream* twiOut;
    TWIResult lightSensorOnResult;
    TWIResult lightSensorContHResResult;
    TWIResult lightSensorReadResult;
    uint8_t lightSensorValueBuffer[2];
} mData;

static void setup(Task* task);
static void loop(Task* task);

static uint8_t LIGHT_SENSOR_ON_MSG = 0x01;
static uint8_t LIGHT_SENSOR_CONTIN_H_RES_MSG = 0x10;

static TWIAction lightSensorOnAction = {TWI_WRITE, 0x23, 1, &LIGHT_SENSOR_ON_MSG, &mData.lightSensorOnResult, false};
static TWIAction lightSensorContHiResMode = {TWI_WRITE, 0x23, 1, &LIGHT_SENSOR_CONTIN_H_RES_MSG, &mData.lightSensorContHResResult, false};
static TWIAction lightSensorGetReadingAction = {TWI_READ, 0x23, 2, mData.lightSensorValueBuffer, &mData.lightSensorReadResult, false};

Task lightSensorTask = {
    .data = &mData,
    .dataSize = sizeof(mData),
    .setup = setup,
    .loop = loop,
};

static void setup(Task* task) {
    pinDirection(PinC2, Output);
    pinDirection(PinC3, Output);
    pinSet(PinC2, High);
    pinSet(PinC3, Low);

    mData.delay = 0;
    mData.serialOut = task->outputStreams[0];
    mData.twiOut = task->outputStreams[1];

    mData.lightSensorOnResult = TWI_NONE;
    mData.lightSensorContHResResult = TWI_NONE;
    mData.lightSensorReadResult = TWI_NONE;

    twiDo(mData.twiOut, &lightSensorOnAction);
    twiDo(mData.twiOut, &lightSensorContHiResMode);
}

static void loop(Task* task) {
    uint32_t millis = clockMillis();

    if(millis >= mData.delay) {
        if(mData.lightSensorReadResult == TWI_SUCCESS) {
            uint16_t t = (mData.lightSensorValueBuffer[0] << 8) | mData.lightSensorValueBuffer[1];
            print(mData.serialOut, "%u\n", t);
        }

        if(mData.lightSensorReadResult != TWI_BUSY) {
            twiDo(mData.twiOut, &lightSensorGetReadingAction);
        }

        mData.delay = millis + 200;
    }
}
