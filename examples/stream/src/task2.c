#include "task2.h"

extern Stream task1Stream;

static struct {
    uint8_t count;
} mData;

static void setup(Task* task);
static void loop(Task* task);

Task task2 = {
    .data = &mData,
    .dataSize = sizeof(mData),
    .setup = setup,
    .loop = loop,
};

static void setup(Task* task) {
    delayMillis(4100);
}

static void loop(Task* task) {
    streamPush(&task1Stream, mData.count);
    mData.count += 25;

    delayMillis(4100);
}
