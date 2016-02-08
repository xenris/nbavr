#include "hello.h"

static struct {
    uint16_t count;
} mData;

static void loop(Task* task);

Task helloTask = {
    .data = &mData,
    .dataSize = sizeof(mData),
    .loop = loop,
};

static void loop(Task* task) {
    print(&stdout, "hello! (%i)\n", mData.count);
    mData.count++;

    delayMillis(1000);
}
