#ifndef SERIAL_H
#define SERIAL_H

#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/atomic.h>
#include <stdio.h>

#include "../config.h"
#include "ringbuffer.h"

void serialInit();
void serialStdioInit();
bool serialSendByte(uint8_t b);
bool serialReceiveByte(uint8_t* b);

#endif
