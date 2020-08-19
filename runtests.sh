#!/bin/bash

microcontrollers="
    atmega2560
    atmega328p
    atmega328pb
    atmega8
    attiny85
    attiny402
"
    # stm32f103c8_md

CFLAGS="-std=c++20 -Werror -Wall -ferror-limit=3 -fdiagnostics-color=always -lgtest"

set -e

cd test/

rm -f test_*

if [[ $# -eq 0 ]]; then
    list=$microcontrollers
else
    list=$*
fi

parallel --tag clang++ -I../src/ $CFLAGS -D__{}__ test.cpp -o test_{} ::: $list

declare -a tests=($(find -name 'test_*'))

set +e

for test in "${tests[@]}" ; do
    chip=$test

    echo "############ $chip ############"

    $test

    if [ "$?" -eq 0 ] ; then
        echo -e "\e[32m^^^^^^^^^^^^ $chip ^^^^^^^^^^^^\e[0m"
    else
        echo -e "\e[31m^^^^^^^^^^^^ $chip ^^^^^^^^^^^^\e[0m"

        exit -1
    fi
done

echo -e "\e[32mAll tests passed\e[0m"
