#!/bin/sh

set -e

if [ ! -d ".tup" ]; then
    tup init
fi

tup

avr-size gen/firmware.elf -C --mcu=atmega328p

if [ "${1}" = "-u" ]; then
    avrdude -p m328p -P /dev/ttyACM0 -c stk500v2 -e -U flash:w:gen/firmware.hex
fi

