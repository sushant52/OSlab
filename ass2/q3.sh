#!/bin/bash
#Shell Script to find XOR of two numbers
#Numbers are first converted into binary
#Input taken through command line argument
#Works for positive numbers
#SUSHANT SINHA
#1901CS62

# Function to find XOR of two numbers by converting them to binary
xor () {
    a_binary=""
    b_binary=""
    xor_binary=""
    a=$1
    b=$2
    ans=0
    twopower=1

    # Converting to binary by repeated division by 2
    while [ $a -ne 0 ] || [ $b -ne 0 ]
    do
        a_binary="$(( $a % 2 ))$a_binary"
        b_binary="$(( $b % 2 ))$b_binary"
        
        # Finding the XOR using xor_bit = (a_bit + b_bit)%2
        xor_bit=$(( ( $a % 2 + $b % 2 ) % 2 ))
        ans=$(( $ans + $twopower * $xor_bit ))
        twopower=$(( $twopower * 2 ))
        xor_binary="${xor_bit}${xor_binary}"

        a=$(( $a / 2 ))
        b=$(( $b / 2 ))
    done
    #Output
    echo "Decimal: XOR of $1 and $2: $ans "
    echo "Binary: XOR of $a_binary and $b_binary: $xor_binary"

}

if [ $# -ne 2 ]
then
    echo "Required number of inputs is 2"
else
    xor $1 $2   # call to function to calculate xor
fi