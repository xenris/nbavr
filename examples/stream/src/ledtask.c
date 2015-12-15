#include "ledtask.h"

#define PULSE_LENGTH 50

bool ledTask(void* p, uint32_t millis) {
    LEDData* data = p;

    if(!data->initialised) {
        pinDirection(PinB5, Output);
        data->serial = getInputStream("serial");
        data->initialised = true;
    }

    uint8_t c;

    if(inputStreamPop(data->serial, &c)) {
        data->ledPulseTime = millis + PULSE_LENGTH;
    }

    bool on = !(millis > data->ledPulseTime);
    pinSet(PinB5, on ? High : Low);

    return true;
}
