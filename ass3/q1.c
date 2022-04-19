// C program to create two child processes
// Child1 finds sum of two numbers
// Child2 finds multiplication of two numbers
// Parent process calculates division of the two results
// All arguments taken through Command Line
// SUSHANT SINHA
// 1901CS62

// Including necessary libraries
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    if(argc != 3){
        printf("ERROR: Required number of arguments are 2.\n");
        return 1;
    }
    // Storing the two input numbers
    long long a = atoll(argv[1]);
    long long b = atoll(argv[2]);

    // File descriptors for two pipes
    int fd1[2];
    int fd2[2];

    if(pipe(fd1) == -1 ){
        printf("ERROR: Pipe Failed.\n");
        return 1;
    }

    if(pipe(fd2) == -1 ){
        printf("ERROR: Pipe Failed.\n");
        return 1;
    }

    // Creating Child1
    pid_t PID1 = fork();
    
    if(PID1 < 0){
        printf("ERROR: Fork Failed.\n");
        return 1;
    }
    else if(PID1 > 0){
        // Creating child2
        pid_t PID2 = fork();

        if(PID2 < 0){
            printf("ERROR: Fork Failed.\n");
            return 1;
        }else if(PID2 == 0){
            close(fd2[0]);
            close(fd2[1]);
            close(fd1[0]);

            // Calculating sum
            long long resadd = a + b;
            // Converting long long to string
            int length = snprintf( NULL, 0, "%lld", resadd );
            char* str = (char*)malloc( sizeof(char)*(length + 1) );
            snprintf( str, length + 1, "%lld0", resadd );
            // Writing to pipe
            write(fd1[1],str,length + 1);

            close(fd1[1]);
            printf("Result of Addition by Child PID %d : %lld\n", getpid(),resadd);
            wait(NULL);
        }else{
            close(fd1[0]);
            close(fd1[1]);
            close(fd2[0]);

            // Calculating multiplication result
            long long resmul = a * b;
            // Converting long long to string
            int length = snprintf( NULL, 0, "%lld", resmul );
            char* str = (char*)malloc( sizeof(char)*(length + 1) );
            snprintf( str, length + 1, "%lld", resmul );
            // Writing to pipe
            write(fd2[1],str,length + 1);

            close(fd2[1]);
            printf("Result of Multiplication by Child PID %d : %lld\n", getpid(),resmul);
        }
    }else{
        close(fd1[1]);
        close(fd2[1]);

        // Reading from pipe the result of both child processes
        char readbuf[100];
        read(fd1[0],readbuf,100);
        long long resadd = atoll(readbuf);
        read(fd2[0],readbuf,100);
        long long resmul = atoll(readbuf);
        float resdiv = (float)resmul/(float)resadd;

        close(fd1[0]);
        close(fd2[0]);
        wait(NULL);

        printf("Result of Division by Parent PID %d : %f\n", getpid(),resdiv);
    }
    return 0;
}