#include "main.h"

void main(void) {
    Task* tasks[] = {&helloTask, &ledTask, &lcdTask, NULL};

    nbavr(tasks);
}
