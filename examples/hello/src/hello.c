#include "hello.h"

static struct {
    uint16_t count;
    uint32_t delay;
} mData;

static void loop(Task* task, uint32_t millis);

Task helloTask = {
    .data = &mData,
    .dataSize = sizeof(mData),
    .loop = loop,
};

static void loop(Task* task, uint32_t millis) {
    if(millis >= mData.delay) {
        print(task->outputStreams[0], "hello! (%i)\n", mData.count);
        mData.delay = millis + 1000;
        mData.count++;
    }
}
