#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H

#include <nbavr.h>
#include <tasks/serial.h>
#include <tasks/twi.h>

// Sample program to test TWI.
// Reads values from the BH1750 light sensor chip and prints them to serial out.
// Use BH1750 with a 5v to 3.3v converter (e.g. GY-302 has a converter built in).
//  SCL = PinC5
//  SDA = PinC4
//  GND = PinC3
//  VCC = PinC2

extern Task lightSensorTask;

#endif
