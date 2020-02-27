#!/bin/sh

# Run all tests:
# ./runtests.sh
# Run some tests:
# ./runtests.sh attiny85 atmega2560
# List all tests:
# ./runtests.sh -l
# Run all but some tests: TODO
# ./runtests.sh -n attiny85 atmega2560
# Debug tests: TODO
# ./runtests.sh -d attiny85 atmega2560
# Update test records:
# ./runtests.sh -u attiny85 atmega2560

cd test/

source ./ignore

cflags="-Werror -Wall -fmax-errors=3 -std=c++17 -g"
includes="-I ../src/"
libs="-lgtest"

update=0
showChips=0

if [ "$1" == "-u" ] ; then
    declare -a args=("${@:2}")
    update=1
elif [ "$1" == "-l" ] ; then
    showChips=1
else
    declare -a args=("${@}")
fi

if [ ${#args[@]} -eq 0 ] ; then
    declare -a chips=($(basename -a -s .hpp $(find ../src/hardware/chips/ -name '*.hpp')))
else
    declare -a chips=("$args")
fi

if [ "$showChips" -eq 1 ] ; then
    for chip in "${chips[@]}" ; do
        if [[ "${ignoreList[@]}" =~ "$chip" ]]; then
            continue
        fi

        echo "$chip"
    done

    exit 0
fi

for chip in "${chips[@]}" ; do
    if [[ "${ignoreList[@]}" =~ "$chip" ]]; then
        continue
    fi

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
