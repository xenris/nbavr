#ifndef NBAVR_H
#define NBAVR_H

#include <config.h>
#include <setjmp.h>
#include "hardware.h"
#include "print.h"
#include "stream.h"
#include "task.h"
#include "timing.h"
#include "uno.h"

void nbavr(Task** tasks) __attribute__((noreturn));
void yield(void) __attribute__((noreturn));
void halt(void) __attribute__((noreturn));
void delay(Task* task, uint32_t ticks);
void sleep(Task* task);
void wake(Task* task);

#endif
