// C program to run two tasks(.sh files)
// Child process executes task1.sh
// Parent process executes task2.sh
// All arguments taken through Command Line
// SUSHANT SINHA
// 1901CS62

// Input Format
// ./q3.c [Task 1 Script Name] [Task 1 Arguments] [Task 2 Script Name] [Task 2 Arguments]

// Including necessary libraries
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    pid_t PID = fork();
    
    if(PID < 0){
        printf("ERROR: Fork Failed.\n");
        return 1;
    }
    else if(PID != 0){
        // Parent process supposed to run task2
        // Forming array of CLA for task2
        char* argv2[3];
        argv2[0] = argv[argc-2];
        argv2[1] = argv[argc-1];
        argv2[2] = NULL;

        execv(argv[argc-2], argv2);
        printf("ERROR: EXECV Failed.\n"); 
    }else{
        // Child process supposed to run task1
        // Forming array of CLA for task1
        char* argv1[argc-2];
        argv1[0] = argv[1];
        for(int i=0;i<argc-4;++i)
            argv1[i+1] = argv[i+2];

        argv1[argc-3] = NULL;
        wait(NULL);
        execv(argv[1],argv1);
        printf("ERROR: EXECV Failed.\n"); 
    }
    return 0;
}