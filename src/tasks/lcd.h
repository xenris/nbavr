#ifndef NBAVR_LCD_H
#define NBAVR_LCD_H

#include <nbavr.h>
// FIXME Shouldn't really be using these blocking calls...?
#include <util/delay.h>

// \r = clear display and return curser to home position.
// \n = move to start of next line, wrapping to first line.
// \v = move curser to the position defined by the next two bytes.
//  e.g. \v\1\2 = move to start of second line.
// \a = clear current line and put curser at start.

#define LCD_STREAM_SIZE 30

typedef struct {
    Pin d4;
    Pin d5;
    Pin d6;
    Pin d7;
    Pin rw;
    Pin rs;
    Pin e;
} LCDConfig;

extern Stream* lcdout;

Task* lcdTask(LCDConfig config);

#endif
