#!/bin/sh
#Shell Script to print all numbers between two numbers
#Input taken through command line argument
#SUSHANT SINHA
#1901CS62

if [ $# -ne 2 ]
then
    echo "ERROR: Two command line arguments needed."
elif [ $1 -gt $2 ]
then
    echo "ERROR: First number must not be greater than second number."
elif [ $1 -eq $2 ]
then
    echo $1
else
    temp=$1
    while [ $temp -le $2 ]
    do
        echo -n "$temp "
        temp=$(( $temp + 1 ))
    done
    echo ""
fi