#include "yield.h"

void yield(void) {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        if(kernel.currentTask != NULL) {
            longjmp(kernel.haltJmp, 2);
        }
    }
}
