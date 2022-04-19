/*
SUSHANT SINHA
1901CS62
*/
// including necessary libraries
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N_READ 5
#define N_WRITE 2

// semaphores and global variable
sem_t mutex, rw_mutex;
int r_count = 0;

// thread for writers
void* writes(void* args){
    sem_wait(&rw_mutex);    // wait to get resource

    int w_c = *((int*)args);
    sleep(2);
    printf("Writer thread:%d, completed.\n",w_c);   // do writing

    sem_post(&rw_mutex);    // release resource
}

// thread for readers
void* reads(void* args){
    sem_wait(&mutex);   // wait to acquire mutex

    r_count++;  // increase readers
    if(r_count==1)  // if first reader, get rw_mutex resource
        sem_wait(&rw_mutex);
    
    sem_post(&mutex);   // release mutex

    int r_c = *((int*)args);
    sleep(2);
    printf("Reader thread:%d, completed.\n",r_c);   // do reading

    sem_wait(&mutex);   // acquire mutex

    r_count--;  // decrease readers
    if(r_count==0)      // if last reader, release rw_mutex resource
        sem_post(&rw_mutex);
    
    sem_post(&mutex);   // release mutex
}

int main(){
    sem_init(&mutex,0,1);   // initialize semaphores
    sem_init(&rw_mutex,0,1);

    pthread_t reader[N_READ], writer[N_WRITE];  // thread variable arrays
    int r_args[N_READ]; // argument arrays
    int w_args[N_WRITE];

    for(int i=0;i<N_READ;++i){  // create reader threads
        r_args[i] = i+1;
        pthread_create(&reader[i], NULL, reads, (void*)&r_args[i]);
    }
    for(int i=0;i<N_WRITE;++i){ // create writer threads
        w_args[i] = i+1;
        pthread_create(&writer[i], NULL, writes, (void*)&w_args[i]);
    }

    for(int i=0;i<N_READ;++i)   // wait for threads to exit
        pthread_join(reader[i],NULL);
    for(int i=0;i<N_WRITE;++i)
        pthread_join(writer[i],NULL);

    return 0;
}