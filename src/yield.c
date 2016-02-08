#include "yield.h"

void yield(void) {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        if(state.currentTask != NULL) {
            longjmp(state.haltJmp, 2);
        }
    }
}
