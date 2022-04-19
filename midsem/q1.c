/*
SUSHANT SINHA
1901CS62
C program to read the hardcoded source program
and print the contents of each line in new file
*/
// Including necessary librarires
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h> 
#include <sys/wait.h>
#define MAX_LENGTH 200  // Max length for buffer

int main(){
    FILE* fptr;    // Open current source file to read
    fptr = fopen("q1.c","r");   // Hardcoded source file
    
    char buffer[MAX_LENGTH];    // Temporary buffer    
    int count = 0;  // Line count

    while(fgets(buffer, MAX_LENGTH, fptr))  // Count number of lines
        count++;
    
    int i=1;
    fptr = fopen("q1.c","r");   // Open file again
    while(i<=count){
        fgets(buffer, MAX_LENGTH, fptr);    // Store one line in buffer
        if(fork()==0){  // Inside child process
            char filename[20];  
            sprintf(filename,"%d.txt",i);   // Making the file name
            FILE* fwptr = fopen(filename,"w");  // open file to write
            fprintf(fwptr,"%s",buffer); // Write to file
            fclose(fwptr);  // Close file
            exit(0);
        }
        wait(NULL); // Wait for child
        i++;
    }
    fclose(fptr);
    return 0;
}