#include "main.h"

int main(void) {
    Task* tasks[] = {&helloTask, &ledTask, &lcdTask, NULL};

    nbavr(tasks);

    return 0;
}
