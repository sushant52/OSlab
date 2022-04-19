/*
SUSHANT SINHA
1901CS62
C program to act as parent program
takes info about gender-name pairs of children
and passes info to another child program to print it
*/
// Including necessary libraries
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h> 
#include <sys/wait.h>

int main(int argc, char* argv[]){
    argc--;
    int i = 1;  // Argument index
    int childcount = 1; // Current child count
    printf("I have %d children.\n",argc/2);
    while(i<argc){
        if(fork()==0){  // Inside child process
            char buffer[10];
            sprintf(buffer,"%d",childcount);    // Convert integer to string
            char* args[] = {"child",buffer,argv[i],argv[i+1],NULL}; // Constructing args for child
            execv("child", args);   // execv call to child program
            exit(0);
        }
        wait(NULL); // Wait for child to finish
        i += 2;
        childcount++;
    }
    while(wait(NULL) > 0);  // Wait for all child process to complete
    printf("All child processes terminated. Parent exits.\n");
    return 1;
}