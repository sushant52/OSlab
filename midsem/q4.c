/*
SUSHANT SINHA
1901CS62
C program to simulate the given treasury with borrower, depositor and hacker 
We have used sleep() and spinlocks in the program to give diverse outputs
*/
// Include necessary librarires
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex;  // mutex
pthread_cond_t deposit_money;   // Condition
int borrow_request = 0; // Requst by borrower to borrow certain amount
int treasury_amount = 150;  // Amount in treasury, initially at 150
int hacked = 0; // Wheather hacking has been done or not

void* borrow(void* arg){
    // borrower thread
    while(1){
        pthread_mutex_lock(&mutex); // Acquire lock
        if(hacked)  // Exit if hacked
            return NULL;
        printf("Enter amount to be borrowed: ");    // Input
        scanf("%d",&borrow_request);
        if(borrow_request > treasury_amount)    // Wait for treasury to fill up
            pthread_cond_wait(&deposit_money, &mutex);
        if(hacked)  // Exit if hacked
            return NULL;
        treasury_amount -= borrow_request;
        printf("Amount = %d borrowed from treasury.\n", borrow_request);
        printf("Total Amount in treasury = %d\n\n",treasury_amount);
        borrow_request = 0;
        pthread_mutex_unlock(&mutex);   // Release lock
    }
}

void* deposit(void* arg){
    // depositor thread
    while(1){
        pthread_mutex_lock(&mutex); // Acquire lock
        if(hacked)  // Exit if hacked
            return NULL;
        if(borrow_request){
            // If borrow request is still on, deposit money
            printf("Amount = %d deposited to treasury.\n", borrow_request - treasury_amount);
            treasury_amount = borrow_request;
            printf("Total Amount in treasury = %d\n\n",treasury_amount);
            pthread_cond_signal(&deposit_money);    // Signal condition
        }
        pthread_mutex_unlock(&mutex);   // Release lock
        sleep(1);   // Sleep for sometime to prevent getting the mutex lock continously
    }
}

void* hack(void* arg){
    // hacker thread
    while(1){
        if(pthread_mutex_trylock(&mutex) == 0){ // Try to acquire lock
            printf("Hacker took %d amount from treasury.\n",treasury_amount);
            hacked = 1; // Hack and take everything
            pthread_mutex_unlock(&mutex);   // Release lock
            return NULL;
        }
        int n = 50000;
        while(n--); // If unable to acquire, wait for some time before trying again 
    }
}
int main(){
    pthread_mutex_init(&mutex, NULL);   // Initialize mutex
    pthread_t borrower, depositor, hacker;  // pthread variable

    // Create borrower, depositor and hacker threads
    pthread_create(&borrower, NULL, borrow, NULL);
    pthread_create(&depositor, NULL, deposit, NULL);
    pthread_create(&hacker, NULL, hack, NULL);

    // Wait for hacker to end
    pthread_join(hacker, NULL);
    return 0;
}