#ifndef SERIAL_H
#define SERIAL_H

#include "hardware.h"
#include "ringbuffer.h"
#include "taskmanager.h"

const char* serialInit(TaskManager* taskManager);

#endif
