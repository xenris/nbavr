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
#include "timing.h"
#include "stream.h"
#include "task.h"

void taskManagerRun(Task** tasks);

#endif
