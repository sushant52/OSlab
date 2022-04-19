#!/bin/bash
#Shell Script to validate passwpord strength
#Input taken through command line argument
#SUSHANT SINHA
#1901CS62

# Function to check the presence of a character in string from a specified set of characters
password_check () {
    criteria=$1
    password=$2
    
    # Loop over every character in checking set and search for its presence in given password
    for (( i=0; i<${#criteria}; i++ ))
    do
        for (( j=0; j<${#password}; j++ ))
        do
            if [ ${criteria:i:1} == ${password:j:1} ]
            then
                check=$(( $check + 1 ))
                return
            fi
        done
    done
    return
}

if [ $# -ne 1 ]
then
    echo "Required number of inputs is one"
else
    # Three different character set checks for various conditions
    alphabet_check="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
    number_check="0123456789"
    special_check="/()<>?"
    
    # Function calls for different checks
    check=0
    password_check $alphabet_check $1
    password_check $number_check $1
    password_check $special_check $1
    
    # If length of input is >= 7 and all checks have satisfied, then valid password
    if [ ${#1} -ge 7 ] && [ $check -eq 3 ]
    then
        echo "VALID PASSWORD"
    else
        echo "INVALID PASSWORD"
    fi
fi