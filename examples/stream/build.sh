#!/bin/sh

mmcu=atmega328p
freq=16000000
programmer=stk500v2 #use "arduino" to upload to an Arduino device.

set -e

if [ ! -d ".tup" ]; then
    tup init
fi

tup

avr-size gen/firmware.elf -C --mcu=atmega328p

if [ "${1}" = "-u" ]; then
    avrdude -p m328p -P /dev/ttyACM0 -c $programmer -e -U flash:w:gen/firmware.hex
fi

if [ "${1}" == "-d" ]; then
    hash avr-gdb 2>/dev/null || { echo >&2 "avr-gdb is needed for debugging but it's not installed."; exit 1; }
    hash simavr 2>/dev/null || { echo >&2 "simavr is needed for debugging but it's not installed."; exit 1; }
    hash kdbg 2>/dev/null || { echo >&2 "kdbg is needed for debugging but it's not installed."; exit 1; }

    simavr -g -v -v -t -m $mmcu -f $freq gen/firmware.elf &
    kdbg -r localhost:1234 gen/firmware.elf

    pkill simavr
fi
