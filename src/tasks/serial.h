#ifndef SERIAL_H
#define SERIAL_H

#include <nbavr.h>
#include <util/setbaud.h>

extern Task serialTask;
extern Stream* stdout;
extern Stream* stdin;

void serialFlush();

#endif
