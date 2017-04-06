#!/bin/sh

# "build.sh" to build the library and its tests.
# "build.sh -u hello" to also upload the test "hello".

set -e

source ./build.config

tup

testdir="tests/${2}"

if [ "${1}" == "-u" ]; then
    if [ -d $testdir ] && [ "${2}" != "" ]; then
        elf="$testdir/gen/firmware.elf"

        avr-size $elf -C --mcu=$mcu

        pkill picocom && sleep 1 || true

        avrdude -p $mcu -P $port -c $programmer -e -U flash:w:$elf
    else
        echo "Example ${2} not found"
        echo "Try one of:"
        for e in tests/*/ ; do
            basename $e
        done
    fi
elif [ "${1}" == "-d" ]; then
    hash avr-gdb 2>/dev/null || { echo >&2 "avr-gdb is needed for debugging but it's not installed."; exit 1; }
    hash simavr 2>/dev/null || { echo >&2 "simavr is needed for debugging but it's not installed."; exit 1; }
    hash kdbg 2>/dev/null || { echo >&2 "kdbg is needed for debugging but it's not installed."; exit 1; }

    if [ -d $testdir ] && [ "${2}" != "" ]; then
        cd $testdir

        elf="gen/firmware.elf"

        simavr -g -v -v -t -m $mcu -f $freq $elf &
        kdbg -r localhost:1234 $elf

        pkill simavr
    else
        echo "Example ${2} not found"
        echo "Try one of:"
        for e in examples/*/ ; do
            basename $e
        done
    fi
fi
