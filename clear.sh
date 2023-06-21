#!/bin/bash

# Clear the .bin and .out files



dir=`ls -d */`

echo $dir

nowpath=`pwd`

arr=($dir)
queue=()

for i in "${arr[@]}" ; do
    queue+=("$nowpath/$i")
done

while [ ${#queue[@]} -ge 1 ] ; do
    echo "${queue[0]}"
    cd "${queue[0]}"
    nowpath=`pwd`
    rm *.bin
    rm *.out
    arr=(`ls -d */ | awk -F '/' '{for (i = 1; i <= NF; i++) printf("%s ", $i)}'`)
    echo `ls -d */ | awk -F '/' '{for (i = 1; i <= NF; i++) printf("%s ", $i)}'`
    for i in "${arr[@]}" ; do
        queue+=("$nowpath/$i")
    done
    queue=(${queue[@]:1})
done


