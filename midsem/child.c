/*
SUSHANT SINHA
1901CS62
C program which runs as child process
and print info taken from argv
*/
// Including necessary libraries
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    // Prints info about child number, gender and name
    printf("Child # %d: I am a %s, and my name is %s.\n",atoi(argv[1]),argv[2],argv[3]);
    return 0;
}