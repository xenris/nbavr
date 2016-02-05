#include "hello.h"

static struct {
    uint16_t count;
    uint32_t delay;
} mData;

static void loop(Task* task);

Task helloTask = {
    .data = &mData,
    .dataSize = sizeof(mData),
    .loop = loop,
};

static void loop(Task* task) {
    uint32_t millis = clockMillis();

    if(millis >= mData.delay) {
        print(&stdout, "hello! (%i)\n", mData.count);
        mData.delay = millis + 1000;
        mData.count++;
    }
}
