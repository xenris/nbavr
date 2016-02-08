#include "watchdog.h"

ISR(WDT_vect) {
    if(state.currentTask != NULL) {
        // TODO Set task state to "crashed" here.
        longjmp(state.haltJmp, 1);
    }
}
