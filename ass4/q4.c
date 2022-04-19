/*
C program to create 3 child processes
child1 copies source program to another file f2.txt
child2 prints contents of f2
child3 deletes file f2
SUSHANT SINHA
1901CS62
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    if(argc != 2){ // Invalid number of arguments
        printf("ERROR: Enter the name of file to copy the source program to\n");
        return 0;
    }

    if(fork() > 0){ // Parent process, creating child 1
        while(wait(NULL) > 0);  // Wait for child to complete execution
        if(fork() > 0){ // Parent process, creating child 2
            while(wait(NULL) > 0);  // Wait for child to complete execution
            if(fork() > 0){ // Parent process, creating child 3
                while(wait(NULL) > 0);  // Wait for child to complete execution
            }
            else{
                // Child 3
                printf("\n\n");
                if(remove(argv[1]) == 0)    // Call to remove, which deletes the created file
                    printf("%s - File removed successfully\n",argv[1]);
                else
                    printf("%s - File could not be reomved\n",argv[1]);
                
                exit(0);
            }
        }
        else{
            // Child 2
            FILE* fptr; 
            fptr = fopen(argv[1],"r");  // Open file to read

            char c = fgetc(fptr);
            while(c != EOF){
                printf("%c",c); // Print contents of file
                c = fgetc(fptr);
            }

            fclose(fptr);   // Close file and exit
            exit(0);
        }
    }
    else{
        // Child 1
        FILE* fptr1;    // Open current source file to read
        FILE* fptr2;    // Open file to write
        fptr1 = fopen(__FILE__,"r");
        fptr2 = fopen(argv[1],"w");

        char c = fgetc(fptr1);
        while(c != EOF){    // Write to requested file
            fprintf(fptr2,"%c",c);
            c = fgetc(fptr1);
        }

        fclose(fptr1);  // Close files and exit
        fclose(fptr2);
        exit(0);
    }
    return 0;
}