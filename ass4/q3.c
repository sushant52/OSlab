/*
C program to create 2 child processes
where child1 generates first n lucas numbers
and child2 prints them
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
    
    if(fork() > 0){ // Parent process, creating Child 1
        while(wait(NULL) > 0);  // Wait for child to complete execution
        if(fork() > 0){ // Parent Process, creating child 2
            while(wait(NULL) > 0);
        }
        else{
            // 2nd child process
            FILE* fptr;
            fptr = fopen("lucas.txt","r");  // Read from file
            char c = fgetc(fptr);

            while(c != EOF){    // Print the file contents
                printf("%c",c);
                c = fgetc(fptr);
            }
            printf("\n");
            fclose(fptr);   // Close file and exit
            exit(0);
        }
    }
    else{
        // 1st child process
        // Instead of starting from 2 and 1, we start from 3 and -1
        // as 3+-1 = 2 and 2+-1 = 1, thus we get the first 2 numbers after 2 iterations
        long long lucas1 = 3;   
        long long lucas2 = -1;
        long long lucas3;

        FILE* fptr;
        fptr = fopen("lucas.txt","w");  // Opening file to write

        for(int i=0;i<n;++i){
            lucas3 = lucas1 + lucas2;   // Calculating next lucas number    
            fprintf(fptr,"%lld ",lucas3);   // Writing to file
            lucas1 = lucas2;
            lucas2 = lucas3;
        }

        fclose(fptr);   // Closing file and exit
        exit(0);
    }
    return 0;
}