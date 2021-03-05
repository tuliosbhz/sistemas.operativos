//fibbonacci.c
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

//The Fibonacci series is a series whose first 2 elements are 0 and 1, respectively, 
//and the remainder are the sum of the two previous elements in the series. 
int main(int argc, char *argv[])
{
    if(argc > 2)
    {
        write(STDOUT_FILENO, "Error in the argc parameter", sizeof("Error in the argc parameter"));
        exit(1);
    }

    int fibb[10];
    fibb[0] = 0;
    fibb[1] = 1;
    printf("Fibbonacci sequence - element 1: %d \n", fibb[0]);
    printf("Fibbonacci sequence - element 2: %d \n", fibb[1]);
    for(int i = 2; i < 10; i++)
    {
        fibb[i] = fibb[i-1] + fibb[i-2];
        printf("Fibbonacci sequence - element %d: %d \n", i+1, fibb[i]);
    }

    return 0;
}