#!/bin/bash
#Shell Script to print command line argument number in reverse order
#Input taken through command line argument
#SUSHANT SINHA
#1901CS62

if [ $# -eq 0 ]
then
    echo "ERROR: No argument provided."
elif [ $# -gt 1 ]
then
    echo "ERROR: Too many arguments provided."
else
    temp=0
    arg=$1
    arg=$(( 10#$arg ))
    while [ $arg -ne 0 ]
    do
        temp=$(( $temp * 10 + $arg % 10 ))
        arg=$(( $arg / 10 ))
    done

    echo "Reversed Number is : $temp"
fi
