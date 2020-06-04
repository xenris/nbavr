#!/bin/sh

tup

if [ "$?" -ne 0 ] ; then
    exit -1
fi

cd test/

declare -a tests=($(find -name 'test_*'))

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
