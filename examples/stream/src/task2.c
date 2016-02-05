#include "task2.h"

extern Stream task1Stream;

static struct {
    uint32_t delay;
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
    mData.delay = 4100;
}

static void loop(Task* task) {
    uint32_t millis = clockMillis();

    if(millis >= mData.delay) {
        streamPush(&task1Stream, mData.count);
        mData.delay = millis + 4100;
        mData.count += 25;
    }
}
