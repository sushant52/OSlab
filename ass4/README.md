SUSHANT SINHA
1901CS62
OS LAB ASSIGNMENT 4

Q1:-
Compile C program:
Command: gcc -o q1.out q1.c
This creates q1.out file

Command: ./q1.out 5 &
Output: [17] 14494
5 zombies created

This runs our program instructing it to create 5 zombie processes.
We also use the & symbol to run asynchronously and returns the PID of parent process

Command: pstree -p 14494
Output: 
q1.out(14494)─┬─q1.out(14495)
              ├─q1.out(14496)
              ├─q1.out(14497)
              ├─q1.out(14498)
              └─q1.out(14499)
Shows the parent process along with 5 child processes with their PIDs

Command: ps aux | grep q1.out
Output:
sushant+ 14494  0.0  0.0   4376   796 pts/1    S    18:43   0:00 ./q1.out 5
sushant+ 14495  0.0  0.0      0     0 pts/1    Z    18:43   0:00 [q1.out] <defunct>
sushant+ 14496  0.0  0.0      0     0 pts/1    Z    18:43   0:00 [q1.out] <defunct>
sushant+ 14497  0.0  0.0      0     0 pts/1    Z    18:43   0:00 [q1.out] <defunct>
sushant+ 14498  0.0  0.0      0     0 pts/1    Z    18:43   0:00 [q1.out] <defunct>
sushant+ 14499  0.0  0.0      0     0 pts/1    Z    18:43   0:00 [q1.out] <defunct>
sushant+ 14520  0.0  0.0  21536  1004 pts/1    S+   18:44   0:00 grep --color=auto q1.out

This command finds all the running processes and then uses regex matching to find processes with q1.out in them.
As we can see, There is the parent process with PID 14494, in "interruptible sleep" state(S).
5 other child processes are there with PIDs 14495, 14496, 14497, 14498 and 14499.
All child processes are defunct and in defunct state(Z). They have became zombie processes.
Required screenshots can be found in zip file.

Q2:-
Compile C program:
Command: gcc -o q2.out q2.c
This creates q2.out file

Command: ./q2.out 3 &
Output: [17] 14992

This runs our program instructing it to create 3 orphan processes.
We also use the & symbol to run asynchronously and returns the PID of parent process

Command: pstree -p 14992
Output: 
The command gives nothing as output as the parent process has terminated.

Command: pstree -p 1
Output:
...
           ├─q2.out(14993)
           ├─q2.out(14994)
           ├─q2.out(14995)
...
We see a structure like this indicating 3 orphan processes are still running.
The parent PID is now 1.

Command: ps aux | grep q2.out
Output:
sushant+ 14993  0.0  0.0   4376    72 pts/1    S    19:03   0:00 ./q2.out 3
sushant+ 14994  0.0  0.0   4376    72 pts/1    S    19:03   0:00 ./q2.out 3
sushant+ 14995  0.0  0.0   4376    72 pts/1    S    19:03   0:00 ./q2.out 3
sushant+ 15004  0.0  0.0  21536  1028 pts/1    S+   19:03   0:00 grep --color=auto q2.out

As we can see, 3 orphan processes are still running in 'S' state.
The PID of parent process can not be seen here as it has terminated.
Required screenshots can be found in zip file.

Q3:-
Compile C program:
gcc -o q3.out q3.c

Command: ./q3.out 5
Output: 2 1 3 4 7
lucas.txt: 2 1 3 4 7 
First five lucas numbers are printed and a lucas.txt file is created from where these are printed.

Command: ./q3.out 1
Output: 2 
lucas.txt: 2  

Command: ./q3.out 10
Output: 2 1 3 4 7 11 18 29 47 76
lucas.txt: 2 1 3 4 7 11 18 29 47 76

Q4:-
Compile C program:
gcc -o q4.out q4.c

Command: ./q4.out f2.txt
Output:
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

f2.txt - File removed successfully

Here. the file f2.txt is created and the source program is written into it.
Another process then outputs the contents of file f2.txt
Another process finally deletes the file