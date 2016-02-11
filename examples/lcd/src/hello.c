#include "hello.h"

static void setup(void);
static void loop(void);

Task helloTask = {
    .setup = setup,
    .loop = loop,
};

static uint8_t scroll;
static const char msg1[] = "Hello!";
static const char msg2[] = "                Welcome to nbavr";

static void setup(void) {
    scroll = 0;
}

static void loop(void) {
    uint16_t seconds = getMillis() / 1000;

    print(lcdout, "\r%s (%u)\n%s", msg1, seconds, msg2 + scroll);

    scroll++;

    if(scroll >= sizeof(msg2)) {
        scroll = 0;
    }

    delayMillis(500);
}
