#include "hello.h"

static void setup(Task* task);
static void loop(Task* task);

Task helloTask = {
    .setup = setup,
    .loop = loop,
};

static uint16_t count;


static void setup(Task* task) {
    count = 0;
}

static void loop(Task* task) {
    print(&stdout, "hello! (%i)\n", count);
    count++;

    delayMillis(1000);
}
