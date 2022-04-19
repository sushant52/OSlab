#!/bin/bash
#Shell Script to create recursive functions
#Calculate factorial and sum of primes upto N
#Input taken through command line argument
#SUSHANT SINHA
#1901CS62

# Recursive Function to calculate factorial of a number using Fact(n)=n*Fact(n-1)
factorial () {
    if [ $1 -lt 2 ]
    then
        echo 1  # Base Case
    else
        echo $(( $1 * $(factorial $(( $1 - 1 ))) ))  # Recursive statement
    fi

    return
}

# Recursive function to find sum of all prime numbers upto n
sum_of_primes () {
    if [ $1 -lt 2 ] # Base case
    then
        echo 0
    else
        i=$(($1 - 1))
        while [ $i -gt 1 ]
        do
            if [ $(( $1 % $i )) -eq 0 ] # Trying to divide given number by all numbers from 2 to n-1
            then
                echo $( sum_of_primes $(($1 - 1)) )
                return
            fi
            i=$(($i - 1))
        done

        echo $(( $1 + $( sum_of_primes $(($1 - 1)) ) )) # Recursive statement
        return
    fi
}

if [ $# -ne 1 ]
then 
    echo "Number of required arguments is 1"
else
    echo "N = $1, Output = $(( $( factorial $1 ) * $( sum_of_primes $1 ) ))"    #Calling recursive function
fi