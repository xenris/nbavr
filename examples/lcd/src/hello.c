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
    uint16_t seconds = TICKS_TO_MS(getTicks()) / 1000;

    printchar(lcdout, '\r');
    printstr(lcdout, msg1);
    printstr(lcdout, " (");
    printi16(lcdout, seconds, PrintUDec);
    printstr(lcdout, ")\n");
    printstr(lcdout, msg2 + scroll);

    scroll++;

    if(scroll >= sizeof(msg2)) {
        scroll = 0;
    }

    delay(&helloTask, MS_TO_TICKS(500));
}
