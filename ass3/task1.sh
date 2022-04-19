#!/bin/bash
#Shell Script to create an array of size N
#And search the array for a particular item
#Input taken through command line argument
#SUSHANT SINHA
#1901CS62

# Storing all input in "array"
i=0
while [ $i -lt $1 ]
do
    temp=$(( $i + 2 ))
    array[$i]=${!temp}
    i=$(( $i + 1 ))
done

idx=-1
searchitem=${!#}

# Searhing through the array to find an element, and store the index in array if found
for i in ${!array[@]}
do

    if [ ${array[$i]} -eq $searchitem ]
    then
        idx=$i
    fi
done

# Output
if [ $idx -ne -1 ]
then
    echo "Search found along with its index: $idx, of searched item: $searchitem"
else
    echo "Error: No match found."
fi