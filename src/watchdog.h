#ifndef WATCHDOG_H
#define WATCHDOG_H

#include <stdbool.h>
#include <avr/wdt.h>
#include "hardware.h"

bool handleWatchdogReset();

#endif
