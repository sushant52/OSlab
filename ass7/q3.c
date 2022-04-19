// SUSHANT SINHA
// 1901CS62
// Including necessary libraries
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N_STUDENT 8
#define N_SLICES 5

// mutex and condition variable
pthread_mutex_t mutex;
pthread_cond_t pizza_available;
// count of available slices and whether order has been made for more
int slice_count = N_SLICES;
int order = 0;

time_t end_time;    // runnning the simulation for limited time

// thread for pizza delivery
void* deliver(void* args){
    while(1){
        if(order){  // if order has been made
            pthread_mutex_lock(&mutex); // acquire lock

            slice_count = N_SLICES; // deliver slices
            printf("%d slices of pizza delivered.\n",N_SLICES);

            order = 0;  // order back to 0
            pthread_cond_broadcast(&pizza_available);   // broadcast that pizza is available
            pthread_mutex_unlock(&mutex);   // release lock
        }
    }
}

// thread for student
void* student(void* args){
    while(1){
        int s_no = *((int*)args);   // student number
        pthread_mutex_lock(&mutex); // acquire lock
        if(slice_count==0){ // if pizza is not available, sleep and wait
            printf("Student %d sleeping due to lack of pizza.\n",s_no);
            pthread_cond_wait(&pizza_available, &mutex);
        }
        
        if(slice_count!=0){ // if pizza is still available
            slice_count--;  // consume pizza and study
            sleep(1);
            printf("Student %d took a slice and studied.\n",s_no);
            if(slice_count==0 && order==0){ // if no pizza and order has not been made yet
                order = 1;  // make order
                printf("Student %d ordered pizza.\n",s_no);
                pthread_cond_wait(&pizza_available,&mutex); // wait for order to complete
            }
        }

        pthread_mutex_unlock(&mutex);   // release lock
        sleep(1);   // allow for randomness in answer
    }
}

int main(){
    pthread_mutex_init(&mutex, NULL);   // initialize mutex

    end_time = time(NULL) + 17; // duration for which simulation has to be run
    pthread_t student_thread[N_STUDENT], pizza_deliver; // thread variables
    int s_args[N_STUDENT];  // arguments

    for(int i=0;i<N_STUDENT;++i){   // create student threads
        s_args[i] = i+1;
        pthread_create(&student_thread[i], NULL, student, (void*)&s_args[i]);
    }
    pthread_create(&pizza_deliver, NULL, deliver, NULL);    // create delivery thread

    while(time(NULL) < end_time);   // wait for time to complete

    for(int i=0;i<N_STUDENT;++i)    // cancel all the threads
        pthread_cancel(student_thread[i]);
    
    pthread_cancel(pizza_deliver);

    return 0;
}