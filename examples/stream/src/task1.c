#include "task1.h"

static struct {
    uint32_t delay;
    uint16_t count;
} mData;

static void loop(Task* task, uint32_t millis);

Task task1 = {&mData, sizeof(mData), loop, NULL, PRIORITY_MEDIUM, NULL, 0, NULL, 0};

static void loop(Task* task, uint32_t millis) {
    if(millis >= mData.delay) {
        print(task->outputStreams[0], "Task1 running (%i)\n", mData.count);
        mData.delay = millis + 1000;
        mData.count++;
    }

    uint8_t b;

    if(streamPop(task->inputStreams[0], &b)) {
        print(task->outputStreams[0], "Task1 received byte 0x%x\n", b);
    }
}
