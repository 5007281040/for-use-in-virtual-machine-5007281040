#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <pthread.h> // for pthreads
#include <time.h>

#include "functionsPA4.h"


/*
So, apparently the setting of configs in GRUB wasn't enough. I have to use systemd to set values that I need.
(according to this, anyways. https://forum.proxmox.com/threads/cset-failing-pve7.95613/)



*/


int main(int argc, char* argv[]){

    //start by parsing command line argument. ./sched 4. General ./sched N
    //verify and validate only 2 arguments have been passed.
    if(argc != 2){

        printf("%s\n", "Needs a number of threads. No more, no less.");
        return 0;
    }

    int* allocatedArr = NULL;

    allocatedArr = malloc(2000000*sizeof(int));
    
    long long int totalSum = 0;

    pthread_mutex_t myMutex;

    pthread_mutex_init(&myMutex, NULL);


    int desiredAmountOfThreads = atoi(argv[1]);


    thread_data_t* allocatedThreadArr = NULL;

    allocatedThreadArr = malloc(desiredAmountOfThreads * sizeof(thread_data_t));

    //allocatedArr[0] = 1;
    //allocatedArr[1] = 4;        
    //printf("%d\n", allocatedArr[0]);
    //printf("%d\n", allocatedArr[1]);


    for(int i=0; i< desiredAmountOfThreads; i++){


        allocatedThreadArr[i].localTid=i;
        allocatedThreadArr[i].data = allocatedArr;
        allocatedThreadArr[i].numVals = 2000000;
        allocatedThreadArr[i].lock = &myMutex;
        

    }

    pthread_t staticThreadArr[desiredAmountOfThreads];


    for(int i=0; i< desiredAmountOfThreads; i++){
        pthread_t localLoopThread;
        staticThreadArr[i] = localLoopThread;


    }

    for(int i=0; i< desiredAmountOfThreads; i++)
    {

    pthread_create(&staticThreadArr[i], NULL, arraySum, (void*) &allocatedThreadArr[i]);

    }


    for(int i=0; i< desiredAmountOfThreads; i++)
    {
    pthread_join(staticThreadArr[i], NULL);
    //note: even though these 2 for loops are symmetrical, do not join them with the one above. 

    }











    return 0;
}

