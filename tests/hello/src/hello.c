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
    print(stdout, "hello! (", count, ")\n");

    count++;

    delay(&helloTask, MS_TO_TICKS(1000));
}