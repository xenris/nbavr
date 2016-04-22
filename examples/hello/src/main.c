#include "main.h"

void main(void) {
    Task* tasks[] = {&helloTask, &ledTask, &serialTask, NULL};

    nbavr(tasks);
}
