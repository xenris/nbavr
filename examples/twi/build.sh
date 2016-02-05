#!/bin/sh

mmcu=atmega328p
freq=16000000

set -e

if [ ! -d ".tup" ]; then
    tup init
fi

tup

avr-size gen/firmware.elf -C --mcu=atmega328p

if [ "${1}" = "-u" ]; then
    avrdude -p m328p -P /dev/ttyACM0 -c stk500v2 -e -U flash:w:gen/firmware.hex
fi

if [ "${1}" == "-d" ]; then
    hash avr-gdb 2>/dev/null || { echo >&2 "avr-gdb is needed for debugging but it's not installed."; exit 1; }
    hash simavr 2>/dev/null || { echo >&2 "simavr is needed for debugging but it's not installed."; exit 1; }
    hash ddd 2>/dev/null || { echo >&2 "ddd is needed for debugging but it's not installed."; exit 1; }

    simavr -g -v -v -t -m $mmcu -f $freq gen/firmware.elf &
    ddd --debugger "avr-gdb" --eval-command="file gen/firmware.elf" --eval-command="target remote localhost:1234"

    pkill simavr
fi
