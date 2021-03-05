//fibbonacci.c
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

//The Fibonacci series is a series whose first 2 elements are 0 and 1, respectively, 
//and the remainder are the sum of the two previous elements in the series.
void in_fibonacci(int *fibb, int n)
{
    fibb[0] = 0;
    fibb[1] = 1;
    printf("Fibbonacci sequence - element 1: %d \n", fibb[0]);
    printf("Fibbonacci sequence - element 2: %d \n", fibb[1]);
    for(int i = 2; i < n; i++)
    {
        fibb[i] = fibb[i-1] + fibb[i-2];
        printf("Fibbonacci sequence - element %d: %d \n", i+1, fibb[i]);
    }
} 
int main(int argc, char *argv[])
{
    if(argc > 2)
    {
        write(STDOUT_FILENO, "Error in the argc parameter", sizeof("Error in the argc parameter"));
        exit(1);
    }
    char ns[3];
    int n;
    printf("Choose a number of elements of fibonacci sequence: \n");
    read(STDIN_FILENO, ns, sizeof(ns));
    n = atoi(ns);
    int fibb[n];
    
    in_fibonacci(fibb, n);

    return 0;
}