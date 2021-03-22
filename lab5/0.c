#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

#define NUM_THREADS 3
#define INIT_COUNTER 10

int n = INIT_COUNTER;

struct th_arg
{
    int thr_num;
    int inc;
} t_args;


void *atom1_counter(int n) 
{
    int count = n;
    return NULL;
}

int main(int argc, char * argv[])
{
    int times = argv[1];
    pthread_t treads[NUM_THREADS];
    for(int i=0; i < times; i++)
    {
        pthread_create(&treads[0], NULL, atom1_counter,n);
        pthread_create(&treads[1], NULL, atom1_counter,NULL);
        pthread_create(&treads[2], NULL, atom1_counter,n);
    }
    //pthread_join(treads[2], NULL);
    printf("Value of the counter is %d", n);
    
}