#!/bin/sh
#Shell Script to count number of lines in a file and delete the file if not enough lines
#Input taken through command line argument
#SUSHANT SINHA
#1901CS62

if [ $# -ne 2 ]
then
    echo "ERROR: Need two arguments."
else
    FILE=$1
    LINE_LIMIT=$2
    LINE_COUNT=0

    while read -r line || [ -n "$line" ]
    do
        LINE_COUNT=$(( $LINE_COUNT + 1 ))
    done < "$FILE"

    echo "Total lines in file: $LINE_COUNT"

    if [ $LINE_COUNT -lt $LINE_LIMIT ]
    then
        rm -f $FILE
        echo "File Deleted."
    fi
fi