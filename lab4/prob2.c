#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
//#include <iostream> 
#include <unistd.h> 

#define NUM_THREADS 3

int thr_res[NUM_THREADS];

typedef struct {
    int thr_num;
    int pid;
    int tid;
} thr_arg_t;


void *thr_func(void *arg);

int main() 
{ 
    //int pid; 
    //pid = fork(); 

    pthread_t tid[NUM_THREADS];
    thr_arg_t result[NUM_THREADS];

    for(int i = 0; i < NUM_THREADS; i++)
    {
        result->thr_num = i+1;
        pthread_create(&tid[i],NULL,thr_func, &result[i]);
    }
    

    for(int i = 0; i < NUM_THREADS; i++)
    {
        thr_arg_t *result_p;
        pthread_join(tid[i], (void **)&result_p);
        printf("THREAD %d:\n\tPID: %d\n\tTID: %d\n", result_p->thr_num, result_p->pid, result_p->tid);
    }
    
    return 0; 
} 



void *thr_func(void *arg)
{
    thr_arg_t *args = (thr_arg_t *) arg;
    args->thr_num = args->thr_num;
    args->pid = getpid();
    args->tid = pthread_self();
    return args;
}
