#!/bin/sh

rm -rf docs/

srcfiles=$(find . -not -path '*/.*' -type f -name '*.hpp')

for srcfile in $srcfiles
do
    mdfile=${srcfile##./}
    mdfile="docs/${mdfile}.md"

    mkdir -p $(dirname $mdfile)

    cat $srcfile | sed -e '/^ *\/\/\/ /! s:.*::' -e 's:^ */// ::' | cat -s | sed -e :a -e '/./,$!d;/^\n*$/{$d;N;};/\n$/ba' > $mdfile
    # cat $srcfile | grep -o '^ *///.*' | sed 's: *///\( \|\)::' > $mdfile
done

find docs/ -empty -delete

docCount=$(find docs/ -type f | wc -l)

echo "${docCount} pages generated"
