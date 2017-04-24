#ifndef LIGHTSENSOR_HPP
#define LIGHTSENSOR_HPP

#include <nbavr.hpp>

// Sample program to test TWI.
// Reads values from the BH1750 light sensor chip and prints them to serial out.
// Use BH1750 with a 5v to 3.3v converter (e.g. GY-302 has a converter built in).
//  SCL = PinC5
//  SDA = PinC4
//  GND = PinC3
//  VCC = PinC2

class LightSensor : public Task {
    TWI::Result lightSensorOnResult;
    TWI::Result lightSensorContHResResult;
    TWI::Result lightSensorReadResult;
    uint8_t lightSensorValueBuffer[2];

    uint8_t LIGHT_SENSOR_ON_MSG = 0x01;
    uint8_t LIGHT_SENSOR_CONTIN_H_RES_MSG = 0x10;

    TWI::Action lightSensorOnAction = {TWI::Mode::Write, 0x23, 1, &LIGHT_SENSOR_ON_MSG, &lightSensorOnResult, false};
    TWI::Action lightSensorContHiResMode = {TWI::Mode::Write, 0x23, 1, &LIGHT_SENSOR_CONTIN_H_RES_MSG, &lightSensorContHResResult, false};
    TWI::Action lightSensorGetReadingAction = {TWI::Mode::Read, 0x23, 2, lightSensorValueBuffer, &lightSensorReadResult, false};

    Stream<char>& stdout;
    Stream<TWI::Action>& twiout;

public:
    LightSensor(Stream<char>& stdout, Stream<TWI::Action>& twiout)
    : stdout(stdout), twiout(twiout) {
        PinC2::direction(PinC2::Direction::Output);
        PinC3::direction(PinC3::Direction::Output);
        PinC2::value(PinC2::Value::High);
        PinC3::value(PinC3::Value::Low);

        lightSensorOnResult = TWI::Result::None;
        lightSensorContHResResult = TWI::Result::None;
        lightSensorReadResult = TWI::Result::None;

        twiout << lightSensorOnAction;
        twiout << lightSensorContHiResMode;
    }

private:
    void loop(Clock& clock) override {
        if(lightSensorReadResult == TWI::Result::Success) {
            uint16_t t = (lightSensorValueBuffer[0] << 8) | lightSensorValueBuffer[1];
            stdout << t << endl;
        }

        if(lightSensorReadResult != TWI::Result::Busy) {
            twiout << lightSensorGetReadingAction;
        }

        delay(clock, MS_TO_TICKS(200));
    }
};

#endif
