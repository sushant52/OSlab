#!/bin/sh
#Shell Script to rename all the files which match a filename pattern
#Matching here is case sensitive
#Input taken through command line argument
#SUSHANT SINHA
#1901CS62

if [ $# -ne 3 ]
then
    echo "ERROR: Need three arguments."
else
    DIRECTORY=$1
    PATTERN=$2
    NEWNAME=$3
    COUNT=0

    MATCHES=$(find $DIRECTORY -name "*${PATTERN}*" -type f)
    for FILE_NAME in $MATCHES
    do
        COUNT=$(( $COUNT + 1 ))
        EXT="${FILE_NAME##*.}"
        NEW_FILE_NAME="${NEWNAME}_${COUNT}.${EXT}"
        $(mv ${FILE_NAME} ${NEW_FILE_NAME})
    done
    echo "Total $COUNT files renamed."
fi