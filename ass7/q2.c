// SUSHANT SINHA
// 1901CS62
// Including necessary libraries
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// semaphores
sem_t mutex, data;

// thread 1 function
void* A(void* args){
    sem_wait(&mutex);
    sem_wait(&data);
    printf("process A");
    sem_post(&data);
    sem_post(&mutex);
}

// thread 2 function
void* B(void* args) {
    sem_wait(&mutex);   // changed order of acquiring data and mutex resource
    sem_wait(&data);
    printf("process B");
    sem_post(&data);
    sem_post(&mutex);
}

int main(){
    sem_init(&mutex,0,1);   // initialize semaphores
    sem_init(&data,0,1);

    pthread_t t1, t2;   //thread variables
    pthread_create(&t1, NULL, A, NULL); // create threads
    pthread_create(&t2, NULL, B, NULL);

    pthread_join(t1,NULL);  // wait for termination
    pthread_join(t2,NULL);

    return 0;
}