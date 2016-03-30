#!/bin/sh

set -e

source ./build.config

tup

avr-size gen/firmware.elf -C --mcu=$mmcu

if [ "${1}" = "-u" ]; then
    avrdude -p $mcu -P $port -c $programmer -e -U flash:w:gen/firmware.hex
fi
