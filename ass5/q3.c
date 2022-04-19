/*
C program to distribute L litres of petrol among M queues parallely
SUSHANT SINHA
1901CS62
*/
// Including necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

const int SUCCESS = 0;
int m,l;    // Required variables
int** queues;   // 2D matrix to store M queues
int* col_count; // Number of people in a given queue
pthread_mutex_t mutex;  // mutex

// Thread Function to distribute petrol 
void* distribute(void* arg){
    int idx = *(int*) arg;  // Queue number
    for(int i=0;i<col_count[idx];++i){  // While people are left in queue
        pthread_mutex_lock(&mutex); // Lock mutex

        if(queues[idx][i] <= l){    // If enough petrol is available
            l -= queues[idx][i];    // Remove petrol
            printf("%d litres given to person number: %d in queue: %d. Remaining petrol: %d\n",queues[idx][i],i,idx,l);
        }
        else{   // If enough petrol is not available
            pthread_mutex_unlock(&mutex);   // Unlock mutex
            pthread_exit((void*)&SUCCESS);  // Exit thread
        }

        pthread_mutex_unlock(&mutex);   // Unlock mutex
    }
    pthread_exit((void*)&SUCCESS);  // Exit thread
}

int main(){
    pthread_mutex_init(&mutex, NULL);   // Initialize mutex
    // Take input and allocate required memory
    printf("Enter the litres of petrol available: ");
    scanf("%d",&l);
    printf("Enter total number of queues: ");
    scanf("%d",&m);

    queues = (int**)malloc(m*sizeof(int*));
    col_count = (int*)malloc(m*sizeof(int));

    for(int i=0;i<m;++i){
        printf("Enter the number of people in queue %d: ",i+1);
        scanf("%d",&col_count[i]);
        queues[i] = (int*)malloc((col_count[i])*sizeof(int));
        printf("Enter the petrol demand of each person: ");
        for(int j=0;j<col_count[i];++j)
            scanf("%d",&queues[i][j]);
    }

    pthread_t* threads = (pthread_t*)malloc(m*sizeof(pthread_t));   // Create arrays for threads and args
    int* args = (int*)malloc(m*sizeof(int));

    for(int i=0;i<m;++i){
        args[i] = i;
        pthread_create(&threads[i],NULL,distribute,(void*)&args[i]);    // Create threads
    }
    
    for(int i=0;i<m;++i)
        pthread_join(threads[i],NULL);  // Wait for threads to terminate
    return 0;
}