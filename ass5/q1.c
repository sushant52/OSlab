/*
C program to create 10 threads
Main thread then waits for all threads to terminate
Status of each thread is printed out
Last thread is cancelled
SUSHANT SINHA
1901CS62
*/
// Including necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

const int SUCCESS = 0;
const int FAILURE = 1;

// Function callep upon by thread
void* func(void* x){
    int num = *(int*) x;    // Thread number
    if(num == 9){   // Cancel thread if last thread
        pthread_cancel(pthread_self());
        pthread_testcancel();
    }
    printf("THREAD %d: Hello World!\n",num);    
    
    return (void*)&SUCCESS;
}

int main(){
    pthread_t threads[10];  // Array of pthread_t
	int args[10];   // Arguments for thread

    for(int i=0; i<10; ++i){    // Creating threads and passing necessary arguments
        args[i] = i;
        int ret_status = pthread_create(&threads[i], NULL, func, (void*)&args[i]);

        if(ret_status != 0){    // Error creating thread
            printf("ERROR : Creating pthread\n");
            return 1;
        }
    }
    void* status[10];   // Array for status returned by threads

    for(int i=0; i<10 ; ++i){   // Waiting for threads to terminate
        int ret_status = pthread_join(threads[i], &status[i]);

        if(ret_status != 0){    // Error joining thread
            printf("ERROR : Joining pthread\n");
            return 1;
        }

        printf("i = %d, status = THREAD %d ",i,i);  // Printing thread status

        if(status[i] == PTHREAD_CANCELED)
            printf("%s\n","CANCELED");
        else 
            printf("%s\n","SUCCESS");
    }
    return 0;
}