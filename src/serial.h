#ifndef SERIAL_H
#define SERIAL_H

#include <avr/io.h>
#include <stdio.h>

#include "../config.h"
#include "ringbuffer.h"
#include "taskmanager.h"

void serialInit(TaskManager* taskManager);
void serialStdioInit();
bool serialSendByte(uint8_t b);
bool serialReceiveByte(uint8_t* b);

#endif
