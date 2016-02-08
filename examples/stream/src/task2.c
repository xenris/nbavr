#include "task2.h"

extern Stream task1Stream;

static void setup(void);
static void loop(void);

Task task2 = {
    .setup = setup,
    .loop = loop,
};

static uint8_t count;

static void setup(void) {
    count = 0;
    delayMillis(4100);
}

static void loop(void) {
    streamPush(&task1Stream, count);
    count += 25;

    delayMillis(4100);
}
