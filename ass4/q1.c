/*
C program to create 'n' zombie child processes
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
        if(fork() == 0){    // If the process is a child process, end it
            exit(0);
        }
    }
    printf("%d Zombie processes created\n",n);
    sleep(120); // Make the parent process sleep for 120 seconds while we access the terminal
    
    return 0;
}