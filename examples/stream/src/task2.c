#include "task2.h"

extern Stream task1Stream;

static void setup(Task* task);
static void loop(Task* task);

Task task2 = {
    .setup = setup,
    .loop = loop,
};

static uint8_t count;

static void setup(Task* task) {
    count = 0;
    delayMillis(4100);
}

static void loop(Task* task) {
    streamPush(&task1Stream, count);
    count += 25;

    delayMillis(4100);
}
