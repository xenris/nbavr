#include "lightsensor.h"

static void setup(void);
static void loop(void);

static TWIResult lightSensorOnResult;
static TWIResult lightSensorContHResResult;
static TWIResult lightSensorReadResult;
static uint8_t lightSensorValueBuffer[2];

static uint8_t LIGHT_SENSOR_ON_MSG = 0x01;
static uint8_t LIGHT_SENSOR_CONTIN_H_RES_MSG = 0x10;

static TWIAction lightSensorOnAction = {TWI_WRITE, 0x23, 1, &LIGHT_SENSOR_ON_MSG, &lightSensorOnResult, false};
static TWIAction lightSensorContHiResMode = {TWI_WRITE, 0x23, 1, &LIGHT_SENSOR_CONTIN_H_RES_MSG, &lightSensorContHResResult, false};
static TWIAction lightSensorGetReadingAction = {TWI_READ, 0x23, 2, lightSensorValueBuffer, &lightSensorReadResult, false};

Task lightSensorTask = {
    .setup = setup,
    .loop = loop,
};

static void setup(void) {
    pinDirection(PinC2, Output);
    pinDirection(PinC3, Output);
    pinSet(PinC2, High);
    pinSet(PinC3, Low);

    lightSensorOnResult = TWI_NONE;
    lightSensorContHResResult = TWI_NONE;
    lightSensorReadResult = TWI_NONE;

    twiDo(&lightSensorOnAction);
    twiDo(&lightSensorContHiResMode);
}

static void loop(void) {
    if(lightSensorReadResult == TWI_SUCCESS) {
        uint16_t t = (lightSensorValueBuffer[0] << 8) | lightSensorValueBuffer[1];
        print(stdout, t, (char)'\n');
    }

    if(lightSensorReadResult != TWI_BUSY) {
        twiDo(&lightSensorGetReadingAction);
    }

    delay(&lightSensorTask, MS_TO_TICKS(200));
}
