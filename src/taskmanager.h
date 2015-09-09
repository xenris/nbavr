#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <avr/interrupt.h>
#include <util/atomic.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "hardware.h"
#include "stream.h"
#include "task.h"
#include "watchdog.h"

typedef struct TaskManager TaskManager;

TaskManager* taskManagerInit(uint8_t maxTasks);
bool taskManagerAddTask(TaskManager* taskManager, TaskFunction taskFunction, uint16_t dataSize, const char* id, TaskPriority priority);
bool taskManagerAddStream(TaskManager* taskManager, const char* fromId, const char* toId, const char* streamId, uint8_t bufferSize);
OutputStream* getOutputStream(const char* streamId);
InputStream* getInputStream(const char* streamId);
OutputStream** getOutputStreams();
InputStream** getInputStreams();
void taskManagerRun(TaskManager* taskManager);

#endif
