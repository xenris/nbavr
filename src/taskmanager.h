#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <avr/eeprom.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include <util/atomic.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

typedef enum {
    PRIORITY_HIGH = 1,
    PRIORITY_MEDIUM = 10,
    PRIORITY_LOW = 20,
} TaskPriority;

typedef bool (*TaskFunction)(void*, uint32_t);
typedef struct TaskManager TaskManager;

TaskManager* taskManagerInit(uint8_t maxTasks);
bool taskManagerAddTask(TaskManager* taskManager, TaskFunction taskFunction, void* data, const char* id, TaskPriority priority);
void taskManagerRun(TaskManager* taskManager);

#endif
