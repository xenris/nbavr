#ifndef SERIAL_H
#define SERIAL_H

#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/atomic.h>

#include "../config.h"
#include "ringbuffer.h"

void serialInit();
bool serialSendByte(uint8_t b);
bool serialReceiveByte(uint8_t* b);

#endif
