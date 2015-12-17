#include "task2.h"

static struct {
    uint32_t delay;
    uint8_t count;
} mData;

static void setup(Task* task, uint32_t millis);
static void loop(Task* task, uint32_t millis);

Task task2 = {&mData, sizeof(mData), setup, NULL, PRIORITY_MEDIUM, NULL, 0, NULL, 0};

static void setup(Task* task, uint32_t millis) {
    mData.delay = 4100;

    task->function = loop;
}

static void loop(Task* task, uint32_t millis) {
    if(millis >= mData.delay) {
        streamPush(task->outputStreams[0], mData.count);
        mData.delay = millis + 4100;
        mData.count += 25;
    }
}
