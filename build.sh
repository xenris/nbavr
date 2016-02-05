#!/bin/sh

# "build.sh" to build the library and its examples.
# "build.sh -u hello" to also upload the example "hello".

mcu=m328p
mmcu=atmega328p
freq=16000000
port=/dev/ttyACM0
programmer=stk500v2

set -e

if [ ! -d ".tup" ]; then
    tup init
fi

tup

if [ "${1}" == "-u" ]; then
    exampledir="examples/${2}"

    if [ -d $exampledir ] && [ "${2}" != "" ]; then
        hexfile="$exampledir/gen/firmware.hex"

        avrdude -p $mcu -P $port -c $programmer -e -U flash:w:$hexfile
    else
        echo "Example ${2} not found"
        echo "Try one of:"
        for e in examples/*/ ; do
            basename $e
        done
    fi
fi

if [ "${1}" == "-d" ]; then
    hash avr-gdb 2>/dev/null || { echo >&2 "avr-gdb is needed for debugging but it's not installed."; exit 1; }
    hash simavr 2>/dev/null || { echo >&2 "simavr is needed for debugging but it's not installed."; exit 1; }
    hash ddd 2>/dev/null || { echo >&2 "ddd is needed for debugging but it's not installed."; exit 1; }

    exampledir="examples/${2}"

    if [ -d $exampledir ] && [ "${2}" != "" ]; then
        cd $exampledir

        simavr -g -v -v -t -m $mmcu -f $freq gen/firmware.elf &
        ddd --debugger "avr-gdb" --eval-command="file gen/firmware.elf" --eval-command="target remote localhost:1234"

        pkill simavr
    else
        echo "Example ${2} not found"
        echo "Try one of:"
        for e in examples/*/ ; do
            basename $e
        done
    fi
fi
