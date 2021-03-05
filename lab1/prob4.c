#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

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
    long int n;
    //read(STDIN_FILENO, argv, sizeof(ns));
    //n = atoi(argv[1]);
    n = strtoll(argv[1], NULL, 10);
    int fibb[n];
    
    in_fibonacci(fibb, n);

    return 0;
}
