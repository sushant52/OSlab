/*
C program to create 'n' orphan child processes
Input taken as command line argument
SUSHANT SINHA
1901CS62
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    if(argc != 2){  // Invalid number of arguments
        printf("ERROR: Enter a number\n");
        return 0;
    }

    int n = atoi(argv[1]);
    for(int i=0;i<n;++i){   // Run a loop n times
        if(fork() == 0){    
            sleep(120);     // If the process is child process, make it wait for 120 seconds
            break;          // Exit from loop
        }
    }
    
    return 0;   // End the parent process while the child processes are waiting for 120 seconds
}