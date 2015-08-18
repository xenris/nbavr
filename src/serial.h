#ifndef SERIAL_H
#define SERIAL_H

#include <avr/io.h>

#include "../config.h"
#include "ringbuffer.h"
#include "taskmanager.h"

const char* serialInit(TaskManager* taskManager);

#endif
