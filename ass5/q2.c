/*
C program to create 3 threads
1st thread writes all the non-prime numbered lines to file
2nd thread writes all the prime numbered lines to file
3rd thread parallely reads number of characters in each line
SUSHANT SINHA
1901CS62
*/
// Including necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

const int SUCCESS = 0;
int* isprime;   // Array indicating whether a number is prime or not
int n;  // Number of lines to be written
FILE* fptrw;    // File pointers to read and write from a file
FILE* fptrr;
int line_r = 1; // Line number to read
int line_w = 1; // Line number to write

void sieve()    // Function to determine which numbers are prime
{
    isprime = (int*)malloc((n+1)*sizeof(int));
    for(int i=0; i<=n ; ++i)
        isprime[i] = 1;

    isprime[0] = 0;
    isprime[1] = 0;
 
    for(int i=2; i*i<=n; i++)
    {
        if(isprime[i])
        {
            for(int j= i*i; j<=n; j+=i)
                isprime[j] = 0;
        }
    }
    return;
}

// Thread function to write non prime lines to file
void* non_prime_print(){
    while(line_w <= n){ // Check if line number is less than specified limit
        int local_line_w = line_w;  // Making a local copy to avoid isues
        if(local_line_w <= n && !isprime[local_line_w]){    // If not prime, then write
            fprintf(fptrw,"Line number : %d is %s, written by thread : %lu\n",local_line_w,"NOT PRIME",pthread_self());
            line_w++;   // Increase line to write
        }
    }
}

// Thread function to write prime lines to file
void* prime_print(){
    while(line_w <= n){ // Check if line number is less than specified limit
        int local_line_w = line_w;  // Making a local copy to avoid isues
        if(local_line_w <= n && isprime[local_line_w]){ // If prime, then write
            fprintf(fptrw,"Line number : %d is %s, written by thread : %lu\n",local_line_w,"PRIME",pthread_self());
            line_w++;   // Increase line to write
        }
    }
}

// Thread function to calculate number of characters in each line
void* count_chars(){
    while(line_r <= n){ // Check if line number is less thn specified limit
        if(line_r < line_w){    // Read line only after it is written
            fflush(fptrw);  // Flush output stream to file
            char c = fgetc(fptrr);
            int count = 0;
            while((c!='\n') && (c!=EOF)){// Read from file until newline or EOF is encountered
                count++;
                c = fgetc(fptrr);
            }
            printf("Total characters in line %d is : %d, counted by thread %lu\n", line_r, count, pthread_self());
            line_r++;   // Increase line number to read
        }
    }
}

int main(int argc, char* argv[]){
    if(argc != 3){  // Error
        printf("Invalid inputs.\n");
        return 1;
    }
    // argv[1] : Number of lines to print
    // argv[2] : File name
    n = atoi(argv[1]);
    fptrw = fopen(argv[2],"w");
    fptrr = fopen(argv[2],"r");

    if(fptrw==NULL || fptrr==NULL){ // Error file opening
        printf("Error opening file.\n");
        return 1;
    }
    sieve();    // Calculate primes

    pthread_t threads[3];   // Array for threads
    // Create threads
    pthread_create(&threads[0], NULL, non_prime_print, NULL);
    pthread_create(&threads[1], NULL, prime_print, NULL);
    pthread_create(&threads[2], NULL, count_chars, NULL);
    // Wait for threads to complete execution
    pthread_join(threads[0],NULL);
    pthread_join(threads[1],NULL);
    pthread_join(threads[2],NULL);

    // Close files
    fclose(fptrw);
    fclose(fptrr);
    return 0;
}