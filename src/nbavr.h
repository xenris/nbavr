#ifndef NBAVR_H
#define NBAVR_H

#include <string.h>

#include "hardware.h"
#include "print.h"
#include "scheduler.h"
#include "serial.h"
#include "state.h"
#include "stream.h"
#include "task.h"
#include "timing.h"
#include "twi.h"
#include "yield.h"

void nbavr(Task** tasks);

#endif
