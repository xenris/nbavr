#!/bin/sh

# Run all tests:
# ./runtests.sh
# Run some tests:
# ./runtests.sh attiny85 atmega2560
# Run all but some tests: TODO
# ./runtests.sh -n attiny85 atmega2560
# Debug tests: TODO
# ./runtests.sh -d attiny85 atmega2560
# Update test records:
# ./runtests.sh -u attiny85 atmega2560

cd test/

cflags="-Werror -Wall -fmax-errors=3 -std=c++17 -g"
includes="-I ../src/"
libs="-lgtest"

if [ "$1" == "-u" ] ; then
    declare -a args=("${@:2}")
    update=1
else
    declare -a args=("${@}")
    update=0
fi

if [ ${#args[@]} -eq 0 ] ; then
    declare -a chips=($(basename -a -s .hpp $(find ../src/hardware/chips/ -name '*.hpp')))
else
    declare -a chips=("$args")
fi

for chip in "${chips[@]}" ; do
    echo "############ $chip ############"

    g++ $includes $cflags $libs "-D__${chip}__" "-DRECORD_ID=\"${chip}\"" "test.cpp" -o test_exe

    error=$?

    if [ "$error" -eq 0 ] ; then
        if [ "$update" -eq 0 ] ; then
            ./test_exe
        else
            ./test_exe -u
        fi

        error=$?

        rm -f test_exe
    fi

    if [ "$error" -eq 0 ] ; then
        echo -e "\e[32m^^^^^^^^^^^^ $chip ^^^^^^^^^^^^\e[0m"
    else
        echo -e "\e[31m^^^^^^^^^^^^ $chip ^^^^^^^^^^^^\e[0m"

        exit -1
    fi
done
