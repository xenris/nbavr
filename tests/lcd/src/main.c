#include "main.h"

void main(void) {
    LCDConfig lcdConfig = {
        .d4 = PinC4,
        .d5 = PinC5,
        .d6 = PinD6,
        .d7 = PinD7,
        .rw = PinD5,
        .rs = PinD4,
        .e = PinB1,
    };

    Task* tasks[] = {&helloTask, &ledTask, lcdTask(lcdConfig), NULL};

    nbavr(tasks);
}
