#ifndef NBAVR_LCD_H
#define NBAVR_LCD_H

#include <nbavr.h>
#include <util/delay.h>

// \r = clear display and return curser to home position.
// \n = move to start of next line.
// \v = move curser to the position defined by the next two bytes.
//  e.g. \v\1\2 = move to start of second line.
// \f = scoll display forward (shift text left)
// \b = scoll display backward (shift text right)

extern Task lcdTask;
extern Stream* lcdout;

#endif
