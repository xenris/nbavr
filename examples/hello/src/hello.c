#include "hello.h"

static struct {
    uint16_t count;
    uint32_t delay;
} mData;

static void setup(Task* task, uint32_t millis);
static void loop(Task* task, uint32_t millis);

Task helloTask = {&mData, sizeof(mData), setup, NULL, PRIORITY_MEDIUM, NULL, 0, NULL, 0};

static void setup(Task* task, uint32_t millis) {
    task->function = loop;
}

static void loop(Task* task, uint32_t millis) {
    if(millis >= mData.delay) {
        print(task->outputStreams[0], "hello! (%i)\n", mData.count);
        mData.delay = millis + 1000;
        mData.count++;
    }
}
