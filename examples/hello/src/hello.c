#include "hello.h"

static void setup(void);
static void loop(void);

Task helloTask = {
    .setup = setup,
    .loop = loop,
};

static uint16_t count;

static void setup(void) {
    count = 0;
}

static void loop(void) {
    print(&stdout, "hello! (%i)\n", count);
    count++;

    delayMillis(1000);
}
