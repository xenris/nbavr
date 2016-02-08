#include "main.h"

int main(void) {
    Task* tasks[] = {&lightSensorTask, &twiTask, &serialTask, NULL};

    nbavr(tasks);

    return 0;
}
