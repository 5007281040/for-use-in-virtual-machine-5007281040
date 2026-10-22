#include "functionsPA4.h"



void* arraySum(void* maskedParameter){


   
    
    thread_data_t *realParameter= (thread_data_t*) maskedParameter;
    volatile long long int threadSum = 0;


    pthread_mutex_lock(realParameter->lock);

    

    long latency_max;

    while(1)
    {
        for(int i=0; i< realParameter->numVals; i++)
        {
            struct timespec start;
            clockid_t clockStartID, clockEndID;
        
            clock_gettime(clockStartID, &start);
            
            threadSum += (realParameter->data[i]);
            realParameter->totalSum = threadSum;

            struct timespec end;
            clock_gettime(clockEndID, &end);


            long latency= end.tv_nsec- start.tv_nsec;
            if(latency > latency_max)
            {
                latency_max = latency;
            }



        }

        print_progress(realParameter->localTid, latency_max);
    }



    pthread_mutex_unlock(realParameter->lock);








}


void print_progress(pid_t, size_t);