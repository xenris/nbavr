#include "ledtask.h"

#define PULSE_LENGTH 50

static void setLED(bool on);

bool ledTask(void* p, uint32_t millis) {
    LEDData* data = p;

    if(!data->initialised) {
        DDRB |= _BV(5);
        data->serial = getInputStream("serial");
        data->initialised = true;
    }

    uint8_t c;

    if(inputStreamPop(data->serial, &c)) {
        data->ledPulseTime = millis + PULSE_LENGTH;
    }

    setLED(!(millis > data->ledPulseTime));

    return true;
}

static void setLED(bool on) {
    if(on) {
        PORTB |= _BV(5);
    } else {
        PORTB &= (uint8_t)~_BV(5);
    }
}
