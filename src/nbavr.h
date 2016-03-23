#ifndef NBAVR_H
#define NBAVR_H

#include "hardware.h"
#include "kernel.h"
#include "lcd.h"
#include "print.h"
#include "servo.h"
#include "scheduler.h"
#include "serial.h"
#include "stream.h"
#include "task.h"
#include "timing.h"
#include "twi.h"
#include "yield.h"
#include "hardware/uno.h"

void nbavr(Task** tasks);

#endif
