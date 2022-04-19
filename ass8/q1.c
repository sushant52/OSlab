/*
SUSHANT SINHA
1901CS62
Program to implement Banker's algorithm
and print all possible safe sequences
*/
// Including necessary libraries
#include <stdio.h>
#include <stdlib.h>

// Global variables for total processes, resources and possible safe sequences
int n_proc, n_rsrc, total;

// Function to print the given safe sequence 
void print_ans(int* ans){
    printf("Safe sequence %d: ", total);
    int i;
    for(i=0;i<n_proc-1;++i)
        printf("P%d->",ans[i]);
    printf("P%d\n",ans[i]);
    return;
}

// Function to recursively determine possible safe sequences using recursiona nd backtracking
void safe_seq(int** need_rsrc, int** all_rsrc, int* avail_rsrc, int* seen, int* ans, int total_safe){
    // if total processes in current safe sequece is equal to total number of processes
    // Then a safe sequence has been found
    // Increment counter and print the array
    if(total_safe==n_proc){
        total++;
        print_ans(ans);
        return;
    }

    // Loop over all processes
    for(int i=0;i<n_proc;++i){
        // If process not already included in safe sequence
        if(!seen[i]){
            int flag = 1;   // Boolean to determine whether given process can be included in safe sequence
            for(int j=0;j<n_rsrc;++j){  
                // If process demands more resources than that are available, then not possible
                if(avail_rsrc[j]<need_rsrc[i][j]){
                    flag = 0;
                    break;
                }
            }
            // If process demands can be met, include it in safe sequence
            if(flag){
                // Free up tha allocated resources of teh process
                for(int j=0;j<n_rsrc;++j)
                    avail_rsrc[j] += all_rsrc[i][j];
                seen[i] = 1;    // mark as included
                ans[total_safe] = i;    // include in the safe sequence

                // recursive call to find next possible process
                safe_seq(need_rsrc, all_rsrc, avail_rsrc, seen, ans, total_safe+1);

                // bactracking, undo all the changes previously made
                ans[total_safe] = -1;
                seen[i] = 0;
                for(int j=0;j<n_rsrc;++j)
                    avail_rsrc[j] -= all_rsrc[i][j];
            }
        }
    }

    return;
}

int main(){
    total = 0;
    // Input
    printf("Enter number of processes: ");
    scanf("%d",&n_proc);
    printf("Enter number of resources: ");
    scanf("%d",&n_rsrc);

    // Memory allocation
    int** all_rsrc = (int**)malloc(n_proc*sizeof(int*));    // allocated matrix
    int** max_rsrc = (int**)malloc(n_proc*sizeof(int*));    // maximum resource matrix
    int** need_rsrc = (int**)malloc(n_proc*sizeof(int*));   // needed resource matrix
    int* avail_rsrc = (int*)malloc(n_rsrc*sizeof(int)); // available resource array
    int* ans = (int*)malloc(n_proc*sizeof(int));    // answer array, stores possible safe sequence
    int* seen = (int*)malloc(n_proc*sizeof(int));   // seen array, determines whether process is in safe sequence or not

    for(int i=0;i<n_proc;++i){  // Matrix initializations and allocation
        all_rsrc[i] = (int*)malloc(n_rsrc*sizeof(int));
        max_rsrc[i] = (int*)malloc(n_rsrc*sizeof(int));
        need_rsrc[i] = (int*)malloc(n_rsrc*sizeof(int));
        ans[i] = -1;
        seen[i] = 0;
    }

    printf("Enter allocated resources for each process:-\n");
    for(int i=0;i<n_proc;++i)
        for(int j=0;j<n_rsrc;++j)
            scanf("%d",&all_rsrc[i][j]);
    
    printf("Enter maximum resources for each process:-\n");
    for(int i=0;i<n_proc;++i)
        for(int j=0;j<n_rsrc;++j)
            scanf("%d",&max_rsrc[i][j]);
    
    printf("Enter available resources:-\n");
    for(int i=0;i<n_rsrc;++i)
        scanf("%d",&avail_rsrc[i]);

    // Calculating need matrix
    for(int i=0;i<n_proc;++i){
        for(int j=0;j<n_rsrc;++j){
            need_rsrc[i][j] = max_rsrc[i][j] - all_rsrc[i][j];
            printf("%d ",need_rsrc[i][j]);
        }
        printf("\n");

    }
    // Finding all possible safe sequences
    safe_seq(need_rsrc,all_rsrc,avail_rsrc,seen,ans,0);
    // If no safe sequence found
    if(total==0)
        printf("No safe sequence found\n");
    return 0;
}