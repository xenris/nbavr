#include "watchdog.h"

bool handleWatchdogReset() {
    wdt_reset();
    wdt_enable(WDTO_250MS);

    bool watchdogReset = watchdogResetFlag();

    clearWatchdogResetFlag();

    return watchdogReset;
}
