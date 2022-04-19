#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N_STUDENT 8
#define N_SLICES 5

time_t end_time;
pthread_mutex_t mutex;
pthread_cond_t pizza_order = PTHREAD_COND_INITIALIZER;
sem_t pizza_available;
int slice_count = N_SLICES;
int pizza_demand = 0;

void* deliver(void* args){
    while(time(NULL)<end_time){
        if(pizza_demand==1){
            pthread_mutex_lock(&mutex);
            printf("lock held by delivery\n");
            slice_count = N_SLICES;
            sleep(1);
            printf("%d slices of pizza delivered.\n",N_SLICES);

            int n = N_SLICES;
            while(n--)
                sem_post(&pizza_available);
            pizza_demand = 0;
            pthread_cond_signal(&pizza_order);
            printf("lock removed by delivery\n");
            pthread_mutex_unlock(&mutex);
        }
    }
}

void* student(void* args){
    int s_no = *((int*)args);
    while(time(NULL)<end_time){

        sem_wait(&pizza_available);

        pthread_mutex_lock(&mutex);
        printf("lock held by %d\n",s_no);
        slice_count--;
        // printf("Student %d took a slice.\n",s_no);
        printf("11lock removed by %d\n",s_no);
        pthread_mutex_unlock(&mutex);

        // printf("Student %d is studying.\n",s_no);
        sleep(1);

        pthread_mutex_lock(&mutex);
        printf("lock held by %d\n",s_no);
        if(slice_count==0 && !pizza_demand){
            pizza_demand = 1;
            // printf("Student %d ordered pizza.\n",s_no);
            // pthread_mutex_unlock(&mutex);
            printf("lock removed by %d and pizza demand set to true\n",s_no);
            pthread_cond_wait(&pizza_order,&mutex);
        }else{
            printf("lock removed by %d\n",s_no);
            pthread_mutex_unlock(&mutex);
        }
    }
}

int main(){
    pthread_mutex_init(&mutex,NULL);
    sem_init(&pizza_available,0,N_SLICES);
    end_time = time(NULL) + 20;

    pthread_t student_thread[N_STUDENT], pizza_deliver;
    int s_args[N_STUDENT];

    for(int i=0;i<N_STUDENT;++i){
        s_args[i] = i+1;
        pthread_create(&student_thread[i], NULL, student, (void*)&s_args[i]);
    }
    
    pthread_create(&pizza_deliver, NULL, deliver, NULL);

    for(int i=0;i<N_STUDENT;++i)
        pthread_join(student_thread[i],NULL);
    
    pthread_join(pizza_deliver,NULL);

    return 0;
}