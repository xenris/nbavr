#include "watchdog.h"

ISR(WDT_vect) {
    if(kernel.currentTask != NULL) {
        // TODO Set task state to "crashed" here.
        longjmp(kernel.haltJmp, 1);
    }
}
