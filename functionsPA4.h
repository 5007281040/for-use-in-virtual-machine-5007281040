#ifndef FUNCTIONSPA4_H
#define FUNCTIONSPA4_H

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

typedef struct _thread_data_t 
{
    int localTid;
    const int *data;
    int numVals;
    pthread_mutex_t *lock;
    long long int *totalSum;

} thread_data_t;

void* arraySum(void*);


#endif